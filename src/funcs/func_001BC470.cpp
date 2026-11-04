struct Base1BC470 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1BC470();
    virtual ~Base1BC470();
};

struct Quat1BC470 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1BC470 : Base1BC470 {
    int m1C[5];
    Quat1BC470 m30;
    Comp1BC470();
    virtual void Update();
    virtual ~Comp1BC470();
};

Comp1BC470::~Comp1BC470()
{
}
