/* sym: __13Base_001AA930 = 0x00184DC0 */
/* sym: _vt$12Obj_001AA930 = 0x00362908 */
/* sym: __13Part_001AA930 = 0x00102FD0 */
struct Base_001AA930 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001AA930();
    virtual ~Base_001AA930();
};

struct Part_001AA930 {
    int m0;
    Part_001AA930();
};

struct Obj_001AA930 : Base_001AA930 {
    char pad1C[4];
    Part_001AA930 m20;
    Obj_001AA930();
    virtual void Update();
};

Obj_001AA930::Obj_001AA930()
{
    m_type = 0x6EB050ED;
}
