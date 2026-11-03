struct Base1733F0 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1733F0();
    virtual ~Base1733F0();
};

struct Quat1733F0 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1733F0 : Base1733F0 {
    int m1C[5];
    Quat1733F0 m30;
    Comp1733F0();
    virtual void Update();
    virtual ~Comp1733F0();
};

Comp1733F0::~Comp1733F0()
{
}
