#include "global.h"
#include "data.h"
#include "functions.h"
#include "kirby.h"
#include "task.h"
#include "palette.h"

extern u16 gUnk_02022120[0x100];
extern u16 gUnk_02022320[0x100];
extern u16 gUnk_02022520[0x200];
extern struct Task *gUnk_0203AD4C;

extern void sub_080356AC(u32, u8, u8);
extern void sub_08020220(void);
extern void sub_080203C8(void);
extern void sub_08031CE4(u8);
extern struct Task *gUnk_03000010;
extern void sub_080363B4(void);
extern void sub_08034A20(void);
extern void sub_08035FA8(void);
extern void sub_080340A8(void);
extern void sub_080006EC(void);
extern void PauseMenuInitRetained(void);
extern void sub_08033B9C(void);
void nullsub_30(struct Task *);
void sub_0803518C(u8 *);

struct Unk_08039E04 {
    void (*unk0)(struct Unk_08039E04 *);
    u32 unk4;
    u16 unk8;
    u16 unkA;
};

extern void (*const gUnk_0834BD94[])(void);

void sub_08039E24(struct Unk_08039E04 *);
void sub_08039E58(struct Unk_08039E04 *);
void sub_08039F04(struct Unk_08039E04 *);
void sub_08039F38(struct Unk_08039E04 *);
void sub_08039F94(struct Unk_08039E04 *);
void sub_08039FE4(struct Unk_08039E04 *);
void sub_08039DB0(struct Task *);
extern void m4aSongNumContinue(u16);
extern void sub_08034304(struct Object5 *);
extern const u8 gUnk_0834BD80[];
extern const u8 gUnk_0834BD84[];
extern bool16 sub_0803D938(struct ObjectBase *);
extern void sub_08035788(struct Kirby *);
extern void sub_08020370(void);
extern void sub_08000798(void);
void sub_08039504(struct Unk_08039E04 *);
void sub_0803D2D0(void);
void sub_0803D2EC(void);
void sub_0803D324(struct Unk_02022930_0 *, u8);

void nullsub_30(struct Task *t)
{
}

void sub_08035FA8(void)
{
    sub_08034304(TaskGetStructPtr(gCurTask));
}

void *sub_08039490(struct ObjectBase *obj)
{
    u32 temp;

    temp = obj->unk56 != 0xFF ? gCurLevelInfo[obj->unk56].unk65E : 0xFF;
    return &gUnk_02022F50[temp * 64];
}

struct Object2 **sub_080394C8(struct ObjectBase *obj)
{
    u32 temp;

    temp = obj->unk56 != 0xFF ? gCurLevelInfo[obj->unk56].unk65E : 0xFF;
    return gUnk_02022EC0[temp];
}

void sub_08036378(void)
{
    u8 *p = TaskGetStructPtr(gUnk_03000010);

    if (p != NULL && p[0xF] != 0)
        p[0xF] = 0x31;
}

bool32 sub_0803D1C8(void)
{
    if (!(gUnk_02022930.unk0[0].unk8 & 4) && !(gUnk_02022930.unk0[1].unk8 & 4)
        && !(gUnk_02022930.unk0[2].unk8 & 4) && !(gUnk_02022930.unk0[3].unk8 & 4))
        return TRUE;
    return FALSE;
}

void sub_08036048(void)
{
    vu16 *dst = (vu16 *)0x0600E48E;
    s32 v = 0xF18F;

    *dst = v;
    dst++;
    v++;
    *dst = v;
    dst++;
    v++;
    *dst = v;
    dst += 30;
    v += 14;
    *dst = v;
    dst++;
    v = 0xF59F;
    *dst = v;
    v = 0xF1A1;
    dst[1] = v;
}

void sub_08039DB0(struct Task *t)
{
    m4aSongNumContinue(0x16);
    m4aSongNumContinue(0x17);
    m4aMPlayVolumeControl(&gMPlayInfo_1, 0xFFFF, 0x100);
    m4aMPlayVolumeControl(&gMPlayInfo_2, 0xFFFF, 0x100);
    m4aMPlayVolumeControl(&gMPlayInfo_3, 0xFFFF, 0x100);
    gUnk_0203AD4C = NULL;
}

void sub_08039F38(struct Unk_08039E04 *s)
{
    sub_08020370();
    sub_0803D2EC();
    sub_08000798();
    sub_08035788(&gKirbys[gUnk_0203AD3C]);
    sub_0806F734();
    s->unk0 = sub_08039504;
}

void sub_08035E28(u8 arg0)
{
    sub_080356AC(0x060078A0, 0xE, arg0);
}

void sub_08036194(void)
{
    *(vu16 *)0x0600E002 = 0xF1B0;
    *(vu16 *)0x0600E042 = 0xF1B1;
}

void sub_080361B0(void)
{
    *(vu16 *)0x0600E002 = 0xF184;
    *(vu16 *)0x0600E042 = 0xF184;
}

void sub_080361C8(void)
{
    u16 i;
    s32 v;
    vu16 *dst;

    if (!(gUnk_0203AD10 & 0x10)) {
        dst = (vu16 *)0x0600E4AA;
        for (i = 0; i < 8; i++) {
            // NB: the (long long) promotion is load-bearing; every narrower
            // cast and every temp-local spelling diffs (permuter-found).
            *dst = (((long long)i) + 0x1BD) | 0xFFFFF000;
            dst++;
        }
    }
}

void sub_0803620C(void)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        CpuFill16(0x184, (void *)0x0600E000, 0x500);
        sub_080363B4();
        gUnk_03000010->main = sub_08035FA8;
    }
}

void sub_08036258(void)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        CpuFill16(0x184, (void *)0x0600E000, 0x500);
        sub_08034A20();
        gUnk_03000010->main = sub_080340A8;
    }
}

void nullsub_119(struct Task *t)
{
}

void sub_080395C0(void)
{
    gUnk_0203AD4C = 0;
    PauseMenuInitRetained();
}

void sub_08039E04(struct Unk_08039E04 *arg0)
{
    if (arg0->unk8 == 0) {
        m4aSongNumStart(0x1F8);
    }
    arg0->unk0 = sub_08039E24;
}

bool32 sub_080395D4(void)
{
    if ((gMainFlags & 0x400) || gUnk_0203AD4C != 0) {
        return FALSE;
    }
    return TRUE;
}

void sub_08039D7C(void)
{
    struct Unk_08039E04 *s = TaskGetStructPtr(gCurTask);

    s->unk0(s);
}

void sub_08039E24(struct Unk_08039E04 *arg0)
{
    struct Unk_02022930_0 *r0;

    arg0->unkA = 0;
    r0 = sub_0803CA20(7);
    r0->unk8 |= 0x80;
    r0->unk4 = 0xFFFF;
    r0->unk6 = -1;
    arg0->unk0 = sub_08039E58;
}

void sub_08039F04(struct Unk_08039E04 *arg0)
{
    sub_080203C8();
    if (arg0->unk4 != 0) {
        if (gUnk_0203AD10 & 2) {
            sub_08031CE4(8);
        }
        arg0->unk0 = sub_08039F38;
    }
}

void sub_08039ED4(struct Unk_08039E04 *arg0)
{
    sub_08020220();
    sub_0803D2D0();
    sub_080006EC();
    gUnk_0834BD94[arg0->unk8]();
    arg0->unk0 = sub_08039F04;
}

void sub_08039F74(struct Unk_08039E04 *arg0)
{
    if (arg0->unkA++ > 2) {
        arg0->unk0 = sub_08039F94;
    }
}

void sub_08039FE4(struct Unk_08039E04 *arg0)
{
    TaskDestroy(gCurTask);
}

void sub_08039F94(struct Unk_08039E04 *arg0)
{
    struct Unk_02022930_0 *r0;
    u16 c;

    arg0->unkA = 0;
    r0 = sub_0803C95C(7);
    r0->unk8 |= 0x80;
    r0->unk4 = 0xFFFF;
    r0->unk6 = -1;
    c = 0x7FFF;
    sub_0803D21C(&c, 0, 1);
    arg0->unk0 = sub_08039FE4;
    arg0->unk0(arg0);
}

