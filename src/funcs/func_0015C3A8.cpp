/* sym: __13Base_0015C3A8 = 0x00141AF8 */
/* sym: _vt$12Der_0015C3A8 = 0x003605F8 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

class Base_0015C3A8 {
public:
    char pad0[0x190];
    Base_0015C3A8();
    virtual void F();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class Der_0015C3A8 : public Base_0015C3A8 {
public:
    char pad194[0x320 - 0x194];
    Der_0015C3A8() {}
    virtual void F();
};

Der_0015C3A8* func_0015C3A8()
{
    return new Der_0015C3A8;
}
