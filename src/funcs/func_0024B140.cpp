/* sym: __13Base_0024B140i = 0x00243DB8 */
/* sym: _vt$12Obj_0024B140 = 0x003740C8 */
struct Base_0024B140 {
    char pad[0x14];
    Base_0024B140(int p);
    virtual void V0();
};

struct Obj_0024B140 : Base_0024B140 {
    char pad18[0x10];
    int m28;
    char pad2C[0x24];
    int m50;
    char pad54[0x50];
    int mA4;
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    Obj_0024B140(int p);
    virtual void V0();
};

Obj_0024B140::Obj_0024B140(int p) : Base_0024B140(p)
{
    m50 = 0x7FFFFFFF;
    m28 = 1;
    mA4 = 0;
    mB0 = 0;
    mAC = 0;
    mA8 = 0;
    mB4 = 0;
}
