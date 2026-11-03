struct Arr_002935C8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Vec_002935C8 {
    float x, y, z, w;
};

struct Ent_002935C8 {
    Vec_002935C8 v;
    float a;
    float b;
    char pad[0x30 - 0x18];
};

extern "C" void func_00292630(void* self);
extern "C" int func_00291E80(void* params);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E8398(void* p, unsigned int key, int* out, int req);
extern "C" void func_00294C80(void* self, int v);
extern "C" int func_001E7C80(void* p, unsigned int key, char** out, int req);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_001E8248(void* p, unsigned int key, Arr_002935C8** out, int req);
extern "C" void* func_001E9378(Arr_002935C8* a, int i);
extern "C" bool func_001E7FA8(void* s, unsigned int name, Vec_002935C8* v, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int a);
extern "C" void func_002945E8(void* self, void* params);
extern char D_00391E10[];

struct Obj_002935C8 {
    int m0;
    char m4[0x36 - 0x4];
    char m36[0x4B - 0x36];
    char m4B[0xAF - 0x4B];
    char mAF[0x114 - 0xAF];
    int m114;
    char pad118[0x130 - 0x118];
    Ent_002935C8 m130[(0x2A1 - 0x130) / 0x30];
    char pad[0x2A1 - 0x130 - ((0x2A1 - 0x130) / 0x30) * 0x30];
    unsigned char m2A1;
    unsigned char pad2A2[2];
    unsigned char m2A4;
    unsigned char m2A5;
    char pad2A6[2];
    int m2A8;
    int m2AC;
    int m2B0;
    int m2B4;
    void Load(void* params);
};

void Obj_002935C8::Load(void* params)
{
    func_00292630(this);
    m2A4 = 0;
    m2A5 = 1;
    m0 = func_00291E80(params);
    func_001E7DE8(params, 0x60CE75AE, &m2A8, 0);
    func_001E8398(params, 0x6D11ED74, &m114, 0);
    func_00294C80(this, m114);
    func_001E7DE8(params, 0xCD66C8AE, &m2B4, 0);
    func_001E7DE8(params, 0xC51BF6E3, &m2AC, 0);
    func_001E8398(params, 0x81CFF663, &m2B0, 0);
    char* str;
    str = D_00391E10;
    func_001E7C80(params, 0x4BC5229D, &str, 0);
    func_00331A9C(m4, str);
    str = D_00391E10;
    func_001E7C80(params, 0x0C5D7E6B, &str, 0);
    func_00331A9C(m4B, str);
    str = D_00391E10;
    func_001E7C80(params, 0x5DE57284, &str, 0);
    func_00331A9C(mAF, str);
    str = D_00391E10;
    func_001E7C80(params, 0xB9426608, &str, 0);
    func_00331A9C(m36, str);
    Arr_002935C8* arr = 0;
    if (func_001E8248(params, 0x32DF12E0, &arr, 0)) {
        int c = arr->mC;
        m2A1 = c;
        for (unsigned int i = 0; i < m2A1; i++) {
            void* s = func_001E9378(arr, i);
            func_001E7FA8(s, 0x7F261953, &m130[i].v, 0);
            func_001E7EB0(s, 0x0AB21AF0, &m130[i].a, 0);
            func_001E7EB0(s, 0xFF7EBAF6, &m130[i].b, 0);
        }
    }
    func_002945E8(this, params);
}
