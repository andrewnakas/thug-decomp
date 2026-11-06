struct Counter_001832A0 {
    unsigned int m_cur;
    unsigned int m_max;
    void Check()
    {
        if (m_cur && m_cur >= m_max) {
            m_cur = 0;
        }
    }
};

struct Slot_001832A0 {
    char pad0[0x84];
    Counter_001832A0 m_a;
    Counter_001832A0 m_b;
};

struct Owner_001832A0 {
    int m0;
    void* m4;
    Slot_001832A0 m_slots[2];
};

struct Obj_001832A0 {
    char pad0[0x20];
    Owner_001832A0* m_owner;
};

extern "C" void func_00183448(Slot_001832A0* s);

extern "C" void func_001832A0(Obj_001832A0* obj)
{
    Owner_001832A0* o = obj->m_owner;
    for (int i = 0; i < 2; i++) {
        o->m_slots[i].m_a.Check();
        o->m_slots[i].m_b.Check();
        func_00183448(&o->m_slots[i]);
    }
}
