#include "global.h"
#include "portable.h"
#include "code_0802E57C.h"
#include "main.h"
#include "malloc_vram.h"
#include "random.h"
#include "sprite.h"
#include "task.h"
#include "gba/m4a.h"

struct Unk_0802E57C_Vec {
    s16 x;
    s16 y;
};

extern s16 gUnk_082EB6DC[];
extern u32 gUnk_082EB6EC[];
extern s16 gUnk_082EB6FC[];
extern const struct Unk_0802E57C_174 gUnk_082EB700[];
extern const struct Unk_0802E57C_174 gUnk_082EB740[];
extern const UnkCFunc2 gUnk_082EB7D0[];
extern u16 gUnk_082EB7F8[];
extern u16 gUnk_082EB954[];
extern u8 gUnk_082EB984[];
extern u16 *gUnk_08D60B24[];

void sub_0802F8D8(struct Unk_0802E57C *, u16, u16, u32, s32, s32, s16, s16, u16);
void sub_0802FA40(struct Unk_0802E57C *, u16, u16, u32, s32, s32, s16, s16, u16);

struct Unk_0802E57C *sub_0802E57C(void) {
    struct Task *t = TaskCreate(sub_0802E78C, sizeof(struct Unk_0802E57C), 0x100, 0, sub_0802E71C);
    struct Unk_0802E57C *tmp = TaskGetStructPtr(t), *x = tmp;
    struct Sprite *s;
    u16 i;

    CpuFill16(0, x, sizeof(struct Unk_0802E57C));
    x->unk0 = t;
    x->unk4 = sub_0802FD3C;
    gDispCnt |= 0x1040;
    s = &x->unk14C;
    s->tilesVram = VramMalloc(0x10);
    s->unk14 = 0x280;
    s->animId = 0x2DE;
    s->variant = 0;
    s->unk16 = 0;
    s->unk1B = 0xFF;
    s->unk1C = 0x10;
    s->palId = 0xB;
    s->x = 0;
    s->y = 0;
    s->unk8 = 0;
    for (i = 0; i < 4; i++) {
        struct Unk_0802E57C_C *c = &x->unkC[i];
        struct Sprite *cs = &c->unk0;

        cs->tilesVram = 0;
        cs->unk14 = 0x100;
        cs->animId = 0x15;
        cs->variant = i;
        cs->unk16 = 0;
        cs->unk1B |= 0xFF;
        cs->unk1C = 0x10;
        cs->palId = i + 0xC;
        cs->x = 0;
        cs->y = 0;
        cs->unk8 = 0x80000;
        sub_08155128(cs);
        cs->tilesVram = VramMalloc(0x10);
        cs->unk14 = 0x100;
        cs->animId = 0;
        cs->variant = 0;
        cs->unk16 = 0;
        cs->unk1B |= 0xFF;
        cs->unk1C = 0x10;
        cs->palId = i + 0xC;
        cs->x = 0;
        cs->y = 0;
        cs->unk8 = 0x40000;
        c->unk2C |= 4;
        c->unk46 = i;
    }
    return x;
}

void sub_0802E6C4(struct Unk_0802E57C *x) {
    struct Sprite s;

    x->unk4 = sub_0802EA4C;
    if (x->unk8 == 0) {
        s.tilesVram = x->unk8 = VramMalloc(0x100);
        s.unk14 = 0;
        s.animId = 0x292;
        s.variant = 0;
        s.unk16 = 0;
        s.unk1B = 0xFF;
        s.unk1C = 0x10;
        s.palId = 0xB;
        s.x = 0;
        s.y = 0;
        s.unk8 = 0;
        sub_08155128(&s);
    }
}

void sub_0802E71C(struct Task *t) {
    struct Unk_0802E57C *tmp = TaskGetStructPtr(t), *x = tmp;
    struct Unk_0802E57C_C *c;
    struct Sprite *s;
    u16 i;

#ifndef NONMATCHING
    ASM_INOUT_R(x);
#endif
    if (x->unk8 != 0) {
        VramFree(x->unk8);
        x->unk8 = 0;
    }
    s = &x->unk14C;
    if (s->tilesVram != 0) {
        VramFree(s->tilesVram);
        s->tilesVram = 0;
    }
    i = 0;
    c = tmp->unkC;
    for (; i < 4; i++) {
        struct Unk_0802E57C_C *e = &c[i];

        if (e->unk0.tilesVram != 0) {
            VramFree(e->unk0.tilesVram);
            e->unk0.tilesVram = 0;
        }
    }
}

