struct Base1B11A8 {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    Base1B11A8();
    virtual ~Base1B11A8();
};

struct Quat1B11A8 {
    float x, y, z, w;
};

// Destructor only resets the vtable and chains to the base destructor.
struct Comp1B11A8 : Base1B11A8 {
    int m1C[5];
    Quat1B11A8 m30;
    Comp1B11A8();
    virtual void Update();
    virtual ~Comp1B11A8();
};

Comp1B11A8::~Comp1B11A8()
{
}
