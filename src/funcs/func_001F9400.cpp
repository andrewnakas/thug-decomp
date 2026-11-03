struct Node_001F9400 {
    int m0;
    int m4;
    int m8;
    Node_001F9400* mC;
    Node_001F9400* m10;

    void Unlink()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
};

struct Conn_001F9400 {
    char m_pad[0x1808];
    Node_001F9400 m1808;
    char m_pad2[0x4358 - 0x181C];
    virtual ~Conn_001F9400();
    virtual void V1();
};

struct Mgr_001F9400 {
    char m_pad[0x2A0];
    int m2A0;
};

extern "C" void func_00201200(Conn_001F9400*);

void func_001F9400(Mgr_001F9400* m, Conn_001F9400* c)
{
    c->m1808.Unlink();
    func_00201200(c);
    delete c;
    m->m2A0--;
}
