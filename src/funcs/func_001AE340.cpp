extern "C" void* func_001E9378(void* scr, int arg);

struct Script_001AE340 {
    int m_pad[3];
    int m_count;
};

extern "C" Script_001AE340* func_001E55B8(int id, int flags);

struct C_001AE340 {
    int m_pad[4];
    void Check(int id, int arg, unsigned int mask);
};

extern "C" int func_001ADE78(C_001AE340* self, void* p);
extern "C" int func_001AB648(C_001AE340* self, void* p);
extern "C" int func_001AB6E8(C_001AE340* self, void* p);
extern "C" int func_001AC030(C_001AE340* self, int a, int b, unsigned int c);
extern "C" void func_001ADD00(C_001AE340* self, int id, int i, int arg);

void C_001AE340::Check(int id, int arg, unsigned int mask)
{
    Script_001AE340* scr = func_001E55B8(id, 0);
    if (!scr) return;
    int n = scr->m_count;
    for (int i = 0; i < n; i++) {
        void* p = func_001E9378(scr, i);
        if (!func_001ADE78(this, p)) continue;
        int a = func_001AB648(this, p);
        int b = func_001AB6E8(this, p);
        unsigned int m = ~mask & 0xFFFFFFFB;
        if (func_001AC030(this, a, 1, m) || func_001AC030(this, b, 1, m)) {
            func_001ADD00(this, id, i, arg);
        }
    }
}
