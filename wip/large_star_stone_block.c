#include "global.h"
#include "data.h"
#include "kirby.h"
#include "functions.h"
#include "object.h"
#include "code_0806F780.h"
#include "malloc_ewram.h"

struct LargeStarStoneBlock
{
    struct Object2 obj2;
    u8 fillerB4[0x2D];
    u8 unkE1;
    u8 unkE2;
    u8 unkE3;
    u8 unkE4;
    u8 unkE5;
    u8 unkE6;
    u8 unkE7;
    s32 unkE8;
}; /* size = 0xEC */

struct Unknown82
{
    struct Object2 obj2;
    s16 unkB4;
    u16 unkB6;
    u16 unkB8;
    s16 unkBA;
}; /* size = 0xBC */

// defined in star_stone_block.c
extern void sub_0811EC80(struct LargeStarStoneBlock *);

void sub_08120438(struct LargeStarStoneBlock *);
void sub_081205CC(u8, u8, u8);
void sub_08120608(struct Task *);
void sub_08120670(struct Object2 *);
void sub_08120788(struct Object2 *);
void sub_081209D8(struct Task *);
void sub_08120A40(struct Unknown82 *);
void sub_08120B90(struct Unknown82 *);
void sub_08120D78(struct Task *);
u8 sub_08120DE0(struct Unknown82 *);
void sub_08120E1C(struct Unknown82 *);
void sub_08120EE0(struct Unknown82 *);
void sub_08121080(struct Unknown82 *);
void sub_08121194(struct LargeStarStoneBlock *);
void sub_08121324(struct LargeStarStoneBlock *);
void sub_081214B8(u8, u8, u8);
void sub_081214F4(struct Task *);
void sub_08121654(struct LargeStarStoneBlock *);
void sub_081217E4(struct LargeStarStoneBlock *);
void sub_08121978(u8, u8, u8);
void sub_081219B4(struct Task *);

void *CreateLargeStarStoneBlock7E(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct LargeStarStoneBlock), 0x1000, TASK_USE_IWRAM, sub_08120608);
    struct LargeStarStoneBlock *tmp = TaskGetStructPtr(t), *block = tmp;

    InitObject(&tmp->obj2, template, a2);
    block->obj2.base.flags |= 0x82408040;
    block->obj2.base.unk68 &= ~7;
    block->obj2.base.unk5C &= ~7;
    block->obj2.base.unk5C |= 4;
    block->obj2.base.unk68 |= 0x800;
    block->obj2.base.unkC |= 1;
    if (block->obj2.object->unk22 & 1)
    {
        block->unkE1 = 5;
        block->obj2.unk83 = 1;
    }
    else
    {
        block->unkE1 = 4;
        block->obj2.unk83 = 0;
    }
    sub_0803E308(&block->obj2.base, -0x10, -0x10, 0x10, 0x10);
    sub_0803E2B0(&block->obj2.base, -0x10, -0x10, 0x10, 0x10);
    ObjectInitSprite(&block->obj2);
    gUnk_08351648[block->obj2.type].unk10(&block->obj2);
    return block;
}

void sub_081202A0(struct LargeStarStoneBlock *block)
{
    struct LargeStarStoneBlock *block2 = block;
    s32 targetX;
    s32 x12;

    sub_0811EC80(block);
    targetX = (s32)block->obj2.object->x << 8;
    x12 = block->obj2.base.x >> 0xc;
    if (block->unkE8 >= x12)
    {
        s32 y12;
        u8 unk56;

        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x200;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x200;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        unk56 = block->obj2.base.unk56;
        y12 = block->obj2.base.y >> 0xc;
        sub_081205CC(unk56, x12, y12 - 1);
        sub_081205CC(unk56, x12 + 1, y12 - 1);
        sub_081205CC(unk56, x12, y12);
        sub_081205CC(unk56, x12 + 1, y12);
        sub_081205CC(unk56, x12, y12 + 1);
        sub_081205CC(unk56, x12 + 1, y12 + 1);
        block2->unkE8 = (block->obj2.base.y >> 0xc) + 5;
        block2->unkE7 = (block->obj2.base.y >> 0xc) + 2;
        block->obj2.base.flags = (block->obj2.base.flags & ~0x40) | 0x100;
        block->obj2.unk78 = sub_08120438;
    }
    else if (targetX < block->obj2.base.x)
    {
        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x200;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x200;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        block->obj2.base.x = targetX;
    }
    block->obj2.base.counter++;
}

