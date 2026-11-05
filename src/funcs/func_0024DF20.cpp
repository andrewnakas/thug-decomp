struct Slot_0024DF20 {
    int m0;
    char pad[0x20];
};

struct Obj_0024DF20 {
    char pad[0xB4];
    Slot_0024DF20 m_slots[30];
    bool Fn();
};

bool Obj_0024DF20::Fn()
{
    for (int i = 0; i < 30; i++) {
        if (!m_slots[i].m0) return false;
    }
    return true;
}
