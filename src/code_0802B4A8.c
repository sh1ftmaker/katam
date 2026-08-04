#include "global.h"
#include "main.h"
#include "malloc_vram.h"
#include "sprite.h"
#include "task.h"
#include "data.h"
#include "gba/m4a.h"

struct Unk_0802B4A8 {
    /* 0x000 */ void (*unk0)(struct Unk_0802B4A8 *);
    /* 0x004 */ struct Sprite unk4[5];
    /* 0x0CC */ struct Sprite unkCC;
    /* 0x0F4 */ struct Sprite unkF4;
    /* 0x11C */ struct Sprite unk11C;
    /* 0x144 */ struct Sprite unk144;
    /* 0x16C */ struct Sprite unk16C;
    /* 0x194 */ u8 filler194[0x214 - 0x194];
    /* 0x214 */ u32 unk214;
    /* 0x218 */ u32 unk218[5][2];
    /* 0x240 */ u16 unk240[5][2];
    /* 0x254 */ u16 unk254[5];
    /* 0x25E */ u8 filler25E[0x274 - 0x25E];
    /* 0x274 */ s32 unk274;
    /* 0x278 */ s32 unk278;
    /* 0x27C */ s32 unk27C;
    /* 0x280 */ s32 unk280;
    /* 0x284 */ u8 filler284[0x2A0 - 0x284];
    /* 0x2A0 */ s32 unk2A0;
    /* 0x2A4 */ s32 unk2A4;
    /* 0x2A8 */ s32 unk2A8;
    /* 0x2AC */ s32 unk2AC;
    /* 0x2B0 */ s32 unk2B0;
    /* 0x2B4 */ s32 unk2B4;
    /* 0x2B8 */ u16 unk2B8;
    /* 0x2BA */ u16 unk2BA;
    /* 0x2BC */ u16 unk2BC;
    /* 0x2BE */ u16 unk2BE;
}; /* size = 0x2C0 */

struct Unk_0802D898 {
    /* 0x00 */ void (*unk0)(struct Unk_0802D898 *);
    /* 0x04 */ u8 filler4[0x44 - 0x04];
    /* 0x44 */ struct Unk_0802B4A8 *unk44;
    /* 0x48 */ u16 unk48;
    /* 0x4A */ u16 unk4A;
    /* 0x4C */ u16 unk4C;
};

extern u32 gUnk_082EB4EC[][2];
extern u32 gUnk_082EB514[][2];
extern u32 gUnk_082EB564[][2];
extern u16 gUnk_082EB640[][6][2];
extern u16 gUnk_082EB5B4[];
extern u16 gUnk_0300000C;

