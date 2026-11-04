struct Pool_002B1F60 {
    char pad[0x3EC];
    int m3EC;
};

extern Pool_002B1F60* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00261078(void* p);
extern "C" void func_002610C0(void* p, void* a);

struct Obj_002B1F60 {
    char pad[0x48];
    void* m48;
    void Create(void* a);
};

void Obj_002B1F60::Create(void* a)
{
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    m48 = func_00261078(func_001046B0(0x64));
    func_002610C0(m48, a);
    func_0010A9B0(D_00388A70);
}
