struct Item_002BA848 {
    char pad0[0xC];
    int mC;
    char pad10[0x20];
};

struct Obj_002BA848 {
    char pad0[0xC0];
    Item_002BA848 m_items[18];
    void Reset();
};

void Obj_002BA848::Reset() {
    for (int i = 17; i >= 0; i--) {
        m_items[i].mC = 0;
    }
}
