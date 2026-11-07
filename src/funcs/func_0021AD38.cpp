struct Node_0021AD38 {
    int m0;
    int m_key;
    int m8;
    Node_0021AD38* m_next;
};

static inline Node_0021AD38* Valid_0021AD38(Node_0021AD38* n)
{
    Node_0021AD38* r = 0;
    if (n->m_key != -1) r = n;
    return r;
}

static inline Node_0021AD38* Next_0021AD38(Node_0021AD38* n)
{
    Node_0021AD38* r = n->m_next;
    if (r->m_key == -1) r = 0;
    return r;
}

struct Game_0021AD38 {
    char m_pad[0x3C];
    Node_0021AD38* m_head;
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_0021AD38* p = Valid_0021AD38(m_head); p; p = Next_0021AD38(p))
            n++;
        return n;
    }
};

extern Game_0021AD38* D_0038FC78;
extern "C" void* func_0022E3C8(Game_0021AD38* g, int i);
extern "C" void func_0022C6E0(Game_0021AD38* g, void* p, int a, int b, int c);

bool Cmd_0021AD38(void* params, void* script)
{
    if (!D_0038FC78->Count()) {
        Game_0021AD38* g = D_0038FC78;
        func_0022C6E0(D_0038FC78, func_0022E3C8(g, 0), 1, 0, 0);
    }
    return true;
}
