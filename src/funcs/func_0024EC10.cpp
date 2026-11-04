struct Base_00243DB8 {
    int m_pad[5];
    Base_00243DB8();
    virtual ~Base_00243DB8();
};

struct Comp_0024EC10 : Base_00243DB8 {
    Comp_0024EC10();
    virtual ~Comp_0024EC10() = 0;
    virtual void Update();
};

Comp_0024EC10::~Comp_0024EC10()
{
}
