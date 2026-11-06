/* sym: _vt$12Obj_00202E98 = 0x00366D08 */
/* sym: _$_15Member_00202E98 = 0x001E6AE8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Member_00202E98 {
    int m0;
    int m4;
    ~Member_00202E98();
};

class Obj_00202E98 {
public:
    int m0;
    Member_00202E98 m4;
    virtual ~Obj_00202E98() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00202E98::~Obj_00202E98()
{
}
