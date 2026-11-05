/* sym: __13Base_0024A4D0i = 0x00243DB8 */
/* sym: _vt$12Obj_0024A4D0 = 0x00373F80 */
struct Obj_0024A4D0;
extern char D_00373DE8[];
extern "C" void func_00103F28(const char* fmt);
extern "C" void func_0024A860(Obj_0024A4D0* self);

struct Base_0024A4D0 {
    char pad[0x14];
    Base_0024A4D0(int p);
    virtual void V0();
};

struct Obj_0024A4D0 : Base_0024A4D0 {
    char pad18[0x8C];
    int mA4;
    int mA8;
    int mAC;
    char padB0[4];
    int mB4;
    char padB8[0x14];
    int mCC;
    int mD0;
    Obj_0024A4D0(int p);
    virtual void V0();
};

Obj_0024A4D0::Obj_0024A4D0(int p) : Base_0024A4D0(p)
{
    func_00103F28(D_00373DE8);
    func_0024A860(this);
    mA4 = 1;
    mB4 = 1;
    mAC = 0;
    mD0 = 0;
    mCC = 0;
}
