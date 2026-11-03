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

struct Comp_002904C8 : public Component {
    int m1C;
    Comp_002904C8();
    virtual void Update();
    virtual ~Comp_002904C8();
};

Comp_002904C8::Comp_002904C8() {
    m_type = 0xB1D5A3E1;
    m1C = 0;
}