void sub_08120438(struct LargeStarStoneBlock *block)
{
    struct LargeStarStoneBlock *block2 = block;
    s32 y12 = block2->obj2.base.y >> 0xc;
    u8 f;
    u8 *e4;

    if (block2->unkE8 >= y12 && block2->unkE7 == y12)
    {
        u8 unk56 = block2->obj2.base.unk56;
        u8 x12 = block2->obj2.base.x >> 0xc;
        u8 y12b = block2->unkE7;

        sub_080023E4(unk56, x12, y12b);
        sub_08001408(unk56, sub_080025AC(unk56, x12, y12b), 0, 0);
        unk56 = block2->obj2.base.unk56;
        x12 = (block2->obj2.base.x >> 0xc) + 1;
        y12b = block2->obj2.base.y >> 0xc;
        sub_080023E4(unk56, x12, y12b);
        sub_08001408(unk56, sub_080025AC(unk56, x12, y12b), 0, 0);
        block2->unkE7++;
    }
    e4 = &block->unkE4;
    f = *e4;
    if (f & 1)
        f |= 4;
    else
        f &= 0xFB;
    *e4 = f;
    if ((block->obj2.base.y >> 8) > 0x50)
    {
        block->obj2.base.sprite.unk8 = (block->obj2.base.sprite.unk8 & ~0x3000) | 0x3000;
        f = *e4;
        f |= 1;
        *e4 = f;
    }
    f = *e4;
    if (!(f & 4) && (f & 1))
        f |= 2;
    else
        f &= 0xFD;
    *e4 = f;
    if (*e4 & 2)
    {
        sub_08089864(&block->obj2.base, -0x10, 5, 0);
        sub_08089864(&block->obj2.base, -0x10, 5, 1);
    }
    if ((block->obj2.base.y >> 8) >= gCurLevelInfo[block->obj2.base.unk56].roomHeight + 0x10)
        block->obj2.base.flags |= 0x1000;
    block->obj2.base.counter++;
}

void sub_08120594(struct LargeStarStoneBlock *block)
{
    block->obj2.base.counter = 0;
    block->unkE2 = 0;
    block->unkE3 = 0;
    block->unkE6 = 0;
    block->unkE7 = 0;
    block->unkE8 = (block->obj2.base.x >> 0xc) - 3;
    block->unkE4 = 0;
    block->obj2.unk78 = sub_081202A0;
}

void sub_081205CC(u8 unk56, u8 x, u8 y)
{
    sub_080023E4(unk56, x, y);
    sub_08001408(unk56, sub_080025AC(unk56, x, y), 0, 0);
}

void sub_08120608(struct Task *t)
{
    struct Object2 *obj2 = TaskGetStructPtr(t);
    u8 unk56 = obj2->base.unk56;
    struct Object *object = obj2->object;
    u32 x = object->unk2;
    u8 y = object->unk3;
    u8 z = gCurLevelInfo[unk56].unk65E;

    ObjectDestroy(t);
    if (x != 0 || unk56 != 0xFF)
        sub_08001678(x, y, z, 1);
}

// sub_08120670: not yet reverse engineered (gKirbys/linked-object scan); the
// #else body below is an unverified placeholder — do not trust it as correct.
#ifndef NONMATCHING
NAKED void sub_08120670(struct Object2 *block)
{
    asm(".include \"asm/nonmatching/sub_08120670.inc\"");
}
#else
void sub_08120670(struct Object2 *block)
{
    block->base.counter++;
}
#endif

// sub_08120788: not yet reverse engineered (gKirbys array scan against
// gUnk_0203AD44 count); the #else body below is an unverified placeholder.
#ifndef NONMATCHING
NAKED void sub_08120788(struct Object2 *block)
{
    asm(".include \"asm/nonmatching/sub_08120788.inc\"");
}
#else
void sub_08120788(struct Object2 *block)
{
    block->base.counter++;
}
#endif

void *CreateCPUKirbyTrigger(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct Object2), 0x1001, TASK_USE_IWRAM, sub_081209D8);
    struct Object2 *tmp = TaskGetStructPtr(t), *obj2 = tmp;

    InitObject(tmp, template, a2);
    obj2->base.flags |= 0x02018F40;
    obj2->base.unk5C |= 0x20;
    obj2->base.unkC |= 1;
    gUnk_08351648[obj2->type].unk10(obj2);
    return obj2;
}

