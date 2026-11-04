struct Base118238 {
    int m_pad[5];
    Base118238();
    virtual ~Base118238();
};

struct Comp118C90 : Base118238 {
    int m18[2];
    int m20;
    Comp118C90(int a, int b);
    virtual ~Comp118C90();
};

Comp118C90::Comp118C90(int a, int b)
{
    m20 = b;
}
