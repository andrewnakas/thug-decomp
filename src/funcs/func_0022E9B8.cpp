extern char D_00372D00[];
extern char D_00372D28[];
extern char D_00372D40[];
extern char D_00372D58[];
extern char D_00372D70[];
extern char D_003729D0[];
extern char D_00371C78[];
extern void* D_00392068;
extern void* D_00390828;

struct Heap_0022E9B8 {
    char pad[0xDC];
    void* m_DC;
};

extern Heap_0022E9B8* D_00388A70;

struct Node_0022E9B8 {
    int pad0;
    int m_pri;
    int pad8;
    Node_0022E9B8* m_next;
};

static inline Node_0022E9B8* Valid_0022E9B8(Node_0022E9B8* n)
{
    return (n->m_pri != -1) ? n : 0;
}

static inline unsigned int Count_0022E9B8(Node_0022E9B8* head)
{
    unsigned int n = 0;
    Node_0022E9B8* q;
    for (Node_0022E9B8* p = head->m_next; (q = Valid_0022E9B8(p)) != 0; p = q->m_next)
        n++;
    return n;
}

struct Iter_0022E9B8 {
    int m_0;
    int m_4;
    void* m_vtbl;
};

struct Game_0022E9B8 {
    char pad[0x30];
    Node_0022E9B8 m_skaters;
    char pad40[0x20];
    int m_60;
    char pad64[0x358];
    void* m_3BC;
};

extern "C" void func_00253F60(void* a, int b);
extern "C" void func_0010A950(Heap_0022E9B8* heap, void* a);
extern "C" void func_0010A9B0(Heap_0022E9B8* heap);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" bool func_002A56E0(void* net);
extern "C" void* func_0022E358(Game_0022E9B8* g);
extern "C" unsigned int func_0024F750(void* a);
extern "C" void func_0010B768(Heap_0022E9B8* heap, unsigned int n);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_0024FDF8(void* a, unsigned int key);
extern "C" void func_0024FEC8(void* a);
extern "C" void func_0022E850(Game_0022E9B8* g);
extern "C" void* func_002A5820(void* net);
extern "C" void func_002B2BC0(void* p, int a);
extern "C" void* func_002A53F8(void* net, Iter_0022E9B8* it, int a);
extern "C" void* func_002A5490(void* net, Iter_0022E9B8* it, int a);
extern "C" void func_002B2310(void* p);
extern "C" unsigned int func_0024F938(void* a);
extern "C" unsigned int func_0024F590(void* a);
extern "C" void func_002A1C50(void* net, unsigned int a);

void func_0022E9B8(Game_0022E9B8* game)
{
    void* net = D_00392068;
    func_00253F60(D_00390828, 0);
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    func_00103F28(D_00372D00, Count_0022E9B8(&game->m_skaters));
    if (!func_002A56E0(net)) {
        if (func_0024F750(func_0022E358(game)) >= 2) {
            Heap_0022E9B8* heap = D_00388A70;
            func_0010B768(heap, func_0024F750(func_0022E358(game)));
        }
        func_0024FDF8(game->m_3BC, func_001F0D78(D_00372D28));
        func_0024FEC8(game->m_3BC);
        func_00103F28(D_00372D40);
    } else {
        func_0022E850(game);
        game->m_60 = 1;
        func_0024FDF8(game->m_3BC, func_001F0D78(D_00372D58));
        func_00103F28(D_00372D70);
    }
    Iter_0022E9B8 it;
    it.m_4 = 0;
    it.m_vtbl = D_00371C78;
    void* host = func_002A5820(net);
    if (host)
        func_002B2BC0(host, 0);
    for (void* p = func_002A53F8(net, &it, 1); p; p = func_002A5490(net, &it, 1))
        func_002B2310(p);
    if (func_0024F938(func_0022E358(game)) == func_001F0D78(D_003729D0))
        func_002A1C50(net, func_0024F590(func_0022E358(game)));
    func_0010A9B0(D_00388A70);
    it.m_vtbl = D_00371C78;
}
