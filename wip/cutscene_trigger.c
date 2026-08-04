#include "global.h"
#include "data.h"
#include "object.h"
#include "functions.h"
#include "task.h"
#include "kirby.h"
#include "random.h"
#include "main.h"
#include "save.h"
#include "multi_08030C94.h"
#include "code_0806F780.h"
#include "trig.h"
#include "constants/songs.h"

union CutsceneVal {
    struct Object2 *obj;
    struct Object4 *obj4;
    struct Unk_02022930_0 *u0;
    s16 s[2];
    u16 h[2];
    u8 b[4];
};

struct CutsceneTrigger {
    /* 0x000 */ struct Object2 obj2;
    /* 0x0B4 */ union CutsceneVal unkB4;
    /* 0x0B8 */ union CutsceneVal unkB8;
    /* 0x0BC */ union CutsceneVal unkBC;
    /* 0x0C0 */ union CutsceneVal unkC0;
    /* 0x0C4 */ union CutsceneVal unkC4;
    /* 0x0C8 */ union { struct Object4 *obj4; s16 s; u16 h; u8 b[4]; s8 sb[4]; } unkC8;
    /* 0x0CC */ u16 unkCC;
    /* 0x0CE */ u16 unkCE;
    /* 0x0D0 */ u16 unkD0;
    /* 0x0D2 */ u16 unkD2;
    /* 0x0D4 */ u16 unkD4;
    /* 0x0D6 */ u8 fillerD6[8];
    /* 0x0DE */ u8 unkDE[4];
    /* 0x0E2 */ u8 unkE2[4];
    /* 0x0E6 */ s16 unkE6;
    /* 0x0E8 */ s16 unkE8;
    /* 0x0EA */ u8 fillerEA[0x1AA];
    /* 0x294 */ struct Object4 *unk294[4];
    /* 0x2A4 */ u16 unk2A4[4];
    /* 0x2AC */ u8 filler2AC[8];
    /* 0x2B4 */ u16 unk2B4;
    /* 0x2B6 */ u16 unk2B6;
}; /* size = 0x2B8 */

extern const u16 gUnk_082DE9FC[];
extern const u16 gUnk_082DEA24[];
extern const s16 gUnk_082DEA4C[];
extern const s16 gUnk_082DEA4E[];
extern const s16 gUnk_082DEA5C[];
extern const s16 gUnk_082DEA5E[];

void sub_08020798(struct CutsceneTrigger *);
void sub_0802084C(struct CutsceneTrigger *);
void sub_08020A90(struct CutsceneTrigger *);
void sub_08020DDC(struct CutsceneTrigger *);
void sub_08020FA8(struct CutsceneTrigger *);
void sub_0802114C(struct CutsceneTrigger *);
void sub_080212C0(struct CutsceneTrigger *);
void sub_08021360(struct CutsceneTrigger *);
void sub_08021424(struct CutsceneTrigger *);
void sub_080214E4(struct CutsceneTrigger *);
void sub_080215B4(struct CutsceneTrigger *);
void sub_08021634(struct CutsceneTrigger *);
void sub_0802172C(struct CutsceneTrigger *);
void sub_08021844(struct CutsceneTrigger *);
void sub_08021984(struct CutsceneTrigger *);
void sub_08021DD4(struct Task *);
void sub_08021EB0(struct CutsceneTrigger *);
void sub_08022090(struct CutsceneTrigger *);
void sub_08022104(struct CutsceneTrigger *);
void sub_08022174(struct CutsceneTrigger *);
void sub_08022350(struct CutsceneTrigger *);
void sub_0802262C(struct CutsceneTrigger *);
void sub_080226C4(struct CutsceneTrigger *);
void sub_08022770(struct CutsceneTrigger *);
void sub_080229E4(struct CutsceneTrigger *);
void sub_08022A90(struct CutsceneTrigger *);
void sub_08022B74(struct CutsceneTrigger *);
void sub_08022C9C(struct CutsceneTrigger *);
void sub_08022D78(struct CutsceneTrigger *);
void sub_08022DE4(struct CutsceneTrigger *);
void sub_08022E6C(struct CutsceneTrigger *);
void sub_08022E80(struct CutsceneTrigger *);
void sub_08022EA0(struct CutsceneTrigger *);
void sub_08022EB4(struct CutsceneTrigger *);
void sub_08022ECC(struct CutsceneTrigger *);
void sub_08022EE0(struct CutsceneTrigger *);
void sub_08022EF8(struct CutsceneTrigger *);
void sub_08022F0C(struct CutsceneTrigger *);
void sub_08022F24(struct CutsceneTrigger *);
void sub_08022F50(struct CutsceneTrigger *);
void sub_08022F64(struct CutsceneTrigger *);
void sub_08022F88(struct CutsceneTrigger *);
void sub_08022FB8(struct CutsceneTrigger *);
void sub_08022FDC(struct CutsceneTrigger *);
void sub_08023030(struct CutsceneTrigger *);
void sub_08023054(struct CutsceneTrigger *);
void sub_08023068(struct CutsceneTrigger *);
void sub_080230A0(struct CutsceneTrigger *);
void sub_080230DC(struct CutsceneTrigger *);
void sub_08023100(struct CutsceneTrigger *);
void sub_08023154(struct CutsceneTrigger *);
void sub_08023168(struct CutsceneTrigger *);
void sub_0802318C(struct CutsceneTrigger *);
void sub_080231C0(struct CutsceneTrigger *);
void sub_08023238(struct CutsceneTrigger *);
void sub_08023268(struct CutsceneTrigger *);
void sub_0802327C(struct CutsceneTrigger *);
void sub_080232A0(struct CutsceneTrigger *);
void sub_080232BC(struct CutsceneTrigger *);
void sub_080232E4(struct CutsceneTrigger *);
void sub_080232F8(struct CutsceneTrigger *);
void sub_0802331C(struct CutsceneTrigger *);
void sub_08023368(struct CutsceneTrigger *);
void sub_08023394(struct CutsceneTrigger *);
void sub_080233A8(struct CutsceneTrigger *);
void sub_080233E0(struct CutsceneTrigger *);
void sub_08023414(struct CutsceneTrigger *);
void nullsub_113(struct CutsceneTrigger *);
void sub_08023438(struct CutsceneTrigger *);
void sub_0802347C(struct CutsceneTrigger *);
void sub_080234C4(struct CutsceneTrigger *);
void sub_080234E4(struct CutsceneTrigger *);
void sub_08023504(struct CutsceneTrigger *);
void sub_08023524(struct CutsceneTrigger *);
void sub_08023544(struct CutsceneTrigger *);
void sub_0802356C(struct CutsceneTrigger *);
void sub_08023580(struct CutsceneTrigger *);
void sub_08023594(struct CutsceneTrigger *);
void sub_080235BC(struct CutsceneTrigger *);
void sub_0802360C(struct CutsceneTrigger *);
void sub_08023644(struct CutsceneTrigger *);
void sub_08023664(struct CutsceneTrigger *);
void sub_08023698(struct CutsceneTrigger *);
void sub_080236CC(struct CutsceneTrigger *);
void sub_080236EC(struct CutsceneTrigger *);
void sub_08023714(struct CutsceneTrigger *);
void sub_08023734(struct CutsceneTrigger *);
void sub_08023790(struct CutsceneTrigger *);
void sub_080237DC(struct CutsceneTrigger *);
void sub_080237F0(struct CutsceneTrigger *);

