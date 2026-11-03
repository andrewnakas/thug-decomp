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

struct Sub_00260520 {
    int m_data[0x1C];
    Sub_00260520();
    virtual ~Sub_00260520();
    int m74;
    int m78;
    int m7C;
};

struct Comp_002908C0 : public Component {
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    Sub_00260520 m30;
    Sub_00260520 mB0;
    Sub_00260520 m130;
    Sub_00260520 m1B0;
    int m230;
    Comp_002908C0();
    virtual void Update();
    virtual ~Comp_002908C0();
};

Comp_002908C0::~Comp_002908C0() {}