void sub_0802E78C(void) {
    struct Unk_0802E57C *tmp = TaskGetStructPtr(gCurTask), *x = tmp;
    u32 *p = &x->unk188;
    u32 v = *p;

    if (!(v & 0x40000000)) {
        if ((v & 0x100) && !(x->unk18C & 0xF)) {
            u32 idx = Rand16() & 0x1F;
            u32 dur = (Rand16() & 0xF) + 0x32;
            s16 v1[2] = { -x->unk180, -x->unk182 };
#ifndef NONMATCHING
            volatile s32 x2, y2;
            register u32 diff ASM_PIN("r0");
            register u32 diff2 ASM_PIN("r1");
            register s32 t ASM_PIN("r0");
            register s32 ty ASM_PIN("r4");
#else
            s32 x2, y2;
            u32 diff, diff2;
            s32 t, ty;
#endif
            u16 animId, variant;

            t = x->unk178 + (((Rand16() & 0xF) - 8) << 8);
            x2 = t;
            t = x->unk17C + (((Rand16() & 0xF) - 8) << 8);
            y2 = t;

            if (v1[0] > v1[1]) {
                diff = (u16)(v1[0] - v1[1]);
            } else {
                diff = (u16)(v1[1] - v1[0]);
            }
            diff2 = diff;
            if ((s16)diff < 0) {
                diff = 0;
#ifndef NONMATCHING
                ASM_USE_R(diff);
#endif
                diff2 = diff;
            }
            if (diff2 <= 0xFF) {
                v1[0] = 0;
                v1[1] = 0x80;
            } else {
#ifndef NONMATCHING
                register s32 w ASM_PIN("r0");
#else
                s32 w;
#endif
                {
                    s16 *q = v1;
                    s16 *p = q;
                    u16 uvx;
                    s16 svx;
#ifndef NONMATCHING
                    ASM_INOUT_R(p);
#endif
                    uvx = *p;
                    svx = *p;
                    if (svx < -0x400) {
                        w = -0x400;
                    } else {
                        w = uvx;
                        if (svx > 0x400) {
                            w = 0x400;
                        }
                    }
                    *q = w;
                }
                {
                    s16 *q = v1;
                    s16 *p = q;
#ifndef NONMATCHING
                    register u32 uvy ASM_PIN("r1");
                    register s32 svy ASM_PIN("r2");
                    ASM_INOUT_R(p);
#else
                    u32 uvy;
                    s32 svy;
#endif
                    uvy = (u16)p[1];
#ifndef NONMATCHING
                    ASM_INOUT_R(uvy);
#endif
                    t = uvy << 16;
                    svy = t >> 16;
                    if (svy < -0x400) {
                        w = -0x400;
                    } else {
                        w = uvy;
                        if (svy > 0x400) {
                            w = 0x400;
                        }
                    }
                    q[1] = w;
                }
            }
            animId = gUnk_082EB954[gUnk_082EB984[idx] * 2];
            variant = (gUnk_082EB954 + 1)[gUnk_082EB984[idx] * 2];
            sub_0802F8D8(x, animId, variant, x->unk8, x2, (ty = y2), v1[0], v1[1], dur);
        }
        x->unk4(x);
        x->unk18C++;
    } else {
        if ((s32)v < 0) {
            TaskDestroy(gCurTask);
        } else {
            *p = v | 0xA0000000;
        }
    }
}

void sub_0802E97C(struct Unk_0802E57C *x) {
    u16 i;

    for (i = 0; i < 4; i++) {
        struct Unk_0802E57C_C *c = &x->unkC[i];

        if (c->unk2C & 2) {
            c->unk40++;
            if ((c->unk3C[c->unk40 * 2] & c->unk3C[c->unk40 * 2 + 1]) == 0xFFFF) {
                c->unk3C = gUnk_08D60B24[Rand16() & 7];
                c->unk40 = 0;
            }
            c->unk2C &= ~2;
            c->unk42 = c->unk3C[c->unk40 * 2];
            c->unk44 = c->unk3C[c->unk40 * 2 + 1];
            c->unk28 = gUnk_082EB7D0[c->unk42];
        }
        sub_0802EF90(x, c);
    }
}

