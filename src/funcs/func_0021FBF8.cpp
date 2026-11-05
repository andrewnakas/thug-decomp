struct Node_0021FBF8 {
    int m0;
    int m_key;
    int m8;
    Node_0021FBF8* m_next;
    Node_0021FBF8* Valid()
    {
        if (m_key == -1)
            return 0;
        return this;
    }
};

struct Game_0021FBF8 {
    char m_pad[0x3C];
    Node_0021FBF8* m_head;
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_0021FBF8* p = m_head->Valid(); p; p = p->m_next->Valid())
            n++;
        return n;
    }
};

extern Game_0021FBF8* D_0038FC78;
extern "C" void* func_0022DE70(Game_0021FBF8* g, unsigned int i);
extern "C" void func_00206968(void* p);

bool Cmd_0021FBF8(void* params, void* script)
{
    for (unsigned int i = 0; i < D_0038FC78->Count(); i++)
        func_00206968(func_0022DE70(D_0038FC78, i));
    return true;
}
