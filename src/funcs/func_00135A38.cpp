/* sym: _vt$10C_00135A38 = 0x0035D808 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class C_00135A38 {
public:
    int m0;
    void* m4;
    char pad8[0x30];
    virtual ~C_00135A38() = 0;
    virtual void V1();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

C_00135A38::~C_00135A38()
{
    if (m4)
        func_0010A8D8(D_00388A70, m4);
}
