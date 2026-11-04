struct Rgba_001265E0 {
    unsigned char r, g, b, a;
};

struct Heap_001265E0 {
    char pad[0xE4];
    void* mE4;
};

struct X_001265E0 {
    char pad[0x538];
    Rgba_001265E0 m538;
    void SetColor(Rgba_001265E0 c) { m538 = c; }
};

extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" X_001265E0* func_001304A8(void* mem);
extern Heap_001265E0* D_00388A70;

struct C_001265E0 {
    char pad[0xC8];
    Rgba_001265E0 mC8;
    char padCC[0xEC];
    X_001265E0* m1B8;
    void Create();
};

extern "C" void func_00126F28(C_001265E0* o, int a);
extern "C" void func_00126E18(C_001265E0* o, int a, int b);

void C_001265E0::Create()
{
    if (m1B8)
        return;
    func_00126F28(this, 0);
    func_0010A950(D_00388A70, D_00388A70->mE4);
    m1B8 = func_001304A8(func_0010A638(D_00388A70, 0x540, 1, 0));
    m1B8->SetColor(mC8);
    func_0010A9B0(D_00388A70);
    func_00126E18(this, 0x11, 0);
}
