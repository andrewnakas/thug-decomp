struct Base1A4450 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1A4450();
    virtual ~Base1A4450();
};

struct Quat1A4450 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1A4450 : Base1A4450 {
    int m1C[5];
    Quat1A4450 m30;
    Comp1A4450();
    virtual void Update();
    virtual ~Comp1A4450();
};

Comp1A4450::~Comp1A4450()
{
}
