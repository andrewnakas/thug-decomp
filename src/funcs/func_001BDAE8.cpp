struct Base1BDAE8 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1BDAE8();
    virtual ~Base1BDAE8();
};

struct Quat1BDAE8 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1BDAE8 : Base1BDAE8 {
    int m1C[5];
    Quat1BDAE8 m30;
    Comp1BDAE8();
    virtual void Update();
    virtual ~Comp1BDAE8();
};

Comp1BDAE8::~Comp1BDAE8()
{
}
