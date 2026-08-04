#ifndef GUARD_CODE_0802E57C_H
#define GUARD_CODE_0802E57C_H

#include "global.h"
#include "sprite.h"
#include "task.h"

struct Unk_0802E57C;

struct Unk_0802E57C_C {
    /* 0x00 */ struct Sprite unk0;
    /* 0x28 */ void (*unk28)(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
    /* 0x2C */ u32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s16 unk38;
    /* 0x3A */ s16 unk3A;
    /* 0x3C */ u16 *unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u16 unk44;
    /* 0x46 */ u16 unk46;
    /* 0x48 */ u16 unk48;
    /* 0x4A */ u16 unk4A;
    /* 0x4C */ u8 filler4C[4];
}; /* size = 0x50 */

typedef void (*UnkCFunc2)(struct Unk_0802E57C *, struct Unk_0802E57C_C *);

struct Unk_0802E57C_174 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
}; /* size = 0x8 */

struct Unk_0802E57C {
    /* 0x000 */ struct Task *unk0;
    /* 0x004 */ void (*unk4)(struct Unk_0802E57C *);
    /* 0x008 */ u32 unk8; // vram
    /* 0x00C */ struct Unk_0802E57C_C unkC[4];
    /* 0x14C */ struct Sprite unk14C;
    /* 0x174 */ const struct Unk_0802E57C_174 *unk174;
    /* 0x178 */ s32 unk178;
    /* 0x17C */ s32 unk17C;
    /* 0x180 */ u16 unk180;
    /* 0x182 */ u16 unk182;
    /* 0x184 */ u16 unk184;
    /* 0x186 */ u16 unk186;
    /* 0x188 */ u32 unk188;
    /* 0x18C */ u32 unk18C;
    /* 0x190 */ u16 unk190;
}; /* size = 0x194 */

/* code_0802E57C.c */
struct Unk_0802E57C *sub_0802E57C(void);
void sub_0802E6C4(struct Unk_0802E57C *);
void sub_0802E71C(struct Task *);
void sub_0802E78C(void);
void sub_0802E97C(struct Unk_0802E57C *);
void sub_0802EA4C(struct Unk_0802E57C *);
void sub_0802EBB0(struct Unk_0802E57C *);
void sub_0802ECBC(struct Unk_0802E57C *);
void sub_0802ED44(struct Unk_0802E57C *);
void sub_0802EDC8(struct Unk_0802E57C *);
void sub_0802EE54(struct Unk_0802E57C *);
void sub_0802EF90(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F088(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F110(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F1C4(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F240(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F2D0(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F354(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F40C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F464(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F4BC(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F51C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F5B8(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F638(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F6A0(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F714(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F77C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F810(struct Unk_0802E57C *, struct Unk_0802E57C_C *);

/* code_0802F8D8.c */
void sub_0802F9AC(void);
void sub_0802FB0C(void);
void sub_0802FBE0(struct Unk_0802E57C *);
void sub_0802FBF4(struct Unk_0802E57C *);
void sub_0802FC08(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FC14(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FC64(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FCB4(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FCDC(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FD00(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FD3C(struct Unk_0802E57C *);
void sub_0802FDA4(struct Unk_0802E57C *);
void sub_0802FDF4(struct Unk_0802E57C *);
void sub_0802FE30(struct Unk_0802E57C *);
void sub_0802FE4C(struct Unk_0802E57C *);
void sub_0802FE5C(void);
void sub_0802FE70(void);
void sub_0802FE84(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FEAC(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FEC8(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FF14(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FF38(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FF5C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FF9C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FFA8(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802FFDC(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_08030018(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_08030024(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0803005C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_08030068(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_080300A0(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_080300CC(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0803010C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_08030138(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0803017C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_080301B0(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_080301DC(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0803020C(struct Unk_0802E57C *, struct Unk_0802E57C_C *);

#endif