void sub_0812098C(struct Object2 *obj2)
{
    obj2->base.counter = 0;
    obj2->base.x -= 0x800;
    obj2->base.y -= 0x800;
    obj2->base.unk48 = obj2->base.x;
    obj2->base.unk4C = obj2->base.y;
    if (!(obj2->object->unk22 & 1) && (obj2->object->unk22 & 6))
        obj2->unk78 = sub_08120788;
    else
        obj2->unk78 = sub_08120670;
}

void sub_081209D8(struct Task *t)
{
    struct Object2 *obj2 = TaskGetStructPtr(t);
    u8 unk56 = obj2->base.unk56;
    struct Object *object = obj2->object;
    u32 x = object->unk2;
    u8 y = object->unk3;
    u8 z = gCurLevelInfo[unk56].unk65E;

    ObjectDestroy(t);
    if (x != 0 || unk56 != 0xFF)
        sub_08001678(x, y, z, 1);
}

// sub_08120A40: not yet reverse engineered (EwramMalloc'd array builder using
// gUnk_08357D20/gUnk_08357D30 tables); the #else body below is an unverified
// placeholder — do not trust it as correct.
#ifndef NONMATCHING
NAKED void sub_08120A40(struct Unknown82 *x)
{
    asm(".include \"asm/nonmatching/sub_08120A40.inc\"");
}
#else
void sub_08120A40(struct Unknown82 *x)
{
    x->obj2.unk78 = sub_08120B90;
}
#endif

// sub_08120B90: not yet reverse engineered (consumer of sub_08120A40's ewram
// array); the #else body below is an unverified placeholder.
#ifndef NONMATCHING
NAKED void sub_08120B90(struct Unknown82 *x)
{
    asm(".include \"asm/nonmatching/sub_08120B90.inc\"");
}
#else
void sub_08120B90(struct Unknown82 *x)
{
    x->obj2.base.counter++;
}
#endif

void *CreateUnknown82(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct Unknown82), 0x1000, TASK_USE_IWRAM, sub_08120D78);
    struct Unknown82 *tmp = TaskGetStructPtr(t), *x = tmp;

    InitObject(&tmp->obj2, template, a2);
    x->obj2.base.flags |= 0x02018F40;
    x->obj2.base.unk5C |= 0x20;
    x->obj2.base.unkC |= 1;
    gUnk_08351648[x->obj2.type].unk10(&x->obj2);
    return x;
}

void sub_08120D78(struct Task *t)
{
    struct Object2 *obj2 = TaskGetStructPtr(t);
    u8 unk56 = obj2->base.unk56;
    struct Object *object = obj2->object;
    u32 x = object->unk2;
    u8 y = object->unk3;
    u8 z = gCurLevelInfo[unk56].unk65E;

    ObjectDestroy(t);
    if (x != 0 || unk56 != 0xFF)
        sub_08001678(x, y, z, 1);
}

u8 sub_08120DE0(struct Unknown82 *x)
{
    if ((s16)x->unkBA <= 0)
    {
        x->unkBA = x->obj2.object->unk1A;
        if (x->unkB8 != 0)
            x->unkB8 = 0;
        else
            x->unkB8 = 1;
        return 1;
    }
    else
    {
        x->unkBA--;
        return 0;
    }
}

// sub_08120E1C: functionally equivalent (verified against the disassembly by
// hand); the remaining diffs after several regalloc/scheduling attempts are
// pointer-vs-member addressing / operand-order shapes only.
#ifndef NONMATCHING
NAKED void sub_08120E1C(struct Unknown82 *x)
{
    asm(".include \"asm/nonmatching/sub_08120E1C.inc\"");
}
#else
void sub_08120E1C(struct Unknown82 *x)
{
    if (sub_08120DE0(x))
    {
        u16 v = x->unkB6;

        v |= 0x100;
        if (v & 1)
            v &= ~2;
        else
            v |= 2;
        x->unkB6 = v;
        v = x->unkB6;
        v |= 1;
        x->unkB6 = v;
    }
    else
    {
        u16 *b6 = &x->unkB6;
        s16 *b4 = &x->unkB4;
        u16 v = *b6 & ~0x100;

        *b6 = v;
        if (*b4 < 0)
        {
            u16 w = v;

            w &= ~1;
            w &= ~0x20;
            w &= ~0x10;
            *b6 = w;
            if (w & 4)
                *b6 = w & ~4;
            else
                *b6 = w | 4;
        }
        else
        {
            u16 w;

            if (v & 0x10)
                w = v & ~0x20;
            else
                w = v | 0x20;
            *b6 = w;
            *b6 = *b6 | 0x10;
            *b4 -= 1;
        }
    }
}
#endif

