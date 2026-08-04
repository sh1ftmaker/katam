#include "flamer.h"
#include "functions.h"
#include "random.h"
#include "kirby.h"
#include "object.h"

void sub_080B8954(struct Object2 *);
void sub_080B89DC(struct Object2 *);
void sub_080B9048(struct Object2 *);
void sub_080B937C(struct Object2 *);
void sub_080B94F4(struct Object2 *);
void sub_080B95F0(struct Object2 *);
void sub_080B976C(struct Object2 *);
void sub_080B9810(struct Object2 *);
void sub_080B998C(struct Object2 *);
void sub_080B9AF0(struct Object2 *);
void sub_080B9DF0(struct Object2 *);
void sub_080BA004(struct Object2 *);
void sub_080BA334(struct Object2 *);
void sub_080BA36C(struct Object2 *);
void sub_080BA39C(struct Object2 *);
void sub_080BA3EC(struct Object2 *);
void sub_080BA400(struct Object2 *);
void sub_080BA450(struct Object2 *);
void sub_080BA498(struct Object2 *);
void sub_080BA4D0(struct Object2 *);
void sub_080BA4F0(struct Object2 *);
void sub_080BA54C(struct Object2 *);
void sub_080BA58C(struct Object2 *);
void sub_080BA5A4(struct Object2 *);
void sub_080BA5B8(struct Object2 *);
void nullsub_125(struct Object2 *);
void sub_080BA5C8(struct Object2 *);
void sub_080BA638(struct Object2 *);
void sub_080BA6A4(struct Object2 *);
void sub_080BA714(struct Object2 *);
void sub_080BA780(struct Object2 *);
void sub_080BA800(struct Object2 *);
void sub_080BA880(struct Object2 *);
void sub_080BA908(struct Object2 *);
void sub_080BA97C(struct Object2 *);
void sub_080BA9F0(struct Object2 *);
void sub_080BAA78(struct Object2 *);
void sub_080BAAF8(struct Object2 *);

// sub_080BA334: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA334(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA334.inc\"");
}
#else
void sub_080BA334(struct Object2 *flamer)
{
    flamer->base.unk68 &= ~0x100;
    if (flamer->object->subtype1 == 1 || flamer->object->subtype1 <= 1)
        sub_080BA4F0(flamer);
    else if (flamer->object->subtype1 == 2)
        sub_080BA5A4(flamer);
    else
        sub_080BA4F0(flamer);
}
#endif


void sub_080BA36C(struct Object2 *flamer)
{
    flamer->base.flags |= 4;
    if (flamer->base.unk62)
    {
        flamer->unk85 = (flamer->unk85 & 0x3F) | 0x40;
        sub_080B8954(flamer);
    }
}

void sub_080BA39C(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 4, sub_080B937C);
    flamer->base.xspeed = 0;
    flamer->base.yspeed = 0;
    flamer->base.flags |= 0x140;
    flamer->base.unkC |= 1;
    if (flamer->base.x > flamer->kirby3->base.base.base.x)
        flamer->base.flags |= 1;
    else
        flamer->base.flags &= ~1;
}

void sub_080BA3EC(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 6, sub_080B94F4);
}

void sub_080BA400(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 7, sub_080B95F0);
    flamer->base.xspeed = 0;
    flamer->base.yspeed = 0;
    flamer->base.flags |= 0x140;
    flamer->base.unkC |= 1;
    if (flamer->base.x > flamer->kirby3->base.base.base.x)
        flamer->base.flags |= 1;
    else
        flamer->base.flags &= ~1;
}

void sub_080BA450(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 8, sub_080B976C);
    flamer->base.xspeed = 0x400;
    flamer->base.yspeed = 0;
    flamer->base.unk68 |= 0x100;
    flamer->base.flags |= 0x140;
    if (flamer->base.flags & 1)
        flamer->base.xspeed = -flamer->base.xspeed;
}

void sub_080BA498(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 9, sub_080B9810);
    flamer->unk85 |= 0x10;
    flamer->base.unk68 &= ~0x100;
    flamer->base.flags |= 0x140;
}

void sub_080BA4D0(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 9, sub_080B998C);
    flamer->base.flags |= 0x140;
}

void sub_080BA4F0(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 6, sub_080B9AF0);
    flamer->base.xspeed = 0;
    flamer->base.yspeed = 0;
    flamer->unk9E = 4;
    if (flamer->base.x > flamer->kirby3->base.base.base.x)
        flamer->base.flags |= 1;
    else
        flamer->base.flags &= ~1;
    flamer->base.flags |= 0x140;
    flamer->base.flags &= ~0x20;
}

