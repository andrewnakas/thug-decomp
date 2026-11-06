/* sym: __13Base_001BDCF0 = 0x00184DC0 */
/* sym: _vt$12Obj_001BDCF0 = 0x00363368 */
extern "C" int func_0010FC30();

struct Base_001BDCF0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001BDCF0();
    virtual ~Base_001BDCF0();
};

struct Obj_001BDCF0 : Base_001BDCF0 {
    char pad1C[4];
    int m20;
    int m24;
    int m28;
    int m2C;
    char pad30[4];
    int m34;
    int m38;
    Obj_001BDCF0();
    virtual void Update();
};

Obj_001BDCF0::Obj_001BDCF0()
{
    m_type = 0x6259B52B;
    m20 = 0;
    m24 = 0;
    m28 = func_0010FC30();
    m2C = 0;
    m38 = 1;
    m34 = 0;
}
