class Tgt_0014A760 {
public:
    int m0[6];
    virtual void V0();
    virtual void V1(int v);
};

struct Obj_0014A760 {
    char pad[0x28];
    int m_28;
    char pad2[0x10];
    Tgt_0014A760* m_3C;
    void Apply();
};

void Obj_0014A760::Apply()
{
    m_3C->V1(m_28);
}
