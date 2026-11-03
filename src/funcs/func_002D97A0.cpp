struct Ent_002D97A0 {
    char pad[0x50];
};

struct Net_002D97A0 {
    char pad0[0x7C];
    Ent_002D97A0 m7C[5];
    char pad[0x20C - 0x7C - 5 * 0x50];
    int m20C;
};

struct Mgr_002D97A0 {
    char pad0[0x10];
    Net_002D97A0* m10;
};

extern Mgr_002D97A0* D_00392068;
extern char D_0037C828[];
extern char D_0037C848[];
extern char D_0037C868[];
extern char D_0037C888[];
extern char D_0037C8A8[];
extern char D_0037C8C0[];
extern "C" void func_002DB2B0(Ent_002D97A0* e);
extern "C" void* func_001E55F8(char* name, int v);
extern "C" void func_001E6518(void* p);
extern "C" void func_002E4550();

bool Cmd_002D97A0(void* params, void* script)
{
    Net_002D97A0* n = D_00392068->m10;
    if (n->m20C == 1) return true;
    {
        for (int i = 0; i < 5; i++) func_002DB2B0(&n->m7C[i]);
        n->m20C = 1;
        func_001E6518(func_001E55F8(D_0037C828, 0));
        func_001E6518(func_001E55F8(D_0037C848, 0));
        func_001E6518(func_001E55F8(D_0037C868, 0));
        func_001E6518(func_001E55F8(D_0037C888, 0));
        func_001E6518(func_001E55F8(D_0037C8A8, 0));
        func_001E6518(func_001E55F8(D_0037C8C0, 0));
        func_002E4550();
    }
    return true;
}
