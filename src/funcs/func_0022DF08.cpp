struct Node_0022DF08 {
    void* m_key;
    unsigned int m_item;
    Node_0022DF08* m_prev;
    Node_0022DF08* m_next;
    bool IsEnd() { return m_item == 0xFFFFFFFF; }
    Node_0022DF08* GetItem() { return m_item == 0xFFFFFFFF ? 0 : this; }
};

struct Head_0022DF08 {
    void* m_key;
    unsigned int m_item;
    Node_0022DF08* m_prev;
    Node_0022DF08* m_next;
    Node_0022DF08* FirstItem()
    {
        if (m_next->IsEnd()) {
            return 0;
        }
        return m_next;
    }
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_0022DF08* item = FirstItem();
        while (item) {
            item = item->m_next->GetItem();
            count++;
        }
        return count;
    }
    Node_0022DF08* GetItem(unsigned int index)
    {
        Node_0022DF08* item = FirstItem();
        while (item) {
            if (index-- == 0) {
                return item;
            }
            item = item->m_next->GetItem();
        }
        return 0;
    }
};

struct Skater_0022DF08 {
    char pad[0x18];
    int m_18;
};

struct Mgr_0022DF08 {
    char m_pad[0x30];
    Head_0022DF08 m_skaters;
    void* FindByKey(int key);
};

void* Mgr_0022DF08::FindByKey(int key)
{
    for (unsigned int i = 0; i < m_skaters.CountItems(); i++) {
        if (m_skaters.GetItem(i)) {
            Skater_0022DF08* s = (Skater_0022DF08*)m_skaters.GetItem(i)->m_item;
            if (s->m_18 == key) {
                return s;
            }
        }
    }
    return 0;
}
