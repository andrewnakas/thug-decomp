/* sym: _$_13Base_0014EA68 = 0x00143180 */
/* sym: _vt$12Der_0014EA68 = 0x0035F848 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Elem_0014EA68 {
    char m0[0x20];
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

class Base_0014EA68 {
public:
    char pad0[0x24];
    virtual void F();
    virtual ~Base_0014EA68();
};

class Der_0014EA68 : public Base_0014EA68 {
public:
    void* m28;
    Elem_0014EA68* m2C;
    virtual void F();
    virtual ~Der_0014EA68();
};

Der_0014EA68::~Der_0014EA68()
{
    if (m2C)
        delete[] m2C;
}
