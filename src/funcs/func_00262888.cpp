struct Heap_00262888 {
    char pad[0x3EC];
    int m3EC;
};

extern Heap_00262888* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_00262388(void* p);
extern "C" void* func_00263460(void* p, const int& k);
extern "C" void func_002610C0(void* dst, void* src);

struct Obj_00262888 {
    int m0;
    char m4[0x1C];
    void* m20;
    void Fn();
};

void Obj_00262888::Fn()
{
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    int k = func_00262388(m20);
    func_002610C0(m20, func_00263460(m4, k));
    func_0010A9B0(D_00388A70);
}
