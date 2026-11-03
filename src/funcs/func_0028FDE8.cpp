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

struct Comp_0028FDA8 : public Component {
    Comp_0028FDA8();
    virtual void Update();
    virtual ~Comp_0028FDA8();
};

Comp_0028FDA8::~Comp_0028FDA8() {}
