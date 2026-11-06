struct Ent_00136DF8 {
    char pad0[0x10];
    float m_rate;
    float m_invRate;
};

extern "C" Ent_00136DF8* func_001365E8(unsigned int id);

class Obj_00136DF8 {
public:
    char pad0[0x14];
    float m_rate;
    unsigned int m_id;
    void SetRate(float r);
};

void Obj_00136DF8::SetRate(float r)
{
    if (r == m_rate) {
        return;
    }
    m_rate = r;
    Ent_00136DF8* e = func_001365E8(m_id);
    if (e) {
        e->m_rate = r;
        e->m_invRate = 1.0f / r;
    }
}
