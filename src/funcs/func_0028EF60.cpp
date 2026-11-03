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
    void Call(int arg);
};

void Component::Call(int arg) { V2(arg); }
