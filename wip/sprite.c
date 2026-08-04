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
#include "palette.h"
#include "functions.h"

// Returns 1 normally; if an anim-command handler returns anything other than
// 1 or -1, that value is propagated to the caller verbatim.  Callers branch on
// it -- do NOT stub this as "return 0".
s32 sub_0815521C(struct Sprite *sprite, u16 framesArg) {
    s32 frames = framesArg;
    s32 ret;
    union AnimCmd current, next, newCursor;
    const union AnimCmd *base;
    s32 total, loopLen;
    u8 savedQueueIdx;
    s32 queueDirty;

    total = 0;
    loopLen = 0;
    queueDirty = 0;
    savedQueueIdx = gUnk_030039A4;

    sprite->unk1B = sprite->variant;
    sprite->unk18 = sprite->animId;
    sprite->animCursor = 0;
    sprite->unk16 = 0;
    sprite->unk8 &= ~0x4000;

    base = gSpriteTables->anims[sprite->animId];
    next = base[sprite->variant];
    while (frames >= 0) {
        for (current.words = &next.words[sprite->animCursor];
            // for whatever command, cmdId is always the first field
            current.getTiles->cmdId < 0;
            current.words = &next.words[sprite->animCursor]) {
            if (current.jumpBack->cmdId == -3)
                loopLen = total;
            ret = gUnk_08D6081C[~current.getTiles->cmdId](current, sprite);
            // The handlers push DMA requests into gUnk_03002EC0; while
            // fast-forwarding we keep re-using the same queue slot instead of
            // letting every skipped frame allocate one.
            if (savedQueueIdx != gUnk_030039A4) {
                gUnk_030039A4 = savedQueueIdx;
                queueDirty = 1;
            }
            if (ret != 1) {
                if (ret == -1) {
                    base = gSpriteTables->anims[sprite->animId];
                    newCursor = base[sprite->variant];
                    sprite->animCursor = 0;
                    next = newCursor;
                } else {
                    if (queueDirty)
                        gUnk_030039A4 = (gUnk_030039A4 + 1) & 0x3F;
                    return ret;
                }
            }
        }
        sprite->unk16 = current.showFrame->delay << 8;
        frames -= current.showFrame->delay;
        sprite->unk16 = -(frames << 8);
        if (loopLen && frames > 0) {
            frames = Mod(frames, loopLen);
        } else {
            total += current.showFrame->delay;
        }
        sprite->unk4 = current.showFrame->index;
        sprite->unk8 |= 0x4000000;
        sprite->animCursor += sizeof(struct AnimCmd_ShowFrame) / 4;
    }
    if (queueDirty)
        gUnk_030039A4 = (gUnk_030039A4 + 1) & 0x3F;
    return 1;
}

// gUnk_08D6081C[0].  Always returns 1 (== "keep executing commands").
s32 sub_08155370(union AnimCmd cursor, struct Sprite *sprite) {
    const void *src;
    u16 size;

    sprite->animCursor += sizeof(struct AnimCmd_GetTiles) / 4;
    if (!(sprite->unk8 & 0x80000)) {
        if (cursor.getTiles->tileIndex < 0) {
            src = gSpriteTables->tiles8bpp + 0x40 * cursor.getTiles->tileIndex;
            size = 0x40 * cursor.getTiles->numTilesToCopy;
        } else {
            src = gSpriteTables->tiles4bpp + 0x20 * cursor.getTiles->tileIndex;
            size = 0x20 * cursor.getTiles->numTilesToCopy;
        }
        gUnk_03002EC0[gUnk_030039A4].unk0 = (uintptr_t)src;
        gUnk_03002EC0[gUnk_030039A4].unk4 = sprite->tilesVram;
        gUnk_03002EC0[gUnk_030039A4].unk8 = size;
        gUnk_030039A4 = (gUnk_030039A4 + 1) & 0x3F;
    }
    return 1;
}

