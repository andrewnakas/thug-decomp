struct Slot_0018DD00 {
    int m0;
    char pad4[0x1C - 0x4];
};

extern "C" void func_0018DE00(Slot_0018DD00* s);

struct Obj_0018DD00 {
    Slot_0018DD00 m_slots[6];
    int mA8;
    void Fn();
};

void Obj_0018DD00::Fn()
{
    Slot_0018DD00* s = m_slots;
    for (int i = 0; i < 6; i++, s++) {
        if (!s->m0) {
            func_0018DE00(s);
            mA8 = 1;
            return;
        }
    }
}
