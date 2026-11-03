struct Component {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    Component();
    virtual ~Component();
};

struct Comp_00291B80 : public Component {
    char pad1C[0x188 - 0x1C];
    int m188[1];
    Comp_00291B80();
    virtual void Update();
    virtual ~Comp_00291B80();
};

Comp_00291B80::~Comp_00291B80() {}
