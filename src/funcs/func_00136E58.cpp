struct Ent_00136E58 {
    char pad0[0x18];
    float m_value;
};

extern "C" Ent_00136E58* func_001365E8(unsigned int id);

class Obj_00136E58 {
public:
    char pad0[0x10];
    float m_value;
    int m14;
    unsigned int m_id;
    void SetValue(float v);
};

void Obj_00136E58::SetValue(float v)
{
    if (v == m_value) {
        return;
    }
    m_value = v;
    Ent_00136E58* e = func_001365E8(m_id);
    if (e) {
        e->m_value = v;
    }
}