bool8 sub_0803D1A4(u8 arg0)
{
    if (gUnk_02022930.unk0[arg0].unk8 & 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_0803D208(u32 arg0)
{
    TaskDestroy(gUnk_02022920);
}

void sub_0803D21C(const u16 *palette, u8 offset, u16 num)
{
    CpuSet(palette, &gBgPalette[offset], num);
    CpuSet(palette, &gUnk_02022120[offset], num);
}

void sub_0803D250(const u16 **arg0, const u16 **arg1)
{
    CpuSet(arg0[0], gUnk_02022120, CPU_SET_32BIT | 0x30);
    CpuSet(arg1[0], &gUnk_02022120[0x60], CPU_SET_32BIT | 0x40);
}

void sub_0803D280(u8 arg0, u8 arg1)
{
    u16 *src = &gObjPalette[arg0];
    s16 count;
    u16 *dest = &gUnk_02022320[arg0];

    count = arg1;
    CpuSet(src, dest, count);
}

void sub_0803D2A8(u8 arg0, u8 arg1)
{
    s16 count;
    u16 *src = &gBgPalette[arg0];
    u16 *dest = &gUnk_02022120[arg0];

    count = arg1;
    CpuSet(src, dest, count);
}

void sub_0803D2D0(void)
{
    CpuFastSet(gUnk_02022120, gUnk_02022520, 0x100);
}

void sub_0803D2EC(void)
{
    CpuFastSet(gUnk_02022520, gUnk_02022120, 0x100);
}

struct Unk_02022930_0 *sub_0803D308(u8 arg0)
{
    return &gUnk_02022930.unk0[arg0];
}

void sub_0803D318(struct Task *t)
{
    gUnk_02022920 = NULL;
}

void sub_0803D324(struct Unk_02022930_0 *arg0, u8 arg1)
{
    struct Unk_02022930_0 *r2 = gUnk_02022930.unk80[arg1];

    if (r2 != NULL) {
        if (r2->unk3 <= arg0->unk3) {
            sub_0803D324(arg0, arg1 + 1);
            return;
        }
        sub_0803D324(r2, arg1 + 1);
    }
    gUnk_02022930.unk80[arg1] = arg0;
}

void sub_080396BC(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 9;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039728(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0xa;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039794(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0xb;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039800(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0xc;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_0803986C(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0xd;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_080398D8(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0xe;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039944(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0xf;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_080399B0(void)
{
    struct Task *t;
    u32 base, off;
    u32 v = 0x10;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & v) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = v;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039A1C(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x11;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039A88(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x12;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039AF4(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x13;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039B60(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x14;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039BCC(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x15;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039C38(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x16;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039CA4(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x17;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08039D10(void)
{
    struct Task *t;
    u32 base, off;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    if (t->flags & TASK_USE_EWRAM) {
        off = t->structOffset << 2;
        base = EWRAM_START;
    } else {
        off = t->structOffset;
        base = IWRAM_START;
    }
    t = (void *)(off + base);
    ((struct Unk_08039E04 *)t)->unk0 = sub_08039E04;
    ((struct Unk_08039E04 *)t)->unk8 = 0x18;
    ((struct Unk_08039E04 *)t)->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08034D68(struct Kirby *);
void sub_08036470(void);

void sub_08036314(struct ObjectBase *arg0)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        if (gUnk_03000010->main == sub_080340A8) {
            CpuFill16(0x184, (void *)0x0600E000, 0x500);
            sub_08034D68(&gKirbys[gUnk_0203AD3C]);
        }
    }
}

void sub_0803641C(void)
{
    TaskCreate(sub_08036470, 4, 0xFFFD, 0, nullsub_119);
    gUnk_0203AD40 = 0;
    gUnk_02022EB0[0][0] = 0;
    gUnk_02022EB0[0][1] = 0;
    gUnk_02022EB0[1][0] = 0;
    gUnk_02022EB0[1][1] = 0;
    gUnk_02022EB0[2][0] = 0;
    gUnk_02022EB0[2][1] = 0;
    gUnk_02022EB0[3][0] = 0;
    gUnk_02022EB0[3][1] = 0;
    gUnk_02022F40[0] = 0;
    gUnk_02022F40[1] = 0;
    gUnk_02022F40[2] = 0;
    gUnk_02022F40[3] = 0;
}

void sub_08039670(void)
{
    struct Unk_08039E04 *s = TaskGetStructPtr(gUnk_0203AD4C);
    s->unk4 = 1;
    CpuFill32(0, (void *)0x06000000, 0x10000);
}

void sub_0803386C(struct Kirby *kirby)
{
    DmaFill32(3, 0, kirby->unk124, 0x80);
    kirby->unk1A0[0] = 0;
    kirby->unk1A0[1] = 0;
    kirby->unk1A0[2] = 0;
    kirby->unk1A4 = 0;
}

void sub_08035EF8(struct ObjectBase *obj)
{
    u16 *p = TaskGetStructPtr(gUnk_03000010);
    if (!(gUnk_0203AD10 & 0x10)) {
        if (obj->unk56 == gUnk_0203AD3C) {
            p[2] = 0xC;
        }
    }
}

void sub_08035F50(struct ObjectBase *obj)
{
    u16 *p = TaskGetStructPtr(gUnk_03000010);
    if (!(gUnk_0203AD10 & 0x10)) {
        if (obj->unk56 == gUnk_0203AD3C) {
            p[2] = 0x7C;
        }
    }
}

void sub_0803CD40(void)
{
    struct Unk_02022930_0 *arr = gUnk_02022930.unk0;
    struct Unk_02022930_0 *p;
    u8 i;

    for (i = 0; i < 8; i++) {
        p = &arr[i];
        if (p->unk8 & 4) {
            if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == (s16)p->unkE) {
                if (!(p->unk8 & 0x10)) {
                    p->unk8 |= 2;
                }
            }
        }
    }
}

extern const u16 gUnk_0834BB20[];
extern const u16 gUnk_082EC7A0[];
extern const u16 *const gUnk_08D60EE4[];

void sub_08035E40(struct ObjectBase *obj)
{
    u16 *p = TaskGetStructPtr(gUnk_03000010);
    if (!(gUnk_0203AD10 & 0x10)) {
        if (obj->unk56 == gUnk_0203AD3C) {
            p[2] = 0;
            sub_08034C9C(2);
        }
    }
}

void sub_08035E9C(struct ObjectBase *obj)
{
    u16 *p = TaskGetStructPtr(gUnk_03000010);
    if (!(gUnk_0203AD10 & 0x10)) {
        if (obj->unk56 == gUnk_0203AD3C) {
            p[2] = 0x80;
            sub_08034C9C(6);
        }
    }
}

void sub_08035FDC(void)
{
    u8 c = gKirbys[gUnk_0203AD3C].color;
    void *dest = (void *)0x060070A0;

    sub_0803D21C(&gUnk_0834BB20[c * 0x10], 0xF0, 0x10);
    CpuSet(gUnk_082EC7A0, dest, 0x380);
    dest += 0x700;
    CpuSet(gUnk_08D60EE4[gLanguage], dest, 0x80);
}

void sub_080362A4(void)
{
    if (!(gUnk_0203AD10 & 0x10)) {
        if (gUnk_03000010->main == sub_080340A8) {
            CpuFill16(0x184, (void *)0x0600E000, 0x500);
            gUnk_03000010->main = sub_08033B9C;
            sub_08035788(&gKirbys[gUnk_0203AD3C]);
        }
    }
}

extern const u16 *const gUnk_08D60F8C[];

struct Unk_02022930_0 *sub_0803CB64(u8 arg0)
{
    struct Unk_02022930_0 *arr = gUnk_02022930.unk0;
    struct Unk_02022930_0 *p = &arr[arg0];

    p->unk8 = 4;
    if (arg0 >= gUnk_0203AD44) {
        p->unk8 = 6;
    } else if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == gKirbys[arg0].base.base.base.roomId) {
        p->unk8 = 6;
    }
    p->unkA = 0;
    p->unk2 = 0xFF;
    return p;
}

void sub_080363B4(void)
{
    vu16 *dst = (vu16 *)0x0600E18E;
    u8 i, j;

    CpuSet(gUnk_08D60F8C[gLanguage], (void *)0x060070A0, 0x400);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 16; j++) {
            *dst = (i * 16 + (((long long)j) + 0x185)) | 0xFFFFF000;
            dst++;
        }
        dst += 0x10;
    }
}

extern void sub_08037314(void);
extern void sub_08038B34(void);
extern void sub_0808838C(void);

void sub_08036470(void)
{
    sub_08037314();
    sub_08038B34();
    sub_0808838C();
    gUnk_02022EB0[0][0] = 0;
    gUnk_02022EB0[0][1] = 0;
    gUnk_02022EB0[1][0] = 0;
    gUnk_02022EB0[1][1] = 0;
    gUnk_02022EB0[2][0] = 0;
    gUnk_02022EB0[2][1] = 0;
    gUnk_02022EB0[3][0] = 0;
    gUnk_02022EB0[3][1] = 0;
    gUnk_02022F40[0] = 0;
    gUnk_02022F40[1] = 0;
    gUnk_02022F40[2] = 0;
    gUnk_02022F40[3] = 0;
    gUnk_02022F50[0] = NULL;
    gUnk_02022F50[64] = NULL;
    gUnk_02022F50[128] = NULL;
    gUnk_02022F50[192] = NULL;
    gUnk_02022EC0[0][0] = NULL;
    gUnk_02022EC0[1][0] = NULL;
    gUnk_02022EC0[2][0] = NULL;
    gUnk_02022EC0[3][0] = NULL;
    gUnk_0203AD40++;
}

void sub_08039E58(struct Unk_08039E04 *arg0)
{
    u16 c;

    if (++arg0->unkA > 0x1E) {
        c = 0x7FFF;
        sub_0803D21C(&c, 0, 1);
        if (gUnk_0203AD10 & 2)
            sub_08031CE4(8);
        arg0->unk0 = sub_08039ED4;
        m4aSongNumStop(0x16);
        m4aSongNumStop(0x17);
        m4aMPlayVolumeControl(&gMPlayInfo_1, 0xFFFF, 0);
        m4aMPlayVolumeControl(&gMPlayInfo_2, 0xFFFF, 0);
    }
}

void sub_08039600(u16 arg0)
{
    struct Task *t;
    struct Unk_08039E04 *s;

    t = TaskCreate(sub_08039D7C, 0xC, 1, 4, sub_08039DB0);
    gUnk_0203AD4C = t;
    s = TaskGetStructPtr(t);
    s->unk0 = sub_08039E04;
    s->unk8 = arg0;
    s->unk4 = 0;
    gMainFlags |= 0x400;
}

void sub_08036114(void)
{
    u8 c = gKirbys[gUnk_0203AD3C].color;
    vu16 *dst = (vu16 *)0x0600E198;
    u8 i;

    sub_0803D21C(&gUnk_0834BB20[c * 0x10], 0xF0, 0x10);
    CpuSet(gUnk_08D60F8C[gLanguage], (void *)0x060070A0, 0x400);
    for (i = 0; i < 6; i++) {
        *dst = (((long long)i) + 0x1B5) | 0xFFFFF000;
        dst++;
    }
}

u8 sub_08039430(struct ObjectBase *obj, s32 x, s32 y, s16 offX, s16 offY, u16 w, u16 h)
{
    s32 x1 = (x >> 8) + offX;
    s32 y1 = (y >> 8) + offY;

    if ((((obj->x >> 8) <= x1 && (obj->x >> 8) + 1 >= x1)
             || ((obj->x >> 8) >= x1 && x1 + w >= (obj->x >> 8)))
     && (((obj->y >> 8) <= y1 && (obj->y >> 8) + 1 >= y1)
             || ((obj->y >> 8) >= y1 && y1 + h >= (obj->y >> 8))))
        return TRUE;
    return FALSE;
}

void sub_08034BB4(void)
{
    vu16 *dst = (vu16 *)0x0600E350;
    u8 i, j;

    for (j = 0; j < 2; j++) {
        for (i = 12; i < 14; i++) {
            *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
            dst++;
        }
        dst += 30;
    }
    dst = (vu16 *)0x0600E290;
    for (j = 0; j < 2; j++) {
        for (i = 12; i < 14; i++) {
            *dst = 0xF184;
            dst++;
        }
        dst += 30;
    }
}

void sub_08034C28(void)
{
    vu16 *dst = (vu16 *)0x0600E290;
    u8 i, j;

    for (j = 0; j < 2; j++) {
        for (i = 12; i < 14; i++) {
            *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
            dst++;
        }
        dst += 30;
    }
    dst = (vu16 *)0x0600E350;
    for (j = 0; j < 2; j++) {
        for (i = 12; i < 14; i++) {
            *dst = 0xF184;
            dst++;
        }
        dst += 30;
    }
}

void sub_08034034(void)
{
    u8 i;
    struct Kirby *k;

    for (i = 0; i < gUnk_0203AD44; i++) {
        if (i != gUnk_0203AD3C) {
            k = &gKirbys[i];
            if (gKirbys[gUnk_0203AD3C].base.base.base.roomId != k->base.base.base.roomId) {
                k->base.base.base.sprite.unk8 |= 0x80000;
                k->base.other.unk7C[1].unk8 |= 0x80000;
                k->base.other.unk7C[0].unk8 |= 0x80000;
            }
        }
    }
}

void sub_0803A1F4(void);

void sub_08039FF8(struct Unk_02022930_0 *arg0)
{
    u8 i;
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p;

    if (gUnk_02022920 == NULL) {
        gUnk_02022920 = TaskCreate(sub_0803A1F4, 0, 0xFFFE, 4, sub_0803D318);
        for (i = 0; i < 8; i++) {
            g->unk80[i] = NULL;
        }
    }
    p = g->unk80[0];
    if (p != NULL) {
        if (p->unk3 > arg0->unk3) {
            sub_0803D324(p, 1);
        } else {
            sub_0803D324(arg0, 1);
            return;
        }
    }
    g->unk80[0] = arg0;
}

extern void sub_0803A078(void);

struct Unk_02022930_0 *sub_0803CAE4(u8 arg0)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 0x14;
    p->unkE = gKirbys[arg0].base.base.base.roomId;
    p->unkA = 0x200;
    p->unkC = 0;
    p->unk1 = 0;
    p->unk2 = 0x1F;
    p->unk0 = 1;
    p->unk3 = 0xA;
    p->unk4 = 0xFFFF;
    p->unk6 = -1;
    sub_08039FF8(p);
    return p;
}

extern const u32 gUnk_0834BD60[];

void sub_08036088(struct Kirby *kirby)
{
    u16 i;
    u8 v = kirby->lives;

    if (v > 0x63) {
        v = 0x63;
    }
    for (i = 0; i < 2; i++) {
        u32 off = (i + 0xA) * 2;
        vu16 *dst = (vu16 *)(off + 0x0600E480);
        u32 d = gUnk_0834BD60[i + 6];
        u32 t = v / d;
        u16 q = t;
        v = v - d * t;
        *dst = (((long long)q) + 0x185) | 0xFFFFF000;
        dst = (vu16 *)(off + 0x0600E4C0);
        *dst = (((long long)q) + 0x195) | 0xFFFFF000;
    }
}

struct Unk_02022930_0 *sub_0803C83C(u8 arg0, u16 arg1)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 0xC;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == arg1) {
        p->unk8 = 0xE;
    }
    p->unkE = arg1;
    p->unkA = 0x200;
    p->unkC = 0;
    p->unk1 = 0;
    p->unk2 = 0x1F;
    p->unk0 = 1;
    p->unk3 = 0xF;
    p->unk4 = 0xFFFF;
    p->unk6 = -1;
    sub_08039FF8(p);
    return p;
}

struct Unk_02022930_0 *sub_0803C8CC(u8 arg0, u16 arg1)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 0xC;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == arg1) {
        p->unk8 = 0xE;
    }
    p->unkE = arg1;
    p->unkA = 0x200;
    p->unkC = 0;
    p->unk1 = 0;
    p->unk2 = 0x1F;
    p->unk0 = 1;
    p->unk3 = 8;
    p->unk4 = 0xFFFF;
    p->unk6 = -1;
    sub_08039FF8(p);
    return p;
}

struct Unk_02022930_0 *sub_0803C95C(u8 arg0)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 4;
    if (arg0 >= gUnk_0203AD44) {
        p->unk8 = 6;
    } else if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == gKirbys[arg0].base.base.base.roomId) {
        p->unk8 = 6;
    }
    p->unkE = gKirbys[arg0].base.base.base.roomId;
    p->unkA = 0xFE00;
    p->unkC = 0x1F00;
    p->unk1 = 0x1F;
    p->unk2 = 0;
    p->unk0 = 1;
    p->unk4 = 0xFFFF;
    p->unk6 = -1;
    p->unk3 = 0xA;
    sub_08039FF8(p);
    return p;
}

struct Unk_02022930_0 *sub_0803CA20(u8 arg0)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 0x4C;
    if (arg0 >= gUnk_0203AD44) {
        p->unk8 = 0x4E;
    } else if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == gKirbys[arg0].base.base.base.roomId) {
        p->unk8 = 0x4E;
    }
    p->unkE = gKirbys[arg0].base.base.base.roomId;
    p->unkA = 0x200;
    p->unkC = 0;
    p->unk1 = 0;
    p->unk2 = 0x1F;
    p->unk0 = 1;
    p->unk3 = 0xA;
    p->unk4 = 0xFFFF;
    p->unk6 = -1;
    sub_08039FF8(p);
    return p;
}

struct Unk_02022930_0 *sub_0803CBC4(u8 arg0)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 0x4C;
    if (arg0 >= gUnk_0203AD44) {
        p->unk8 = 0x4E;
    } else if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == gKirbys[arg0].base.base.base.roomId) {
        p->unk8 = 0x4E;
    }
    p->unkE = gKirbys[arg0].base.base.base.roomId;
    p->unkA = 0x100;
    p->unkC = 0;
    p->unk1 = 0;
    p->unk2 = 0xA;
    p->unk0 = 0;
    p->unk4 = 0x3F00;
    p->unk6 = 0x3FFF;
    p->unk3 = 5;
    sub_08039FF8(p);
    return p;
}

struct Unk_02022930_0 *sub_0803CC80(u8 arg0)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    struct Unk_02022930_0 *p = &g->unk0[arg0];
    u8 i;

    for (i = 0; i < 8; i++) {
        if (g->unk80[i] == p) {
            g->unk80[i] = NULL;
            sub_0803A078();
        }
    }
    p->unk8 = 4;
    if (arg0 >= gUnk_0203AD44) {
        p->unk8 = 6;
    } else if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == gKirbys[arg0].base.base.base.roomId) {
        p->unk8 = 6;
    }
    p->unkE = gKirbys[arg0].base.base.base.roomId;
    p->unkA = 0xFE00;
    p->unkC = 0xA00;
    p->unk1 = 0xA;
    p->unk2 = 0;
    p->unk0 = 0;
    p->unk4 = 0x3F00;
    p->unk6 = 0x3FFF;
    p->unk3 = 5;
    sub_08039FF8(p);
    return p;
}

void sub_0803C748(struct Unk_02022930_0 *p)
{
    u16 *pal;
    u16 i;
    s32 t;
    s32 sum;
    u16 dv;
    s32 v;
    s32 lim;
    u8 saved;

    if (p->unk8 & 2) {
        pal = gBgPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk6 >> i) & 1) {
                t = -1;
                CpuSet(&t, pal, 0x05000008);
            }
            pal += 0x10;
        }
        pal = gObjPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk4 >> i) & 1) {
                t = -1;
                CpuSet(&t, pal, 0x05000008);
            }
            pal += 0x10;
        }
        gMainFlags |= 3;
    }
    if (!(p->unk8 & 1)) {
        sum = (u16)p->unkA + p->unkC;
        p->unkC = sum;
        v = (s16)sum >> 8;
        p->unk1 = v;
        lim = (s8)p->unk2;
        saved = p->unk2;
        if ((v <= lim && (s16)(u16)p->unkA < 0) || (v >= lim && (s16)(u16)p->unkA > 0)) {
            if (p->unk8 & 0x20) {
                if (p->unk8 & 0x40) {
                    p->unkC = (s8)p->unk2 << 8;
                    p->unk1 = saved;
                } else {
                    p->unk8 = (p->unk8 | 1) & 0xFF59;
                }
            } else {
                p->unk1 = saved;
                p->unk8 |= 0x20;
            }
        }
    }
}

