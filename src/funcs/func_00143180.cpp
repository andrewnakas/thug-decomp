/* sym: _vt$12Buf_00143180 = 0x0035EDF0 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Buf_00143180 {
public:
    void* m0;
    void* m4;
    int m8;
    void* mC;
    char pad10[0x14];
    virtual ~Buf_00143180() = 0;
    virtual void V1();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Buf_00143180::~Buf_00143180()
{
    if (m0)
        func_0010A8D8(D_00388A70, m0);
    if (m4)
        func_0010A8D8(D_00388A70, m4);
    if (mC)
        func_0010A8D8(D_00388A70, mC);
}
