struct Base11ABA8 {
    int m_pad[5];
    Base11ABA8();
    virtual ~Base11ABA8();
};

struct Comp11BB40 : Base11ABA8 {
    Comp11BB40();
    virtual void Update();
    virtual ~Comp11BB40();
};

Comp11BB40::~Comp11BB40()
{
}
