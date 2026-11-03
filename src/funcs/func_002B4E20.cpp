struct Heap_002B4E20 {
    char pad0[0xF4];
    int mF4;
    char pad1[0x108 - 0xF8];
    int m108;
};

struct Tag_002B4E20 {
    char c[4];
};

extern Heap_002B4E20* D_00388A70;
extern unsigned int D_0039242C;
extern int D_00392430;
extern char D_003924C0[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" unsigned int func_0010FC30();
extern "C" void* func_002D3D30(int id);
extern "C" void func_002B4250();
extern "C" void func_00306690(void* p, Tag_002B4E20* tag, int n, int a, void (*cb)(), void* arg);

struct Obj_002B4E20 {
    int m0;
    int m4;
    void Refresh(int force);
};

extern "C" void func_002B4B70(Obj_002B4E20* o);
extern "C" void func_002B4BF8(Obj_002B4E20* o);
extern "C" void func_002B4AE0(Obj_002B4E20* o);
extern "C" int func_002A1A28(Obj_002B4E20* o);
extern "C" void func_002A53A0(Obj_002B4E20* o);

void Obj_002B4E20::Refresh(int force)
{
    if (!force && func_0010FC30() - D_0039242C < 5000)
        return;
    D_0039242C = func_0010FC30();
    D_00392430 = 1;
    func_0010A950(D_00388A70, D_00388A70->mF4);
    func_002B4B70(this);
    func_002B4BF8(this);
    func_002B4AE0(this);
    if (func_002A1A28(this)) {
        Tag_002B4E20 tag = *(Tag_002B4E20*)D_003924C0;
        func_0010A950(D_00388A70, D_00388A70->m108);
        func_00306690(func_002D3D30(m4), &tag, 4, 0, func_002B4250, this);
        func_0010A9B0(D_00388A70);
    } else {
        func_002A53A0(this);
    }
    func_0010A9B0(D_00388A70);
}
