// LOCAL-ONLY — DO NOT SUBMIT UPSTREAM.
//
// asm/sprite.s is claimed by another contributor under upstream PR #367.
// This file exists to unblock the WebAssembly port (~/Desktop/katam-port),
// which cannot draw a single sprite until sub_08155128 has a C body: every
// object in the game reaches OAM through it, 521 references, and while it is
// stubbed nothing but backgrounds renders.
//
// Therefore:
//   * Nothing here is ever to be opened as a pull request, and nothing here
//     is wired into linker.ld or the build. asm/sprite.o still supplies the
//     real code; this file is compiled only for verification and consumed
//     only by the port.
//   * CORRECT C IS THE GOAL. A byte match is a bonus, not the bar. The port
//     needs behaviour, and duplicating #367's matching effort is explicitly
//     not what this is for.
//   * If #367 lands, this file should be deleted, not merged.
//
// Verify a function here with:
//   python3 ~/Desktop/katam-mcheck.py wip/sprite.c asm/sprite.s

#include "gba/m4a.h"
#include "portable.h"
#include "data.h"
#include "sprite.h"
#include "main.h"
#include "task.h"