// gUnk_08D6081C[1].  Always returns 1.  OBJ-palette twin of
// AnimCmd_GetPalette_2 (src/sprite_1.c), which targets gBgPalette instead.
s32 sub_08155400(union AnimCmd cursor, struct Sprite *sprite) {
    s32 idx;

    sprite->animCursor += sizeof(struct AnimCmd_GetPalette) / 4;
    if (!(sprite->unk8 & 0x40000)) {
        idx = cursor.getPalette->palId;
        if (gMainFlags & MAIN_FLAG_OBJ_PALETTE_TRANSFORMATION_ENABLE) {
            LoadObjPaletteWithTransformation(gSpriteTables->palette + 0x10 * idx,
                0x10 * sprite->palId + cursor.getPalette->insertOffset,
                cursor.getPalette->numColors);
        } else {
            DmaCopy16(3,
                gSpriteTables->palette + 0x10 * idx,
                &gObjPalette[0x10 * sprite->palId + cursor.getPalette->insertOffset],
                cursor.getPalette->numColors * sizeof(u16));
            gMainFlags |= MAIN_FLAG_OBJ_PALETTE_SYNC_ENABLE;
        }
    }
    return 1;
}

// gUnk_08D6081C[5].  Always returns 1.
// Installs a collision/hit box into sprite->unk20[].  The slot index is the
// low nibble of the incoming box's unk0, so unk20 IS a real array (0..15).
s32 sub_08155494(union AnimCmd cursor, struct Sprite *sprite) {
    u8 idx = cursor._6->unk4.unk0 & 0xF;

    sprite->animCursor += sizeof(struct AnimCmd_6) / 4;
    DmaCopy32(3, &cursor._6->unk4, &sprite->unk20[idx], sizeof(struct Sprite_20));
    if (!cursor._6->unk4.unk4
        && !cursor._6->unk4.unk5
        && !cursor._6->unk4.unk6
        && !cursor._6->unk4.unk7) {
        sprite->unk20[idx].unk0 = -1;
    } else {
        // hflip/vflip mirror the box: swap the two bounds and negate both.
        if (sprite->unk8 & 0x800) {
            XorSwap(sprite->unk20[idx].unk5, sprite->unk20[idx].unk7);
            sprite->unk20[idx].unk5 = -sprite->unk20[idx].unk5;
            sprite->unk20[idx].unk7 = -sprite->unk20[idx].unk7;
        }
        if (sprite->unk8 & 0x400) {
            XorSwap(sprite->unk20[idx].unk4, sprite->unk20[idx].unk6);
            sprite->unk20[idx].unk4 = -sprite->unk20[idx].unk4;
            sprite->unk20[idx].unk6 = -sprite->unk20[idx].unk6;
        }
    }
    return 1;
}

// Angle of the vector (x, y), in 1024ths of a turn (0..0x3FF).
// Returns (u16)-1 == 0xFFFF for the zero vector -- callers test for that, so a
// stub returning 0 reads as "pointing right" rather than "no direction".
u16 sub_08154FE8(s16 x, s16 y) {
    u8 octants[8] = { 1, 0, 2, 3, 6, 7, 5, 4 };
    u16 ux = x;
    u16 uy = y;
    u8 idx = 0;
    u16 ratio;

    if (((s16)ux | (s16)uy) == 0)
        return -1;
    if ((s16)ux <= 0) {
        ux = -(s16)ux;
        idx = 4;
    }
    if ((s16)uy <= 0) {
        uy = -(s16)uy;
        idx = idx + 2;
    }
    if ((s16)ux >= (s16)uy) {
        uy = (s16)uy << 7;
        if ((s16)ux == 0)
            ratio = uy;
        else
            ratio = (s16)uy / (s16)ux;
    } else {
        idx = idx + 1;
        ux = (s16)ux << 7;
        if ((s16)uy == 0)
            ratio = ux;
        else
            ratio = (s16)ux / (s16)uy;
    }
    if (octants[idx] & 1)
        ratio = 0x80 - (s16)ratio;
    return ((s16)ratio + (octants[idx] << 7)) & 0x3FF;
}

#include "trig.h"
#include "gba/syscall.h"

