#include "global.h"
#include "data.h"
#include "kirby.h"
#include "functions.h"
#include "object.h"
#include "code_0806F780.h"
#include "malloc_ewram.h"
#include "unknown_75.h"

extern const u8 gUnk_08357D20[];
extern const s8 gUnk_08357D30[];

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

    sub_0811EC80(block);
    targetX = (s32)block->obj2.object->x << 8;
    if (block->unkE8 >= block->obj2.base.x >> 0xc)
    {
        u8 *u56p;

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
        *sub_08002888(0, block->obj2.object->unk4, gCurLevelInfo[block->obj2.kirby3->base.base.base.unk56].unk65E) = 0;
        u56p = &block->obj2.base.unk56;
        sub_081205CC(*u56p, block->obj2.base.x >> 0xc, (block->obj2.base.y >> 0xc) - 1);
        sub_081205CC(*u56p, (block->obj2.base.x >> 0xc) + 1, (block->obj2.base.y >> 0xc) - 1);
        sub_081205CC(*u56p, block->obj2.base.x >> 0xc, block->obj2.base.y >> 0xc);
        sub_081205CC(*u56p, (block->obj2.base.x >> 0xc) + 1, block->obj2.base.y >> 0xc);
        sub_081205CC(*u56p, block->obj2.base.x >> 0xc, (block->obj2.base.y >> 0xc) + 1);
        sub_081205CC(*u56p, (block->obj2.base.x >> 0xc) + 1, (block->obj2.base.y >> 0xc) + 1);
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
#ifndef NONMATCHING
    register u32 f asm("r2");
    register u32 g asm("r1");
    register u32 m asm("r0");
    register u8 *e4 asm("r1");
#else
    u32 f;
    u32 g;
    u32 m;
    u8 *e4;
#endif
    u32 t;
    u8 *p;

    if (block->unkE8 >= (block->obj2.base.y >> 0xc) && block->unkE7 == (block->obj2.base.y >> 0xc))
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
    e4 = &block2->unkE4;
    f = *e4;
    t = f & 1;
    p = e4;
    if (t)
    {
        m = 4;
        *p = m | f;
    }
    else
    {
        m = 0xFB;
        *p = m & f;
    }
    if ((block->obj2.base.y >> 8) > 0x50)
    {
        block->obj2.base.sprite.unk8 = (block->obj2.base.sprite.unk8 & ~0x3000) | 0x3000;
        g = *p;
        m = 1;
        *p = m | g;
    }
    if (!(*p & 4) && (*p & 1))
        *p |= 2;
    else
        *p &= 0xFD;
    if (*p & 2)
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

// sub_08120670: linked-object scan (via sub_08039490), room+type filtered,
// AABB overlap test against block's hitbox rect, tracks the max object->unk11.
void sub_08120670(struct Object2 *block)
{
    u16 room = gCurLevelInfo[block->base.unk56].currentRoom;
    struct Object2 **list = sub_08039490(&block->base);
    s16 rect[4];

    rect[0] = (block->base.x >> 8) + block->object->unk1A;
    rect[1] = (block->base.y >> 8) + block->object->unk1C;
    rect[2] = rect[0] + block->object->unk1E;
    rect[3] = rect[1] + block->object->unk20;

    for (; *list != NULL; list++) {
        struct Object2 *o = *list;
        s32 kx;
        s16 ky;

        if (room != gCurLevelInfo[o->base.unk56].currentRoom)
            continue;
        if (o->type != 0x79 && o->type != 0x7D)
            continue;

        kx = o->base.x << 8;
        ky = (s16)((o->base.y << 8) >> 16);
        if (rect[0] > (s16)(kx >> 16)
         || rect[2] < (s16)((o->base.x << 8) >> 16)
         || rect[1] > ky
         || rect[3] < ky) {
            continue;
        }

        {
            u32 *p = sub_08002888(0, 0xF, gCurLevelInfo[block->base.unk56].unk65E);
            if (*p < block->object->unk11)
                *p = block->object->unk11;
        }
        block->base.flags |= 0x1000;
    }
    block->base.counter++;
}

// sub_08120788: gKirbys array scan (count gUnk_0203AD44), room+player-slot
// filtered, AABB overlap test against block's hitbox rect, tracks the max
// object->unk11 (sibling of sub_08120670, which scans the linked-object
// list instead of gKirbys[]).
#ifndef NONMATCHING
NAKED void sub_08120788(struct Object2 *block)
{
    asm(".include \"asm/nonmatching/sub_08120788.inc\"");
}
#else
void sub_08120788(struct Object2 *block)
{
    s16 rect[4];
    u16 room;
    u8 i;

    rect[0] = (block->base.x >> 8) + block->object->unk1A;
    rect[1] = (block->base.y >> 8) + block->object->unk1C;
    rect[2] = rect[0] + block->object->unk1E;
    rect[3] = rect[1] + block->object->unk20;

    room = gCurLevelInfo[block->base.unk56].currentRoom;

    for (i = 0; i < gUnk_0203AD44; i++) {
        if (room != gCurLevelInfo[i].currentRoom)
            continue;
        if (!(block->object->unk22 & 2) && i < gUnk_0203AD30)
            continue;
        if (!(block->object->unk22 & 4) && i >= gUnk_0203AD30)
            continue;
        if (rect[0] > (gKirbys[i].base.base.base.x >> 8))
            continue;
        if (rect[2] < (gKirbys[i].base.base.base.x >> 8))
            continue;
        if (rect[1] > (gKirbys[i].base.base.base.y >> 8))
            continue;
        if (rect[3] < (gKirbys[i].base.base.base.y >> 8))
            continue;
        if (gKirbys[i].base.base.base.unkC & 0x8000)
            continue;

        {
            u32 *p = sub_08002888(0, 0xF, gCurLevelInfo[block->base.unk56].unk65E);
            if (*p < block->object->unk11)
                *p = block->object->unk11;
        }
        block->base.flags |= 0x1000;
    }
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

// sub_08120A40: EwramMalloc'd array builder using gUnk_08357D20/gUnk_08357D30
// tables; entry struct is struct Unk_0888562C_4 (unknown_75.h), same idiom as
// unknown_75.c:sub_0811C29C but building a whole array instead of one entry.
#ifndef NONMATCHING
NAKED void sub_08120A40(struct Unknown82 *x)
{
    asm(".include \"asm/nonmatching/sub_08120A40.inc\"");
}
#else
void sub_08120A40(struct Unknown82 *x)
{
    struct Unk_0888562C_4 *entry;
    u8 unk56;
    u16 xu, yu;
    s16 x12, y12;
    u32 i, j;
    s16 unused[2];

    x->obj2.base.counter = 0;
    x->unkB4 = gUnk_08357D20[x->obj2.object->unk14];
    x->unkB6 = x->obj2.object->unk14;
    x->unkB8 = 0;
    x->unkBA = 0;

    entry = EwramMalloc(x->unkB4 * sizeof(struct Unk_0888562C_4));
    x->obj2.unk8C = entry;

    unk56 = x->obj2.base.unk56;
    xu = x->obj2.base.x >> 0xc;
    x12 = xu;
    yu = x->obj2.base.y >> 0xc;
    y12 = yu;

    j = 0;
    for (i = 0; i < x->unkB4; i++) {
            u16 dx = gUnk_08357D30[x->unkB6 * 0x12 + j];
            u16 dy;
            u8 ex, ey;
            u16 ax, ay;

            j++;
            dy = gUnk_08357D30[x->unkB6 * 0x12 + j];
            j++;

            ex = xu + dx;
            ey = yu + dy;
            entry->unk14 = sub_080025AC(unk56, ex, ey);

            ax = x12 + (s16)dx;
            ay = y12 + (s16)dy;
            sub_080015A8(unk56, ax, ay, entry->unk0.unk08);
            entry->unk0.unk10 = sub_080023E4(unk56, ax, ay);

            entry->unk0.unk00 = 1;
            entry->unk0.unk02 = ex;
            entry->unk0.unk03 = ey;
            entry->unk0.unk04 = 0x14;

            entry++;
    }

    x->obj2.unk78 = sub_08120B90;
}
#endif

// sub_08120B90: consumer of sub_08120A40's ewram array; same entry struct
// (struct Unk_0888562C_4), invoking sub_08001408 on either the whole entry
// pointer or just its cached union field, same shape as unknown_75.c's
// sub_0811C328 but looped over the array instead of a single entry.
#ifndef NONMATCHING
NAKED void sub_08120B90(struct Unknown82 *x)
{
    asm(".include \"asm/nonmatching/sub_08120B90.inc\"");
}
#else
void sub_08120B90(struct Unknown82 *x)
{
    struct Unk_0888562C_4 * volatile arr = x->obj2.unk8C;
    u8 unk56 = x->obj2.base.unk56;

    if (*sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[unk56].unk65E) != 0) {
        *sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E) = 0;

        x->unkBA = x->obj2.object->unk12;
        if (!(x->unkB8 & 1))
            x->unkB8 |= 0x10;
    }

    if ((s16)x->unkBA > 0) {
        x->unkBA--;
    } else {
        if (x->unkB8 & 1)
            x->unkB8 |= 0x10;
        x->unkBA = 0;
    }

    if (x->unkB8 & 0x10) {
        x->unkB8 &= ~0x10;
        if (x->unkB8 & 1) {
            u32 i;
            x->unkB8 &= ~1;
            for (i = 0; i < (u16)x->unkB4; i++)
                sub_08001408(unk56, &arr[i].unk0, NULL, NULL);
        } else {
            u32 i;
            x->unkB8 |= 1;
            for (i = 0; i < (u16)x->unkB4; i++)
                sub_08001408(unk56, arr[i].unk14, NULL, NULL);
        }
    }

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

void sub_08120EE0(struct Unknown82 *x)
{
    u8 *q = (u8 *)sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E);
    u32 pressed = x->unkB6 & 1;

    if (pressed)
    {
        if (x->unkB8 != 0)
        {
            u8 t0 = x->obj2.object->unk14 >> 8;
            u8 zero = 0;
            q[0] = t0;
            q[1] = x->obj2.object->unk14;
            q[2] = x->obj2.object->unk12 >> 8;
            q[3] = zero;
        }
        else
        {
            u8 t0 = x->obj2.object->unk18 >> 8;
            u8 zero = 0;
            q[0] = t0;
            q[1] = x->obj2.object->unk18;
            q[2] = x->obj2.object->unk16 >> 8;
            q[3] = zero;
        }
    }
    else
    {
        u16 a = x->obj2.object->unk14 >> 8;
        u8 b = x->obj2.object->unk14;
        u16 c = x->obj2.object->unk12 >> 8;
        if (q[0] == a && q[1] == b)
        {
            u32 q2 = q[2];
            u8 match;
#ifndef NONMATCHING
            asm("" : "+r"(q2));
#endif
            match = 1;
            if (q2 != c)
            {
                match = 0;
            }
            if (match)
            {
                q[0] = pressed;
                q[1] = pressed;
                q[2] = pressed;
                q[3] = pressed;
            }
        }
    }
}

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

    sub_0811EC80(block);
    targetX = (s32)block->obj2.object->x << 8;
    if (block->unkE8 <= block->obj2.base.x >> 0xc)
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
        *sub_08002888(0, block->obj2.object->unk4, gCurLevelInfo[block->obj2.base.unk56].unk65E) = 0;
        sub_081214B8(block->obj2.base.unk56, (block->obj2.base.x >> 0xc) - 1, (block->obj2.base.y >> 0xc) - 1);
        sub_081214B8(block->obj2.base.unk56, block->obj2.base.x >> 0xc, (block->obj2.base.y >> 0xc) - 1);
        sub_081214B8(block->obj2.base.unk56, (block->obj2.base.x >> 0xc) - 1, block->obj2.base.y >> 0xc);
        sub_081214B8(block->obj2.base.unk56, block->obj2.base.x >> 0xc, block->obj2.base.y >> 0xc);
        sub_081214B8(block->obj2.base.unk56, (block->obj2.base.x >> 0xc) - 1, (block->obj2.base.y >> 0xc) + 1);
        sub_081214B8(block->obj2.base.unk56, block->obj2.base.x >> 0xc, (block->obj2.base.y >> 0xc) + 1);
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
    struct LargeStarStoneBlock *block2 = block;