extern const u16 *const gUnk_08D60F2C[];
extern const u16 *const gUnk_08D60F44[];

void sub_08034828(u8 arg0)
{
    vu16 *dst = (vu16 *)0x0600E000;
    u8 i, j;

    switch (arg0) {
    case 0:
    default:
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 14; i++) {
                *dst = 0xF184;
                dst++;
            }
            dst += 18;
        }
        break;
    case 1:
        CpuSet(gUnk_08D60F2C[gLanguage], (void *)0x06007C60, 0x1D0);
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 14; i++) {
                *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
                dst++;
            }
            dst += 18;
        }
        break;
    case 2:
        CpuSet(gUnk_08D60F44[gLanguage], (void *)0x06007C60, 0x1D0);
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 14; i++) {
                *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
                dst++;
            }
            dst += 18;
        }
        break;
    }
}

extern const u16 *const gUnk_08D60EFC[];
extern const u16 *const gUnk_08D60F14[];

void sub_08034924(u8 arg0)
{
    vu16 *dst = (vu16 *)0x0600E000;
    u8 i, j;

    switch (arg0) {
    case 0:
    default:
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 14; i++) {
                *dst = 0xF184;
                dst++;
            }
            dst += 18;
        }
        break;
    case 1:
        CpuSet(gUnk_08D60EFC[gLanguage], (void *)0x06007C60, 0x1D0);
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 14; i++) {
                *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
                dst++;
            }
            dst += 18;
        }
        break;
    case 2:
        CpuSet(gUnk_08D60F14[gLanguage], (void *)0x06007C60, 0x1D0);
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 14; i++) {
                *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
                dst++;
            }
            dst += 18;
        }
        break;
    }
}

void sub_08039504(struct Unk_08039E04 *s)
{
    u16 i;

    gMainFlags &= ~0x400;
    s->unkA = 0;
    if (gUnk_0203AD10 & 2) {
        for (i = 0; i < gUnk_0203AD30; i++) {
            struct Kirby *k = &gKirbys[i];
            u16 v = gUnk_020382D0.unk8[0][i];
            k->movementState |= v & 2;
        }
    } else {
        gKirbys[0].movementState |= gHeldKeys & 2;
    }
    s->unk0 = sub_08039F74;
}

void sub_08034C9C(u8 arg0)
{
    u16 i;
    u8 *p;
    vu16 *dst;
    int palette;

    if (!(gUnk_0203AD10 & 0x10)) {
        p = TaskGetStructPtr(gUnk_03000010);
        palette = 0xE;
        p[0x14] = arg0;
        dst = (vu16 *)0x0600E380;
        for (i = 0; i < 6 - arg0; i++) {
            *dst = 0x184;
            dst++;
            *dst = 0x184;
            dst++;
            *dst = 0x184;
            dst++;
            *dst = 0x184;
            dst++;
            *dst = 0x184;
            dst += 0x1C;
        }
        for (i = 0; i < arg0; i++) {
            s32 v;
            v = (i * 5 + 0x1C5) | (palette << 12);
            *dst = v;
            dst++;
            v = (i * 5 + 0x1C6) | (palette << 12);
            *dst = v;
            dst++;
            v = (i * 5 + 0x1C7) | (palette << 12);
            *dst = v;
            dst++;
            v = (i * 5 + 0x1C8) | (palette << 12);
            *dst = v;
            dst++;
            v = (i * 5 + 0x1C9) | (palette << 12);
            *dst = v;
            dst += 0x1C;
        }
    }
}

void sub_08034D68(struct Kirby *kirby)
{
    u8 *p = TaskGetStructPtr(gUnk_03000010);
    vu16 *dst = (vu16 *)0x0600E004;
    s32 a, b, x, y, t;

    switch (kirby->battery) {
    case 0:
        a = 0x30;
        b = 0x31;
        break;
    case 1:
        if (p[0xD] & 0x20) {
            a = 0x35;
            b = 0x37;
        } else {
            a = 0x35;
            b = 0x36;
        }
        break;
    case 2:
        a = 0x34;
        b = 0x33;
        break;
    default:
        a = 0x32;
        b = 0x33;
        break;
    }
    x = 0x185 + a;
    t = x | 0xFFFFF000;
    *dst = t;
    dst++;
    y = 0x185 + b;
    t = y | 0xFFFFF000;
    *dst = t;
    dst += 0x1F;
    t = x | 0xFFFFF800;
    *dst = t;
    t = y | 0xFFFFF800;
    dst[1] = t;
}

void sub_0803557C(struct Object5 *p)
{
    if (p->unkF != 0) {
        if (!(gUnk_03000510.unk4 & ((1 << gUnk_0203AD3C) | 0x10))) {
            if ((u8)++p->unkF > 0x30) {
                CpuFill16(0, (void *)0x060077A0, 0x100);
                p->unkF = 0;
                sub_08034FA8(NULL);
                p->unk1C = NULL;
            }
        }
    }
    if ((s8)p->unk9 != (s8)p->unkA) {
        if ((s8)p->unk9 > (s8)p->unkA) {
            s32 d = ((s8)p->unk9 - (s8)p->unkA) >> 3;
            if (d != 0)
                p->unk9 = p->unk9 - d;
            else
                p->unk9 = p->unk9 - 1;
            if ((s8)p->unk9 <= 0) {
                p->unk9 = 0;
                p->unkF = 1;
            }
        } else if ((s8)p->unk9 < (s8)p->unkA) {
            if (gUnk_0203AD40 & 7) {
                p->unk9 = p->unk9 + 1;
                PlaySfxInternal(&gKirbys[gUnk_0203AD3C].base.base.base, 0x1F6);
            }
        }
        sub_08034FA8(p);
    }
}

extern const u16 *const gUnk_08D60B64[];
extern const u32 *const gUnk_08D60BE4[][32];

void sub_080356AC(u32 arg0, u8 arg1, u8 arg2)
{
    sub_0803D21C(gUnk_08D60B64[arg2], arg1 * 0x10, 0x10);
    gMainFlags |= 1;
    if (arg2 > 0x1B) {
        gUnk_03002EC0[gUnk_030039A4].unk0 = (uintptr_t)gUnk_08D60BE4[gLanguage][arg2];
        gUnk_03002EC0[gUnk_030039A4].unk4 = arg0;
        gUnk_03002EC0[gUnk_030039A4].unk8 = 0x140;
    } else {
        gUnk_03002EC0[gUnk_030039A4].unk0 = (uintptr_t)gUnk_08D60BE4[gLanguage][arg2];
        gUnk_03002EC0[gUnk_030039A4].unk4 = arg0;
        gUnk_03002EC0[gUnk_030039A4].unk8 = 0x3C0;
    }
    gUnk_030039A4 = (gUnk_030039A4 + 1) & 0x3F;
}

extern void sub_0804E09C(struct Kirby *);
extern void sub_0804A728(struct Kirby *);

u32 sub_080364E4(struct ObjectBase *arg0, struct Kirby *kirby)
{
    u32 flags = kirby->base.base.base.flags;
    u32 f2;
    u32 m;
    struct Object2 *p;

    if (flags & 0x200)
        return 0;
    p = arg0->parent;
    if (p == (struct Object2 *)kirby)
        return 0;
    if (arg0->unk68 & 0x20) {
        if (p->base.flags & 0x200)
            return 0;
        m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
        if ((m & arg0->unk68) == 0)
            return 0;
        if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
            return 0;
        if (flags & 0x8000)
            return 0;
        if (p != NULL && p->base.unk0 == 1 && p->type == 0x32) {
            if (kirby->ability == 0)
                return 0;
        }
        kirby->base.base.base.unk6C = p;
        if (p == NULL)
            kirby->base.base.base.unk6C = arg0;
        kirby->base.base.base.flags |= 0x40000;
        sub_0804E09C(kirby);
    } else {
        kirby->base.base.base.unk6C = arg0;
        f2 = flags | 0x40000;
        kirby->base.base.base.flags = f2;
        m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
        if ((m & arg0->unk68) == 0)
            return 0;
        if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
            return 0;
        if (f2 & 0x8000)
            return 0;
        if (arg0->unk68 & 0x800000)
            return 0;
        sub_0804A728(kirby);
    }
    return 0;
}

extern bool8 sub_080A049C(struct Object2 *, struct Kirby *);
extern bool8 sub_080A1804(struct Object2 *, struct Kirby *);
extern bool8 sub_080CC6F0(struct Object2 *, struct Kirby *);
extern bool8 sub_080B6368(struct Object2 *, struct Kirby *);
extern bool8 sub_080CE94C(struct Object2 *, struct Kirby *);
extern bool8 sub_080B0758(struct Object2 *, struct Kirby *);
extern bool8 sub_080E588C(struct Object2 *, struct Kirby *);
extern bool8 sub_080E74E4(struct Object2 *, struct Kirby *);
extern bool8 sub_080D4004(struct Object2 *, struct Kirby *);
extern bool8 sub_080E1B8C(struct Object2 *, struct Kirby *);
extern bool8 sub_080C8548(struct Object2 *, struct Kirby *);
extern bool8 sub_080AC5E0(struct Object2 *, struct Kirby *);
extern void sub_080853C8(struct Kirby *, u16);
extern struct Object5 *sub_08034E14(struct Object2 *);
extern void sub_0808845C(struct Object2 *, u16);
extern void sub_0808520C(struct Object2 *, s16);
extern void sub_080884C4(struct Object2 *);

u32 sub_080365C8(struct ObjectBase *arg0, struct Kirby *kirby)
{
    struct Object2 *p;
    u32 m;

    if (arg0->unk0 == 2) {
        if (kirby->base.base.type == 0x46 && arg0->xspeed < 0)
            return 0;
        if (arg0->unk0 == 2 && arg0->parent == kirby)
            return 0;
    }
    if (kirby->base.base.base.flags & 0x1000000) {
        if (arg0->flags & 0x40000)
            return 0;
        if (arg0->unk68 & 0x80)
            return 0;
    }
    if (arg0->parent != NULL && ((struct Object2 *)arg0->parent)->base.unk0 == 0
        && arg0->unk56 == gUnk_0203AD3C)
        sub_08034E14(&kirby->base.base);
    if (arg0->unk68 & 0x20) {
        p = arg0->parent;
        if (p == NULL)
            return 0;
        if (p->base.unk0 == 1) {
            if (p->type != 7 && p->type != 0xE)
                return 0;
            if ((u8)(kirby->base.base.type - 0x5E) > 0xE)
                return 0;
            if (!(arg0->flags & 0x10000)) {
                kirby->base.base.base.flags |= 0x40000;
                kirby->base.base.base.unk6C = p;
            }
            sub_0809CFC4(&kirby->base.base);
            return 1;
        }
        if (arg0->unk56 >= gUnk_0203AD30) {
            if ((u8)(kirby->base.base.type - 0x5E) <= 0xE)
                return 0;
            if (kirby->base.base.type == 0xA4)
                return 0;
            if (kirby->base.base.type == 0xA3 && kirby->base.base.base.unk56 < gUnk_0203AD30)
                return 0;
        }
        if (!(arg0->flags & 0x10000) && !(kirby->base.base.base.flags & 0x20000)) {
            if ((arg0->flags & 0x100000) || (kirby->base.base.base.flags & 0x200000)) {
                m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
                if ((m & arg0->unk68) != 0
                    && (arg0->unk68 & 7) >= (kirby->base.base.base.unk5C & 7)) {
                    kirby->base.base.base.flags |= 0x40000;
                    kirby->base.base.base.unk6C = p;
                }
            } else {
                kirby->base.base.base.flags |= 0x40000;
                kirby->base.base.base.unk6C = p;
            }
        }
        if (arg0->unk68 == 0x20000023)
            kirby->base.base.unk90
                = (kirby->base.base.unk90 & ~(3 << (arg0->unk56 * 2))) | (2 << (arg0->unk56 * 2));
        else
            kirby->base.base.unk90
                = (kirby->base.base.unk90 & ~(3 << (arg0->unk56 * 2))) | (1 << (arg0->unk56 * 2));
        if (kirby->base.base.base.unk5C & 0x20) {
            if (kirby->base.base.type <= 0xD4)
                return 0;
            if (!(arg0->unk68 & 0x200000))
                return 0;
        } else if (!(arg0->unk68 & 0x200000)) {
            goto _080367F8;
        }
        if ((u8)(kirby->base.base.type - 0x5E) <= 0xE) {
            arg0->flags &= ~0x40000;
            return 0;
        }
    _080367F8:
        m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
        if ((m & arg0->unk68) != 0 && (arg0->unk68 & 7) >= (kirby->base.base.base.unk5C & 7)) {
            arg0->flags |= 0x40000;
            kirby->base.base.base.unk6C = p;
            sub_0809C380(&kirby->base.base);
            return 0;
        }
        if (Macro_0810B1F4(&kirby->base.base.base))
            return 0;
        kirby->base.base.base.objBase54 += (gUnk_0203AD40 & 2) << 1;
        return 0;
    } else {
        if (!(arg0->flags & 0x10000) && !(kirby->base.base.base.flags & 0x20000)) {
            if ((arg0->flags & 0x100000) || (kirby->base.base.base.flags & 0x200000)) {
                m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
                if ((m & arg0->unk68) == 0)
                    goto _0803690E;
                if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
                    goto _080368BC;
            }
            kirby->base.base.base.flags |= 0x40000;
            kirby->base.base.base.unk6C = arg0;
        }
    _080368BC:
        m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
        if ((m & arg0->unk68) == 0)
            goto _0803690E;
        if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
            goto _0803690E;
        if (kirby->base.base.base.flags & 0x8000)
            goto _0803690E;
        if (arg0->unk68 & 0x8000)
            sub_0809C6D0(&kirby->base.base);
        else
            sub_0809B1E4(&kirby->base.base);
        if (kirby->base.base.base.unk68 & 0x20000000)
            return 0;
        return 1;
    _0803690E:
        if (!(kirby->base.base.base.flags & 0x40000))
            return 0;
        if (arg0->unk68 & 0x800000)
            return 0;
        if ((u8)(kirby->base.base.type - 0x38) > 0x1A) {
            if (kirby->base.base.type != 0x6D || !(arg0->unk68 & 0x80))
                sub_0808845C(&kirby->base.base, 0xA);
            if (!(kirby->base.base.base.flags & 0x8000))
                sub_0808520C(&kirby->base.base, 0x10);
        } else {
            sub_0808845C(&kirby->base.base, 0xA);
            if (!(kirby->base.base.base.flags & 0x8000))
                sub_0808520C(&kirby->base.base, 0x10);
        }
        if (arg0->unk68 & 0x10000)
            sub_080884C4(&kirby->base.base);
        return 0;
    }
}

