extern void* D_00388A70;
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_0011F8C8(void* p, int v);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Sub_002B3168 {
    int m0;
    char m4[0x5C - 4];
    char m5C[4];
};

struct Obj_002B3168 {
    char pad[0x1C];
    Sub_002B3168* m1C;
    void Destroy(int flags);
};

void Obj_002B3168::Destroy(int flags)
{
    Sub_002B3168* s = m1C;
    if (s) {
        func_001E6AE8(s->m5C, 2);
        func_0011F8C8(s->m4, 2);
        func_0010A8D8(D_00388A70, s);
    }
    if (flags & 1)
        func_0010A8D8(D_00388A70, this);
}
