/* sym: _$_13Base_00114D00 = 0x00114D00 */
/* sym: _vt$12Obj_0025FFE0 = 0x00375A88 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" int func_00104968(void* p);
extern "C" void func_001048F0(void* p);
extern void* D_00388A70;

struct Comp_0025FFE0 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual ~Comp_0025FFE0();
};

struct Base_00114D00 {
    int m0;
    int m4;
    virtual void V0();
    virtual ~Base_00114D00();
};

struct Obj_0025FFE0 : Base_00114D00 {
    char padC[0xC8];
    void* mD4;
    char padD8[0x28];
    Comp_0025FFE0* m100;
    virtual void V0();
    virtual ~Obj_0025FFE0();
};

Obj_0025FFE0::~Obj_0025FFE0()
{
    if (mD4) func_0010A8D8(D_00388A70, mD4);
    if (m100) {
        if (func_00104968(m100)) func_001048F0(m100);
        delete m100;
    }
}