u8 sub_0803699C(struct Kirby *kirby, struct ObjectBase *arg0)
{
    struct Object2 *p;
    u32 m;
    u8 ret;

    if (kirby->base.base.base.unk0 == 1 && kirby->base.base.type == 0x46 && arg0->xspeed < 0)
        return 0;
    p = arg0->parent;
    if (p == (struct Object2 *)kirby)
        return 0;
    if (kirby->base.base.base.unk0 == 1 && (kirby->base.base.base.flags & 0x1000000) &&
        (arg0->flags & 0x40000))
        return 0;
    if (arg0->unk68 & 0x20) {
        arg0->unk6C = kirby;
        m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
        if ((m & arg0->unk68) == 0)
            return 0;
        if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
            return 0;
        if (kirby->base.base.base.flags & 0x8000)
            return 0;
        if (p == NULL)
            return 0;
        p->base.unkC &= ~0x40;
        if (p->base.unk0 != 1)
            return 0;
        switch (p->type) {
        case 0x32:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080A049C(p, kirby);
            break;
        case 0x33:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080A1804(p, kirby);
            break;
        case 0x38:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080CC6F0(p, kirby);
            break;
        case 0x9E:
        case 0xAE:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080B6368(p, kirby);
            break;
        case 0x3A:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080CE94C(p, kirby);
            break;
        case 0xF:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080B0758(p, kirby);
            break;
        case 0x48:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080E588C(p, kirby);
            break;
        case 0x9F:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080E74E4(p, kirby);
            break;
        case 0x3E:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080D4004(p, kirby);
            break;
        case 0x47:
        case 0x4D:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080E1B8C(p, kirby);
            break;
        case 0x3C:
            if (kirby->base.base.base.flags & 0x8000)
                return 0;
            ret = sub_080C8548(p, kirby);
            break;
        case 0x7:
        case 0xE:
            ret = sub_080AC5E0(p, kirby);
            break;
        default:
            return 0;
        }
        if (ret)
            return 1;
        return 0;
    }

    if (!(kirby->base.base.base.flags & 0x10000) && !(arg0->flags & 0x20000)) {
        if ((kirby->base.base.base.flags & 0x100000) || (arg0->flags & 0x200000)) {
            m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
            if ((m & arg0->unk68) == 0)
                goto _08036C08;
            if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
                goto _08036C08;
        }
        arg0->flags |= 0x4000000;
        arg0->unk6C = kirby;
    }
_08036C08:
    if ((arg0->unk68 & 0x10000000) && !(kirby->base.base.base.flags & 0x400000) &&
        !(kirby->base.base.base.flags & 0x10000)) {
        if (kirby->base.base.base.flags & 0x100000) {
            m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
            if ((m & arg0->unk68) == 0)
                return 0;
            if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
                goto _08036C70;
        }
        if (!(arg0->unk68 & 0x400000) || !(kirby->base.base.base.unk5C & 0x400000))
            sub_080853C8((struct Kirby *)p, 4);
    }
_08036C70:
    m = 0x3FFFF8 & ~(kirby->base.base.base.unk5C & -8);
    if ((m & arg0->unk68) == 0)
        return 0;
    if ((arg0->unk68 & 7) < (kirby->base.base.base.unk5C & 7))
        return 0;
    if (kirby->base.base.base.flags & 0x8000)
        return 0;
    if (arg0->unk68 & 0x20000000)
        return 0;
    return 1;
}

extern void sub_08088F84(void *, s16, s16);
extern void sub_0800E0E4(struct Object2 *, s16, s16);
extern struct Object4 *sub_0808AE30(struct ObjectBase *, u32, u16, u8);
extern void sub_08085328(void *);
extern void sub_0806FE64(u16, struct ObjectBase *);

void sub_08036CBC(struct ObjectBase *arg0)
{
    s8 box[4];
    u32 flags;
    u32 maxX, minX, maxY, minY;
    s32 dir;
    u32 cx;
    u32 cy;
    u32 j;
    u32 x, y;
    u32 n;
    u32 k;
    s32 d;
    u32 t;
    u8 id;
    struct Object4 *obj;

    if (!(arg0->unk68 & 0x20))
        goto _noHit;

    dir = 1;
    flags = arg0->flags;
    if (flags & 0x40000)
        return;

    id = arg0->unk56;
    maxX = (u16)(gCurLevelInfo[id].levelMaxPosition.x << 4 >> 16);
    maxY = (u16)(gCurLevelInfo[id].levelMaxPosition.y << 4 >> 16);
    minX = (u16)(gCurLevelInfo[id].levelMinPosition.x << 4 >> 16);
    minY = (u16)(gCurLevelInfo[id].levelMinPosition.y << 4 >> 16);
    if (flags & dir) {
        box[2] = -arg0->unk3C;
        box[0] = -arg0->unk3E;
    } else {
        box[0] = arg0->unk3C;
        box[2] = arg0->unk3E;
    }
    box[1] = arg0->unk3D;
    box[3] = arg0->unk3F;
    if (flags & 1)
        dir = 0xFF;

    t = (arg0->x >> 8) & 0xF;
    d = box[2] - box[0];
    if (d < 0)
        d = box[0] - box[2];
    cx = (u8)(((d + t) >> 4) + 1);

    t = ((arg0->y >> 8) + box[1]) & 0xF;
    d = box[3] - box[1];
    if (d < 0)
        d = box[1] - box[3];
    cy = (u8)((d + t) >> 4);

    y = (u16)(arg0->y << 4 >> 16);
    for (j = 0; j <= cy; j = (u8)(j + 1)) {
        if ((s32)y <= (s16)maxY && (s32)y >= (s16)minY) {
            x = (u16)(arg0->x << 4 >> 16);
            n = cx;
            if (n != 0) {
                n = (u8)(n - 1);
                if ((s32)x <= (s16)maxX && (s32)x >= (s16)minX) {
                    d = (s8)dir;
                    do {
                        if ((gUnk_082D88B8[(u8)sub_080023E4(arg0->unk56, x, y)] & 0x00F01000) == 0x1000) {
                            id = arg0->unk56;
                            sub_08001408(id, sub_080025AC(id, x, y), NULL, NULL);
                            sub_08088F84(arg0->parent, (s16)x, (s16)y);
                            arg0->flags |= 0x80000;
                            return;
                        }
                        x = (u16)(x + d);
                        if (n == 0)
                            break;
                        n = (u8)(n - 1);
                        if ((s32)x > (s16)maxX)
                            break;
                    } while ((s32)x >= (s16)minX);
                }
            }
            if (j & 1)
                y = (u16)(y + 1 + j);
            else
                y = (u16)(y - 1 - j);
        }
    }
    return;

_noHit:
    if (arg0->flags & 1) {
        box[2] = -arg0->unk3C;
        box[0] = -arg0->unk3E;
    } else {
        box[0] = arg0->unk3C;
        box[2] = arg0->unk3E;
    }
    box[1] = arg0->unk3D;
    box[3] = arg0->unk3F;

    t = ((arg0->x >> 8) + box[0]) & 0xF;
    d = box[2] - box[0];
    if (d < 0)
        d = box[0] - box[2];
    cx = (u8)((d + t) >> 4);

    t = ((arg0->y >> 8) + box[1]) & 0xF;
    d = box[3] - box[1];
    if (d < 0)
        d = box[1] - box[3];
    cy = (u8)((d + t) >> 4);

    x = (u16)(((arg0->x >> 8) + box[0]) << 0xC >> 0x10);
    y = (u16)(((arg0->y >> 8) + box[1]) << 0xC >> 0x10);

    id = arg0->unk56;
    d = (gCurLevelInfo[id].levelMaxPosition.x >> 12) - (cx + x);
    if ((s16)d & 0x8000) {
        cx = (u8)(cx + (u16)d);
        if (cx & 0x80)
            return;
    }
    d = x - (gCurLevelInfo[id].levelMinPosition.x >> 12);
    if ((s16)d & 0x8000) {
        if ((s32)cx + (s16)d < 0)
            return;
        x = (u16)(x - (u16)d);
        cx = (u8)(cx + (u16)d);
    }
    d = (gCurLevelInfo[id].levelMaxPosition.y >> 12) - (cy + y);
    if ((s16)d & 0x8000) {
        cy = (u8)(cy + (u16)d);
        if (cy & 0x80)
            return;
    }
    d = y - (gCurLevelInfo[id].levelMinPosition.y >> 12);
    if ((s16)d & 0x8000) {
        if ((s32)cy + (s16)d < 0)
            return;
        y = (u16)(y - (u16)d);
        cy = (u8)(cy + (u16)d);
    }

    j = (u8)(cy + 1);
    while (j != 0) {
        j = (u8)(j - 1);
        n = (u8)(cx + 1);
        if (n == 0)
            continue;
        k = j + y;
        do {
            u32 tile;

            n = (u8)(n - 1);
            tile = gUnk_082D88B8[(u8)sub_080023E4(arg0->unk56, (u16)(x + n), (u16)k)];
            if (!(tile & 0x1000))
                continue;
            switch (tile & 0x00F00000) {
            case 0x00200000:
                if (!(arg0->unk68 & 0x1000))
                    continue;
                break;
            case 0x00300000:
                if (!(arg0->unk68 & 0x4000))
                    continue;
                break;
            case 0x00400000:
                if (!(arg0->unk68 & 0x800))
                    continue;
                break;
            }
            if (tile & 0x20) {
                id = arg0->unk56;
                t = n + x;
                sub_08001408(id, sub_080025AC(id, t, k), NULL, NULL);
                sub_0800E0E4((struct Object2 *)arg0, (s16)t, (s16)k);
                PlaySfx(arg0, 0x1FE);
            } else {
                id = arg0->unk56;
                t = n + x;
                sub_08001408(id, sub_080025AC(id, t, k), NULL, NULL);
                obj = sub_0808AE30(arg0, 0, 0x28D, 0);
                obj->x = (t << 12) + 0x800;
                obj->y = (k << 12) + 0x800;
                PlaySfx(arg0, 0x1FE);
                if (arg0->unk68 & 0x10000000) {
                    sub_08085328(arg0->parent);
                    sub_0806FE64(2, arg0);
                }
            }
            arg0->flags |= 0x80000;
        } while (n != 0);
    }
}

extern u8 (*const gUnk_0834BD88[])(struct ObjectBase *);
extern void sub_08038010(struct Kirby *, struct ObjectBase *);

// !!! INCOMPLETE BODY -- NOT BEHAVIOURALLY AUTHORITATIVE. DO NOT SHIP. !!!
//
// The reference is ~1731 asm lines: an outer sweep plus SIX near-identical
// bounding-box collision blocks. Decoded and written here: the outer sweep,
// and collision block 1 (ref _0803740C.._080376B0). Blocks 2-6
// (ref _080376D2.._08037B72, asm lines 7986-9254) are NOT written -- they
// re-apply the same predicate against gKirbys[], against gUnk_02022F50[i][..]
// a second time, and against gUnk_02022EC0.
//
// This links and it DIFFs, which unblocks the port's build. It does NOT do
// all the collision work the real function does. A caller will get partial
// collision resolution that looks plausible and is wrong -- a worse failure
// mode than an obvious stub, which is why this warning is here and not only
// in the commit message. Filling in blocks 2-6 is the highest-value
// follow-up on this file.
//
// Confidence: outer sweep HIGH; block 1 control flow HIGH; block 1's
// sprite-hitbox fallback predicate MEDIUM.
void sub_08037314(void)
{
    u32 i;
    u32 j;
    u8 count;
    u8 n;
    struct Object2 **pp;
    struct ObjectBase **q;
    struct ObjectBase **r;
    struct Object2 *o2;
    struct ObjectBase *obj;
    struct ObjectBase *other;
    struct Kirby *kirby;
    s32 x1, y1, x2, y2;
    s32 ax, ay;
    u8 res;
    u8 hit;

    for (i = 0; i < gUnk_0203AD44; i++) {
        pp = &gUnk_02022EC0[i][0];
        count = gUnk_02022F40[i];
        while (count != 0) {
            o2 = *pp;
            pp++;
            count--;
            if (o2 != NULL) {
                for (j = 0; j < gUnk_0203AD44; j++) {
                    kirby = &gKirbys[j];
                    if (o2->base.roomId == kirby->base.base.base.roomId
                     && !(kirby->base.base.base.flags & 0x100))
                        sub_08038010(kirby, &o2->base);
                }
                q = &gUnk_02022F50[i * 64];
                n = gUnk_02022EB0[i][0];
                while (n != 0) {
                    other = *q;
                    if ((other->unkC & 0x1000)
                     && o2->base.roomId == other->roomId
                     && !(other->flags & 0x100))
                        sub_08038010((struct Kirby *)other, &o2->base);
                    n--;
                    q++;
                }
            }
        }

        q = &gUnk_02022F50[i * 64 + 32];
        count = gUnk_02022EB0[i][1];
        while (count != 0) {
            obj = *q;
            count--;
            if (obj != NULL) {
                if (obj->flags & 1)
                    x1 = (obj->x >> 8) + (-obj->unk38 - obj->unk3A * 2);
                else
                    x1 = (obj->x >> 8) + obj->unk38;
                y1 = (obj->y >> 8) + obj->unk39;

                if (obj->flags & 0x2000000) {
                    r = &gUnk_02022F50[i * 64];
                    n = gUnk_02022EB0[i][0];
                    while (n != 0) {
                        other = *r;
                        if (other != NULL) {
                            if (obj->flags & 0x200)
                                break;
                            if (!(other->flags & 0x200)) {
                                if (other->flags & 1)
                                    x2 = (other->x >> 8) + (-other->unk38 - other->unk3A * 2);
                                else
                                    x2 = (other->x >> 8) + other->unk38;
                                y2 = (other->y >> 8) + other->unk39;

                                ax = (obj->x >> 8) + obj->sprite.unk20[0].unk4;
                                ay = (obj->y >> 8) + obj->sprite.unk20[0].unk5;
                                hit = 0;
                                if (obj->unk3A != 0 && obj->unk3B != 0) {
                                    if (((x1 <= x2 && x1 + obj->unk3A * 2 >= x2)
                                      || (x1 >= x2 && x2 + other->unk3A * 2 >= x1))
                                     && ((y1 <= y2 && y1 + obj->unk3B * 2 >= y2)
                                      || (y1 >= y2 && y2 + other->unk3B * 2 >= y1)))
                                        hit = 1;
                                }
                                if (hit == 0 && obj->sprite.unk20[0].unk0 == 0) {
                                    if (((ax <= x2 && ax + (obj->sprite.unk20[0].unk6 - obj->sprite.unk20[0].unk4) >= x2)
                                      || (ax >= x2 && x2 + other->unk3A * 2 >= ax))
                                     && ((ay <= y2 && ay + (obj->sprite.unk20[0].unk7 - obj->sprite.unk20[0].unk5) >= y2)
                                      || (ay >= y2 && y2 + other->unk3B * 2 >= ay)))
                                        hit = 1;
                                }
                                if (hit != 0) {
                                    res = gUnk_0834BD88[obj->unk0](other);
                                    if ((u16)gUnk_0834BD88[other->unk0](obj) != 0)
                                        *r = NULL;
                                    obj = *q;
                                    if (res != 0) {
                                        if (obj->flags & 0x400000)
                                            obj->flags = (obj->flags | 0x40000) & 0xFBFFFFFF;
                                        *q = NULL;
                                        break;
                                    }
                                }
                            }
                        }
                        n--;
                        r++;
                    }
                }
                obj = *q;
                if (obj != NULL) {
                    if (obj->flags & 0x400000)
                        obj->flags = (obj->flags | 0x40000) & 0xFBFFFFFF;
                }
            }
            q++;
        }
    }
}

