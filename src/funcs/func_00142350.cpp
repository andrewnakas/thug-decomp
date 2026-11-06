class Obj_00142350 {
public:
    char pad[0x150];
    int m_150;
    char pad154[0x3C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    void SetMode(int m);
};

void Obj_00142350::SetMode(int m)
{
    if (m_150 != m) {
        m_150 = m;
        V3();
    }
}
