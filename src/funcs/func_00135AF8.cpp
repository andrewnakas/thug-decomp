struct Heap_00135AF8 {
    char pad[0xE4];
    void* mE4;
};

extern "C" void func_0010A950(Heap_00135AF8* heap, void* sub);
extern "C" void func_0010A9B0(Heap_00135AF8* heap);
extern "C" void* func_0010A638(Heap_00135AF8* heap, int size, int a, int b);
extern "C" void func_00331A9C(void* p, void* a);
extern Heap_00135AF8* D_00388A70;

class C_00135AF8 {
public:
    int m0;
    void* m4;
    char pad8[0x30];
    virtual ~C_00135AF8();
    virtual void V1();
    virtual void V2();
    virtual int V3();
    void Load(void* a);
};

void C_00135AF8::Load(void* a)
{
    if (!m4) {
        func_0010A950(D_00388A70, D_00388A70->mE4);
        m4 = func_0010A638(D_00388A70, 0x60, 1, 0);
        func_0010A9B0(D_00388A70);
    }
    func_00331A9C(m4, a);
    V3();
}