void sub_0802EA4C(struct Unk_0802E57C *x) {
    u16 i;
    struct Sprite *s;
    void (*f)(struct Unk_0802E57C *);

    x->unk178 = gUnk_082EB6FC[0] << 8;
    x->unk17C = gUnk_082EB6FC[1] << 8;
    s = &x->unk14C;
    s->animId = 0x2DE;
    s->variant = 0;
    s->unk1B = 0xFF;
    for (i = 0; i < 4; i++) {
        struct Unk_0802E57C_C *c = &x->unkC[i];
        u32 f2;

        c->unk0.animId = 4;
        c->unk0.variant = 0;
        c->unk0.unk1B = 0xFF;
        f2 = c->unk2C;
        f2 &= ~8;
        f2 &= ~0x10;
        c->unk2C = f2;
        c->unk3C = gUnk_082EB7F8;
        c->unk40 = 0;
        c->unk42 = 0;
        c->unk44 = 0;
        switch (i) {
        case 0:
            c->unk2C &= ~1;
            c->unk30 = x->unk178 - 0x1400;
            c->unk34 = 0x8000;
            c->unk38 = 0x40;
            c->unk3A = -0x400;
            break;
        case 1:
            c->unk2C |= 1;
            c->unk30 = x->unk178 + 0x1400;
            c->unk34 = 0x8000;
            c->unk38 = -0x40;
            c->unk3A = -0x400;
            break;
        case 2:
            c->unk2C |= 1;
            c->unk30 = x->unk178 + 0x2800;
            c->unk34 = 0x8000;
            c->unk38 = -0xC0;
            c->unk3A = -0x400;
            break;
        case 3:
            c->unk2C &= ~1;
            c->unk30 = x->unk178 - 0x2800;
            c->unk34 = 0x8000;
            c->unk38 = 0xC0;
            c->unk3A = -0x400;
            break;
        }
        c->unk28 = sub_0802FC08;
    }
    x->unk188 |= 0x100;
    f = sub_0802EBB0;
    x->unk4 = f;
    f(x);
}

void sub_0802EBB0(struct Unk_0802E57C *x) {
    u16 i;
    s16 *p;
    struct Sprite *s = &x->unk14C;

    if (sub_08155128(s) == 0) {
        s->unk1B = 0xFF;
    }
    s->x = x->unk178 >> 8;
    s->y = x->unk17C >> 8;
    sub_0815604C(s);
    i = 0;
    p = &x->unkC[0].unk3A;
    for (; i < 4; i++) {
        x->unkC[i].unk3A += 0x26;
        sub_0802EF90(x, &x->unkC[i]);
    }
    if (*p >= -0x10) {
        for (i = 0; i < 4; i++) {
            struct Unk_0802E57C_C *c = &x->unkC[i];
            u32 f;
            u16 z = 0;
            u8 ff = 0xFF;

            c->unk0.animId = 0x2D;
            c->unk0.variant = i;
            {
                u8 tb = c->unk0.unk1B;

                tb |= ff;
                c->unk0.unk1B = tb;
            }
            f = c->unk2C;
            f &= ~8;
            f |= 0x10;
            c->unk2C = f;
            c->unk30 = x->unk178;
            c->unk34 = x->unk17C;
            c->unk38 = z;
            c->unk3A = z;
            f &= ~1;
            f |= 0x80;
            c->unk2C = f;
        }
        sub_0802FA40(x, 0x292, 0, x->unk8, x->unk178, x->unk17C, 0, 0, 1);
        m4aSongNumStart(0x7E);
        x->unk4 = sub_0802FE30;
    }
}

void sub_0802ECBC(struct Unk_0802E57C *x) {
    u16 i;
    struct Sprite *s = &x->unk14C;

    if (sub_08155128(s) == 0) {
        s->unk1B = 0xFF;
    }
    s->x = x->unk178 >> 8;
    s->y = x->unk17C >> 8;
    sub_0815604C(s);
    for (i = 0; i < 4; i++) {
        struct Unk_0802E57C_C *c = &x->unkC[i];

        c->unk30 = x->unk178;
        c->unk34 = x->unk17C;
        sub_0802EF90(x, c);
    }
    if (x->unk190++ > 0x1E) {
        x->unk4 = sub_0802ED44;
    }
}

