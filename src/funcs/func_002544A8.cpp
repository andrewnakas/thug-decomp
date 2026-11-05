struct Heap_002544A8 {
    char pad[0xE4];
    int mE4;
};

struct Ent_002544A8 {
    char pad[0x38];
    int m38;
};

extern Heap_002544A8* D_00388A70;
extern void* D_00389A30;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_00254660(Ent_002544A8* e, int v);
extern "C" void func_0012DCD0(void* p);
extern "C" void func_0010A9B0(void* p);

struct Obj_002544A8 {
    char pad[0x20];
    Ent_002544A8* m20;
    void Fn();
};

void Obj_002544A8::Fn()
{
    func_0010A950(D_00388A70, D_00388A70->mE4);
    func_00254660(m20, m20->m38);
    func_0012DCD0(D_00389A30);
    func_0010A9B0(D_00388A70);
}
