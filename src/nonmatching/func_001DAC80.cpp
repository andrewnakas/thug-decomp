/* fuzzy: 48.4 */
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
    for (int i = m_start; i < m_count; i++) {
        Ent_001DAC80* e = &m_ents[i];
        if (e->id == id) {
            m_count--;
            *e = m_ents[m_count];
            m_FC8--;
            return;
        }
    }
}
