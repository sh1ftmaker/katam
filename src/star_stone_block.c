#include "star_stone_block.h"
#include "kirby.h"
#include "functions.h"
#include "object.h"
#include "code_0806F780.h"
#include "malloc_ewram.h"

void sub_0811F034(struct Task *);
void sub_0811F0E8(struct StarStoneBlock *);
void sub_0811F824(struct Task *);
void sub_0811F918(struct Unknown7A *);

void *CreateStarStoneBlock(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct StarStoneBlock), 0x1000, TASK_USE_IWRAM, sub_0811F034);
    struct StarStoneBlock *tmp = TaskGetStructPtr(t), *block = tmp;

    InitObject(&tmp->obj2, template, a2);
    block->obj2.base.flags |= 0x82C08000;
    block->obj2.base.unk68 &= ~7;
    block->obj2.base.unk5C &= ~7;
    block->obj2.base.unk5C |= 4;
    block->obj2.base.unk68 |= 0x800;
    block->obj2.base.unkC |= 1;
    if (block->obj2.object->unk22 & 1)
    {
        block->unkE1 = 3;
        block->obj2.unk83 = 1;
    }
    else
    {
        block->unkE1 = 2;
        block->obj2.unk83 = 0;
    }
    sub_0803E308(&block->obj2.base, -7, -8, 7, 8);
    sub_0803E2B0(&block->obj2.base, -7, -8, 7, 8);
    ObjectInitSprite(&block->obj2);
    gUnk_08351648[block->obj2.type].unk10(&block->obj2);
    return block;
}

void sub_0811EA60(struct StarStoneBlock *block, u32 i)
{
    s32 kRect[4];
    s32 bRect[4];
    s32 bx, by;
    s32 *br;
    u8 v, v2;

#ifndef NONMATCHING
    asm("" ::: "r4");
#endif
    if (gKirbys[i].base.base.base.roomId != block->obj2.base.roomId)
        return;
    kRect[0] = (gKirbys[i].base.base.base.x >> 8) + gKirbys[i].base.base.base.unk3C;
    kRect[1] = (gKirbys[i].base.base.base.y >> 8) + gKirbys[i].base.base.base.unk3D;
    kRect[2] = (gKirbys[i].base.base.base.x >> 8) + gKirbys[i].base.base.base.unk3E;
    kRect[3] = (gKirbys[i].base.base.base.y >> 8) + gKirbys[i].base.base.base.unk3F;
    br = bRect;
    bx = block->obj2.base.x >> 8;
    bRect[0] = bx + block->obj2.base.unk3C - 4;
    by = block->obj2.base.y >> 8;
    br[1] = by + block->obj2.base.unk3D;
    br[2] = bx + block->obj2.base.unk3E + 4;
    br[3] = by + block->obj2.base.unk3F;
    v = (block->obj2.unk90 & (3 << (i * 2))) >> (i * 2);
    v2 = v;
    if (v & 3)
    {
        if (gKirbys[i].base.base.base.kirby2 == (struct Kirby *)block)
            return;
        if (gKirbys[i].base.base.base.x >> 8 > bx)
        {
            u8 t = block->unkE0;
            block->unkE0 = t - 1;
            if (v & 2)
                block->unkE0 = t - 2;
        }
        else
        {
            u32 t = block->unkE0 + 1;
            block->unkE0 = t;
            v2 &= 2;
            if (v2)
                block->unkE0 = t + 1;
            if (((kRect[0] <= bRect[0] && kRect[2] >= bRect[0]) || (kRect[0] >= bRect[0] && br[2] >= kRect[0]))
                && ((kRect[1] <= br[1] && kRect[3] >= br[1]) || (kRect[1] >= br[1] && br[3] >= kRect[1])))
                block->unkE3 |= 0x20;
            return;
        }
    }
    else
    {
        if (!sub_08070504(&block->obj2.base))
            return;
        if (gKirbys[i].base.base.base.kirby2 == (struct Kirby *)block)
            return;
        if (block->obj2.object->unk22 & 2)
        {
            if (((kRect[0] <= bRect[0] && kRect[2] >= bRect[0]) || (kRect[0] >= bRect[0] && br[2] >= kRect[0]))
                && ((kRect[1] <= br[1] && kRect[3] >= br[1]) || (kRect[1] >= br[1] && br[3] >= kRect[1])))
                block->unkE3 |= 0x20;
            return;
        }
    }
    if (((kRect[0] <= bRect[0] && kRect[2] >= bRect[0]) || (kRect[0] >= bRect[0] && br[2] >= kRect[0]))
        && ((kRect[1] <= br[1] && kRect[3] >= br[1]) || (kRect[1] >= br[1] && br[3] >= kRect[1])))
        block->unkE3 |= 0x10;
}