// sub_08120EE0: not yet reverse engineered; the #else body below is an
// unverified placeholder — do not trust it as correct.
#ifndef NONMATCHING
NAKED void sub_08120EE0(struct Unknown82 *x)
{
    asm(".include \"asm/nonmatching/sub_08120EE0.inc\"");
}
#else
void sub_08120EE0(struct Unknown82 *x)
{
    (void)x;
}
#endif

void *CreateUnknown87(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct Unknown82), 0x1000, TASK_USE_IWRAM, ObjectDestroy);
    struct Unknown82 *tmp = TaskGetStructPtr(t), *x = tmp;

    InitObject(&tmp->obj2, template, a2);
    x->obj2.base.flags |= 0x02008300;
    x->obj2.base.unk68 &= ~7;
    x->obj2.base.unk5C |= 0x20;
    x->obj2.base.unkC |= 1;
    gUnk_08351648[x->obj2.type].unk10(&x->obj2);
    return x;
}

void sub_0812102C(struct Unknown82 *x)
{
    x->obj2.unk78 = sub_08121080;
    *sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E) = 0;
    x->unkB4 = 0;
    x->unkB6 = 0;
    x->unkB8 = 0;
    x->unkBA = 0;
}

void sub_08121080(struct Unknown82 *x)
{
    sub_08120E1C(x);
    sub_08120EE0(x);
    x->obj2.base.counter++;
}

void *CreateLargeStarStoneBlock88(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct LargeStarStoneBlock), 0x1000, TASK_USE_IWRAM, sub_081214F4);
    struct LargeStarStoneBlock *tmp = TaskGetStructPtr(t), *block = tmp;

    InitObject(&tmp->obj2, template, a2);
    block->obj2.base.flags |= 0x82408040;
    block->obj2.base.unk68 &= ~7;
    block->obj2.base.unk5C &= ~7;
    block->obj2.base.unk5C |= 4;
    block->obj2.base.unk68 |= 0x800;
    block->obj2.base.unkC |= 1;
    if (block->obj2.object->unk22 & 1)
    {
        block->unkE1 = 5;
        block->obj2.unk83 = 1;
    }
    else
    {
        block->unkE1 = 4;
        block->obj2.unk83 = 0;
    }
    sub_0803E308(&block->obj2.base, -0x10, -0x10, 0x10, 0x10);
    sub_0803E2B0(&block->obj2.base, -0x10, -0x10, 0x10, 0x10);
    ObjectInitSprite(&block->obj2);
    gUnk_08351648[block->obj2.type].unk10(&block->obj2);
    return block;
}

void sub_08121194(struct LargeStarStoneBlock *block)
{
    struct LargeStarStoneBlock *block2 = block;
    s32 targetX;
    s32 x12;

    sub_0811EC80(block);
    targetX = (s32)block->obj2.object->x << 8;
    x12 = block->obj2.base.x >> 0xc;
    if (block->unkE8 <= x12)
    {
        s32 y12;
        u8 unk56;

        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x200;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x200;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        unk56 = block->obj2.base.unk56;
        y12 = block->obj2.base.y >> 0xc;
        sub_081214B8(unk56, x12 - 1, y12 - 1);
        sub_081214B8(unk56, x12, y12 - 1);
        sub_081214B8(unk56, x12 - 1, y12);
        sub_081214B8(unk56, x12, y12);
        sub_081214B8(unk56, x12 - 1, y12 + 1);
        sub_081214B8(unk56, x12, y12 + 1);
        block2->unkE8 = (block->obj2.base.y >> 0xc) + 7;
        block2->unkE7 = (block->obj2.base.y >> 0xc) + 2;
        block->obj2.base.flags = (block->obj2.base.flags & ~0x40) | 0x100;
        block->obj2.unk78 = sub_08121324;
    }
    else if (targetX > block->obj2.base.x)
    {
        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x200;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x200;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        block->obj2.base.x = targetX;
    }
    block->obj2.base.counter++;
}

