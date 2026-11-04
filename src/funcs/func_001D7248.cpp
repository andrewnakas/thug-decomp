typedef int qword __attribute__((mode(TI)));

struct Mat_001D7248 {
    qword r0;
    qword r1;
    qword r2;
    qword r3;
    Mat_001D7248() {}
    void Set(const qword& a, const qword& b, const qword& c, const qword& d)
    {
        r0 = a;
        r1 = b;
        r2 = c;
        r3 = d;
    }
};

struct Node_001D33D8 {
    int m0;
    unsigned short m_flags;
    void* m8;
    virtual void Update();
    virtual ~Node_001D33D8();
};

struct Node_001D4D50 : Node_001D33D8 {
    qword m10;
    Mat_001D7248 m20;
    Mat_001D7248 m60;
    int mA0;
    Node_001D4D50(const Node_001D4D50& o);
    virtual void Update();
    virtual ~Node_001D4D50();
};

Node_001D4D50::Node_001D4D50(const Node_001D4D50& o)
    : Node_001D33D8(o), m10(o.m10)
{
    m20.Set(o.m20.r0, o.m20.r1, o.m20.r2, o.m20.r3);
    m60.Set(o.m60.r0, o.m60.r1, o.m60.r2, o.m60.r3);
    mA0 = o.mA0;
}