u8 sub_0803912C(struct ObjectBase *a, struct ObjectBase *b)
{
    s8 ra[4];
    s8 rb[4];
    s32 ax, ay, bx, by;

    if (a->flags & 1) {
        ra[2] = -a->unk3C;
        ra[0] = -a->unk3E;
    } else {
        ra[0] = a->unk3C;
        ra[2] = a->unk3E;
    }
    ra[1] = a->unk3D;
    ra[3] = a->unk3F;

    if (b->flags & 1) {
        rb[2] = -b->unk3C;
        rb[0] = -b->unk3E;
    } else {
        rb[0] = b->unk3C;
        rb[2] = b->unk3E;
    }
    rb[1] = b->unk3D;
    rb[3] = b->unk3F;

    ax = a->x + (ra[0] << 8);
    bx = b->x + (rb[0] << 8);
    if ((ax <= bx && ax + ((ra[2] - ra[0]) << 8) >= bx)
     || (ax >= bx && bx + ((rb[2] - rb[0]) << 8) >= ax)) {
        ay = a->y + (ra[1] << 8);
        by = b->y + (rb[1] << 8);
        if (((ay <= by && ay + ((ra[3] - ra[1]) << 8) >= by)
          || (ay >= by && by + ((rb[3] - rb[1]) << 8) >= ay))
         && a->yspeed <= 0)
            return TRUE;
    }
    return FALSE;
}

u8 sub_0803925C(struct ObjectBase *a, struct ObjectBase *b)
{
    s32 ax, ay, bx, by;

    if (a->flags & 1)
        ax = (a->x >> 8) + (-a->unk38 - a->unk3A * 2);
    else
        ax = (a->x >> 8) + a->unk38;
    ay = (a->y >> 8) + a->unk39;
    if (b->flags & 1)
        bx = (b->x >> 8) + (-b->unk38 - b->unk3A * 2);
    else
        bx = (b->x >> 8) + b->unk38;
    by = (b->y >> 8) + b->unk39;

    if (((ax <= bx && ax + a->unk3A * 2 >= bx) || (ax >= bx && bx + b->unk3A * 2 >= ax))
     && ((ay <= by && ay + a->unk3B * 2 >= by) || (ay >= by && by + b->unk3B * 2 >= ay)))
        return TRUE;
    return FALSE;
}

u8 sub_08039358(struct ObjectBase *obj, s32 x, s32 y, u16 offX, u16 offY, u16 w, u16 h)
{
    s32 ax, ay, bx, by;

    if (obj->flags & 1)
        ax = (obj->x >> 8) + (-obj->unk38 - obj->unk3A * 2);
    else
        ax = (obj->x >> 8) + obj->unk38;
    ay = (obj->y >> 8) + obj->unk39;
    bx = (x >> 8) + (s16)offX;
    by = (y >> 8) + (s16)offY;

    if (((ax <= bx && ax + obj->unk3A * 2 >= bx) || (ax >= bx && bx + w >= ax))
     && ((ay <= by && ay + obj->unk3B * 2 >= by) || (ay >= by && by + h >= ay)))
        return TRUE;
    return FALSE;
}


void sub_0803CD98(u8 palId, u16 animId1, u8 variant1, u16 animId2, u8 variant2, u16 blend)
{
    u16 pal[16];
    u16 pal2[16];
    struct Sprite s;
    u8 i;
    s8 c;
    u16 color;

    s.tilesVram = 0x06000000;
    s.unk1B = 0xFF;
    s.x = 0;
    s.y = 0;
    s.unk14 = 0;
    s.unk16 = 0;
    s.unk1C = 0x10;
    s.palId = palId;
    s.unk8 = 0x80000;

    if (animId2 == 0 && variant2 == 0)
        CpuSet(&gObjPalette[palId * 16], pal2, 0x10);

    if (animId1 != 0 || variant1 != 0) {
        s.animId = animId1;
        s.variant = variant1;
        sub_08155128(&s);
    }

    CpuSet(&gObjPalette[palId * 16], pal, 0x10);

    if (animId2 != 0 || variant2 != 0) {
        s.animId = animId2;
        s.variant = variant2;
        sub_08155128(&s);
        CpuSet(&gObjPalette[palId * 16], pal2, 0x10);
    }

    for (i = 1; (i & 0xF0) == 0; i++) {
        c = (pal[i] & 0x1F) + ((blend * ((pal2[i] & 0x1F) - (pal[i] & 0x1F))) >> 8);
        if (c & 0xE0) {
            if (c & 0x80)
                c = 0;
            else
                c = 0x1F;
        }
        color = c;

        c = ((pal[i] >> 5) & 0x1F)
            + ((blend * (((pal2[i] >> 5) & 0x1F) - ((pal[i] >> 5) & 0x1F))) >> 8);
        if (c & 0xE0) {
            if (c & 0x80)
                c = 0;
            else
                c = 0x1F;
        }
        color |= c << 5;

        c = ((pal[i] >> 10) & 0x1F)
            + ((blend * (((pal2[i] >> 10) & 0x1F) - ((pal[i] >> 10) & 0x1F))) >> 8);
        if (c & 0xE0) {
            if (c & 0x80)
                c = 0;
            else
                c = 0x1F;
        }
        color |= c << 10;

        pal[i] = color;
    }

    if (gMainFlags & 0x20000) {
        LoadObjPaletteWithTransformation(pal, palId * 16, 0x10);
    } else {
        DmaCopy16(3, pal, &gObjPalette[palId * 16], 0x20);
        gMainFlags |= 2;
    }

    CpuSet(&gObjPalette[(u8)(palId * 16)], &gUnk_02022320[(u8)(palId * 16)], 0x10);
}

void sub_0803CFC4(u8 palId, u16 animId, u8 variant, s8 dr, s8 dg, s8 db, u16 blend)
{
    u16 pal[16];
    struct Sprite s;
    u8 i;
    s8 c;
    u16 color;

    s.tilesVram = 0x06000000;
    s.unk1B = 0xFF;
    s.x = 0;
    s.y = 0;
    s.unk14 = 0;
    s.unk16 = 0;
    s.unk1C = 0x10;
    s.palId = palId;
    s.unk8 = 0x80000;

    if (animId != 0 || variant != 0) {
        s.animId = animId;
        s.variant = variant;
        sub_08155128(&s);
    }

    CpuSet(&gObjPalette[palId * 16], pal, 0x10);

    for (i = 1; (i & 0xF0) == 0; i++) {
        c = (pal[i] & 0x1F) + ((blend * dr) >> 8);
        if (c & 0xE0) {
            if (c & 0x80)
                c = 0;
            else
                c = 0x1F;
        }
        color = c;

        c = ((pal[i] >> 5) & 0x1F) + ((blend * dg) >> 8);
        if (c & 0xE0) {
            if (c & 0x80)
                c = 0;
            else
                c = 0x1F;
        }
        color |= c << 5;

        c = ((pal[i] >> 10) & 0x1F) + ((blend * db) >> 8);
        if (c & 0xE0) {
            if (c & 0x80)
                c = 0;
            else
                c = 0x1F;
        }
        color |= c << 10;

        pal[i] = color;
    }

    if (gMainFlags & 0x20000) {
        LoadObjPaletteWithTransformation(pal, palId * 16, 0x10);
    } else {
        DmaCopy16(3, pal, &gObjPalette[palId * 16], 0x20);
        gMainFlags |= 2;
    }
    gMainFlags |= 2;

    CpuSet(&gObjPalette[(u8)(palId * 16)], &gUnk_02022320[(u8)(palId * 16)], 0x10);
}

