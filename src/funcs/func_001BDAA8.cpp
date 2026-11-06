/* sym: __13Base_001BDAA8 = 0x00184DC0 */
/* sym: _vt$12Obj_001BDAA8 = 0x00363300 */
struct Base_001BDAA8 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001BDAA8();
    virtual ~Base_001BDAA8();
};

struct Obj_001BDAA8 : Base_001BDAA8 {
    Obj_001BDAA8();
    virtual void Update();
};

Obj_001BDAA8::Obj_001BDAA8()
{
    m_type = 0x41272956;
}
