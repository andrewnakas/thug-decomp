struct Entry_001872C8 {
    unsigned int m_key;
    void* m_fn;
};

struct Item_001872C8 {
    int m0;
    unsigned int m4;
    char pad8[0x14 - 0x8];
    Item_001872C8* m14;
};

extern Item_001872C8* D_004655E8[];

struct Reg_001872C8 {
    char pad0[0x50];
    unsigned int m50;
    Entry_001872C8 m54[1];
    void Push(Item_001872C8* item);
};

void Reg_001872C8::Push(Item_001872C8* item)
{
    unsigned int key = item->m4;
    for (unsigned int i = 0; i < m50; i++) {
        if (m54[i].m_key == key) {
            item->m14 = D_004655E8[i];
            D_004655E8[i] = item;
            return;
        }
    }
}
