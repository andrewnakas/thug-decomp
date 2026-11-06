/* sym: __13Base_00278478 = 0x00184DC0 */
/* sym: _vt$12Obj_00278478 = 0x003769E0 */
struct Base_00278478 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00278478();
    virtual ~Base_00278478();
};

struct Obj_00278478 : Base_00278478 {
    Obj_00278478();
    virtual void Update();
};

Obj_00278478::Obj_00278478()
{
    m_type = 0x125044E2;
}
