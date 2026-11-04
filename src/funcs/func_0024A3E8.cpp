struct Game_0024A3E8 {
    char pad0[0xA8];
    int m_cash;
};

extern char D_00373CD0[];
extern char D_00373CE8[];
extern char D_00390130[];
extern "C" void func_001F0370(char* name, void* params, int a, int b);
extern "C" void* func_00240850();
extern "C" void func_0023D608(void* a, int n);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E6AE8(void* p, int in_chrg);

int func_0024A3E8(Game_0024A3E8* g, int amount)
{
    int cash = g->m_cash;
    if (cash <= 0) {
        func_001F0370(D_00373CD0, 0, 0, 0);
        return 0;
    }
    if (cash < amount) amount = cash;
    void* s = func_00240850();
    if (s) {
    func_0023D608(s, amount);
    g->m_cash -= amount;
    void* p = func_001E6978(func_001190D0(8));
    func_001E7268(p, D_00390130, amount);
    func_001F0370(D_00373CE8, p, 0, 0);
    if (p) func_001E6AE8(p, 3);
    return 1;
    }
    return 0;
}
