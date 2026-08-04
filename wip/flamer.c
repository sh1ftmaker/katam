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
struct Object4 *sub_080B9DF0(struct Object2 *, u8);
void sub_080BA004(void);
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

extern const struct Unk_08353510 gUnk_083546A4[];
extern const struct Unk_08353510 gUnk_08354710[];
extern const struct Unk_08353510 gUnk_08354734[];
extern const struct Unk_08353510 gUnk_0835477C[];
extern const s8 gUnk_083547E0[];

void sub_080709F8(struct Object4 *, struct Sprite *, u32, u16, u8, u16);
bool32 sub_0806FAC8(struct Object4 *);

u32 sub_080B75D0(struct Object2 *);
u32 sub_080B7E74(struct Object2 *);
u32 sub_080B819C(struct Object2 *);
struct Kirby *sub_0803D368(struct ObjectBase *);
extern void (*const gUnk_083547AC[])(struct Object2 *);

void sub_080B8954(struct Object2 *flamer)
{
    u8 t;

    ObjectSetFunc(flamer, 0, sub_080B89DC);
    flamer->base.flags |= 0x40;
    t = flamer->subtype;
    switch (t)
    {
    case 0:
        flamer->base.xspeed = 0xCD;
        t = 0;
        flamer->unk83 = t;
        break;
    case 1:
        flamer->base.xspeed = 0x140;
        goto set_unk83;
    case 2:
        flamer->base.xspeed = 0x300;
    set_unk83:
        flamer->unk83 = t;
        break;
    }
    if (flamer->base.flags & 1)
        flamer->base.xspeed = -flamer->base.xspeed;
    flamer->base.flags |= 0x140;
    flamer->base.unkC &= ~1;
}

