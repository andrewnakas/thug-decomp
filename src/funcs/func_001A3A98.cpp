/* sym: __13Base_001A3A98 = 0x00184DC0 */
/* sym: _vt$12Der_001A3A98 = 0x00362490 */
class Base_001A3A98 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_001A3A98();
    virtual void F();
};

class Der_001A3A98 : public Base_001A3A98 {
public:
    char pad1C[0x28 - 0x1C];
    int m28;
    int m2C;
    Der_001A3A98();
    virtual void F();
};

Der_001A3A98::Der_001A3A98()
{
    m4 = 0x0F1641E3;
    m28 = 0;
    m2C = 0;
}
