struct Heap_002B4B70 {
    char pad0[0x108];
    int m108;
};

extern Heap_002B4B70* D_00388A70;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_001048F0(void* p);
extern "C" void* func_002D3D30(int id);
extern "C" void func_00306790(void* p);
extern "C" void func_001FC128(void* p);

struct Obj_002B4B70 {
    int m0;
    int m4;
    char pad[0xA8 - 8];
    void* mA8;
    void Cleanup();
};

extern "C" int func_002A1A28(Obj_002B4B70* o);
extern "C" char* func_002A39F0(Obj_002B4B70* o);

void Obj_002B4B70::Cleanup()
{
    if (func_002A1A28(this)) {
        func_0010A950(D_00388A70, D_00388A70->m108);
        if (func_002D3D30(m4))
            func_00306790(func_002D3D30(m4));
        func_0010A9B0(D_00388A70);
    } else {
        char* r = func_002A39F0(this);
        if (r)
            func_001FC128(r + 4);
        func_001048F0(mA8);
    }
}
