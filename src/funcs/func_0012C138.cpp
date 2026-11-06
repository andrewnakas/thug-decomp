/* sym: __13Base_0012C138 = 0x00123628 */
/* sym: __17Listener_0012C138 = 0x00187DA0 */
/* sym: _vt$13Elem_0012C138$17Listener_0012C138 = 0x0035D1E0 */
/* sym: _vt$13Elem_0012C138 = 0x0035D200 */
class Root_0012C138 {
public:
    int m0;
    int m4;
    virtual void V0();
};

class Base_0012C138 : public Root_0012C138 {
public:
    char padC[0x1A0 - 0xC];
    Base_0012C138();
    virtual void V0();
};

class Listener_0012C138 {
public:
    int m0[6];
    Listener_0012C138();
    virtual void L0();
};

class Elem_0012C138;
extern "C" void func_00187E38(Listener_0012C138* l, Elem_0012C138* owner);
extern "C" void func_00183F08(Elem_0012C138* self, unsigned int type);

class Elem_0012C138 : public Base_0012C138, public Listener_0012C138 {
public:
    int m1BC;
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    float m1D8;
    int m1DC;
    int m1E0;
    float m1E4;
    Elem_0012C138();
    virtual void V0();
    virtual void L0();
};

Elem_0012C138::Elem_0012C138()
{
    func_00187E38(this, this);
    m1BC = 0;
    m1C0 = 0;
    m1CC = 0;
    m1D0 = 0;
    m1D4 = 0;
    m1D8 = 10000.0f;
    m1DC = -1;
    m1E0 = 0;
    m1E4 = -1.0f;
    func_00183F08(this, 0x84298A3C);
}
