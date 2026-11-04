struct Heap_00243FB0 {
    char pad0[0xDC];
    void* m_DC;
};

extern Heap_00243FB0* D_00388A70;

extern "C" void func_0010A950(Heap_00243FB0* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_00243FB0* mgr);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Goal_00243FB0 {
    char pad0[0x20];
    void* m_params;
    char pad24[0x4C];
    int m_70;
    char pad74[0x2C];
    int m_A0;

    void Begin();
};

extern "C" void func_00248788(Goal_00243FB0* self);
extern "C" void func_00248800(Goal_00243FB0* self, unsigned int name);
extern "C" void func_00247D00(Goal_00243FB0* self);

void Goal_00243FB0::Begin()
{
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    func_00248788(this);
    func_00248800(this, 0x398B1B8B);
    func_00247D00(this);
    m_70 = 1;
    int v = 0;
    func_001E7DE8(m_params, 0xF0E712D2, &v, 0);
    if (v)
        m_A0 = 1;
    func_0010A9B0(D_00388A70);
}
