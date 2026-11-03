struct Node {
    char pad[0x18];
    Node* m_next;
    Node* m_prev;
    void Unlink();
};

void Node::Unlink()
{
    m_prev->m_next = m_next;
    m_next->m_prev = m_prev;
    m_next = this;
    m_prev = this;
}