// Build a BG affine transform (REG_BGxPA..BGxY) for `angle` (0..0x3FF, in
// 1024ths of a turn), independent X/Y zoom factors, a world position (x, y)
// and a screen-space rotation centre (centerX, centerY).
//
// The zooms are RECIPROCALS: 0x10000 / xScale is the horizontal step, so a
// larger xScale zooms IN.  0x40/0x40 (see dark_mind.c) is 1:1... no: Div gives
// 0x10000/0x40 = 0x400, times cos>>6 (0x100 at angle 0) >> 8 = 0x400 -> 4x.
// Callers pass the *effective zoom* in 1/0x100 units of a full screen step.
//
// No return value; writes 0x10 bytes at `dst`.
void sub_081548A8(u16 angle, s16 xScale, s16 yScale, s16 x, s16 y, s16 centerX, s16 centerY,
                  struct BgAffineReg *dst)
{
    s16 cos = gSineTable[angle + 0x100] >> 6;

    dst->pa = ((s16)Div(0x10000, xScale) * cos) >> 8;
    dst->pb = ((s16)Div(0x10000, xScale) * (s16)(gSineTable[angle] >> 6)) >> 8;
    /* NB: negate the raw table entry and *then* shift -- not -(entry >> 6). */
    dst->pc = ((s16)Div(0x10000, yScale) * (s16)(-gSineTable[angle] >> 6)) >> 8;
    dst->pd = ((s16)Div(0x10000, yScale) * cos) >> 8;

    dst->x = (s16)dst->pa * -centerX + (s16)dst->pb * -centerY + (x << 8);
    dst->y = (s16)dst->pc * -centerX + (s16)dst->pd * -centerY + (y << 8);
}

// VBlank/main-loop worker #1 (gUnk_08D5FDD4[1], src/main.c:54).
//
// Services the four pending "fill a rectangle of a BG tilemap" requests.  Each
// BG i owns a 4-byte record gUnk_03002E80[i*4 .. i*4+3] = { left, top, right,
// bottom } in tile units, plus one fill byte in gUnk_030060A0.parts[i].  For
// every BG with a non-empty record this DMA-fills the rectangle inside that
// BG's screen base block and then zeroes the record.
//
// RETURN VALUE IS LOAD-BEARING: always 1.  main.c's worker list treats 0 as
// "not finished" and will stop running tasks forever if this ever returns 0.
u32 sub_08154B14(void)
{
    u16 src;
    u32 zero;
    u8 i, y;

    for (i = 0; i < 4; i++) {
        u8 *req = &gUnk_03002E80[i * 4];
        u16 bgCnt = gBgCntRegs[i];
        u8 *base = (u8 *)(0x06000000 + ((bgCnt & 0x1F00) << 3));
        u8 left = req[0];
        u8 top = req[1];

        // empty request: both axis pairs collapsed
        if (req[1] == req[3] && req[0] == req[2])
            continue;

        if (i > 1 && (gDispCnt & 3) != 0) {
            // Rotation/scaling BG: the map is one BYTE per tile and its width
            // is 16 << screenSize tiles.
            u32 width = 0x10 << (bgCnt >> 14);
            u8 fill = gUnk_030060A0.parts[i];

            base += left;
            if (req[3] == 0xFF) {
                // "to the bottom": one shot over whole rows.
                src = fill | (fill << 8);
                DmaFill16(3, src, base + width * top, (req[3] - top) * width);
            } else if (top <= req[3]) {
                for (y = top; y <= req[3]; y++) {
                    src = fill | (fill << 8);
                    // BUG (reproduced): the span is already in bytes, so this
                    // extra >> 1 makes the fill cover only half the requested
                    // width in rotation BG modes.
                    DmaFill16(3, src, base + width * y, (req[2] - left + 1) >> 1);
                }
            }
        } else {
            // Text BG: two bytes per tile.  Row stride is 64 tiles for screen
            // sizes 2 and 3, otherwise 32.
            u32 width = 0x20;

            base += left * 2;
            if ((u8)((gBgCntRegs[i] >> 14) - 2) <= 1)
                width = 0x40;

            if (req[2] == 0xFF) {
                src = gUnk_030060A0.parts[i];
                DmaFill16(3, src, base + (width * 2) * top, (req[3] - top) * width * 2);
            } else if (top <= req[3]) {
                for (y = top; y <= req[3]; y++) {
                    src = gUnk_030060A0.parts[i];
                    DmaFill16(3, src, base + (width * 2) * y, (req[2] - left + 1) * 2);
                }
            }
        }

        zero = 0;
        DmaFill32(3, zero, req, 4);
    }
    return 1;
}

