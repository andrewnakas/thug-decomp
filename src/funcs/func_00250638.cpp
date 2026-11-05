/* sym: __13Base_0024FF90 = 0x0024FF90 */
/* sym: _vt$12Obj_00250638 = 0x00374A70 */
struct Base_0024FF90 {
    int m0;
    Base_0024FF90();
    virtual void V0();
};

struct Obj_00250638 : Base_0024FF90 {
    int m8;
    Obj_00250638(int a);
    virtual void V0();
};

Obj_00250638::Obj_00250638(int a)
{
    m8 = a;
}
