struct Heap_001E8E98 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001E8E98* D_00388A70;

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_0010BDE0(unsigned int);

struct Array_001E8E98 {
    int m0;
    unsigned int* m4;
    int m8;
    unsigned int mC;
};

extern "C" void func_001E8E38(Array_001E8E98*);

extern "C" void func_001E8E98(Array_001E8E98* a, unsigned int n, int type)
{
    func_001E8E38(a);
    a->m8 = type;
    a->mC = n;
    if (n) {
        if (n != 1) {
            func_0010A950(D_00388A70, D_00388A70->mEC);
            a->m4 = (unsigned int*)func_0010BDE0(a->mC * 4);
            func_0010A9B0(D_00388A70);
            unsigned int* p = a->m4;
            for (unsigned int i = 0; i < a->mC; i++)
                *p++ = 0;
        }
    } else {
        a->m8 = 0;
    }
}