// sub_0811EC80: functionally equivalent; the remaining diffs are register
// allocation and constant-rematerialization shapes only.
#ifndef NONMATCHING
NAKED void sub_0811EC80(struct StarStoneBlock *block)
{
    asm(".include \"asm/nonmatching/sub_0811EC80.inc\"");
}
#else
void sub_0811EC80(struct StarStoneBlock *block)
{
    struct StarStoneBlock *block2 = block;
    u8 avu;
    s8 av;
    s16 step;
    s32 t;
    u16 zero = 0; // the original ORs a register known to be 0 into unkE3

    Macro_080A4728(&block->obj2);
    block2->unkE0 = 0;
    block2->unkE3 &= 0xCF;
    sub_0811EA60(block2, 0);
    sub_0811EA60(block2, 1);
    sub_0811EA60(block2, 2);
    sub_0811EA60(block2, 3);
    if (block->obj2.base.unk62 & 1)
        block2->unkE3 |= 0x10;
    if (block->obj2.base.unk62 & 2)
        block2->unkE3 |= 0x20;
    t = (s8)block2->unkE0;
    if (t < 0)
        t = -t;
    avu = t;
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
    av = avu;
    if (av == 0)
    {
        if (sub_08070504(&block->obj2.base))
        {
            u8 f, g;

            f = block2->unkE3 & 0xF7;
            block2->unkE3 = f;
            if (!(f & 4))
                block2->unkE3 = f | 8;
            g = block2->unkE3 | 4;
            g |= zero;
            block2->unkE3 = g;
            if (block->obj2.object->unk22 & 2)
            {
                if (!(g & 8))
                    goto end;
                if (g & 0x20)
                    goto end;
                if (block->obj2.base.flags & 1)
                {
                    step = 0x200;
                    block->obj2.base.xspeed = step + block->obj2.base.xspeed;
                    if (block->obj2.base.xspeed < -0x200)
                        block->obj2.base.xspeed = -0x200;
                    else if (block->obj2.base.xspeed > step)
                        block->obj2.base.xspeed = step;
                }
                else
                {
                    step = -0x200;
                    block->obj2.base.xspeed = step + block->obj2.base.xspeed;
                    if (block->obj2.base.xspeed > 0x200)
                        block->obj2.base.xspeed = 0x200;
                    else if (block->obj2.base.xspeed < step)
                        block->obj2.base.xspeed = step;
                }
                if (block2->unkE3 & 1)
                    sub_08089864(&block->obj2.base, 0, 0xC, 1);
                else
                    sub_08089864(&block->obj2.base, 0, 4, 1);
            }
            else
            {
                if (!(g & 8))
                    goto end;
                if (g & 0x10)
                    goto end;
                if (block->obj2.base.flags & 1)
                {
                    step = -0x200;
                    block->obj2.base.xspeed = step + block->obj2.base.xspeed;
                    if (block->obj2.base.xspeed < step)
                        block->obj2.base.xspeed = step;
                    else if (block->obj2.base.xspeed > 0x200)
                        block->obj2.base.xspeed = 0x200;
                }
                else
                {
                    step = 0x200;
                    block->obj2.base.xspeed = step + block->obj2.base.xspeed;
                    if (block->obj2.base.xspeed > step)
                        block->obj2.base.xspeed = step;
                    else if (block->obj2.base.xspeed < -0x200)
                        block->obj2.base.xspeed = -0x200;
                }
                if (block2->unkE3 & 1)
                    sub_08089864(&block->obj2.base, 0, 0xC, 0);
                else
                    sub_08089864(&block->obj2.base, 0, 4, 0);
            }
        }
        else
        {
            if (block->obj2.base.xspeed < 0)
            {
                block->obj2.base.xspeed += 0x200;
                if (block->obj2.base.xspeed > 0)
                    block->obj2.base.xspeed = av;
            }
            else
            {
                block->obj2.base.xspeed -= 0x200;
                if (block->obj2.base.xspeed < 0)
                    block->obj2.base.xspeed = av;
            }
            block2->unkE3 &= 0xFB;
        }
    }
    else
    {
        if (av >= block2->unkE1)
        {
            u8 f = block2->unkE3;

            if (f & 0x30)
            {
                if (f & 0x20)
                {
                    if (!(f & 0x10) && (s8)block2->unkE0 < 0)
                    {
                        if (block->obj2.base.flags & 1)
                        {
                            block->obj2.base.xspeed -= 0x40;
                            if (block->obj2.base.xspeed < -0x40)
                                block->obj2.base.xspeed = -0x40;
                            else if (block->obj2.base.xspeed > 0x40)
                                block->obj2.base.xspeed = 0x40;
                        }
                        else
                        {
                            block->obj2.base.xspeed += 0x40;
                            if (block->obj2.base.xspeed > 0x40)
                                block->obj2.base.xspeed = 0x40;
                            else if (block->obj2.base.xspeed < -0x40)
                                block->obj2.base.xspeed = -0x40;
                        }
                    }
                }
                else if (f & 0x10)
                {
                    if ((s8)block2->unkE0 > 0)
                    {
                        if (block->obj2.base.flags & 1)
                        {
                            block->obj2.base.xspeed += 0x40;
                            if (block->obj2.base.xspeed < -0x40)
                                block->obj2.base.xspeed = -0x40;
                            else if (block->obj2.base.xspeed > 0x40)
                                block->obj2.base.xspeed = 0x40;
                        }
                        else
                        {
                            block->obj2.base.xspeed -= 0x40;
                            if (block->obj2.base.xspeed > 0x40)
                                block->obj2.base.xspeed = 0x40;
                            else if (block->obj2.base.xspeed < -0x40)
                                block->obj2.base.xspeed = -0x40;
                        }
                    }
                }
            }
            else
            {
                if ((s8)block2->unkE0 > 0)
                {
                    if (block->obj2.base.flags & 1)
                    {
                        block->obj2.base.xspeed += 0x40;
                        if (block->obj2.base.xspeed < -0x40)
                            block->obj2.base.xspeed = -0x40;
                        else if (block->obj2.base.xspeed > 0x40)
                            block->obj2.base.xspeed = 0x40;
                    }
                    else
                    {
                        block->obj2.base.xspeed -= 0x40;
                        if (block->obj2.base.xspeed > 0x40)
                            block->obj2.base.xspeed = 0x40;
                        else if (block->obj2.base.xspeed < -0x40)
                            block->obj2.base.xspeed = -0x40;
                    }
                }
                else
                {
                    if (block->obj2.base.flags & 1)
                    {
                        block->obj2.base.xspeed -= 0x40;
                        if (block->obj2.base.xspeed < -0x40)
                            block->obj2.base.xspeed = -0x40;
                        else if (block->obj2.base.xspeed > 0x40)
                            block->obj2.base.xspeed = 0x40;
                    }
                    else
                    {
                        block->obj2.base.xspeed += 0x40;
                        if (block->obj2.base.xspeed > 0x40)
                            block->obj2.base.xspeed = 0x40;
                        else if (block->obj2.base.xspeed < -0x40)
                            block->obj2.base.xspeed = -0x40;
                    }
                }
            }
        }
    }
end:
    if (block->obj2.base.flags & 0x20)
    {
        if (block2->unkE2 != 0)
        {
            if (!(block->obj2.object->unk22 & 4))
            {
                u8 t2;

                block->obj2.base.flags |= 0x100;
                t2 = block2->unkE3;
                t2 |= 2;
                t2 |= 0x40;
                block2->unkE3 = t2;
            }
        }
        else
        {
            block2->unkE2 = 1;
        }
    }
}
#endif

