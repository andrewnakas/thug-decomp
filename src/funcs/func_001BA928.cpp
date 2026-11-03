extern "C" unsigned int func_0010FC30();
extern "C" void func_00107CA0(void* p, int i, int v);

struct Slot_001BA928 {
    int m_active;
    unsigned int m_start;
    unsigned int m_duration;
};

struct Base_001BA928 {
    int m_pad[6];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Suspend(int on);
};

struct C_001BA928 : Base_001BA928 {
    int m1C;
    Slot_001BA928 m_slots[2];
    void* m38;
    void Update();
};

void C_001BA928::Update()
{
    if (!m1C) {
        Suspend(1);
        return;
    }
    for (int i = 1; i != -1; i--) {
        if (!m_slots[i].m_active) continue;
        unsigned int start = m_slots[i].m_start;
        if (func_0010FC30() - start < m_slots[i].m_duration) continue;
        func_00107CA0(m38, i, 0);
        m_slots[i].m_active = 0;
    }
}