void *CreateCutsceneTrigger(struct Object *arg0, u8 arg1) {
    struct CutsceneTrigger *x;
    struct Task *task;
    u32 size;
    void *dtor;

    switch (arg0->subtype1) {
    case 0:
        size = 0xD8;
        dtor = ObjectDestroy;
        break;
    case 1:
        size = 0xC0;
        dtor = ObjectDestroy;
        break;
    case 2:
        size = 0x2B8;
        dtor = ObjectDestroy;
        break;
    case 4:
        size = 0xCC;
        dtor = sub_08021DD4;
        break;
    case 5:
        size = 0xEC;
        dtor = ObjectDestroy;
        break;
    case 6:
        size = 0xB4;
        dtor = ObjectDestroy;
        break;
    }
    task = TaskCreate(ObjectMain, size, 0x3100, 0, dtor);
    x = TaskGetStructPtr(task);
    CpuFill16(0, x, size);
    InitObject(&x->obj2, arg0, arg1);
    x->obj2.base.flags |= 0x02018F40;
    x->obj2.base.unkC |= 1;
    gUnk_08351648[x->obj2.type].unk10(&x->obj2);
    return x;
}

void sub_08020798(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;

    x->unkB4.obj = CreateObjTemplateAndObj(x->obj2.base.unk56, 1, 0x24, 0xD0, 0x88, 0, 0x1F, 0, 0, 0x36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    x2->unkCC = 0;
    x2->unkCE = 0;
    x->obj2.unk78 = sub_0802084C;
}

void sub_0802084C(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 i;
    u16 j;
    u8 flag = 1;

    j = 0;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && x->obj2.base.roomId == kirby->base.base.base.roomId) {
            if (!(kirby->base.base.base.flags & 0x01000000)) {
                if (sub_0804BAD8(kirby)) {
                    kirby->base.base.base.flags |= 0x01000000;
                    kirby->base.base.base.flags &= ~1;
                    kirby->base.base.base.x = (-(j * 18) + 0x50) << 8;
                    kirby->animationIndex = i + 0x4A;
                }
                flag = 0;
            } else if ((u16)(kirby->animationIndex - 0x4A) <= 0xF) {
                if (!(kirby->base.base.base.unk62 & 4)) {
                    if (++kirby->animationIndex > 0x59)
                        kirby->animationIndex = 0x4A;
                } else {
                    kirby->animationIndex = 0x14;
                    kirby->base.base.base.yspeed = 0x200;
                    sub_0808925C(&kirby->base.base.base);
                    PlaySfx(&kirby->base.base.base, SE_KIRBY_BOUNCE);
                }
                flag = 0;
            } else if (kirby->animationIndex == 0x14) {
                if (kirby->base.base.base.unk62 & 4) {
                    kirby->animationIndex = 0;
                    PlaySfx(&kirby->base.base.base, SE_KIRBY_LANDING);
                }
                flag = 0;
            } else {
                x2->unkCC |= 1 << i;
            }
            j++;
        }
    }
    if (flag) {
        x2->unkCE = j;
        x->obj2.unk78 = sub_08022E6C;
    }
}

void sub_08020DDC(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    struct Object4 *obj;
    union CutsceneVal *p;
    union CutsceneVal *q;
    u16 mask;
    u16 i;

    if ((x->unkD0 & 0xF) == 0) {
        i = (x->unkD0 >> 4) & 1;
        mask = x->unkCE <= 2 ? 0xF : 0x1F;
        p = &x->unkB8;
        if (p[i].obj4 != NULL)
            p[i].obj4->flags |= 0x1000;
        p[i].obj4 = sub_0808B62C(&x->obj2.base, 4, 0x2C3, 0, 0);
        p[i].obj4->sprite.palId = 0;
        if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == p[i].obj4->roomId) {
            if (p[i].obj4->sprite.palId == 0) {
                p[i].obj4->sprite.palId = sub_0803DF24(0x2C3);
                if (p[i].obj4->sprite.palId == 0xFF)
                    p[i].obj4->sprite.palId = sub_0803DFAC(0x2C3, 0);
            }
        } else {
            p[i].obj4->sprite.palId = 0;
        }
        if (i != 0) {
            q = &x2->unkB8;
            obj = q[i].obj4;
            obj->x = ((-(x2->unkCE * 0x12) >> 1) + ((Rand16() & mask) + 0x4E)) << 8;
        } else {
            q = &x2->unkB8;
            obj = q[i].obj4;
            obj->x = ((-(x2->unkCE * 0x12) >> 1) - ((Rand16() & mask) - 0x52)) << 8;
        }
        q[i].obj4->y = (0x74 - (Rand16() & 0xF)) << 8;
    }
    if (x2->unkD0++ > 0xB4) {
        if (x2->unkB8.obj4 != NULL)
            x2->unkB8.obj4->flags |= 0x1000;
        x2->unkB8.obj4 = NULL;
        if (x2->unkBC.obj4 != NULL)
            x2->unkBC.obj4->flags |= 0x1000;
        x2->unkBC.obj4 = NULL;
        x->obj2.unk78 = sub_08022E80;
    }
}

void sub_08020FA8(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    struct Object2 *obj = x->unkB4.obj;
    struct LevelInfo *lvl = &gCurLevelInfo[gUnk_0203AD3C];

    if (++x->unkD0 > 0x3C) {
        if (obj->base.xspeed != 0) {
            obj->base.xspeed += 0xE;
            if (obj->base.xspeed > 0) {
                x->unkC8.obj4 = sub_0808B62C(&x->obj2.base, 4, 0x2C3, 0, 0);
                x->unkC8.obj4->sprite.palId = 0;
                if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == x->unkC8.obj4->roomId) {
                    if (x->unkC8.obj4->sprite.palId == 0) {
                        x->unkC8.obj4->sprite.palId = sub_0803DF24(0x2C3);
                        if (x->unkC8.obj4->sprite.palId == 0xFF)
                            x->unkC8.obj4->sprite.palId = sub_0803DFAC(0x2C3, 0);
                    }
                } else {
                    x->unkC8.obj4->sprite.palId = 0;
                }
                x2->unkC8.obj4->x = obj->base.x;
                x2->unkC8.obj4->y = obj->base.y - 0x1400;
                obj->base.xspeed = 0;
                obj->unk83 = 0;
                obj->base.sprite.unk1C = 0x10;
            }
        }
    }
    if (x2->unkD0 & 1) {
        lvl->viewportModX_44 = (Rand16() & 7) - 4;
        lvl->viewportModY_46 = (Rand16() & 7) - 4;
    } else {
        lvl->viewportModX_44 = 0;
        lvl->viewportModY_46 = 0;
    }
    if (obj->base.xspeed == 0 && x2->unkD0 > 0x78) {
        lvl->viewportModX_44 = 0;
        lvl->viewportModY_46 = 0;
        obj->base.xspeed = 0;
        obj->base.sprite.unk1C = 0x10;
        x->obj2.unk78 = sub_0802114C;
    }
}

