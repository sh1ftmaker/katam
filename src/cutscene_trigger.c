#include "global.h"
#include "data.h"
#include "object.h"
#include "functions.h"
#include "task.h"
#include "kirby.h"
#include "code_0806F780.h"
#include "constants/songs.h"

struct CutsceneTrigger {
    /* 0x000 */ struct Object2 obj2;
    /* 0x0B4 */ struct Object2 *unkB4;
    /* 0x0B8 */ struct Object2 *unkB8;
    /* 0x0BC */ u16 unkBC;
    /* 0x0BE */ u16 unkBE;
    /* 0x0C0 */ u8 fillerC0[8];
    /* 0x0C8 */ s16 unkC8;
    /* 0x0CA */ u16 unkCA;
    /* 0x0CC */ u16 unkCC;
    /* 0x0CE */ u16 unkCE;
    /* 0x0D0 */ u16 unkD0;
    /* 0x0D2 */ u16 unkD2;
    /* 0x0D4 */ u16 unkD4;
    /* 0x0D6 */ u8 fillerD6[0x1E0];
    /* 0x2B6 */ u16 unk2B6;
}; /* size = 0x2B8 */

void sub_08020798(struct CutsceneTrigger *);
void sub_0802084C(struct CutsceneTrigger *);
void sub_08021DD4(struct Task *);
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
void sub_08021424(struct CutsceneTrigger *);
void sub_08021634(struct CutsceneTrigger *);
void sub_08021EB0(struct CutsceneTrigger *);
void sub_08022090(struct CutsceneTrigger *);
void sub_08023438(struct CutsceneTrigger *);
void sub_0802347C(struct CutsceneTrigger *);
void sub_080234C4(struct CutsceneTrigger *);
void sub_080234E4(struct CutsceneTrigger *);
void sub_08023524(struct CutsceneTrigger *);
void sub_08023544(struct CutsceneTrigger *);

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

    x->unkB4 = CreateObjTemplateAndObj(x->obj2.base.unk56, 1, 0x24, 0xD0, 0x88, 0, 0x1F, 0, 0, 0x36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
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
    struct Object2 *obj = x->unkB4;

    obj->unk83 = 1;
    obj->base.sprite.unk1C = 8;
    x->obj2.unk78 = sub_0802347C;
}

void sub_08022EA0(struct CutsceneTrigger *x) {
    x->unkD0 = 0;
    x->obj2.unk78 = sub_080234C4;
}

void sub_08022ECC(struct CutsceneTrigger *x) {
    x->unkBC = 0;
    x->obj2.unk78 = sub_080234E4;
}

void sub_08022EE0(struct CutsceneTrigger *x) {
    x->unkB4->base.yspeed = 0x400;
    x->obj2.unk78 = sub_08021634;
}

void sub_08022EF8(struct CutsceneTrigger *x) {
    x->unkBC = 0;
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
    x->unkC8 = 0;
    x->obj2.unk78 = sub_08022F64;
}

void sub_08022F64(struct CutsceneTrigger *x) {
    if (++x->unkC8 > 0x3B)
        x->obj2.unk78 = sub_08022F88;
}

void sub_08022FB8(struct CutsceneTrigger *x) {
    if (++x->unkC8 > 9)
        x->obj2.unk78 = sub_08022FDC;
}

void sub_08023030(struct CutsceneTrigger *x) {
    if (++x->unkC8 > 9)
        x->obj2.unk78 = sub_08022090;
}

void sub_08023054(struct CutsceneTrigger *x) {
    x->unkC8 = 0;
    x->obj2.unk78 = sub_08023068;
}
