/* sym: __13Base_002778F0 = 0x00184DC0 */
/* sym: _vt$12Obj_002778F0 = 0x003768F0 */
struct Base_002778F0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_002778F0();
    virtual ~Base_002778F0();
};

struct Obj_002778F0 : Base_002778F0 {
    int m_field;
    Obj_002778F0();
    virtual void Update();
};

Obj_002778F0::Obj_002778F0()
{
    m_type = 0xD262802F;
    m_field = 0;
}
