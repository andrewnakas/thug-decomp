extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;
extern "C" bool func_001E8A30(void* params, unsigned int name, void* out, int required);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* s, void* src);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" void func_001E7360(void* s, unsigned int id, unsigned int v);

struct Elem_0019FB58 {
    int m0;
    char pad4[0xF0 - 0x4];
    Elem_0019FB58() { m0 = 0; }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Sub_0019FB58 {
    char pad0[0x18];
    int m18;
};

struct Obj_0019FB58 {
    char pad0[0xC];
    Sub_0019FB58* mC;
    char pad10[0x4C - 0x10];
    int m4C;
    char pad50[0x64 - 0x50];
    Elem_0019FB58* m64;
    void Fn(void* params);
};

extern "C" void func_0019FB18(Obj_0019FB58* self, int v);
extern "C" void func_0019FAB8(Obj_0019FB58* self);
extern "C" void func_001A0F10(Obj_0019FB58* self, unsigned int name, float t);
extern "C" void func_001A1790(Obj_0019FB58* self, int a, int b);
extern "C" void func_001A27A0(Obj_0019FB58* self, void* s);

void Obj_0019FB58::Fn(void* params)
{
    int v;
    unsigned int anim;
    func_001E8A30(params, 0x5B8C6DC2, &m4C, 0);
    if (func_001E8A30(params, 0x6C2BFB7F, &v, 0)) {
        func_0019FB18(this, v);
        func_0019FAB8(this);
        if (func_001E8A30(params, 0xEAE64B47, &anim, 0)) {
            func_001A0F10(this, anim, 0.3f);
            func_001A1790(this, 1, 1);
        } else {
            func_001A0F10(this, 0x1CA1FF20, 0.3f);
        }
    }
    if (mC->m18 == 0) {
        m64 = new Elem_0019FB58[12];
        void* s = func_001E6978(func_001190D0(8));
        func_001E6AC8(s, params);
        func_001E7360(s, 0x7321A8D6, 0xFDF0436C);
        func_001E7360(s, 0x3ED7262B, 0x5D5C0E72);
        func_001A27A0(this, s);
        if (s)
            func_001E6AE8(s, 3);
    }
}