void sub_0802114C(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    struct Object2 *obj = x->unkB4.obj;
    struct Object4 *obj4;
    struct Object4 *o;
    u16 i;

    obj4 = sub_0808AE30(&x->obj2.base, 0, 0x292, 0);
    obj4->x = obj->base.x;
    obj4->y = obj->base.y;
    obj->unk83 = 0x13;
    obj->base.xspeed = 0x200;
    obj->base.yspeed = 0x400;
    x->unkC8.obj4->flags |= 0x1000;
    for (i = 0; i < 4; i++) {
        int v = x2->unkCC;

        if ((v >> i) & 1) {
            gKirbys[i].animationIndex = 0xA;
            (&x2->unkB8)[i].obj4 = sub_0808B62C(&gKirbys[i].base.base.base, 4, 0x2C3, 1, 0);
            (&x2->unkB8)[i].obj4->sprite.palId = 0;
            if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == (&x2->unkB8)[i].obj4->roomId) {
                if ((&x2->unkB8)[i].obj4->sprite.palId == 0) {
                    (&x2->unkB8)[i].obj4->sprite.palId = sub_0803DF24(0x2C3);
                    if ((&x2->unkB8)[i].obj4->sprite.palId == 0xFF)
                        (&x2->unkB8)[i].obj4->sprite.palId = sub_0803DFAC(0x2C3, 1);
                }
            } else {
                (&x2->unkB8)[i].obj4->sprite.palId = 0;
            }
            o = (&x2->unkB8)[i].obj4;
            o->x = gKirbys[i].base.base.base.x - 0x800;
            o->y = gKirbys[i].base.base.base.y - 0xC00;
            o->flags |= 1;
        }
    }
    x->obj2.unk78 = sub_080212C0;
}

void sub_080212C0(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    struct Object2 *obj = x->unkB4.obj;
    u16 i;

    obj->base.yspeed -= 0x13;
    if (obj->base.x > 0x12000) {
        obj->base.flags |= 0x1000;
        for (i = 0; i < 4; i++) {
            int v = x->unkCC;

            if ((v >> i) & 1) {
                union CutsceneVal *p;

                gKirbys[i].animationIndex = 0;
                p = &x2->unkB8;
                p += i;
                p->obj4->flags |= 0x1000;
                p->obj4 = NULL;
            }
        }
        x->obj2.unk78 = sub_08022EA0;
    }
}

void sub_08021360(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 i;

    for (i = 0; i < 4; i++) {
        int v = x2->unkCC;

        if ((v >> i) & 1) {
            struct Kirby *kirby;

            gKirbys[i].base.base.base.flags &= ~0x01000000;
            kirby = &gKirbys[i];
            if (kirby->ability == 0xB) {
                sub_080641FC(kirby);
            } else if (kirby->ability == 0xE) {
                sub_0806A798(kirby);
            } else if (kirby->ability == 0x13 && (kirby->base.base.base.flags & 0x40)) {
                sub_08047EF0(kirby);
            } else {
                struct Kirby *k2 = &gKirbys[i];

                if (k2->base.base.base.unk58 & 2)
                    sub_08059810(k2);
                else if (k2->base.base.base.flags & 0x60)
                    sub_08044EA8(k2);
                else
                    sub_0803FE74(k2);
            }
            return;
        }
    }
    x->obj2.base.flags |= 0x1000;
}

void sub_08021424(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 i;
    u16 j;
    u8 flag = 1;

    j = 0;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && x->obj2.base.roomId == kirby->base.base.base.roomId) {
            if (!(gKirbys[i].base.base.base.flags & 0x01000000)) {
                kirby->base.base.base.flags |= 0x01000000;
                kirby->base.base.base.flags &= ~1;
                flag = 0;
            } else if (kirby->animationIndex != 0) {
                flag = 0;
            } else {
                x->unkB8.h[0] |= 1 << i;
            }
            j++;
        }
    }
    if (flag) {
        x2->unkB8.h[1] = j;
        x->obj2.unk78 = sub_08022ECC;
    }
}

