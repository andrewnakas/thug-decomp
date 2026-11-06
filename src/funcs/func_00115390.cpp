/* sym: __13Base_00115390 = 0x00114F70 */
/* sym: _vt$12Obj_00115390 = 0x0035C508 */
struct Base_00115390 {
    int m0;
    int m_type;
    Base_00115390();
    virtual void V0();
};

struct Obj_00115390 : Base_00115390 {
    void* m_res;
    float m_a;
    float m_b;
    Obj_00115390();
    virtual void V0();
};

Obj_00115390::Obj_00115390()
{
    m_type = 2;
    m_a = 1.0f;
    m_b = 1.0f;
    m_res = 0;
}
