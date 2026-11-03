struct Base_00243DB8 {
    int m_pad[5];
    Base_00243DB8();
    virtual ~Base_00243DB8();
};

struct Comp_0024B1A0 : Base_00243DB8 {
    Comp_0024B1A0();
    virtual ~Comp_0024B1A0() = 0;
    virtual void Update();
};

Comp_0024B1A0::~Comp_0024B1A0()
{
}
