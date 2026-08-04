#include "global.h"
#include "data.h"
#include "functions.h"
#include "kirby.h"
#include "task.h"

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
void sub_08039DB0(struct Task *);
void sub_0803D2D0(void);
void sub_0803D324(struct Unk_02022930_0 *, u8);

void nullsub_30(void)
{
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
            v = (i + 0x1BD) | 0xFFFFF000;
            *dst = v;
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

void nullsub_119(void)
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

void sub_08039FE4(void)
{
    TaskDestroy(gCurTask);
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

void sub_0803D250(const u16 **arg0, const u16 **arg1)
{
    CpuSet(arg0[0], gUnk_02022120, CPU_SET_32BIT | 0x30);
    CpuSet(arg1[0], &gUnk_02022120[0x60], CPU_SET_32BIT | 0x40);
}

void sub_0803D280(u8 arg0, u8 arg1)
{
    u16 *src = &gObjPalette[arg0];
    u16 *dest = &gUnk_02022320[arg0];

    CpuSet(src, dest, arg1);
}

void sub_0803D2A8(u8 arg0, u8 arg1)
{
    u16 *src = &gBgPalette[arg0];
    u16 *dest = &gUnk_02022120[arg0];

    CpuSet(src, dest, arg1);
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

void sub_0803D318(void)
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
