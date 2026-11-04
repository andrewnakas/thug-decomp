struct Range124328 {
    int m0;
    float a;
    float b;
    int mC;
    Range124328();
};

struct Ranges_001307E0 {
    float m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
};

extern "C" int func_001E8998(void* params, unsigned int id, Range124328* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

struct C_001307E0 {
    char pad[0x500];
    Ranges_001307E0 m500;
    Ranges_001307E0* Load(void* params, unsigned int* out);
};

extern "C" void func_00130780(C_001307E0* self, unsigned int ms);

Ranges_001307E0* C_001307E0::Load(void* params, unsigned int* out)
{
    Range124328 r1;
    if (func_001E8998(params, 0x21DE240C, &r1, 0)) {
        m500.m0 = r1.a;
        m500.m4 = r1.b;
    }
    Range124328 r2;
    if (func_001E8998(params, 0x3E10436D, &r2, 0)) {
        m500.m8 = r2.a;
        m500.mC = r2.b;
    }
    Range124328 r3;
    if (func_001E8998(params, 0x4C2A3CDE, &r3, 0)) {
        m500.m10 = r3.a;
        m500.m14 = r3.b;
    }
    float t;
    unsigned int ms;
    if (func_001E7EB0(params, 0x906B67BA, &t, 0))
        ms = (unsigned int)(t * 1000.0f);
    else
        ms = 0;
    func_00130780(this, ms);
    if (out)
        *out = ms;
    return &m500;
}
