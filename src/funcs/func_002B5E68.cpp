extern char D_00392460[];
extern char D_00379DD8[];
extern char D_00379DE8[];
extern char D_00392508[];
extern char D_00379E08[];
extern char D_00379E18[];
extern char D_00379E30[];
extern char D_00379E40[];

struct Elem_002B5E68 {
    char pad[0x18];
    char m18[0x28 - 0x18];
    int m28;
    int m2C;
    char pad30[4];
    int m34;
    int m38;
    int m3C;
    int m40;
    char pad44[0x98 - 0x44];
    int m98;
};

struct Mgr_002B5E68 {
    char pad[4];
    void* m4;
    char pad8[4];
    void* mC;
    char pad10[0x9C - 0x10];
    void* m9C;
};

extern Mgr_002B5E68* D_00392068;
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int flags);
extern "C" void func_002B3BE0(Mgr_002B5E68* m);
extern "C" Elem_002B5E68* func_002B5098(Mgr_002B5E68* s, int id);
extern "C" int func_002A18E0(Mgr_002B5E68* m);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001048F0(void* p);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_002D7EB8(void* p);
extern "C" void func_002D30B0(void* p, char* q);
extern "C" char* func_00327098(int v);
extern "C" int func_00100030(int n);
extern "C" void func_001E7A68(void* s, int name, int type, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_002B5E68(void* params)
{
    Mgr_002B5E68* mgr = D_00392068;
    bool over = false;
    int crc = 0;
    int id;
    func_001E8398(params, func_001F0D78(D_00392460), &id, 0);
    func_002B3BE0(mgr);
    Elem_002B5E68* e = func_002B5098(mgr, id);
    if (func_002A18E0(mgr) == 0) {
        if (!(e->m34 < e->m38)) {
            over = true;
            crc = func_001F0D78(D_00379DD8);
        }
    } else if (func_002A18E0(mgr) == 1) {
        if (!(e->m3C < e->m40)) {
            over = true;
            crc = func_001F0D78(D_00379DE8);
        }
    }
    if (over) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E73C8(s, D_00392508, crc);
        func_001E73C8(s, D_00379E08, 0);
        func_001048F0(mgr->m9C);
        func_001F0370(D_00379E18, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    } else {
        void* s = func_001E6978(func_001190D0(8));
        if (func_002D7EB8(mgr->mC))
            func_002D30B0(mgr->m4, e->m18);
        char* r = func_00327098(e->m28);
        if (e->m98 == 0)
            func_001E7A68(s, 0x751F4599, 13, func_00100030(0x7FFFFFFF));
        func_001E7A68(s, 0, 1, e->m2C);
        func_001E7A30(s, 0, 3, r);
        func_001E7268(s, D_00379E30, e->m38);
        func_001F0370(D_00379E40, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    }
    return true;
}
