extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E88B0(void* params, unsigned int name, const char** out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, void** out, int req);
extern "C" unsigned int func_0010FC30();
extern "C" unsigned int func_0033EBE0(float f);
extern "C" const char* func_001E9218(void* arr, int i);
extern char D_0038CF78[];

struct Entry_001AEC48 {
    unsigned char m0;
    unsigned char m1;
    short m2;
    int m4;
    unsigned int m8;
};

struct Array_001AEC48 {
    int m_pad[3];
    int mC;
};

extern "C" Entry_001AEC48* func_001E6E90(void* params, Entry_001AEC48* prev);

struct C_001AEC48 {
    int m_pad[1219];
    int m130C;
    int m1310;
    unsigned int m1314;
    unsigned int m1318;
    int m131C;
    unsigned int m1320[10];
    int m1348[10];
    unsigned int m1370;
    int m1374;
    void Setup(void* params);
};

extern "C" void func_001AF538(C_001AEC48* self, const char* name);

void C_001AEC48::Setup(void* params)
{
    float t = 0.0f;
    m130C = 1;
    m1310 = 1;
    if (func_001E7EB0(params, 0x79A07F3F, &t, 0)) {
        m1310 = 0;
        m1318 = func_0010FC30();
        m1314 = func_0033EBE0(t * 16.666668f);
    }
    m131C = 0;
    unsigned int id = 0;
    if (func_001E8398(params, 0x1E26FD3E, &id, 0)) {
        m131C = 1;
        m1320[0] = id;
    } else {
        Entry_001AEC48* e = 0;
        while ((e = func_001E6E90(params, e))) {
            if (!e->m4 && e->m1 == 0xD) m1320[m131C++] = e->m8;
        }
    }
    m1370 = 0;
    func_001E8398(params, 0xB394C01C, &m1370, 0);
    for (int i = 9; i >= 0; i--) m1348[i] = 0;
    m1374 = 0;
    const char* name = D_0038CF78;
    void* arr = 0;
    if (func_001E88B0(params, 0xF277291D, &name, 0)) {
        func_001AF538(this, name);
        return;
    }
    if (func_001E8248(params, 0xF277291D, &arr, 0)) {
        int n = ((Array_001AEC48*)arr)->mC;
        for (int j = 0; j < n; j++) func_001AF538(this, func_001E9218(arr, j));
    }
}
