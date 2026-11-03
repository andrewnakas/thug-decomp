struct Base_00104870 {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    Base_00104870();
    virtual ~Base_00104870();
};

struct Comp_002CBCE0 : public Base_00104870 {
    char pad1C[0x20 - 0x1C];
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    Comp_002CBCE0();
    virtual void Update();
    virtual ~Comp_002CBCE0();
};

Comp_002CBCE0::~Comp_002CBCE0() {}