// Rotate/scale one sprite.  `transform` is a 5-entry s16 array:
//   [0] angle (0..0x3FF), [1] x zoom, [2] y zoom, [3] base x, [4] base y.
//
// Writes the OAM affine matrix selected by s->unk8 & 0x1F (gOamBuffer + 6 +
// 32*index, the pa/pb/pc/pd slots interleaved through four OAM entries) and
// then rewrites s->x / s->y so the sprite's on-screen anchor stays put under
// the transform.  Negative zooms mean "mirror on that axis": the matrix keeps
// the sign but the offset maths uses |zoom| and the mirrored hot-spot.
//
// No return value.  Does nothing at all when s->unk4 == -1 (no frame).
void sub_08155604(struct Sprite *s, s16 *transform)
{
    const struct SpriteAttributes_Sub *attr;
    const u8 *tableBase;
    u16 *matrix;
    u16 oamIndex;
    s32 angle;
    s16 cos, sin;
    s16 xScale, yScale;
    s16 m00, m01, m10, m11;
    s32 x, y;
    s16 ox, oy;
    s32 dx, dy;
    u16 halfW, halfH;

    if (s->unk4 == -1)
        return;

    // The high nibble of unk4 selects the wide (0x10-byte) attribute record.
    tableBase = (const u8 *)gSpriteTables->attrs[s->animId].sub;
    if ((u32)s->unk4 >> 28)
        attr = (const struct SpriteAttributes_Sub *)(tableBase + s->unk4 * 0x10);
    else
        attr = (const struct SpriteAttributes_Sub *)(tableBase + s->unk4 * 0xC);

    oamIndex = s->unk8 & 0x1F;
    matrix = (u16 *)((u8 *)gOamBuffer + 6 + oamIndex * 32);

    angle = transform[0] & 0x3FF;
    cos = gSineTable[angle + 0x100] >> 6;
    sin = gSineTable[angle] >> 6;
    xScale = transform[1];
    yScale = transform[2];

    matrix[0] = ((s16)Div(0x10000, xScale) * cos) >> 8;
    matrix[4] = ((s16)Div(0x10000, xScale) * sin) >> 8;
    matrix[8] = ((s16)Div(0x10000, yScale) * -sin) >> 8;
    matrix[12] = ((s16)Div(0x10000, yScale) * cos) >> 8;

    // From here on the scales are taken as magnitudes.
    if (transform[1] < 0)
        xScale = -transform[1];
    if (transform[2] < 0)
        yScale = -transform[2];

    m00 = (cos * xScale) >> 8;
    m01 = (-sin * xScale) >> 8;
    m10 = (sin * yScale) >> 8;
    m11 = (cos * yScale) >> 8;

    x = transform[3];
    y = transform[4];

    // Hot spot relative to the frame's centre, mirrored when the zoom is
    // negative (offset measured from the far edge instead).
    if (transform[1] > 0)
        ox = attr->offsetX;
    else
        ox = attr->width - attr->offsetX;
    if (transform[2] > 0)
        oy = attr->offsetY;
    else
        oy = attr->height - attr->offsetY;

    halfW = attr->width >> 1;
    halfH = attr->height >> 1;
    dx = ox - halfW;
    dy = oy - halfH;

    s->x = x - ((dx * m00 + dy * m01 + (halfW << 8)) >> 8);
    s->y = y - ((dx * m10 + dy * m11 + (halfH << 8)) >> 8);
}

