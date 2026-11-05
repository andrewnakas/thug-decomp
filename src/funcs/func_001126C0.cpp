struct Item_001126C0 {
    int m0;
    int m4;
    int m_id;
};

struct Group_001126C0 {
    unsigned int m_count;
    int m4;
    Item_001126C0* m_items;
};

extern "C" Item_001126C0* func_001126C0(int id, Group_001126C0* g)
{
    for (; g->m_count != 0xFFFFFFFF; g++) {
        Item_001126C0* it = g->m_items;
        for (unsigned int i = 0; i < g->m_count; i++, it++) {
            if (it->m_id == id) {
                return it;
            }
        }
    }
    return 0;
}
