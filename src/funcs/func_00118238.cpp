/* sym: _vt$13Node_00118238 = 0x0035C6D8 */
struct Base_00118238 {
    int m0;
    Base_00118238* m4;
    int m8;
    Base_00118238* mC;
    Base_00118238* m10;
    virtual void v0();
};

struct Node_00118238 : Base_00118238 {
    int m18;
    int m1C;
    virtual void v1();
    Node_00118238(int a);
};

Node_00118238::Node_00118238(int a)
{
    m18 = a;
    m4 = this;
    m8 = 0;
    mC = this;
    m10 = this;
    m1C = 0;
}