void sub_0802BA6C(void);
void sub_0802BCEC(struct Unk_0802B4A8 *);
void sub_0802BF68(struct Unk_0802B4A8 *);
void sub_0802C1D8(struct Unk_0802B4A8 *);
void sub_0802C308(struct Unk_0802B4A8 *);
void sub_0802C3C8(struct Unk_0802B4A8 *);
void sub_0802C550(struct Unk_0802B4A8 *);
void sub_0802C8E8(struct Unk_0802B4A8 *);
void sub_0802D360(struct Task *);
void sub_0802D4E0(struct Unk_0802B4A8 *);
void sub_0802D564(struct Unk_0802B4A8 *);
void sub_0802D588(struct Unk_0802B4A8 *);
void sub_0802D5B0(struct Unk_0802B4A8 *);
void sub_0802D618(struct Unk_0802B4A8 *);
void sub_0802D664(struct Unk_0802B4A8 *);
void sub_0802D6B4(struct Unk_0802B4A8 *);
void sub_0802D6D8(struct Unk_0802B4A8 *);
void sub_0802D738(struct Unk_0802B4A8 *);
void sub_0802D75C(struct Unk_0802B4A8 *);
void sub_0802D7DC(struct Unk_0802B4A8 *);
void sub_0802D824(struct Unk_0802B4A8 *);
void sub_0802D84C(struct Unk_0802B4A8 *);
void sub_0802D9B8(struct Unk_0802B4A8 *);
void sub_0802D9F4(struct Unk_0802B4A8 *);
void sub_0802DA54(struct Unk_0802B4A8 *);
void sub_0802DAA0(struct Unk_0802B4A8 *);
void sub_0802DAB4(struct Unk_0802B4A8 *);
void sub_0802DAC8(struct Unk_0802B4A8 *);
void sub_0802DB00(struct Unk_0802B4A8 *);
void sub_0802DB34(struct Unk_0802B4A8 *);
void sub_0802DB48(struct Unk_0802B4A8 *);
void sub_0802DBC0(struct Unk_0802B4A8 *);
void sub_0802DC10(struct Unk_0802B4A8 *);
void sub_0802DC34(struct Unk_0802B4A8 *);
void sub_0802DC58(struct Unk_0802B4A8 *);
void sub_0802DCC4(struct Unk_0802B4A8 *);
void sub_0802DD18(struct Unk_0802B4A8 *);
void sub_0802BFBC(struct Unk_0802B4A8 *);
void sub_0802C064(struct Unk_0802B4A8 *);
void sub_0802CC7C(struct Unk_0802D898 *);
void sub_0802CDF8(struct Unk_0802D898 *);
void sub_0802D8AC(struct Unk_0802D898 *);
void sub_0802D8F4(struct Unk_0802D898 *);
void sub_0802D940(struct Unk_0802D898 *);
void sub_0802D964(struct Unk_0802D898 *);
void sub_0802D9A4(struct Unk_0802D898 *);
void sub_0802C5E4(struct Unk_0802B4A8 *);
void sub_0802C360(struct Unk_0802B4A8 *);
void sub_0802DE94(struct Unk_0802B4A8 *);
void sub_0802DEB8(struct Unk_0802B4A8 *);
void sub_0802DEE0(struct Unk_0802B4A8 *);
void sub_0802DF30(struct Unk_0802B4A8 *);
void sub_0802DFA0(struct Unk_0802B4A8 *);
void sub_0802DFB4(struct Unk_0802B4A8 *);
void sub_0802E01C(struct Unk_0802B4A8 *);
void sub_0802E040(struct Unk_0802B4A8 *);
void sub_0802E064(struct Unk_0802B4A8 *);
void sub_0802E088(struct Unk_0802B4A8 *);
void sub_0802E0D4(struct Unk_0802B4A8 *);
void sub_0802E0E8(struct Unk_0802B4A8 *);
void sub_0802E11C(struct Unk_0802B4A8 *);

void sub_0802B4A8(void) {
    struct Task *t;
    struct Unk_0802B4A8 *tp;
    struct Unk_0802B4A8 *x;
    u16 i;

    CpuFill32(0x7FFF, gBgPalette, 0x200);
    CpuFill32(0x7FFF, gObjPalette, 0x200);
    gMainFlags |= 3;
    gBldRegs.bldCnt = 0xBF;
    gBldRegs.bldY = 0x10;
    t = TaskCreate(sub_0802BA6C, 0x2C0, 0x100, 0, sub_0802D360);
    tp = TaskGetStructPtr(t);
    x = tp;
    CpuFill16(0, tp, 0x2C0);
    x->unk2B8 = 0x200;
    SpriteInit(&x->unk16C, VramMalloc(0x100), 0, 0x292, 0, 0, 0xFF, 0x10, 0xD, 0, 0, 0);
    for (i = 0; i < 5; i++) {
        x->unk4[i].tilesVram = VramMalloc(0x10);
        x->unk218[i][0] = gUnk_082EB4EC[i][0];
        x->unk218[i][1] = gUnk_082EB4EC[i][1];
        x->unk254[i] = gUnk_082EB5B4[i];
    }
    x->unkCC.tilesVram = VramMalloc(0x10);
    x->unkF4.tilesVram = VramMalloc(0x30);
    x->unk11C.tilesVram = VramMalloc(0x30);
    x->unk144.tilesVram = VramMalloc(0x10);
    gUnk_0300000C = 0;
    x->unk0 = sub_0802BCEC;
}

void sub_0802D360(struct Task *t) {
    struct Unk_0802B4A8 *tmp = TaskGetStructPtr(t), *x = tmp;
    u16 i;

    for (i = 0; i < 5; i++) {
        VramFree(x->unk4[i].tilesVram);
    }
    VramFree(x->unkCC.tilesVram);
    VramFree(x->unkF4.tilesVram);
    VramFree(x->unk11C.tilesVram);
    VramFree(x->unk144.tilesVram);
    VramFree(x->unk16C.tilesVram);
}

void sub_0802D3E0(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802BF68;
}

void sub_0802D3F4(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802D564;
}

void sub_0802D408(struct Unk_0802B4A8 *x) {
    x->unk214 |= 0x08000000;
    x->unk2BC = 0;
    x->unk0 = sub_0802D588;
}

void sub_0802D430(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802D5B0;
}

void sub_0802D444(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802D738;
}

