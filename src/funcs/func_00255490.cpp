/* sym: _$_13Base_00256980 = 0x00256980 */
/* sym: _vt$12Obj_00255490 = 0x00375458 */
extern "C" void func_001048F0(void* p);

struct Comp_00255490 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual ~Comp_00255490();
};

struct Base_00256980 {
    int m0;
    int m4;
    virtual void V0();
    virtual ~Base_00256980();
};

struct Obj_00255490 : Base_00256980 {
    char padC[0x154];
    Comp_00255490* m160;
    virtual void V0();
    virtual ~Obj_00255490();
};

Obj_00255490::~Obj_00255490()
{
    func_001048F0(m160);
    delete m160;
}