void sub_0802ED44(struct Unk_0802E57C *x) {
    u16 i;
    struct Sprite *s = &x->unk14C;

    if (sub_08155128(s) == 0) {
        s->unk1B = 0xFF;
    }
    s->x = x->unk178 >> 8;
    s->y = x->unk17C >> 8;
    sub_0815604C(s);
    for (i = 0; i < 4; i++) {
        struct Unk_0802E57C_C *c = &x->unkC[i];

        c->unk30 = x->unk178;
        c->unk34 = x->unk17C;
        sub_0802EF90(x, c);
    }
    if (x->unk188 & 0x200) {
        x->unk4 = sub_0802EDC8;
    }
}

void sub_0802EDC8(struct Unk_0802E57C *x) {
    void (*f)(struct Unk_0802E57C *);

    if (gUnk_03002558 == 1) {
        x->unk174 = gUnk_082EB740;
    } else {
        x->unk174 = gUnk_082EB700;
    }
    x->unk184 = 1;
    x->unk186 = 0;
    x->unk180 = x->unk174->unk0;
    x->unk182 = x->unk174->unk2;
    if (gUnk_03002558 == 1) {
        m4aSongNumStart(0x206);
    } else {
        m4aSongNumStart(0x208);
    }
    f = sub_0802EE54;
    x->unk4 = f;
    f(x);
}

void sub_0802EE54(struct Unk_0802E57C *x) {
    u16 idx = x->unk184;
    const struct Unk_0802E57C_174 *tbl = x->unk174;
    const struct Unk_0802E57C_174 *entry = (const struct Unk_0802E57C_174 *)(idx * 8 + (u32)tbl);

    if ((entry->unk6 & 1) || x->unk178 < -0x4000 || x->unk178 > 0x13000 || x->unk17C < -0x4000
        || x->unk17C > 0xE000) {
        x->unk188 &= ~0x100;
        x->unk4 = sub_0802FE4C;
    } else {
        u16 i;
        struct Sprite *s;

        if (entry->unk4 < x->unk186++) {
            x->unk186 = 0;
            x->unk184++;
        }
        x->unk180 += x->unk174[x->unk184].unk0;
        x->unk182 += x->unk174[x->unk184].unk2;
        x->unk178 += (s16)x->unk180;
        x->unk17C += (s16)x->unk182;
        s = &x->unk14C;
        if (sub_08155128(s) == 0) {
            s->unk1B = 0xFF;
        }
        s->x = x->unk178 >> 8;
        s->y = x->unk17C >> 8;
        sub_0815604C(s);
        for (i = 0; i < 4; i++) {
            struct Unk_0802E57C_C *c = &x->unkC[i];

            c->unk30 = x->unk178;
            c->unk34 = x->unk17C;
            sub_0802EF90(x, c);
        }
    }
}

void sub_0802EF90(struct Unk_0802E57C *x, struct Unk_0802E57C_C *c) {
    c->unk30 += c->unk38;
    c->unk34 += c->unk3A;
    if (!(c->unk2C & 0x80)) {
        if (c->unk30 < -0x8000) {
            c->unk30 = -0x8000;
        } else if (c->unk30 > 0x17000) {
            c->unk30 = 0x17000;
        }
        if (c->unk34 > 0x7FFF) {
            c->unk2C &= ~0x40;
            c->unk34 = 0x8000;
            c->unk3A = 0;
        } else {
            c->unk2C |= 0x40;
            if (c->unk34 < -0x8000) {
                c->unk34 = -0x8000;
            }
        }
    }
    c->unk28(x, c);
    {
        struct Unk_0802E57C_C *c2 = c;

        if (c2->unk2C & 1) {
            c2->unk0.unk8 |= 0x400;
        } else {
            c2->unk0.unk8 &= ~0x400;
        }
        if (sub_08155128(&c2->unk0) == 0) {
            c->unk2C |= 8;
        } else {
            c->unk2C &= ~8;
        }
        {
            u32 f = c->unk2C;

            if (f & 8) {
                if (f & 0x10) {
                    c2->unk0.unk1B = 0xFF;
                    x->unk188 &= ~8;
                }
            }
        }
        c2->unk0.x = c->unk30 >> 8;
        c2->unk0.y = c->unk34 >> 8;
        sub_0815604C(&c2->unk0);
    }
}

