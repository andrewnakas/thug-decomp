struct Node_002149A8 {
    int pad0;
    int m_pri;
    int pad8;
    Node_002149A8* m_next;
};

static inline Node_002149A8* Valid_002149A8(Node_002149A8* n)
{
    return (n->m_pri != -1) ? n : 0;
}

static inline unsigned int Count_002149A8(Node_002149A8* head)
{
    unsigned int n = 0;
    Node_002149A8* q;
    for (Node_002149A8* p = head->m_next; (q = Valid_002149A8(p)) != 0; p = q->m_next)
        n++;
    return n;
}

struct Game_002149A8 {
    char pad[0x30];
    Node_002149A8 m_skaters;
};

class SkaterBase_002149A8 {
public:
    char pad0[8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void Reset();
};

class Skater_002149A8 : public SkaterBase_002149A8 {
public:
    char padC[0x31C - 0xC];
    int m31C;
};

extern Game_002149A8* D_0038FC78;
extern char D_0038F598[];
extern "C" unsigned int func_001E87B8(void* params, char* name);
extern "C" Skater_002149A8* func_0022DE70(Game_002149A8* g, unsigned int i);
extern "C" void func_00185128(Skater_002149A8* s, unsigned int crc);

bool Cmd_002149A8(void* params, void* script)
{
    unsigned int crc = func_001E87B8(params, D_0038F598);
    Game_002149A8* g = D_0038FC78;
    unsigned int n = Count_002149A8(&g->m_skaters);
    for (unsigned int i = 0; i < n; i++) {
        Skater_002149A8* s = func_0022DE70(g, i);
        if (s && s->m31C) {
            s->Reset();
            func_00185128(s, crc);
        }
    }
    return true;
}
