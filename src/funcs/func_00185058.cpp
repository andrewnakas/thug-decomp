extern "C" void func_001EFDC0(void* p);

struct K_00185058 {
    char pad0[0x8];
    unsigned int m_flags;
    char padC[0x10 - 0xC];
    K_00185058* m_next;
    char pad14[0x18 - 0x14];
    virtual void V0();
    virtual void Update();
};

struct B_00185058 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void Think();
};

struct C_00185058 : B_00185058 {
    unsigned int m_state;
    int m10;
    void* m_model;
    char pad18[0x100 - 0x18];
    K_00185058* m_comps;
    int m_mode;
    void Update();
};

void C_00185058::Update()
{
    if (m_mode & 1) return;
    if (!(m_mode & 2)) {
        if (m_model) func_001EFDC0(m_model);
        if (m_state & 1) return;
        Think();
    }
    for (K_00185058* c = m_comps; c; c = c->m_next) {
        if (c->m_flags & 1) continue;
        c->Update();
        if (m_state & 1) break;
    }
    m_mode &= ~8;
}
