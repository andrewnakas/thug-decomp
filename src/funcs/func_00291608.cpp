struct Comp_00291588 {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    virtual ~Comp_00291588();
    virtual void V1();
    virtual void V2(int arg);
    void Call(int arg);
};

void Comp_00291588::Call(int arg) { V2(arg); }
