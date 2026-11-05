struct Entry_002DBA08 {
    char pad[0x68];
};

struct Table_002DBA08 {
    int m0;
    char pad4[0x30 - 4];
    Entry_002DBA08 e[1];
};

extern char D_0037CCC0[];
extern char D_0037CCE8[];
extern "C" int func_00332FB0(char* fmt, ...);

Entry_002DBA08* func_002DBA08(Table_002DBA08* t, int i)
{
    if (!t || !t->m0) {
        func_00332FB0(D_0037CCC0);
        return 0;
    }
    if (i <= 0 || t->m0 < i) {
        func_00332FB0(D_0037CCE8, i);
        return 0;
    }
    return &t->e[i - 1];
}
