/* sym: _$_13Elem_0012CF78 = 0x0012C1E0 */
/* sym: _vt$13Item_0012CF78 = 0x0035D0F0 */
/* sym: _vt$13Item_0012CF78$17Listener_0012CF78 = 0x0035D0D0 */
class Root_0012CF78 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Root_0012CF78();
};

class Base_0012CF78 : public Root_0012CF78 {
public:
    char padC[0x1A0 - 0xC];
    virtual void V0();
    virtual ~Base_0012CF78();
};

class Listener_0012CF78 {
public:
    int m0[6];
    virtual void L0();
    virtual ~Listener_0012CF78();
};

class Elem_0012CF78 : public Base_0012CF78, public Listener_0012CF78 {
public:
    int m1BC[11];
    virtual void V0();
    virtual void L0();
    virtual ~Elem_0012CF78();
};

class Item_0012CF78 : public Elem_0012CF78 {
public:
    int m_flag;
    virtual void V0();
    virtual void L0();
    virtual ~Item_0012CF78();
};

Item_0012CF78::~Item_0012CF78()
{
}