void sub_0811F034(struct Task *t)
{
    struct StarStoneBlock *block = TaskGetStructPtr(t);
    u8 f, unk56, unk56b, unk3, unk3b, unk65E;
    u32 unk2;

    f = block->unkE3;
    unk56 = block->obj2.base.unk56;
    unk56b = unk56;
    unk2 = block->obj2.object->unk2;
    unk3 = block->obj2.object->unk3;
    unk3b = unk3;
    if (unk56 != 0xFF)
    {
        unk65E = gCurLevelInfo[unk56].unk65E;
        unk56b = unk56;
    }
    ObjectDestroy(t);
    if (unk2 != 0 || unk56b != 0xFF)
    {
        if (f & 0x40)
            sub_08001678(unk2, unk3, unk65E, 1);
        else
            sub_08001678(unk2, unk3b, unk65E, 0);
    }
}

void sub_0811F0CC(struct Object2 *obj)
{
    struct StarStoneBlock *block = (struct StarStoneBlock *)obj;

    block->obj2.base.counter = 0;
    block->unkE2 = 0;
    block->unkE3 = 0;
    block->obj2.unk78 = sub_0811F0E8;
}

void sub_0811F0E8(struct StarStoneBlock *block)
{
    sub_0811EC80(block);
    if (block->obj2.base.y >> 8 >= gCurLevelInfo[block->obj2.base.unk56].roomHeight - 8)
    {
        block->obj2.base.flags |= 0x1000;
    }
    block->obj2.base.counter++;
}

