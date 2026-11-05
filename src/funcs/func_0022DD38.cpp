struct Node_0022DD38 {
    void* m_key;
    unsigned int m_item;
    Node_0022DD38* m_prev;
    Node_0022DD38* m_next;
    bool IsEnd() { return m_item == 0xFFFFFFFF; }
    Node_0022DD38* GetItem() { return m_item == 0xFFFFFFFF ? 0 : this; }
};

struct Head_0022DD38 {
    void* m_key;
    unsigned int m_item;
    Node_0022DD38* m_prev;
    Node_0022DD38* m_next;
    Node_0022DD38* FirstItem()
    {
        if (m_next->IsEnd()) {
            return 0;
        }
        return m_next;
    }
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_0022DD38* item = FirstItem();
        while (item) {
            item = item->m_next->GetItem();
            count++;
        }
        return count;
    }
    Node_0022DD38* GetItem(unsigned int index)
    {
        Node_0022DD38* item = FirstItem();
        while (item) {
            if (index-- == 0) {
                return item;
            }
            item = item->m_next->GetItem();
        }
        return 0;
    }
};

struct Skater_0022DD38 {
    char pad[0x31C];
    int m_31C;
};

struct Mgr_0022DD38 {
    char m_pad[0x30];
    Head_0022DD38 m_skaters;
    void* FindActive();
};

void* Mgr_0022DD38::FindActive()
{
    for (unsigned int i = 0; i < m_skaters.CountItems(); i++) {
        if (m_skaters.GetItem(i)) {
            Skater_0022DD38* s = (Skater_0022DD38*)m_skaters.GetItem(i)->m_item;
            if (s->m_31C) {
                return s;
            }
        }
    }
    return 0;
}
