struct Base1A9BA0 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1A9BA0();
    virtual ~Base1A9BA0();
};

struct Quat1A9BA0 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1A9BA0 : Base1A9BA0 {
    int m1C[5];
    Quat1A9BA0 m30;
    Comp1A9BA0();
    virtual void Update();
    virtual ~Comp1A9BA0();
};

Comp1A9BA0::~Comp1A9BA0()
{
}
