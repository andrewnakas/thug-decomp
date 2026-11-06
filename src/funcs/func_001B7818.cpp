/* sym: __13Base_001B7818 = 0x00184DC0 */
/* sym: _vt$12Obj_001B7818 = 0x00362DB0 */
struct Base_001B7818 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B7818();
    virtual ~Base_001B7818();
};

struct Obj_001B7818 : Base_001B7818 {
    int m1C;
    Obj_001B7818();
    virtual void Update();
};

Obj_001B7818::Obj_001B7818()
{
    m_type = 0x27443708;
    m1C = 0;
}
