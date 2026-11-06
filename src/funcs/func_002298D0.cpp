struct Node_002298D0 {
    unsigned short m_value;
    Node_002298D0* m_next;
};

struct Slot_002298D0 {
    void* m_ptr;
    int m_key;
};

extern unsigned short D_00416FC8[];
extern Slot_002298D0 D_003FD98C[];
extern unsigned int D_0038FB68;
extern int D_0038FB6C;

void Pack_002298D0()
{
    unsigned short* dst = D_00416FC8;
    for (unsigned int i = 0; i < D_0038FB68; i++) {
        Node_002298D0* head = (Node_002298D0*)D_003FD98C[i].m_ptr;
        int count = 0;
        Node_002298D0* n = head;
        while (n) {
            count++;
            n = n->m_next;
        }
        D_003FD98C[i].m_ptr = dst;
        *dst = count;
        dst++;
        n = head;
        while (n) {
            *dst = n->m_value;
            dst++;
            n = n->m_next;
        }
        D_0038FB6C++;
        D_0038FB6C += count;
    }
}