void sub_080B89DC(struct Object2 *flamer)
{
    u32 v;
    u32 collision;
    u32 attr;
    u32 t1;
    u32 t2;
    u32 t3;
    u8 st;
    u8 *facing;
    u8 *sub;
    s32 mag;
    s16 *speed;

    flamer->base.flags |= 4;
    if (flamer->base.x <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.x
        && flamer->base.x >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.x
        && flamer->base.y <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.y
        && flamer->base.y >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.y)
        flamer->unk85 |= 0x20;
    else
        flamer->unk85 &= 0xDF;

    facing = &flamer->unk85;
    v = sub_080B75D0(flamer);
#ifndef NONMATCHING
    asm("" ::: "r0");
#endif
    if (v == 0)
        goto end;

    v &= 1;
    if (v)
    {
        t1 = *facing & 0xC0;
        if (t1 == 0x40)
        {
            *facing = (*facing & 0x3F) | ({ s32 m = -0x40; m; });
            if (!(flamer->base.flags & 1))
                flamer->base.x = (flamer->base.x & 0xFFFFF000) + 0x300;
            else
                flamer->base.x = (flamer->base.x & 0xFFFFF000) + 0xD00;
        }
        else if (t1 == 0)
        {
            *facing = (*facing & 0x3F) | ({ s32 m = -0x80; m; });
            if (flamer->base.flags & 1)
                flamer->base.x = (flamer->base.x & 0xFFFFF000) + 0x300;
            else
                flamer->base.x = (flamer->base.x & 0xFFFFF000) + 0xD00;
        }
        else if (t1 == 0x80)
        {
            *facing = (*facing & 0x3F) | 0x40;
            flamer->base.y = (flamer->base.y & 0xFFFFF000) + 0xB00;
        }
        else if (t1 == 0xC0)
        {
            *facing = *facing & 0x3F;
            flamer->base.y = (flamer->base.y & 0xFFFFF000) + 0x400;
        }

        if (sub_080B75D0(flamer) & 1)
        {
            sub_080B9048(flamer);
            goto end;
        }
    }

    collision = sub_080B7E74(flamer);
    attr = sub_080B819C(flamer) & 0xF0000000;
#ifndef NONMATCHING
    asm("" ::: "r3");
#endif
    if (collision == 0)
        goto end;
    if ((collision & 0xF0000001) || (attr & 0xF0000000))
        goto dispatch;

    t2 = *facing & 0xC0;
    if (t2 == 0x40)
    {
        *facing = (*facing & 0x3F) | ({ s32 m = -0x80; m; });
        if (flamer->base.flags & 1)
            flamer->base.x = ((flamer->base.x + (flamer->base.unk3C - 1) * 0x100) & 0xFFFFF000) + 0x1300;
        else
            flamer->base.x = ((flamer->base.x + (flamer->base.unk3E + 1) * 0x100) & 0xFFFFF000) - 0x300;
    }
    else if (t2 == 0)
    {
        *facing = (*facing & 0x3F) | ({ s32 m = -0x40; m; });
        if (!(flamer->base.flags & 1))
            flamer->base.x = ((flamer->base.x + (flamer->base.unk3C - 1) * 0x100) & 0xFFFFF000) + 0x1300;
        else
            flamer->base.x = ((flamer->base.x + (flamer->base.unk3E + 1) * 0x100) & 0xFFFFF000) - 0x300;
    }
    else if (t2 == 0x80)
    {
        *facing = *facing & 0x3F;
        flamer->base.y = ((flamer->base.y + (flamer->base.unk3D - 1) * 0x100) & 0xFFFFF000) + 0x1300;
    }
    else if (t2 == 0xC0)
    {
        *facing = (*facing & 0x3F) | 0x40;
        flamer->base.y = ((flamer->base.y + (flamer->base.unk3F + 1) * 0x100) & 0xFFFFF000) - 0x300;
    }

dispatch:
    t3 = *facing & 0xC0;
    if (t3 == 0x40)
    {
        st = flamer->subtype;
        sub = &flamer->subtype;
        switch (st)
        {
        case 1: mag = 0x140; break;
        case 2: mag = 0x300; break;
        default: mag = 0xCD; break;
        }
        speed = &flamer->base.xspeed;
        *speed = mag;
        flamer->base.yspeed = 0;
        if (attr == 0)
            goto end;
        switch (attr)
        {
        case 0x30000000:
            switch (*sub)
            {
            case 1: mag = 0xE2; break;
            case 2: mag = 0x21F; break;
            default: mag = 0x90; break;
            }
            break;
        case 0x10000000: case 0x20000000: case 0x50000000: case 0x60000000:
            switch (*sub)
            {
            case 1: mag = 0x127; break;
            case 2: mag = 0x2C4; break;
            default: mag = 0xBC; break;
            }
            break;
        case 0x40000000:
            switch (*sub)
            {
            case 1: mag = 0xE2; break;
            case 2: mag = 0x21F; break;
            default: mag = 0x90; break;
            }
            break;
        default:
            goto callback;
        }
    }
    else if (t3 == 0)
    {
        st = flamer->subtype;
        sub = &flamer->subtype;
        switch (st)
        {
        case 1: mag = 0x140; break;
        case 2: mag = 0x300; break;
        default: mag = 0xCD; break;
        }
        mag = -mag;
        speed = &flamer->base.xspeed;
        *speed = mag;
        flamer->base.yspeed = 0;
        if (attr == 0)
            goto end;
        switch (attr)
        {
        case 0x90000000: case 0xA0000000:
            switch (*sub)
            {
            case 1: mag = 0xE2; break;
            case 2: mag = 0x21F; break;
            default: mag = 0x90; break;
            }
            break;
        case 0x70000000: case 0x80000000: case 0xC0000000:
            switch (*sub)
            {
            case 1: mag = 0x127; break;
            case 2: mag = 0x2C4; break;
            default: mag = 0xBC; break;
            }
            break;
        default:
            goto callback;
        }
        *speed = -mag;
        gUnk_083547AC[attr >> 0x1C](flamer);
        goto post;
    }
    else if (t3 == 0x80)
    {
        flamer->base.xspeed = 0;
        st = flamer->subtype;
        sub = &flamer->subtype;
        switch (st)
        {
        case 1: mag = 0x140; break;
        case 2: mag = 0x300; break;
        default: mag = 0xCD; break;
        }
        speed = &flamer->base.yspeed;
        *speed = mag;
        if (attr == 0)
            goto end;
        switch (attr)
        {
        case 0x30000000: case 0x40000000: case 0x90000000: case 0xA0000000:
            switch (*sub)
            {
            case 1: mag = 0xE2; break;
            case 2: mag = 0x21F; break;
            default: mag = 0x90; break;
            }
            break;
        case 0x10000000: case 0x20000000: case 0x50000000: case 0x60000000:
            switch (*sub)
            {
            case 1: mag = 0x127; break;
            case 2: mag = 0x2C4; break;
            default: mag = 0xBC; break;
            }
            break;
        case 0x70000000: case 0x80000000: case 0xB0000000: case 0xC0000000:
            switch (*sub)
            {
            case 1: mag = 0x117; break;
            case 2: mag = 0x4A; break;
            default: mag = 0x74; break;
            }
            break;
        default:
            goto callback;
        }
    }
    else if (t3 == 0xC0)
    {
        flamer->base.xspeed = 0;
        st = flamer->subtype;
        sub = &flamer->subtype;
        switch (st)
        {
        case 1: mag = 0x140; break;
        case 2: mag = 0x300; break;
        default: mag = 0xCD; break;
        }
        mag = -mag;
        speed = &flamer->base.yspeed;
        *speed = mag;
        if (attr == 0)
            goto end;
        switch (attr)
        {
        case 0x10000000: case 0x60000000: case 0x70000000: case 0xB0000000: case 0xC0000000:
            switch (*sub)
            {
            case 1: mag = 0x117; break;
            case 2: mag = 0x4A; break;
            default: mag = 0x74; break;
            }
            break;
        case 0x30000000: case 0x40000000: case 0x90000000:
            switch (*sub)
            {
            case 1: mag = 0xE2; break;
            case 2: mag = 0x21F; break;
            default: mag = 0x90; break;
            }
            break;
        default:
            goto callback;
        }
        *speed = -mag;
        gUnk_083547AC[attr >> 0x1C](flamer);
        goto post;
    }
    else
    {
        goto end;
    }
    *speed = mag;
callback:
    gUnk_083547AC[attr >> 0x1C](flamer);
post:

    if (flamer->base.flags & 1)
        flamer->base.xspeed = -flamer->base.xspeed;

    if (flamer->object->subtype1 != 0)
        goto end;

    flamer->unk9E++;
    if (flamer->unk9E <= 0x14)
        goto end;

    {
        s32 dx = flamer->kirby3->base.base.base.x - flamer->base.x;
        s32 dy;
        if (dx >= 0)
        {
            if (dx > 0x3FFF)
                goto retarget;
        }
        else if (flamer->base.x - flamer->kirby3->base.base.base.x > 0x3FFF)
        {
            goto retarget;
        }
        dy = flamer->kirby3->base.base.base.y - flamer->base.y;
        if (dy >= 0)
        {
            if (dy > 0x3FFF)
                goto retarget;
        }
        else if (flamer->base.y - flamer->kirby3->base.base.base.y > 0x3FFF)
        {
            goto retarget;
        }
        sub_080BA39C(flamer);
        goto end;
    retarget:
        {
            flamer->kirby3 = sub_0803D368(&flamer->base);
            flamer->unk9E = 0;
        }
    }

end:
    return;
}

