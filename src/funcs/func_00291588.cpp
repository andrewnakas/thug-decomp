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

struct Comp_00291588 : public Component {
    int m1C;
    char pad20[0x2C - 0x20];
    int m2C;
    int m30;
    Comp_00291588();
    virtual void Update();
    virtual ~Comp_00291588();
};

Comp_00291588::Comp_00291588() {
    m_type = 0x488AF07A;
    m2C = 0;
    m30 = 0;
    m1C = 0;
}
