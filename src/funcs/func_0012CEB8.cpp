/* sym: __13Elem_0012CEB8 = 0x0012C138 */
/* sym: _vt$13Item_0012CEB8 = 0x0035D178 */
/* sym: _vt$13Item_0012CEB8$17Listener_0012CEB8 = 0x0035D158 */
class Root_0012CEB8 {
public:
    int m0;
    int m4;
    virtual void V0();
};

class Base_0012CEB8 : public Root_0012CEB8 {
public:
    char padC[0x1A0 - 0xC];
    virtual void V0();
};

class Listener_0012CEB8 {
public:
    int m0[6];
    virtual void L0();
};

class Elem_0012CEB8 : public Base_0012CEB8, public Listener_0012CEB8 {
public:
    int m1BC[11];
    Elem_0012CEB8();
    virtual void V0();
    virtual void L0();
};

class Item_0012CEB8 : public Elem_0012CEB8 {
public:
    int m_flag;
    Item_0012CEB8();
    virtual void V0();
    virtual void L0();
};

Item_0012CEB8::Item_0012CEB8()
{
    m_flag = 1;
}
