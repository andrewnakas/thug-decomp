/* sym: __13Base_0013F860 = 0x002568D8 */
/* sym: _vt$12Obj_0013F860 = 0x0035EC68 */
class Base_0013F860 {
public:
    int m0;
    int m4;
    Base_0013F860();
    virtual void V0();
};

class Obj_0013F860;
extern "C" void func_0013F7A8(Obj_0013F860* self);

class Obj_0013F860 : public Base_0013F860 {
public:
    Obj_0013F860();
    virtual void V0();
};

Obj_0013F860::Obj_0013F860()
{
    func_0013F7A8(this);
}
