struct Heap_001EA538 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001EA538* D_00388A70;

struct Pair_001EA538 {
    int m0;
    int m4;
    int m8;
};

struct Vec_001EA538 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Array_001EA538;

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void func_001E6518(Array_001EA538*);
extern "C" void func_001E8E98(Array_001EA538*, unsigned int, int);
extern "C" int func_001EC7A0(unsigned char*);
extern "C" void func_001E90A8(Array_001EA538*, unsigned int, int);
extern "C" void func_001E90D0(Array_001EA538*, unsigned int, float);
extern "C" void func_001E90F8(Array_001EA538*, unsigned int, int);
extern "C" void* func_001E4DE0(unsigned char*);
extern "C" void func_001E9058(Array_001EA538*, unsigned int, void*);
extern "C" void func_001E9080(Array_001EA538*, unsigned int, void*);
extern "C" unsigned int func_00331BB8(unsigned char*);
extern "C" void* func_001E8C30(unsigned int);
extern "C" Pair_001EA538* func_001E4C80(void*);
extern "C" void func_001E9148(Array_001EA538*, unsigned int, Pair_001EA538*);
extern "C" void* func_001E8C80(unsigned int);
extern "C" Vec_001EA538* func_001E4C68(void*);
extern "C" void func_001E9120(Array_001EA538*, unsigned int, Vec_001EA538*);
extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" unsigned char* func_001E9D70(void*, unsigned char*);
extern "C" void func_001E9170(Array_001EA538*, unsigned int, void*);
extern "C" void* func_00122CF8(unsigned int);
extern "C" Array_001EA538* func_001E8DD0(void*);
extern "C" void func_001E9198(Array_001EA538*, unsigned int, Array_001EA538*);

static inline float ReadFloat_001EA538(unsigned char* p)
{
    union {
        int i;
        float f;
    } u;
    u.i = func_001EC7A0(p);
    return u.f;
}

extern "C" unsigned char* func_001EA538(Array_001EA538* a, unsigned char* p)
{
    func_001E6518(a);
    unsigned char type = *p++;
    unsigned int n = *p++;
    n += *p++ << 8;
    func_0010A950(D_00388A70, D_00388A70->mEC);
    func_001E8E98(a, n, type);
    func_0010A9B0(D_00388A70);
    switch (type) {
    case 0:
        break;
    case 1:
        for (unsigned int i = 0; i < n; i++) {
            int v = func_001EC7A0(p);
            p += 4;
            func_001E90A8(a, i, v);
        }
        break;
    case 2:
        for (unsigned int i = 0; i < n; i++) {
            float v = ReadFloat_001EA538(p);
            p += 4;
            func_001E90D0(a, i, v);
        }
        break;
    case 13:
        for (unsigned int i = 0; i < n; i++) {
            int v = func_001EC7A0(p);
            p += 4;
            func_001E90F8(a, i, v);
        }
        break;
    case 3:
        for (unsigned int i = 0; i < n; i++) {
            func_001E9058(a, i, func_001E4DE0(p));
            p += func_00331BB8(p) + 1;
        }
        break;
    case 4:
        for (unsigned int i = 0; i < n; i++) {
            func_001E9080(a, i, func_001E4DE0(p));
            p += func_00331BB8(p) + 1;
        }
        break;
    case 5:
        for (unsigned int i = 0; i < n; i++) {
            Pair_001EA538* v = func_001E4C80(func_001E8C30(12));
            v->m4 = func_001EC7A0(p);
            p += 4;
            v->m8 = func_001EC7A0(p);
            p += 4;
            func_001E9148(a, i, v);
        }
        break;
    case 6:
        for (unsigned int i = 0; i < n; i++) {
            Vec_001EA538* v = func_001E4C68(func_001E8C80(16));
            v->m4 = func_001EC7A0(p);
            p += 4;
            v->m8 = func_001EC7A0(p);
            p += 4;
            v->mC = func_001EC7A0(p);
            p += 4;
            func_001E9120(a, i, v);
        }
        break;
    case 10:
        for (unsigned int i = 0; i < n; i++) {
            void* s = func_001E6978(func_001190D0(8));
            p = func_001E9D70(s, p);
            func_001E9170(a, i, s);
        }
        break;
    case 12:
        for (unsigned int i = 0; i < n; i++) {
            Array_001EA538* s = func_001E8DD0(func_00122CF8(16));
            p = func_001EA538(s, p);
            func_001E9198(a, i, s);
        }
        break;
    }
    return p;
}