void sub_0803A078(void)
{
    struct Unk_02022930 *g = &gUnk_02022930;

    if (g->unk80[0] == NULL && g->unk80[1] == NULL && g->unk80[2] == NULL
     && g->unk80[3] == NULL && g->unk80[4] == NULL && g->unk80[5] == NULL
     && g->unk80[6] == NULL && g->unk80[7] == NULL)
        return;

    if (g->unk80[6] == NULL) {
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
    if (g->unk80[5] == NULL) {
        g->unk80[5] = g->unk80[6];
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
    if (g->unk80[4] == NULL) {
        g->unk80[4] = g->unk80[5];
        g->unk80[5] = g->unk80[6];
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
    if (g->unk80[3] == NULL) {
        g->unk80[3] = g->unk80[4];
        g->unk80[4] = g->unk80[5];
        g->unk80[5] = g->unk80[6];
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
    if (g->unk80[2] == NULL) {
        g->unk80[2] = g->unk80[3];
        g->unk80[3] = g->unk80[4];
        g->unk80[4] = g->unk80[5];
        g->unk80[5] = g->unk80[6];
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
    if (g->unk80[1] == NULL) {
        g->unk80[1] = g->unk80[2];
        g->unk80[2] = g->unk80[3];
        g->unk80[3] = g->unk80[4];
        g->unk80[4] = g->unk80[5];
        g->unk80[5] = g->unk80[6];
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
    if (g->unk80[0] == NULL) {
        g->unk80[0] = g->unk80[1];
        g->unk80[1] = g->unk80[2];
        g->unk80[2] = g->unk80[3];
        g->unk80[3] = g->unk80[4];
        g->unk80[4] = g->unk80[5];
        g->unk80[5] = g->unk80[6];
        g->unk80[6] = g->unk80[7];
        g->unk80[7] = NULL;
    }
}

extern void (*const gUnk_0834C120[])(struct Unk_02022930_0 *);

void sub_0803A1F4(void)
{
    struct Unk_02022930 *g = &gUnk_02022930;
    u8 i;
    u16 flags;
    u32 objDirty = 0;
    u32 bgDirty = 0;
    u16 v;
    u16 t;

    flags = g->unk0[0].unk8 | g->unk0[1].unk8 | g->unk0[2].unk8 | g->unk0[3].unk8
          | g->unk0[4].unk8 | g->unk0[5].unk8 | g->unk0[6].unk8 | g->unk0[7].unk8;

    if (flags & 4) {
        v = flags & 0x100;
        for (i = 0; i < 8; i++) {
            if (!(g->unk0[i].unk8 & 0x10) && (g->unk0[i].unk8 & 4)) {
                if (!(gMainFlags & 0x800) || v == 0 || (g->unk0[i].unk8 & 0x80)) {
                    if (g->unk0[i].unk6 != 0 && bgDirty == 0) {
                        CpuSet(gUnk_02022120, gBgPalette, CPU_SET_32BIT | 0x80);
                        bgDirty = 1;
                    }
                    if (g->unk0[i].unk4 != 0 && objDirty == 0) {
                        CpuSet(gUnk_02022320, gObjPalette, CPU_SET_32BIT | 0x80);
                        objDirty = 1;
                    }
                }
            }
        }
    }

    if ((gMainFlags & 0x800) && !(flags & 0x80))
        return;

    v = flags & 0x100;
    for (i = 0; i < 8; i++) {
        if (g->unk80[i] != NULL) {
            if (!(gMainFlags & 0x800) || v == 0 || (g->unk80[i]->unk8 & 0x80)) {
                gUnk_0834C120[g->unk80[i]->unk0](g->unk80[i]);
                t = g->unk80[i]->unk8 & 2;
                if (t == 0) {
                    if (g->unk80[i]->unk8 & 1)
                        g->unk80[i] = NULL;
                    objDirty = 0;
                } else if (!(g->unk0[i].unk8 & 0x10) && (g->unk0[i].unk8 & 4)
                        && g->unk0[i].unk4 != 0) {
                    objDirty = 1;
                }
            }
        }
    }

    sub_0803A078();

    if (gMainFlags & 0x10000) {
        if (objDirty) {
            if (gMainFlags & 0x20000) {
                LoadObjPaletteWithTransformation(gObjPalette, 0, 0x100);
            } else {
                DmaCopy16(3, gObjPalette, gObjPalette, 0x200);
                gMainFlags |= 2;
            }
        }
        if (bgDirty) {
            if (gMainFlags & 0x10000) {
                LoadBgPaletteWithTransformation(gBgPalette, 0, 0x100);
            } else {
                DmaCopy16(3, gBgPalette, gBgPalette, 0x200);
                gMainFlags |= 1;
            }
        }
    }
}

extern const u16 *const gUnk_08D60F5C[];
extern const u16 *const gUnk_08D60F74[];

void sub_08034A20(void)
{
    struct Kirby *kirby = &gKirbys[gUnk_0203AD3C];
    vu16 *dst = (vu16 *)0x0600E190;
    u8 i, j;

    CpuSet(gUnk_08D60F5C[gLanguage], (void *)0x060070A0, 0x200);
    CpuSet(gUnk_08D60F74[gLanguage], (void *)0x06007C60, 0x1D0);

    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId != 0x397) {
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 16; i++) {
                *dst = (j * 16 + (((long long)i) + 0x185)) | 0xFFFFF000;
                dst++;
            }
            dst += 0x10;
        }
        dst = (vu16 *)0x0600E294;
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 6; i++) {
                *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
                dst++;
            }
            dst += 0x1A;
        }
        dst = (vu16 *)0x0600E354;
        for (j = 0; j < 2; j++) {
            for (i = 6; i < 12; i++) {
                *dst = (j * 15 + (((long long)i) + 0x1E3)) | 0xFFFFF000;
                dst++;
            }
            dst += 0x1A;
        }
        if (gKirbys[gUnk_0203AD3C].unkD9 != 0)
            sub_08034BB4();
        else
            sub_08034C28();
    }

    if (gRoomProps[gKirbys[gUnk_0203AD3C].base.base.base.roomId].priorityFlags & 8)
        sub_08036194();
    else
        sub_080361B0();
    sub_08034D68(kirby);
}

void sub_080338B4(void)
{
    struct Task *t;
    void *tmp;
    struct Object5 *p;
    struct Kirby *kirby;
    struct Sprite *s;
    u8 i;

    gBgCntRegs[1] = 0x1C04;
    CPU_FILL(0x184, (void *)0x0600E000, 0x800, 16);
    CPU_FILL(0, (void *)0x06007080, 0x600, 16);
    gBgScrollRegs[1][0] = 0;
    gBgScrollRegs[1][1] = 0;
    t = TaskCreate(sub_08033B9C, 0x200, 0xF500, 0, nullsub_30);
    gUnk_03000010 = t;
    tmp = TaskGetStructPtr(t);
    p = tmp;
    CPU_FILL(0, p, 0x200, 16);
    kirby = &gKirbys[gUnk_0203AD3C];

    if (gUnk_0203AD10 & 0x10) {
        sub_08036114();
        t->main = sub_08034034;
        return;
    }

    sub_08035FDC();
    sub_08035E28(kirby->ability);
    sub_08036048();
    sub_08036088(kirby);
    sub_0803518C((u8 *)kirby);
    sub_08034C9C(2);
    sub_08036194();
    sub_08034D68(kirby);
    sub_080361C8();
    sub_08034FA8(NULL);
    CPU_FILL(0, (void *)0x060077A0, 0x100, 16);

    p->unk0 = kirby->score;
    p->unk6 = kirby->hp;
    p->unk7 = kirby->lives;
    p->unkC = kirby->battery;
    p->unkB = gRoomProps[kirby->base.base.base.roomId].priorityFlags & 8;
    p->unk4 = 0x80;
    p->unk9 = 0;
    p->unkA = 0;
    p->unkF = 0;
    p->unk1C = NULL;
    p->unkE = 0;
    p->unk10 = 0;
    p->unkD = 0;

    for (i = 0; i < gUnk_0203AD44; i++) {
        if (gUnk_0203AD3C == i) {
            s = &p->unk20[0][i];
            s->tilesVram = 0;
            s->unk14 = 0x80;
            s->animId = 0x2DB;
            s->variant = 1;
            s->unk16 = 0;
            s->unk1B |= 0xFF;
            s->unk1C = 0x10;
            s->palId = 0;
            s->x = 8;
            s->y = 0xF;
            s->unk8 = 0x40000;
        } else {
            s = &p->unk20[0][i];
            s->tilesVram = gKirbys[i].base.base.base.sprite.tilesVram;
            s->unk14 = 0x80;
            s->animId = 0;
            s->variant = 0;
            s->unk16 = 0;
            s->unk1B |= 0xFF;
            s->unk1C = 0x10;
            s->palId = gKirbys[i].base.base.base.sprite.palId;
            s->x = 0;
            s->y = 0;
            s->unk8 = 0x42000;
        }
        s = &p->unk20[1][i];
        s->tilesVram = gKirbys[i].base.base.base.sprite.tilesVram + 0x80;
        s->unk14 = 0x80;
        s->animId = 0;
        s->variant = 0;
        s->unk16 = 0;
        s->unk1B |= 0xFF;
        s->unk1C = 0x10;
        s->palId = gKirbys[i].base.other.unk7C[1].palId;
        s->x = 0;
        s->y = 0;
        s->unk8 = 0x42000;
        s = &p->unk20[2][i];
        s->tilesVram = gKirbys[i].base.other.unk7C[0].tilesVram;
        s->unk14 = 0x80;
        s->animId = 0;
        s->variant = 0;
        s->unk16 = 0;
        s->unk1B |= 0xFF;
        s->unk1C = 0x10;
        s->palId = 0xF;
        s->x = 0;
        s->y = 0;
        s->unk8 = 0x42000;
    }
}

void sub_0803533C(struct Object5 *);

void sub_08033B9C(void)
{
    void *tmp = TaskGetStructPtr(gCurTask);
    struct Object5 *p = tmp;
    struct Kirby *kirby = &gKirbys[gUnk_0203AD3C];
    struct Sprite *s;
    u16 v;
    u8 flag;
    u8 i;

    if (p->unk6 != kirby->hp)
        sub_0803518C((u8 *)kirby);

    if (p->unk7 != kirby->lives)
        sub_08036088(kirby);

    if (gUnk_02021580 < gUnk_0203AD44
        && (gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000
            || gKirbys[gUnk_02021580].base.base.base.roomId
                != kirby->base.base.base.roomId)
        && gRoomProps[kirby->base.base.base.roomId].priorityFlags & 0x10) {
        flag = 1;
        for (i = 1; i <= 8; i++) {
            if (gUnk_0835105C[i] == kirby->base.base.base.roomId
                && *sub_08002888(1, i, 0) != 0) {
                flag = 0;
                break;
            }
        }
        for (i = 9; i <= 0xD; i++) {
            if (gUnk_0835105C[i] == kirby->base.base.base.roomId
                && *sub_08002888(1, i + 3, 0) != 0) {
                flag = 0;
                break;
            }
        }

        if (flag) {
        PlaySfxAlt(&kirby->base.base.base, 0x1FC);

        if (!(gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000)
            || kirby->lives != 0) {
            switch (p->unkE) {
            case 0:
                if (gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000)
                    sub_08034924(1);
                else
                    sub_08034828(1);
                break;
            case 0x60:
            case 0xE0:
                if (gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000)
                    sub_08034924(0);
                else
                    sub_08034828(0);
                sub_08036194();
                sub_08034D68(kirby);
                p->unkD = 0;
                break;
            case 0x80:
                if (gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000)
                    sub_08034924(2);
                else
                    sub_08034828(2);
                break;
            }

            if (p->unkE < 0x60 || (u8)(p->unkE + 0x80) < 0x60) {
                s = &p->unk20[0][gUnk_0203AD3C];
                s->tilesVram
                    = gKirbys[gUnk_02021580].base.base.base.sprite.tilesVram
                    + 0x100;
                s->palId = gUnk_02021580;
                s->unk1B = 0xFF;
                if (gUnk_0203AD20 & 8) {
                    s->y = 0x91;
                    s->unk8 |= 0x800;
                } else {
                    s->y = 0xF;
                    s->unk8 &= ~0x800;
                }
                sub_08155128(s);
                sub_0815604C(s);
            }
        } else {
            sub_08034924(0);
            sub_08036194();
            sub_08034D68(kirby);
            p->unkD = 0;
        }

            p->unkE++;
            p->unk10 |= 1;
            goto _08033F5C;
        }
    }

    if (p->unk10 & 1) {
        if (kirby->base.base.base.unk56 == gUnk_0203AD3C)
                m4aSongNumStop(0x1FC);
        sub_08034828(0);
        sub_08036194();
        sub_08034D68(kirby);
        p->unkD = 0;
        p->unkE = 0;
        p->unk10 &= ~1;
    }

    if (p->unkC != kirby->battery) {
        sub_08034D68(kirby);
        p->unkD = 0;
    } else if (p->unkC == 1) {
        p->unkD++;
        sub_08034D68(kirby);
    }

    v = gRoomProps[kirby->base.base.base.roomId].priorityFlags & 8;
    if (p->unkB != v) {
        if (v != 0)
            sub_08036194();
        else
            sub_080361B0();
    }

_08033F5C:
    if (p->unk1C != NULL)
        sub_0803533C(p);
    sub_0803557C(p);

    if (p->unk4 <= 0x7D) {
        if (p->unk4 == 8)
            sub_08034C9C(2);
        if (p->unk4 == 9)
            sub_08034C9C(3);
        if (p->unk4 == 0xA)
            sub_08034C9C(4);
        if (p->unk4 == 0xB)
            sub_08034C9C(5);
        if (p->unk4 == 0xC)
            sub_08034C9C(6);
        if (p->unk4 == 0x79)
            sub_08034C9C(5);
        if (p->unk4 == 0x7A)
            sub_08034C9C(4);
        if (p->unk4 == 0x7B)
            sub_08034C9C(3);
        if (p->unk4 == 0x7C)
            sub_08034C9C(2);
        p->unk4++;
    }

    p->unk0 = kirby->score;
    p->unk6 = kirby->hp;
    p->unk7 = kirby->lives;
    p->unkC = kirby->battery;
    p->unkB = gRoomProps[kirby->base.base.base.roomId].priorityFlags & 8;
    sub_08034304(p);
}

void sub_08034304(struct Object5 *p)
{
    struct Sprite sprite;
    struct Kirby *kirby;
    struct Sprite *s0;
    struct Sprite *s1;
    struct Sprite *s2;
    u8 *flag;
    u16 r;
    u8 i;
    u8 j;

    j = 0;
    for (i = 0; i < gUnk_0203AD44; i++) {
        if (i == gUnk_0203AD3C)
            continue;
        j++;
        kirby = &gKirbys[i];
        s0 = &p->unk20[0][i];
        s1 = &p->unk20[1][i];
        s2 = &p->unk20[2][i];

        if (gKirbys[gUnk_0203AD3C].base.base.base.roomId
            == kirby->base.base.base.roomId) {
            r = sub_0803D938(&kirby->base.base.base);
            if (r != 0) {
                struct LevelInfo *lvl = &gCurLevelInfo[gUnk_0203AD3C];
                s0->animId = 0x2DC;
                s0->variant = 0;
                if (lvl->viewportPosition.x + 0x600 > kirby->base.base.base.x)
                    s0->x = 6;
                else if (lvl->viewportPosition.x + 0xE800 < kirby->base.base.base.x)
                    s0->x = 0xE8;
                else
                    s0->x = (kirby->base.base.base.x - lvl->viewportPosition.x) >> 8;

                if (lvl->viewportPosition.y + 0xA00 > kirby->base.base.base.y)
                    s0->y = 0xA;
                else if (lvl->viewportPosition.y + 0x8C00 < kirby->base.base.base.y)
                    s0->y = 0x8C;
                else
                    s0->y = (kirby->base.base.base.y - lvl->viewportPosition.y) >> 8;

                if (s0->x <= 0x15) {
                    if (s0->y <= 0x19) {
                        s0->variant = 3;
                        if (s0->y < gUnk_0834BD80[j] + 0xA)
                            s0->y = gUnk_0834BD80[j] + 0xA;
                    } else if (s0->y > 0x7C) {
                        s0->variant = 7;
                        if (s0->y > 0x8C - gUnk_0834BD80[j])
                            s0->y = 0x8C - gUnk_0834BD80[j];
                    } else {
                        s0->variant = 1;
                    }
                    s0->x = s0->x + gUnk_0834BD80[j];
                } else if (s0->x > 0xD8) {
                    if (s0->y <= 0x19) {
                        s0->variant = 2;
                        if (s0->y < gUnk_0834BD80[j] + 0xA)
                            s0->y = gUnk_0834BD80[j] + 0xA;
                    } else if (s0->y > 0x7C) {
                        s0->variant = 6;
                        if (s0->y > 0x8C - gUnk_0834BD80[j])
                            s0->y = 0x8C - gUnk_0834BD80[j];
                    } else {
                        s0->variant = 0;
                    }
                    s0->x = s0->x - gUnk_0834BD80[j];
                } else if (s0->y <= 0x19) {
                    s0->variant = 4;
                    s0->y = s0->y + gUnk_0834BD80[j];
                } else {
                    s0->variant = 5;
                    s0->y = s0->y - gUnk_0834BD80[j];
                }

                flag = &p->filler14[i + 1];
                if (*flag != 1) {
                    s1->unk1B = 0xFF;
                    s0->unk1B = -1;
                    s2->animId = 0;
                    s2->variant = 0;
                    *flag = 1;
                }

                if (!(gUnk_0203AD20 & 8))
                    s0->unk8 &= ~0x800;

                kirby->base.base.base.sprite.unk8 |= 0x80000;
                kirby->base.other.unk7C[1].unk8 |= 0x80000;
                kirby->base.other.unk7C[0].unk8 |= 0x80000;
                sub_08155128(s0);
                if (!(gUnk_0203AD10 & 0x20) && kirby->hp > 0
                    && (u16)(kirby->base.base.base.roomId - 0x394) > 3
                    && kirby->base.base.base.roomId != 0x38D
                    && kirby->base.base.base.roomId > 0x3D3)
                    sub_0815604C(s0);
            } else {
                flag = &p->filler14[i + 1];
                if (*flag != 0) {
                    kirby->base.base.base.sprite.unk8 &= ~0x80000;
                    kirby->base.other.unk7C[1].unk8 &= ~0x80000;
                    kirby->base.other.unk7C[0].unk8 &= ~0x80000;
                    s2->animId = r;
                    s2->variant = 0;
                    CPU_COPY(&kirby->base.base.base.sprite, &sprite, 0x28, 32);
                    sub_0815521C(&sprite, kirby->base.base.base.unk1);
                    CPU_COPY(&kirby->base.other.unk7C[1], &sprite, 0x28, 32);
                    sub_0815521C(&sprite, kirby->base.base.base.unk1);
                    *flag = 0;
                }
            }
        } else {
            u32 *pA;
            u32 *pB;
            u16 t;

            kirby->base.base.base.sprite.unk8 &= ~0x80000;
            pA = &kirby->base.other.unk7C[1].unk8;
            *pA &= ~0x80000;
            pB = &kirby->base.other.unk7C[0].unk8;
            *pB &= ~0x80000;

            if (gUnk_0203AD20 & 8) {
                s0->x = gUnk_0834BD84[j];
                s0->y = 0x91;
                s1->x = gUnk_0834BD84[j];
                s1->y = s0->y;
                s2->x = s0->x;
                s2->y = s0->y - 6;
                s0->unk8 |= 0x800;
                s1->unk8 |= 0x800;
                s2->unk8 |= 0x800;
            } else {
                s0->x = gUnk_0834BD84[j];
                s0->y = 0xF;
                s1->x = gUnk_0834BD84[j];
                s1->y = s0->y;
                s2->x = s0->x;
                s2->y = s0->y - 6;
                s0->unk8 &= ~0x800;
                s1->unk8 &= ~0x800;
                s2->unk8 &= ~0x800;
            }

            flag = &p->filler14[i + 1];
            if (*flag != 2) {
                s1->unk1B = 0xFF;
                s0->unk1B = -1;
                s2->animId = 0;
                s2->variant = 0;
                *flag = 2;
            }

            t = gRoomProps[kirby->base.base.base.roomId].priorityFlags & 8;
            if (t == 0) {
                s0->animId = 0x2DB;
                s0->variant = 0;
                s1->animId = t;
                s1->variant = 0;
            } else {
                s0->animId = gUnk_08350AAC[kirby->ability].animId;
                s0->variant = gUnk_08350AAC[kirby->ability].variant;
                s1->animId = gUnk_08350B30[kirby->ability].animId;
                s1->variant = gUnk_08350B30[kirby->ability].variant;
            }

            if (kirby->base.base.base.unkC & 0x400) {
                s2->animId = 0x2B8;
                s2->variant = 0;
            }

            if (s2->animId != 0) {
                u32 res = sub_08155128(s2);
                if (res == 0) {
                    if (s2->variant == 0) {
                        s2->variant = 1;
                    } else {
                        s2->animId = res;
                        s2->variant = 0;
                    }
                }
                if (!(gUnk_0203AD10 & 0x20) && s2->animId != 0)
                    sub_0815604C(s2);
            }

            if (s1->animId != 0) {
                sub_08155128(s1);
                if (!(gUnk_0203AD10 & 0x20))
                    sub_0815604C(s1);
            }

            sub_08155128(s0);
            if (!(gUnk_0203AD10 & 0x20))
                sub_0815604C(s0);

            kirby->base.base.base.sprite.unk8 |= 0x80000;
            *pA |= 0x80000;
            *pB |= 0x80000;
        }
    }
}

void sub_080340A8(void)
{
    void *tmp = TaskGetStructPtr(gCurTask);
    struct Object5 *p = tmp;
    struct Kirby *kirby = &gKirbys[gUnk_0203AD3C];
    u8 flag;
    u8 i;

    if (kirby->base.base.base.roomId != 0x397) {
        if (kirby->unkD9 != 0)
            sub_08034BB4();
        else
            sub_08034C28();
    }

    if (p->unkC != kirby->battery)
        sub_08034D68(kirby);

    if (gRoomProps[kirby->base.base.base.roomId].priorityFlags & 8)
        sub_08036194();
    else
        sub_080361B0();

    sub_08034304(p);
    p->unkC = kirby->battery;
    p->unkB = gRoomProps[kirby->base.base.base.roomId].priorityFlags & 8;

    if (gUnk_02021580 < gUnk_0203AD44
        && (gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000
            || gKirbys[gUnk_02021580].base.base.base.roomId
                != kirby->base.base.base.roomId)
        && gRoomProps[kirby->base.base.base.roomId].priorityFlags & 0x10) {
        flag = 1;
        for (i = 1; i <= 8; i++) {
            if (gUnk_0835105C[i] == kirby->base.base.base.roomId
                && *sub_08002888(1, i, 0) != 0) {
                flag = 0;
                break;
            }
        }
        for (i = 9; i <= 0xD; i++) {
            if (gUnk_0835105C[i] == kirby->base.base.base.roomId
                && *sub_08002888(1, i + 3, 0) != 0) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            PlaySfxAlt(&kirby->base.base.base, 0x1FC);
            p->unkE++;
            p->unk10 |= 1;
            return;
        }
    }

    if (p->unk10 & 1) {
        if (kirby->base.base.base.unk56 == gUnk_0203AD3C)
            m4aSongNumStop(0x1FC);
        p->unkE = 0;
        p->unk10 &= ~1;
    }
}

extern const u16 gUnk_083513E8[];
extern const u16 gUnk_08351458[][4];
extern const u16 gUnk_08351628[][4];

struct Object5 *sub_08034E14(struct Object2 *obj)
{
    void *tmp = TaskGetStructPtr(gUnk_03000010);
    struct Object5 *p = tmp;
    u16 v;
    s32 w;

    if (gUnk_0203AD10 & 0x10)
        return NULL;
    if (gCurTask->main == sub_08035FA8)
        return NULL;
    if (gCurTask->main == sub_080340A8)
        return NULL;
    if (obj->type > 0x5D)
        return NULL;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId != obj->base.roomId)
        return NULL;
    if (p->unk1C == obj)
        return NULL;
    if (obj == NULL) {
        p->unk1C = obj;
        sub_08034FA8(NULL);
        return NULL;
    }
    if (obj->unk80 <= 0)
        return NULL;
    if (obj->base.flags & 0x1000)
        return NULL;
    p->unk1C = obj;
    CpuSet((const u8 *)gUnk_08D60EE4[gLanguage] + (obj->type << 8),
        (void *)0x060077A0, 0x80);
    p->unkF = 0;
    if ((u8)(p->unk1C->type - 0x38) <= 0x1A) {
        if (p->unk1C->type == 0x4F)
            v = p->unk1C->unk80 * gUnk_08351628[p->unk1C->subtype][gUnk_0203AD30 - 1];
        else
            v = p->unk1C->unk80
              * gUnk_08351458[p->unk1C->type - 0x38][gUnk_0203AD30 - 1];
        w = v << 16;
    } else {
        w = (p->unk1C->unk80 * gUnk_083513E8[p->unk1C->type]) << 16;
    }
    p->unkA = w >> 24;
    if (w & 0xFF0000)
        p->unkA = (w >> 24) + 1;
    p->unk9 = p->unkA;
    sub_08034FA8(p);
    return p;
}

