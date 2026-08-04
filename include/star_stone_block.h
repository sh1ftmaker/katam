#ifndef GUARD_STAR_STONE_BLOCK_H
#define GUARD_STAR_STONE_BLOCK_H

#include "global.h"
#include "data.h"

struct StarStoneBlock
{
    struct Object2 obj2;
    u8 fillerB4[0x2C];
    u8 unkE0;
    u8 unkE1;
    u8 unkE2;
    u8 unkE3;
}; /* size = 0xE4 */

struct Unknown7A
{
    struct Object2 obj2;
    u8 unkB4[4];
    s16 unkB8;
    s16 unkBA;
    s16 unkBC;
    s16 unkBE;
    s16 unkC0;
    s16 unkC2;
    u16 unkC4;
    s16 unkC6;
}; /* size = 0xC8 */

void *CreateStarStoneBlock(struct Object *, u8);
void sub_0811EA60(struct StarStoneBlock *, u32);
void sub_0811EC80(struct StarStoneBlock *);
void sub_0811F0CC(struct Object2 *);
void *CreateUnknown7A(struct Object *, u8);
void sub_0811F20C(struct Object2 *);
void sub_0811F26C(struct Unknown7A *);
void sub_0811F410(struct Unknown7A *);

#endif // GUARD_STAR_STONE_BLOCK_H
