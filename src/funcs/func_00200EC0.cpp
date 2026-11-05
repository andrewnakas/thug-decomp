struct Node_00200EC0 {
    int m0;
    int m4;
    int m8;
    Node_00200EC0* m_next;
    Node_00200EC0* Valid() { return (m4 != -1) ? this : 0; }
    int GetData() { return m4; }
};

struct Iter_00200EC0 {
    int m0;
    Node_00200EC0* cur;
    int Next()
    {
        cur = cur->m_next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    int First(Node_00200EC0* h)
    {
        cur = h;
        return Next();
    }
};

struct Mgr_00200EC0 {
    char pad[0x42D8];
    Node_00200EC0 m_list;
    int First(Iter_00200EC0* it);
};

int Mgr_00200EC0::First(Iter_00200EC0* it)
{
    return it->First(&m_list);
}