extern const u16 gUnk_082ECBA0[];

void sub_08034FA8(struct Object5 *obj)
{
    u16 *dst;
    u16 v;
    u16 i;

    if (gUnk_0203AD10 & 0x10)
        return;
    if (gUnk_03000010->main == sub_08035FA8)
        return;
    if (gUnk_03000010->main == sub_080340A8)
        return;
    dst = (u16 *)0x0600E4E8;
    if (obj == NULL) {
        CpuSet((const u8 *)gUnk_08D60EE4[gLanguage]
                + ((gUnk_08D6CD0C[gKirbys[gUnk_0203AD3C].base.base.base.roomId]->unk46 << 9)
                    + 0x5300),
            (void *)0x060077A0, 0x80);
        CpuSet((const u8 *)gUnk_08D60EE4[gLanguage]
                + ((gUnk_08D6CD0C[gKirbys[gUnk_0203AD3C].base.base.base.roomId]->unk46 << 9)
                    + 0x5400),
            (void *)0x060074A0, 0x80);
        *dst++ = 0xF184;
        *dst++ = 0xF184;
        *dst++ = 0xF1A5;
        *dst++ = 0xF1A6;
        *dst++ = 0xF1A7;
        *dst++ = 0xF1A8;
        *dst++ = 0xF1A9;
        *dst++ = 0xF1AA;
        *dst++ = 0xF1AB;
        *dst++ = 0xF1AC;
    } else {
        CpuSet(gUnk_082ECBA0, (void *)0x060074A0, 0x80);
        *dst = 0xF1A5;
        dst = (u16 *)0x0600E4EA;
        v = (s8)obj->unk9;
        i = 8;
        do {
            s16 t = v;
            if (t & 0xF8) {
                *dst++ = 0xF1A7;
                v = t - 8;
            } else if (t & 7) {
                *dst++ = (0x1AF - t) | 0xF000;
                v = 0;
            } else {
                *dst++ = 0xF1AF;
            }
        } while (--i != 0);
        *dst = 0xF1A6;
    }
}

void sub_0803518C(u8 *p)
{
    u8 a, b;
    u16 i;
    s8 n;
    u16 *dst;

    if (gUnk_0203AD10 & 0x10)
        return;
    a = p[0x101];
    b = p[0x100];
    if ((s8)p[0x100] < 0)
        b = 0;
    n = ((s8)a >> 1) + ((s8)a & 1);
    for (i = 0; i < n; i++) {
        dst = (u16 *)0x0600E480 + i + 13;
        if ((s8)b & 0xFE) {
            *dst = 0xF192;
            dst = (u16 *)0x0600E4C0 + i + 13;
            *dst = 0xF1A2;
            b = (s8)b - 2;
        } else if ((s8)b & 1) {
            if (!((s8)a & 0xFE) && ((s8)a & 1)) {
                *dst = 0xF1B2;
                dst = (u16 *)0x0600E4C0 + i + 13;
                *dst = 0xF1A4;
            } else {
                *dst = 0xF193;
                dst += 0x20;
                *dst = 0xF1A3;
            }
            b = (s8)b - 1;
        } else {
            if (!((s8)a & 0xFE) && ((s8)a & 1)) {
                *dst = 0xF9B4;
                dst = (u16 *)0x0600E4C0 + i + 13;
                *dst = 0xF1B4;
            } else {
                *dst = 0xF194;
                dst += 0x20;
                *dst = 0xF994;
            }
        }
        a = (s8)a - 2;
    }
    if (!(p[0x101] & 1)) {
        dst = (u16 *)0x0600E480 + i + 13;
        *dst = 0xF9B3;
        dst = (u16 *)0x0600E4C0 + i + 13;
        *dst = 0xF1B3;
    }
}

void sub_0803533C(struct Object5 *p)
{
    u16 v;
    s32 w;
    s32 t;
    s32 d;

    if (p->unk1C->unk80 <= 0) {
        p->unkA = 0;
    } else {
        if ((u8)(p->unk1C->type - 0x38) <= 0x1A) {
            if (p->unk1C->type == 0x4F)
                v = p->unk1C->unk80 * gUnk_08351628[p->unk1C->subtype][gUnk_0203AD30 - 1];
            else
                v = p->unk1C->unk80
                  * gUnk_08351458[p->unk1C->type - 0x38][gUnk_0203AD30 - 1];
            w = v << 16;
        } else {
            w = (p->unk1C->unk80 * gUnk_083513E8[p->unk1C->type]) << 16;
        }
        p->unkA = w >> 24;
        if (w & 0xFF0000)
            p->unkA = (w >> 24) + 1;
    }
    if (p->unk1C->base.flags & 0x1000) {
        if (p->unk1C->unk80 <= 0) {
            p->unkA = 0;
        } else {
            CPU_FILL(0, (void *)0x060077A0, 0x100, 16);
            p->unk9 = 0;
            p->unkA = 0;
            sub_08034FA8(NULL);
        }
        p->unk1C = NULL;
        return;
    }
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId != p->unk1C->base.roomId
        || gKirbys[gUnk_0203AD3C].hp <= 0 || (gUnk_0203AD10 & 0x20)) {
        CPU_FILL(0, (void *)0x060077A0, 0x100, 16);
        p->unk9 = 0;
        p->unkA = 0;
        sub_08034FA8(NULL);
        p->unk1C = NULL;
        return;
    }
    if ((u8)(p->unk1C->type - 0x38) <= 0x1A) {
        t = p->unk1C->base.x - 0x7800;
        d = gCurLevelInfo[gUnk_0203AD3C].viewportPosition.x - t;
        if (d < 0)
            d = t - gCurLevelInfo[gUnk_0203AD3C].viewportPosition.x;
        if (d <= 0xF000) {
            t = p->unk1C->base.y - 0x5000;
            d = gCurLevelInfo[gUnk_0203AD3C].viewportPosition.y - t;
            if (d < 0)
                d = t - gCurLevelInfo[gUnk_0203AD3C].viewportPosition.y;
            if (d <= 0xC800)
                return;
        }
    } else {
        t = p->unk1C->base.x - 0x7800;
        d = gCurLevelInfo[gUnk_0203AD3C].viewportPosition.x - t;
        if (d < 0)
            d = t - gCurLevelInfo[gUnk_0203AD3C].viewportPosition.x;
        if (d <= 0xA800) {
            t = p->unk1C->base.y - 0x5000;
            d = gCurLevelInfo[gUnk_0203AD3C].viewportPosition.y - t;
            if (d < 0)
                d = t - gCurLevelInfo[gUnk_0203AD3C].viewportPosition.y;
            if (d <= 0x8000)
                return;
        }
    }
    CPU_FILL(0, (void *)0x060077A0, 0x100, 16);
    p->unk9 = 0;
    p->unkA = 0;
    sub_08034FA8(NULL);
    p->unk1C = NULL;
}


