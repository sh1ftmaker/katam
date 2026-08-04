#include "global.h"
#include "main.h"
#include "malloc_vram.h"
#include "sprite.h"
#include "task.h"
#include "data.h"
#include "gba/m4a.h"
#include "bg.h"
#include "functions.h"
#include "trig.h"
#include "palette.h"
#include "random.h"
#include "save.h"
#include "multi_08030C94.h"
#include "code_0814EBE4.h"
#include "kirby.h"

struct Unk_0802B4A8 {
    /* 0x000 */ void (*unk0)(struct Unk_0802B4A8 *);
    /* 0x004 */ struct Sprite unk4[5];
    /* 0x0CC */ struct Sprite unkCC;
    /* 0x0F4 */ struct Sprite unkF4;
    /* 0x11C */ struct Sprite unk11C;
    /* 0x144 */ struct Sprite unk144;
    /* 0x16C */ struct Sprite unk16C;
    /* 0x194 */ struct Background unk194;
    /* 0x1D4 */ struct Background unk1D4;
    /* 0x214 */ u32 unk214;
    /* 0x218 */ u32 unk218[5][2];
    /* 0x240 */ u16 unk240[5][2];
    /* 0x254 */ u16 unk254[5];
    /* 0x25E */ u16 unk25E[5];
    /* 0x268 */ u16 unk268[5];
    /* 0x272 */ u8 filler272[0x274 - 0x272];
    /* 0x274 */ s32 unk274;
    /* 0x278 */ s32 unk278;
    /* 0x27C */ s32 unk27C;
    /* 0x280 */ s32 unk280;
    /* 0x284 */ u8 filler284[0x294 - 0x284];
    /* 0x294 */ s32 unk294;
    /* 0x298 */ s32 unk298;
    /* 0x29C */ s32 unk29C;
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

struct Unk_0802E390 {
    /* 0x00 */ struct Background unk0;
    /* 0x40 */ void (*unk40)(struct Unk_0802E390 *);
    /* 0x44 */ u16 unk44;
}; /* size = 0x48 */

struct Unk_0802CE64 {
    /* 0x00 */ struct Sprite sprite;
    /* 0x28 */ struct Unk_0802B4A8 *unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ s16 unk3A;
}; /* size = 0x3C */

struct Unk_0802D898 {
    /* 0x00 */ void (*unk0)(struct Unk_0802D898 *);
    /* 0x04 */ struct Background unk4;
    /* 0x44 */ struct Unk_0802B4A8 *unk44;
    /* 0x48 */ u16 unk48;
    /* 0x4A */ u16 unk4A;
    /* 0x4C */ u16 unk4C;
};

extern u16 gUnk_082EB4A0[][2];
extern u32 gUnk_082EB4EC[][2];
extern u32 gUnk_082EB4F0[][2];
extern u32 gUnk_082EB53C[][2];
extern u32 gUnk_082EB58C[][2];
extern u32 gUnk_082EB514[][2];
extern u32 gUnk_082EB564[][2];
extern u16 gUnk_082EB634[];
extern u16 gUnk_082EB640[][6][2];
extern u16 gUnk_082EB5B4[];
extern u32 gUnk_082EB5C0[][2];
extern u32 gUnk_082EB5C4[][2];
extern u16 gUnk_082EB4B4[][2];
extern u16 gUnk_082EB4B6[][2];
extern u16 gUnk_0300000C;
extern u16 gUnk_082EB5E0[][2];
extern u8 gUnk_082EB630[];
extern u8 gUnk_082EB610[];

void sub_0803D2D0(void);
extern u16 gUnk_082EB6D0[];

void sub_0802BA6C(void);
void sub_0802B62C(struct Unk_0802B4A8 *);
void sub_0802D480(struct Unk_0802B4A8 *);
struct Unk_0802CE64 *sub_0802D198(struct Unk_0802B4A8 *, u16, u16, u32, s32, s32, u16, u16);
void sub_0802BCEC(struct Unk_0802B4A8 *);
void sub_0802BF68(struct Unk_0802B4A8 *);
void sub_0802D3E0(struct Unk_0802B4A8 *);
void sub_0802C1D8(struct Unk_0802B4A8 *);
void sub_0802C26C(struct Unk_0802B4A8 *);
void sub_0802D408(struct Unk_0802B4A8 *);
void sub_0802D5D4(struct Unk_0802B4A8 *);
void sub_0802C68C(struct Unk_0802B4A8 *);
void sub_0802D780(struct Unk_0802B4A8 *);
void sub_0802C308(struct Unk_0802B4A8 *);
void sub_0802C3C8(struct Unk_0802B4A8 *);
void sub_0802C4BC(struct Unk_0802B4A8 *);
void sub_0802D458(struct Unk_0802B4A8 *);
void sub_0802D46C(struct Unk_0802B4A8 *);
void sub_0802C550(struct Unk_0802B4A8 *);
void sub_0802C8E8(struct Unk_0802B4A8 *);
void sub_0802CA78(struct Unk_0802B4A8 *);
void sub_0802D360(struct Task *);
void sub_0802DE14(struct Unk_0802B4A8 *);
void sub_0802DE38(struct Unk_0802B4A8 *);
void sub_0802E270(struct Unk_0802E390 *);
void sub_0802E390(void);
void nullsub_11(struct Task *);
void sub_0802E3C8(struct Unk_0802E390 *);
void sub_0802E3D4(struct Unk_0802E390 *);
void sub_0802E450(struct Unk_0802E390 *);
void sub_0802E470(struct Unk_0802E390 *);
void sub_0802E484(struct Unk_0802E390 *);
void sub_0802E500(struct Unk_0802E390 *);
void sub_0802E55C(struct Unk_0802E390 *);
void sub_0802D3F4(struct Unk_0802B4A8 *);
void sub_0802D898(struct Unk_0802D898 *);
void sub_0802D92C(struct Unk_0802D898 *);
void sub_0802D9A4(struct Unk_0802D898 *);
void sub_0802D708(struct Unk_0802B4A8 *);
void sub_0802D4E0(struct Unk_0802B4A8 *);
void sub_0802D4F4(struct Unk_0802B4A8 *);
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
struct Unk_0802D898 *sub_0802DB48(struct Unk_0802B4A8 *);
void sub_0802DBC0(struct Unk_0802B4A8 *);
void sub_0802DC10(struct Unk_0802B4A8 *);
void sub_0802DC34(struct Unk_0802B4A8 *);
void sub_0802DC58(struct Unk_0802B4A8 *);
void sub_0802DCC4(struct Unk_0802B4A8 *);
void sub_0802DD18(struct Unk_0802B4A8 *);
void sub_0802DCA0(struct Unk_0802B4A8 *);
void sub_0802C770(struct Unk_0802B4A8 *);
void sub_0802D800(struct Unk_0802B4A8 *);
void sub_0802DDA0(struct Unk_0802B4A8 *);
void sub_0802DDB4(struct Unk_0802B4A8 *);
void sub_0802DDC0(struct Unk_0802B4A8 *);
void sub_0802DDEC(struct Unk_0802B4A8 *);
void sub_0802DE00(struct Unk_0802B4A8 *);
void sub_0802DF0C(struct Unk_0802B4A8 *);
void sub_0802CB60(struct Unk_0802B4A8 *);
void sub_0802BFBC(struct Unk_0802B4A8 *);
void sub_0802C064(struct Unk_0802B4A8 *);
void sub_0802D430(struct Unk_0802B4A8 *);
void sub_0802CC7C(struct Unk_0802D898 *);
void sub_0802CDA0(struct Unk_0802D898 *);
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
void sub_0802D444(struct Unk_0802B4A8 *);
void sub_0802DD3C(void);
void sub_0802DD94(struct Unk_0802D898 *);
struct Unk_0802CE64 *sub_0802CE64(struct Unk_0802B4A8 *, u16, u16, u32, s32, s32, u16, u16, u16);
struct Unk_0802CE64 *sub_0802CFF0(struct Unk_0802B4A8 *, u16, u16, u32, s32, s32, u16, u16, u16);
void sub_0802D0B8(void);
void sub_0802D288(void);
void sub_0802D550(struct Unk_0802B4A8 *);
void sub_0802CF2C(void);
void sub_0802D528(struct Unk_0802B4A8 *);
void sub_0802D53C(struct Unk_0802B4A8 *);

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

void sub_0802B62C(struct Unk_0802B4A8 *x) {
    u16 i;
    u16 j;
    struct Sprite *s;

    if ((s32)x->unk214 >= 0 && sub_08155128(&x->unkCC) == 0)
        x->unkCC.unk1B = 0xFF;

    j = 0;
    for (i = 0; i < 5; i++, j += 3) {
        if (x->unk214 & (1 << j)) {
            s = &x->unk4[i];
            x->unk254[i] = (x->unk254[i] + 4) & 0x3FF;
            if ((s16)x->unk25E[i] < (s16)x->unk268[i]) {
                x->unk25E[i] += 4;
                if ((s16)x->unk25E[i] > (s16)x->unk268[i])
                    x->unk25E[i] = x->unk268[i];
            } else if ((s16)x->unk25E[i] > (s16)x->unk268[i]) {
                x->unk25E[i] -= 4;
                if ((s16)x->unk25E[i] < (s16)x->unk268[i])
                    x->unk25E[i] = x->unk268[i];
            }
            s->x = (s32)x->unk218[i][0] >> 8;
            s->y = (s32)(x->unk218[i][1] + (gSineTable[x->unk254[i]] >> 10) * ((s16)x->unk25E[i] >> 4)) >> 8;
            if ((s32)x->unk214 >= 0) {
                if (!(x->unk214 & (2 << j))) {
                    if (sub_08155128(s) == 0)
                        x->unk214 |= 2 << j;
                }
                if (x->unk214 & (2 << j)) {
                    x->unk214 &= ~(2 << j);
                    s->unk1B = 0xFF;
                }
            }
            sub_0815604C(s);
            if (x->unk214 & (4 << j)) {
                x->unkCC.x = s->x;
                x->unkCC.y = s->y;
                sub_0815604C(&x->unkCC);
                if (!(x->unk214 & 0x800000)) {
                    if (((x->unk2BA + i * 2) & 7) == 0) {
                        sub_0802CFF0(x, 0x295, 2, x->unk16C.tilesVram,
                            x->unk2B4 + x->unk218[i][0] + 0x1000,
                            x->unk218[i][1] + 0x800, 0, 0, 1);
                    }
                    if (((x->unk2BA + i * 2) & 0xF) == 0) {
                        u32 b = Rand16() & 0x1F;
                        sub_0802CE64(x, gUnk_082EB5E0[gUnk_082EB610[b]][0], gUnk_082EB5E0[gUnk_082EB610[b]][1],
                            x->unk16C.tilesVram,
                            x->unk2B4 + x->unk218[i][0] + (((Rand16() & 0xF) + 8) << 8),
                            x->unk218[i][1] + (((Rand16() & 0x1F) - 0x10) << 8),
                            (Rand16() & 0xFF) + 0x80, 0, 0);
                    }
                }
            }
        }
    }

    if (x->unk214 & 0x8000) {
        s = &x->unkF4;
        if ((s32)x->unk214 >= 0) {
            if (!(x->unk214 & 0x10000)) {
                if (sub_08155128(s) == 0)
                    x->unk214 |= 0x10000;
            }
            if (x->unk214 & 0x10000) {
                x->unk214 &= ~0x10000;
                s->unk1B = 0xFF;
            }
        }
        s->x = x->unk274 >> 8;
        s->y = x->unk278 >> 8;
        sub_0815604C(s);
    }

    if (x->unk214 & 0x20000) {
        s = &x->unk11C;
        if ((s32)x->unk214 >= 0) {
            if (!(x->unk214 & 0x40000)) {
                if (sub_08155128(s) == 0)
                    x->unk214 |= 0x40000;
            }
            if (x->unk214 & 0x40000) {
                x->unk214 &= ~0x40000;
                s->unk1B = 0xFF;
            }
        }
        s->x = x->unk294 >> 8;
        s->y = x->unk298 >> 8;
        sub_0815604C(s);
    }

    if (x->unk214 & 0x80000) {
        s = &x->unk144;
        if ((s32)x->unk214 >= 0) {
            if (!(x->unk214 & 0x100000)) {
                if (sub_08155128(s) == 0)
                    x->unk214 |= 0x100000;
            }
            if (x->unk214 & 0x100000) {
                x->unk214 &= ~0x100000;
                s->unk1B = 0xFF;
            }
        }
        s->x = x->unk2A4 >> 8;
        s->y = x->unk2A8 >> 8;
        sub_0815604C(s);
    }
}

void sub_0802BA6C(void) {
    struct Unk_0802B4A8 *tmp = TaskGetStructPtr(gCurTask);
    struct Unk_0802B4A8 *x = tmp;

    if ((x->unk214 & 0x8000000) && (gPressedKeys & 0xB)) {
        x->unk214 |= 0x40000000;
    }

    if ((x->unk214 & 0x60000000) != 0x40000000) {
        x->unk0(x);
        if (gUnk_0300000C != 0)
            return;
        if (x->unk214 & 0x1000000) {
            x->unk2B4 -= (s16)x->unk2B8;
            gBgScrollRegs[0][0] = x->unk2B4 >> 9;
        }
        if ((x->unk214 & 0x800000) && (x->unk2BA & 0x3F) == 0) {
            u16 a, b, dx;
            s32 xpos;

            a = Rand16() & 3;
            b = Rand16() & 3;
            if (a < 2) {
                dx = -((Rand16() & 0xF) + 0x10);
                xpos = ((Rand16() & 0x1F) << 0xB) + 0x1000;
            } else {
                dx = (Rand16() & 0xF) + 0x10;
                xpos = ((Rand16() & 0x1F) << 0xB) - 0x2000;
            }
            sub_0802D198(x, gUnk_082EB5E0[gUnk_082EB630[b]][0], gUnk_082EB5E0[gUnk_082EB630[b]][1],
                x->unk16C.tilesVram, xpos, (-((Rand16() & 0xF) + 0x20)) << 8, (s16)dx, 0x40);
        }
        x->unk2BA++;
    } else if (x->unk214 & 0x60000000) {
        if ((x->unk214 & 0x80000000) == 0) {
            gBldRegs.bldCnt = 0xBF;
            gBldRegs.bldY = 0;
            x->unk2BC = 0;
            m4aMPlayFadeOut(&gMPlayInfo_0, 4);
            m4aMPlayFadeOut(&gMPlayInfo_1, 4);
            m4aMPlayFadeOut(&gMPlayInfo_2, 4);
            m4aMPlayFadeOut(&gMPlayInfo_3, 4);
            x->unk214 |= 0x80000000;
        } else {
            u32 t = x->unk2BC + 1;
            x->unk2BC = t;
            if ((u16)t > 0xF) {
                if (x->unk214 & 0x10000000) {
                    sub_0802CB60(x);
                    return;
                } else {
                    x->unk214 = 0x14000000;
                    x->unk0 = sub_0802D480;
                    return;
                }
            } else {
                gBldRegs.bldY = t;
            }
        }
    }

    if (gUnk_0300000C == 0)
        sub_0802B62C(x);
}

void sub_0802BCEC(struct Unk_0802B4A8 *x) {
    u16 i;
    struct Background *bg;
    struct Sprite *s;
    struct Sprite *s2;
    u32 ff = -1;

    gDispCnt = 0x1140;
    bg = &x->unk194;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    gBgCntRegs[0] = 0x1F0A;
    BgInit(bg, 0x06008000, 0, 0x0600F800, 0, 0, 0x2B0, 0, 0, 0, 0, 0x20, 0x20, 0, 0, 0, 8, 0, 0, 0x7FFF, 0x7FFF);
    LZ77UnCompVram(gUnk_082D7850[0x2B0]->tileset, (void *)0x06008000);
    sub_08153060(bg);

    for (i = 0; i < 5; i++) {
        s = &x->unk4[i];
        x->unk218[i][0] = gUnk_082EB4EC[i][0];
        x->unk218[i][1] = gUnk_082EB4F0[i][0];
        x->unk254[i] = gUnk_082EB5B4[i];
        if (i < 4) {
            s->unk14 = 0x100;
            s->animId = *(u16 *)(gKirbys[i].color * 4 + (u32)gUnk_082EB4B4);
            s->variant = *(u16 *)(gKirbys[i].color * 4 + (u32)gUnk_082EB4B6);
            s->unk16 = 0;
            s->unk1B = 0xFF;
            s->unk1C = 0x10;
            s->palId = i;
            s->x = 0;
            s->y = 0;
            s->unk8 = 0x81000;
            sub_08155128(s);
        } else {
            s->unk14 = 0x100;
            s->animId = *(u16 *)(i * 4 + (u32)gUnk_082EB4A0);
            s->variant = *(u16 *)(i * 4 + ((u32)gUnk_082EB4A0 + 2));
            s->unk16 = 0;
            s->unk1B = 0xFF;
            s->unk1C = 0x10;
            s->palId = i;
            s->x = 0;
            s->y = 0;
            s->unk8 = 0x81000;
            sub_08155128(s);
        }

        s->unk14 = 0x100;
        s->animId = 0x2D;
        s->variant = 4;
        s->unk16 = 0;
        s->unk1B = 0xFF;
        s->unk1C = 0x10;
        s->palId = i;
        s->x = (s32)x->unk218[i][0] >> 8;
        s->y = (s32)x->unk218[i][1] >> 8;
        s->unk8 = 0x41000;
        sub_08155128(s);
    }

    s2 = &x->unkCC;
    s2->unk14 = 0x140;
    s2->animId = 0x2DE;
    s2->variant = 0;
    s2->unk16 = 0;
    s2->unk1B |= ff;
    s2->unk1C = 0x10;
    s2->palId = 0xF;
    s2->x = 0xFF00;
    s2->y = 0xFF00;
    s2->unk8 = 0x1000;
    sub_08155128(s2);

    s2 = &x->unkF4;
    s2->unk14 = 0x300;
    s2->animId = 0x2D3;
    s2->variant = 1;
    s2->unk16 = 0;
    s2->unk1B |= ff;
    s2->unk1C = 0x10;
    s2->palId = 0xE;
    s2->x = 0xFF00;
    s2->y = 0xFF00;
    s2->unk8 = 0x1000;
    sub_08155128(s2);

    x->unk214 |= 0x01005B6D;
    x->unk214 |= 0x20000000;
    m4aSongNumStart(0x12);
    x->unk0 = sub_0802D3E0;
}

void sub_0802BF68(struct Unk_0802B4A8 *x) {
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0xF) {
        gBldRegs.bldCnt = 0;
        gBldRegs.bldY = 0;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802D3F4;
    } else {
        gBldRegs.bldY = 0x10 - t;
    }
}

