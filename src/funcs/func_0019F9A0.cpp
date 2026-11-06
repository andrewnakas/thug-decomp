/* sym: __13Base_0019F9A0 = 0x00184DC0 */
/* sym: _vt$12Der_0019F9A0 = 0x00362358 */
extern char D_003623C0[];

struct Node_0019F9A0 {
    int m0;
    unsigned int m4;
    int m8;
    Node_0019F9A0* m_prev;
    Node_0019F9A0* m_next;
    void* m_vtbl;
    Node_0019F9A0()
    {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        m_prev = this;
        m_next = this;
        m_vtbl = D_003623C0;
    }
};

class Base_0019F9A0 {
public:
    int m0;
    unsigned int m4;
    char pad8[0x18 - 0x8];
    Base_0019F9A0();
    virtual void F();
};

class Der_0019F9A0 : public Base_0019F9A0 {
public:
    Node_0019F9A0 m1C;
    char pad34[0x3C - 0x34];
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    char pad50[0x60 - 0x50];
    int m60;
    int m64;
    Der_0019F9A0();
    virtual void F();
};

extern "C" void func_0019FAB8(Der_0019F9A0* self);

Der_0019F9A0::Der_0019F9A0()
{
    m44 = 0;
    m4C = 0;
    m3C = 0;
    m4 = 0x72AD7B23;
    func_0019FAB8(this);
    m60 = 0;
    m64 = 0;
}
