struct Slot_0022DCE0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Mgr_0022DCE0 {
    char pad[0x3C8];
    Slot_0022DCE0 m_slots[8];
    void Set(int index, int value);
};

extern "C" void* func_0022DE70(Mgr_0022DCE0* self, int index);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001BAD28(void* comp, int value);

void Mgr_0022DCE0::Set(int index, int value)
{
    m_slots[index].m0 = value;
    void* obj = func_0022DE70(this, index);
    if (obj) {
        void* comp = func_00185578(obj, 0x404EB936);
        if (comp) {
            func_001BAD28(comp, value);
        }
    }
}
