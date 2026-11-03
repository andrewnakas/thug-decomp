extern "C" void func_0018A928(void* table, int* key);

struct S_00189278 {
    char pad[0x18];
    int m_id;
};

struct L_00189278 {
    char pad[0x4];
    void Add(int a, int b, unsigned int c, int d, int e, int type);
};

struct E_00189278 {
    int m_id;
    int m_value;
    int m_owner;
};

struct C_00189278 {
    int m0;
    int m4;
    void* m_table;
    char padC[0x20 - 0xC];
    L_00189278 m_log;
    char pad24[0xB038 - 0x24];
    E_00189278 m_slots[40];
    void Rename(S_00189278* obj, int owner, int keep);
    void Release(S_00189278* obj);
};

void C_00189278::Rename(S_00189278* obj, int owner, int keep)
{
    int key = obj->m_id;
    func_0018A928(m_table, &key);
    if (keep) {
        for (int i = 0; i < 40; i++) {
            int id = obj->m_id;
            if (m_slots[i].m_owner == id) m_slots[i].m_owner = owner;
        }
    } else {
        Release(obj);
    }
    m_log.Add(0, obj->m_id, 0x36B2EE74, 0, 0, 5);
}
