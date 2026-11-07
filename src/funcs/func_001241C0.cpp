/* cflags: -O1 */
struct Node_001241C0 {
    char pad[0x60];
    Node_001241C0* m_next;
};

struct Owner_001241C0 {
    char pad[0x54];
    Node_001241C0* m_first;
    Node_001241C0* GetLast();
};

Node_001241C0* Owner_001241C0::GetLast()
{
    Node_001241C0* n = m_first;
    while (n && n->m_next)
        n = n->m_next;
    return n;
}
