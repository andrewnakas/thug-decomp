extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001E7360(void* s, int a, unsigned int name);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

struct Comp_001B6220 {
    int m_pad[7];
    int m1C;
};

struct Thing_001B6220 {
    int m_pad[47];
    void* mBC;
};

extern "C" Thing_001B6220* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);

static inline void SetRef_001B6220(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_001B6220 {
    int m_pad[3];
    void* mC;
    int m10[4];
    unsigned int m20;
    void Spawn(void* params, int flag);
};

extern "C" void func_001B5E78(C_001B6220* self);
extern "C" void* func_001B4D00(C_001B6220* self, void* params);
extern "C" void* func_001B5450(C_001B6220* self, void* params, int flag);

void C_001B6220::Spawn(void* params, int flag)
{
    func_001B5E78(this);
    Comp_001B6220* comp = (Comp_001B6220*)func_00185578(mC, 0x0A015E17);
    void* s = func_001B4D00(this, params);
    void* t = func_001B5450(this, params, flag);
    func_001E6AC8(s, t);
    if (t) func_001E6AE8(t, 3);
    if (flag) {
        m20 &= ~2u;
        func_001E7360(s, 0, 0x01615618);
    }
    if (comp->m1C & 0x100) {
        func_001E7200(s, 0x65B5788D, 1);
    } else {
        func_001E7200(s, 0x65B5788D, 0);
    }
    if (func_001E8708(params, 0xB02567AE)) {
        m20 = (m20 & ~2u) | 0x800;
    }
    Thing_001B6220* th = func_001F0750(0xB83C383C, s, 0, 0, -1, 0, 0, 0, 0, 0);
    SetRef_001B6220(&th->mBC, mC);
    if (s) func_001E6AE8(s, 3);
}