void sub_0802BFBC(struct Unk_0802B4A8 *x) {
    u32 acc = 0;
    u16 i;

    for (i = 0; i < 4; i++) {
        if ((s32)gUnk_082EB53C[i][0] >= (s32)x->unk218[i][0] && (s16)x->unk240[i][0] != 0) {
            x->unk240[i][0] += 4;
            if ((s16)x->unk240[i][0] >= 0) {
                x->unk240[i][0] = 0;
                x->unk268[i] = 0x800;
            }
        }
        x->unk218[i][0] += (s16)x->unk240[i][0];
        acc |= x->unk240[i][0];
    }
    if ((u16)acc == 0) {
        x->unk0 = sub_0802D408;
    }
}

void sub_0802C064(struct Unk_0802B4A8 *x) {
    u32 acc = 0;
    u16 i;

    for (i = 0; i < 5; i++) {
        if (i == 4) {
            if ((s32)gUnk_082EB58C[i][0] >= (s32)x->unk218[i][0] && (s16)x->unk240[i][0] != 0) {
                x->unk240[i][0] += 2;
                x->unk240[i][1] += 2;
                if ((s16)x->unk240[i][0] >= 0) {
                    x->unk240[i][0] = 0;
                    x->unk240[i][1] = 0;
                    x->unk268[i] = 0x800;
                }
            }
        } else {
            if ((s16)x->unk240[i][1] > 0) {
                x->unk240[i][1] -= 2;
                if ((s16)x->unk240[i][1] < 0) {
                    x->unk240[i][1] = 0;
                }
            } else if ((s16)x->unk240[i][1] < 0) {
                x->unk240[i][1] += 2;
                if ((s16)x->unk240[i][1] > 0) {
                    x->unk240[i][1] = 0;
                }
            }
            if ((s32)gUnk_082EB58C[i][0] <= (s32)x->unk218[i][0] && (s16)x->unk240[i][0] != 0) {
                x->unk240[i][0] -= 2;
                if ((s16)x->unk240[i][0] >= 0) {
                    x->unk240[i][0] = 0;
                    x->unk240[i][1] = 0;
                    x->unk268[i] = 0x800;
                }
            }
        }
        x->unk218[i][0] += (s16)x->unk240[i][0];
        x->unk218[i][1] += (s16)x->unk240[i][1];
        acc |= x->unk240[i][0] | x->unk240[i][1];
    }
    if ((u16)acc == 0 && (x->unk214 & 0x2000000)) {
        x->unk0 = sub_0802D430;
    }
}