void sub_0802D458(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802D75C;
}

void sub_0802D46C(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802D7DC;
}

void sub_0802D480(struct Unk_0802B4A8 *x) {
    gBgPalette[0] = 0x7FFF;
    gMainFlags |= 1;
    gDispCnt = 0x1040;
    gBldRegs.bldCnt = 0;
    gBldRegs.bldY = 0;
    x->unk214 = (x->unk214 & 0xFBF7FFFF) | 0x10800000;
    x->unk0 = sub_0802D4E0;
}

void sub_0802D4E0(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802D824;
}

void sub_0802D4F4(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    gBldRegs.bldCnt = 0xBF;
    gBldRegs.bldY = 0;
    x->unk214 |= 0x20000000;
    x->unk0 = sub_0802D84C;
}

void sub_0802D528(struct Unk_0802B4A8 *x) {
    TaskDestroy(gCurTask);
}

void sub_0802D53C(struct Unk_0802B4A8 *x) {
    TaskDestroy(gCurTask);
}

void sub_0802D550(struct Unk_0802B4A8 *x) {
    TaskDestroy(gCurTask);
}

void sub_0802D564(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802D9B8;
    }
}

void sub_0802D588(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x168) {
        x->unk0 = sub_0802D9F4;
    }
}

void sub_0802D5B0(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802DA54;
    }
}

void sub_0802D5D4(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    gBldRegs.bldCnt = 0xBF;
    gBldRegs.bldY = 0;
    m4aSongNumStart(0x213);
    x->unk214 |= 0x20000000;
    x->unk0 = sub_0802D618;
}

void sub_0802D618(struct Unk_0802B4A8 *x) {
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0xF) {
        gBldRegs.bldY = 0x10;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802D664;
    } else {
        gBldRegs.bldY = t;
    }
}

void sub_0802D664(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk240[x->unk2BE][0] = 0;
    x->unk240[x->unk2BE][1] = 0;
    x->unk214 &= ~(7 << (x->unk2BE * 3));
    x->unk0 = sub_0802D6B4;
}

void sub_0802D6B4(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802D6D8;
    }
}

void sub_0802D6D8(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    gBldRegs.bldY = 0x10;
    x->unk214 |= 0x20000000;
    x->unk0 = sub_0802C308;
}

void sub_0802D708(struct Unk_0802B4A8 *x) {
    if (++x->unk2BE <= 3) {
        x->unk0 = sub_0802C1D8;
    } else {
        x->unk0 = sub_0802DAA0;
    }
}

void sub_0802D738(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x78) {
        x->unk0 = sub_0802C3C8;
    }
}

void sub_0802D75C(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802C550;
    }
}

void sub_0802D780(struct Unk_0802B4A8 *x) {
    if (x->unk2A8 > 0xC800) {
        x->unk2A0 = 0;
        x->unk214 &= 0xFFF7FFFF;
        x->unk0 = sub_0802DAB4;
    }
    x->unk2B0 += 0x40;
    if (x->unk2B0 > 0x400) {
        x->unk2B0 = 0x400;
    }
    x->unk2A8 += x->unk2B0;
}

void sub_0802D7DC(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802DAC8;
    }
}

void sub_0802D800(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802DB00;
    }
}

void sub_0802D824(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x1E0) {
        x->unk0 = sub_0802C8E8;
    }
}

void sub_0802D84C(struct Unk_0802B4A8 *x) {
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0xF) {
        gBldRegs.bldY = 0x10;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802DB34;
    } else {
        gBldRegs.bldY = t;
    }
}

void sub_0802D898(struct Unk_0802D898 *x) {
    x->unk4A = 0;
    x->unk0 = sub_0802D8AC;
}

void sub_0802D8AC(struct Unk_0802D898 *x) {
    if (gUnk_082EB640[gLanguage][x->unk4C][1] < x->unk4A++) {
        x->unk0 = sub_0802D8F4;
    }
}

void sub_0802D8F4(struct Unk_0802D898 *x) {
    gBldRegs.bldCnt = 0x1344;
    gBldRegs.bldAlpha = 0x10;
    x->unk4A = 0;
    x->unk44->unk214 |= 0x20000000;
    x->unk0 = sub_0802CDF8;
}

void sub_0802D92C(struct Unk_0802D898 *x) {
    x->unk4A = 0;
    x->unk0 = sub_0802D940;
}

void sub_0802D940(struct Unk_0802D898 *x) {
    if (x->unk4A++ > 0x1E) {
        x->unk0 = sub_0802D964;
    }
}

