struct Node_001D79C0 {
    unsigned char m_flags;
    char pad[3];
    unsigned int m4;
    bool IsBranch() const { return (m_flags & 3) != 3; }
};
extern "C" Node_001D79C0* func_001DA7D8(unsigned int* p);
extern "C" Node_001D79C0* func_001DA820(unsigned int* p);

extern "C" unsigned int func_001D79C0(Node_001D79C0* n)
{
    if (!n->IsBranch())
        return n->m4;
    unsigned int a = func_001D79C0(func_001DA7D8(&n->m4));
    unsigned int b = func_001D79C0(func_001DA820(&n->m4));
    return a < b ? a : b;
}