void sub_080214E4(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;

    x->unkB4.obj = CreateObjTemplateAndObj(x->obj2.base.unk56, 1, 0x24, 0xFFE0, 0xFFE0, 0, 0x1F, 0, 0, 0x36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    x2->unkB4.obj->base.flags |= 1;
    x2->unkB4.obj->unk83 = 7;
    x2->unkB4.obj->base.xspeed = 0x200;
    x2->unkB4.obj->base.yspeed = 0xFE00;
    x->obj2.unk78 = sub_08023504;
}

void sub_080215B4(struct CutsceneTrigger *x) {
    struct Object2 *obj = x->unkB4.obj;
    struct Sprite sprite;

    sub_0808AE30(&obj->base, 0, 0x28C, 2);
    sprite.tilesVram = 0x06000000;
    sprite.animId = 0x2C3;
    sprite.variant = 3;
    sprite.unk1B = 0xFF;
    sprite.x = 0;
    sprite.y = 0;
    sprite.unk14 = 0;
    sprite.unk16 = 0;
    sprite.unk1C = 0x10;
    sprite.palId = obj->base.sprite.palId & 0xF;
    sprite.unk8 = 0x80000;
    sub_08155128(&sprite);
    sub_0803D280(sprite.palId << 4, 0x10);
    obj->unk83 = 8;
    x->obj2.unk78 = sub_08022EE0;
}

void sub_08021634(struct CutsceneTrigger *x) {
    struct Object2 *obj = x->unkB4.obj;

    obj->base.flags |= 4;
    obj->base.yspeed -= 0x26;
    if (obj->base.y > 0x87FF) {
        struct Object2 *obj2 = CreateObjTemplateAndObj(x->obj2.base.unk56, 1, 0x24, obj->base.x >> 8, obj->base.y >> 8, 0, 0x1F, 0, 0,
            0x8F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        sub_0808B62C(&obj2->base, 0x14, 0x2C9, 0, 1)->y = obj2->base.y - 0x2800;
        obj->base.flags |= 0x1000;
        x->obj2.unk78 = sub_08022EF8;
    }
}

void sub_08021844(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 i;
    u16 j = 0;
    const s16 *p = gUnk_082DEA5C;

    for (i = 0; i < 4; i++) {
        x2->unk2A4[i] = 0;
        if (x2->unk294[i] == (struct Object4 *)-1) {
            struct Object4 *obj = x2->unk294[i] = sub_0808B62C(&x->obj2.base, 0x10, 0x2DE, 0, 0);

            obj->x = p[j * 2] << 8;
            obj->y = gUnk_082DEA5E[j * 2] << 8;
            obj->unk3C = 0;
            obj->unk3E = 0;
            obj->sprite.unk8 = (obj->sprite.unk8 & 0xFFFFCFFF) | 0x1000;
            j++;
        }
    }
    PlaySfx(&x->obj2.base, 0x201);
    x->obj2.unk78 = sub_08021984;
}

void sub_0802172C(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 i;
    u16 j;
    const s16 *xTable;

    x2->unk2B4 = 0;
    xTable = gUnk_082DEA4C;
    j = 0;
    for (i = 0; i < 4; i++) {
        x2->unk294[i] = NULL;
        if (x->obj2.base.roomId == gKirbys[i].base.base.base.roomId && gKirbys[i].hp > 0) {
            struct Object4 *obj;

            gKirbys[i].base.base.base.x = (-(j * 18) + 0x64) << 8;
            gKirbys[i].base.base.base.flags = (gKirbys[i].base.base.base.flags & ~1) | 0x01000000;
            obj = x2->unk294[i] = sub_0808B62C(&x->obj2.base, 0, 0x29C, 0, 0);
            obj->x = *(j * 2 + xTable) << 8;
            obj->y = *(j * 2 + gUnk_082DEA4E) << 8;
            obj->unk3C = 0;
            obj->unk3E = 0;
            obj->sprite.unk8 = (obj->sprite.unk8 & 0xFFFFCFFF) | 0x3000;
            j++;
            x2->unk2B4++;
        }
    }
    x->obj2.unk78 = sub_08022F0C;
}

void sub_08021DD4(struct Task *t) {
    struct CutsceneTrigger *x = TaskGetStructPtr(t);
    struct Object *obj = x->obj2.object;
    u8 a = obj->unk2;
    u8 b = obj->unk3;
    u8 id = x->obj2.base.unk56;
    u16 st = gAIKirbyState;

    if (st <= 0x63) {
        gAIKirbyState = AI_KIRBY_STATE_TUTORIAL;
        if (!(gUnk_0203AD10 & 0x10)) {
            if (gUnk_0203AD10 & 2) {
                if (gUnk_0203AD3C == gUnk_0203AD24) {
                    u16 v = gSaveID;
                    u16 off = 0;

                    if (v <= 2)
                        off = v;
                    UpdateSaveBufferByOffset(1, off);
                } else {
                    sub_08031CE4(8);
                }
            } else {
                u16 v = gSaveID;
                u16 off = 0;

                if (v <= 2)
                    off = v;
                UpdateSaveBufferByOffset(1, off);
            }
        }
    }
    ObjectDestroy(t);
    if (a != 0 || id != 0xFF)
        sub_08001678(a, b, gCurLevelInfo[id].unk65E, 1);
}

void sub_08021EB0(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    struct Sprite s;
    u16 animId = gUnk_082DE9FC[18];
    u8 variant = gUnk_082DE9FC[19];
    u16 animId2;
    u8 i;

    x->unkBC.obj4 = sub_0808B62C(&x->obj2.base, 1, animId, variant, 0);
    x->unkBC.obj4->sprite.palId = 0;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == x->unkBC.obj4->roomId) {
        if (x->unkBC.obj4->sprite.palId == 0) {
            x->unkBC.obj4->sprite.palId = sub_0803DF24(animId);
            if (x->unkBC.obj4->sprite.palId == 0xFF)
                x->unkBC.obj4->sprite.palId = sub_0803DFAC(animId, variant);
        }
    } else {
        x->unkBC.obj4->sprite.palId = 0;
    }
    x2->unkBC.obj4->x = x2->unkBC.obj4->y = -0x4000;

    animId2 = gUnk_082DEA24[18];
    x2->unkC0.obj4 = sub_0808B62C(&x->obj2.base, 0, animId2, gUnk_082DEA24[19], 0);
    x2->unkC0.obj4->sprite.palId = x2->unkBC.obj4->sprite.palId + 1;
    SpriteSomething(&s, 0x6000000, animId2, gUnk_082DEA24[19], 0xFF, 0, 0, 0, 0, 0x10,
        x2->unkC0.obj4->sprite.palId & 0xF, 0x80000);
    x2->unkC0.obj4->x = x2->unkC0.obj4->y = -0x4000;

    x2->unkB4.obj4 = sub_0808B62C(&x->obj2.base, 0x14, gUnk_082DE9FC[0], ((const u8 *)gUnk_082DE9FC)[2], 0);
    x2->unkB4.obj4->sprite.palId = x2->unkBC.obj4->sprite.palId;
    x2->unkB4.obj4->x = 0xC800;
    x2->unkB4.obj4->y = 0x8800;
    x2->unkB8.obj4 = sub_0808B62C(&x->obj2.base, 0x14, gUnk_082DEA24[0], ((const u8 *)gUnk_082DEA24)[2], 0);
    x2->unkB8.obj4->sprite.palId = x2->unkC0.obj4->sprite.palId;
    x2->unkB8.obj4->x = 0xC800;
    x2->unkB8.obj4->y = 0x8800;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        kirby->base.base.base.flags = (kirby->base.base.base.flags | 0x1000800) & ~1;
        kirby->animationIndex = 0;
    }
    x->obj2.unk78 = sub_08022F50;
}

void sub_08022090(struct CutsceneTrigger *x) {
    struct Sprite *s;

    x->unkC4.s[0] = 0x300;
    x->unkC4.s[1] = -0xA00;
    s = &x->unkB4.obj4->sprite;
    s->animId = gUnk_082DE9FC[12];
    s->variant = gUnk_082DE9FC[13];
    sub_08155128(s);
    s = &x->unkB8.obj4->sprite;
    s->animId = gUnk_082DEA24[12];
    s->variant = gUnk_082DEA24[13];
    sub_08155128(s);
    m4aSongNumStart(0x243);
    x->unkC8.s = 0;
    x->obj2.unk78 = sub_08022104;
}

void sub_08022104(struct CutsceneTrigger *x) {
    x->unkC4.h[1] += 0x26;
    x->unkB4.obj4->x += x->unkC4.s[0];
    x->unkB4.obj4->y += x->unkC4.s[1];
    x->unkB8.obj4->x += x->unkC4.s[0];
    x->unkB8.obj4->y += x->unkC4.s[1];
    if (x->unkB8.obj4->y <= -0x4000)
        x->obj2.unk78 = sub_08023054;
}

