struct Node_001E6B90 {
    int m0;
    int m_key;
    int m8;
    Node_001E6B90* m_next;
};

extern "C" void func_001E6250(Node_001E6B90* n);
extern "C" void func_001E8D20(Node_001E6B90* n);

struct List_001E6B90 {
    int m0;
    Node_001E6B90* m_head;
    void Remove(int key);
};

void List_001E6B90::Remove(int key)
{
    Node_001E6B90* prev = 0;
    Node_001E6B90* n = m_head;
    Node_001E6B90* next;
    if (n) do {
        next = n->m_next;
        if (n->m_key == key) {
            if (prev)
                prev->m_next = next;
            else
                m_head = next;
            func_001E6250(n);
            func_001E8D20(n);
        } else {
            prev = n;
        }
        n = next;
    } while (next);
}
