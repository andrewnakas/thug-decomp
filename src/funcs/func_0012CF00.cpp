/* sym: _$_13Elem_0012CF00 = 0x0012C1E0 */
/* sym: _vt$13Item_0012CF00 = 0x0035D178 */
/* sym: _vt$13Item_0012CF00$17Listener_0012CF00 = 0x0035D158 */
class Root_0012CF00 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Root_0012CF00();
};

class Base_0012CF00 : public Root_0012CF00 {
public:
    char padC[0x1A0 - 0xC];
    virtual void V0();
    virtual ~Base_0012CF00();
};

class Listener_0012CF00 {
public:
    int m0[6];
    virtual void L0();
    virtual ~Listener_0012CF00();
};

class Elem_0012CF00 : public Base_0012CF00, public Listener_0012CF00 {
public:
    int m1BC[11];
    virtual void V0();
    virtual void L0();
    virtual ~Elem_0012CF00();
};

class Item_0012CF00 : public Elem_0012CF00 {
public:
    int m_flag;
    virtual void V0();
    virtual void L0();
    virtual ~Item_0012CF00();
};

Item_0012CF00::~Item_0012CF00()
{
}
