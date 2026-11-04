extern "C" int func_002041F8(void* obj);
extern "C" int func_00215EE0(int a, int b);
extern "C" int func_0022EF98(void* mgr);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E72B0(void* s, unsigned int name, float f);
extern "C" void func_001E70C0(void* s, unsigned int name, const char* str);
extern "C" void func_001E6AE8(void* s, int flags);
extern void* D_0038FC78;
extern char D_00362BC0[];

struct Heap_001B6BF0 {
    int m_pad[82];
    int m148[4];
};

extern "C" void func_0010A950(Heap_001B6BF0* heap, int ctx);
extern "C" void func_0010A9B0(Heap_001B6BF0* heap);
extern Heap_001B6BF0* D_00388A70;

struct Obj_001B6BF0 {
    int m_pad[199];
    int m31C;
};

struct C_001B6BF0 {
    int m_pad[3];
    Obj_001B6BF0* mC;
    int m10[2];
    virtual void V0();
    virtual void V1();
    virtual void Apply(void* s);
    void Reset();
};

extern "C" void func_001B6B08(C_001B6BF0* self);
extern "C" void func_001B69E8(C_001B6BF0* self, int mode);

void C_001B6BF0::Reset()
{
    Obj_001B6BF0* o = mC;
    Heap_001B6BF0* h = D_00388A70;
    int mode = 1;
    func_0010A950(h, h->m148[func_002041F8(o)]);
    if (func_00215EE0(0, 0)) mode = func_0022EF98(D_0038FC78);
    if (!o->m31C) mode = 2;
    void* s = func_001E6978(func_001190D0(8));
    func_001E72B0(s, 0x6F8CD62F, 1.0f);
    func_001E70C0(s, 0x545F8172, D_00362BC0);
    Apply(s);
    if (s) func_001E6AE8(s, 3);
    func_001B6B08(this);
    func_001B69E8(this, mode);
    func_0010A9B0(D_00388A70);
}