void sub_0802C26C(struct Unk_0802B4A8 *x) {
    s32 dx = (s32)(x->unk218[x->unk2BE][0] - x->unk274) >> 8;
    s32 dy = (s32)(x->unk218[x->unk2BE][1] - x->unk278) >> 8;

    if (dx * dx + dy * dy <= 0x8F) {
        x->unk0 = sub_0802D5D4;
    } else {
        x->unk218[x->unk2BE][0] += (s16)x->unk240[x->unk2BE][0];
        x->unk218[x->unk2BE][1] += (s16)x->unk240[x->unk2BE][1];
    }
}

void sub_0802C5E4(struct Unk_0802B4A8 *x) {
    struct Background *bg = &x->unk194;

    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    gBgCntRegs[0] = 0x1F0A;
    BgInit(bg, 0x06008000, 0, 0x0600F800, 0, 0, 0x306, 0, 0, 0, 0, 0x1E, 0x14, 0, 0, 0, 8, 0, 0, 0x7FFF, 0x7FFF);
    LZ77UnCompVram(gUnk_082D7850[0x306]->tileset, (void *)bg->tilesVram);
    sub_08153060(bg);
    x->unk0 = sub_0802C68C;
}

void sub_0802C68C(struct Unk_0802B4A8 *x) {
    const struct RoomTiledBG *bg = gRoomTiledBGs[gRoomProps[0x321].backgroundIdx];
    const u16 *src;
    u16 *dst;
    u16 i;

    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;
    gBgCntRegs[1] = 0x1E03;
    LZ77UnCompVram(bg->tileset, (void *)0x06000000);

    src = bg->tilemap;
    dst = (u16 *)0x0600F000;
    src += bg->width * 8;
    for (i = 0; i <= 0x13; i++) {
        CpuCopy16(src, dst, 0x3C);
        src += bg->width;
        dst += 0x20;
    }

    if (gMainFlags & MAIN_FLAG_BG_PALETTE_TRANSFORMATION_ENABLE) {
        LoadBgPaletteWithTransformation(bg->palette, bg->paletteOffset, bg->paletteSize);
    } else {
        DmaSet(3, bg->palette, gBgPalette + bg->paletteOffset, bg->paletteSize | ((DMA_ENABLE | DMA_16BIT) << 16));
        gMainFlags |= MAIN_FLAG_BG_PALETTE_SYNC_ENABLE;
    }

    gDispCnt |= 0x300;
    x->unk0 = sub_0802D46C;
}

