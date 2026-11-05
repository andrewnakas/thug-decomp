/* sym: _vt$12Obj_0010F388 = 0x0035BBB8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_0010ECF8(void* p);
extern void* D_00388A70;

class Obj_0010F388 {
public:
    int m0;
    void* m4;
    void* m8;
    char padC[0xA1C - 0xC];
    virtual ~Obj_0010F388() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0010F388::~Obj_0010F388()
{
    if (m8) {
        func_0010BEB8(m8);
        m8 = 0;
    }
    if (m4) {
        func_0010ECF8(m4);
    }
}
