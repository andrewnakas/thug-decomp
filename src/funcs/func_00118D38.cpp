struct Base118238 {
    int m_pad[5];
    Base118238();
    virtual ~Base118238();
};

struct Comp118D38 : Base118238 {
    int m18[2];
    int m20;
    Comp118D38(int a, int b);
    virtual ~Comp118D38();
};

Comp118D38::Comp118D38(int a, int b)
{
    m20 = b;
}
