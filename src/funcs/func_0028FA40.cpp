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

struct Comp_0028FA40 : public Component {
    int m1C;
    int m20;
    Comp_0028FA40();
    virtual ~Comp_0028FA40();
};

Comp_0028FA40::Comp_0028FA40() {
    m_type = 0x9B373E58;
    m1C = 0;
    m20 = 0;
}
