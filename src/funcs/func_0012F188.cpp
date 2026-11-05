struct Obj_0012F188 {
    char pad[0x5B4];
    int m_ids[48];
    int m_count;
    bool Has(int id);
};

bool Obj_0012F188::Has(int id)
{
    for (int i = 0; i < m_count; i++) {
        if (id == m_ids[i])
            return true;
    }
    return false;
}