void sub_080B9048(struct Object2 *flamer)
{
    ObjectSetFunc(flamer, 3, sub_080BA36C);
    flamer->base.flags &= ~0x140;
    flamer->base.unkC &= ~1;
    flamer->base.xspeed = 0;
    flamer->base.yspeed = 0;

    if (flamer->base.x <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.x
        && flamer->base.x >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.x
        && flamer->base.y <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.y
        && flamer->base.y >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.y)
    {
        if (*CollisionAttributesAt(flamer, 0, flamer->base.unk3F << 8) & 0xFFFFDEFC)
        {
            flamer->unk85 = (flamer->unk85 & 0x3F) | 0x40;
            sub_080B8954(flamer);
            return;
        }
        if (*CollisionAttributesAt(flamer, 0, flamer->base.unk3D << 8) & 0xFFFFDEFC)
        {
            flamer->unk85 &= 0x3F;
            sub_080B8954(flamer);
            return;
        }
        if (*CollisionAttributesAt(flamer, flamer->base.unk3C << 8, 0) & 0xFFFFDEFC)
        {
            if (flamer->base.flags & 1)
                flamer->unk85 = (flamer->unk85 & 0x3F) | ({ s32 m = -0x80; m; });
            else
                flamer->unk85 = (flamer->unk85 & 0x3F) | ({ s32 m = -0x40; m; });
            sub_080B8954(flamer);
            return;
        }
        if (*CollisionAttributesAt(flamer, flamer->base.unk3E << 8, 0) & 0xFFFFDEFC)
        {
            if (flamer->base.flags & 1)
                flamer->unk85 = (flamer->unk85 & 0x3F) | ({ s32 m = -0x40; m; });
            else
                flamer->unk85 = (flamer->unk85 & 0x3F) | ({ s32 m = -0x80; m; });
            sub_080B8954(flamer);
        }
    }
}

void sub_080B937C(struct Object2 *flamer)
{
    if (flamer->unk83 == 5)
        flamer->base.flags |= 4;
    if (flamer->unk9E == 0)
    {
        flamer->unk9F++;
        if (gUnk_083546A4[flamer->unk9F].unk8 == 0)
            flamer->unk9F--;
        flamer->unk9E = gUnk_083546A4[flamer->unk9F].unk8;
        if (gUnk_083546A4[flamer->unk9F].unk9 != 0xFF)
            flamer->unk83 = gUnk_083546A4[flamer->unk9F].unk9;
        if (flamer->unk9F != 0)
        {
            if (gUnk_083546A4[flamer->unk9F].unk0 != gUnk_083546A4[flamer->unk9F - 1].unk0)
            {
                flamer->base.xspeed = gUnk_083546A4[flamer->unk9F].unk0;
                if (flamer->base.flags & 1)
                    flamer->base.xspeed = -flamer->base.xspeed;
            }
            if (gUnk_083546A4[flamer->unk9F].unk2 != gUnk_083546A4[flamer->unk9F - 1].unk2)
                flamer->base.yspeed = gUnk_083546A4[flamer->unk9F].unk2;
        }
        else
        {
            flamer->base.yspeed = gUnk_083546A4[flamer->unk9F].unk2;
            flamer->base.xspeed = gUnk_083546A4[flamer->unk9F].unk0;
            if (flamer->base.flags & 1)
                flamer->base.xspeed = -flamer->base.xspeed;
        }
    }
    if (flamer->base.flags & 1)
        flamer->base.xspeed -= gUnk_083546A4[flamer->unk9F].unk4;
    else
        flamer->base.xspeed += gUnk_083546A4[flamer->unk9F].unk4;
    flamer->base.yspeed += gUnk_083546A4[flamer->unk9F].unk6;
    flamer->unk9E--;
    if (gUnk_083546A4[(u8)(flamer->unk9F + 1)].unk8 == 0 && flamer->unk9E == 0)
        sub_080BA3EC(flamer);
}


