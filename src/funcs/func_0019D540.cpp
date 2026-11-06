/* sym: __13Base_0019D540 = 0x00184DC0 */
/* sym: _vt$12Der_0019D540 = 0x00362230 */
class Base_0019D540 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_0019D540();
    virtual void F();
};

class Der_0019D540 : public Base_0019D540 {
public:
    Der_0019D540();
    virtual void F();
};

Der_0019D540::Der_0019D540()
{
    m4 = 0x69C257E9;
}