#ifndef NONMATCHING
    register u32 f asm("r2");
    register u32 g asm("r1");
    register u32 m asm("r0");
    register u8 *e4 asm("r1");
#else
    u32 f;
    u32 g;
    u32 m;
    u8 *e4;
#endif
    u32 t;
    u8 *p;

    if (block->unkE8 >= (block->obj2.base.y >> 0xc) && block->unkE7 == (block->obj2.base.y >> 0xc))
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
    e4 = &block2->unkE4;
    f = *e4;
    t = f & 1;
    p = e4;
    if (t)
    {
        m = 4;
        *p = m | f;
    }
    else
    {
        m = 0xFB;
        *p = m & f;
    }
    if ((block->obj2.base.y >> 8) > 0x70)
    {
        block->obj2.base.sprite.unk8 = (block->obj2.base.sprite.unk8 & ~0x3000) | 0x3000;
        g = *p;
        m = 1;
        *p = m | g;
    }
    if (!(*p & 4) && (*p & 1))
        *p |= 2;
    else
        *p &= 0xFD;
    if (*p & 2)
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

    sub_0811EC80(block);
    targetX = (s32)block->obj2.object->x << 8;
    if (block->unkE8 >= block->obj2.base.x >> 0xc)
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
        *sub_08002888(0, block->obj2.object->unk4, gCurLevelInfo[block->obj2.base.unk56].unk65E) = 0;
        sub_08121978(block->obj2.base.unk56, block->obj2.base.x >> 0xc, (block->obj2.base.y >> 0xc) - 1);
        sub_08121978(block->obj2.base.unk56, (block->obj2.base.x >> 0xc) + 1, (block->obj2.base.y >> 0xc) - 1);
        sub_08121978(block->obj2.base.unk56, block->obj2.base.x >> 0xc, block->obj2.base.y >> 0xc);
        sub_08121978(block->obj2.base.unk56, (block->obj2.base.x >> 0xc) + 1, block->obj2.base.y >> 0xc);
        sub_08121978(block->obj2.base.unk56, block->obj2.base.x >> 0xc, (block->obj2.base.y >> 0xc) + 1);
        sub_08121978(block->obj2.base.unk56, (block->obj2.base.x >> 0xc) + 1, (block->obj2.base.y >> 0xc) + 1);
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
    struct LargeStarStoneBlock *block2 = block;
#ifndef NONMATCHING
    register u32 f asm("r2");
    register u32 g asm("r1");
    register u32 m asm("r0");
    register u8 *e4 asm("r1");
#else
    u32 f;
    u32 g;
    u32 m;
    u8 *e4;
#endif
    u32 t;
    u8 *p;

    if (block->unkE8 >= (block->obj2.base.y >> 0xc) && block->unkE7 == (block->obj2.base.y >> 0xc))
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
    e4 = &block2->unkE4;
    f = *e4;
    t = f & 1;
    p = e4;
    if (t)
    {
        m = 4;
        *p = m | f;
    }
    else
    {
        m = 0xFB;
        *p = m & f;
    }
    if ((block->obj2.base.y >> 8) > 0x70)
    {
        block->obj2.base.sprite.unk8 = (block->obj2.base.sprite.unk8 & ~0x3000) | 0x3000;
        g = *p;
        m = 1;
        *p = m | g;
    }
    if (!(*p & 4) && (*p & 1))
        *p |= 2;
    else
        *p &= 0xFD;
    if (*p & 2)
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
