extern char D_00392F98[];
extern char D_00392FA0[];
extern char D_00392FA8[];
extern char D_00392FB0[];
extern char D_00392FB8[];
extern char D_00392FC0[];
extern char D_00392FC8[];
extern char D_0037CE88[];
extern char D_0037CE98[];
extern char D_0037CEB0[];
extern char D_0037CEC0[];
extern char D_0037CED0[];
extern char D_0037CEE0[];
extern char D_0037CEF8[];
extern char D_0037CF08[];
extern char D_0037CF18[];
extern char D_0037CF28[];
extern char D_0037CF38[];
extern char D_0037CF48[];
extern char D_0037CF58[];
extern char D_0037CF68[];
extern char D_0037CF78[];
extern char D_0037CF88[];
extern char D_0037CF98[];
extern char D_0037CFA8[];
extern char D_0037CFD0[];
extern char D_0037CFE8[];
extern char D_0037CFF8[];
extern char D_0037D010[];
extern char D_0037D020[];
extern char D_0037D030[];
extern char D_0037D040[];
extern char D_0037D050[];
extern char D_0037D068[];
extern char D_0037D078[];
extern char D_0037D0A8[];
extern char D_0037D0C8[];
extern char D_0037D0E8[];

struct Ent_002DBED8 {
    int m0;
    int m4;
    char pad8[0x28 - 8];
    char name[1];
};

struct List_002DBED8 {
    int count;
};

struct Rec_002DBED8 {
    char pad0[0x200];
    char m200[0x100];
    char m300[0x100];
    char m400[0x100];
    char m500[0x100];
    char m600[0x100];
    char m700[0x100];
    char m800[0x100];
    char m900[0x100];
    char mA00[0x100];
    char mB00[0x100];
    char mC00[0x100];
    char padD00[0x1100 - 0xD00];
    char m1100[0x100];
    char m1200[0x140];
};

struct Mgr_002DBED8 {
    char pad[0x9E00];
    List_002DBED8 list;
    char pad9E04[0xA240 - 0x9E04];
    Rec_002DBED8 recs[4];
};

extern Mgr_002DBED8* D_00392068;

extern "C" void* func_002A6070(void* m);
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" bool func_001E7D18(void* params, char* name, char** out, int required);
extern "C" Ent_002DBED8* func_002DBA08(List_002DBED8* l, int n);
extern "C" int func_00331950(char* a, char* b);
extern "C" int func_00331BB8(const char* s);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, const char* value);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void func_00203068(void* goals, unsigned int name, void* params);
extern "C" void func_001E6AE8(void* p, int flags);

