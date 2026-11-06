extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Buf_0026DFE0 {
    int m0;
    void* m4;
    ~Buf_0026DFE0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Buf_0026DFE0::~Buf_0026DFE0()
{
    func_0010A8D8(D_00388A70, m4);
}
