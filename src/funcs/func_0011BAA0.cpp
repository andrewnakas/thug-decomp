struct Base11ABA8 {
    int m_pad[5];
    Base11ABA8();
    virtual ~Base11ABA8();
};

struct Comp11BAA0 : Base11ABA8 {
    Comp11BAA0();
    virtual void Update();
    virtual ~Comp11BAA0();
};

Comp11BAA0::~Comp11BAA0()
{
}