void *CreateUnknown7A(struct Object *template, u8 a2)
{
    struct Task *t = TaskCreate(ObjectMain, sizeof(struct Unknown7A), 0x1000, TASK_USE_IWRAM, sub_0811F824);
    struct Unknown7A *block = TaskGetStructPtr(t);
    u16 rect[4];

    InitObject(&block->obj2, template, a2);
    block->obj2.base.flags |= 0x2008740;
    block->obj2.base.unk68 &= ~7;
    block->obj2.base.unk5C |= 0x20;
    block->obj2.base.unkC |= 1;
    rect[0] = block->obj2.object->unk1A;
    rect[1] = block->obj2.object->unk1C;
    rect[2] = rect[0] + block->obj2.object->unk1E;
    rect[3] = rect[1] + block->obj2.object->unk20;
    sub_0803E308(&block->obj2.base, (s8)rect[0], (s8)rect[1], (s8)rect[2], (s8)rect[3]);
    gUnk_08351648[block->obj2.type].unk10(&block->obj2);
    return block;
}

void sub_0811F20C(struct Object2 *obj)
{
    struct Unknown7A *block = (struct Unknown7A *)obj;

    block->obj2.base.counter = 0;
    block->unkB8 = block->obj2.object->x;
    block->unkBA = block->obj2.object->y;
    block->unkBC = block->unkB8;
    block->unkBE = block->unkBA;
    block->unkC0 = block->unkB8;
    block->unkC2 = block->unkBA;
    block->unkC4 = 0;
    block->unkC6 = block->obj2.object->unk14;
    block->obj2.unk78 = sub_0811F918;
}

// sub_0811F26C: functionally equivalent; the remaining diffs are register
// allocation and instruction-scheduling shapes only.
#ifndef NONMATCHING
NAKED void sub_0811F26C(struct Unknown7A *block)
{
    asm(".include \"asm/nonmatching/sub_0811F26C.inc\"");
}
#else
void sub_0811F26C(struct Unknown7A *block)
{
    u8 *state = (u8 *)sub_08002888(0, block->obj2.object->unk4, gCurLevelInfo[block->obj2.base.unk56].unk65E);

    if (state[0] != 0 || state[1] != 0 || state[2] != 0)
    {
        u8 *b4 = block->unkB4;
        u8 v0 = state[0];
        u8 v0b = v0;
        u8 *b4b = b4;
        bool8 diff;

        if (v0 != b4[0] || state[1] != b4[1] || (diff = state[2] != b4[2]))
        {
            u8 z = 0;

            b4b[0] = v0b;
            b4b[1] = state[1];
            b4b[2] = state[2];
            b4b[3] = z;
            block->unkC6 = block->obj2.object->unk14;
            block->unkC4 &= ~0x200;
        }
        else if (block->unkC4 & 0x200)
        {
            b4[0] = v0b;
            b4[1] = state[1];
            b4[2] = state[2];
            b4[3] = diff;
            block->unkC6 = block->obj2.object->unk14;
            block->unkC4 &= ~0x200;
        }
    }
    else if (!(block->unkC4 & 0x100))
    {
        u16 y = block->obj2.object->y;
        s16 b8 = block->unkB8;
        u16 by = block->unkBA;
        s16 x = block->obj2.object->x;
        u8 flag = x == b8 && y == by;

        if (flag)
        {
            u8 *q;

            block->unkC4 &= ~0x200;
            q = block->unkB4;
            q[0] = 0;
            q[1] = 0;
            q[2] = 0;
            q[3] = 0;
        }
        else if (block->unkB4[0] & 0x10)
        {
            if (block->unkC6 >= 0)
            {
                block->unkC6 = block->unkC6 - 1;
            }
            else
            {
                block->unkBC = block->unkB8;
                block->unkBE = block->unkBA;
                block->unkC0 = block->obj2.object->x;
                block->unkC2 = block->obj2.object->y;
                block->unkC6 = block->obj2.object->unk14;
                block->unkC4 |= 0x200;
            }
        }
    }
}
#endif

