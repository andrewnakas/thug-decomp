extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj_00146088 {
    char pad[0x88];
    int m88;
    int m8C;
};

extern "C" Obj_00146088* func_0014C0A0(void* mem);
extern "C" void* func_0010DAB0(const char* name);
extern "C" void* func_00170AE8(void* src, int flags);
extern "C" void func_0014C1C0(Obj_00146088* o, void* s);

extern "C" Obj_00146088* func_00146088(const char* name, int a, int b, int c, int d)
{
    Obj_00146088* o = func_0014C0A0(func_0010A638(D_00388A70, 0x2A0, 1, 0));
    o->m88 = b;
    o->m8C = c;
    void* src = func_0010DAB0(name);
    int flags = d == 0;
    if (c)
        flags |= 2;
    func_0014C1C0(o, func_00170AE8(src, flags));
    return o;
}
