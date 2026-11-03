extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001E7360(void* s, int a, unsigned int name);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

struct Comp_001B5DA8 {
    int m_pad[7];
    int m1C;
};

struct Thing_001B5DA8 {
    int m_pad[47];
    void* mBC;
};

extern "C" Thing_001B5DA8* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);

static inline void SetRef_001B5DA8(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_001B5DA8 {
    int m_pad[3];
    void* mC;
    int m10[4];
    unsigned int m20;
    void Spawn(void* params);
};

extern "C" void func_001B5E78(C_001B5DA8* self);
extern "C" void* func_001B4D00(C_001B5DA8* self, void* params);

void C_001B5DA8::Spawn(void* params)
{
    func_001B5E78(this);
    m20 |= 0x1000;
    void* s = func_001B4D00(this, params);
    Thing_001B5DA8* th = func_001F0750(0x365B2D85, s, 0, 0, -1, 0, 0, 0, 0, 0);
    SetRef_001B5DA8(&th->mBC, mC);
    if (s) func_001E6AE8(s, 3);
}