void sub_0802C550(struct Unk_0802B4A8 *x) {
    struct Sprite *s = &x->unk144;

    x->unk2A4 = 0x7800;
    x->unk2A8 = -0x2800;
    x->unk2AC = 0;
    x->unk2B0 = 0x200;
    s->unk14 = 0x100;
    s->animId = 0x2C3;
    s->variant = 3;
    s->unk16 = 0;
    s->unk1B = 0xFF;
    s->unk1C = 0x10;
    s->palId = 6;
    s->x = x->unk2A4 >> 8;
    s->y = x->unk2A8 >> 8;
    s->unk8 = 0x1000;
    sub_08155128(s);
    x->unk214 = (x->unk214 & ~0x100000) | 0x80000;
    x->unk0 = sub_0802D780;
}

void sub_0802C1D8(struct Unk_0802B4A8 *x) {
    s32 t;

    t = sub_08154FE8((s32)(x->unk274 - x->unk218[x->unk2BE][0]) >> 8, (s32)(x->unk278 - x->unk218[x->unk2BE][1]) >> 8) & 0x3FF;
    x->unk240[x->unk2BE][0] = gSineTable[t] >> 7;
    x->unk240[x->unk2BE][1] = gSineTable[t + 0x100] >> 7;
    x->unk0 = sub_0802C26C;
}

void sub_0802C308(struct Unk_0802B4A8 *x) {
    u32 t2;
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0x3F) {
        gBldRegs.bldCnt = 0;
        gBldRegs.bldY = 0;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802D708;
    } else {
        t2 = t;
        gBldRegs.bldY = 0x10 - ((u16)t2 >> (t = 2));
    }
}

void sub_0802C360(struct Unk_0802B4A8 *x) {
    x->unk240[4][0] -= 4;
    if ((s16)x->unk240[4][0] < -0x80) {
        x->unk240[4][0] = 0xFF80;
    }
    if ((s32)x->unk218[4][0] < -0x2000) {
        x->unk214 &= 0xFFFF8FFF;
        x->unk240[4][0] = 0;
        x->unk0 = sub_0802D444;
    }
    x->unk218[4][0] += (s16)x->unk240[4][0];
}

