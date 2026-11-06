/* sym: __13Base_002724F0 = 0x00184DC0 */
/* sym: _vt$12Obj_002724F0 = 0x00376750 */
struct Base_002724F0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_002724F0();
    virtual ~Base_002724F0();
};

struct Obj_002724F0 : Base_002724F0 {
    char pad[0x58 - 0x1C];
    int m_field;
    Obj_002724F0();
    virtual void Update();
};

Obj_002724F0::Obj_002724F0()
{
    m_type = 0x52D61A0D;
    m_field = 0;
}
