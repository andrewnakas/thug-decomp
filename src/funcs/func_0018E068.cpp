/* sym: __13Base_0018E068 = 0x00184DC0 */
/* sym: _vt$12Der_0018E068 = 0x00361E88 */
class Base_0018E068 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_0018E068();
    virtual void F();
};

class Der_0018E068 : public Base_0018E068 {
public:
    Der_0018E068();
    virtual void F();
};

Der_0018E068::Der_0018E068()
{
    m4 = 0xE3FCA939;
}