void sub_080BA54C(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 0xA, sub_080BA58C);
    flamer->base.xspeed = 0;
    flamer->base.yspeed = 0;
    if (flamer->base.x > flamer->kirby3->base.base.base.x)
        flamer->base.flags |= 1;
    else
        flamer->base.flags &= ~1;
}

void sub_080BA58C(struct Object2 *flamer)
{
    if (flamer->base.flags & 2)
        sub_080B9048(flamer);
}

void sub_080BA5A4(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 0, sub_080BA5B8);
}

void sub_080BA5B8(struct Object2 *flamer)
{
    flamer->base.flags |= 4;
}

void nullsub_125(struct Object2 *flamer)
{
}

// sub_080BA5C8: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA5C8(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA5C8.inc\"");
}
#else
void sub_080BA5C8(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3E * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm = x & ~0xF00;
        m = 0xF00;
        xm += m;
        y &= m;
        flamer->base.x = xm - y - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y = flamer->base.y + off;
        s32 m;
        s32 ym = y & ~0xF00;
        m = 0xF00;
        ym += m;
        x &= m;
        flamer->base.y = ym - x - off;
    }
}
#endif


// sub_080BA638: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA638(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA638.inc\"");
}
#else
void sub_080BA638(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3C * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xF00;
        y &= 0xF00;
        flamer->base.x = x + y - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + x - off;
    }
}
#endif


// sub_080BA6A4: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA6A4(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA6A4.inc\"");
}
#else
void sub_080BA6A4(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3C * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xF00;
        y &= 0xF00;
        flamer->base.x = x + 0xF00 - y - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + 0xF00 - x - off;
    }
}
#endif


// sub_080BA714: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA714(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA714.inc\"");
}
#else
void sub_080BA714(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3E * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xF00;
        y &= 0xF00;
        flamer->base.x = x + y - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + x - off;
    }
}
#endif


// sub_080BA780: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA780(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA780.inc\"");
}
#else
void sub_080BA780(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3E * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + 0xFFF - ((y - 0x800) << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + ((0xF00 - (x >> 1)) & 0xF00) - off;
    }
}
#endif


// sub_080BA800: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA800(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA800.inc\"");
}
#else
void sub_080BA800(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3E * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + 0xFFF - (y << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + ((0x7FF - (x >> 1)) & 0xF00) - off;
    }
}
#endif


// sub_080BA880: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA880(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA880.inc\"");
}
#else
void sub_080BA880(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3C * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + ((y - 0x800) << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + (((x >> 1) | 0x800) & 0xF00) - off;
    }
}
#endif


// sub_080BA908: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA908(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA908.inc\"");
}
#else
void sub_080BA908(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3C * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + (y << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + ((x >> 1) & 0xF00) - off;
    }
}
#endif


// sub_080BA97C: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA97C(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA97C.inc\"");
}
#else
void sub_080BA97C(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3E * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + (y << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + ((x >> 1) & 0xF00) - off;
    }
}
#endif


// sub_080BA9F0: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BA9F0(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA9F0.inc\"");
}
#else
void sub_080BA9F0(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3E * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + ((y - 0x800) << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + (((x >> 1) | 0x800) & 0xF00) - off;
    }
}
#endif


// sub_080BAA78: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BAA78(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BAA78.inc\"");
}
#else
void sub_080BAA78(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3C * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + 0xFFF - (y << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + ((0x7FF - (x >> 1)) & 0xF00) - off;
    }
}
#endif


// sub_080BAAF8: functionally equivalent; remaining diff is register allocation / constant scheduling.
#ifndef NONMATCHING
NAKED void sub_080BAAF8(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BAAF8.inc\"");
}
#else
void sub_080BAAF8(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
        s32 off = flamer->base.unk3C * 0x100;
        s32 x = flamer->base.x + off;
        s32 y = flamer->base.y;
        x &= ~0xFFF;
        y &= 0xFFF;
        flamer->base.x = x + 0xFFF - ((y - 0x800) << 1) - off;
    }
    else
    {
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y = flamer->base.y + off;
        y &= ~0xF00;
        x &= 0xF00;
        flamer->base.y = y + ((0xF00 - (x >> 1)) & 0xF00) - off;
    }
}
#endif