void sub_08035788(struct Kirby *kirby)
{
    u8 color = gKirbys[gUnk_0203AD3C].color;
    struct Object5 *p = TaskGetStructPtr(gUnk_03000010);
    vu16 *dst;
    u8 i, j;
    u16 k;
    u32 flag;

    CpuFill16(0x184, (void *)0x0600E000, 0x500);
    if (gUnk_0203AD10 & 0x10) {
        sub_0803D21C(&gUnk_0834BB20[gKirbys[gUnk_0203AD3C].color * 0x10], 0xF0, 0x10);
        CpuSet(gUnk_08D60F8C[gLanguage], (void *)0x060070A0, 0x400);
        dst = (vu16 *)0x0600E198;
        for (i = 0; i < 6; i++) {
            *dst = (((long long)i) + 0x1B5) | 0xFFFFF000;
            dst++;
        }
        return;
    }
    sub_0803D21C(&gUnk_0834BB20[color * 0x10], 0xF0, 0x10);
    if (gUnk_03000010->main == sub_08035FA8) {
        dst = (vu16 *)0x0600E18E;
        CpuSet(gUnk_08D60F8C[gLanguage], (void *)0x060070A0, 0x400);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 16; j++) {
                *dst = (i * 16 + (((long long)j) + 0x185)) | 0xFFFFF000;
                dst++;
            }
            dst += 0x10;
        }
        return;
    }
    sub_0803D21C(&gUnk_0834BB20[gKirbys[gUnk_0203AD3C].color * 0x10], 0xF0, 0x10);
    CpuSet(gUnk_082EC7A0, (void *)0x060070A0, 0x380);
    CpuSet(gUnk_08D60EE4[gLanguage], (void *)0x060077A0, 0x80);
    if (gUnk_03000010->main == sub_080340A8) {
        sub_08034A20();
        return;
    }
    if (gKirbys[gUnk_0203AD3C].unkDB != 0)
        sub_080356AC(0x060078A0, 0xE, gKirbys[gUnk_0203AD3C].unkDB);
    else
        sub_080356AC(0x060078A0, 0xE, gKirbys[gUnk_0203AD3C].ability);
    dst = (vu16 *)0x0600E48E;
    *dst++ = 0xF18F;
    *dst++ = 0xF190;
    *dst = 0xF191;
    dst += 0x1E;
    *dst++ = 0xF19F;
    *dst++ = 0xF59F;
    *dst = 0xF1A1;
    {
        u8 v = gKirbys[gUnk_0203AD3C].lives;

        if (v > 0x63) {
            v = 0x63;
        }
        for (k = 0; k < 2; k++) {
            u32 off = (k + 0xA) * 2;
            vu16 *d = (vu16 *)(off + 0x0600E480);
            u32 dv = gUnk_0834BD60[k + 6];
            u32 t = v / dv;
            u16 q = t;
            v = v - dv * t;
            *d = (((long long)q) + 0x185) | 0xFFFFF000;
            d = (vu16 *)(off + 0x0600E4C0);
            *d = (((long long)q) + 0x195) | 0xFFFFF000;
        }
    }
    sub_0803518C((u8 *)&gKirbys[gUnk_0203AD3C]);
    sub_08034C9C(p->filler14[0]);
    if (gRoomProps[gKirbys[gUnk_0203AD3C].base.base.base.roomId].priorityFlags & 8) {
        *(vu16 *)0x0600E002 = 0xF1B0;
        *(vu16 *)0x0600E042 = 0xF1B1;
    } else {
        *(vu16 *)0x0600E002 = 0xF184;
        *(vu16 *)0x0600E042 = 0xF184;
    }
    sub_08034D68(&gKirbys[gUnk_0203AD3C]);
    if (!(gUnk_0203AD10 & 0x10)) {
        dst = (vu16 *)0x0600E4AA;
        for (k = 0; k < 8; k++) {
            *dst = (((long long)k) + 0x1BD) | 0xFFFFF000;
            dst++;
        }
    }
    if (p->unk1C != NULL) {
        CpuSet((const u8 *)gUnk_08D60EE4[gLanguage] + (p->unk1C->type << 8),
            (void *)0x060077A0, 0x80);
        sub_08034FA8(p);
    } else {
        CpuFill16(0, (void *)0x060077A0, 0x100);
        sub_08034FA8(NULL);
    }
    if (gUnk_02021580 >= gUnk_0203AD44)
        return;
    if (!(gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000)
        && gKirbys[gUnk_02021580].base.base.base.roomId == kirby->base.base.base.roomId)
        return;
    if (!(gRoomProps[kirby->base.base.base.roomId].priorityFlags & 0x10))
        return;
    j = TRUE;
    for (i = 1; i < 9; i++) {
        if (gUnk_0835105C[i] == kirby->base.base.base.roomId) {
            if (*sub_08002888(1, i, 0) != 0) {
                j = FALSE;
                break;
            }
        }
    }
    for (i = 9; i < 0xE; i++) {
        if (gUnk_0835105C[i] == kirby->base.base.base.roomId) {
            if (*sub_08002888(1, i + 3, 0) != 0) {
                j = FALSE;
                break;
            }
        }
    }
    if (!j)
        return;
    flag = gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000;
    if (!flag || kirby->lives != 0) {
        if (p->unkE <= 0x5F) {
            if (flag)
                sub_08034924(1);
            else
                sub_08034828(1);
        } else if ((u8)(p->unkE + 0x80) <= 0x5F) {
            if (flag)
                sub_08034924(2);
            else
                sub_08034828(2);
        } else {
            if (flag)
                sub_08034924(0);
            else
                sub_08034828(0);
            *(vu16 *)0x0600E002 = 0xF1B0;
            *(vu16 *)0x0600E042 = 0xF1B1;
            sub_08034D68(kirby);
            p->unkD = 0;
        }
        if (p->unkE <= 0x5F || (u8)(p->unkE + 0x80) <= 0x5F) {
            struct Sprite *s = &p->unk20[0][gUnk_0203AD3C];

            s->tilesVram = gKirbys[gUnk_02021580].base.base.base.sprite.tilesVram + 0x100;
            s->palId = gUnk_02021580;
            s->unk1B = 0xFF;
            if (gUnk_0203AD20 & 8) {
                s->y = 0x91;
                s->unk8 |= 0x800;
            } else {
                s->y = 0xF;
                s->unk8 &= ~0x800;
            }
            sub_08155128(s);
            sub_0815604C(s);
        } else {
            if (gKirbys[gUnk_02021580].base.base.base.unkC & 0x10000)
                sub_08034924(0);
            else
                sub_08034828(0);
            *(vu16 *)0x0600E002 = 0xF1B0;
            *(vu16 *)0x0600E042 = 0xF1B1;
            sub_08034D68(kirby);
            p->unkD = 0;
        }
    }
    p->unk10 |= 1;
}
extern const u16 gUnk_0834BE20[];
extern const u16 gUnk_0834BEA0[];
extern const u16 gUnk_0834BF20[];
extern const u16 gUnk_0834BFA0[];
extern const u16 gUnk_0834C020[];
extern const u16 gUnk_0834C0A0[];

#define FADE_ADD(pal, tr, tg, tb)                                            \
    {                                                                        \
        u32 c = *(pal);                                                      \
        *(pal) = tr[(0x1F & c) + (s8)p->unk1] |                              \
                 tg[(((c << 16) >> 21) & 0x1F) + (s8)p->unk1] |               \
                 tb[(((c << 16) >> 26) & 0x1F) + (s8)p->unk1];                \
    }

#define FADE_SUB(pal, tr, tg, tb)                                            \
    {                                                                        \
        u32 c = *(pal);                                                      \
        *(pal) = tr[(0x1F & c) - ((s8)p->unk1 - 0x1F)] |                     \
                 tg[(((c << 16) >> 21) & 0x1F) - ((s8)p->unk1 - 0x1F)] |      \
                 tb[(((c << 16) >> 26) & 0x1F) - ((s8)p->unk1 - 0x1F)];       \
    }

#define FADE_MIX(pal, tr, tg, tb)                                            \
    {                                                                        \
        u32 c = *(pal);                                                      \
        *(pal) = tr[(0x1F & c) + (s8)p->unk1] |                              \
                 tg[(((c << 16) >> 21) & 0x1F) - ((s8)p->unk1 - 0x1F)] |      \
                 tb[(((c << 16) >> 26) & 0x1F) - ((s8)p->unk1 - 0x1F)];       \
    }

void sub_0803AFE8(struct Unk_02022930_0 *p)
{
    u16 *pal;
    u16 i;
    s32 sum;
    s32 v;
    s32 lim;
    u16 flags;
    u8 saved;

    if (p->unk8 & 2) {
        pal = gBgPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk6 >> i) & 1) {
                if (i == 0)
                    FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
            } else {
                pal += 16;
            }
        }
        pal = gObjPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk4 >> i) & 1) {
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
                FADE_ADD(pal, gUnk_0834BE20, gUnk_0834BEA0, gUnk_0834BF20);
                pal++;
            } else {
                pal += 16;
            }
        }
        gMainFlags |= 3;
    }
    flags = p->unk8;
    if (!(flags & 1)) {
        if (!(gMainFlags & 0x800) || (flags & 0x80)) {
            sum = (u16)p->unkA + p->unkC;
            p->unkC = sum;
            v = (s16)sum >> 8;
            p->unk1 = v;
            lim = (s8)p->unk2;
            saved = p->unk2;
            if ((v <= lim && (s16)(u16)p->unkA < 0) || (v >= lim && (s16)(u16)p->unkA > 0)) {
                if (flags & 0x20) {
                    if (flags & 0x40) {
                        p->unkC = (s8)p->unk2 << 8;
                        p->unk1 = saved;
                    } else {
                        p->unk8 = (flags | 1) & 0xFF59;
                    }
                } else {
                    p->unk1 = saved;
                    p->unk8 = flags | 0x20;
                }
            }
        }
    }
}

void sub_0803B788(struct Unk_02022930_0 *p)
{
    u16 *pal;
    u16 i;
    s32 sum;
    s32 v;
    s32 lim;
    u16 flags;
    u8 saved;

    if (p->unk8 & 2) {
        pal = gBgPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk6 >> i) & 1) {
                if (i == 0)
                    FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
            } else {
                pal += 16;
            }
        }
        pal = gObjPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk4 >> i) & 1) {
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_SUB(pal, gUnk_0834BFA0, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
            } else {
                pal += 16;
            }
        }
        gMainFlags |= 3;
    }
    flags = p->unk8;
    if (!(flags & 1)) {
        if (!(gMainFlags & 0x800) || (flags & 0x80)) {
            sum = (u16)p->unkA + p->unkC;
            p->unkC = sum;
            v = (s16)sum >> 8;
            p->unk1 = v;
            lim = (s8)p->unk2;
            saved = p->unk2;
            if ((v <= lim && (s16)(u16)p->unkA < 0) || (v >= lim && (s16)(u16)p->unkA > 0)) {
                if (flags & 0x20) {
                    if (flags & 0x40) {
                        p->unkC = (s8)p->unk2 << 8;
                        p->unk1 = saved;
                    } else {
                        p->unk8 = (flags | 1) & 0xFF59;
                    }
                } else {
                    p->unk1 = saved;
                    p->unk8 = flags | 0x20;
                }
            }
        }
    }
}

void sub_0803BF68(struct Unk_02022930_0 *p)
{
    u16 *pal;
    u16 i;
    s32 sum;
    s32 v;
    s32 lim;
    u16 flags;
    u8 saved;

    if (p->unk8 & 2) {
        pal = gBgPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk6 >> i) & 1) {
                if (i == 0)
                    FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
            } else {
                pal += 16;
            }
        }
        pal = gObjPalette;
        for (i = 0; i < 16; i++) {
            if ((p->unk4 >> i) & 1) {
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
                FADE_MIX(pal, gUnk_0834BE20, gUnk_0834C020, gUnk_0834C0A0);
                pal++;
            } else {
                pal += 16;
            }
        }
        gMainFlags |= 3;
    }
    flags = p->unk8;
    if (!(flags & 1)) {
        if (!(gMainFlags & 0x800) || (flags & 0x80)) {
            sum = (u16)p->unkA + p->unkC;
            p->unkC = sum;
            v = (s16)sum >> 8;
            p->unk1 = v;
            lim = (s8)p->unk2;
            saved = p->unk2;
            if ((v <= lim && (s16)(u16)p->unkA < 0) || (v >= lim && (s16)(u16)p->unkA > 0)) {
                if (flags & 0x20) {
                    if (flags & 0x40) {
                        p->unkC = (s8)p->unk2 << 8;
                        p->unk1 = saved;
                    } else {
                        p->unk8 = (flags | 1) & 0xFF59;
                    }
                } else {
                    p->unk1 = saved;
                    p->unk8 = flags | 0x20;
                }
            }
        }
    }
}


/* Palette-fade descriptor: same storage as struct Unk_02022930_0, but the fade
   code treats +1/+2 as signed and +0xA as unsigned. */
struct PalFadeTask {
    u8 unk0;
    s8 level;
    s8 target;
    u8 unk3;
    u16 objMask;
    u16 bgMask;
    u16 flags;
    u16 step;
    u16 accum;
    u16 unkE;
};

#define FADE_COLOR(pal, p)                            \
{                                                     \
    u16 v;                                            \
    u16 n;                                            \
    (pal)++;                                          \
    v = (*(pal) & 0x1F) - (p)->level;                 \
    if (v & 0x8000)                                   \
        n = 0;                                        \
    else                                              \
        n = v;                                        \
    v = ((*(pal) >> 5) & 0x1F) - (p)->level;          \
    if (!(v & 0x8000))                                \
        n |= v << 5;                                  \
    v = ((*(pal) >> 10) & 0x1F) - (p)->level;         \
    if (!(v & 0x8000))                                \
        n |= v << 10;                                 \
    *(pal) = n;                                       \
}

#define FADE_PALETTE(pal, p)                          \
{                                                     \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p) FADE_COLOR(pal, p)             \
    FADE_COLOR(pal, p)                                \
    (pal)++;                                          \
}

void sub_0803A450(struct Unk_02022930_0 *arg)
{
    struct PalFadeTask *p = (struct PalFadeTask *)arg;
    u16 *pal;
    u16 i;

    if (p->flags & 2) {
        pal = gBgPalette;
        for (i = 0; i < 16; i++) {
            if ((p->bgMask >> i) & 1)
                FADE_PALETTE(pal, p)
            else
                pal += 16;
        }
        pal = gObjPalette;
        for (i = 0; i < 16; i++) {
            if ((p->objMask >> i) & 1)
                FADE_PALETTE(pal, p)
            else
                pal += 16;
        }
        gMainFlags |= 3;
    }

    if (p->flags & 1)
        return;
    if ((gMainFlags & 0x800) && !(p->flags & 0x80))
        return;

    if (p->level == p->target) {
        if (p->flags & 0x40) {
            p->level = p->target;
        } else {
            p->flags = (p->flags | 1) & 0xFF79;
        }
    } else {
        p->accum += p->step;
        p->level = p->accum >> 8;
    }
}