void sub_080B94F4(struct Object2 *flamer)
{
    s16 off;

    flamer->base.flags |= 4;
    if (flamer->base.x > flamer->kirby3->base.base.base.x)
        off = 0x4000;
    else
        off = 0xC000;
    if (flamer->base.counter-- <= 0)
    {
        s32 dx = (flamer->kirby3->base.base.base.x + off - flamer->base.x) >> 8;
        s32 dy = (flamer->base.y - flamer->kirby3->base.base.base.y) >> 8;
        u16 dist = Sqrt((dx * dx + dy * dy) * 256);
        s32 vx = dx * 256 / dist;
        s32 vy = dy * 256 / dist;
        u16 v;

        flamer->base.xspeed = vx << 4;
        flamer->base.yspeed = vy << 4;
        switch (flamer->subtype)
        {
        case 1:
            v = 9;
            break;
        case 2:
            v = 6;
            break;
        default:
            v = 12;
            break;
        }
        flamer->base.counter = v;
    }
    if (abs(flamer->kirby3->base.base.base.x + off - flamer->base.x) <= 0x9FF)
    {
        if (abs(flamer->kirby3->base.base.base.y - flamer->base.y) <= 0x9FF)
            sub_080BA400(flamer);
    }
}


void sub_080B95F0(struct Object2 *flamer)
{
    if (flamer->unk9E == 0)
    {
        flamer->unk9F++;
        if (gUnk_08354710[flamer->unk9F].unk8 == 0)
            flamer->unk9F--;
        flamer->unk9E = gUnk_08354710[flamer->unk9F].unk8;
        if (gUnk_08354710[flamer->unk9F].unk9 != 0xFF)
            flamer->unk83 = gUnk_08354710[flamer->unk9F].unk9;
        if (flamer->unk9F != 0)
        {
            if (gUnk_08354710[flamer->unk9F].unk0 != gUnk_08354710[flamer->unk9F - 1].unk0)
            {
                flamer->base.xspeed = gUnk_08354710[flamer->unk9F].unk0;
                if (flamer->base.flags & 1)
                    flamer->base.xspeed = -flamer->base.xspeed;
            }
            if (gUnk_08354710[flamer->unk9F].unk2 != gUnk_08354710[flamer->unk9F - 1].unk2)
                flamer->base.yspeed = gUnk_08354710[flamer->unk9F].unk2;
        }
        else
        {
            flamer->base.yspeed = gUnk_08354710[flamer->unk9F].unk2;
            flamer->base.xspeed = gUnk_08354710[flamer->unk9F].unk0;
            if (flamer->base.flags & 1)
                flamer->base.xspeed = -flamer->base.xspeed;
        }
    }
    if (flamer->base.flags & 1)
        flamer->base.xspeed -= gUnk_08354710[flamer->unk9F].unk4;
    else
        flamer->base.xspeed += gUnk_08354710[flamer->unk9F].unk4;
    flamer->base.yspeed += gUnk_08354710[flamer->unk9F].unk6;
    flamer->unk9E--;
    if (gUnk_08354710[(u8)(flamer->unk9F + 1)].unk8 == 0 && flamer->unk9E == 0)
        sub_080BA450(flamer);
}


void sub_080B976C(struct Object2 *flamer)
{
    s32 c;
    u16 n;

    flamer->base.flags |= 4;
    n = flamer->base.counter;
#ifndef NONMATCHING
    asm("" ::: "memory");
#endif
    c = flamer->base.counter;
    if (c != 0)
    {
        flamer->base.counter = n + 1;
        if ((s16)flamer->base.counter > 0xC)
        {
            if (flamer->unk85 & 0x10)
                sub_080BA4D0(flamer);
            else
                sub_080BA498(flamer);
        }
    }
    else
    {
        flamer->unk9E++;
        if ((flamer->unk9E & 3) == 3)
        {
            sub_080B9DF0(flamer, flamer->unk9E >> 2);
            if (flamer->unk9E & 8)
                flamer->unk9E = c;
        }
        if (flamer->base.flags & 1)
        {
            if (flamer->kirby3->base.base.base.x > flamer->base.x)
                flamer->base.counter++;
        }
        else
        {
            if (flamer->kirby3->base.base.base.x < flamer->base.x)
                flamer->base.counter++;
        }
    }
}