void sub_0802F088(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u8 v = 0;
    u32 f;

    b->unk0.animId = 2;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    f = b->unk2C;
    f &= ~8;
    f |= 0x10;
    b->unk2C = f;
    b->unk30 = gUnk_082EB6DC[b->unk46 * 2] << 8;
    b->unk34 = (gUnk_082EB6DC + 1)[b->unk46 * 2] << 8;
    if (gUnk_082EB6EC[b->unk46] != 0) {
        f |= 1;
    } else {
        f &= ~1;
    }
    b->unk2C = f;
    b->unk48 = 0;
    b->unk4A = 0;
    b->unk28 = sub_0802F110;
}

void sub_0802F110(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    if (b->unk48 > 0x50) {
        if (b->unk4A == 0) {
            u8 v = 0;
            u32 f;

            b->unk0.animId = 0x33;
            b->unk0.variant = v;
            b->unk0.unk1B = 0xFF;
            f = b->unk2C;
            f &= ~8;
            f |= 0x10;
            b->unk2C = f;
            b->unk4A = 1;
        }
        if (b->unk38 > 0) {
            b->unk38 -= 0x20;
            if (b->unk38 < 0) {
                b->unk38 = 0;
            }
        } else if (b->unk38 < 0) {
            b->unk38 += 0x20;
            if (b->unk38 > 0) {
                b->unk38 = 0;
            }
        }
        if (b->unk38 == 0) {
            b->unk2C |= 2;
        }
    } else {
        if (b->unk2C & 1) {
            b->unk38 -= 0x20;
        } else {
            b->unk38 += 0x20;
        }
        {
            u16 uv = b->unk38;
            s16 sv = b->unk38;
#ifndef NONMATCHING
            register s32 w ASM_PIN("r0");
#else
            s32 w;
#endif
            if (sv < -0x1DC) {
                w = -0x1DC;
            } else {
                w = uv;
                if (sv > 0x1DC) {
                    w = 0x1DC;
                }
            }
            b->unk38 = w;
        }
        b->unk48++;
    }
}

void sub_0802F1C4(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u8 v = 0;
    u32 f;

    b->unk0.animId = 1;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    f = b->unk2C;
    f &= ~8;
    f |= 0x10;
    b->unk2C = f;
    if (b->unk30 <= 0x4FFF) {
        f &= ~1;
        b->unk2C = f;
    } else if (b->unk30 > 0xA000) {
        f |= 1;
        b->unk2C = f;
    }
    b->unk34 = 0x8000;
    b->unk48 = Rand16() & 0x1F;
    b->unk28 = sub_0802F240;
}

void sub_0802F240(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    if (b->unk44 < b->unk48) {
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
    } else {
        if (b->unk2C & 1) {
            b->unk38 -= 0x20;
        } else {
            b->unk38 += 0x20;
        }
        {
            u16 uv = b->unk38;
            s16 sv = b->unk38;
#ifndef NONMATCHING
            register s32 w ASM_PIN("r0");
#else
            s32 w;
#endif
            if (sv < -0x14C) {
                w = -0x14C;
            } else {
                w = uv;
                if (sv > 0x14C) {
                    w = 0x14C;
                }
            }
            b->unk38 = w;
        }
        b->unk48++;
    }
}

void sub_0802F2D0(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u8 v = 0;
    u32 f;

    b->unk0.animId = 2;
    b->unk0.variant = v;
    b->unk0.unk1B = 0xFF;
    f = b->unk2C;
    f &= ~8;
    f |= 0x10;
    b->unk2C = f;
    if (b->unk30 <= 0x4FFF) {
        f &= ~1;
        b->unk2C = f;
    } else if (b->unk30 > 0xA000) {
        f |= 1;
        b->unk2C = f;
    }
    b->unk34 = 0x8000;
    b->unk48 = Rand16() & 0x1F;
    b->unk4A = 0;
    b->unk28 = sub_0802F354;
}

