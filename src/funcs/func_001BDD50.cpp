struct Base1BDD50 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1BDD50();
    virtual ~Base1BDD50();
};

struct Quat1BDD50 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1BDD50 : Base1BDD50 {
    int m1C[5];
    Quat1BDD50 m30;
    Comp1BDD50();
    virtual void Update();
    virtual ~Comp1BDD50();
};

Comp1BDD50::~Comp1BDD50()
{
}