void sub_080B9810(struct Object2 *flamer)
{
    if (flamer->unk9E == 0)
    {
        flamer->unk9F++;
        if (gUnk_08354734[flamer->unk9F].unk8 == 0)
            flamer->unk9F--;
        flamer->unk9E = gUnk_08354734[flamer->unk9F].unk8;
        if (gUnk_08354734[flamer->unk9F].unk9 != 0xFF)
            flamer->unk83 = gUnk_08354734[flamer->unk9F].unk9;
        if (flamer->unk9F != 0)
        {
            if (gUnk_08354734[flamer->unk9F].unk0 != gUnk_08354734[flamer->unk9F - 1].unk0)
            {
                flamer->base.xspeed = gUnk_08354734[flamer->unk9F].unk0;
                if (flamer->base.flags & 1)
                    flamer->base.xspeed = -flamer->base.xspeed;
            }
            if (gUnk_08354734[flamer->unk9F].unk2 != gUnk_08354734[flamer->unk9F - 1].unk2)
                flamer->base.yspeed = gUnk_08354734[flamer->unk9F].unk2;
        }
        else
        {
            flamer->base.yspeed = gUnk_08354734[flamer->unk9F].unk2;
            flamer->base.xspeed = gUnk_08354734[flamer->unk9F].unk0;
            if (flamer->base.flags & 1)
                flamer->base.xspeed = -flamer->base.xspeed;
        }
    }
    if (flamer->base.flags & 1)
        flamer->base.xspeed -= gUnk_08354734[flamer->unk9F].unk4;
    else
        flamer->base.xspeed += gUnk_08354734[flamer->unk9F].unk4;
    flamer->base.yspeed += gUnk_08354734[flamer->unk9F].unk6;
    flamer->unk9E--;
    if (gUnk_08354734[(u8)(flamer->unk9F + 1)].unk8 == 0 && flamer->unk9E == 0)
        sub_080BA4F0(flamer);
}


void sub_080B998C(struct Object2 *flamer)
{
    flamer->base.flags |= 4;
    if (flamer->unk9E == 0)
    {
        flamer->unk9F++;
        if (gUnk_0835477C[flamer->unk9F].unk8 == 0)
            flamer->unk9F--;
        flamer->unk9E = gUnk_0835477C[flamer->unk9F].unk8;
        if (gUnk_0835477C[flamer->unk9F].unk9 != 0xFF)
            flamer->unk83 = gUnk_0835477C[flamer->unk9F].unk9;
        if (flamer->unk9F != 0)
        {
            if (gUnk_0835477C[flamer->unk9F].unk0 != gUnk_0835477C[flamer->unk9F - 1].unk0)
            {
                flamer->base.xspeed = gUnk_0835477C[flamer->unk9F].unk0;
                if (flamer->base.flags & 1)
                    flamer->base.xspeed = -flamer->base.xspeed;
            }
            if (gUnk_0835477C[flamer->unk9F].unk2 != gUnk_0835477C[flamer->unk9F - 1].unk2)
                flamer->base.yspeed = gUnk_0835477C[flamer->unk9F].unk2;
        }
        else
        {
            flamer->base.yspeed = gUnk_0835477C[flamer->unk9F].unk2;
            flamer->base.xspeed = gUnk_0835477C[flamer->unk9F].unk0;
            if (flamer->base.flags & 1)
                flamer->base.xspeed = -flamer->base.xspeed;
        }
    }
    if (flamer->base.flags & 1)
        flamer->base.xspeed -= gUnk_0835477C[flamer->unk9F].unk4;
    else
        flamer->base.xspeed += gUnk_0835477C[flamer->unk9F].unk4;
    flamer->base.yspeed += gUnk_0835477C[flamer->unk9F].unk6;
    flamer->unk9E--;
}

void sub_080B9AF0(struct Object2 *flamer)
{
    s16 dirSign;
    u32 collideFlags;
    s32 x1, y1, x2, y2, x3, y3, x4, y4;

    collideFlags = 1;
    flamer->base.flags |= 4;

    dirSign = flamer->base.x > flamer->kirby3->base.base.base.x ? 0x1000 : -0x1000;

    if (flamer->base.counter-- <= 0)
    {
        s32 dx = (flamer->kirby3->base.base.base.x + dirSign - flamer->base.x) >> 8;
        s32 dy = (flamer->base.y - flamer->kirby3->base.base.base.y) >> 8;
        u16 dist = Sqrt((dx * dx + dy * dy) * 256);
        s32 vx = dx * 256 / dist;
        s32 vy = dy * 256 / dist;

        flamer->base.xspeed = vx << 4;
        flamer->base.yspeed = vy << 4;

        switch (flamer->subtype)
        {
        case 1:
            flamer->base.counter = 9;
            break;
        case 2:
            flamer->base.counter = 6;
            break;
        default:
            flamer->base.counter = 12;
            break;
        }
    }

    x1 = flamer->base.x + (flamer->base.unk3E << 8);
    if (x1 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.x
        && x1 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.x)
    {
        y1 = flamer->base.y + (flamer->base.unk3D << 8);
        if (y1 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.y
            && y1 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.y)
        {
            const u32 *tbl1;
            u8 idx1;

            idx1 = sub_080023E4(flamer->base.unk56,
                ((flamer->base.x >> 8) + flamer->base.unk3E) >> 4,
                ((flamer->base.y >> 8) + flamer->base.unk3D) >> 4);
            tbl1 = gUnk_082D88B8;
            collideFlags |= tbl1[idx1];
        }
    }

    x2 = flamer->base.x + (flamer->base.unk3C << 8);
    if (x2 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.x
        && x2 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.x)
    {
        y2 = flamer->base.y + (flamer->base.unk3D << 8);
        if (y2 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.y
            && y2 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.y)
        {
            const u32 *tbl2;
            u8 idx2;

            idx2 = sub_080023E4(flamer->base.unk56,
                ((flamer->base.x >> 8) + flamer->base.unk3C) >> 4,
                ((flamer->base.y >> 8) + flamer->base.unk3D) >> 4);
            tbl2 = gUnk_082D88B8;
            collideFlags |= tbl2[idx2];
        }
    }

    x3 = flamer->base.x + (flamer->base.unk3E << 8);
    if (x3 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.x
        && x3 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.x)
    {
        y3 = flamer->base.y + (flamer->base.unk3F << 8);
        if (y3 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.y
            && y3 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.y)
        {
            const u32 *tbl3;
            u8 idx3;

            idx3 = sub_080023E4(flamer->base.unk56,
                ((flamer->base.x >> 8) + flamer->base.unk3E) >> 4,
                ((flamer->base.y >> 8) + flamer->base.unk3F) >> 4);
            tbl3 = gUnk_082D88B8;
            collideFlags |= tbl3[idx3];
        }
    }

    x4 = flamer->base.x + (flamer->base.unk3C << 8);
    if (x4 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.x
        && x4 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.x)
    {
        y4 = flamer->base.y + (flamer->base.unk3F << 8);
        if (y4 <= gCurLevelInfo[flamer->base.unk56].levelMaxPosition.y
            && y4 >= gCurLevelInfo[flamer->base.unk56].levelMinPosition.y)
        {
            const u32 *tbl4;
            u8 idx4;

            idx4 = sub_080023E4(flamer->base.unk56,
                ((flamer->base.x >> 8) + flamer->base.unk3C) >> 4,
                ((flamer->base.y >> 8) + flamer->base.unk3F) >> 4);
            tbl4 = gUnk_082D88B8;
            collideFlags |= tbl4[idx4];
        }
    }

    if (collideFlags == 1)
    {
        if (flamer->unk9E)
        {
            flamer->base.xspeed = 0;
            flamer->base.yspeed = 0;
            flamer->unk9E--;
        }
        sub_080BA54C(flamer);
    }
}