/* gUnk_08D5FDD4[2] -- one of src/main.c's four VRAM-transfer workers.
 *
 * Drains the BG-sprite queue that sub_08154148() (src/sprite_1.c) fills:
 * gUnk_03006030[0 .. gUnk_030068B0-1] holds every struct Sprite that was
 * asked to render into a *background tilemap* rather than into OAM. For each
 * one it walks the frame's OAM subframe list, and for every subframe stamps a
 * rectangle of tile entries into the BG's screen-base block, computing the
 * entry value from (sprite->tilesVram - charBase) >> shift plus the subframe's
 * attr2 tile number.
 *
 * RETURN PROTOCOL -- LOAD-BEARING, do not stub with 0:
 *   0 = "did NOT finish". Only returned when V-Blank is already over
 *       (REG_DISPSTAT & DISPSTAT_VBLANK clear) on entry; nothing is drawn and
 *       the queue is left intact for the next frame. src/main.c latches the
 *       worker index into gUnk_030035D4 and BREAKS out of the worker chain.
 *   1 = finished. Either the queue was already empty, or it was fully drawn
 *       and gUnk_030068B0 has been reset to 0.
 *
 * Two BG layouts are handled:
 *   - affine (bg 2/3 while gDispCnt mode != 0): 1-byte map entries, so the
 *     writes are done as read-modify-write halfword stores because GBA VRAM
 *     ignores 8-bit writes. No flip and no palette bits.
 *   - text (bg 0/1, or any bg in mode 0): 2-byte map entries carrying tile,
 *     hflip (0x400), vflip (0x800) and palette (0xF000).
 *
 * Note `shift` is deliberately hoisted out of the per-sprite loop: the
 * original sets it to 5 once on entry and to 6 whenever it meets a 256-colour
 * BG, and never resets it, so a 256-colour BG makes every later sprite in the
 * same pass use the 8bpp shift too. Faithful to the ROM. */
