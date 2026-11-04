struct Heap_001E8F48 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001E8F48* D_00388A70;

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_0010BDE0(unsigned int);
extern "C" void func_0010BEB8(void*);

struct Array_001E8F48 {
    int m0;
    unsigned int* m4;
    int m8;
    unsigned int mC;
};

extern "C" unsigned int* func_001E9038(Array_001E8F48*);

extern "C" void func_001E8F48(Array_001E8F48* a, unsigned int n)
{
    if (n == a->mC)
        return;
    func_0010A950(D_00388A70, D_00388A70->mEC);
    unsigned int* buf = (unsigned int*)func_0010BDE0(n * 4);
    func_0010A9B0(D_00388A70);
    unsigned int* s = func_001E9038(a);
    unsigned int* d = buf;
    unsigned int i;
    for (i = 0; i < a->mC; i++)
        *d++ = *s++;
    unsigned int extra = n - a->mC;
    for (i = 0; i < extra; i++)
        *d++ = 0;
    if (a->mC >= 2)
        func_0010BEB8(a->m4);
    a->m4 = buf;
    a->mC = n;
}
