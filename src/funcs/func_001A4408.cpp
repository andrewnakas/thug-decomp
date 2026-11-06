/* sym: __13Base_001A4408 = 0x00184DC0 */
/* sym: _vt$12Der_001A4408 = 0x003625F8 */
class Base_001A4408 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_001A4408();
    virtual void F();
};

class Der_001A4408 : public Base_001A4408 {
public:
    char pad1C[0x60 - 0x1C];
    int m60;
    Der_001A4408();
    virtual void F();
};

Der_001A4408::Der_001A4408()
{
    m4 = 0x5CB5CB7E;
    m60 = 0;
}
