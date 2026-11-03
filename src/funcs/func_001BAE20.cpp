struct Base1BAE20 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1BAE20();
    virtual ~Base1BAE20();
};

struct Quat1BAE20 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1BAE20 : Base1BAE20 {
    int m1C[5];
    Quat1BAE20 m30;
    Comp1BAE20();
    virtual void Update();
    virtual ~Comp1BAE20();
};

Comp1BAE20::~Comp1BAE20()
{
}
