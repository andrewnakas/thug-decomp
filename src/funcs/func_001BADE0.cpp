/* sym: __13Base_001BADE0 = 0x00184DC0 */
/* sym: _vt$12Obj_001BADE0 = 0x003630A0 */
struct Base_001BADE0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001BADE0();
    virtual ~Base_001BADE0();
};

struct Obj_001BADE0 : Base_001BADE0 {
    Obj_001BADE0();
    virtual void Update();
};

Obj_001BADE0::Obj_001BADE0()
{
    m_type = 0xE594F0A2;
}