u32 sub_0815436C(void)
{
    u32 shift = 5;
    u8 i;

    if (!(REG_DISPSTAT & DISPSTAT_VBLANK))
        return 0;

    if (gUnk_030068B0 == 0)
        return 1;

    for (i = 0; i < gUnk_030068B0; i++) {
        struct Sprite *sprite = gUnk_03006030[i];
        u32 frame = sprite->unk4;
        const struct SpriteAttributes_Sub *attr;
        u32 bg, mapWidth, charBase, screenBase;
        u16 bgcnt;
        const u16 *src;
        u16 sp00[3];
        u8 j;

        if (frame == (u32)-1)
            continue;

        if (!(frame >> 28))
            attr = &gSpriteTables->attrs[sprite->animId].sub[frame];
        else
            attr = &gSpriteTables->attrs[sprite->animId].full[frame].sub;

        bg = (sprite->unk8 & 0x18000) >> 15;
        bgcnt = gBgCntRegs[bg];
        charBase = ((bgcnt & 0xC) << 12) + 0x06000000;
        screenBase = ((bgcnt & 0x1F00) << 3) + 0x06000000;
        if (bgcnt & 0x80)
            shift = 6;

        if (bg > 1 && (gDispCnt & 3) != 0) {
            /* ---- affine BG: 8-bit map entries ---- */
            u32 pend = 0;

            mapWidth = (0x00100000u << (bgcnt >> 14)) >> 16;
            src = gSpriteTables->oamData[sprite->animId]
                + 3 * (attr->bitfield & 0x3FFF);

            for (j = 0; j < attr->numSubframes; j++) {
                u32 sas, wTiles, hTiles, tile;
                s32 x, y;
                u8 *dst;
                s8 rowStep = (u8)mapWidth;

                DmaCopy16(3, src, sp00, 6);
                src += 3;

                sas = ((sp00[0] & 0xC000) >> 12) | ((sp00[1] & 0xC000) >> 14);
                wTiles = gUnk_08D6084C[sas][0] >> 3;
                hTiles = gUnk_08D6084C[sas][1] >> 3;

                y = sprite->y - attr->offsetY;
                x = (sprite->x - attr->offsetX) & -16;

                dst = (u8 *)(screenBase + mapWidth * ((y + (sp00[0] & 0xFF)) >> 3));
                tile = ((((u32)sprite->tilesVram - charBase) >> shift)
                        + (sp00[2] & 0x3FF)) & 0xFF;

                for (; hTiles != 0; --hTiles) {
                    u8 *p = dst + (((s32)(sp00[1] & 0x1FF) + x) >> 3);
                    u32 n = wTiles;

                    for (; n != 0; --n) {
                        if ((uintptr_t)p & 1) {
                            pend = (u16)(pend | (tile << 8));
                            *(u16 *)(p - 1) = pend;
                        } else {
                            pend = tile;
                        }
                        tile = (u16)(tile + 1);
                        ++p;
                    }
                    if ((uintptr_t)p & 1) {
                        u16 *q = (u16 *)(p - 1);

                        *q = (*q & 0xFF00) | pend;
                    }
                    dst += rowStep;
                }
            }
        } else {
            /* ---- text BG: 16-bit map entries ---- */
            mapWidth = 0x20;
            if ((u8)((gBgCntRegs[bg] >> 14) - 2) <= 1)
                mapWidth = 0x40;

            src = gSpriteTables->oamData[sprite->animId]
                + 3 * (attr->bitfield & 0x3FFF);

            for (j = 0; j < attr->numSubframes; j++) {
                u32 sas, wTiles, hTiles, tile, oamX, oamY;
                s32 x, y, xoff;
                u8 *dst;
                s8 colStep, rowStep;

                DmaCopy16(3, src, sp00, 6);
                src += 3;

                sas = ((sp00[0] & 0xC000) >> 12) | ((sp00[1] & 0xC000) >> 14);
                wTiles = gUnk_08D6084C[sas][0] >> 3;
                hTiles = gUnk_08D6084C[sas][1] >> 3;
                oamX = sp00[1] & 0x1FF;
                oamY = sp00[0] & 0xFF;
                sp00[2] += sprite->palId << 12;

                if (((sprite->unk8 >> 11) & 1) != (u32)(attr->bitfield >> 15)) {
                    sp00[1] ^= 0x2000;
                    if (attr->bitfield & 0x4000)
                        y = sprite->y + attr->offsetY;
                    else
                        y = sprite->y + (attr->height - attr->offsetY);
                    y -= 8;
                    oamY = (u16)-oamY;
                } else {
                    y = sprite->y - attr->offsetY;
                }

                if ((((u32)(attr->bitfield >> 14)) ^ (sprite->unk8 >> 10)) & 1) {
                    sp00[1] ^= 0x1000;
                    if (attr->bitfield & 0x4000)
                        x = sprite->x + attr->offsetX;
                    else
                        x = sprite->x + (attr->width - attr->offsetX);
                    x -= 8;
                    oamX = (u16)-oamX;
                } else {
                    x = sprite->x - attr->offsetX;
                }

                x &= -16;
                y &= -8;

                colStep = (sp00[1] & 0x1000) ? -2 : 2;
                rowStep = (sp00[1] & 0x2000) ? (u8)(-(mapWidth << 25) >> 24)
                                             : (u8)((mapWidth << 25) >> 24);

                dst = (u8 *)(screenBase + mapWidth * ((y + (s32)(s16)oamY) >> 2));
                tile = (u16)(((((u32)sprite->tilesVram - charBase) >> shift)
                              + (sp00[2] & 0xF3FF))
                             + ((sp00[1] & 0x3000) >> 2));

                if (hTiles == 0)
                    continue;

                xoff = ((s32)(s16)oamX + x) >> 2;
                for (; hTiles != 0; --hTiles) {
                    u8 *p = dst + xoff;
                    u32 n = wTiles;

                    for (; n != 0; --n) {
                        *(u16 *)p = tile;
                        tile = (u16)(tile + 1);
                        p += colStep;
                    }
                    dst += rowStep;
                }
            }
        }
    }

    gUnk_030068B0 = 0;
    return 1;
}
