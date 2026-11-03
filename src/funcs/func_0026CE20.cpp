struct Heap_0026CE20 {
    char m_pad[0xEC];
    int mEC;
};
extern Heap_0026CE20* D_00388A70;

struct Gap_0026CE20 {
    int m0;
    int m4;
    int m8;
    Gap_0026CE20* mC;
    Gap_0026CE20* m10;
    char m14[0x34];
    int m48;
};

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_001046B0(int size);
extern "C" Gap_0026CE20* func_0026CB10(void* p);
extern "C" void func_0026CBA8(Gap_0026CE20* g);
extern "C" void func_0026CBD0(Gap_0026CE20* g, char* name);
extern "C" void func_0026CC08(Gap_0026CE20* g, int a);
extern "C" void func_0026CC10(Gap_0026CE20* g, int a);
extern "C" char* func_0026CBB0(Gap_0026CE20* g);
extern "C" int func_00331950(char* a, char* b);
extern "C" int func_00104610(char* a, char* b);

static inline Gap_0026CE20* Valid_0026CE20(Gap_0026CE20* n)
{
    Gap_0026CE20* g = 0;
    if (n->m4 != -1)
        g = n;
    return g;
}

struct Level_0026CE20 {
    int m0;
    Gap_0026CE20 m4;
    void AddGap(char* name, int flags, int score);
};

void Level_0026CE20::AddGap(char* name, int flags, int score)
{
    Gap_0026CE20* after = 0;
    m0 = 1;
    for (Gap_0026CE20* g = Valid_0026CE20(m4.mC); g; g = Valid_0026CE20(g->mC)) {
        if (!func_00331950(func_0026CBB0(g), name) && g->m48 == score) {
            func_0026CC10(g, 1);
            return;
        }
        if (g->m48 < score)
            after = g;
        else if (g->m48 == score) {
            if (func_00104610(func_0026CBB0(g), name) < 0)
                after = g;
        }
    }
    func_0010A950(D_00388A70, D_00388A70->mEC);
    Gap_0026CE20* n = func_0026CB10(func_001046B0(0x60));
    func_0026CBA8(n);
    func_0026CBD0(n, name);
    func_0026CC08(n, flags);
    n->m48 = score;
    if (after) {
        n->m10 = after;
        n->mC = after->mC;
        after->mC->m10 = n;
        after->mC = n;
    } else {
        Gap_0026CE20* h = &m4;
        n->m10 = h;
        n->mC = h->mC;
        h->mC->m10 = n;
        h->mC = n;
    }
    func_0010A9B0(D_00388A70);
}