// sub_0811F410: functionally equivalent; the remaining diffs are register
// allocation and instruction-scheduling shapes only.
#ifndef NONMATCHING
NAKED void sub_0811F410(struct Unknown7A *block)
{
    asm(".include \"asm/nonmatching/sub_0811F410.inc\"");
}
#else
void sub_0811F410(struct Unknown7A *block)
{
    u16 t;
    u16 y;
    u16 *c4, *c4b;
    u16 mask;
    u32 a, b;

    block->unkC0 = block->obj2.object->x;
    y = block->obj2.object->y;
    block->unkC2 = y;
    if (!(block->unkC4 & 0x200))
    {
        switch (block->unkB4[0] & 3)
        {
        case 0:
            block->unkC0 -= block->unkB4[2] << 4;
            break;
        case 1:
            block->unkC2 = y - (block->unkB4[2] << 4);
            break;
        case 2:
            block->unkC0 = (block->unkB4[2] << 4) + block->unkC0;
            break;
        case 3:
            block->unkC2 = y + (block->unkB4[2] << 4);
            break;
        }
    }
    c4 = &block->unkC4;
    t = *c4 & 0xFFE0;
    mask = 0;
    *c4 = t;
    a = *(u32 *)&block->unkC0;
    b = *(u32 *)&block->unkB8;
    c4b = c4;
    if (a == b)
    {
        *c4b = t | 0x10;
    }
    else if (block->unkC0 != block->unkB8)
    {
        if (block->unkC2 == block->unkBA)
        {
            if (block->unkB8 < block->unkC0)
                *c4b = t | 4;
            else
                *c4b = t | 1;
        }
    }
    else
    {
        if (block->unkC2 != block->unkBA)
        {
            if (block->unkBA < block->unkC2)
                *c4b = t | 8;
            else
                *c4b = t | 2;
        }
    }
    mask = 0x100;
    *c4b = mask | *c4b;
    switch (*c4b & 0x1F)
    {
    case 1:
        if (block->obj2.base.flags & 1)
        {
            block->obj2.base.xspeed += block->unkB4[1];
            if (block->obj2.base.xspeed < -block->unkB4[1])
                block->obj2.base.xspeed = -block->unkB4[1];
            else if (block->obj2.base.xspeed > block->unkB4[1])
                block->obj2.base.xspeed = block->unkB4[1];
        }
        else
        {
            block->obj2.base.xspeed -= block->unkB4[1];
            if (block->obj2.base.xspeed > block->unkB4[1])
                block->obj2.base.xspeed = block->unkB4[1];
            else if (block->obj2.base.xspeed < -block->unkB4[1])
                block->obj2.base.xspeed = -block->unkB4[1];
        }
        block->unkB8 = block->obj2.base.x >> 8;
        break;
    case 2:
        if (block->unkB4[1] != 0)
        {
            block->obj2.base.yspeed += block->unkB4[1];
            if (block->obj2.base.yspeed > block->unkB4[1])
                block->obj2.base.yspeed = block->unkB4[1];
        }
        else
        {
            block->obj2.base.yspeed += block->unkB4[1];
            if (block->obj2.base.yspeed < -block->unkB4[1])
                block->obj2.base.yspeed = -block->unkB4[1];
        }
        block->unkBA = block->obj2.base.y >> 8;
        break;
    case 4:
        if (block->obj2.base.flags & 1)
        {
            block->obj2.base.xspeed -= block->unkB4[1];
            if (block->obj2.base.xspeed < -block->unkB4[1])
                block->obj2.base.xspeed = -block->unkB4[1];
            else if (block->obj2.base.xspeed > block->unkB4[1])
                block->obj2.base.xspeed = block->unkB4[1];
        }
        else
        {
            block->obj2.base.xspeed += block->unkB4[1];
            if (block->obj2.base.xspeed > block->unkB4[1])
                block->obj2.base.xspeed = block->unkB4[1];
            else if (block->obj2.base.xspeed < -block->unkB4[1])
                block->obj2.base.xspeed = -block->unkB4[1];
        }
        block->unkB8 = block->obj2.base.x >> 8;
        break;
    case 8:
        block->obj2.base.yspeed -= block->unkB4[1];
        if (block->obj2.base.yspeed < -block->unkB4[1])
            block->obj2.base.yspeed = -block->unkB4[1];
        block->unkBA = block->obj2.base.y >> 8;
        break;
    }
    switch (*c4b & 0x1F)
    {
    case 1:
        if (block->unkC0 < block->unkB8)
            goto skip;
        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x7FFF;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x7FFF;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        block->unkB8 = block->unkC0;
        break;
    case 2:
        if (block->unkC2 < block->unkBA)
            goto skip;
        if (block->obj2.base.yspeed < 0)
        {
            block->obj2.base.yspeed += 0x7FFF;
            if (block->obj2.base.yspeed > 0)
                block->obj2.base.yspeed = 0;
        }
        else
        {
            block->obj2.base.yspeed -= 0x7FFF;
            if (block->obj2.base.yspeed < 0)
                block->obj2.base.yspeed = 0;
        }
        block->unkBA = block->unkC2;
        break;
    case 4:
        if (block->unkC0 > block->unkB8)
            goto skip;
        if (block->obj2.base.xspeed < 0)
        {
            block->obj2.base.xspeed += 0x7FFF;
            if (block->obj2.base.xspeed > 0)
                block->obj2.base.xspeed = 0;
        }
        else
        {
            block->obj2.base.xspeed -= 0x7FFF;
            if (block->obj2.base.xspeed < 0)
                block->obj2.base.xspeed = 0;
        }
        block->unkB8 = block->unkC0;
        break;
    case 8:
        if (block->unkC2 > block->unkBA)
            goto skip;
        if (block->obj2.base.yspeed < 0)
        {
            block->obj2.base.yspeed += 0x7FFF;
            if (block->obj2.base.yspeed > 0)
                block->obj2.base.yspeed = 0;
        }
        else
        {
            block->obj2.base.yspeed -= 0x7FFF;
            if (block->obj2.base.yspeed < 0)
                block->obj2.base.yspeed = 0;
        }
        block->unkBA = block->unkC2;
        break;
    }
    *c4b &= ~0x100;
skip:
    gCurLevelInfo[block->obj2.base.unk56].unk2C = -((block->obj2.object->x - block->unkB8) << 8);
    gCurLevelInfo[block->obj2.base.unk56].unk30 = (block->obj2.object->y - block->unkBA) << 8;
}
#endif

