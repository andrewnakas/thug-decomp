/* sym: __13Base_0026FE38 = 0x00184DC0 */
/* sym: _vt$12Obj_0026FE38 = 0x003764D8 */
struct Base_0026FE38 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_0026FE38();
    virtual ~Base_0026FE38();
};

struct Obj_0026FE38 : Base_0026FE38 {
    char pad[0x2C - 0x1C];
    int m_field;
    Obj_0026FE38();
    virtual void Update();
};

Obj_0026FE38::Obj_0026FE38()
{
    m_type = 0x21FC3301;
    m_field = 0;
}
