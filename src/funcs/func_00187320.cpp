struct Item_00187320 {
    int m0;
    int m_key;
    char pad8[0xC];
    Item_00187320* m_next;
};

struct Slot_00187320 {
    int m_key;
    int m4;
};

extern Item_00187320* D_004655E8[];

struct Mgr_00187320 {
    char pad0[0x50];
    unsigned int m_count;
    Slot_00187320 m_slots[1];
};

extern "C" void func_00187320(Mgr_00187320* mgr, Item_00187320* item)
{
    int key = item->m_key;
    for (unsigned int i = 0; i < mgr->m_count; i++) {
        if (mgr->m_slots[i].m_key == key) {
            Item_00187320* head = D_004655E8[i];
            if (head == item) {
                D_004655E8[i] = item->m_next;
                item->m_next = 0;
                return;
            }
            for (Item_00187320* p = head; p; p = p->m_next) {
                Item_00187320* n = p->m_next;
                if (n == item) {
                    p->m_next = n->m_next;
                    n->m_next = 0;
                    return;
                }
            }
        }
    }
}
