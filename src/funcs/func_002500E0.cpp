/* sym: __13Base_0024FF90 = 0x0024FF90 */
/* sym: _vt$12Obj_002500E0 = 0x00374AE0 */
struct Base_0024FF90 {
    int m0;
    Base_0024FF90();
    virtual void V0();
};

struct Obj_002500E0 : Base_0024FF90 {
    int m8;
    Obj_002500E0(int a);
    virtual void V0();
};

Obj_002500E0::Obj_002500E0(int a)
{
    m8 = a;
}
