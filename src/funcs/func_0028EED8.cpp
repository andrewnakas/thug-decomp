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

struct Comp_0028EED8 : public Component {
    char pad1C[0x20 - 0x1C];
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    Comp_0028EED8();
    virtual void Update();
    virtual ~Comp_0028EED8();
};

Comp_0028EED8::Comp_0028EED8() {
    m_type = 0x9F9CC949;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m20 = 0;
}
