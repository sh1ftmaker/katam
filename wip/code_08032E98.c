#include "global.h"
#include "data.h"
#include "functions.h"
#include "kirby.h"
#include "task.h"

extern u16 gUnk_02022120[0x100];
extern u16 gUnk_02022320[0x100];
extern u16 gUnk_02022520[0x200];
extern u32 gUnk_0203AD4C;

extern void sub_080356AC(u32, u8, u8);
extern void sub_08020220(void);
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
void sub_08039F04(struct Unk_08039E04 *);
void sub_08039F94(struct Unk_08039E04 *);
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
