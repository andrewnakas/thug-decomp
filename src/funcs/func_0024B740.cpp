/* sym: __13Base_0024B740i = 0x00243DB8 */
/* sym: _vt$12Obj_0024B740 = 0x003741D8 */
struct Base_0024B740 {
    char pad[0x14];
    Base_0024B740(int p);
    virtual void V0();
};

struct Obj_0024B740 : Base_0024B740 {
    char pad18[0x10];
    int m28;
    char pad2C[0x78];
    int mA4;
    Obj_0024B740(int p);
    virtual void V0();
};

Obj_0024B740::Obj_0024B740(int p) : Base_0024B740(p)
{
    m28 = 1;
    mA4 = 0;
}
