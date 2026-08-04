#include "global.h"
#include "data.h"
#include "functions.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "gba/macro.h"

// TODO: these fields belong in `struct Unk_08002E48` in include/data.h
// (offsets 0x02..0x23 are currently covered by `u8 filler[0x23]`).
struct Unk_08002E48_2 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 filler1[1];
    /* 0x02 */ u16 dispCnt;
    /* 0x04 */ u16 bgCnt[4];
    /* 0x0C */ s16 bgScroll[4][2];
    /* 0x1C */ struct BlendRegs bldRegs;
    /* 0x24 */ union Unk_03002E60 *unk24;
}; /* size = 0x28 */

// TODO: belongs in include/data.h (defined in src/code_080023A4.c)
extern struct RoomTiledBG *const gUnk_082D8D74[];

// TODO: belongs in include/functions.h
void LoadLevelGfx(u8 playerId, const u16 **, const u16 **);

void sub_08000460(void)
{
    struct Unk_08002E48_2 *var0;
    u8 i;

    gDispCnt = 0x940;
    gUnk_02023350 = TaskCreate(sub_08001FF8, 0, 1, 0, (TaskDestructor)sub_08002E3C);
    gUnk_02023354 = TaskCreate(sub_08002118, 0x28, 0x7FFF, 0, sub_08002E48);
    var0 = TaskGetStructPtr(gUnk_02023354);

    gBgCntRegs[0] = 0x1F03;
    gBgCntRegs[3] = 0x1E0A;
    gBgCntRegs[2] = 0x1D09;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    gBgScrollRegs[3][0] = 0;
    gBgScrollRegs[3][1] = 0;
    gBgScrollRegs[2][0] = 0;
    gBgScrollRegs[2][1] = 0;

    var0->unk24 = (union Unk_03002E60 *)gUnk_03002E60;
    gUnk_03002E60 = (const union Unk_03002E60 *)gUnk_082D8D74;

    CpuFill32(0, gUnk_02028EE0, 1950 * 8 * 4);
    CpuFill32(0, gUnk_02024ED0, 1950 * 4);
    CpuFill32(0, gUnk_02026D60, 1954 * 4);
    CpuFill16(0, gUnk_02026D50, 8);
    sub_080027A8();
    var0->unk0 = gUnk_0203AD3C;
    CpuFill16(0, gCurLevelInfo, sizeof(gCurLevelInfo));

    for (i = 0; i < 4; i++) {
        struct LevelInfo *levelInfo = gCurLevelInfo + i;
        struct Background *bg;

        levelInfo->currentRoom |= 0xFFFF;
        levelInfo->unk65C |= 0xFFFF;

        bg = &levelInfo->unkC0[1];
        bg->tilesVram = 0x06008000;
        bg->unkA = 0;
        bg->tilemapVram = 0x0600F000;
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->unk1C = i;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->unk26 = 0x1F;
        bg->unk28 = 0x15;
        bg->paletteOffset = 0;
        bg->animFrameCounter = 0;
        bg->animDelayCounter = 0;
        bg->unk2E = 0x3B;
        bg->scrollX = 0;
        bg->scrollY = 0;
        bg->prevScrollX = 0x7FFF;
        bg->prevScrollY = 0x7FFF;

        bg = &levelInfo->unkC0[2];
        bg->tilesVram = 0x06000000;
        bg->unkA = 0;
        bg->tilemapVram = 0x0600F800;
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->unk1C = i + 4;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->unk26 = 0x1F;
        bg->unk28 = 0x15;
        bg->paletteOffset = 0;
        bg->animFrameCounter = 0;
        bg->animDelayCounter = 0;
        bg->unk2E = 0x38;
        bg->scrollX = 0;
        bg->scrollY = 0;
        bg->prevScrollX = 0x7FFF;
        bg->prevScrollY = 0x7FFF;

        bg = &levelInfo->unkC0[0];
        bg->tilesVram = 0x06008000;
        bg->unkA = 0;
        bg->tilemapVram = 0x0600E800;
        bg->unk18 = 0;
        bg->unk1A = 0;
        bg->unk1C = i + 8;
        bg->unk1E = 0;
        bg->unk20 = 0;
        bg->unk22 = 0;
        bg->unk24 = 0;
        bg->unk26 = 0x1F;
        bg->unk28 = 0x15;
        bg->paletteOffset = 0;
        bg->animFrameCounter = 0;
        bg->animDelayCounter = 0;
        bg->unk2E = 0x3A;
        bg->scrollX = 0;
        bg->scrollY = 0;
        bg->prevScrollX = 0x7FFF;
        bg->prevScrollY = 0x7FFF;
    }

    if (!(gUnk_0203AD10 & 1))
        sub_0800A820();
}

