struct Node_0022DE70 {
    void* m_key;
    unsigned int m_item;
    Node_0022DE70* m_prev;
    Node_0022DE70* m_next;
    Node_0022DE70* GetItem() { return m_item == 0xFFFFFFFF ? 0 : this; }
};

struct Head_0022DE70 {
    void* m_key;
    unsigned int m_item;
    Node_0022DE70* m_prev;
    Node_0022DE70* m_next;
    Node_0022DE70* FirstItem()
    {
        if (!~m_next->m_item) {
            return 0;
        }
        return m_next;
    }
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_0022DE70* item = m_next->GetItem();
        while (item) {
            item = item->m_next->GetItem();
            count++;
        }
        return count;
    }
    Node_0022DE70* GetItem(unsigned int index)
    {
        Node_0022DE70* item = FirstItem();
        while (item) {
            if (index-- == 0) {
                return item;
            }
            item = item->m_next->GetItem();
        }
        return 0;
    }
};

struct Mgr_0022DE70 {
    char m_pad[0x30];
    Head_0022DE70 m_skaters;
    void* GetSkater(unsigned int index);
};

void* Mgr_0022DE70::GetSkater(unsigned int index)
{
    if (index >= m_skaters.CountItems()) {
        return 0;
    }
    return (void*)m_skaters.GetItem(index)->m_item;
}
