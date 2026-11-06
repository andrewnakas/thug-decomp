/* sym: __13Base_001A4EE0 = 0x00184DC0 */
/* sym: _vt$12Der_001A4EE0 = 0x00362660 */
class Base_001A4EE0 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_001A4EE0();
    virtual void F();
};

class Der_001A4EE0 : public Base_001A4EE0 {
public:
    int m1C;
    int m20;
    int m24;
    char pad28[0x48 - 0x28];
    int m48;
    Der_001A4EE0();
    virtual void F();
};

Der_001A4EE0::Der_001A4EE0()
{
    m4 = 0xC695136D;
    m48 = 1;
    m1C = 0;
    m20 = 0;
    m24 = 0;
}