void sub_080006EC(void)
{
    struct Unk_08002E48_2 *var0 = TaskGetStructPtr(gUnk_02023354), *var1 = var0;
    u16 i;

    var1->dispCnt = gDispCnt;

    for (i = 0; i < 4; i++) {
        var1->bgCnt[i] = gBgCntRegs[i];
        var1->bgScroll[i][0] = gBgScrollRegs[i][0];
        var1->bgScroll[i][1] = gBgScrollRegs[i][1];
    }

    CpuSet(&gBldRegs, &var1->bldRegs, 2);
    gUnk_03002E60 = var1->unk24;
}

void sub_08000798(void)
{
    u8 playerId = sub_08002374();
    struct Unk_08002E48_2 *var0 = TaskGetStructPtr(gUnk_02023354), *var1 = var0;
    u16 i;

    gUnk_03002E60 = (const union Unk_03002E60 *)gUnk_082D8D74;
    gDispCnt = var1->dispCnt;

    for (i = 0; i < 4; i++) {
        gBgCntRegs[i] = var1->bgCnt[i];
        gBgScrollRegs[i][0] = var1->bgScroll[i][0];
        gBgScrollRegs[i][1] = var1->bgScroll[i][1];
    }

    CpuSet(&var1->bldRegs, &gBldRegs, 2);
    LoadLevelGfx(playerId, NULL, NULL);
    sub_08003438();

    gCurLevelInfo[playerId].unkC0[1].prevScrollX = 0x7FFF;
    gCurLevelInfo[playerId].unkC0[1].prevScrollY = 0x7FFF;
    gCurLevelInfo[playerId].unkC0[2].prevScrollX = 0x7FFF;
    gCurLevelInfo[playerId].unkC0[2].prevScrollY = 0x7FFF;
    gCurLevelInfo[playerId].unkC0[0].prevScrollX = 0x7FFF;
    gCurLevelInfo[playerId].unkC0[0].prevScrollY = 0x7FFF;
    sub_080019F8(gCurLevelInfo + playerId);
}

void LoadLevelGfx(u8 playerId, const u16 **a, const u16 **b)
{
    struct Unk_08002E48_2 *var0 = TaskGetStructPtr(gUnk_02023354);
    struct LevelInfo *levelInfo = gCurLevelInfo + playerId;

    var0->unk0 = playerId;
    gDispCnt |= 0xB00;
    LZ77UnCompVram(gForegroundInfo[gRoomProps[levelInfo->currentRoom].pixelDataIdx]->tileset, (void *)0x06008000);

    if (a != NULL)
        *a = gForegroundPalettes[gRoomProps[levelInfo->currentRoom].paletteDataIdx]->palette;

    levelInfo->unkC0[1].prevScrollX = 0x7FFF;
    levelInfo->unkC0[1].prevScrollY = 0x7FFF;
    gBgScrollRegs[3][0] = 0;
    gBgScrollRegs[3][1] = 0;
    LZ77UnCompVram(levelInfo->unk180[1].tileset, (void *)0x06000000);

    if (b != NULL)
        *b = levelInfo->unk180[1].palette;

    levelInfo->unkC0[2].prevScrollX = 0x7FFF;
    levelInfo->unkC0[2].prevScrollY = 0x7FFF;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    levelInfo->unkC0[0].prevScrollX = 0x7FFF;
    levelInfo->unkC0[0].prevScrollY = 0x7FFF;
    gBgScrollRegs[2][0] = 0;
    gBgScrollRegs[2][1] = 0;

    if (gRoomProps[levelInfo->currentRoom].objectList2Idx != 0xFFFF)
        gDispCnt |= 0x400;
    else
        gDispCnt &= 0xFBFF;

    gBgCntRegs[3] &= 0xFFFC;
    gBgCntRegs[2] &= 0xFFFC;

    if (gRoomProps[levelInfo->currentRoom].priorityFlags & 1) {
        gBgCntRegs[3] |= 2;
        gBgCntRegs[2] |= 1;
    }
    else {
        gBgCntRegs[3] |= 1;
        gBgCntRegs[2] |= 2;
    }
}
