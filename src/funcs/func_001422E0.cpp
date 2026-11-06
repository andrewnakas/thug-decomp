class Obj_001422E0 {
public:
    char pad0[0x150];
    int m_busy;
    int m_locked;
    char pad158[0x190 - 0x158];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Try();
};

void Obj_001422E0::Try()
{
    if (!m_busy && !m_locked) {
        V5();
    }
}
