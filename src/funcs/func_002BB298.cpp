extern void* D_00388A70;
extern "C" void** func_002C0368();
extern "C" int func_002B74E0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Elem_002BB298 {
    int a[3];
};

struct Obj_002BB298 {
    char pad0[0x28];
    Elem_002BB298* m28;
    unsigned int m2C;
    void Resize(unsigned int n);
};

void Obj_002BB298::Resize(unsigned int n)
{
    Elem_002BB298* p = 0;
    if ((int)n >= 3) {
        void* pool = D_00388A70;
        func_0010A950(pool, func_002B74E0(*func_002C0368()));
        p = (Elem_002BB298*)func_0010A638(D_00388A70, (n - 2) * 12, 1, 0);
        func_0010A9B0(D_00388A70);
    }
    if (p && m28 && n >= m2C) {
        for (unsigned int i = 2; i < m2C; i++) p[i - 2] = m28[i - 2];
    }
    if (m28) func_0010A8D8(D_00388A70, m28);
    m28 = p;
    m2C = n;
}
