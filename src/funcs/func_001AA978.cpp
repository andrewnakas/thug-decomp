struct Base1AA978 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1AA978();
    virtual ~Base1AA978();
};

struct Quat1AA978 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1AA978 : Base1AA978 {
    int m1C[5];
    Quat1AA978 m30;
    Comp1AA978();
    virtual void Update();
    virtual ~Comp1AA978();
};

Comp1AA978::~Comp1AA978()
{
}