void sub_0802C3C8(struct Unk_0802B4A8 *x) {
    struct Sprite *s = &x->unk11C;

    x->unk294 = 0x11800;
    x->unk298 = 0x5000;
    x->unk29C = 0;
    x->unk2A0 = 0;
    s->unk14 = 0x100;
    s->animId = 0x395;
    s->variant = 0;
    s->unk16 = 0;
    s->unk1B = 0xFF;
    s->unk1C = 0x10;
    s->palId = 5;
    s->x = x->unk294 >> 8;
    s->y = x->unk298 >> 8;
    s->unk8 = 0x1400;
    sub_08155128(s);
    s = &x->unk144;
    x->unk2A4 = x->unk294;
    x->unk2A8 = x->unk298;
    x->unk2AC = 0;
    x->unk2B0 = 0;
    s->unk14 = 0x100;
    s->animId = 0x395;
    s->variant = 1;
    s->unk16 = 0;
    s->unk1B = 0xFF;
    s->unk1C = 0x10;
    s->palId = 6;
    s->x = x->unk2A4 >> 8;
    s->y = x->unk2A8 >> 8;
    s->unk8 = 0x1400;
    sub_08155128(s);
    x->unk214 |= 0xA0000;
    x->unk0 = sub_0802C4BC;
}

void sub_0802C4BC(struct Unk_0802B4A8 *x) {
    x->unk29C = -0x140;
    if (x->unk294 <= 0xDBFF) {
        x->unk2A0 -= 8;
    }
    if (x->unk298 < -0x2000) {
        x->unk29C = 0;
        x->unk2A0 = 0;
        x->unk214 &= 0xFFF7FFFF;
        x->unk0 = sub_0802D458;
    }
    x->unk294 += x->unk29C;
    x->unk298 += x->unk2A0;
    x->unk2A4 = x->unk294;
    x->unk2A8 = x->unk298;
}

void sub_0802C770(struct Unk_0802B4A8 *x) {
    struct Background *bg;

    gDispCnt |= 0x300;
    gBgScrollRegs[0][0] = 0;
    gBgScrollRegs[0][1] = 0;
    gBgCntRegs[0] = 0x1F09;
    bg = &x->unk194;
    BgInit(bg, 0x06008000, 0, 0x0600F800, 0, 0, gUnk_082EB634[gLanguage], 0, 0, 0, 0, 0x1E, 0x14, 0, 0, 0, 0x18, 0, 0, 0x7FFF, 0x7FFF);
    sub_08153060(bg);
    LZ77UnCompVram(gUnk_082D7850[bg->unk1C]->tileset, (void *)bg->tilesVram);

    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;
    gBgCntRegs[1] = 0x1E02;
    bg = &x->unk1D4;
    bg->tilesVram = 0x06000000;
    bg->unkA = 0;
    bg->tilemapVram = 0x0600F000;
    bg->unk18 = 0;
    bg->unk1A = 0;
    bg->unk1C = 0x2B1;
    bg->unk1E = 0;
    bg->unk20 = 0;
    bg->unk22 = 0;
    bg->unk24 = 0;
    bg->unk26 = 0x1E;
    bg->unk28 = 0x14;
    bg->paletteOffset = 0;
    bg->animFrameCounter = 0;
    bg->animDelayCounter = 0;
    bg->unk2E = 9;
    bg->prevScrollX = 0x7FFF;
    bg->prevScrollY = 0x7FFF;
    sub_08153060(bg);
    LZ77UnCompVram(gUnk_082D7850[bg->unk1C]->tileset, (void *)bg->tilesVram);

    x->unk2BC = 0;
    x->unk214 &= 0xFFF7FFFF;
    x->unk0 = sub_0802D800;
}

void sub_0802C8E8(struct Unk_0802B4A8 *x) {
    u16 i;
    struct Sprite *s;
    struct Sprite *s2;
    u32 ff = -1;

    for (i = 0; i < 4; i++) {
        s = &x->unk4[i];
        x->unk218[i][0] = gUnk_082EB5C0[i][0];
        x->unk218[i][1] = gUnk_082EB5C4[i][0];
        x->unk240[i][0] = 0x300;
        x->unk240[i][1] = 0xFF80;
        x->unk25E[i] = 0;
        x->unk268[i] = 0;

        s->unk14 = 0x100;
        s->animId = gUnk_082EB4B4[gKirbys[i].color][0];
        s->variant = gUnk_082EB4B6[gKirbys[i].color][0];
        s->unk16 = 0;
        s->unk1B = 0xFF;
        s->unk1C = 0x10;
        s->palId = i;
        s->x = 0;
        s->y = 0;
        s->unk8 = 0x81000;
        sub_08155128(s);

        s->unk14 = 0x100;
        s->animId = 0x2D;
        s->variant = 0;
        s->unk16 = 0;
        s->unk1B = ff;
        s->unk1C = 0x10;
        s->palId = i;
        s->x = (s32)x->unk218[i][0] >> 8;
        s->y = (s32)x->unk218[i][1] >> 8;
        s->unk8 = 0x41000;
        sub_08155128(s);
    }

    s2 = &x->unkCC;
    s2->unk14 = 0x140;
    s2->animId = 0x2DE;
    s2->variant = 0;
    s2->unk16 = 0;
    s2->unk1B |= ff;
    s2->unk1C = 0x10;
    s2->palId = 0xF;
    s2->x = 0xFF00;
    s2->y = 0xFF00;
    s2->unk8 = 0x1000;
    sub_08155128(s2);

    x->unk214 = (x->unk214 & 0xF0800000) | 0xB6D;
    x->unk0 = sub_0802CA78;
}

void sub_0802CA78(struct Unk_0802B4A8 *x) {
    u16 i;
    u32 flag = 1;

    for (i = 0; i < 4; i++) {
        if ((s16)x->unk240[i][0] > 0x80) {
            x->unk240[i][0] -= 6;
            if ((s16)x->unk240[i][0] <= 0x80) {
                x->unk4[i].animId = 0x2D;
                x->unk4[i].variant = 6;
                x->unk240[i][0] = 0x80;
            }
        }
        if ((s32)x->unk218[i][0] > 0x13000 || (s32)x->unk218[i][1] < -0x4000) {
            x->unk240[i][1] = 0;
            x->unk240[i][0] = 0;
        } else {
            flag = 0;
        }
        x->unk218[i][0] += (s16)x->unk240[i][0];
        x->unk218[i][1] += (s16)x->unk240[i][1];
    }
    if (flag != 0) {
        x->unk0 = sub_0802D4F4;
    }
}

