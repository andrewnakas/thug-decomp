/* sym: __13Base_00277F00 = 0x00184DC0 */
/* sym: _vt$12Obj_00277F00 = 0x00376958 */
struct Base_00277F00 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00277F00();
    virtual ~Base_00277F00();
};

struct Obj_00277F00 : Base_00277F00 {
    char pad[0x64 - 0x1C];
    int m_field;
    Obj_00277F00();
    virtual void Update();
};

Obj_00277F00::Obj_00277F00()
{
    m_type = 0xBF518E27;
    m_field = 0;
}