void sub_08022174(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 animId;
    u8 variant;
    u8 i;

    for (i = 0; i < 4; i++) {
        x2->unkDE[i] = x2->unkE2[i] = 0;
    }
    x2->unkB4.h[0] = 0;
    animId = gUnk_082DE9FC[8];
    variant = ((const u8 *)gUnk_082DE9FC)[0x12];
    x2->unkBC.obj4 = sub_0808B62C(&x->obj2.base, 0x14, animId, variant, 0);
    x2->unkBC.obj4->sprite.palId = 0;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == x2->unkBC.obj4->roomId) {
        if (x2->unkBC.obj4->sprite.palId == 0) {
            x2->unkBC.obj4->sprite.palId = sub_0803DF24(animId);
            if (x2->unkBC.obj4->sprite.palId == 0xFF)
                x2->unkBC.obj4->sprite.palId = sub_0803DFAC(animId, variant);
        }
    } else {
        x2->unkBC.obj4->sprite.palId = 0;
    }
    x2->unkBC.obj4->x = 0xB800;
    x2->unkBC.obj4->y = 0x11C00;
    x2->unkBC.obj4->flags ^= 1;
    animId = gUnk_082DEA24[8];
    variant = ((const u8 *)gUnk_082DEA24)[0x12];
    x2->unkC0.obj4 = sub_0808B62C(&x->obj2.base, 0x14, animId, variant, 0);
    x2->unkC0.obj4->sprite.palId = 0;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == x2->unkC0.obj4->roomId) {
        if (x2->unkC0.obj4->sprite.palId == 0) {
            x2->unkC0.obj4->sprite.palId = sub_0803DF24(animId);
            if (x2->unkC0.obj4->sprite.palId == 0xFF)
                x2->unkC0.obj4->sprite.palId = sub_0803DFAC(animId, variant);
        }
    } else {
        x2->unkC0.obj4->sprite.palId = 0;
    }
    x2->unkC0.obj4->x = 0xB800;
    x2->unkC0.obj4->y = 0x11C00;
    x2->unkC0.obj4->flags ^= 1;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && kirby->base.base.base.roomId == x->obj2.base.roomId) {
            kirby->base.base.base.flags |= 0x1000800;
            kirby->base.base.base.flags |= 0x100;
        }
    }
    x->obj2.unk78 = sub_080230DC;
}

void sub_08022350(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    struct LevelInfo *lvl = &gCurLevelInfo[gUnk_0203AD3C];
    u8 i;

    x->unkB4.h[0]++;
    if (x->unkB4.h[0] & 1) {
        *(u8 *)&x->unkCC = 1;
        x->unkC8.sb[2] = (Rand32() & 7) - 4;
        x->unkC8.sb[3] = (Rand32() & 7) - 4;
        lvl->viewportModX_44 += x->unkC8.sb[2];
        lvl->viewportModY_46 += x->unkC8.sb[3];
        for (i = 0; i < 4; i++) {
            if (gKirbys[i].hp > 0 && gKirbys[i].base.base.base.roomId == x->obj2.base.roomId) {
                gKirbys[i].base.base.base.x -= x2->unkC8.sb[2] << 8;
                gKirbys[i].base.base.base.y -= x2->unkC8.sb[3] << 8;
            }
        }
    } else {
        *(u8 *)&x->unkCC = 0;
        lvl->viewportModX_44 -= x->unkC8.sb[2];
        lvl->viewportModY_46 -= x->unkC8.sb[3];
        for (i = 0; i < 4; i++) {
            if (gKirbys[i].hp > 0 && gKirbys[i].base.base.base.roomId == x->obj2.base.roomId) {
                gKirbys[i].base.base.base.x += x2->unkC8.sb[2] << 8;
                gKirbys[i].base.base.base.y += x2->unkC8.sb[3] << 8;
            }
        }
        x->unkC8.sb[2] = 0;
        x->unkC8.sb[3] = 0;
    }

    if (++x->unkC8.b[0] >= x->unkC8.b[1] && x->unkB4.s[0] <= 0x95) {
        x->unkC8.b[0] = 0;
        x->unkC8.b[1] = (Rand32() & 0x1F) + 5;
        gBldRegs.bldY = 0x10;
        m4aSongNumStart(0x23E);
    } else if (gBldRegs.bldY != 0) {
        gBldRegs.bldY--;
    } else {
        gBldRegs.bldY = 0;
    }

    if (x->unkB4.s[0] > 0x95 && gBldRegs.bldY == 0) {
        if (*(u8 *)&x2->unkCC != 0) {
            *(u8 *)&x2->unkCC = 0;
            lvl->viewportModX_44 -= x2->unkC8.sb[2];
            lvl->viewportModY_46 -= x2->unkC8.sb[3];
            for (i = 0; i < 4; i++) {
                if (gKirbys[i].hp > 0 && gKirbys[i].base.base.base.roomId == x->obj2.base.roomId) {
                    gKirbys[i].base.base.base.x += x2->unkC8.sb[2] << 8;
                    gKirbys[i].base.base.base.y += x2->unkC8.sb[3] << 8;
                }
            }
            x2->unkC8.sb[2] = 0;
            x2->unkC8.sb[3] = 0;
        }
        gBldRegs.bldCnt = 0;
        gBldRegs.bldY = 0;
        x->obj2.unk78 = sub_08023154;
    }
}

void sub_0802262C(struct CutsceneTrigger *x) {
    struct Object4 *obj;
    u8 *p;

    obj = x->unkB8.obj4 = sub_0808B62C(&x->obj2.base, 0x24, 0x399, 0xA, 0);
    p = &obj->sprite.palId;
    *p = 0;
    if (gKirbys[gUnk_0203AD3C].base.base.base.roomId == obj->roomId) {
        *p = sub_0803DF24(0x399);
        if (*p == 0xFF)
            *p = sub_0803DFAC(0x399, 0xD);
    } else {
        *p = 0;
    }
    obj->x = 0x17000;
    obj->y = 0xE000;
    obj->sprite.unk14 = 0x7C0;
    x->obj2.unk78 = sub_0802318C;
}

void sub_080226C4(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u16 *p;
    u8 i;

    x->unkB4.s[0] = 0;
    p = &x->unkD0;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && kirby->base.base.base.roomId == x->obj2.base.roomId) {
            (&x2->unkCE)[i * 2] = 0;
            if (kirby->base.base.base.y >> 8 > 0xDF)
                p[i * 2] = 0xFD00;
            else
                p[i * 2] = 0x300;
            kirby->animationIndex = i + 0x4A;
            kirby->base.base.base.flags |= 0x100;
        }
    }
    x->obj2.unk78 = sub_08022770;
}

