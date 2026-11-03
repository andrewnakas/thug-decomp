extern "C" int func_001F0708(int id);
extern "C" void func_001EE5F8(void* obj);

struct O_00189F98 {
    char pad[0x18];
    int m18;
};

struct S_00189F98 {
    char pad[0xAC];
    int mAC;
    char padB0[0xBC - 0xB0];
    O_00189F98* mBC;
};

struct E_00189F98 {
    int m_id;
    int m_value;
    int m_owner;
};

struct C_00189F98 {
    char pad[0xB038];
    E_00189F98 m_slots[40];
    void Add(S_00189F98* obj, int value);
};

void C_00189F98::Add(S_00189F98* obj, int value)
{
    int slot = -1;
    int i;
    for (i = 0; i < 40; i++) {
        if (m_slots[i].m_value == 0) {
            slot = i;
            break;
        }
    }
    if (slot < 0) {
        for (i = 0; i < 40; i++) {
            if (!func_001F0708(m_slots[i].m_id)) {
                slot = i;
                break;
            }
        }
        if (slot < 0) return;
    }
    m_slots[slot].m_id = obj->mAC;
    if (obj->mBC) m_slots[slot].m_owner = obj->mBC->m18;
    else m_slots[slot].m_owner = 0;
    m_slots[slot].m_value = value;
    func_001EE5F8(obj);
}