void sub_0802CB60(struct Unk_0802B4A8 *x) {
    gBldRegs.bldCnt = 0;
    gBldRegs.bldY = 0;
    CpuFill16(0x7FFF, gBgPalette, 0x200);
    CpuFill16(0x7FFF, gObjPalette, 0x200);
    gMainFlags |= 3;
    gUnk_0300000C = 1;
    TasksDestroyInPriorityRange(0, 0xFFFF);
    gUnk_03003A04 = gUnk_03003790;
    gUnk_030068B0 = 0;
    gUnk_03006078 = gUnk_030039A4;
    if (gAIKirbyState < AI_KIRBY_STATE_UNK1) {
        gAIKirbyState = AI_KIRBY_STATE_UNK1;
        if (!(gUnk_0203AD10 & 0x10)) {
            if (gUnk_0203AD10 & 2) {
                if (gUnk_0203AD3C == gUnk_0203AD24) {
                    UpdateSaveBufferByOffset(SAVE_BUFFER_TYPE_WORLD_PROPS, gSaveID > 2 ? 0 : gSaveID);
                } else {
                    sub_08031CE4(8);
                }
            } else {
                UpdateSaveBufferByOffset(SAVE_BUFFER_TYPE_WORLD_PROPS, gSaveID > 2 ? 0 : gSaveID);
            }
        }
    }
    sub_0814EBE4();
}

void sub_0802CC7C(struct Unk_0802D898 *x) {
    struct Background *bg;
    u16 bgIdx;

    gDispCnt |= 0x400;
    gBldRegs.bldCnt = 0x1344;
    gBldRegs.bldAlpha = 0x1000;
    bg = &x->unk4;
    bgIdx = gUnk_082EB640[gLanguage][x->unk4C][0];
    gBgScrollRegs[2][0] = 0;
    gBgScrollRegs[2][1] = 0;
    gBgCntRegs[2] = 0x1D00;
    BgInit(bg, 0x06000000, 0, 0x0600E800, 0, 0, bgIdx, 0, 0, 0, 0xA, 0x1E, 0xA, 0, 0, 0, 0x1A, 0, 0, 0x7FFF, 0x7FFF);
    LZ77UnCompVram(gUnk_082D7850[bgIdx]->tileset, (void *)bg->tilesVram);
    CpuFill32(0, (void *)(bg->tilesVram + 0x3FE0), 0x20);
    CpuFill16(0x1FF, (void *)bg->tilemapVram, 0x800);
    sub_08153060(bg);
    x->unk4A = 0;
    x->unk44->unk214 |= 0x20000000;
    x->unk0 = sub_0802CDA0;
}

void sub_0802CDA0(struct Unk_0802D898 *x) {
    u32 t = x->unk4A + 1;

    x->unk4A = t;
    if ((u16)t > 0xF) {
        gBldRegs.bldCnt = 0;
        gBldRegs.bldAlpha = 0x10;
        x->unk44->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802D898;
    } else {
        gBldRegs.bldAlpha = t | ((0x10 - t) << 8);
    }
}

void sub_0802CDF8(struct Unk_0802D898 *x) {
    u32 t = x->unk4A + 1;

    x->unk4A = t;
    if ((u16)t > 0xF) {
        gDispCnt &= 0xFBFF;
        gBldRegs.bldCnt = 0;
        gBldRegs.bldAlpha = 0x1000;
        x->unk44->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802D92C;
    } else {
        gBldRegs.bldAlpha = (0x10 - t) | (t << 8);
    }
}

struct Unk_0802CE64 *sub_0802CE64(struct Unk_0802B4A8 *x, u16 animId, u16 variant, u32 tilesVram, s32 a5, s32 a6, u16 a7, u16 a8, u16 a9) {
    struct Task *t;
    struct Unk_0802CE64 *s;

    t = TaskCreate(sub_0802CF2C, 0x3C, 0x101, 0, NULL);
    s = TaskGetStructPtr(t);
    s->unk28 = x;
    s->unk2C = a5;
    s->unk30 = a6;
    s->unk34 = a7;
    s->unk36 = a8;
    s->unk38 = a9;
    SpriteInit(&s->sprite, tilesVram, 0x140, animId, variant, 0, 0xFF, 0x10, 0xD, a5 >> 8, a6 >> 8, 0x81000);
    return s;
}

void sub_0802CF2C(void) {
    struct Unk_0802CE64 *tmp = TaskGetStructPtr(gCurTask);
    struct Unk_0802CE64 *s = tmp;
    struct Unk_0802CE64 *s2;

#ifndef NONMATCHING
    asm("" : "+r"(s));
#endif
    s2 = s;
#ifndef NONMATCHING
    asm("" : "+r"(s2));
#endif
    s->sprite.x = (s->unk2C - s->unk28->unk2B4) >> 8;
    s->sprite.y = s->unk30 >> 8;
    if (sub_08155128(&s->sprite) == 0) {
        s->sprite.unk1B = 0xFF;
    }
    sub_0815604C(&s->sprite);
    s->unk2C += s->unk34;
    s->unk30 += s->unk36;
    if (s->unk38 == 0 || --s->unk38 != 0) {
        if ((u16)(s2->sprite.x + 0x40) <= 0x170 && (s16)s2->sprite.y >= -0x40 && (s16)s2->sprite.y <= 0xE0
            && !(s->unk28->unk214 & 0x4000000)) {
            return;
        }
    }
    gCurTask->main = (TaskMain)sub_0802D528;
}

struct Unk_0802CE64 *sub_0802CFF0(struct Unk_0802B4A8 *x, u16 animId, u16 variant, u32 tilesVram, s32 a5, s32 a6, u16 a7, u16 a8, u16 a9) {
    struct Task *t;
    struct Unk_0802CE64 *s;

    t = TaskCreate(sub_0802D0B8, 0x3C, 0x101, 0, NULL);
    s = TaskGetStructPtr(t);
    s->unk28 = x;
    s->unk2C = a5;
    s->unk30 = a6;
    s->unk34 = a7;
    s->unk36 = a8;
    s->unk38 = a9;
    SpriteInit(&s->sprite, tilesVram, 0x140, animId, variant, 0, 0xFF, 0x10, 0xD, a5 >> 8, a6 >> 8, 0x81000);
    return s;
}

