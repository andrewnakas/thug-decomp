extern "C" void func_0010A950(void* heap, void* ctx);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_0022B940(void* self);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00255278(void* self, int a);
extern "C" void func_00255578(void* self, int a);
extern int D_00388818;

struct Heap_0022B8A8 {
    char pad0[0xDC];
    void* m_DC;
    char padE0[0x11C - 0xE0];
    void* m_11C;
};

extern Heap_0022B8A8* D_00388A70;

struct Obj_0022B8A8 {
    char pad0[0x5C];
    int m_5C;
    void* m_60;
    void Create(int a);
};

void Obj_0022B8A8::Create(int a)
{
    if (D_00388818) {
        func_0010A950(D_00388A70, D_00388A70->m_11C);
    } else {
        func_0010A950(D_00388A70, D_00388A70->m_DC);
    }
    if (m_60) {
        func_0022B940(this);
    }
    void* o = func_00255278(func_001046B0(0x180), m_5C);
    m_60 = o;
    func_00255578(o, a);
    func_0010A9B0(D_00388A70);
}
