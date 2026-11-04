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

struct Comp_00290368 : public Component {
    Comp_00290368();
    virtual void Update();
    virtual ~Comp_00290368();
};

Comp_00290368::Comp_00290368() {
    m_type = 0xD8CC3428;
}
