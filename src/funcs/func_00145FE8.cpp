extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj_00145FE8 {
    char pad[0x88];
    int m88;
    int m8C;
};

extern "C" Obj_00145FE8* func_0014C0A0(void* mem);
extern "C" void* func_0016DC08(void* mem);
extern "C" void func_00170B88(void* s, int a);
extern "C" void func_00170578(void* s, int a);
extern "C" void func_0014C1D0(Obj_00145FE8* o, void* s);

extern "C" Obj_00145FE8* func_00145FE8(int a, int b, int c)
{
    Obj_00145FE8* o = func_0014C0A0(func_0010A638(D_00388A70, 0x2A0, 1, 0));
    void* s = func_0016DC08(func_0010A638(D_00388A70, 0x50, 1, 0));
    func_00170B88(s, 1);
    func_00170578(s, 1);
    func_0014C1D0(o, s);
    o->m88 = c;
    o->m8C = 0;
    return o;
}
