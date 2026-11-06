/* fuzzy: 60.3 */
/* NM 31/34: game peels the first Valid() (movn form) before a movz loop; gcc here cross-jumps it into the loop (b into loop middle). Tried for/while/do, Valid ternary forms, Count()==0/<1/>0 */
struct Node_0021AD38 {
    int m0;
    int m_key;
    int m8;
    Node_0021AD38* m_next;
    Node_0021AD38* Valid()
    {
        if (m_key == -1)
            return 0;
        return this;
    }
};

struct Game_0021AD38 {
    char m_pad[0x3C];
    Node_0021AD38* m_head;
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_0021AD38* p = m_head->Valid(); p; p = p->m_next->Valid())
            n++;
        return n;
    }
};

extern Game_0021AD38* D_0038FC78;
extern "C" void* func_0022E3C8(Game_0021AD38* g, int i);
extern "C" void func_0022C6E0(Game_0021AD38* g, void* p, int a, int b, int c);

bool Cmd_0021AD38(void* params, void* script)
{
    Game_0021AD38* g = D_0038FC78;
    if (!g->Count())
        func_0022C6E0(D_0038FC78, func_0022E3C8(g, 0), 1, 0, 0);
    return true;
}
