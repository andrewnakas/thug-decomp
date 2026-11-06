/* sym: __13Node_001183B0i = 0x00118238 */
/* sym: _vt$12Evt_001183B0 = 0x0035C688 */
struct Base_001183B0 {
    int m0;
    Base_001183B0* m4;
    int m8;
    Base_001183B0* mC;
    Base_001183B0* m10;
    virtual void v0();
};

struct Node_001183B0 : Base_001183B0 {
    int m18;
    int m1C;
    virtual void v1();
    Node_001183B0(int a);
};

struct Evt_001183B0 : Node_001183B0 {
    float m_value;
    virtual void v1();
    Evt_001183B0(int a, float v);
};

Evt_001183B0::Evt_001183B0(int a, float v) : Node_001183B0(a)
{
    m_value = v;
}