bool Cmd_002DBED8(void* params, void* script)
{
    Mgr_002DBED8* mgr = D_00392068;
    Rec_002DBED8* rec = 0;
    Ent_002DBED8* e = 0;
    void* goals = func_002A6070(mgr);
    int idx;
    void* p;
    if (func_001E88F8(params, D_00392F98, &idx, 0)) {
        rec = &mgr->recs[idx];
        e = func_002DBA08(&mgr->list, idx + 1);
    } else {
        char* name;
        int found = 0;
        func_001E7D18(params, D_00392FA0, &name, 1);
        for (int i = 0; i < mgr->list.count; i++) {
            e = func_002DBA08(&mgr->list, i + 1);
            if (e && e->m0 && !func_00331950(e->name, name) && e->m4) {
                idx = i;
                found = 1;
                rec = &mgr->recs[i];
                break;
            }
        }
        if (!found) {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, func_001E54B8(D_0037CE98, 0));
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037CEC0));
            func_00203068(goals, func_001F0D78(D_0037CED0), p);
            if (p)
                func_001E6AE8(p, 3);
            func_001F0370(D_0037CEE0, 0, 0, 0);
            return false;
        }
    }
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, e->name);
    func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037CEF8));
    func_00203068(goals, func_001F0D78(D_0037CED0), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->m300);
    func_00203068(goals, func_001F0D78(D_0037CF08), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->m400);
    func_00203068(goals, func_001F0D78(D_0037CF18), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->m500);
    func_00203068(goals, func_001F0D78(D_00392FA8), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->m600);
    func_00203068(goals, func_001F0D78(D_0037CF28), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->m700);
    func_00203068(goals, func_001F0D78(D_0037CF38), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->m200);
    func_00203068(goals, func_001F0D78(D_0037CF48), p);
    if (p)
        func_001E6AE8(p, 3);
    char buf0[64];
    char buf1[128];
    func_003331D0(buf0, D_00392FB0, rec->m1100, rec->m1200);
    func_003331D0(buf1, D_00392FB0, buf0, rec->m800);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, buf1);
    func_00203068(goals, func_001F0D78(D_0037CF58), p);
    if (p)
        func_001E6AE8(p, 3);
    func_003331D0(buf1, D_00392FB0, buf0, rec->m900);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, buf1);
    func_00203068(goals, func_001F0D78(D_0037CF68), p);
    if (p)
        func_001E6AE8(p, 3);
    func_003331D0(buf1, D_00392FB0, buf0, rec->mA00);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, buf1);
    func_00203068(goals, func_001F0D78(D_0037CF78), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->mB00);
    func_00203068(goals, func_001F0D78(D_0037CF88), p);
    if (p)
        func_001E6AE8(p, 3);
    p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0037CE88), 3, rec->mC00);
    func_00203068(goals, func_001F0D78(D_0037CF98), p);
    if (p)
        func_001E6AE8(p, 3);
    int has = 0;
    if (func_00331BB8(rec->m600) || func_00331BB8(rec->m700))
        has = 1;
    switch (e->m4) {
    case 1:
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_0037CFA8);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037CFD0));
        func_00203068(goals, func_001F0D78(D_0037CFE8), p);
        if (p)
            func_001E6AE8(p, 3);
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_0037CFF8);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D010));
        func_00203068(goals, func_001F0D78(D_0037D020), p);
        if (p)
            func_001E6AE8(p, 3);
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FB8);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D030));
        func_00203068(goals, func_001F0D78(D_0037D040), p);
        if (p)
            func_001E6AE8(p, 3);
        break;
    case 2:
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_0037CFA8);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037CFD0));
        func_00203068(goals, func_001F0D78(D_0037CFE8), p);
        if (p)
            func_001E6AE8(p, 3);
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_0037D050);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_00392FC0));
        func_00203068(goals, func_001F0D78(D_0037D020), p);
        if (p)
            func_001E6AE8(p, 3);
        if (has) {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FB8);
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D030));
            func_00203068(goals, func_001F0D78(D_0037D040), p);
            if (p)
                func_001E6AE8(p, 3);
        } else {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FC8);
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D068));
            func_00203068(goals, func_001F0D78(D_0037D040), p);
            if (p)
                func_001E6AE8(p, 3);
        }
        break;
    case 3:
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_0037D078);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D0A8));
        func_00203068(goals, func_001F0D78(D_0037CFE8), p);
        if (p)
            func_001E6AE8(p, 3);
        if (has) {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FB8);
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D030));
            func_00203068(goals, func_001F0D78(D_0037D040), p);
            if (p)
                func_001E6AE8(p, 3);
        } else {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FC8);
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D068));
            func_00203068(goals, func_001F0D78(D_0037D040), p);
            if (p)
                func_001E6AE8(p, 3);
        }
        break;
    case 4:
    case 5:
        p = func_001E6978(func_001190D0(8));
        func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_0037D0C8);
        func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D0E8));
        func_00203068(goals, func_001F0D78(D_0037CFE8), p);
        if (p)
            func_001E6AE8(p, 3);
        if (has) {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FB8);
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D030));
            func_00203068(goals, func_001F0D78(D_0037D040), p);
            if (p)
                func_001E6AE8(p, 3);
        } else {
            p = func_001E6978(func_001190D0(8));
            func_001E7A30(p, func_001F0D78(D_0037CE88), 3, D_00392FC8);
            func_001E7A68(p, func_001F0D78(D_0037CEB0), 13, func_001F0D78(D_0037D068));
            func_00203068(goals, func_001F0D78(D_0037D040), p);
            if (p)
                func_001E6AE8(p, 3);
        }
        break;
    }
    return true;
}
