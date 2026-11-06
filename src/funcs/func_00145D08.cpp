/* sym: __13Base_00145D08 = 0x00142650 */
/* sym: _vt$12Mgr_00145D08 = 0x00360638 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_00173DF0();
extern "C" void func_00146F20();
extern "C" void* func_0015C418(void* mem);
extern void* D_00388A70;

struct Base_00145D08 {
    int m0;
    Base_00145D08();
};

class Mgr_00145D08 : public Base_00145D08 {
public:
    virtual ~Mgr_00145D08();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

extern Mgr_00145D08* D_00389C34;
extern void* D_00389C38;

extern "C" void func_00145D08()
{
    func_00173DF0();
    D_00389C34 = new Mgr_00145D08;
    func_00146F20();
    D_00389C38 = func_0015C418(func_0010A638(D_00388A70, 0x12C0, 1, 0));
}