void sub_08022770(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    s16 v[2];
    s16 d[2];
    u8 i;
    u8 flag = 1;

    x->unkB4.s[0]++;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && kirby->base.base.base.roomId == x2->obj2.base.roomId) {
            kirby->base.base.base.flags |= 0x1000000;
            switch (x->unkDE[i]) {
            case 0: {
                s32 t;
                u8 angle;
                s32 idx;

                if (++kirby->animationIndex > 0x59)
                    kirby->animationIndex = 0x4A;
                t = x->unkB4.s[0] / 2;
                angle = t > 0xC7 ? 0xC8 : t;
                v[0] = (&x->unkCE)[i * 2];
                v[1] = (&x->unkD0)[i * 2];
                d[0] = 0x7000 - kirby->base.base.base.x;
                d[1] = -0x2000 - kirby->base.base.base.y;
                if (d[0] * v[1] - v[0] * d[1] > 0)
                    angle = -angle;
                idx = ((s8)angle + 0x400) & 0x3FF;
                (&x->unkCE)[i * 2] = (v[0] * gSineTable[idx + 0x100] - v[1] * gSineTable[idx]) >> 14;
                (&x->unkD0)[i * 2] = (v[0] * gSineTable[idx] + v[1] * gSineTable[idx + 0x100]) >> 14;
                kirby->base.base.base.x += (s16)(&x->unkCE)[i * 2];
                kirby->base.base.base.y += (s16)(&x->unkD0)[i * 2];
                if (kirby->base.base.base.x >> 8 >= 0x168 && kirby->base.base.base.x >> 8 <= 0x178) {
                    if (kirby->base.base.base.y >> 8 > 0xD7 && kirby->base.base.base.y >> 8 <= 0xE8) {
                        kirby->base.base.base.x = 0x17000;
                        kirby->base.base.base.y = 0xE000;
                        kirby->base.base.base.flags |= 0x800;
                        x->unkDE[i] = 1;
                    }
                }
                flag = 0;
                break;
            }
            case 1:
                if (++kirby->animationIndex > 0x59)
                    kirby->animationIndex = 0x4A;
                if (x->unkE2[i] & 1)
                    kirby->base.base.base.flags ^= 0x400;
                if (++x->unkE2[i] > 0x3B) {
                    kirby->base.base.base.flags |= 0x400;
                    x->unkDE[i] = 2;
                }
                flag = 0;
                break;
            case 2:
                break;
            }
        }
    }
    if (flag != 0) {
        m4aMPlayFadeOut(&gMPlayInfo_0, 3);
        m4aMPlayFadeOut(&gMPlayInfo_1, 3);
        m4aMPlayFadeOut(&gMPlayInfo_2, 3);
        m4aMPlayFadeOut(&gMPlayInfo_3, 3);
        x2->obj2.unk78 = sub_08023268;
    }
}

void sub_080229E4(struct CutsceneTrigger *x) {
    struct Object4 *obj;
    struct Sprite *s;

    x->unkB4.s[0] = 0;
    s = &x->unkBC.obj4->sprite;
    s->animId = gUnk_082DE9FC[14];
    s->variant = gUnk_082DE9FC[15];
    s->unk1C = 0x20;
    sub_08155128(s);
    obj = x->unkBC.obj4;
    obj->flags = (obj->flags & 0xFFFB) | 8;
    obj->unk4 = 1;
    obj->unk2 = 0x20;
    obj->unk1 = 2;
    s = &x->unkC0.obj4->sprite;
    s->animId = gUnk_082DEA24[14];
    s->variant = gUnk_082DEA24[15];
    sub_08155128(s);
    obj = x->unkC0.obj4;
    obj->flags = (obj->flags & 0xFFFB) | 8;
    obj->unk4 = 1;
    obj->unk2 = 0x20;
    obj->unk1 = 2;
    x->obj2.unk78 = sub_08022A90;
}

void sub_08022A90(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;

    if (x->unkBC.obj4->unk3C != 0) {
        x->unkBC.obj4->unk3C -= 0x32;
        x->unkC0.obj4->unk3C -= 0x32;
        if (x->unkBC.obj4->unk3C < 0) {
            x->unkBC.obj4->unk3C = 0;
            x->unkC0.obj4->unk3C = 0;
        }
    }
    if (++x->unkB4.s[0] > 9) {
        struct Object4 *a;

        x->unkB4.s[0] = 0;
        a = x->unkBC.obj4;
        a->flags &= 0xFFFB;
        a->unk4 = 1;
        a->unk2 += 0x20;
        a->unk1 = a->unk2 >> 4;
        a = x->unkC0.obj4;
        a->flags &= 0xFFFB;
        a->unk4 = 1;
        a->unk2 += 0x10;
        a->unk1 = a->unk2 >> 4;
        x->unkBC.obj4->flags &= 0xFFF7;
        x->unkC0.obj4->flags &= 0xFFF7;
        x2->obj2.unk78 = sub_08022B74;
    }
    x->unkBC.obj4->flags &= 0xFFFD;
    x->unkC0.obj4->flags &= 0xFFFD;
    x->unkBC.obj4->flags &= 0xEFFF;
    x->unkC0.obj4->flags &= 0xEFFF;
}

void sub_08022B74(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;

    if (x->unkBC.obj4->unk3C != 0) {
        x->unkBC.obj4->unk3C -= 0x32;
        x->unkC0.obj4->unk3C -= 0x32;
        if (x->unkBC.obj4->unk3C < 0) {
            x->unkBC.obj4->unk3C = 0;
            x->unkC0.obj4->unk3C = 0;
        }
    }
    if (x->unkBC.obj4->flags & 2) {
        struct Sprite *s;

        s = &x->unkBC.obj4->sprite;
        s->animId = gUnk_082DE9FC[16];
        s->variant = gUnk_082DE9FC[17];
        sub_08155128(s);
        x->unkBC.obj4->unk4 = 0;
        s = &x->unkC0.obj4->sprite;
        s->animId = gUnk_082DEA24[16];
        s->variant = gUnk_082DEA24[17];
        sub_08155128(s);
        x->unkC0.obj4->unk4 = 0;
        x->unkC0.obj4->x += 0x1400;
        x->unkC0.obj4->y += -0x1900;
        x->unkE6 = (0x17000 - x->unkC0.obj4->x) / 0x14;
        x->unkE8 = (0xE000 - x->unkC0.obj4->y) / 0x14 - 0x17C;
        m4aSongNumStart(0x1A4);
        x2->obj2.unk78 = sub_08022C9C;
    }
    x->unkBC.obj4->flags &= 0xFFFD;
    x->unkC0.obj4->flags &= 0xFFFD;
    x->unkBC.obj4->flags &= 0xEFFF;
    x->unkC0.obj4->flags &= 0xEFFF;
}

void sub_08022C9C(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;

    x->unkE8 += 0x26;
    x->unkC0.obj4->x += x->unkE6;
    x->unkC0.obj4->y += x->unkE8;
    if (x->unkBC.obj4->unk3C != 0) {
        x->unkBC.obj4->unk3C -= 0x32;
        if (x->unkBC.obj4->unk3C < 0) {
            x->unkBC.obj4->unk3C = 0;
        }
    }
    if (x->unkBC.obj4->flags & 2) {
        x->unkBC.obj4->flags |= 8;
        x->unkBC.obj4->sprite.unk1C = 0x10;
    }
    if (++x->unkB4.s[0] > 0x13) {
        u16 v = x->unkC0.obj4->flags;

        x->unkC0.obj4->flags = v | 0x1000;
        x2->obj2.unk78 = sub_080232E4;
    } else {
        x->unkBC.obj4->flags &= 0xFFFD;
        x->unkC0.obj4->flags &= 0xFFFD;
        x->unkBC.obj4->flags &= 0xEFFF;
        x->unkC0.obj4->flags &= 0xEFFF;
    }
}

void sub_08022D78(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x3B) {
        u16 v;
        struct Unk_02022930_0 *p = sub_0803C83C(5, x->obj2.base.roomId);

        x->unkC4.u0 = p;
        v = p->unk8;
        p->unk8 = v | 0x40;
        x->unkC4.u0->unkA = 0x80;
        x->unkC4.u0->unk4 = 0xFFFF;
        x->unkC4.u0->unk6 = -1;
        x->unkB4.s[0] = 0;
        x->obj2.unk78 = sub_080233A8;
        sub_0808859C(&x->obj2, gUnk_0835105C[10], 0x48);
    }
}

