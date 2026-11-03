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
    virtual void Refresh();
    virtual ~Comp_0028FA40();
};

Comp_0028FA40::~Comp_0028FA40() {}
