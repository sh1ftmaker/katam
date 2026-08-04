// LOCAL-ONLY — DO NOT SUBMIT UPSTREAM.
//
// asm/sprite.s is claimed by another contributor under upstream PR #367.
// This file exists to unblock the WebAssembly port (~/Desktop/katam-port),
// which cannot draw a single sprite until sub_08155128 has a C body: every
// object in the game reaches OAM through it, 521 references, and while it is
// stubbed nothing but backgrounds renders.
//
// Therefore:
//   * Nothing here is ever to be opened as a pull request, and nothing here
//     is wired into linker.ld or the build. asm/sprite.o still supplies the
//     real code; this file is compiled only for verification and consumed
//     only by the port.
//   * CORRECT C IS THE GOAL. A byte match is a bonus, not the bar. The port
//     needs behaviour, and duplicating #367's matching effort is explicitly
//     not what this is for.
//   * If #367 lands, this file should be deleted, not merged.
//
// Verify a function here with:
//   python3 ~/Desktop/katam-mcheck.py wip/sprite.c asm/sprite.s

#include "gba/m4a.h"
#include "portable.h"
#include "data.h"
#include "sprite.h"
#include "main.h"
#include "task.h"

/* include/sprite.h's AnimCmd_SetIdAndVariant is wrong: sub_08154E70 reads the
 * variant as a halfword at +0x6, not +0x8, and advances the cursor by 2 words,
 * so the command is 8 bytes, not 0xC. Corrected shape kept local to this file
 * so as not to disturb the shared header. */
struct AnimCmd_SetIdAndVariant_Fixed {
    /* 0x00 */ s32 cmdId;
    /* 0x04 */ u16 animId;
    /* 0x06 */ u16 variant;
}; /* size = 8 */

// gUnk_08D6081C[2]: jump backwards in the command stream by `offset` words.
s32 sub_08154E18(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor -= cmd.jumpBack->offset;
    return 1;
}

// gUnk_08D6081C[3]: stop the animation. Sets the "animation finished" flag
// (0x4000 of unk8); returning 0 makes sub_08155128 report "not advanced".
s32 sub_08154E24(union AnimCmd cmd, struct Sprite *s)
{
    s->unk8 |= 0x4000;
    return 0;
}

// gUnk_08D6081C[4]: play a sound effect.
s32 sub_08154E34(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor += 2;
    m4aSongNumStart(cmd.playSoundEffect->songId);
    return 1;
}

// gUnk_08D6081C[6]: translate the sprite by (x, y).
s32 sub_08154E48(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor += 2;
    s->x += cmd.translateSprite->x;
    s->y += cmd.translateSprite->y;
    return 1;
}

// no-op command, 3 words wide (0xC bytes).
s32 sub_08154E64(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor += 3;
    return 1;
}

// gUnk_08D6081C[8]: switch to another animation (id + variant). Returning -1
// tells sub_08155128 to re-fetch the command stream and restart at cursor 0.
s32 sub_08154E70(union AnimCmd cmd, struct Sprite *s)
{
    const struct AnimCmd_SetIdAndVariant_Fixed *c = (const void *)cmd.words;

    s->animCursor += 2;
    s->animId = c->animId;
    s->unk1B = 0xFF;
    s->variant = c->variant;
    return -1;
}

// no-op command, 4 words wide (0x10 bytes). NOTE: the original sets no return
// value at all -- r0 still holds the command pointer on return, so
// sub_08155128 forwards that (nonzero) address to its caller. Reproduced
// literally because callers only ever test the result against 0.
s32 sub_08154E88(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor += 4;
    return (s32)cmd.words;
}

// no-op command, 2 words wide.
s32 sub_08154E90(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor += 2;
    return 1;
}

// no-op command, 2 words wide.
s32 sub_08154E9C(union AnimCmd cmd, struct Sprite *s)
{
    s->animCursor += 2;
    return 1;
}

// Advance a sprite's animation by one tick and pick the frame to draw.
//
// RETURN VALUE (load-bearing -- callers test it):
//   0       the sprite has no frame this tick: the animation is stopped.
//           Either the "finished" flag (0x4000 of unk8) was already set on
//           entry, or the stop command sub_08154E24 set it just now. Callers
//           use `if (sub_08155128(s) == 0)` to detect "animation over".
//   1       normal: either the current frame's timer is still running, or a
//           new ShowFrame command was consumed (unk4 = frame index, and
//           0x04000000 set in unk8 to mark the sprite as needing a redraw).
//   other   an anim-command handler returned something that is neither 1
//           (continue) nor -1 (restart), and it is passed straight through.
//           Only sub_08154E88 does this today, and it leaks a ROM address, so
//           in practice every nonzero return means "there is a frame".
u32 sub_08155128(struct Sprite *s)
{
    const s32 *anim;
    const s32 *cmd;
    s32 ret;

    // Resync when the caller changed animId/variant behind our back.
    if (s->unk1B != s->variant || s->unk18 != s->animId) {
        s->unk1B = s->variant;
        s->unk18 = s->animId;
        s->animCursor = 0;
        s->unk16 = 0;
        s->unk8 &= ~0x4000;
    }

    if (s->unk8 & 0x4000)
        return 0;

    // unk16 is the remaining display time of the current frame in 8.8 fixed
    // point; unk1C is the playback speed, applied as unk1C/16 frames per tick.
    if (s->unk16 > 0) {
        s->unk16 -= s->unk1C * 16;
        return 1;
    }

    anim = gSpriteTables->anims[s->animId][s->variant].words;
    cmd = &anim[s->animCursor];

    // Negative words are commands; run them until a (non-negative) ShowFrame.
    while (*cmd < 0) {
        ret = gUnk_08D6081C[~*cmd](cmd, s);
        if (ret != 1) {
            if (ret != -1)
                return ret;
            anim = gSpriteTables->anims[s->animId][s->variant].words;
            s->animCursor = 0;
        }
        cmd = &anim[s->animCursor];
    }

    s->unk16 = (*cmd << 8) + s->unk16 - s->unk1C * 16;
    s->unk4 = cmd[1];
    s->unk8 |= 0x04000000;
    s->animCursor += 2;
    return 1;
}
