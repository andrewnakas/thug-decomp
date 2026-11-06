struct Slot_00272560 {
    int m0;
    char pad[0x10];
};

struct Obj_00272560 {
    char pad[0x2C];
    Slot_00272560 m_slots[3];
    void Reset();
};

void Obj_00272560::Reset()
{
    for (int i = 2; i != -1; i--)
        m_slots[i].m0 = 0;
}
