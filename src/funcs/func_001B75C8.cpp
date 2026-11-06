/* sym: __13Base_001B75C8 = 0x00184DC0 */
/* sym: _vt$12Obj_001B75C8 = 0x00362D40 */
struct Base_001B75C8 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B75C8();
    virtual ~Base_001B75C8();
};

struct Obj_001B75C8 : Base_001B75C8 {
    int m1C;
    Obj_001B75C8();
    virtual void Update();
};

Obj_001B75C8::Obj_001B75C8()
{
    m_type = 0x1CDFB2A3;
    m1C = 0;
}
