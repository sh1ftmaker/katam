#include "global.h"
#include "main.h"
#include "functions.h"
#include "multi_sio.h"

struct Unk_03000020 {
    /* 0x0 */ u8 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u16 unkA;
}; /* size = 0xC */

extern struct Unk_03000020 gUnk_03000020;
extern u32 gUnk_0300002C;
extern u32 gUnk_03000030;
extern u32 gUnk_03000034;
extern u8 gUnk_03006CC0;
extern const char gAgbSramLibVer[];

void nullsub_1(void);
u32 sub_08158D14(u8);
u32 sub_08158D80(void);
u32 sub_08158DBC(u8);

void sub_08158934(void) {
    DmaFill32(3, 0, &gMultiSioSend, sizeof(gMultiSioSend));
    DmaFill32(3, 0, gMultiSioRecv, sizeof(gMultiSioRecv));
    gMultiSioStatusFlags = 0;
    gUnk_03002558 = 0;
    MultiSioInit(0);
}

void sub_0815898C(void) {
    if (gMainFlags & 0x80000) {
        REG_IME = 0;
        REG_IE &= ~INTR_FLAG_TIMER3;
        REG_IME = 1;
        REG_IME = 0;
        gIntrTable[0] = (IntrFunc)gMultiSioIntrFuncBuf;
        REG_IME = 1;
        MultiSioInit(0);
    }
    gUnk_03002558 = 1;
}

void sub_081589E8(void) {
    gUnk_03002558 = 0;
    gMainFlags &= ~0x100000;
    MultiSioStop();
    MultiSioInit(0);
    if (gMainFlags & 0x80000) {
        nullsub_1();
    }
}

void sub_08158A28(void) {
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | 0x8;
    REG_SIOCNT |= SIO_INTR_ENABLE;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
    REG_IME = 1;
    {
        u32 tmp = *(vu8 *)REG_ADDR_SIOCNT;
        tmp &= -2;
        *(vu8 *)REG_ADDR_SIOCNT = tmp;
    }
    gUnk_03006CC0 = 0;
    CpuFill32(0, &gUnk_03000020, sizeof(gUnk_03000020));
    REG_IME = 0;
    REG_SIOCNT |= SIO_ENABLE;
    REG_IME = 1;
    REG_TM3CNT_L = 0x8000;
    REG_TM3CNT_H = 0xC1;
}

// sub_08158AE4: functionally equivalent; remaining diff is register allocation
// inside the case-0 block only (80 diff lines, was 141). The recv/z pins plus
// the late s = ptr copy reproduce ref's b-extraction reload shape and the
// adds r4 base copy; still open: ref's a-extraction is in-place in r0 with a
// separate copy to r1 at the first compare (the a1 local merges back under
// copy-prop no matter how it is blocked), and a global r0/r2/r3 rotation of
// the scratch pseudos seeded by that copy. Pins are bare here because this is
// the #else branch of the wrapper; guard them if the wrapper is ever removed.
#ifndef NONMATCHING
NAKED void sub_08158AE4(void) {
    asm(".include \"asm/nonmatching/sub_08158AE4.inc\"");
}
#else
void sub_08158AE4(void) {
    gUnk_03000030 = REG_SIODATA32;
    REG_TM3CNT_H = 0;
    REG_TM3CNT_L = 0x8000;

    switch (gUnk_03006CC0) {
    case 0: {
        register u32 recv asm("r6") = REG_SIODATA32;
        struct Unk_03000020 *ptr = &gUnk_03000020;
        struct Unk_03000020 *s;
        u32 k = ptr->unk0;
        u32 x = recv << (k * 16);
        register u32 z asm("r1");
        u16 a = x >> 16;
        u16 b;
        z = recv << ((1 - k) * 16);
        b = z >> 16;
        {u16 unkAv = ptr->unkA; s = ptr;

        if (unkAv == 0) {
            u32 a1 = a;
            if (a1 == s->unk6) {
                if (s->unk2 <= 3) {
                    if (a1 == (u16)~s->unk4 && b == (u16)~s->unk6) {
                        s->unk2++;
                    }
                } else {
                    s->unkA = b;
                    if (b == 0x8002) {
                        gUnk_03006CC0 = 1;
                        gUnk_0300002C = sub_08158DBC(1);
                        REG_SIODATA32 = gUnk_0300002C;
                        s->unk2 = 0;
                        goto send;
                    }
                    s->unkA = 0;
                    s->unk2 = 0;
                }
            } else {
                s->unk2 = 0;
            }
        }
        }
        if (s->unk2 <= 3) {
            s->unk4 = *(u16 *)(gAgbSramLibVer + s->unk2 * 2);
        } else {
            s->unk4 = 0x8000;
        }
        s->unk6 = ~b;
        REG_SIODATA32 = (s->unk4 << ((1 - s->unk0) * 16))
                      + (s->unk6 << (s->unk0 * 16));
        goto send;
    }
    case 1:
        if (sub_08158D14(gUnk_03006CC0) != 0) {
            gUnk_03000020.unk2 = 0;
            CpuFill32(0, &gUnk_03000020, sizeof(gUnk_03000020));
            gUnk_03006CC0 = 0;
        } else {
            gUnk_03006CC0 = 2;
        }
        gUnk_0300002C = sub_08158DBC(gUnk_03006CC0);
        REG_SIODATA32 = gUnk_0300002C;
        goto send;
    case 2:
        if (sub_08158D14(gUnk_03006CC0) != 0) {
            gUnk_03000020.unk2 = 0;
            CpuFill32(0, &gUnk_03000020, sizeof(gUnk_03000020));
            gUnk_03006CC0 = 0;
        } else {
            gUnk_03006CC0 = 3;
        }
        gUnk_0300002C = sub_08158DBC(gUnk_03006CC0);
        REG_SIODATA32 = gUnk_0300002C;
        goto send;
    case 3:
        if (sub_08158D14(gUnk_03006CC0) != 0) {
            gUnk_03000020.unk2 = 0;
            CpuFill32(0, &gUnk_03000020, sizeof(gUnk_03000020));
            gUnk_03006CC0 = 0;
        }
        gUnk_0300002C = sub_08158DBC(gUnk_03006CC0);
        REG_SIODATA32 = gUnk_0300002C;
        goto send;
    case 4:
    case 5:
    default:
        REG_IME = 0;
        REG_IE &= ~INTR_FLAG_SERIAL;
        REG_IME = 1;
        return;
    }

send:
    REG_SIOCNT |= SIO_START;
    REG_TM3CNT_H = 0xC1;
}
#endif

