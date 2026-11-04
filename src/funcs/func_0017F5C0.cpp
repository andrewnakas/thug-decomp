struct Base17F5C0 {
    int m_pad[6];
    Base17F5C0(int a);
    virtual void Update();
};

struct Comp17F5C0 : Base17F5C0 {
    Comp17F5C0();
    virtual void Update();
};

Comp17F5C0::Comp17F5C0() : Base17F5C0(1)
{
}
