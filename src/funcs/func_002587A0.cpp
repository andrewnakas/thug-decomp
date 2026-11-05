/* sym: _vt$12Obj_002587A0 = 0x003755C8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Obj_002587A0 {
    char pad[0x104];
    virtual void V0();
    virtual ~Obj_002587A0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_002587A0::~Obj_002587A0()
{
}
