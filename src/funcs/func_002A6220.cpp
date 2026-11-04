extern char D_00378610[];
extern char D_00378628[];
extern char D_00378260[];
extern char D_00378648[];
extern char D_00378658[];
extern char D_00378668[];
extern char D_00378678[];
extern char D_00378688[];
extern char D_00378698[];
extern char D_003786A8[];
extern char D_003786B8[];
extern char D_003786C8[];
extern char D_003786D8[];
extern char D_003786E8[];
extern char D_003786F8[];
extern char D_00378708[];
extern char D_00378718[];
extern char D_00378728[];
extern char D_00378738[];
extern char D_00378748[];
extern char D_00378758[];
extern char D_00378768[];
extern char D_00378778[];
extern char D_00378788[];
extern char D_003787A0[];
extern char D_003787C0[];
extern char D_003787D8[];
extern char D_003787F0[];
extern char D_00378810[];
extern char D_00378828[];
extern char D_00378840[];
extern char D_00378860[];
extern char D_00378318[];
extern char D_00392120[];
extern char D_00392140[];
extern char D_00392148[];
extern char D_00392150[];
extern char D_00392158[];

struct Arr_002A6220 {
    char pad[0xC];
    int mC;
};

extern void* D_0038EB78;

extern "C" void* func_002A6070(void* m);
extern "C" Arr_002A6220* func_001E55F8(const char* name, int a);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8A50(void* params, const char* name, int* out, int required);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8890(void* params, const char* name, char** out, int required);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_00331950(char* a, char* b);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_00203068(void* p, int name, void* s);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001FA470(void* m, int v);
extern "C" void func_001FA500(void* m, char* s);
extern "C" void func_001FA528(void* m, char* s);
extern "C" void func_001FA350(void* m, char* s);
extern "C" void func_001FA288(void* m, char* s);
extern "C" void func_001FA2E8(void* m, char* s);
extern "C" void func_001FA498(void* m, int i, char* s);
extern "C" void func_001FA228(void* m, char* s);
extern "C" void func_001FA248(void* m, char* s);
extern "C" void func_001FA268(void* m, char* s);
extern "C" void func_001FA448(void* m, int v);
extern "C" void func_001FA3B0(void* m, int v);
extern "C" void func_001FA490(void* m, int v);
extern "C" int func_002A1B30(void* m);
extern "C" void func_002A1EF8(void* m, int v);
extern "C" void func_002A2148(void* m, int v);

struct Obj_002A6220 {
    char pad[0x9934];
    char mNames[10][16];
    void Load();
};

