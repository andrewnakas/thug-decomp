struct Pool_002DBCE8 {
    char pad[0xE4];
    int mE4;
};

struct Ent_002DBCE8 {
    int m0;
    int m4;
    char pad8[0x28 - 8];
    char m28[0x20];
};

struct List_002DBCE8 {
    int m0;
};

struct Glob_002DBCE8 {
    char pad[0x9E00];
    List_002DBCE8 m9E00;
};

extern Glob_002DBCE8* D_00392068;
extern Pool_002DBCE8* D_00388A70;
extern char D_00392F80[];
extern char D_00392F88[];
extern char D_00392F90[];
extern char D_00392F98[];
extern char D_0037CDE0[];
extern char D_0037CDF0[];
extern char D_0037CE08[];
extern char D_0037CE20[];
extern char D_0037CE30[];
extern char D_0037CE58[];
extern char D_0037CE70[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" Ent_002DBCE8* func_002DBA08(List_002DBCE8* l, int i);
extern "C" int func_003331D0(char* d, const char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7860(void* p, char* name, void* s);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

bool func_002DBCE8(void* params, void* script)
{
    Glob_002DBCE8* g = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->mE4);
    for (int i = 0; i < g->m9E00.m0; i++) {
        Ent_002DBCE8* e = func_002DBA08(&g->m9E00, i + 1);
        if (e && e->m0 && e->m4) {
            char buf[0x40];
            func_003331D0(buf, D_00392F80, e->m28);
            void* s = func_001E6978(func_001190D0(8));
            func_001E7138(s, D_00392F88, buf);
            func_001E73C8(s, D_00392F90, func_001F0D78(D_0037CDE0) + i);
            func_001E73C8(s, D_0037CDF0, func_001F0D78(D_0037CE08));
            func_001E73C8(s, D_0037CE20, func_001F0D78(D_0037CE30));
            void* t = func_001E6978(func_001190D0(8));
            func_001E7268(t, D_00392F98, i);
            func_001E7860(s, D_0037CE58, t);
            func_001F0370(D_0037CE70, s, 0, 0);
            if (s) func_001E6AE8(s, 3);
            if (t) func_001E6AE8(t, 3);
        }
    }
    func_0010A9B0(D_00388A70);
    return true;
}