struct Object4 *sub_080B9DF0(struct Object2 *flamer, u8 dirIndex)
{
    struct Task *t = TaskCreate(sub_080BA004, sizeof(struct Object4), 0x3500, TASK_USE_IWRAM, sub_0803DCCC);
    struct Object4 *tmp = TaskGetStructPtr(t), *newObj = tmp;
    u16 gfxId;
    u16 param;
    u8 dy;
    u32 z;

    sub_0803E3B0(tmp);
    newObj->unk0 = 3;
    newObj->x = flamer->base.x;
    newObj->y = flamer->base.y;
    newObj->parent = flamer;
    newObj->roomId = flamer->base.roomId;
    z = 0;
    dy = ((const u8 *)gUnk_083547E0)[dirIndex & 3];
    newObj->y += (s8)dy << 8;
    if (Macro_0810B1F4(&flamer->base))
        newObj->flags |= 0x2000;
    newObj->flags |= 0x4000;
    sub_080709F8(newObj, &newObj->sprite, 6, gfxId = 0x31E, 12, 12);
    newObj->sprite.palId = (u8)z;
    if (flamer->base.unkC & 0x10)
    {
        if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == newObj->roomId)
        {
            param = gUnk_08351648[OBJ_DROPPY].unk8;
            newObj->sprite.palId = sub_0803DF24(param);
            if (newObj->sprite.palId == 0xFF)
                newObj->sprite.palId = sub_0803DFAC(param, 0);
        }
        else
            newObj->sprite.palId = (u8)z;
    }
    else
    {
        if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == newObj->roomId)
        {
            newObj->sprite.palId = sub_0803DF24(gfxId);
            if (newObj->sprite.palId == 0xFF)
                newObj->sprite.palId = sub_0803DFAC(gfxId, 0);
        }
        else
            newObj->sprite.palId = (u8)z;
    }
    PlaySfx(&flamer->base, SE_BASIC_ENEMY_FIRE_ATTACK);
    return newObj;
}


void sub_080BA004(void)
{
    void *tmp = TaskGetStructPtr(gCurTask);
    struct Object4 *obj = tmp;
    struct Object2 *kirbyObj = obj->parent;
    struct Sprite sprite;

    if (obj->flags & 0x1000)
    {
        TaskDestroy(gCurTask);
        return;
    }

    Macro_08107BA8_4(obj, &obj->sprite, &sprite, 6, &obj->sprite);

    if (kirbyObj->base.unkC & 0x10)
        Macro_081050E8(obj, &obj->sprite, gUnk_08351648[OBJ_DROPPY].unk8, obj->sprite.palId == 0);
    else
        Macro_081050E8(obj, &obj->sprite, 0x31E, obj->sprite.palId == 0);

    {
        struct Object2 *parent = obj->parent;

        if (parent && parent->base.unk0 && (parent->base.flags & 0x1000))
        {
            obj->parent = NULL;
            parent = NULL;
        }
        if (parent)
        {
            if (Macro_0810B1F4(&parent->base) && !(obj->flags & 0x2000))
            {
                sub_0803DBC8(obj);
                return;
            }
        }
        else
        {
            KirbySomething(obj);
        }
    }

    Macro_0809E55C(obj);

    if (obj->flags & 2)
    {
        obj->flags |= 0x1000;
        return;
    }

    if (!(obj->flags & 0x800))
    {
        s32 newX = obj->x + obj->unk3C;
        s32 newY = obj->y - obj->unk3E;

        asm("" ::: "memory");
        obj->x = newX + obj->unk3C;
        obj->y = newY - obj->unk3E;
    }

    sub_0806FAC8(obj);
}