u32 sub_08158D14(u8 kind) {
    u32 top = gUnk_03000030 >> 28;

    if ((u8)sub_08158D80() != 0)
        return 1;

    switch (kind) {
    case 1:
        gUnk_03000034 = ((gUnk_03000030 << 4) >> 8) & kind;
        if (top == 1)
            break;
        return 1;
    case 2:
        if (top != 2)
            return 1;
        if (gUnk_03000034 == (gUnk_03000030 << 4) >> 8)
            break;
        return 1;
    case 3:
        if (top != 3)
            return 1;
        break;
    default:
        return 1;
    }
    return 0;
}

u32 sub_08158D80(void) {
    u32 data = gUnk_03000030 >> 4;
    u32 expected = gUnk_03000030 & 0xF;
    u32 sum;
    u8 i;

    /* barrier: stops gcc folding (gUnk >> 4) >> 24 into gUnk >> 28 */
#ifndef NONMATCHING
    asm("" : "+r"(data));
#endif
    sum = data >> 24;

    for (i = 6; i != 0;) {
        sum ^= (data >> ((i - 1) * 4)) & 0xF;
        i--;
    }

    if (sum == expected) {
        return 0;
    }
    return 1;
}

u32 sub_08158DBC(u8 kind) {
    u32 base;
    u32 ret;
    u8 sum;
    u8 i;

    switch (kind) {
    case 1:
        base = 0x10000010;
        sum = base >> 28;
        for (i = 6; i != 0; i--) {
            sum ^= (base >> (i * 4)) & 0xF;
        }
        ret = (sum & 0xF) | base;
        break;
    case 2:
        base = ((gUnk_03000034 & 0xFFFFFF) << 4) | 0x20000000;
        /* barriers: keep `base` opaque so base >> 28 is not const-folded,
           and keep the u8 truncation of the seed nibble */
#ifndef NONMATCHING
        asm("" : "+r"(base));
#endif
        {
            u32 t = base >> 28;
#ifndef NONMATCHING
            asm("" : "+r"(t));
#endif
            sum = t;
        }
        for (i = 6; i != 0; i--) {
            sum ^= (base >> (i * 4)) & 0xF;
        }
        ret = (sum & 0xF) | base;
        break;
    case 3:
        base = (gUnk_0300607C << 4) | 0x40000000;
        /* barriers: keep `base` opaque so base >> 28 is not const-folded,
           and keep the u8 truncation of the seed nibble */
#ifndef NONMATCHING
        asm("" : "+r"(base));
#endif
        {
            u32 t = base >> 28;
#ifndef NONMATCHING
            asm("" : "+r"(t));
#endif
            sum = t;
        }
        for (i = 6; i != 0; i--) {
            sum ^= (base >> (i * 4)) & 0xF;
        }
        ret = (sum & 0xF) | base;
        break;
    case 4:
    case 5:
        base = 0x10000010;
        sum = base >> 28;
        for (i = 6; i != 0; i--) {
            sum ^= (base >> (i * 4)) & 0xF;
        }
        ret = (sum & 0xF) | base;
        break;
    }
    return ret;
}

void Timer3Intr(void) {
    REG_IME = 0;
    REG_IE &= ~INTR_FLAG_TIMER3;
    REG_IME = 1;
    REG_IME = 0;
    REG_SIOCNT &= ~SIO_START;
    REG_IME = 1;
    REG_TM3CNT_H = 0;
    REG_TM3CNT_L = 0x8000;
    gUnk_03006CC0 = 5;
}

void nullsub_147(void) {}

void nullsub_1(void) {}

void nullsub_2(void) {}

u32 sub_08158F10(void) {
    return 1;
}