void sub_0802F354(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    if (b->unk44 < b->unk48) {
        if (b->unk4A == 0) {
            u8 v = 0;
            u32 f;

            b->unk0.animId = 0x33;
            b->unk0.variant = v;
            b->unk0.unk1B = 0xFF;
            f = b->unk2C;
            f &= ~8;
            f |= 0x10;
            b->unk2C = f;
            b->unk4A = 1;
        }
        if (b->unk38 > 0) {
            b->unk38 -= 0x20;
            if (b->unk38 < 0) {
                b->unk38 = 0;
            }
        } else if (b->unk38 < 0) {
            b->unk38 += 0x20;
            if (b->unk38 > 0) {
                b->unk38 = 0;
            }
        }
        if (b->unk38 == 0) {
            b->unk2C |= 2;
        }
    } else {
        if (b->unk2C & 1) {
            b->unk38 -= 0x20;
        } else {
            b->unk38 += 0x20;
        }
        {
            u16 uv = b->unk38;
            s16 sv = b->unk38;
#ifndef NONMATCHING
            register s32 w ASM_PIN("r0");
#else
            s32 w;
#endif
            if (sv < -0x1DC) {
                w = -0x1DC;
            } else {
                w = uv;
                if (sv > 0x1DC) {
                    w = 0x1DC;
                }
            }
            b->unk38 = w;
        }
        b->unk48++;
    }
}

void sub_0802F40C(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u16 old = b->unk3A;
    s32 sum = old + 0x26;
#ifndef NONMATCHING
    register s32 w ASM_PIN("r0");
#else
    s32 w;
#endif

    b->unk3A = sum;
    if ((s16)sum < -0x280) {
        w = -0x280;
    } else {
        w = sum;
        if ((s16)sum > 0x280) {
            w = 0x280;
        }
    }
    b->unk3A = w;
    if ((s16)w >= 0) {
        u32 f;

        b->unk0.animId = 0x185;
        b->unk0.variant = 3;
        b->unk0.unk1B = 0xFF;
        f = b->unk2C;
        f &= ~8;
        f &= ~0x10;
        b->unk2C = f;
        b->unk28 = sub_0802F464;
    }
}

void sub_0802F464(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u32 f = b->unk2C;

    if (f & 0x40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w ASM_PIN("r0");
#else
        s32 w;
#endif

        b->unk3A = sum;
        if ((s16)sum < -0x280) {
            w = -0x280;
        } else {
            w = sum;
            if ((s16)sum > 0x280) {
                w = 0x280;
            }
        }
        b->unk3A = w;
    } else {
        u8 v = 0;

        b->unk0.animId = 0;
        b->unk0.variant = v;
        b->unk0.unk1B = 0xFF;
        f &= ~8;
        f |= 0x10;
        b->unk2C = f;
        b->unk28 = sub_08030018;
    }
}

void sub_0802F4BC(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u32 f;

    b->unk0.animId = 6;
    b->unk0.variant = 5;
    b->unk0.unk1B = 0xFF;
    f = b->unk2C;
    f &= ~8;
    f &= ~0x10;
    b->unk2C = f;
    if (b->unk30 <= 0x4FFF) {
        f &= ~1;
        b->unk2C = f;
    } else if (b->unk30 > 0xA000) {
        f |= 1;
        b->unk2C = f;
    }
    b->unk34 = 0x8000;
    b->unk48 = 0;
    b->unk4A = 0;
    b->unk28 = sub_08030024;
}

void sub_0802F51C(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u32 t40;
    u32 f;

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
    t40 = b->unk2C & 0x40;
    f = b->unk2C;
    if (t40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w ASM_PIN("r0");
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
    }
    if (f & 8) {
        u8 v = 0;
        u32 g;

        b->unk0.animId = 7;
        b->unk0.variant = v;
        b->unk0.unk1B = 0xFF;
        g = f & ~8;
        g |= 0x10;
        b->unk2C = g;
        if (g & 0x40) {
            b->unk28 = sub_08030068;
        } else {
            b->unk28 = sub_080301DC;
        }
    }
}

void sub_0802F5B8(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
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
    if (b->unk2C & 0x40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w ASM_PIN("r0");
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
        if (b->unk48++ > 0x1E) {
            b->unk28 = sub_080300A0;
        }
    } else {
        b->unk28 = sub_0803010C;
    }
}

