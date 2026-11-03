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

struct Comp_0029DBC8 : public Component {
    char pad1C[0x20 - 0x1C];
    int m20;
    int m24;
    int m28;
    int m2C;
    char pad30[0x40 - 0x30];
    int m40;
    Comp_0029DBC8();
    virtual void Update();
    virtual ~Comp_0029DBC8();
};

Comp_0029DBC8::~Comp_0029DBC8() {}
