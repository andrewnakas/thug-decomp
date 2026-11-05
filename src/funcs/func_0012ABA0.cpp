extern "C" int func_0013ED40(void* p, int mask);

struct Slot_0012ABA0 {
    void* m_ref;
    char pad[0x1C];
};

struct Obj_0012ABA0 {
    char pad[0x1A0];
    Slot_0012ABA0 m_slots[25];
    int m_count;
    char pad4C4[0x590 - 0x4C4];
    int m_layer;
    void ApplyLayer();
};

void Obj_0012ABA0::ApplyLayer()
{
    int mask = 1 << m_layer;
    for (int i = 0; i < m_count; i++) {
        func_0013ED40(m_slots[i].m_ref, mask);
    }
}
