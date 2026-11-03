struct Node_002506B8 {
    int m0;
    int m_key;
    int m8;
    Node_002506B8* m_next;
    Node_002506B8* Next() { return ~m_next->m_key ? m_next : 0; }
};

struct List_002506B8 {
    Node_002506B8 m_head;
    unsigned int Count()
    {
        unsigned int n = 0;
        Node_002506B8* p = m_head.Next();
        while (p) {
            n++;
            p = p->Next();
        }
        return n;
    }
};

struct Mgr_002506B8 {
    int m_pad[12];
    List_002506B8 m_list;
};

extern Mgr_002506B8* D_0038FC78;
extern "C" void* func_0022DE70(Mgr_002506B8* mgr, int index);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);

struct Ranker_002506B8 {
    bool IsBest(int index);
};

bool Ranker_002506B8::IsBest(int index)
{
    Mgr_002506B8* mgr = D_0038FC78;
    for (int i = 0; i < mgr->m_list.Count(); i++) {
        if (i == index)
            continue;
        void* mine = func_00203360(func_0022DE70(mgr, index));
        void* other = func_00203360(func_0022DE70(mgr, i));
        if (func_002392B8(mine) < func_002392B8(other))
            return false;
    }
    return true;
}