void sub_08022DE4(struct CutsceneTrigger *x) {
    switch (x->obj2.object->subtype1) {
        case 0:
            x->obj2.unk78 = sub_08020798;
            break;
        case 1:
            x->obj2.unk78 = sub_08022EB4;
            break;
        case 2:
            x->obj2.unk78 = sub_0802172C;
            break;
        case 3:
            break;
        case 4:
            x->obj2.unk78 = sub_08022F24;
            break;
        case 5:
            x->obj2.unk78 = sub_08022174;
            break;
        case 6: {
            void (*func)(struct CutsceneTrigger *) = sub_080233E0;

            x->obj2.unk78 = func;
            func(x);
            break;
        }
    }
}

void sub_08022E6C(struct CutsceneTrigger *x) {
    x->unkD0 = 0;
    x->obj2.unk78 = sub_08023438;
}

void sub_08022E80(struct CutsceneTrigger *x) {
    struct Object2 *obj = x->unkB4.obj;

    obj->unk83 = 1;
    obj->base.sprite.unk1C = 8;
    x->obj2.unk78 = sub_0802347C;
}

void sub_08022EA0(struct CutsceneTrigger *x) {
    x->unkD0 = 0;
    x->obj2.unk78 = sub_080234C4;
}

void sub_08022EB4(struct CutsceneTrigger *x) {
    x->unkB8.h[0] = 0;
    x->unkB8.h[1] = 0;
    x->obj2.unk78 = sub_08021424;
}

void sub_08022ECC(struct CutsceneTrigger *x) {
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_080234E4;
}

void sub_08022EE0(struct CutsceneTrigger *x) {
    x->unkB4.obj->base.yspeed = 0x400;
    x->obj2.unk78 = sub_08021634;
}

void sub_08022EF8(struct CutsceneTrigger *x) {
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_08023524;
}

void sub_08022F0C(struct CutsceneTrigger *x) {
    x->unk2B6 = 0;
    x->obj2.unk78 = sub_08023544;
}

void sub_08022F24(struct CutsceneTrigger *x) {
    void (*func)(struct CutsceneTrigger *);
    u16 state = gAIKirbyState;

    if (state > 0x63) {
        func = sub_080230A0;
    } else {
        m4aMPlayAllStop();
        func = sub_08021EB0;
    }
    x->obj2.unk78 = func;
}

void sub_08022F50(struct CutsceneTrigger *x) {
    x->unkC8.s = 0;
    x->obj2.unk78 = sub_08022F64;
}

void sub_08022F64(struct CutsceneTrigger *x) {
    if (++x->unkC8.s > 0x3B)
        x->obj2.unk78 = sub_08022F88;
}

void sub_08022F88(struct CutsceneTrigger *x) {
    x->unkB4.obj4->flags ^= 1;
    x->unkB8.obj4->flags ^= 1;
    x->unkC8.s = 0;
    x->obj2.unk78 = sub_08022FB8;
}

void sub_08022FB8(struct CutsceneTrigger *x) {
    if (++x->unkC8.s > 9)
        x->obj2.unk78 = sub_08022FDC;
}

void sub_08022FDC(struct CutsceneTrigger *x) {
    struct Sprite *s;

    s = &x->unkB4.obj4->sprite;
    s->animId = gUnk_082DE9FC[10];
    s->variant = gUnk_082DE9FC[11];
    sub_08155128(s);
    s = &x->unkB8.obj4->sprite;
    s->animId = gUnk_082DEA24[10];
    s->variant = gUnk_082DEA24[11];
    sub_08155128(s);
    x->unkC8.s = 0;
    x->obj2.unk78 = sub_08023030;
}

void sub_08023030(struct CutsceneTrigger *x) {
    if (++x->unkC8.s > 9)
        x->obj2.unk78 = sub_08022090;
}

void sub_08023054(struct CutsceneTrigger *x) {
    x->unkC8.s = 0;
    x->obj2.unk78 = sub_08023068;
}

void sub_08023068(struct CutsceneTrigger *x) {
    if (++x->unkC8.s > 0x3B) {
        m4aSongNumStart(gRoomProps[0x323].songIdx);
        x->obj2.unk78 = sub_080230A0;
    }
}

void sub_080230A0(struct CutsceneTrigger *x) {
    u8 i;

    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        kirby->base.base.base.flags &= ~0x01000000;
    }
    x->obj2.base.flags |= 0x1000;
}

void sub_080230DC(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x77)
        x->obj2.unk78 = sub_08023100;
}

void sub_08023100(struct CutsceneTrigger *x) {
    gBldRegs.bldCnt = 0xBF;
    x->unkC8.b[1] = (Rand32() & 0xF) + 5;
    x->unkB4.s[0] = 0;
    x->unkC8.b[0] = 0;
    x->obj2.unk78 = sub_08022350;
}

void sub_08023154(struct CutsceneTrigger *x) {
    x->unkB4.s[0] = 0;
    x->obj2.unk78 = sub_08023168;
}

void sub_08023168(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x3B)
        x->obj2.unk78 = sub_0802262C;
}

void sub_0802318C(struct CutsceneTrigger *x) {
    struct Object4 *obj = x->unkB8.obj4;

    if (obj->flags & 2) {
        struct Sprite *s = &obj->sprite;

        s->animId = 0x399;
        s->variant = 0xB;
        sub_08155128(s);
        x->obj2.unk78 = sub_080231C0;
    }
}

void sub_080231C0(struct CutsceneTrigger *x) {
    struct CutsceneTrigger *x2 = x;
    u8 i;

    x->unkB4.s[0] = 0;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && kirby->base.base.base.roomId == x->obj2.base.roomId) {
            if (kirby->base.base.base.x < x2->unkB8.obj4->x)
                kirby->base.base.base.flags &= ~1;
            else
                kirby->base.base.base.flags |= 1;
        }
    }
    x->obj2.unk78 = sub_08023238;
}

void sub_08023238(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x2C) {
        m4aSongNumStart(0x21A);
        x->obj2.unk78 = sub_080226C4;
    }
}

void sub_08023268(struct CutsceneTrigger *x) {
    x->unkB4.s[0] = 0;
    x->obj2.unk78 = sub_0802327C;
}

void sub_0802327C(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x3B)
        x->obj2.unk78 = sub_080232A0;
}

void sub_080232A0(struct CutsceneTrigger *x) {
    struct Object4 *a = x->unkBC.obj4;
    struct Object4 *b = x->unkC0.obj4;

    b->unk3C = 0x200;
    a->unk3C = 0x200;
    x->obj2.unk78 = sub_080232BC;
}

void sub_080232BC(struct CutsceneTrigger *x) {
    struct Object4 *a = x->unkBC.obj4;

    if (a->x > 0x10800) {
        x->unkC0.obj4->x = 0x10800;
        a->x = 0x10800;
        x->obj2.unk78 = sub_080229E4;
    }
}

void sub_080232E4(struct CutsceneTrigger *x) {
    x->unkB4.s[0] = 0;
    x->obj2.unk78 = sub_080232F8;
}

