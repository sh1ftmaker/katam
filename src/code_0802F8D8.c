#include "global.h"
#include "code_0802E57C.h"
#include "random.h"
#include "sprite.h"
#include "task.h"

struct Unk_0802F8D8 {
    /* 0x00 */ struct Sprite sprite;
    /* 0x28 */ struct Unk_0802E57C *unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
}; /* size = 0x3C */

/* Local view of struct Unk_0802E57C_C with the fields in filler48 named. */
struct Unk_0802F8D8_C {
    /* 0x00 */ struct Sprite unk0;
    /* 0x28 */ void (*unk28)(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
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

typedef void (*UnkCFunc2)(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);

extern u16 gUnk_082EB800[];
extern u16 gUnk_082EB7F8[];
extern const UnkCFunc2 gUnk_082EB7D0[];

void sub_0802E97C(struct Unk_0802E57C *);
void sub_0802ECBC(struct Unk_0802E57C *);
void sub_0802EF90(struct Unk_0802E57C *, struct Unk_0802E57C_C *);
void sub_0802F40C(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
void sub_0802F51C(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
void sub_0802F5B8(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
void sub_0802F638(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
void sub_0802F6A0(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
void sub_0802F714(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);
void sub_0802F77C(struct Unk_0802E57C *, struct Unk_0802F8D8_C *);

struct Unk_0802F8D8 *sub_0802F8D8(struct Unk_0802E57C *a, u16 animId, u16 variant, u32 tiles, s32 x, s32 y, u16 xspeed,
                                  u16 yspeed, u16 duration);
void sub_0802F9AC(void);
struct Unk_0802F8D8 *sub_0802FA40(struct Unk_0802E57C *a, u16 animId, u16 variant, u32 tiles, s32 x, s32 y, u16 xspeed,
                                  u16 yspeed, u16 duration);
void sub_0802FB0C(void);
void sub_0802FBE0(struct Unk_0802E57C *a);
void sub_0802FBF4(struct Unk_0802E57C *a);
void sub_0802FC08(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FC14(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FC64(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FCB4(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FCDC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FD00(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FD3C(struct Unk_0802E57C *a);
void sub_0802FDA4(struct Unk_0802E57C *a);
void sub_0802FDF4(struct Unk_0802E57C *a);
void sub_0802FE30(struct Unk_0802E57C *a);
void sub_0802FE4C(struct Unk_0802E57C *a);
void sub_0802FE5C(void);
void sub_0802FE70(void);
void sub_0802FE84(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FEAC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FEC8(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FF14(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FF38(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FF5C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FF9C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FFA8(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0802FFDC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_08030018(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_08030024(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0803005C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_08030068(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_080300A0(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_080300CC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0803010C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_08030138(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0803017C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_080301B0(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_080301DC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);
void sub_0803020C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b);

struct Unk_0802F8D8 *sub_0802F8D8(struct Unk_0802E57C *a, u16 animId, u16 variant, u32 tiles, s32 x, s32 y, u16 xspeed,
                                  u16 yspeed, u16 duration) {
    struct Task *t = TaskCreate(sub_0802F9AC, sizeof(struct Unk_0802F8D8), 0x101, 0, NULL);
    struct Unk_0802F8D8 *s = TaskGetStructPtr(t);

    s->unk28 = a;
#ifndef NONMATCHING
    asm("" ::: "r8");
#endif
    s->unk2C = x;
    s->unk30 = y;
    s->unk34 = xspeed;
    s->unk36 = yspeed;
    s->unk38 = duration;
    SpriteInit(&s->sprite, tiles, 0x340, animId, variant, 0, ({ s32 m = -1; m; }), 0x10, 0xB, x >> 8, y >> 8,
               0x80000);
    s->sprite.unk8 |= 0x40000;
    return s;
}

void sub_0802F9AC(void) {
    struct Unk_0802F8D8 *tmp = TaskGetStructPtr(gCurTask), *s = tmp;

    s->unk2C += s->unk34;
    s->unk30 += s->unk36;
    if (s->unk38 != 0) {
        s->unk38--;
        if (s->unk38 == 0) {
            gCurTask->main = sub_0802FE5C;
        }
    }
    if (s->unk28->unk188 & 0x20000000) {
        gCurTask->main = sub_0802FE5C;
    }
    s->sprite.x = s->unk2C >> 8;
    s->sprite.y = s->unk30 >> 8;
    sub_08155128(&s->sprite);
    s->sprite.unk1B = 0xFF;
    sub_0815604C(&s->sprite);
}

struct Unk_0802F8D8 *sub_0802FA40(struct Unk_0802E57C *a, u16 animId, u16 variant, u32 tiles, s32 x, s32 y, u16 xspeed,
                                  u16 yspeed, u16 duration) {
    struct Task *t = TaskCreate(sub_0802FB0C, sizeof(struct Unk_0802F8D8), 0x101, 0, NULL);
    struct Unk_0802F8D8 *s = TaskGetStructPtr(t);

    s->unk28 = a;
    s->unk2C = x;
    s->unk30 = y;
    s->unk34 = xspeed;
    s->unk36 = yspeed;
    s->unk38 = duration;
    SpriteInit(&s->sprite, tiles, 0, animId, variant, 0, 0xFF, 0x10, 0xB, x >> 8, y >> 8, 0x80000);
    s->sprite.unk8 |= 0x40000;
    return s;
}

void sub_0802FB0C(void) {
    struct Unk_0802F8D8 *tmp = TaskGetStructPtr(gCurTask), *s = tmp, *s2 = s;

    s->sprite.x = s->unk2C >> 8;
    s->sprite.y = s->unk30 >> 8;
    if (sub_08155128(&s->sprite) == 0) {
        if (s->unk38 != 0 && --s->unk38 == 0) {
            gCurTask->main = sub_0802FE70;
        } else {
            s->sprite.unk1B = 0xFF;
        }
    }
    sub_0815604C(&s2->sprite);
    s->unk2C += s->unk34;
    s->unk30 += s->unk36;
    if ((u16)(s2->sprite.x + 0x40) > 0x170 || s2->sprite.y < -0x40 || s2->sprite.y > 0xE0) {
        gCurTask->main = sub_0802FE70;
    }
    if (s->unk28->unk188 & 0x20000000) {
        gCurTask->main = sub_0802FE70;
    }
}

void sub_0802FBE0(struct Unk_0802E57C *a) {
    a->unk188 |= 0x40000000;
}

void sub_0802FBF4(struct Unk_0802E57C *a) {
    a->unk188 |= 0x200;
}

void sub_0802FC08(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    b->unk2C |= 2;
}

void sub_0802FC14(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u8 v = 0;
    u32 flags;

#ifndef NONMATCHING
    asm("" : "+r"(v));
#endif
    b->unk0.animId = 0;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags |= 0x10;
    b->unk2C = flags;
    b->unk34 = 0x8000;
    b->unk48 = Rand16() & 0x1F;
    b->unk28 = sub_0802FE84;
}

void sub_0802FC64(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;

    b->unk0.animId = 0x49;
    b->unk0.variant = 1;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    if (b->unk30 <= 0x4FFF) {
        flags &= ~1;
        b->unk2C = flags;
    } else if (b->unk30 > 0xA000) {
        flags |= 1;
        b->unk2C = flags;
    }
    b->unk34 = 0x8000;
    b->unk28 = sub_0802FEAC;
}

void sub_0802FCB4(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u8 v = 0;
    u32 flags;

    b->unk0.animId = 0x185;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    b->unk28 = sub_0802FFA8;
}

void sub_0802FCDC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u8 v = 6;
    u32 flags;

#ifndef NONMATCHING
    asm("" : "+r"(v));
#endif
    b->unk0.animId = 6;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    b->unk28 = sub_0802F51C;
}

void sub_0802FD00(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    UnkCFunc2 f;

    b->unk48 = Rand16() & 0x1F;
    f = sub_0802F77C;
    b->unk28 = f;
    f(a, b);
}

void sub_0802FD3C(struct Unk_0802E57C *a) {
    u16 i = 0;
    void (*f)(struct Unk_0802E57C *) = sub_0802FDA4;

    for (; i < 4; i++) {
        struct Unk_0802F8D8_C *b = (struct Unk_0802F8D8_C *)&a->unkC[i];

        b->unk3C = gUnk_082EB800;
        b->unk42 = gUnk_082EB800[b->unk40 * 2];
        b->unk44 = b->unk3C[b->unk40 * 2 + 1];
        b->unk28 = gUnk_082EB7D0[b->unk42];
    }
    a->unk4 = f;
}

void sub_0802FDA4(struct Unk_0802E57C *a) {
    u16 flag = 1;
    u16 i;

    for (i = 0; i < 4; i++) {
        sub_0802EF90(a, &a->unkC[i]);
        if (!(a->unkC[i].unk2C & 2)) {
            flag = 0;
        }
    }
    if (flag != 0) {
        void (*f)(struct Unk_0802E57C *) = sub_0802FDF4;

        a->unk4 = f;
        f(a);
    }
}

void sub_0802FDF4(struct Unk_0802E57C *a) {
    u16 i = 0;
    void (*f)(struct Unk_0802E57C *) = sub_0802E97C;

    for (; i < 4; i++) {
        struct Unk_0802F8D8_C *b = (struct Unk_0802F8D8_C *)&a->unkC[i];

        b->unk3C = gUnk_082EB7F8;
        b->unk40 = 0;
    }
    a->unk4 = f;
    f(a);
}

void sub_0802FE30(struct Unk_0802E57C *a) {
    void (*f)(struct Unk_0802E57C *);

    a->unk190 = 0;
    f = sub_0802ECBC;
    a->unk4 = f;
    f(a);
}

void sub_0802FE4C(struct Unk_0802E57C *a) {
    a->unk188 |= 1;
}

void sub_0802FE5C(void) {
    TaskDestroy(gCurTask);
}

void sub_0802FE70(void) {
    TaskDestroy(gCurTask);
}

void sub_0802FE84(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u16 *p = &b->unk44;
    u16 v = b->unk48;

    if (*p < v) {
        b->unk2C |= 2;
    } else {
        b->unk48 = v + 1;
    }
}

void sub_0802FEAC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    if (b->unk2C & 8) {
        b->unk28 = sub_0802FEC8;
    }
}

void sub_0802FEC8(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u8 v = 0;
    u32 flags;

    b->unk0.animId = 0x49;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags |= 0x10;
    b->unk2C = flags;
    b->unk48 = Rand16() & 0x1F;
    b->unk28 = sub_0802FF14;
}

void sub_0802FF14(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u16 *p = &b->unk44;
    u16 v = b->unk48;

    if (*p < v) {
        b->unk28 = sub_0802FF38;
    } else {
        b->unk48 = v + 1;
    }
}

void sub_0802FF38(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;

    b->unk0.animId = 0x49;
    b->unk0.variant = 2;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    b->unk28 = sub_0802FF5C;
}

void sub_0802FF5C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u16 *p = &b->unk44;
    u16 v = b->unk48;

    if (*p < v) {
        u8 v2 = 0;
        u32 flags;

#ifndef NONMATCHING
        asm("" : "+r"(v2));
#endif
        b->unk0.animId = 0;
        b->unk0.variant = v2;
        b->unk0.unk1B = 0xFF;
        flags = b->unk2C;
        flags &= ~8;
        flags |= 0x10;
        b->unk2C = flags;
        b->unk28 = sub_0802FF9C;
    } else {
        b->unk48 = v + 1;
    }
}

void sub_0802FF9C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    b->unk2C |= 2;
}

void sub_0802FFA8(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags = b->unk2C;

    if (flags & 8) {
        b->unk0.animId = 0x185;
        b->unk0.variant = 1;
        b->unk0.unk1B = 0xFF;
        flags &= ~8;
        flags &= ~0x10;
        b->unk2C = flags;
        b->unk28 = sub_0802FFDC;
    }
}

void sub_0802FFDC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags = b->unk2C;

    if (flags & 8) {
        b->unk0.animId = 0x185;
        b->unk0.variant = 2;
        b->unk0.unk1B = 0xFF;
        flags &= ~8;
        flags |= 0x10;
        b->unk2C = flags;
        b->unk3A = 0xFE00;
        b->unk28 = sub_0802F40C;
    }
}

void sub_08030018(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    b->unk2C |= 2;
}

void sub_08030024(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags = b->unk2C;

    if (flags & 8) {
        u8 v = 0;

        b->unk0.animId = 7;
        b->unk0.variant = v;
        b->unk0.unk1B = 0xFF;
        flags &= ~8;
        flags |= 0x10;
        flags |= 0x20;
        b->unk2C = flags;
        b->unk28 = sub_0803005C;
    }
}

void sub_0803005C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    b->unk2C |= 2;
}

void sub_08030068(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;
    UnkCFunc2 f;

    b->unk0.animId = 4;
    b->unk0.variant = 2;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags |= 0x10;
    b->unk2C = flags;
    b->unk48 = 0;
    f = sub_0802F5B8;
    b->unk28 = f;
    f(a, b);
}

void sub_080300A0(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;
    UnkCFunc2 f;

    b->unk0.animId = 4;
    b->unk0.variant = 3;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    f = sub_0802F638;
    b->unk28 = f;
    f(a, b);
}

void sub_080300CC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    if (b->unk2C & 0x40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w asm("r0");
#else
        s32 w;
#endif

        b->unk3A = sum;
        if ((s16)sum < -0x150) {
            w = -0x150;
        } else {
            w = sum;
            if ((s16)sum > 0x280) {
                w = 0x280;
            }
        }
        b->unk3A = w;
    } else {
        b->unk28 = sub_0803017C;
    }
}

void sub_0803010C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;
    UnkCFunc2 f;

    b->unk0.animId = 0;
    b->unk0.variant = 1;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    f = sub_08030138;
    b->unk28 = f;
    f(a, b);
}

void sub_08030138(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    if (b->unk38 > 0) {
        b->unk38 -= 0xE;
        if (b->unk38 < 0) {
            b->unk38 = 0;
        }
    } else if (b->unk38 < 0) {
        b->unk38 += 0xE;
        if (b->unk38 > 0) {
            b->unk38 = 0;
        }
    }
    if (b->unk2C & 8) {
        b->unk28 = sub_080301DC;
    }
}

void sub_0803017C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;
    UnkCFunc2 f;

    b->unk0.animId = 4;
    b->unk0.variant = 5;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    b->unk3A = 0xFE00;
    f = sub_0802F6A0;
    b->unk28 = f;
    f(a, b);
}

void sub_080301B0(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u32 flags;
    UnkCFunc2 f;

    b->unk0.animId = 4;
    b->unk0.variant = 2;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags &= ~0x10;
    b->unk2C = flags;
    f = sub_0802F714;
    b->unk28 = f;
    f(a, b);
}

void sub_080301DC(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    u8 v = 0;
    u32 flags;
    UnkCFunc2 f;

#ifndef NONMATCHING
    asm("" : "+r"(v));
#endif
    b->unk0.animId = 0;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    flags = b->unk2C;
    flags &= ~8;
    flags |= 0x10;
    flags &= ~0x20;
    b->unk2C = flags;
    f = sub_0803020C;
    b->unk28 = f;
    f(a, b);
}

void sub_0803020C(struct Unk_0802E57C *a, struct Unk_0802F8D8_C *b) {
    if (b->unk38 > 0) {
        b->unk38 -= 0xE;
        if (b->unk38 < 0) {
            b->unk38 = 0;
        }
    } else if (b->unk38 < 0) {
        b->unk38 += 0xE;
        if (b->unk38 > 0) {
            b->unk38 = 0;
        }
    }
    if (b->unk38 == 0) {
        b->unk2C |= 2;
    }
}
