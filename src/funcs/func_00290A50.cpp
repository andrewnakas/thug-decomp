struct Component {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    virtual ~Component();
    virtual void V1();
    virtual void V2(int arg);
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int on);
    void Enable();
};

void Component::Enable() { V6(1); }
