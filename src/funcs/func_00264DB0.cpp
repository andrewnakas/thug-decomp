/* sym: _vt$13Node_00264DB0 = 0x00376060 */
struct Base_00264DB0 {
    int m0;
    Base_00264DB0* m4;
    int m8;
    Base_00264DB0* mC;
    Base_00264DB0* m10;
    virtual void v0();
};

struct Node_00264DB0 : Base_00264DB0 {
    int m18;
    virtual void v1();
    Node_00264DB0(int a);
};

Node_00264DB0::Node_00264DB0(int a)
{
    m18 = a;
    m4 = this;
    m8 = 0;
    mC = this;
    m10 = this;
}
