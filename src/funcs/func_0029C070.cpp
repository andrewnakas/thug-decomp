struct Grp_0029C070 {
    int m0;
    Grp_0029C070* next;
};

extern char D_003775C8[];
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);

struct Obj_0029C070 {
    char pad[0x24];
    Grp_0029C070* m24;
    Grp_0029C070* Find(int name);
};

Grp_0029C070* Obj_0029C070::Find(int name)
{
    int i = 0;
    for (Grp_0029C070* g = m24; g; g = g->next, i++) {
        char buf[64];
        func_003331D0(buf, D_003775C8, i);
        if (name == func_001F0D78(buf))
            return g;
    }
    return 0;
}
