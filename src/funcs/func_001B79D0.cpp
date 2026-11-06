/* sym: __13Base_001B79D0 = 0x00184DC0 */
/* sym: _vt$12Obj_001B79D0 = 0x00362E20 */
struct Base_001B79D0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B79D0();
    virtual ~Base_001B79D0();
};

struct Obj_001B79D0 : Base_001B79D0 {
    int m1C;
    Obj_001B79D0();
    virtual void Update();
};

Obj_001B79D0::Obj_001B79D0()
{
    m_type = 0x3506CE64;
    m1C = 1;
}
