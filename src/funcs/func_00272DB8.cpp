/* sym: __13Base_00272DB8 = 0x00184DC0 */
/* sym: _vt$12Obj_00272DB8 = 0x003767B8 */
struct Base_00272DB8 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00272DB8();
    virtual ~Base_00272DB8();
};

struct Obj_00272DB8 : Base_00272DB8 {
    char pad[0x30 - 0x1C];
    int m_field;
    Obj_00272DB8();
    virtual void Update();
};

Obj_00272DB8::Obj_00272DB8()
{
    m_type = 0xD9151D4D;
    m_field = 0;
}
