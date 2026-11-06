struct Item_00119EA8 {
    int m0[4];
    int m_id;
};

class Set_00119EA8 {
public:
    char pad0[0x3C];
    Item_00119EA8* m_items[4];
    int m_count;
    Item_00119EA8* Find(int id);
};

Item_00119EA8* Set_00119EA8::Find(int id)
{
    for (int i = 0; i < m_count; i++) {
        if (m_items[i]->m_id == id) {
            return m_items[i];
        }
    }
    return 0;
}
