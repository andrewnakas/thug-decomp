/* sym: __13Base_0019CB58 = 0x00184DC0 */
/* sym: _vt$12Der_0019CB58 = 0x003621A8 */
class Base_0019CB58 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_0019CB58();
    virtual void F();
};

class Der_0019CB58 : public Base_0019CB58 {
public:
    char pad1C[0xA0 - 0x1C];
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    Der_0019CB58();
    virtual void F();
};

Der_0019CB58::Der_0019CB58()
{
    m4 = 0x2C747D8A;
    mA0 = 60.0f;
    mA4 = 144.0f;
    mAC = 3.0f;
}