void sub_0802D0B8(void) {
    struct Unk_0802CE64 *tmp = TaskGetStructPtr(gCurTask);
    struct Unk_0802CE64 *s = tmp;
    struct Unk_0802CE64 *s2;

#ifndef NONMATCHING
    asm("" : "+r"(s));
#endif
    s2 = s;
#ifndef NONMATCHING
    asm("" : "+r"(s2));
#endif
    s->sprite.x = (s->unk2C - s->unk28->unk2B4) >> 8;
    s->sprite.y = s->unk30 >> 8;
    if (sub_08155128(&s->sprite) == 0) {
        if (s->unk38 != 0 && --s->unk38 == 0) {
            gCurTask->main = (TaskMain)sub_0802D53C;
        } else {
            s->sprite.unk1B = 0xFF;
        }
    }
    sub_0815604C(&s2->sprite);
    s->unk2C += s->unk34;
    s->unk30 += s->unk36;
    if ((u16)(s2->sprite.x + 0x40) > 0x170 || (s16)s2->sprite.y < -0x40 || (s16)s2->sprite.y > 0xE0) {
        gCurTask->main = (TaskMain)sub_0802D53C;
    }
    if (s->unk28->unk214 & 0x4000000) {
        gCurTask->main = (TaskMain)sub_0802D53C;
    }
}

struct Unk_0802CE64 *sub_0802D198(struct Unk_0802B4A8 *x, u16 animId, u16 variant, u32 tilesVram, s32 a5, s32 a6, u16 a7, u16 a8) {
    struct Task *t;
    struct Unk_0802CE64 *s;

    t = TaskCreate(sub_0802D288, 0x3C, 0x101, 0, NULL);
    s = TaskGetStructPtr(t);
    s->unk28 = x;
    s->unk2C = a5;
    s->unk30 = a6;
    s->unk34 = a7;
    s->unk36 = a8;
    s->unk38 = Rand16() & 0x3FF;
    s->unk3A = (Rand16() & 0x7FF) + 0x800;
    SpriteInit(&s->sprite, tilesVram, 0x140, animId, variant, 0, 0xFF, 0x10, 0xD, a5 >> 8, a6 >> 8, 0x81000);
    return s;
}

void sub_0802D288(void) {
    struct Unk_0802CE64 *tmp = TaskGetStructPtr(gCurTask);
    struct Unk_0802CE64 *s = tmp;

    s->sprite.x = (s->unk2C + ((gSineTable[s->unk38] >> 6) * s->unk3A >> 8)) >> 8;
    s->sprite.y = s->unk30 >> 8;
    if (sub_08155128(&s->sprite) == 0) {
        s->sprite.unk1B = 0xFF;
    }
    sub_0815604C(&s->sprite);
    s->unk2C += s->unk34;
    s->unk30 += s->unk36;
    s->unk38 += 8;
    s->unk38 &= 0x3FF;
    if ((u16)(s->sprite.x + 0x40) > 0x170 || (s16)s->sprite.y < -0x40 || (s16)s->sprite.y > 0xE0) {
        gCurTask->main = (TaskMain)sub_0802D550;
    }
    if (s->unk28->unk214 & 0x4000000) {
        gCurTask->main = (TaskMain)sub_0802D550;
    }
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

struct Unk_0802D898 *sub_0802DB48(struct Unk_0802B4A8 *x) {
    struct Task *t;
    struct Unk_0802D898 *s;

    x->unk214 &= 0xFDFFFFFF;
    t = TaskCreate(sub_0802DD3C, 0x50, 0x101, 0, NULL);
    s = TaskGetStructPtr(t);
    CpuFill16(0, s, 0x50);
    s->unk44 = x;
    s->unk0 = sub_0802DD94;
    return s;
}

void sub_0802DBC0(struct Unk_0802B4A8 *x) {
    if (x->unk278 <= 0x63FF) {
        if (x->unk280 != 0) {
            x->unk280 += 4;
            if (x->unk280 > 0) {
                x->unk280 = 0;
            }
        } else {
            x->unk0 = sub_0802DDA0;
        }
    }
    x->unk278 += x->unk280;
}

void sub_0802DC10(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802DDB4;
    }
}

void sub_0802DC34(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802DDC0;
    }
}

void sub_0802DC58(struct Unk_0802B4A8 *x) {
    x->unk2B0 += 8;
    if (x->unk2B0 > 0x800) {
        x->unk2B0 = 0x800;
    }
    if (x->unk2A8 > 0x8000) {
        x->unk2B0 = 0;
        x->unk2A8 = 0x8000;
        x->unk0 = sub_0802DCA0;
    }
    x->unk2A8 += x->unk2B0;
}

void sub_0802DCA0(struct Unk_0802B4A8 *x) {
    x->unk144.animId = 0x2C3;
    x->unk144.variant = 4;
    x->unk0 = sub_0802DDEC;
}

void sub_0802DCC4(struct Unk_0802B4A8 *x) {
    u32 t2;
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0x3F) {
        gBldRegs.bldY = 0;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802DE00;
    } else {
        t2 = t;
        gBldRegs.bldY = 0x10 - ((u16)t2 >> (t = 2));
    }
}

void sub_0802DD18(struct Unk_0802B4A8 *x) {
    if (x->unk2BC++ > 0x3C) {
        x->unk0 = sub_0802CB60;
    }
}

void sub_0802DD3C(void) {
    struct Unk_0802D898 *x = TaskGetStructPtr(gCurTask);

    if ((s32)x->unk44->unk214 >= 0) {
        x->unk0(x);
        x->unk48++;
    } else {
        sub_0802D9A4(x);
    }
}

void sub_0802DD94(struct Unk_0802D898 *x) {
    x->unk0 = sub_0802CC7C;
}

void sub_0802DDA0(struct Unk_0802B4A8 *x) {
    x->unk2BC = 0;
    x->unk0 = sub_0802DE14;
}

