struct Range124328 {
    int m0;
    float a;
    float b;
    int mC;
    Range124328();
};

struct Sub_001258D8 {
    char pad[0x20];
    float m20;
    float m24;
    char pad28[0x50 - 0x28];
};

struct Obj_001258D8 {
    char pad[0x188];
    float m188;
    float m18C;
};

struct C_001258D8 {
    char pad0[0x48];
    Obj_001258D8* m48;
    char pad4C[0xD0 - 0x4C];
    Sub_001258D8 mD0;
    int GetRange(void* params, float* a, float* b);
};

extern "C" int func_001E8180(void* params, unsigned int id, void** out, int req);
extern "C" int func_001E8998(void* params, unsigned int id, Range124328* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int id);

int C_001258D8::GetRange(void* params, float* a, float* b)
{
    Range124328 r;
    void* s;
    if (func_001E8180(params, 0x7F261953, &s, 0)) {
        func_001E8998(s, 0, &r, 1);
        if (func_001E8708(s, 0x91A4C826)) {
            Sub_001258D8* d = &mD0;
            *a = d->m20 + r.a;
            *b = d->m24 + r.b;
        } else if (func_001E8708(s, 0xB922906A)) {
            *a = r.a * m48->m188;
            *b = r.b * m48->m18C;
        }
        return 1;
    }
    if (func_001E8998(params, 0x7F261953, &r, 0)) {
        *a = r.a;
        *b = r.b;
        return 1;
    }
    return 0;
}
