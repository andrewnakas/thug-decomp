/* sym: __13Base_00270948 = 0x00184DC0 */
/* sym: _vt$12Obj_00270948 = 0x003765D8 */
struct Base_00270948 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00270948();
    virtual ~Base_00270948();
};

struct Obj_00270948 : Base_00270948 {
    char pad[0x28 - 0x1C];
    int m28;
    float m2C;
    float m30;
    Obj_00270948();
    virtual void Update();
};

Obj_00270948::Obj_00270948()
{
    m_type = 0x187574FA;
    m28 = 0;
    m2C = 1.0f;
    m30 = 1.0f;
}
