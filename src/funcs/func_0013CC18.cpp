/* sym: _vt$13Mesh_0013CC18 = 0x0035E9A8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00136158(void* p);
extern void* D_00388A70;

class Mesh_0013CC18;
extern "C" void func_0013EA58(Mesh_0013CC18* m);

class Mesh_0013CC18 {
public:
    char pad0[0x100];
    void* m100;
    char pad104[0xB4];
    virtual ~Mesh_0013CC18() = 0;
    virtual void V1();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mesh_0013CC18::~Mesh_0013CC18()
{
    if (m100)
        func_00136158(m100);
    func_0013EA58(this);
}
