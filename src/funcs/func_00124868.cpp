struct Range124328 {
    int m0;
    float a;
    float b;
    int mC;
    Range124328();
};

struct Color124868 {
    unsigned char r, g, b, a;
};

extern "C" int func_001E8998(void* params, unsigned int id, Range124328* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" int func_0033EBE0(float f);

struct C_00124868 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
    char pad10[0x70];
    float m80;
    char pad84[0x114];
    float m198;
    void Update(void* params);
};

extern "C" int func_001258D8(C_00124868* self, void* params, float* a, float* b);
extern "C" void func_00123A18(C_00124868* self, float a, float b, int f);
extern "C" void func_00123EB0(C_00124868* self, float a, int f);
extern "C" void func_00123DB0(C_00124868* self, bool b, int f, float lo, float hi);
extern "C" void func_00123F00(C_00124868* self, int v);
extern "C" int func_00125B78(C_00124868* self, void* params, unsigned int id, Color124868* c);
extern "C" void func_00123FE0(C_00124868* self, const Color124868& c, int f);

void C_00124868::Update(void* params)
{
    float a;
    float b;
    if (func_001258D8(this, params, &a, &b))
        func_00123A18(this, a, b, 0);
    if (func_001E8708(params, 0x5D8BB535))
        func_00123EB0(this, m198, 0);
    float f;
    if (func_001E7EB0(params, 0x2F1FC695, &f, 0)) {
        if (func_001E8708(params, 0xFF8DF26B))
            m198 = m80;
        func_00123EB0(this, f, 0);
    }
    bool flag = func_001E8708(params, 0xE1F4711F) != 0;
    float g;
    if (func_001E7EB0(params, 0x13B9DA7B, &g, 0))
        func_00123DB0(this, flag, 0, g, g);
    Range124328 r;
    if (func_001E8998(params, 0x13B9DA7B, &r, 0))
        func_00123DB0(this, flag, 0, r.a, r.b);
    float t;
    int v;
    if (func_001E7EB0(params, 0x906B67BA, &t, 0))
        v = func_0033EBE0(t * 1000.0f);
    else
        v = 0;
    func_00123F00(this, v);
    mC &= ~0x300;
    unsigned int id = 0;
    if (func_001E8398(params, 0x98549BA4, &id, 0)) {
        if (id == 0xF5B95CE4)
            mC |= 0x100;
        else if (id == 0x6AA7DD49)
            mC |= 0x200;
        else if (id == 0x768F6843)
            mC |= 0x300;
    }
    Color124868 c;
    if (func_00125B78(this, params, 0x3F6BCDBA, &c))
        func_00123FE0(this, Color124868(c), 0);
}
