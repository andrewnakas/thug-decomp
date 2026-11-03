extern char D_00371C78[];

struct Iter_002D7738 {
    int m0;
    int m4;
    void* m8;
    Iter_002D7738() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002D7738() { m8 = D_00371C78; }
};

struct Pool_002D7738 {
    char pad0[0x104];
    int m104;
};

struct Elem_002D7738 {
    char pad0[0x28];
    int m28;
    char pad2C[0x34 - 0x2C];
    char m34[4];
};

extern Pool_002D7738* D_00388A70;
extern void* D_00392068;
extern char D_00392DD0[];
extern char D_00392DB8[];
extern char D_0037C528[];
extern char D_0037C480[];
extern char D_0037C4D0[];
extern char D_0037C4C0[];
extern char D_00392D98[];
extern char D_00392DA0[];
extern char D_0037C468[];
extern char D_00392DC8[];
extern char D_0037C538[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" Elem_002D7738* func_002A53F8(void* self, Iter_002D7738* it, int a);
extern "C" Elem_002D7738* func_002A5490(void* self, Iter_002D7738* it, int a);
extern "C" int func_002B1FC8(Elem_002D7738* e);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7318(void* p, char* name, float v);
extern "C" void func_001E7860(void* p, char* name, void* v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Obj_002D7738 {
    int Has(int id);
    void Send();
};

extern "C" int func_002D8160(Obj_002D7738* self, int id);

void Obj_002D7738::Send()
{
    Iter_002D7738 it;
    void* t = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    for (Elem_002D7738* e = func_002A53F8(t, &it, 1); e; e = func_002A5490(t, &it, 1)) {
        if (func_002B1FC8(e)) continue;
        if (!e->m28) continue;
        if (func_002D8160(this, e->m28)) continue;
        void* p = func_001E6978(func_001190D0(8));
        func_001E7138(p, D_00392DD0, e->m34);
        func_001E73C8(p, D_00392DB8, e->m28);
        func_001E73C8(p, D_0037C480, func_001F0D78(D_0037C528));
        func_001E73C8(p, D_0037C4C0, func_001F0D78(D_0037C4D0));
        void* q = func_001E6978(func_001190D0(8));
        func_001E7268(q, D_00392D98, e->m28);
        func_001E7138(q, D_00392DA0, e->m34);
        func_001E7860(p, D_0037C468, q);
        func_001E7318(p, D_00392DC8, 1.1f);
        func_001F0370(D_0037C538, p, 0, 0);
        if (p) func_001E6AE8(p, 3);
        if (q) func_001E6AE8(q, 3);
    }
    func_0010A9B0(D_00388A70);
}
