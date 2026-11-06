struct O_001D4C60 {
    int m0, m4, m8;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8();
};

struct N_001D4C60 {
    int m0;
    O_001D4C60* m4;
    int m8;
    N_001D4C60* mC;
    N_001D4C60* Valid() { if ((int)m4 == -1) return 0; return this; }
};

struct C_001D4C60 {
    char m_pad[0x10];
    N_001D4C60* m10;
    void Run();
};

void C_001D4C60::Run()
{
    m10->mC->Valid()->m4->V8();
}
