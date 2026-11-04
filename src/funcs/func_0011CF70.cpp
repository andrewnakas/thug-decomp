struct Base11ABA8 {
    int m_pad[5];
    Base11ABA8();
    virtual ~Base11ABA8();
};

struct Comp11CF70 : Base11ABA8 {
    Comp11CF70();
    virtual void Update();
    virtual ~Comp11CF70();
};

Comp11CF70::~Comp11CF70()
{
}
