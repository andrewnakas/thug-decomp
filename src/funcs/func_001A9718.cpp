extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" int func_001E87B8(void* params, char* name);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void* func_001046B0(int size);
extern char D_003626C8[];

struct Helper_001A9718 {
    char pad0[0x418];
    unsigned int m418;
    char pad41C[0x430 - 0x41C];
    float m430;
    int m434;
    char pad438[0x440 - 0x438];
};

extern "C" Helper_001A9718* func_0025A2E8(void* mem);
extern "C" void func_0025A340(Helper_001A9718* p, int flags);
extern "C" void func_0025A370(Helper_001A9718* p);

struct Comp_001A9718 {
    char pad0[0x60];
    int m60;
};

struct Obj_001A9718 {
    char pad0[0xC];
    void* mC;
    char pad10[0x1C - 0x10];
    int m1C;
    char pad20[0x220 - 0x20];
    Helper_001A9718* m220;
    int m224;
    void Fn(void* params);
};

void Obj_001A9718::Fn(void* params)
{
    if (func_001E8708(params, 0xD443A2BC)) {
        m1C &= ~0x200;
        if (m220) {
            func_0025A340(m220, 3);
            m220 = 0;
        }
    } else {
        m224 = func_001E87B8(params, D_003626C8);
        m1C = (m1C | 0x200) & ~8;
        ((Comp_001A9718*)func_00185578(mC, 0x5CB5CB7E))->m60 = 0;
        if (!m220)
            m220 = func_0025A2E8(func_001046B0(0x440));
        func_0025A370(m220);
        float f = 0.0f;
        func_001E7EB0(params, 0xE36D657E, &f, 0);
        m220->m430 = f;
        unsigned int v = 0;
        func_001E8398(params, 0xA1DC81F9, &v, 0);
        m220->m418 = v;
        if (func_001E8708(params, 0xE19E310A))
            m220->m434 = 1;
    }
}