void sub_08121324(struct LargeStarStoneBlock *block)
{
    s32 y12 = block->obj2.base.y >> 0xc;
    u8 f;

    if (block->unkE8 >= y12 && block->unkE7 == y12)
    {
        u8 unk56 = block->obj2.base.unk56;
        u8 x12 = (block->obj2.base.x >> 0xc) - 1;
        u8 y12b = block->unkE7;

        sub_080023E4(unk56, x12, y12b);
        sub_08001408(unk56, sub_080025AC(unk56, x12, y12b), 0, 0);
        unk56 = block->obj2.base.unk56;
        x12 = block->obj2.base.x >> 0xc;
        y12b = block->obj2.base.y >> 0xc;
        sub_080023E4(unk56, x12, y12b);
        sub_08001408(unk56, sub_080025AC(unk56, x12, y12b), 0, 0);
        block->unkE7++;
    }
    f = block->unkE4;
    if (f & 1)
        f |= 4;
    else
        f &= 0xFB;
    block->unkE4 = f;
    if ((block->obj2.base.y >> 8) > 0x70)
    {
        block->obj2.base.sprite.unk8 = (block->obj2.base.sprite.unk8 & ~0x3000) | 0x3000;
        f = block->unkE4;
        f |= 1;
        block->unkE4 = f;
    }
    f = block->unkE4;
    if (!(f & 4) && (f & 1))
        f |= 2;
    else
        f &= 0xFD;
    block->unkE4 = f;
    if (block->unkE4 & 2)
    {
        sub_08089864(&block->obj2.base, -0x10, 5, 0);
        sub_08089864(&block->obj2.base, -0x10, 5, 1);
    }
    if ((block->obj2.base.y >> 8) >= gCurLevelInfo[block->obj2.base.unk56].roomHeight + 0x10)
        block->obj2.base.flags |= 0x1000;
    block->obj2.base.counter++;
}

void sub_08121480(struct LargeStarStoneBlock *block)
{
    block->obj2.base.counter = 0;
    block->unkE2 = 0;
    block->unkE3 = 0;
    block->unkE6 = 0;
    block->unkE7 = 0;
    block->unkE8 = (block->obj2.base.x >> 0xc) + 2;
    block->unkE4 = 0;
    block->obj2.unk78 = sub_08121194;
}

void sub_081214B8(u8 unk56, u8 x, u8 y)
{
    sub_080023E4(unk56, x, y);
    sub_08001408(unk56, sub_080025AC(unk56, x, y), 0, 0);
}

void sub_081214F4(struct Task *t)
{
    struct Object2 *obj2 = TaskGetStructPtr(t);
    u8 unk56 = obj2->base.unk56;
    struct Object *object = obj2->object;
    u32 x = object->unk2;
    u8 y = object->unk3;
    u8 z = gCurLevelInfo[unk56].unk65E;

    ObjectDestroy(t);
    if (x != 0 || unk56 != 0xFF)
        sub_08001678(x, y, z, 1);
}

void *CreateLargeStarStoneBlock89(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct LargeStarStoneBlock), 0x1000, TASK_USE_IWRAM, sub_081219B4);
    struct LargeStarStoneBlock *tmp = TaskGetStructPtr(t), *block = tmp;

    InitObject(&tmp->obj2, template, a2);
    block->obj2.base.flags |= 0x82408040;
    block->obj2.base.unk68 &= ~7;
    block->obj2.base.unk5C &= ~7;
    block->obj2.base.unk5C |= 4;
    block->obj2.base.unk68 |= 0x800;
    block->obj2.base.unkC |= 1;
    if (block->obj2.object->unk22 & 1)
    {
        block->unkE1 = 5;
        block->obj2.unk83 = 1;
    }
    else
    {
        block->unkE1 = 4;
        block->obj2.unk83 = 0;
    }
    sub_0803E308(&block->obj2.base, -0x10, -0x10, 0x10, 0x10);
    sub_0803E2B0(&block->obj2.base, -0x10, -0x10, 0x10, 0x10);
    ObjectInitSprite(&block->obj2);
    gUnk_08351648[block->obj2.type].unk10(&block->obj2);
    return block;
}

