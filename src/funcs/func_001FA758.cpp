/* sym: _vt$13Node_001FA758 = 0x00366900 */
struct Base_001FA758 {
    int m0;
    Base_001FA758* m4;
    int m8;
    Base_001FA758* mC;
    Base_001FA758* m10;
    virtual void v0();
};

struct Node_001FA758 : Base_001FA758 {
    int m18;
    virtual void v1();
    Node_001FA758(int a);
};

Node_001FA758::Node_001FA758(int a)
{
    m18 = a;
    m4 = this;
    m8 = 0;
    mC = this;
    m10 = this;
}
