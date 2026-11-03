struct Ent_002DBB78 {
    int m0;
    int m4;
    char m8[4];
};

struct Table_002DBB78 {
    int m0;
    char pad4[0x440 - 4];
};

struct Slot_002DBB78 {
    char pad[0x1340];
};

struct Mgr_002DBB78 {
    char pad0[0x9E00];
    Table_002DBB78 m9E00;
    Slot_002DBB78 mA240[8];
};

extern Mgr_002DBB78* D_00392068;
extern int D_00392F78;
extern char* D_00392F28;
extern char D_0037CDD0[];
extern "C" void func_00106B98(char* s, int a, int b, int c);
extern "C" int func_002DB820();
extern "C" int func_002DB8E8(char* name, Table_002DBB78* t);
extern "C" Ent_002DBB78* func_002DBA08(Table_002DBB78* t, int i);
extern "C" int func_002DBA70(char* name, char* name2, Slot_002DBB78* s);
extern "C" void func_002DBB48(Ent_002DBB78* e, Slot_002DBB78* s);

bool Sync_002DBB78()
{
    Mgr_002DBB78* m = D_00392068;
    if (!D_00392F78) {
        func_00106B98(D_0037CDD0, 0, 0, 1);
        func_002DB820();
    }
    if (func_002DB8E8(D_00392F28, &m->m9E00) < 0)
        return false;
    for (int i = 0; i < m->m9E00.m0; i++) {
        Ent_002DBB78* e = func_002DBA08(&m->m9E00, i + 1);
        if (e && e->m0 && e->m4) {
            Slot_002DBB78* s = &m->mA240[i];
            func_002DBA70(D_00392F28, e->m8, s);
            func_002DBB48(e, s);
        }
    }
    return true;
}
