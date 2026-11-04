struct Entry_002DB9A0 {
    char pad[0x68];
};

struct Table_002DB9A0 {
    unsigned int m0;
    unsigned int m4;
    char pad8[0x30 - 8];
    Entry_002DB9A0 e[1];
};

extern char D_0037CC68[];
extern char D_0037CC90[];
extern "C" int func_00332FB0(char* fmt, ...);

Entry_002DB9A0* func_002DB9A0(Table_002DB9A0* t)
{
    if (!t || !t->m0) {
        func_00332FB0(D_0037CC68);
        return 0;
    }
    if (t->m4 >= t->m0) {
        func_00332FB0(D_0037CC90, t->m4);
        return 0;
    }
    return &t->e[t->m4];
}
