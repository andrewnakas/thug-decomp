struct Item_00112618 {
    int m0;
    int m4;
    int m_id;
};

struct Group_00112618 {
    unsigned int m_count;
    int m_id;
    Item_00112618* m_items;
};

extern "C" void func_001124E8(int key, int* group, int* item);

extern "C" Item_00112618* func_00112618(int key, Group_00112618* g)
{
    int gid;
    int iid;
    func_001124E8(key, &gid, &iid);
    for (; g->m_count != 0xFFFFFFFF; g++) {
        if (g->m_id == gid) {
            Item_00112618* it = g->m_items;
            for (unsigned int i = 0; i < g->m_count; i++, it++) {
                if (it->m_id == iid) {
                    return it;
                }
            }
        }
    }
    return 0;
}
