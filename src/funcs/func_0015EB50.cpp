/* sym: _$_13Base_0015EB50 = 0x0013F8B0 */
/* sym: _vt$12Der_0015EB50 = 0x00360730 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Base_0015EB50 {
public:
    int m0;
    int m4;
    virtual void F();
    virtual ~Base_0015EB50();
};

class Der_0015EB50 : public Base_0015EB50 {
public:
    char padC[0x224 - 0xC];
    void* m224;
    void* m228;
    virtual void F();
    virtual ~Der_0015EB50();
};

Der_0015EB50::~Der_0015EB50()
{
    if (m224)
        func_0010A8D8(D_00388A70, m224);
    if (m228)
        func_0010A8D8(D_00388A70, m228);
}
