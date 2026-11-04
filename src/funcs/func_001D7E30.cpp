struct Node_001D7E30 {
    unsigned char m_flags;
    char pad1[3];
    unsigned int m_link;
    bool IsLeaf() const { return (m_flags & 3) == 3; }
};

extern "C" Node_001D7E30* func_001DA7D8(unsigned int* link);
extern "C" Node_001D7E30* func_001DA820(unsigned int* link);

bool func_001D7E30(Node_001D7E30* n, unsigned int nodeBase, unsigned int leafBase)
{
    if (n->IsLeaf()) {
        n->m_link = leafBase + n->m_link * 2;
    } else {
        n->m_link = ((n->m_link & ~3) + nodeBase) | (n->m_link & 3);
        func_001D7E30(func_001DA7D8(&n->m_link), nodeBase, leafBase);
        func_001D7E30(func_001DA820(&n->m_link), nodeBase, leafBase);
    }
    return true;
}
