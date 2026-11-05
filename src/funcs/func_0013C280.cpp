/* sym: _vt$12Buf_0013C280 = 0x0035E7C8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Buf_0013C280 {
public:
    int m0;
    int m4;
    int m8;
    void* mC;
    int m10;
    virtual ~Buf_0013C280() = 0;
    virtual void V1();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Buf_0013C280::~Buf_0013C280()
{
    if (mC)
        func_0010A8D8(D_00388A70, mC);
}
