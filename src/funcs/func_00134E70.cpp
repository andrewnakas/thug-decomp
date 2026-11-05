/* sym: _vt$10C_00134E70 = 0x0035D6C8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct A_00134E70 {
    char pad[0xC];
    virtual ~A_00134E70();
};

struct B_00134E70 {
    char pad[0x14];
    virtual ~B_00134E70();
};

class C_00134E70 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18];
    B_00134E70* m20;
    A_00134E70* m24;
    virtual ~C_00134E70() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

C_00134E70::~C_00134E70()
{
    if (m24 && (m4 & 2))
        delete m24;
    if (m20)
        delete m20;
}
