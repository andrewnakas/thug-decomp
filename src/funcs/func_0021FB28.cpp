struct Node_0021FB28 {
    int pad0;
    int m_pri;
    int pad8;
    Node_0021FB28* m_next;
};

static inline Node_0021FB28* Valid_0021FB28(Node_0021FB28* n)
{
    return (n->m_pri != -1) ? n : 0;
}

static inline unsigned int Count_0021FB28(Node_0021FB28* head)
{
    unsigned int n = 0;
    Node_0021FB28* p = Valid_0021FB28(head->m_next);
    while (p) {
        p = Valid_0021FB28(p->m_next);
        n++;
    }
    return n;
}

struct Game_0021FB28 {
    char pad[0x30];
    Node_0021FB28 m_skaters;
};

struct Pool_0021FB28 {
    char pad[0x148];
    void* m_heaps[1];
};

extern Game_0021FB28* D_0038FC78;
extern Pool_0021FB28* D_00388A70;
extern "C" void* func_0022DE70(Game_0021FB28* g, unsigned int i);
extern "C" int func_002041F8(void* s);
extern "C" void func_0010A950(Pool_0021FB28* pool, void* heap);
extern "C" void func_002069C0(void* s);
extern "C" void func_0010A9B0(Pool_0021FB28* pool);

bool Cmd_0021FB28(void* params, void* script)
{
    for (unsigned int i = 0; i < Count_0021FB28(&D_0038FC78->m_skaters); i++) {
        void* s = func_0022DE70(D_0038FC78, i);
        Pool_0021FB28* pool = D_00388A70;
        func_0010A950(pool, pool->m_heaps[func_002041F8(s)]);
        func_002069C0(s);
        func_0010A9B0(D_00388A70);
    }
    return true;
}
