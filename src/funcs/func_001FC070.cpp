class Node_001FC070 {
public:
    int m0;
    int m4;
    int m8;
    Node_001FC070* m_next;
    int m10;
    virtual ~Node_001FC070() = 0;
    virtual void V1();
    Node_001FC070* Valid() { return (m4 != -1) ? this : 0; }
};

void func_001FC070(Node_001FC070* table)
{
    for (int i = 0; i < 0xFF; i++) {
        Node_001FC070* n = table[i].m_next->Valid();
        while (n) {
            Node_001FC070* next = n->m_next->Valid();
            delete n;
            n = next;
        }
    }
}
