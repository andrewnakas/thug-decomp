struct Slot_001F1318 {
    char m[0x10];
};

struct Pair_001F1318 {
    int a;
    int b;
};

extern "C" void func_001E6250(Slot_001F1318* s);

struct Obj_001F1318 {
    int m0;
    Slot_001F1318 m_slots[20];
    int m144;
    Pair_001F1318 m_pairs[20];
    int m1E8;
    int m1EC;
    int m1F0;
    int m1F4;
    void Reset();
};

void Obj_001F1318::Reset()
{
    int i;
    for (i = 0; i < 20; i++)
        func_001E6250(&m_slots[i]);
    m144 = 0;
    m1E8 = 0;
    for (i = 0; i < 20; i++) {
        m_pairs[i].a = 0;
        m_pairs[i].b = 0;
    }
    m1EC = 0;
    m1F4 = 0;
}
