/* sym: __13Base_0014B0C8 = 0x00137A08 */
/* sym: _vt$13Menu_0014B0C8 = 0x0035F3A8 */
/* sym: __12Sub_0014B0C8 = 0x0016C2E0 */
/* sym: SetMode__13Menu_0014B0C8i = 0x0014B780 */
/* sym: SetItem__13Menu_0014B0C8ii = 0x0014B7B0 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Sub_0014B0C8 {
public:
    char pad[0xC0];
    Sub_0014B0C8();
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

class Base_0014B0C8 {
public:
    char pad[0x18];
    Base_0014B0C8();
    virtual ~Base_0014B0C8();
};

class Menu_0014B0C8 : public Base_0014B0C8 {
public:
    Sub_0014B0C8* m1C;
    Menu_0014B0C8();
    virtual void V1();
    virtual ~Menu_0014B0C8();
    void SetMode(int m);
    void SetItem(int i, int v);
};

Menu_0014B0C8::Menu_0014B0C8()
{
    m1C = new Sub_0014B0C8;
    SetMode(0);
    for (int i = 0; i < 2; i++) SetItem(i, 0);
}
