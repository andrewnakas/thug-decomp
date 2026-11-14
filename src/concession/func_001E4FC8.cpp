/* force: {"kind": "lfr", "block": 0, "reg": 118, "hard": 3} */
struct Node_001E4FC8 {
    int m0;
    unsigned int m_id;
    int m8;
    int mC;
    Node_001E4FC8* m_next;
};

extern Node_001E4FC8* D_0038E47C;

extern "C" Node_001E4FC8* func_001E4FC8(unsigned int id)
{
    Node_001E4FC8* n = &D_0038E47C[id & 0xFFF];
    if (n->m_id == id)
        return n;
    n = n->m_next;
    while (n && n->m_id != id)
        n = n->m_next;
    return n;
}
