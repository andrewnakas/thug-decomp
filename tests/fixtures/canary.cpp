/* Toolchain canary: must always compile to the bytes in canary.sha1 (tools/toolcheck.py). */
#include "common.h"

extern "C" int func_00100030(int n);

struct Canary {
    s32 a;
    s32 b;
    f32 c;
    Canary();
    f32 Step(f32 x);
};

Canary::Canary() { a = 0; b = 0; c = 1.5f; }

f32 Canary::Step(f32 x)
{
    s32 i;
    for (i = 0; i < a; i++) {
        b += func_00100030(i);
    }
    return x * c + (f32)b;
}
