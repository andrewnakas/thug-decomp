struct Comp_002958F8 {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    virtual ~Comp_002958F8();
    virtual void V1();
    virtual void V2(int arg);
    void Call(int arg);
};

void Comp_002958F8::Call(int arg) { V2(arg); }
