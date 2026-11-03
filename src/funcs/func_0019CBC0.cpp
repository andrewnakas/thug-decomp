struct Base19CBC0 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base19CBC0();
    virtual ~Base19CBC0();
};

struct Quat19CBC0 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp19CBC0 : Base19CBC0 {
    int m1C[5];
    Quat19CBC0 m30;
    Comp19CBC0();
    virtual void Update();
    virtual ~Comp19CBC0();
};

Comp19CBC0::~Comp19CBC0()
{
}
