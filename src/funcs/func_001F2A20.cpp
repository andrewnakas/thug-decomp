extern "C" void func_001F1478(void* self);

struct Slot_001F2A20 {
    int m0;
    int m4;
    bool TryTake()
    {
        if (m0) {
            m0--;
            return true;
        }
        return false;
    }
};

struct Obj_001F2A20 {
    char m_pad0[0x14C];
    Slot_001F2A20 m14C[19];
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
    int m1F4;
    void Take();
};

void Obj_001F2A20::Take()
{
    Slot_001F2A20* slots = m14C;
    int n;
    Slot_001F2A20* s;
    while (!(n = (s = &slots[m1E8])->m0)) {
        func_001F1478(this);
        if (m1F4)
            return;
    }
    s->m0 = n - 1;
}
