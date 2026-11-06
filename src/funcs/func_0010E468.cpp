extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

/* sym: _vt$12Obj_0010E468 = 0x0035BB18 */
class Obj_0010E468 {
public:
    int m[14];
    virtual ~Obj_0010E468() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0010E468::~Obj_0010E468()
{
}
