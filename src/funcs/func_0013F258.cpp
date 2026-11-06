/* sym: _vt$12Obj_0013F258 = 0x0035EA30 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0010DCD0(void* p);
extern void* D_00388A70;

class Obj_0013F258 {
public:
    int m0[2];
    char m_file[0x8C - 0x8];
    int m_open;
    char pad90[0xBC - 0x90];
    virtual void V0();
    virtual ~Obj_0013F258();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0013F258::~Obj_0013F258()
{
    if (m_open) {
        func_0010DCD0(m_file);
    }
}
