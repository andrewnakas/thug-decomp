struct Slot_0022DC50 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Comp_0022DC50 {
    char pad[0x368];
    int m_368;
};

struct Mgr_0022DC50 {
    char pad[0x3C8];
    Slot_0022DC50 m_slots[8];
    void Set(int index, int value);
};

extern "C" void* func_0022DE70(Mgr_0022DC50* self, int index);
extern "C" Comp_0022DC50* func_00185578(void* obj, unsigned int name);

void Mgr_0022DC50::Set(int index, int value)
{
    m_slots[index].m8 = value;
    void* obj = func_0022DE70(this, index);
    if (obj) {
        func_00185578(obj, 0x5BD63B29)->m_368 = value;
    }
}
