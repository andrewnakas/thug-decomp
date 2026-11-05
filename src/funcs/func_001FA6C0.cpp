/* sym: _vt$13Node_001FA6C0 = 0x003668E8 */
struct Base_001FA6C0 {
    int m0;
    Base_001FA6C0* m4;
    int m8;
    Base_001FA6C0* mC;
    Base_001FA6C0* m10;
    virtual void v0();
};

struct Node_001FA6C0 : Base_001FA6C0 {
    int m18;
    int m1C;
    virtual void v1();
    Node_001FA6C0(int a);
};

Node_001FA6C0::Node_001FA6C0(int a)
{
    m18 = a;
    m4 = this;
    m8 = 0;
    mC = this;
    m10 = this;
    m1C = 0;
}
