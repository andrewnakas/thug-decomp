struct Mgr_0029B000 {
    void* m0;
    char pad[0x80 - 0x4];
    int m80;
};

struct Base_0029B000 {
    char pad[0x18];
    virtual void v0();
    virtual void v1();
    virtual void v2(void* s);
};

struct Comp_0029B000 : Base_0029B000 {
    int m1C;
    int m20;
    char m24[4];
};

extern "C" Mgr_0029B000* func_002C0368();
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" void func_002B7FE8(void* p);
extern "C" void func_002B8018(void* p, int a);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_0026FA48(void* p);

struct Obj_0029B000;
extern "C" void func_0029A730(Obj_0029B000* o);
extern "C" void func_0029B6E0(Obj_0029B000* o);

struct Obj_0029B000 {
    char pad[0x1C];
    Comp_0029B000* m1C;
    void Set(bool on);
};

void Obj_0029B000::Set(bool on)
{
    Mgr_0029B000* m = func_002C0368();
    if (on) {
        func_001F0210(0x0EC0A515, 0, 0, 0, 0);
        func_002B7FE8(m->m0);
        func_0029A730(this);
        func_0029B6E0(this);
    } else {
        func_001F0210(0x52D1CE6F, 0, 0, 0, 0);
        func_002B8018(m->m0, m->m80);
        void* s = func_001E6978(func_001190D0(8));
        func_001E7200(s, 0x67E6859A, 0);
        m1C->v2(s);
        if (s)
            func_001E6AE8(s, 3);
        func_0026FA48(m1C->m24);
    }
}