void sub_08121654(struct LargeStarStoneBlock *block)
{
    struct LargeStarStoneBlock *block2 = block;
    s32 targetX;
    s32 x12;

    sub_0811EC80(block);
    targetX = (s32)block->obj2.object->x << 8;
    x12 = block->obj2.base.x >> 0xc;
    if (block->unkE8 >= x12)
    {
        s32 y12;
        u8 unk56;

        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x200;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x200;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        unk56 = block->obj2.base.unk56;
        y12 = block->obj2.base.y >> 0xc;
        sub_08121978(unk56, x12, y12 - 1);
        sub_08121978(unk56, x12 + 1, y12 - 1);
        sub_08121978(unk56, x12, y12);
        sub_08121978(unk56, x12 + 1, y12);
        sub_08121978(unk56, x12, y12 + 1);
        sub_08121978(unk56, x12 + 1, y12 + 1);
        block2->unkE8 = (block->obj2.base.y >> 0xc) + 7;
        block2->unkE7 = (block->obj2.base.y >> 0xc) + 2;
        block->obj2.base.flags = (block->obj2.base.flags & ~0x40) | 0x100;
        block->obj2.unk78 = sub_081217E4;
    }
    else if (targetX < block->obj2.base.x)
    {
        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x200;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x200;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        block->obj2.base.x = targetX;
    }
    block->obj2.base.counter++;
}

void sub_081217E4(struct LargeStarStoneBlock *block)
{
    s32 y12 = block->obj2.base.y >> 0xc;
    u8 f;

    if (block->unkE8 >= y12 && block->unkE7 == y12)
    {
        u8 unk56 = block->obj2.base.unk56;
        u8 x12 = block->obj2.base.x >> 0xc;
        u8 y12b = block->unkE7;

        sub_080023E4(unk56, x12, y12b);
        sub_08001408(unk56, sub_080025AC(unk56, x12, y12b), 0, 0);
        unk56 = block->obj2.base.unk56;
        x12 = (block->obj2.base.x >> 0xc) + 1;
        y12b = block->obj2.base.y >> 0xc;
        sub_080023E4(unk56, x12, y12b);
        sub_08001408(unk56, sub_080025AC(unk56, x12, y12b), 0, 0);
        block->unkE7++;
    }
    f = block->unkE4;
    if (f & 1)
        f |= 4;
    else
        f &= 0xFB;
    block->unkE4 = f;
    if ((block->obj2.base.y >> 8) > 0x70)
    {
        block->obj2.base.sprite.unk8 = (block->obj2.base.sprite.unk8 & ~0x3000) | 0x3000;
        f = block->unkE4;
        f |= 1;
        block->unkE4 = f;
    }
    f = block->unkE4;
    if (!(f & 4) && (f & 1))
        f |= 2;
    else
        f &= 0xFD;
    block->unkE4 = f;
    if (block->unkE4 & 2)
    {
        sub_08089864(&block->obj2.base, -0x10, 5, 0);
        sub_08089864(&block->obj2.base, -0x10, 5, 1);
    }
    if ((block->obj2.base.y >> 8) >= gCurLevelInfo[block->obj2.base.unk56].roomHeight + 0x10)
        block->obj2.base.flags |= 0x1000;
    block->obj2.base.counter++;
}

void sub_08121940(struct LargeStarStoneBlock *block)
{
    block->obj2.base.counter = 0;
    block->unkE2 = 0;
    block->unkE3 = 0;
    block->unkE6 = 0;
    block->unkE7 = 0;
    block->unkE8 = (block->obj2.base.x >> 0xc) - 3;
    block->unkE4 = 0;
    block->obj2.unk78 = sub_08121654;
}

void sub_08121978(u8 unk56, u8 x, u8 y)
{
    sub_080023E4(unk56, x, y);
    sub_08001408(unk56, sub_080025AC(unk56, x, y), 0, 0);
}

void sub_081219B4(struct Task *t)
{
    struct Object2 *obj2 = TaskGetStructPtr(t);
    u8 unk56 = obj2->base.unk56;
    struct Object *object = obj2->object;
    u32 x = object->unk2;
    u8 y = object->unk3;
    u8 z = gCurLevelInfo[unk56].unk65E;

    ObjectDestroy(t);
    if (x != 0 || unk56 != 0xFF)
        sub_08001678(x, y, z, 1);
}
