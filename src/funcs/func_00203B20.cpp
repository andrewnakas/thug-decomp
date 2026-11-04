struct Range_00203B20 {
    int m0;
    float lo;
    float hi;
    int mC;
};

struct Flag_00203B20 {
    char pad0[0x34];
    int m34;
};

struct Model_00203B20 {
    char pad0[0x164];
    int m164;
};

struct Inst_00203B20 {
    char pad0[0xC];
    Model_00203B20* mC;
    char pad10[0x5A0];
    Flag_00203B20* m5B0;
};

struct Obj_00203B20 {
    char pad0[0x2E0];
    Inst_00203B20* m2E0;
    float Calc(int script);
};

extern int D_0038FC78;
extern "C" void func_001E4C80(Range_00203B20* r);
extern "C" int func_001E8998(int s, unsigned int id, Range_00203B20* r, int f);
extern "C" int func_001E7DE8(int s, unsigned int id, int* v, int f);
extern "C" int func_001E7EB0(int s, unsigned int id, float* v, int f);
extern "C" float func_00203868(Obj_00203B20* o, int i);
extern "C" int func_0022E360(int m);
extern "C" int func_00240120(int m, int a);

float Obj_00203B20::Calc(int script)
{
    Range_00203B20 base;
    Range_00203B20 scale;
    func_001E4C80(&base);
    func_001E4C80(&scale);
    func_001E8998(script, 0, &base, 0);
    int idx;
    float f;
    if (!func_001E7DE8(script, 0, &idx, 0)) {
        f = 10.0f;
    } else {
        f = func_00203868(this, idx);
    }
    float lo = base.lo;
    float hi = base.hi;
    float v = lo + (hi - lo) * f * 0.1f;
    int on;
    if (m2E0->mC->m164) on = m2E0->m5B0->m34;
    else on = m2E0->m5B0->m34 ^ 1;
    if (on && func_001E8998(script, 0x9016B4E7, &scale, 0)) {
        float s = scale.lo + (scale.hi - scale.lo) * func_00203868(this, 6) * 0.1f;
        if (s < 0.0f) s = 0.0f;
        if (s > 1.0f) s = 1.0f;
        v *= s;
    }
    int mode = func_00240120(func_0022E360(D_0038FC78), 0);
    if (mode != 1) {
        Range_00203B20 m;
        func_001E4C80(&m);
        if (func_001E8998(script, 0xBA8FB854, &m, 0)) {
            if (mode == 0) v *= m.lo;
            else if (mode == 2) v *= m.hi;
        }
    }
    float lim;
    if (func_001E7EB0(script, 0x8069179F, &lim, 0)) {
        if (lo < hi) {
            if (lim < v) v = lim;
        } else {
            if (v < lim) v = lim;
        }
    }
    return v;
}
