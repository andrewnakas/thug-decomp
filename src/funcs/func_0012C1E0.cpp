/* sym: _$_13Base_0012C1E0 = 0x001238D0 */
/* sym: _$_17Listener_0012C1E0 = 0x00187DC8 */
/* sym: _vt$13Elem_0012C1E0$17Listener_0012C1E0 = 0x0035D1E0 */
/* sym: _vt$13Elem_0012C1E0 = 0x0035D200 */
class Root_0012C1E0 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Root_0012C1E0();
};

class Base_0012C1E0 : public Root_0012C1E0 {
public:
    char padC[0x1A0 - 0xC];
    virtual void V0();
    virtual ~Base_0012C1E0();
};

class Listener_0012C1E0 {
public:
    int m0[6];
    virtual void L0();
    virtual ~Listener_0012C1E0();
};

class Elem_0012C1E0 : public Base_0012C1E0, public Listener_0012C1E0 {
public:
    int m1BC[11];
    virtual void V0();
    virtual void L0();
    virtual ~Elem_0012C1E0();
};

Elem_0012C1E0::~Elem_0012C1E0()
{
}
