struct Base11ABA8 {
    int m_pad[5];
    Base11ABA8();
    virtual ~Base11ABA8();
};

struct Comp11B610 : Base11ABA8 {
    Comp11B610();
    virtual void Update();
    virtual ~Comp11B610();
};

Comp11B610::~Comp11B610()
{
}
