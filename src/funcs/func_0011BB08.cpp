struct Base11AB88 {
    int m_pad[5];
    Base11AB88();
    virtual ~Base11AB88();
};

struct Comp11BB08 : Base11AB88 {
    Comp11BB08();
    virtual ~Comp11BB08();
};

Comp11BB08::Comp11BB08()
{
}
