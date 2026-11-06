/* sym: __13Base_001B73B8 = 0x00184DC0 */
/* sym: _vt$12Obj_001B73B8 = 0x00362CD0 */
struct Base_001B73B8 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B73B8();
    virtual ~Base_001B73B8();
};

struct Obj_001B73B8 : Base_001B73B8 {
    int m1C;
    Obj_001B73B8();
    virtual void Update();
};

Obj_001B73B8::Obj_001B73B8()
{
    m_type = 0xC472ECC5;
    m1C = 0;
}