void sub_080232F8(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x1D)
        x->obj2.unk78 = sub_0802331C;
}

void sub_0802331C(struct CutsceneTrigger *x) {
    struct Sprite *s;

    s = &x->unkBC.obj4->sprite;
    s->animId = gUnk_082DE9FC[0];
    s->variant = gUnk_082DE9FC[1];
    sub_08155128(s);
    s = &x->unkB8.obj4->sprite;
    s->animId = 0x399;
    s->variant = 0xC;
    sub_08155128(s);
    x->obj2.unk78 = sub_08023368;
}

void sub_08023368(struct CutsceneTrigger *x) {
    struct Object4 *obj = x->unkB8.obj4;

    if (obj->flags & 2) {
        obj->flags |= 0x1000;
        x->obj2.unk78 = sub_08023394;
    }
}

void sub_08023394(struct CutsceneTrigger *x) {
    x->unkB4.s[0] = 0;
    x->obj2.unk78 = sub_08022D78;
}

void sub_080233A8(struct CutsceneTrigger *x) {
    if (++x->unkB4.s[0] > 0x4F) {
        struct Object4 *obj = x->unkC4.obj4;
        u16 v = obj->unk8;

        obj->unk8 = v & 0xFFBF;
        x->obj2.base.flags |= 0x1000;
    }
}

void sub_080233E0(struct CutsceneTrigger *x) {
    u16 state = gAIKirbyState;

    if (state > 0x12B) {
        x->obj2.unk78 = nullsub_113;
    } else {
        void (*func)(struct CutsceneTrigger *) = sub_08023414;

        x->obj2.unk78 = func;
        func(x);
    }
}

void sub_08023414(struct CutsceneTrigger *x) {
    if (sub_080395D4()) {
        sub_08039600(0x1A);
        x->obj2.unk78 = nullsub_113;
    }
}

void nullsub_113(struct CutsceneTrigger *x) {
}

void sub_08023438(struct CutsceneTrigger *x) {
    if (x->unkD0++ > 0x3C) {
        x->unkD0 = 0;
        x->unkD2 = 0;
        x->unkD4 = 0;
        if (x->unkCE != 4)
            x->obj2.unk78 = sub_08020A90;
        else
            x->obj2.unk78 = sub_08020DDC;
    }
}

void sub_0802347C(struct CutsceneTrigger *x) {
    struct ObjectBase *obj = &x->unkB4.obj->base;
    s32 v;

    obj->flags |= 4;
    v = (u16)obj->xspeed - 0x10;
    obj->xspeed = v;
    if ((s16)v < -0xA6)
        obj->xspeed = -0xA6;
    if (obj->x <= 0xAFFF)
        x->obj2.unk78 = sub_0802356C;
}

void sub_080234C4(struct CutsceneTrigger *x) {
    if (x->unkD0++ > 0xB4)
        x->obj2.unk78 = sub_08021360;
}

void sub_080234E4(struct CutsceneTrigger *x) {
    if (x->unkBC.h[0]++ > 0xB4)
        x->obj2.unk78 = sub_08023580;
}

void sub_08023504(struct CutsceneTrigger *x) {
    if (x->unkB4.obj->base.x > 0x5000)
        x->obj2.unk78 = sub_08023594;
}

void sub_08023524(struct CutsceneTrigger *x) {
    if (x->unkBC.h[0]++ > 0xB4)
        x->obj2.unk78 = sub_080235BC;
}

void sub_08023544(struct CutsceneTrigger *x) {
    if (x->unk2B6++ > 0x3C)
        x->obj2.unk78 = sub_0802360C;
}

void sub_0802356C(struct CutsceneTrigger *x) {
    x->unkD0 = 0;
    x->obj2.unk78 = sub_08020FA8;
}

void sub_08023580(struct CutsceneTrigger *x) {
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_08023644;
}

void sub_08023594(struct CutsceneTrigger *x) {
    sub_0803CA20(7)->unkA = 0x400;
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_08023664;
}

void sub_080235BC(struct CutsceneTrigger *x) {
    u16 i;

    for (i = 0; i < 4; i++) {
        int v = x->unkB8.h[0];

        if ((v >> i) & 1)
            gKirbys[i].base.base.base.flags &= ~0x01000000;
    }
    x->obj2.base.flags |= 0x1000;
}

void sub_0802360C(struct CutsceneTrigger *x) {
    u16 i;

    for (i = 0; i < 4; i++) {
        if (x->unk294[i] != NULL) {
            x->unk294[i]->unk3C = 0x80;
            x->unk294[i]->unk3E = 0x20;
        }
    }
    x->obj2.unk78 = sub_08023734;
}

void sub_08023644(struct CutsceneTrigger *x) {
    if (x->unkBC.h[0]++ > 0x3C)
        x->obj2.unk78 = sub_080214E4;
}

void sub_08023664(struct CutsceneTrigger *x) {
    struct ObjectBase *obj = &x->unkB4.obj->base;

    if (x->unkBC.h[0]++ > 0x10) {
        obj->xspeed = 0;
        obj->yspeed = 0;
        x->obj2.unk78 = sub_08023698;
    }
}

void sub_08023698(struct CutsceneTrigger *x) {
    struct Object2 *obj = x->unkB4.obj;

    obj->base.x = 0x8000;
    obj->base.y = 0x8800;
    obj->base.flags &= ~1;
    obj->unk83 = 0;
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_080236CC;
}

void sub_080236CC(struct CutsceneTrigger *x) {
    if (x->unkBC.h[0]++ > 0x3C)
        x->obj2.unk78 = sub_080236EC;
}

void sub_080236EC(struct CutsceneTrigger *x) {
    sub_0803C95C(7)->unkA = 0xFF80;
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_08023714;
}

void sub_08023714(struct CutsceneTrigger *x) {
    if (x->unkBC.h[0]++ > 0x40)
        x->obj2.unk78 = sub_080237DC;
}

void sub_08023734(struct CutsceneTrigger *x) {
    u8 flag = 1;
    u16 i;

    for (i = 0; i < 4; i++) {
        if (x->unk294[i] != NULL) {
            struct Object4 *obj = x->unk294[i];

            if (obj->x <= 0x11FFF && obj->y > -0x2000) {
                flag = 0;
            } else {
                obj->unk3C = 0;
                obj->unk3E = 0;
            }
        }
    }
    if (flag)
        x->obj2.unk78 = sub_08023790;
}

void sub_08023790(struct CutsceneTrigger *x) {
    u16 i;

    for (i = 0; i < 4; i++) {
        struct Object4 *obj = x->unk294[i];

        if (obj != NULL) {
            obj->flags |= 0x1000;
            x->unk294[i] = (struct Object4 *)-1;
        }
    }
    x->obj2.unk78 = sub_08021844;
}

void sub_080237DC(struct CutsceneTrigger *x) {
    x->unkBC.h[0] = 0;
    x->obj2.unk78 = sub_080237F0;
}

void sub_080237F0(struct CutsceneTrigger *x) {
    if (x->unkBC.h[0]++ > 0xB4)
        x->obj2.unk78 = sub_080215B4;
}
