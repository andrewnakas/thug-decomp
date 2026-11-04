extern "C" void func_001D0460(void* self, void* n);
extern "C" void func_001D04E0(void* self, void* n);

struct Node_001D0A08 {
    char pad0[0xC];
    signed char m_C;
    char padD[0x1C - 0xD];
    Node_001D0A08* m_next;
};

struct Mgr_001D0A08 {
    char pad0[0x10];
    Node_001D0A08* m_head;
    void Flush(int all);
};

void Mgr_001D0A08::Flush(int all)
{
    Node_001D0A08* n = m_head->m_next;
    while (n != m_head) {
        Node_001D0A08* next = n->m_next;
        if (all || !n->m_C) {
            func_001D0460(this, n);
            next = n->m_next;
            func_001D04E0(this, n);
        }
        n = next;
    }
}
