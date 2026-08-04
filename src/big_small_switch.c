#include "global.h"
#include "data.h"
#include "functions.h"
#include "task.h"
#include "main.h"
#include "object.h"
#include "kirby.h"
#include "bonus.h"
#include "constants/songs.h"

struct BigSmallSwitch {
    /* 0x00 */ struct Object2 obj2;
    /* 0xB4 */ s16 timer;
    /* 0xB6 */ u16 switchFlags;
    /* 0xB8 */ u16 isBig;
}; /* size = 0xBC */

static void sub_08119980(struct BigSmallSwitch *);
void sub_08119A20(struct BigSmallSwitch *);
void sub_08119AA8(struct BigSmallSwitch *);
void sub_08119B3C(struct BigSmallSwitch *);
void sub_08119BB8(struct BigSmallSwitch *);
static void sub_08119C0C(struct BigSmallSwitch *);

extern void (*const gUnk_08357B8C[])(void);

void *CreateSmallSwitch(struct Object *arg0, u8 arg1) {
    struct BigSmallSwitch *x;
    struct Task *task = TaskCreate(ObjectMain, sizeof(struct BigSmallSwitch), 0x1001, TASK_USE_IWRAM, ObjectDestroy);

    x = TaskGetStructPtr(task);
    InitObject(&x->obj2, arg0, arg1);
    x->obj2.base.flags |= 0x02608000;
    x->obj2.base.unk68 &= ~7;
    x->obj2.base.unk5C |= 0x00308020;
    x->obj2.base.unkC |= 1;
    x->isBig = 0;
    sub_0803E2B0(&x->obj2.base, -7, -0xA, 7, -2);
    sub_0803E308(&x->obj2.base, -7, -0xA, 7, -2);
    x->obj2.base.y = (((x->obj2.base.y + (x->obj2.base.unk3F << 8)) + 0xFFF) & ~0xFFF) - (x->obj2.base.unk3F << 8) - 1;
    x->obj2.base.unk4C = x->obj2.base.y;
    ObjectInitSprite(&x->obj2);
    gUnk_08351648[x->obj2.type].unk10(&x->obj2);
    return x;
}

void *CreateBigSwitch(struct Object *arg0, u8 arg1) {
    struct BigSmallSwitch *x;
    struct Task *task = TaskCreate(ObjectMain, sizeof(struct BigSmallSwitch), 0x1000, TASK_USE_IWRAM, ObjectDestroy);

    x = TaskGetStructPtr(task);
    InitObject(&x->obj2, arg0, arg1);
    x->obj2.base.flags |= 0x02308000;
    x->obj2.base.unk68 &= ~7;
    x->obj2.base.unk5C |= ~0x87;
    x->isBig = 1;
    sub_0803E2B0(&x->obj2.base, -0xE, -0x18, 0xE, 0);
    sub_0803E308(&x->obj2.base, -0xE, -0x18, 0xE, 0);
    ObjectInitSprite(&x->obj2);
    gUnk_08351648[x->obj2.type].unk10(&x->obj2);
    return x;
}

void sub_0811938C(struct Object2 *obj2) {
    struct BigSmallSwitch *x = (struct BigSmallSwitch *)obj2;
    struct BigSmallSwitch *x2 = x;

    ObjectSetFunc(x, 0, sub_08119980);
    if (x->isBig != 0) {
        if (*sub_08002888(2, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E) != 0) {
            x->obj2.unk78 = sub_08119C0C;
            x->obj2.base.flags |= 0xF40;
            return;
        }
    }
    x2->timer = 0;
    x2->switchFlags = 0;
    {
        u16 v = x->obj2.object->unk18;
        if (v != 0) {
            x2->switchFlags = 0x400;
        } else if (x->obj2.object->unk22 & 4) {
            v |= 0x400;
            x2->switchFlags = v;
        }
    }
}

bool32 sub_0811942C(struct BigSmallSwitch *x) {
    if (x->obj2.base.y >> 8 >= gCurLevelInfo[x->obj2.base.unk56].roomHeight - 0x14) {
        x->obj2.base.flags |= 0x40;
        if (x->obj2.base.xspeed < 0) {
            x->obj2.base.xspeed += 0x200;
            if (x->obj2.base.xspeed > 0) {
                x->obj2.base.xspeed = 0;
            }
        } else {
            x->obj2.base.xspeed += -0x200;
            if (x->obj2.base.xspeed < 0) {
                x->obj2.base.xspeed = 0;
            }
        }
        if (x->obj2.base.yspeed < 0) {
            x->obj2.base.yspeed += 0x200;
            if (x->obj2.base.yspeed > 0) {
                x->obj2.base.yspeed = 0;
            }
        } else {
            x->obj2.base.yspeed += -0x200;
            if (x->obj2.base.yspeed < 0) {
                x->obj2.base.yspeed = 0;
            }
        }
    }
    if (x->obj2.base.flags & 0x40) {
        return FALSE;
    }
    return TRUE;
}

