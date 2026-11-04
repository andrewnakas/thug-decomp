struct Inner_0027D9F0 {
    char pad0[0x2C];
    int m2C;
};

struct Sub_0027D9F0 {
    char pad0[0x24];
    Inner_0027D9F0 m24;
    char pad54[0x164];
    int m1B8;
};

struct Body_0027D9F0 {
    char pad0[0xB0];
    float vx, vy, vz;
};

struct Flags_0027D9F0 {
    char pad0[0x28];
    int m28;
};

struct Obj_0027D9F0 {
    char pad0[0xC];
    Body_0027D9F0* mC;
    char pad10[0x354];
    int m364;
    char pad368[0x8];
    int m370;
    char pad374[0x220];
    Sub_0027D9F0* m594;
    char pad598[0x18];
    Flags_0027D9F0* m5B0;
    int Check();
};

extern "C" float sqrtf(float);
extern "C" float func_00203D40(Body_0027D9F0* b, unsigned int id);

int Obj_0027D9F0::Check()
{
    Sub_0027D9F0* s = m594;
    Inner_0027D9F0* in = &s->m24;
    if (m370 != 0) return 0;
    if (m364 == 0 && s->m1B8 == 0) return 0;
    if (in->m2C) return 0;
    Body_0027D9F0* b = mC;
    float* v = &b->vx;
    float speed = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (!m5B0->m28) {
        if (func_00203D40(b, 0x4610C2E3) < speed) return 0;
    } else {
        if (func_00203D40(b, 0x92E0247C) < speed) return 0;
    }
    return 1;
}
