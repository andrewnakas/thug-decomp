struct Comp_0028FE40 {
    char pad[0xC];
    int mC;
};

extern "C" void func_001848F0(Comp_0028FE40* c, unsigned int name, int v);

struct Obj_0028FE40 {
    char pad0[0xC];
    Comp_0028FE40* mC;
    char pad10[0x1C - 0x10];
    float m1C;
    float m20;
    float m24;
    float m28;
    void Check();
};

extern "C" float func_002901A0(Obj_0028FE40* o);
extern "C" float func_00290238(Obj_0028FE40* o);

void Obj_0028FE40::Check()
{
    float t = 0.0f;
    if (m1C != 0.0f) {
        t = func_002901A0(this);
        if (t <= m1C) {
            func_001848F0(mC, 0xDB7413FB, 0);
            if ((mC->mC & 1) == 0) func_001848F0(mC, 0x5E8EB123, 0);
        } else {
            if (func_00290238(this) <= m1C) func_001848F0(mC, 0x5E8EB123, 0);
            t = 0.0f;
        }
    }
    if (m20 != 0.0f) {
        if (t == 0.0f) t = func_002901A0(this);
        if (m20 <= t && (mC->mC & 1) == 0) func_001848F0(mC, 0xA41F5336, 0);
    }
    if (m24 != 0.0f) {
        if (t == 0.0f) t = func_002901A0(this);
        if (t <= m24 && (mC->mC & 1) == 0) func_001848F0(mC, 0xFAEEC40F, 0);
    }
    if (m28 != 0.0f) {
        if (t == 0.0f) t = func_002901A0(this);
        if (m28 <= t && (mC->mC & 1) == 0) func_001848F0(mC, 0x9C5AF1A0, 0);
    }
}
