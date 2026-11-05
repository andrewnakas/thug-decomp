class Tgt_0014A2A0 {
public:
    int m0[6];
    virtual void V0();
    virtual void V1(int v);
};

struct Obj_0014A2A0 {
    char pad[0x2C];
    int m_2C;
    char pad2[0x10];
    Tgt_0014A2A0* m_40;
    void Apply();
};

void Obj_0014A2A0::Apply()
{
    m_40->V1(m_2C);
}
