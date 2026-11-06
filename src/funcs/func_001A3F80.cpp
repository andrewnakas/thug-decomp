/* sym: __13Base_001A3F80 = 0x00184DC0 */
/* sym: _vt$12Der_001A3F80 = 0x00362508 */
class Base_001A3F80 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_001A3F80();
    virtual void F();
};

class Der_001A3F80 : public Base_001A3F80 {
public:
    Der_001A3F80();
    virtual void F();
};

Der_001A3F80::Der_001A3F80()
{
    m4 = 0xA432DC41;
}
