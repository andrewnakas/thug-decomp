struct Base18E0A8 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base18E0A8();
    virtual ~Base18E0A8();
};

struct Quat18E0A8 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp18E0A8 : Base18E0A8 {
    int m1C[5];
    Quat18E0A8 m30;
    Comp18E0A8();
    virtual void Update();
    virtual ~Comp18E0A8();
};

Comp18E0A8::~Comp18E0A8()
{
}
