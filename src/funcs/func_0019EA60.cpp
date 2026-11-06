/* sym: __13Base_0019EA60 = 0x00184DC0 */
/* sym: _vt$12Der_0019EA60 = 0x003622A8 */
class Base_0019EA60 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_0019EA60();
    virtual void F();
};

class Der_0019EA60 : public Base_0019EA60 {
public:
    int m1C;
    Der_0019EA60();
    virtual void F();
};

Der_0019EA60::Der_0019EA60()
{
    m4 = 0x222756D5;
    m1C = 0;
}