void sub_0802F638(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    if (b->unk2C & 0x40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w ASM_PIN("r0");
        register u32 f ASM_PIN("r2");
#else
        s32 w;
        u32 f;
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
        f = b->unk2C;
        if (f & 8) {
            u8 v = 4;

#ifndef NONMATCHING
            ASM_INOUT_R(v);
#endif
            b->unk0.animId = 4;
            b->unk0.variant = v;
            b->unk0.unk1B = 0xFF;
            f &= ~8;
            f &= ~0x10;
            b->unk2C = f;
            b->unk28 = sub_080300CC;
        }
    } else {
        b->unk28 = sub_0803017C;
    }
}

void sub_0802F6A0(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u32 t40;
    u32 f;

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
    t40 = b->unk2C & 0x40;
    f = b->unk2C;
    if (t40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w ASM_PIN("r0");
#else
        s32 w;
#endif

        b->unk3A = sum;
        if ((s16)sum < -0x280) {
            w = -0x280;
        } else {
            w = sum;
            if ((s16)sum > 0x280) {
                w = 0x280;
            }
        }
        b->unk3A = w;
    }
    if (f & 8) {
        b->unk28 = sub_080301B0;
    }
}

void sub_0802F714(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
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
    if (b->unk2C & 0x40) {
        u16 old = b->unk3A;
        s32 sum = old + 0x26;
#ifndef NONMATCHING
        register s32 w ASM_PIN("r0");
#else
        s32 w;
#endif

        b->unk3A = sum;
        if ((s16)sum < -0x280) {
            w = -0x280;
        } else {
            w = sum;
            if ((s16)sum > 0x280) {
                w = 0x280;
            }
        }
        b->unk3A = w;
    } else {
        b->unk28 = sub_0803010C;
    }
}

void sub_0802F77C(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    u16 v = (u32)(b->unk34 << 4) >> 16;
    u16 r = Rand16() & 7;
    UnkCFunc2 f2;

    b->unk4A = r;
    if (v >= r) {
        b->unk0.animId = 7;
        b->unk0.variant = 0;
    } else {
        b->unk0.animId = 7;
        b->unk0.variant = 1;
    }
    b->unk0.unk1B = 0xFF;
    b->unk2C = (b->unk2C & ~8) | 0x10;
#ifndef NONMATCHING
    ASM_CLOBBER_MEM();
#endif
    if (b->unk30 <= 0x4FFF) {
        b->unk2C &= ~1;
    } else if (b->unk30 > 0xA000) {
        b->unk2C |= 1;
    }
    f2 = sub_0802F810;
    b->unk28 = f2;
    f2(a, b);
}

void sub_0802F810(struct Unk_0802E57C *a, struct Unk_0802E57C_C *b) {
    if (b->unk44 < b->unk48) {
        b->unk2C |= 2;
    } else {
        u16 v = (u32)(b->unk34 << 4) >> 16;
        u16 old = b->unk3A;
        s32 sum = old + 0x16;

        b->unk3A = sum;
        {
#ifndef NONMATCHING
            register s32 t ASM_PIN("r0");
            register s32 sv ASM_PIN("r4");
            register s32 mx ASM_PIN("r3");
#else
            s32 t, sv, mx;
#endif
            t = sum << 16;
            sv = t >> 16;
            if (sv >= -0x150) {
                mx = 0x120;
                if (sv > mx) {
                    sum = mx;
                }
            } else {
                sum = -0x150;
            }
        }
        b->unk3A = sum;
        if (v >= b->unk4A) {
#ifndef NONMATCHING
            register s32 w ASM_PIN("r0");
#else
            s32 w;
#endif
            sum -= 0x78;
            b->unk3A = sum;
            if ((s16)sum < -0x150) {
                w = -0x150;
            } else {
                w = sum;
                if ((s16)sum > 0x120) {
                    w = 0x120;
                }
            }
            b->unk3A = w;
        }
        if (b->unk2C & 1) {
            b->unk38 -= 0x16;
        } else {
            b->unk38 += 0x16;
        }
        {
            u16 uv = b->unk38;
            s16 sv = b->unk38;
#ifndef NONMATCHING
            register s32 w2 ASM_PIN("r0");
#else
            s32 w2;
#endif
            if (sv < -0x110) {
                w2 = -0x110;
            } else {
                w2 = uv;
                if (sv > 0x110) {
                    w2 = 0x110;
                }
            }
            b->unk38 = w2;
        }
        if (v == b->unk4A) {
            b->unk28 = sub_0802F77C;
        }
        b->unk48++;
    }
}