void Obj_002A6220::Load()
{
    int crc;
    char* str;
    int crc2;
    char* sa;
    char* sb;
    char* s1;
    char* s2;
    char* s3;
    int crc3;
    void* mgr = D_0038EB78;
    int i;
    int n;
    for (i = 0; i < 10; i++)
        mNames[i][0] = 0;
    void* cfg = func_002A6070(this);
    Arr_002A6220* arr = func_001E55F8(D_00378610, 0);
    func_001E8A50(func_00202EF8(cfg, func_001F0D78(D_00378628)), D_00378260, &crc, 1);
    if (crc == func_001F0D78(D_00378648)) {
        for (i = 0; i < arr->mC; i++) {
            func_001E8890(func_001E9378(arr, i), D_00392120, &str, 1);
            func_00331A9C(mNames[i], str);
        }
    } else {
        n = 0;
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378658)), D_00378318, &str, 1);
        if (func_00331950(str, D_00392140)) {
            n = 1;
            func_00331A9C(mNames[0], str);
        }
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378668)), D_00378318, &str, 1);
        if (func_00331950(str, D_00392140)) {
            func_00331A9C(mNames[n], str);
            n++;
        }
        for (i = 0; i < arr->mC; i++) {
            func_001E8890(func_001E9378(arr, i), D_00392120, &str, 1);
            func_00331A9C(mNames[n + i], str);
        }
    }
    func_001E8A50(func_00202EF8(cfg, func_001F0D78(D_00378678)), D_00378260, &crc2, 1);
    int flag = crc2 == func_001F0D78(D_00392148);
    char* name1 = func_001E54B8(D_00378688, 0);
    char* name2 = func_001E54B8(D_00378698, 0);
    if (name1 && !*name1)
        name1 = 0;
    if (name1) {
        flag = 0;
        void* s = func_001E6978(func_001190D0(8));
        func_001E7A30(s, func_001F0D78(D_00378318), 3, name1);
        func_00203068(func_002A6070(this), func_001F0D78(D_003786A8), s);
        if (s)
            func_001E6AE8(s, 3);
        if (name2 && *name2) {
            void* t = func_001E6978(func_001190D0(8));
            func_001E7A30(t, func_001F0D78(D_00378318), 3, name2);
            func_00203068(func_002A6070(this), func_001F0D78(D_00392150), t);
            if (t)
                func_001E6AE8(t, 3);
        }
    }
    func_001FA470(mgr, flag);
    if (flag) {
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_003786B8)), D_00378318, &sa, 1);
        func_001FA500(mgr, sa);
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_003786C8)), D_00378318, &sb, 1);
        func_001FA528(mgr, sb);
    } else {
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_003786A8)), D_00378318, &str, 1);
        func_001FA350(mgr, str);
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00392150)), D_00378318, &str, 1);
        func_001FA288(mgr, str);
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_003786D8)), D_00378318, &str, 1);
        func_001FA2E8(mgr, str);
    }
    func_001E8A50(func_00202EF8(cfg, func_001F0D78(D_003786E8)), D_00378260, &crc, 1);
    if (crc == func_001F0D78(D_00378648) && !name1) {
        func_001FA498(mgr, 0, D_00392158);
        func_001FA498(mgr, 1, D_00392158);
        func_001FA498(mgr, 2, D_00392158);
    } else if (name1) {
        func_001FA498(mgr, 0, D_003786F8);
        func_001FA498(mgr, 1, D_00378708);
    } else {
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378718)), D_00378318, &str, 1);
        func_001FA498(mgr, 0, str);
        func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378728)), D_00378318, &str, 1);
        func_001FA498(mgr, 1, str);
    }
    func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378738)), D_00378318, &s1, 1);
    func_001FA228(mgr, s1);
    func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378748)), D_00378318, &s2, 1);
    func_001FA248(mgr, s2);
    func_001E8890(func_00202EF8(cfg, func_001F0D78(D_00378758)), D_00378318, &s3, 1);
    func_001FA268(mgr, s3);
    func_001E8A50(func_00202EF8(cfg, func_001F0D78(D_00378768)), D_00378260, &crc3, 1);
    int dbg = *func_001E54B8(D_00378778, 0) != 0;
    if (crc3 == func_001F0D78(D_00378788) || dbg) {
        if (name1)
            func_001F0370(D_003787A0, 0, 0, 0);
        func_001FA448(mgr, 3);
        func_001FA3B0(mgr, 2);
    } else if (crc3 == func_001F0D78(D_003787C0) || name1) {
        if (name1)
            func_001F0370(D_003787D8, 0, 0, 0);
        func_001FA448(mgr, 1);
        func_001FA3B0(mgr, 2);
    } else if (crc3 == func_001F0D78(D_003787F0)) {
        func_001FA448(mgr, 1);
        func_001FA3B0(mgr, 3);
    } else if (crc3 == func_001F0D78(D_00378810)) {
        func_001FA448(mgr, 2);
        func_001FA3B0(mgr, 1);
        if (func_002A1B30(this) >= 4)
            func_002A1EF8(this, 3);
        func_002A2148(this, 0);
    } else if (crc3 == func_001F0D78(D_00378828)) {
        func_001FA448(mgr, 4);
        func_001FA3B0(mgr, 1);
        if (func_002A1B30(this) >= 4)
            func_002A1EF8(this, 3);
        func_002A2148(this, 0);
    } else if (crc3 == func_001F0D78(D_00378840)) {
        func_001FA448(mgr, 3);
        func_001FA3B0(mgr, 3);
    } else {
        func_001FA3B0(mgr, 0);
        func_001FA448(mgr, 0);
    }
    func_001E8A50(func_00202EF8(cfg, func_001F0D78(D_00378860)), D_00378260, &crc, 1);
    func_001FA490(mgr, crc == func_001F0D78(D_00378648));
}
