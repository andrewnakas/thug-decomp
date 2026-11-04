struct Slot_0026F6C0 {
    int m_pad[7];
    int m_id;
    int m20;
    Slot_0026F6C0* Match(int id)
    {
        if (m_id == id)
            return this;
        return 0;
    }
};

struct Set_0026F6C0 {
    int m0;
    Slot_0026F6C0 m_s0;
    Slot_0026F6C0 m_s1;
    Slot_0026F6C0 m_s2;
    Slot_0026F6C0 m_s3;
    Slot_0026F6C0 m_s4;
    Slot_0026F6C0 m_s5;
    Slot_0026F6C0 m_s6;
    Slot_0026F6C0 m_s7;
    Slot_0026F6C0 m_s8;
    Slot_0026F6C0 m_s9;
    Slot_0026F6C0 m_s10;
    Slot_0026F6C0 m_s11;
    Slot_0026F6C0 m_s12;
    Slot_0026F6C0 m_s13;
    Slot_0026F6C0 m_s14;
    Slot_0026F6C0 m_s15;
    Slot_0026F6C0* Find(int id);
};

Slot_0026F6C0* Set_0026F6C0::Find(int id)
{
    Slot_0026F6C0* s;
    s = &m_s0;
    if (s->m_id == id)
        return s;
    s = &m_s1;
    if (s->m_id == id)
        return s;
    s = &m_s2;
    if (s->m_id == id)
        return s;
    s = &m_s3;
    if (s->m_id == id)
        return s;
    s = &m_s11;
    if (s->m_id == id)
        return s;
    s = &m_s10;
    if (s->m_id == id)
        return s;
    s = &m_s12;
    if (s->m_id == id)
        return s;
    s = &m_s13;
    if (s->m_id == id)
        return s;
    s = &m_s4;
    if (s->m_id == id)
        return s;
    s = &m_s5;
    if (s->m_id == id)
        return s;
    s = &m_s6;
    if (s->m_id == id)
        return s;
    s = &m_s7;
    if (s->m_id == id)
        return s;
    s = &m_s8;
    if (s->m_id == id)
        return s;
    s = &m_s9;
    if (s->m_id == id)
        return s;
    s = &m_s14;
    if (s->m_id == id)
        return s;
    return m_s15.Match(id);
}
