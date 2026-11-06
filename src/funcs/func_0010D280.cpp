extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Pool_0010D280 {
    void* m_mem;
    ~Pool_0010D280();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Pool_0010D280::~Pool_0010D280()
{
    func_0010A8D8(D_00388A70, m_mem);
}
