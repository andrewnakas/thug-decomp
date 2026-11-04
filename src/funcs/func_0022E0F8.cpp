extern char D_00372BB8[];
extern void* D_00392068;
extern void* D_00389C34;

struct Node_0022E0F8 {
    int pad0;
    int m_pri;
    int pad8;
    Node_0022E0F8* m_next;
};

static inline Node_0022E0F8* Valid_0022E0F8(Node_0022E0F8* n)
{
    return (n->m_pri != -1) ? n : 0;
}

static inline unsigned int Count_0022E0F8(Node_0022E0F8* head)
{
    unsigned int n = 0;
    Node_0022E0F8* q;
    for (Node_0022E0F8* p = head->m_next; (q = Valid_0022E0F8(p)) != 0; p = q->m_next)
        n++;
    return n;
}

struct Skater_0022E0F8 {
    char pad[0xC];
    unsigned int m_flags;
    char pad10[0x30C];
    int m_local;
};

struct Game_0022E0F8 {
    char pad[0x28];
    void* m_28;
    char pad2C[4];
    Node_0022E0F8 m_skaters;
    char pad40[0x38];
    void* m_78;
    char pad7C[0x320];
    void* m_39C;
    void* m_3A0;
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" Skater_0022E0F8* func_0022DE70(Game_0022E0F8* g, unsigned int i);
extern "C" void func_00205B30(Skater_0022E0F8* s, int a, int b);
extern "C" void func_0025F460(void* a);
extern "C" void func_002057E8(Skater_0022E0F8* s);
extern "C" void func_00206968(Skater_0022E0F8* s);
extern "C" void* func_0022BFE0();
extern "C" void func_0022B940(void* a);
extern "C" void* func_0022E040(Game_0022E0F8* g);
extern "C" void func_00184D30();
extern "C" void func_00187900(void* a, void (*f)(), int b);
extern "C" void func_001876A8(void* a);
extern "C" void func_002069C0(Skater_0022E0F8* s);
extern "C" void func_002A84A0(void* net);
extern "C" void func_001F03D0();
extern "C" void func_00266100(void* a);
extern "C" void func_00141390();
extern "C" void func_002683E8(void* a);
extern "C" void func_0026B770();
extern "C" void func_0026C228();
extern "C" void func_00142878(void* a);

void func_0022E0F8(Game_0022E0F8* game)
{
    func_00103F28(D_00372BB8);
    unsigned int i;
    for (i = 0; i < Count_0022E0F8(&game->m_skaters); i++) {
        Skater_0022E0F8* s = func_0022DE70(game, i);
        if (s) {
            s->m_flags |= 2;
            if (s->m_local) {
                func_00205B30(s, 0, 1);
                func_0025F460(game->m_39C);
            }
            func_002057E8(s);
            func_00206968(s);
        }
    }
    func_0025F460(game->m_39C);
    func_0025F460(game->m_3A0);
    void* v = func_0022BFE0();
    if (v)
        func_0022B940(v);
    func_00187900(func_0022E040(game), func_00184D30, 0);
    func_001876A8(func_0022E040(game));
    for (i = 0; i < Count_0022E0F8(&game->m_skaters); i++) {
        Skater_0022E0F8* s = func_0022DE70(game, i);
        if (s) {
            s->m_flags &= ~2u;
            func_002069C0(s);
        }
    }
    func_002A84A0(D_00392068);
    func_001F03D0();
    func_00266100(game->m_78);
    func_00141390();
    func_002683E8(game->m_28);
    func_0026B770();
    func_0026C228();
    func_00142878(D_00389C34);
}