void sub_0802D964(struct Unk_0802D898 *x) {
    if (++x->unk4C <= 5) {
        x->unk0 = sub_0802CC7C;
    } else {
        x->unk44->unk214 |= 0x02000000;
        x->unk0 = sub_0802D9A4;
    }
}

void sub_0802D9A4(struct Unk_0802D898 *x) {
    TaskDestroy(gCurTask);
}

void sub_0802D9B8(struct Unk_0802B4A8 *x) {
    u16 i;

    for (i = 0; i < 4; i++) {
        x->unk240[i][0] = gUnk_082EB514[i][0];
    }
    sub_0802DB48(x);
    x->unk0 = sub_0802BFBC;
}

void sub_0802D9F4(struct Unk_0802B4A8 *x) {
    u16 i;

    for (i = 0; i < 5; i++) {
        x->unk240[i][0] = gUnk_082EB564[i][0];
        x->unk240[i][1] = gUnk_082EB564[i][1];
    }
    x->unk0 = sub_0802C064;
}

void sub_0802DA54(struct Unk_0802B4A8 *x) {
    x->unk274 = 0x7800;
    x->unk278 = 0xB400;
    x->unk27C = 0;
    x->unk280 = -0x100;
    x->unk214 |= 0x8000;
    x->unk0 = sub_0802DBC0;
}

void sub_0802DAA0(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802DC10;
}

void sub_0802DAB4(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802DC34;
}

void sub_0802DAC8(struct Unk_0802B4A8 *x) {
    x->unk2A8 = -0x1000;
    x->unk214 |= 0x80000;
    x->unk144.unk1B = 0xFF;
    x->unk0 = sub_0802DC58;
}

void sub_0802DB00(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    gBldRegs.bldCnt = 0xAF;
    gBldRegs.bldY = 0x10;
    x->unk214 |= 0x20000000;
    x->unk0 = sub_0802DCC4;
}

void sub_0802DB34(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802DD18;
}

void sub_0802DDC0(struct Unk_0802B4A8 *x) {
    gDispCnt = 0x1040;
    x->unk214 &= 0xFAFFFFFF;
    x->unk0 = sub_0802C5E4;
}

void sub_0802DDEC(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802DE94;
}

void sub_0802DE00(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802DEB8;
}

void sub_0802DE14(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802DEE0;
    }
}

void sub_0802DE94(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x1E) {
        x->unk0 = sub_0802DF30;
    }
}

void sub_0802DEB8(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3FC) {
        x->unk0 = sub_0802DFB4;
    }
}

void sub_0802DEE0(struct Unk_0802B4A8 *x) {
    x->unk4[4].animId = 0x2D;
    x->unk4[4].variant = 7;
    x->unk2BE = 0;
    x->unk2BC = 0;
    x->unk0 = sub_0802E01C;
}

void sub_0802DF0C(struct Unk_0802B4A8 *x) {
    x->unk4[4].animId = 0x2D;
    x->unk4[4].variant = 4;
    x->unk2BC = 0;
    x->unk0 = sub_0802E040;
}

void sub_0802DFA0(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802E064;
}

void sub_0802DFB4(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    gBldRegs.bldCnt = 0xBF;
    gBldRegs.bldY = 0;
    m4aMPlayFadeOut(&gMPlayInfo_0, 8);
    m4aMPlayFadeOut(&gMPlayInfo_1, 8);
    m4aMPlayFadeOut(&gMPlayInfo_2, 8);
    m4aMPlayFadeOut(&gMPlayInfo_3, 8);
    x->unk214 |= 0x20000000;
    x->unk0 = sub_0802E088;
}

void sub_0802E01C(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0xB4) {
        x->unk0 = sub_0802C1D8;
    }
}

void sub_0802E040(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802E0D4;
    }
}

void sub_0802E064(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0xB4) {
        x->unk0 = sub_0802E0E8;
    }
}

void sub_0802E088(struct Unk_0802B4A8 *x) {
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0xF) {
        gBldRegs.bldY = 0x10;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802D480;
    } else {
        gBldRegs.bldY = t;
    }
}

void sub_0802E0D4(struct Unk_0802B4A8 *x) {
    x->unk240[4][0] = 0;
    x->unk0 = sub_0802C360;
}

void sub_0802E0E8(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    gBldRegs.bldCnt = 0xBF;
    gBldRegs.bldY = 0;
    x->unk214 |= 0x20000000;
    x->unk0 = sub_0802E11C;
}
