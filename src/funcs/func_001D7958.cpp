struct Tree_001D7958 {
    unsigned char m_type;
    unsigned char m1;
    unsigned short m_count;
    char m_link[4];
    bool IsLeaf() const { return (m_type & 3) == 3; }
};

extern "C" Tree_001D7958* func_001DA7D8(void* link);
extern "C" Tree_001D7958* func_001DA820(void* link);

extern "C" int func_001D7958(Tree_001D7958* t)
{
    if (t->IsLeaf()) {
        return t->m_count;
    }
    return func_001D7958(func_001DA7D8(t->m_link)) + func_001D7958(func_001DA820(t->m_link));
}
