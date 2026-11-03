struct Base11ABA8 {
    int m_pad[5];
    Base11ABA8();
    virtual ~Base11ABA8();
};

struct Comp11CEB0 : Base11ABA8 {
    Comp11CEB0();
    virtual void Update();
    virtual ~Comp11CEB0();
};

Comp11CEB0::~Comp11CEB0()
{
}
