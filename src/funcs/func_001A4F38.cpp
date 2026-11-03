struct Base1A4F38 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1A4F38();
    virtual ~Base1A4F38();
};

struct Quat1A4F38 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1A4F38 : Base1A4F38 {
    int m1C[5];
    Quat1A4F38 m30;
    Comp1A4F38();
    virtual void Update();
    virtual ~Comp1A4F38();
};

Comp1A4F38::~Comp1A4F38()
{
}