// sub_080BA334: functionally equivalent; remaining diff is ONE branch mnemonic in the
// switch decision tree (ref `ble` = signed LE vs ours `bcc` = unsigned LT); see flamer.md.
#ifndef NONMATCHING
NAKED void sub_080BA334(struct Object2 *flamer)
{
    asm(".include \"asm/nonmatching/sub_080BA334.inc\"");
}
#else
void sub_080BA334(struct Object2 *flamer)
{
    flamer->base.unk68 &= ~0x100;
    switch ((u32)flamer->object->subtype1)
    {
        case 0:
            sub_080BA4F0(flamer);
            break;
        case 1:
            sub_080BA4F0(flamer);
            break;
        case 2:
            sub_080BA5A4(flamer);
            break;
        default:
            sub_080BA4F0(flamer);
            break;
    }
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

void sub_080BA5C8(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r2") = flamer->base.unk3E * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r3") = flamer->base.y;
        register s32 m asm("r1");
        register s32 xm asm("r0");
#else
        s32 off = flamer->base.unk3E * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
#endif
        x &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        xm = x + m;
        y &= m;
        flamer->base.x = xm - y - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3F * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r3") = y0 + off;
        register s32 m asm("r1");
        register s32 ym asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 ym;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        ym = y + m;
        x &= m;
        flamer->base.y = ym - x - off;
    }
}


void sub_080BA638(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r1") = flamer->base.unk3C * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r3") = x0 + off;
        register s32 y asm("r2") = flamer->base.y;
        register s32 m asm("r0");
        register s32 xm asm("r0");
#else
        s32 off = flamer->base.unk3C * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
#endif
        x &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        y &= m;
        xm = x + y;
        flamer->base.x = xm - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r3") = flamer->base.x;
        register s32 off asm("r1") = flamer->base.unk3F * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r2") = y0 + off;
        register s32 m asm("r0");
        register s32 ym asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 ym;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        ym = y + x;
        flamer->base.y = ym - off;
    }
}


void sub_080BA6A4(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r2") = flamer->base.unk3C * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r3") = flamer->base.y;
        register s32 m asm("r1");
        register s32 xm asm("r0");
#else
        s32 off = flamer->base.unk3C * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
#endif
        x &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        xm = x + m;
        y &= m;
        flamer->base.x = xm - y - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3D * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r3") = y0 + off;
        register s32 m asm("r1");
        register s32 ym asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 ym;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        ym = y + m;
        x &= m;
        flamer->base.y = ym - x - off;
    }
}


void sub_080BA714(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r1") = flamer->base.unk3E * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r3") = x0 + off;
        register s32 y asm("r2") = flamer->base.y;
        register s32 m asm("r0");
        register s32 xm asm("r0");
#else
        s32 off = flamer->base.unk3E * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
#endif
        x &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        y &= m;
        xm = x + y;
        flamer->base.x = xm - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r3") = flamer->base.x;
        register s32 off asm("r1") = flamer->base.unk3D * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r2") = y0 + off;
        register s32 m asm("r0");
        register s32 ym asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 ym;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        ym = y + x;
        flamer->base.y = ym - off;
    }
}


void sub_080BA780(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r2") = flamer->base.unk3E * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r3") = flamer->base.y;
        register s32 m asm("r0");
        register s32 xm asm("r1");
        register s32 ys asm("r0");
#else
        s32 off = flamer->base.unk3E * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
        s32 ys;
#endif
        x &= ~0xFFF;
        m = 0xFFF;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        xm = x + m;
        y &= m;
        ys = y - 0x800;
        ys <<= 1;
        xm -= ys;
        xm -= off;
        flamer->base.x = xm;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3F * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r3") = y0 + off;
        register s32 m asm("r1");
        register s32 xs asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        xs = m - xs;
        xs &= m;
        flamer->base.y = y + xs - off;
    }
}


void sub_080BA800(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r2") = flamer->base.unk3E * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r5") = flamer->base.y;
        register s32 m asm("r1");
        register s32 xm asm("r0");
        register s32 ys asm("r1");
#else
        s32 off = flamer->base.unk3E * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
        s32 ys;
#endif
        x &= ~0xFFF;
        m = 0xFFF;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        xm = x + m;
        y &= m;
        ys = y << 1;
        flamer->base.x = xm - ys - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3F * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r5") = y0 + off;
        register s32 m asm("r3");
        register s32 xs asm("r1");
        register s32 xr asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
        s32 xr;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        xr = 0x7FF - xs;
        xr &= m;
        flamer->base.y = y + xr - off;
    }
}


