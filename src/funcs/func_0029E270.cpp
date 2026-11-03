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

struct Comp_0029E230 : public Component {
    Comp_0029E230();
    virtual void Update();
    virtual ~Comp_0029E230();
};

Comp_0029E230::~Comp_0029E230() {}
