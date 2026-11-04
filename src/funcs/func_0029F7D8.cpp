extern "C" void func_00183CB8(void* p, void* pp);

struct Ref_0029F7D8 {
    void* p;
    int pad[3];
    ~Ref_0029F7D8() {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
};

struct Sub_0029F7D8 {
    char pad[0x20];
    unsigned int m20;
};

extern void* D_00389A30;
extern char D_00377D58[];
extern char D_00377D68[];
extern char D_00392088[];
extern "C" int func_001F0D78(char* s);
extern "C" void func_0012DB48(Ref_0029F7D8* out, void* t, int crc, int a);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001841F0(void* p, void* s);
extern "C" bool func_001E84E8(void* s, char* name, int* out, int a);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_002A8260(void* p, int v);

struct Obj_0029F7D8 {
    char pad[0x1C];
    Sub_0029F7D8* m1C;
    char pad2[0x2C - 0x20];
    void* m2C;
    void Check();
};

void Obj_0029F7D8::Check()
{
    void* t = D_00389A30;
    void* y = m2C;
    void* p;
    {
        Ref_0029F7D8 r;
        func_0012DB48(&r, t, func_001F0D78(D_00377D58), 0);
        p = r.p;
    }
    if (p) {
        void* s = func_001E6978(func_001190D0(8));
        func_001841F0(p, s);
        int v;
        func_001E84E8(s, D_00377D68, &v, 0);
        if (s)
            func_001E6AE8(s, 3);
        if (v == func_001F0D78(D_00392088))
            return;
    }
    if (m1C->m20 & 0x40)
        func_002A8260(y, 1);
}
