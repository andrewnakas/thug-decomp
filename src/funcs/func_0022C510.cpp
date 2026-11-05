struct Node_0022C510 {
    void* m_key;
    unsigned int m_item;
    Node_0022C510* m_prev;
    Node_0022C510* m_next;
    bool IsEnd() { return m_item == 0xFFFFFFFF; }
    Node_0022C510* GetItem() { return m_item == 0xFFFFFFFF ? 0 : this; }
};

struct Head_0022C510 {
    void* m_key;
    unsigned int m_item;
    Node_0022C510* m_prev;
    Node_0022C510* m_next;
    Node_0022C510* FirstItem()
    {
        if (m_next->IsEnd()) {
            return 0;
        }
        return m_next;
    }
    unsigned int CountItems()
    {
        unsigned int count = 0;
        Node_0022C510* item = m_next->GetItem();
        while (item) {
            item = item->m_next->GetItem();
            count++;
        }
        return count;
    }
    Node_0022C510* GetItem(unsigned int index)
    {
        Node_0022C510* item = FirstItem();
        while (item) {
            if (index-- == 0) {
                return item;
            }
            item = item->m_next->GetItem();
        }
        return 0;
    }
};

struct Mgr_0022C510 {
    char m_pad[0x30];
    Head_0022C510 m_list;
    unsigned int FindSlot(int flag);
};

extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F750(void* a);
extern "C" unsigned int func_002041F8(unsigned int item);

unsigned int Mgr_0022C510::FindSlot(int flag)
{
    unsigned int slot = flag == 0;
    for (int tries = 0; tries < (int)func_0024F750(func_0022E358(this)); tries++) {
        bool used = false;
        for (unsigned int i = 0; i < m_list.CountItems(); i++) {
            if (m_list.GetItem(i)) {
                if (func_002041F8(m_list.GetItem(i)->m_item) == slot) {
                    used = true;
                    break;
                }
            }
        }
        if (!used) {
            return slot;
        }
        slot = (slot + 1) % func_0024F750(func_0022E358(this));
    }
    return slot;
}
