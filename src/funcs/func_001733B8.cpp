struct Base1733B8 {
    int m_pad[6];
    Base1733B8(int a);
    virtual void Update();
};

struct Comp1733B8 : Base1733B8 {
    Comp1733B8();
    virtual void Update();
};

Comp1733B8::Comp1733B8() : Base1733B8(1)
{
}
