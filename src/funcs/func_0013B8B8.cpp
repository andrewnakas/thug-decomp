extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

/* sym: _vt$12Obj_0013B8B8 = 0x0035E2B8 */
class Obj_0013B8B8 {
public:
    int m[15];
    virtual ~Obj_0013B8B8() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0013B8B8::~Obj_0013B8B8()
{
}
