/* sym: _vt$12Obj_00145610 = 0x0035F028 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_00145610 {
    char m_data[0x48];
    virtual void Update();
    virtual ~Obj_00145610();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00145610::~Obj_00145610()
{
}
