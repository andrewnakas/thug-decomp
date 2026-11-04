struct ListNode {
    char pad[0x10];
    ListNode* m_next;
};

struct ListOwner {
    int m0;
    int m4;
    ListNode* m_head;
    bool HasItems() const;
};

bool ListOwner::HasItems() const
{
    return m_head->m_next != m_head;
}
