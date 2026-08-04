#include "global.h"
#include "data.h"
#include "object.h"
#include "functions.h"
#include "task.h"
#include "kirby.h"
#include "random.h"
#include "main.h"
#include "code_0806F780.h"
#include "constants/songs.h"

union CutsceneVal {
    struct Object2 *obj;
    struct Object4 *obj4;
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
    /* 0x0C8 */ union { s16 s; u16 h; u8 b[2]; } unkC8;
    /* 0x0CC */ u16 unkCC;
    /* 0x0CE */ u16 unkCE;
    /* 0x0D0 */ u16 unkD0;
    /* 0x0D2 */ u16 unkD2;
    /* 0x0D4 */ u16 unkD4;
    /* 0x0D6 */ u8 fillerD6[0x1BE];
    /* 0x294 */ struct Object4 *unk294[4];
    /* 0x2A4 */ u8 filler2A4[0x12];
    /* 0x2B6 */ u16 unk2B6;
}; /* size = 0x2B8 */

extern const u16 gUnk_082DE9FC[];
extern const u16 gUnk_082DEA24[];

void sub_08020798(struct CutsceneTrigger *);
void sub_0802084C(struct CutsceneTrigger *);
void sub_08020A90(struct CutsceneTrigger *);
void sub_08020DDC(struct CutsceneTrigger *);
void sub_08020FA8(struct CutsceneTrigger *);
void sub_08021360(struct CutsceneTrigger *);
void sub_08021424(struct CutsceneTrigger *);
void sub_080214E4(struct CutsceneTrigger *);
void sub_080215B4(struct CutsceneTrigger *);
void sub_08021634(struct CutsceneTrigger *);
void sub_08021844(struct CutsceneTrigger *);
void sub_08021DD4(struct Task *);
void sub_08021EB0(struct CutsceneTrigger *);
void sub_08022090(struct CutsceneTrigger *);
void sub_08022350(struct CutsceneTrigger *);
void sub_0802262C(struct CutsceneTrigger *);
void sub_080226C4(struct CutsceneTrigger *);
void sub_080229E4(struct CutsceneTrigger *);
void sub_08022D78(struct CutsceneTrigger *);
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
    u8 i;

    x->unkB4.s[0] = 0;
    for (i = 0; i < 4; i++) {
        struct Kirby *kirby = &gKirbys[i];

        if (kirby->hp > 0 && kirby->base.base.base.roomId == x->obj2.base.roomId) {
            if (kirby->base.base.base.x < x->unkB8.obj4->x)
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
    u16 flags = obj->flags;

    if (flags & 2) {
        obj->flags = 0x1000 | flags;
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

        obj->unk8 = 0xFFBF & v;
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
        struct Object4 *obj = x->unk294[i];

        if (obj != NULL) {
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