// sub_081194DC: functionally equivalent; remaining diff is register allocation only.
#ifndef NONMATCHING
NAKED bool32 sub_081194DC(struct BigSmallSwitch *x) {
    asm(".include \"asm/nonmatching/sub_081194DC.inc\"");
}
#else
bool32 sub_081194DC(struct BigSmallSwitch *x) {
    struct Object2 **list;
    s16 mine[4];
    s16 other[4];
    u8 i;

    if (!sub_0811942C(x)) {
        return FALSE;
    }

    list = sub_08039490(&x->obj2.base);
    mine[0] = x->obj2.base.unk3C + (x->obj2.base.x >> 8);
    mine[1] = x->obj2.base.unk3D + (x->obj2.base.y >> 8);
    mine[2] = x->obj2.base.unk3E + (x->obj2.base.x >> 8);
    mine[3] = x->obj2.base.unk3F + (x->obj2.base.y >> 8);
    for (; *list != NULL; list++) {
        struct Object2 *o = *list;
        if (o->type == 0x79 || o->type == 0x7D) {
            other[0] = o->base.unk3C + (o->base.x >> 8);
            other[1] = o->base.unk3D + (o->base.y >> 8);
            other[2] = o->base.unk3E + (o->base.x >> 8);
            other[3] = o->base.unk3F + (o->base.y >> 8);
            if (((mine[0] <= other[0] && other[0] <= mine[2]) || (other[0] <= mine[0] && mine[0] <= other[2]))
             && ((mine[1] <= other[1] && other[1] <= mine[3]) || (other[1] <= mine[1] && mine[1] <= other[3]))) {
                return TRUE;
            }
        }
    }

    if (!(x->obj2.object->unk22 & 2)) {
        if (x->switchFlags & 0x400) {
            if (x->obj2.base.flags & 0x40000) {
                goto held;
            }
            if (x->obj2.base.flags & 0x1000000) {
                return TRUE;
            }
        } else {
            for (i = 0; i < gUnk_0203AD44; i++) {
                if (gKirbys[i].base.base.base.unk56 != x->obj2.base.unk56) {
                    continue;
                }
                other[0] = gKirbys[i].base.base.base.unk38 + (gKirbys[i].base.base.base.x >> 8);
                other[1] = gKirbys[i].base.base.base.unk39 + (gKirbys[i].base.base.base.y >> 8);
                other[2] = gKirbys[i].base.base.base.unk3A + (gKirbys[i].base.base.base.x >> 8);
                other[3] = gKirbys[i].base.base.base.unk3B + (gKirbys[i].base.base.base.y >> 8);
                if (((mine[0] <= other[0] && other[0] <= mine[2]) || (other[0] <= mine[0] && mine[0] <= other[2]))
                 && ((mine[1] <= other[1] && other[1] <= mine[3]) || (other[1] <= mine[1] && mine[1] <= other[3]))) {
                    if (!(gKirbys[i].base.base.base.unkC & 0x8000)) {
                        return TRUE;
                    }
                } else if (x->obj2.base.flags & 0x1000000) {
                    return TRUE;
                }
            }
        }
    }

    if (x->obj2.base.flags & 0x40000) {
        struct ObjectBase *held6C;
held:
        if (x->isBig == 0) {
            return TRUE;
        }
        held6C = x->obj2.base.unk6C;
        if (held6C->unk56 < gUnk_0203AD30) {
            if (x->switchFlags & 0x2000) {
                return TRUE;
            }
            BonusCreateTomato((struct Kirby *)held6C);
            return TRUE;
        }
    }
    return FALSE;
}
#endif

