extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001E7360(void* s, int a, unsigned int name);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

struct Comp_001B3920 {
    int m_pad[7];
    int m1C;
};

struct Thing_001B3920 {
    int m_pad[47];
    void* mBC;
};

extern "C" Thing_001B3920* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);

static inline void SetRef_001B3920(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_001B3920 {
    int m_pad[3];
    void* mC;
    void Apply(void* params);
};

extern "C" int func_001B4170(C_001B3920* self, void* params, unsigned int name);
extern "C" void func_001B41E8(C_001B3920* self, float f);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);

void C_001B3920::Apply(void* params)
{
    if (func_001E8708(params, 0x74E4BBA5) && func_001B4170(this, params, 0x922C5B59)) {
        float f;
        func_001E7EB0(params, 0xA04D16EC, &f, 1);
        func_001B41E8(this, f);
    }
    if (func_001E8708(params, 0x55D98ED7) && func_001B4170(this, params, 0x86C9CCCE)) {
        unsigned int id;
        func_001E8398(params, 0x64B4CD9D, &id, 1);
        Thing_001B3920* th = func_001F0750(id, 0, 0, 0, -1, 0, 0, 0, 0, 0);
        SetRef_001B3920(&th->mBC, mC);
    }
}
