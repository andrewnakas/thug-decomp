struct Base1BC4C0 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1BC4C0();
    virtual ~Base1BC4C0();
};

struct Quat1BC4C0 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1BC4C0 : Base1BC4C0 {
    int m1C[5];
    Quat1BC4C0 m30;
    Comp1BC4C0();
    virtual void Update();
    virtual ~Comp1BC4C0();
};

Comp1BC4C0::~Comp1BC4C0()
{
}