// sub_081197D4: functionally equivalent; remaining diff is register allocation only.
#ifndef NONMATCHING
NAKED void sub_081197D4(struct BigSmallSwitch *x) {
    asm(".include \"asm/nonmatching/sub_081197D4.inc\"");
}
#else
void sub_081197D4(struct BigSmallSwitch *x) {
    if (sub_081194DC(x)) {
        register u32 zero asm("r3");
        u16 v = x->switchFlags & ~4;
        zero = 0;
        asm("" : "+r"(zero));
        x->switchFlags = (v | 0x100) | zero;
        if (x->switchFlags & 1) {
            x->switchFlags &= ~2;
        } else {
            x->switchFlags |= 2;
            x->timer = x->obj2.object->unk18 + 2;
            PlaySfx(&x->obj2.base, SE_SWITCH_ACTIVATE);
        }
        {
            u32 bit;
            u16 t = x->switchFlags | 1;
            bit = 0x200;
            asm("" : "+r"(bit));
            x->switchFlags = t | bit;
        }
    } else {
        u16 flags = x->switchFlags;
        if (flags & 1) {
            x->switchFlags = flags & ~2;
        }
        flags = x->switchFlags & ~0x100;
        x->switchFlags = flags;
        if (x->timer <= 0) {
            if (!(x->obj2.object->unk22 & 4)) {
                {
                    u32 m;
                    u16 f1 = flags & ~0x20;
                    u16 f2;
                    m = 0xFFEF;
                    asm("" : "+r"(m));
                    f2 = f1 & m;
                    x->switchFlags = f2;
                    if (f2 & 4) {
                        x->switchFlags = f2 & ~4;
                    }
                }
                if (x->switchFlags & 1) {
                    x->switchFlags |= 4;
                }
                x->switchFlags &= ~1;
            }
        } else {
            if (flags & 0x10) {
                x->switchFlags = flags & ~0x20;
            } else {
                x->switchFlags = flags | 0x20;
            }
            x->switchFlags |= 0x10;
            x->timer--;
        }
    }
}
#endif

static void sub_08119980(struct BigSmallSwitch *x) {
    struct BigSmallSwitch *x2 = x;

    sub_081197D4(x);
    if (x->switchFlags & 1) {
        x->obj2.unk83 = 1;
        if (x->switchFlags & 0x400) {
            x->obj2.base.flags |= 0x10000;
        }
    } else {
        x->obj2.unk83 = 0;
        if (x->obj2.base.flags & 0x10000) {
            x->obj2.base.flags &= ~0x10000;
        }
    }
    if (x->obj2.object->unk22 & 1) {
        sub_08119AA8(x2);
    } else if (x->obj2.object->unk22 & 2) {
        sub_08119B3C(x2);
    } else if (x->obj2.object->unk22 & 0x8000) {
        sub_08119BB8(x2);
    } else {
        sub_08119A20(x2);
    }
    x->obj2.base.counter++;
}

void sub_08119A20(struct BigSmallSwitch *x) {
    u32 *p;

    if (x->switchFlags & 2) {
        p = sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E);
        *p = *p + 1;
    } else if (x->switchFlags & 4) {
        p = sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E);
        if (*p != 0) {
            *p = *p - 1;
        }
    }
}

void sub_08119AA8(struct BigSmallSwitch *x) {
    u8 *q = (u8 *)sub_08002888(0, x->obj2.object->unk4, gCurLevelInfo[x->obj2.base.unk56].unk65E);
    u32 pressed = x->switchFlags & 1;

    if (pressed) {
        u8 t0 = x->obj2.object->unk14 >> 8;
        u8 zero = 0;
        q[0] = t0;
        q[1] = x->obj2.object->unk14;
        q[2] = x->obj2.object->unk12 >> 8;
        q[3] = zero;
    } else {
        u16 a = x->obj2.object->unk14 >> 8;
        u8 b = x->obj2.object->unk14;
        u16 c = x->obj2.object->unk12 >> 8;
        if (q[0] == a && q[1] == b) {
            u32 q2 = q[2];
            u8 match;
#ifndef NONMATCHING
            asm("" : "+r"(q2));
#endif
            match = 1;
            if (q2 != c) {
                match = 0;
            }
            if (match) {
                q[0] = pressed;
                q[1] = pressed;
                q[2] = pressed;
                q[3] = pressed;
            }
        }
    }
}

void sub_08119B3C(struct BigSmallSwitch *);
void sub_08119BB8(struct BigSmallSwitch *);
static void sub_08119C0C(struct BigSmallSwitch *);

extern void (*const gUnk_08357B8C[])(void);

void sub_08119B3C(struct BigSmallSwitch *x) {
    if ((x->switchFlags & 0x3000) == 0x2000) {
        x->obj2.base.flags |= 0xF40;
    }
    if (x->switchFlags & 2) {
        x->switchFlags |= 0x1000;
        x->switchFlags |= 0x2000;
    }
    if (x->switchFlags & 0x1000) {
        if (sub_080395D4()) {
            gUnk_08357B8C[x->obj2.object->unk14]();
            x->switchFlags &= ~0x1000;
        }
    }
}

void nullsub_127(void) {}

void sub_08119BB8(struct BigSmallSwitch *x) {
    u32 *p;

    sub_08119A20(x);
    if (x->switchFlags & 1) {
        p = sub_08002888(0, 0xF, gCurLevelInfo[x->obj2.base.unk56].unk65E);
        if (*p < x->obj2.object->unk11) {
            *p = x->obj2.object->unk11;
        }
    }
}

static void sub_08119C0C(struct BigSmallSwitch *x) {
    x->obj2.base.flags |= 0x1000;
}
