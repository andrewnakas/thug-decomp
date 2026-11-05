struct Obj_00263188 {
    char pad[0x2C];
    int m_count;
    int m_ids[3];
    void* m_items[3];
    void* Find(int id);
};

void* Obj_00263188::Find(int id)
{
    for (int i = 0; i < m_count; i++) {
        if (m_ids[i] == id)
            return m_items[i];
    }
    return 0;
}
