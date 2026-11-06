/* sym: __13Base_001BB510 = 0x00184DC0 */
/* sym: _vt$12Obj_001BB510 = 0x00363180 */
/* sym: __13Part_001BB510 = 0x0026F090 */
struct Base_001BB510 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001BB510();
    virtual ~Base_001BB510();
};

struct Part_001BB510 {
    char pad[0x27C];
    Part_001BB510();
};

struct Obj_001BB510 : Base_001BB510 {
    char pad1C[8];
    Part_001BB510 m24;
    Part_001BB510 m2A0;
    int m51C;
    Obj_001BB510();
    virtual void Update();
};

Obj_001BB510::Obj_001BB510()
{
    m_type = 0x27D7CD28;
    m51C = 0;
}