// sub_0811F824: functionally equivalent; the remaining diffs are register
// allocation and instruction-scheduling shapes only.
#ifndef NONMATCHING
NAKED void sub_0811F824(struct Task *t)
{
    asm(".include \"asm/nonmatching/sub_0811F824.inc\"");
}
#else
void sub_0811F824(struct Task *t)
{
    struct Unknown7A *block = TaskGetStructPtr(t);

    if (block->obj2.base.sprite.tilesVram != 0)
    {
        if (!(block->obj2.base.flags & 0x4000))
        {
            VramFree(block->obj2.base.sprite.tilesVram);
        }
    }
    if (block->obj2.unk8C != NULL)
    {
        EwramFree(block->obj2.unk8C);
    }
    if (block->obj2.object != 0)
    {
        if (block->obj2.object->unk2 != 0 || block->obj2.object->unk3 != 31)
        {
            if (block->obj2.object->unk2 != 0 || block->obj2.base.unk56 != 0xFF)
            {
                sub_08001678(block->obj2.object->unk2, block->obj2.object->unk3,
                             gCurLevelInfo[block->obj2.base.unk56].unk65E, 1);
            }
            else
            {
                return;
            }
        }
        else
        {
            struct Object *p = gUnk_020229E0;
            u8 i;

            for (i = 0; i < 0x20; i++, p++)
            {
                if (p == block->obj2.object)
                {
                    gUnk_020229D4 &= ~(1 << i);
                    break;
                }
            }
        }
    }
    if (block->obj2.base.unk56 != 0xFF)
    {
        sub_080028CC(block->obj2.base.unk56, sub_08002984(block->obj2.base.unk56, &block->obj2.base.unk56));
    }
}
#endif

void sub_0811F918(struct Unknown7A *block)
{
    sub_0811F26C(block);
    sub_0811F410(block);
    Macro_080A4728(&block->obj2);
    block->obj2.base.counter++;
}
