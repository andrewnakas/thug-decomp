/* fuzzy: 76.6 */
struct Ent_001DAC80 {
    int id;
    int val;
};
struct Obj_001DAC80 {
    char pad0[0x20];
    Ent_001DAC80 m_ents[(0xFC0 - 0x20) / 8];
    int m_count;
    int m_start;
    int m_FC8;
    void Remove(int id);
};

void Obj_001DAC80::Remove(int id)
{
    int i = m_start;
    Ent_001DAC80* e = &m_ents[i];
    for (;;) {
        if (i >= m_count)
            return;
        if (e->id == id)
            break;
        i++;
        e++;
    }
    m_count--;
    *e = m_ents[m_count];
    m_FC8--;
}
