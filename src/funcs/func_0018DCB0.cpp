struct Slot_0018DCB0 {
    int m0;
    char pad4[0x1C - 0x4];
};

extern "C" void func_0018DDF0(Slot_0018DCB0* s);

struct Obj_0018DCB0 {
    Slot_0018DCB0 m_slots[6];
    int mA8;
    void Fn();
};

void Obj_0018DCB0::Fn()
{
    Slot_0018DCB0* s = m_slots;
    for (int i = 0; i < 6; i++, s++)
        func_0018DDF0(s);
    mA8 = 0;
}
