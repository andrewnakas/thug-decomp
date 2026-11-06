class Item_00119DC8 {
public:
    int m0[5];
    virtual ~Item_00119DC8();
};

class Set_00119DC8 {
public:
    char pad0[0x3C];
    Item_00119DC8* m_items[4];
    int m_count;
    void Remove(Item_00119DC8* it);
};

void Set_00119DC8::Remove(Item_00119DC8* it)
{
    for (int i = 0; i < m_count; i++) {
        if (it == m_items[i]) {
            if (it) {
                delete it;
            }
            m_items[i] = 0;
            for (int j = i; j < m_count - 1; j++) {
                m_items[j] = m_items[j + 1];
            }
            m_count--;
            return;
        }
    }
}
