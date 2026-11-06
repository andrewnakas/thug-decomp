struct Heap_001EE2C0 {
    char m_pad0[0xD8];
    void* m_sub;
};

extern Heap_001EE2C0* D_00388A70;

extern "C" void func_0010A950(Heap_001EE2C0* h, void* ctx);
extern "C" void func_0010A9B0(Heap_001EE2C0* h);
extern "C" int func_0010DAB0(void* data);
extern "C" void func_001EDBA8(void* data, int a, int b, int c);
extern "C" void func_0010DCD0(void* data);
extern "C" void func_001EE1F0();

extern "C" void func_001EE2C0(void* data, int b)
{
    func_0010A950(D_00388A70, D_00388A70->m_sub);
    int a = func_0010DAB0(data);
    func_0010A9B0(D_00388A70);
    func_001EDBA8(data, a, b, 1);
    func_0010DCD0(data);
    func_001EE1F0();
}