void sub_0802DDB4(struct Unk_0802B4A8 *x) {
    x->unk0 = sub_0802DE38;
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

void sub_0802E11C(struct Unk_0802B4A8 *x) {
    u32 t2;
    u32 t = x->unk2BC + 1;

    x->unk2BC = t;
    if ((u16)t > 0x3F) {
        gBldRegs.bldY = 0x10;
        x->unk214 &= 0xDFFFFFFF;
        x->unk0 = sub_0802C770;
    } else {
        t2 = t;
        gBldRegs.bldY = (u16)t2 >> (t = 2);
    }
}

void sub_0802DE38(struct Unk_0802B4A8 *x) {
    x->unk280 -= 4;
    if (x->unk280 < -0x100) {
        x->unk280 = -0x100;
    }
    if (x->unk278 < -0x3C00) {
        x->unk214 &= 0xFFFE7FFF;
        x->unk280 = 0;
        x->unk0 = sub_0802DF0C;
    }
    x->unk278 += x->unk280;
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

void sub_0802DF30(struct Unk_0802B4A8 *x) {
    struct Unk_0802CE64 *s;

    x->unk214 &= 0xFBFFFFFF;
    x->unk2B4 = 0;
    s = sub_0802CFF0(x, 0x28F, 3, x->unk16C.tilesVram, x->unk2A4, x->unk2A8, 0, 0, 1);
    s->sprite.unk1C >>= 1;
    m4aSongNumStart(0x212);
    x->unk0 = sub_0802DFA0;
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

void sub_0802E16C(void) {
    struct Task *t = TaskCreate(sub_0802E390, 0x48, 0x1000, 4, nullsub_11);
    struct Unk_0802E390 *x;
    u16 bgIdx;
    u16 white;
    s32 val;

    white = 0x7FFF;
    sub_0803D21C(&white, 0, 1);
    val = 0x1840;
    gDispCnt = val;
    x = TaskGetStructPtr(t);
    x->unk40 = sub_0802E3C8;
    x->unk44 = 0;
    bgIdx = gUnk_082EB6D0[gLanguage];
    gBgScrollRegs[3][0] = 0;
    gBgScrollRegs[3][1] = 0;
    gBgCntRegs[3] = 0x1E0A;
    x->unk0.tilesVram = 0x06008000;
    x->unk0.unkA = 0;
    x->unk0.tilemapVram = 0x0600F000;
    x->unk0.unk18 = 0;
    x->unk0.unk1A = 0;
    x->unk0.unk1C = bgIdx;
    x->unk0.unk1E = 0;
    x->unk0.unk20 = 0;
    x->unk0.unk22 = 0;
    x->unk0.unk24 = 0;
    x->unk0.unk26 = 0x1E;
    x->unk0.unk28 = 0x14;
    x->unk0.paletteOffset = 0;
    x->unk0.animFrameCounter = 0;
    x->unk0.animDelayCounter = 0;
    x->unk0.unk2E = 0x1B;
    x->unk0.scrollX = 0;
    x->unk0.scrollY = 0;
    x->unk0.prevScrollX = 0x7FFF;
    val = 0x7FFF;
    x->unk0.prevScrollY = val;
    LZ77UnCompVram(gUnk_082D7850[bgIdx]->tileset, (void *)x->unk0.tilesVram);
    sub_08153060(&x->unk0);
}

void sub_0802E270(struct Unk_0802E390 *x) {
    u16 i;

    for (i = gUnk_0203AD30; i < gUnk_0203AD44; i++) {
        gUnk_02038590[i].unk18 = gUnk_082D8D28[i];
    }
    for (i = 0; i < gUnk_0203AD30; i++) {
        gKirbys[i].base.base.base.flags |= 0x1000000;
    }
    if (gAIKirbyState < AI_KIRBY_STATE_CUTSCENE) {
        gAIKirbyState = AI_KIRBY_STATE_CUTSCENE;
        if (!(gUnk_0203AD10 & 0x10)) {
            if (gUnk_0203AD10 & 2) {
                if (gUnk_0203AD3C == gUnk_0203AD24) {
                    UpdateSaveBufferByOffset(SAVE_BUFFER_TYPE_WORLD_PROPS, gSaveID > 2 ? 0 : gSaveID);
                } else {
                    sub_08031CE4(8);
                }
            } else {
                UpdateSaveBufferByOffset(SAVE_BUFFER_TYPE_WORLD_PROPS, gSaveID > 2 ? 0 : gSaveID);
            }
        }
    }
    sub_0803D21C(gBgPalette, 0, 0x100);
    sub_0803D280(0, 0xFF);
    sub_0803D2D0();
    m4aMPlayAllStop();
    m4aSoundVSyncOff();
    sub_08039670();
    TaskDestroy(gCurTask);
}

void sub_0802E390(void) {
    struct Unk_0802E390 *x = TaskGetStructPtr(gCurTask);

    x->unk40(x);
}

void nullsub_11(struct Task *t) {
}

void sub_0802E3C8(struct Unk_0802E390 *x) {
    x->unk40 = sub_0802E3D4;
}

void sub_0802E3D4(struct Unk_0802E390 *x) {
    const struct TiledBg_082D7850 *ptr = gUnk_082D7850[gUnk_082EB6D0[gLanguage]];
    u16 white = 0x7FFF;
    struct Unk_02022930_0 *unkStruct;

    sub_0803D21C(ptr->palette, 0, 0x20);
    unkStruct = sub_0803C95C(7);
    unkStruct->unk8 |= 0x180;
    unkStruct->unk4 = 0xFFFF;
    unkStruct->unk6 = -1;
    sub_0803D21C(&white, 0, 1);
    x->unk44 = 0;
    x->unk40 = sub_0802E450;
}

void sub_0802E450(struct Unk_0802E390 *x) {
    if (x->unk44++ > 0x20) {
        x->unk40 = sub_0802E470;
    }
}

void sub_0802E470(struct Unk_0802E390 *x) {
    x->unk44 = 0;
    x->unk40 = sub_0802E484;
}

void sub_0802E484(struct Unk_0802E390 *x) {
    u16 i;
    u8 flag = 0;

    if (gUnk_0203AD10 & 2) {
        for (i = 0; i < gUnk_0203AD30; i++) {
            if (gUnk_020382D0.unk8[1][i] & 0xB) {
                flag = 1;
                break;
            }
        }
    } else {
        if (gPressedKeys & 0xB) {
            flag = 1;
        }
    }

    if (flag) {
        x->unk40 = sub_0802E500;
    }
}

void sub_0802E500(struct Unk_0802E390 *x) {
    u16 white = 0x7FFF;
    struct Unk_02022930_0 *unkStruct;

    x->unk44 = 0;
    unkStruct = sub_0803CA20(7);
    unkStruct->unk8 |= 0x80;
    unkStruct->unk4 = 0xFFFF;
    unkStruct->unk6 = -1;
    sub_0803D21C(&white, 0, 1);
    m4aMPlayFadeOut(&gMPlayInfo_0, 2);
    x->unk40 = sub_0802E55C;
}

void sub_0802E55C(struct Unk_0802E390 *x) {
    if (x->unk44++ > 0x20) {
        x->unk40 = sub_0802E270;
    }
}
