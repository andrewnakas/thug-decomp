/* sym: __13Base_00273788 = 0x00184DC0 */
/* sym: _vt$12Obj_00273788 = 0x00376820 */
struct Base_00273788 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00273788();
    virtual ~Base_00273788();
};

struct Obj_00273788 : Base_00273788 {
    int m1C;
    char m20;
    char pad21[0x30 - 0x21];
    int m30;
    int m34;
    char m38;
    char m39;
    short m3A;
    short m3C;
    short m3E;
    int m40;
    int m44;
    Obj_00273788();
    virtual void Update();
};

Obj_00273788::Obj_00273788()
{
    m_type = 0x7CD3E6D5;
    m34 = 0;
    m40 = 0;
    m44 = 0;
    m1C = 0;
    m20 = -1;
    m30 = 0;
    m38 = 0;
    m39 = -1;
    m3C = 0;
}
