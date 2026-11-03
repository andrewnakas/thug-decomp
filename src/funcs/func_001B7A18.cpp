struct Base1B7A18 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1B7A18();
    virtual ~Base1B7A18();
};

struct Quat1B7A18 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1B7A18 : Base1B7A18 {
    int m1C[5];
    Quat1B7A18 m30;
    Comp1B7A18();
    virtual void Update();
    virtual ~Comp1B7A18();
};

Comp1B7A18::~Comp1B7A18()
{
}