void sub_080BA880(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r1") = flamer->base.unk3C * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r5") = x0 + off;
        register s32 y asm("r4") = flamer->base.y;
        register s32 ys asm("r0");
#else
        s32 off = flamer->base.unk3C * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 ys;
#endif
        x &= ~0xFFF;
        y &= 0xFFF;
        ys = y - 0x800;
        ys <<= 1;
        flamer->base.x = x + ys - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r5") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3F * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r4") = y0 + off;
        register s32 m asm("r3");
        register s32 xs asm("r0");
        register s32 b asm("r1");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
        s32 b;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        b = 0x800;
        xs |= b;
        xs &= m;
        flamer->base.y = y + xs - off;
    }
}


void sub_080BA908(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r1") = flamer->base.unk3C * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r3") = flamer->base.y;
        register s32 ys asm("r0");
#else
        s32 off = flamer->base.unk3C * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 ys;
#endif
        x &= ~0xFFF;
        y &= 0xFFF;
        ys = y << 1;
        flamer->base.x = x + ys - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3F * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r3") = y0 + off;
        register s32 m asm("r1");
        register s32 xs asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3F * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        xs &= m;
        flamer->base.y = y + xs - off;
    }
}


void sub_080BA97C(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r1") = flamer->base.unk3E * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r3") = flamer->base.y;
        register s32 ys asm("r0");
#else
        s32 off = flamer->base.unk3E * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 ys;
#endif
        x &= ~0xFFF;
        y &= 0xFFF;
        ys = y << 1;
        flamer->base.x = x + ys - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3D * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r3") = y0 + off;
        register s32 m asm("r1");
        register s32 xs asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        xs &= m;
        flamer->base.y = y + xs - off;
    }
}


void sub_080BA9F0(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r1") = flamer->base.unk3E * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r5") = x0 + off;
        register s32 y asm("r4") = flamer->base.y;
        register s32 ys asm("r0");
#else
        s32 off = flamer->base.unk3E * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 ys;
#endif
        x &= ~0xFFF;
        y &= 0xFFF;
        ys = y - 0x800;
        ys <<= 1;
        flamer->base.x = x + ys - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r5") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3D * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r4") = y0 + off;
        register s32 m asm("r3");
        register s32 xs asm("r0");
        register s32 b asm("r1");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
        s32 b;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        b = 0x800;
        xs |= b;
        xs &= m;
        flamer->base.y = y + xs - off;
    }
}


void sub_080BAA78(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r2") = flamer->base.unk3C * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r5") = flamer->base.y;
        register s32 m asm("r1");
        register s32 xm asm("r0");
        register s32 ys asm("r1");
#else
        s32 off = flamer->base.unk3C * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
        s32 ys;
#endif
        x &= ~0xFFF;
        m = 0xFFF;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        xm = x + m;
        y &= m;
        ys = y << 1;
        flamer->base.x = xm - ys - off;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3D * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r5") = y0 + off;
        register s32 m asm("r3");
        register s32 xs asm("r1");
        register s32 xr asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
        s32 xr;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        xr = 0x7FF - xs;
        xr &= m;
        flamer->base.y = y + xr - off;
    }
}


void sub_080BAAF8(struct Object2 *flamer)
{
    u32 t = flamer->unk85 & 0xC0;

    if (t == 0x80 || t == 0xC0)
    {
#ifndef NONMATCHING
        register s32 off asm("r2") = flamer->base.unk3C * 0x100;
        register s32 x0 asm("r0") = flamer->base.x;
        register s32 x asm("r4") = x0 + off;
        register s32 y asm("r3") = flamer->base.y;
        register s32 m asm("r0");
        register s32 xm asm("r1");
        register s32 ys asm("r0");
#else
        s32 off = flamer->base.unk3C * 0x100;
        s32 x0 = flamer->base.x;
        s32 x = x0 + off;
        s32 y = flamer->base.y;
        s32 m;
        s32 xm;
        s32 ys;
#endif
        x &= ~0xFFF;
        m = 0xFFF;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        xm = x + m;
        y &= m;
        ys = y - 0x800;
        ys <<= 1;
        xm -= ys;
        xm -= off;
        flamer->base.x = xm;
    }
    else
    {
#ifndef NONMATCHING
        register s32 x asm("r4") = flamer->base.x;
        register s32 off asm("r2") = flamer->base.unk3D * 0x100;
        register s32 y0 asm("r0") = flamer->base.y;
        register s32 y asm("r3") = y0 + off;
        register s32 m asm("r1");
        register s32 xs asm("r0");
#else
        s32 x = flamer->base.x;
        s32 off = flamer->base.unk3D * 0x100;
        s32 y0 = flamer->base.y;
        s32 y = y0 + off;
        s32 m;
        s32 xs;
#endif
        y &= ~0xF00;
        m = 0xF00;
#ifndef NONMATCHING
        asm("" : "+r"(m));
#endif
        x &= m;
        xs = x >> 1;
        xs = m - xs;
        xs &= m;
        flamer->base.y = y + xs - off;
    }
}


