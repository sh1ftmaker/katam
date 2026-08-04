#ifndef GUARD_PORTABLE_H
#define GUARD_PORTABLE_H

/* Shims for the ARM/agbcc-specific constructs that exist purely to steer
 * register allocation and instruction scheduling so the compiled output
 * matches the original ROM.  They are meaningless on any other target, so a
 * PORTABLE build compiles them away.  The GBA build must expand to exactly
 * the original text, byte for byte. */

#ifdef PORTABLE

/* `register T v ASM_PIN("r4");` degrades to `register T v;` -- plain C89,
 * where `register` is only a hint and the variable is fully preserved. */
#define ASM_PIN(reg)

#define ASM_BARRIER()
#define ASM_INOUT_R(v) ((void)(v))
#define ASM_OUT_R(v)
#define ASM_USE_R(v) ((void)(v))
#define ASM_USE_R2(v1, v2) ((void)(v1), (void)(v2))
#define ASM_USE_M(v) ((void)(v))
#define ASM_CLOBBER_MEM()
#define ASM_CLOBBER(reg)

#else

#define ASM_PIN(reg) asm(reg)

#define ASM_BARRIER() asm("")
#define ASM_INOUT_R(v) asm("" : "+r"(v))
#define ASM_OUT_R(v) asm("" : "=r"(v))
#define ASM_USE_R(v) asm("" ::"r"(v))
#define ASM_USE_R2(v1, v2) asm("" ::"r"(v1), "r"(v2))
#define ASM_USE_M(v) asm("" ::"m"(v))
#define ASM_CLOBBER_MEM() asm("" ::: "memory")
#define ASM_CLOBBER(reg) asm("" ::: reg)

#endif

#endif /* GUARD_PORTABLE_H */
