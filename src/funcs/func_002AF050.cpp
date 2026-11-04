extern char D_00371C78[];

struct Iter_002AF050 {
    int m0;
    int m4;
    void* m8;
    Iter_002AF050() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AF050() { m8 = D_00371C78; }
};

struct Arr_002AF050 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Pool_002AF050 {
    char pad[0x3EC];
    int m3EC;
};

struct Info_002AF050 {
    unsigned long m0;
    long m8;
    int m10;
    char pad14[4];
    int m18;
    char pad1C[4];
    signed char m20;
    unsigned char m21;
    char pad22[2];
    int m24;
    signed char m28;
    char pad29[3];
    char m2C[4];
};

struct Item_002AF050 {
    char pad[0x18];
    int m18;
};

struct Scr_002AF050 {
    char pad[0x1C];
    void* m1C;
};

struct Mgr_002AF050 {
    char pad0[0x30];
    int m30;
    int m34;
    char pad38[0x70 - 0x38];
    int m70;
    char pad74[0x18C - 0x74];
    int m18C;
    int m190;
};

extern Pool_002AF050* D_00388A70;
extern void* D_0038FC78;
extern char D_00379020[];
extern char D_00379050[];
extern char D_00379358[];
extern char D_00379370[];
extern char D_00379380[];
extern char D_00379398[];
extern char D_003793B0[];
extern char D_003793C8[];
extern char D_003793E0[];
extern char D_003793F8[];
extern char D_00392270[];
extern char D_00392290[];
extern char D_003922B8[];
extern "C" void func_0010A950(Pool_002AF050* p, int v);
extern "C" void func_0010A9B0(Pool_002AF050* p);
extern "C" void func_002A6D68(Mgr_002AF050* m, char* name);
extern "C" Item_002AF050* func_002A53F8(Mgr_002AF050* m, Iter_002AF050* it, int a);
extern "C" Item_002AF050* func_002A5490(Mgr_002AF050* m, Iter_002AF050* it, int a);
extern "C" int func_002B1FC8(Item_002AF050* e);
extern "C" void func_00206968(int p);
extern "C" void func_00206920(int p);
extern "C" void* func_0022E358(void* g);
extern "C" void* func_0022E360(void* g);
extern "C" void func_0024FA70(void* p, int v);
extern "C" void func_0023C298(void* p, int v);
extern "C" int func_002A19A8(Mgr_002AF050* m);
extern "C" Arr_002AF050* func_001E55F8(char* name, int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int v);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E66C0(void* arr, void* src);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_001E7B38(void* s, unsigned int name, void* arr);
extern "C" void func_0022D728(void* g, int v);
extern "C" int func_0024FBD8(void* p, void* s);
extern "C" void func_0024F418(void* p, int n);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_0022E9B8(void* g);
extern "C" void func_002A7598(Mgr_002AF050* m);
extern "C" void func_002A7ED8(Mgr_002AF050* m, int v);
extern "C" void func_002A7EA8(Mgr_002AF050* m, int v);
extern "C" void func_002A7EB8(Mgr_002AF050* m, int v);
extern "C" void func_002A7658(Mgr_002AF050* m, int v);
extern "C" void func_0023C6C0(void* p);
extern "C" void func_002B2310(Item_002AF050* e);
extern "C" void func_002B3070(Item_002AF050* e);
extern "C" Scr_002AF050* func_00185578(int script, unsigned int checksum);
extern "C" void func_002381E0(void* p);
extern "C" Item_002AF050* func_002A5820(Mgr_002AF050* m);
extern "C" void func_002B2BC0(Item_002AF050* e, int v);
extern "C" int func_001E8A50(void* p, char* key, unsigned int* out, int flag);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);

struct Cmd_002AF050 {
    Info_002AF050* m0;
    char pad4[0x18];
    Mgr_002AF050* m1C;
    int Run();
};

int Cmd_002AF050::Run()
{
    Iter_002AF050 it;
    unsigned int key;
    unsigned int name;
    void* g = D_0038FC78;
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    Mgr_002AF050* m = m1C;
    Info_002AF050* p = m0;
    func_002A6D68(m, p->m2C);
    m->m70 = p->m28;
    m->m190 = 0;
    for (Item_002AF050* e = func_002A53F8(m, &it, 0); e; e = func_002A5490(m, &it, 0)) {
        if (!func_002B1FC8(e)) {
            func_00206968(e->m18);
            func_00206920(e->m18);
        }
    }
    func_0024FA70(func_0022E358(g), p->m0);
    func_0023C298(func_0022E360(g), 0);
    Arr_002AF050* arr;
    if (func_002A19A8(m)) {
        arr = func_001E55F8(D_00379050, 0);
    } else {
        arr = func_001E55F8(D_00379358, 0);
    }
    void* s = func_001E6978(func_001190D0(8));
    if (p->m8 == 0 && p->m0 != func_001F0D78(D_00379370)) {
        func_001E7A68(s, func_001F0D78(D_00379380), 1, 0);
        if (p->m0 != 0x3D6D444F && p->m0 != 0xBFF33600) {
            void* a = func_001E8DD0(func_00122CF8(0x10));
            func_001E66C0(a, func_001E55F8(D_00379398, 0));
            func_001E7A68(func_001E9378(a, 0), func_001F0D78(D_00392270), 1, p->m10);
            func_001E7B38(s, func_001F0D78(D_003793B0), a);
        }
    } else {
        func_001E7A68(s, func_001F0D78(D_00379380), 1, p->m8);
        if (p->m0 == func_001F0D78(D_00392290)) {
            void* a = func_001E8DD0(func_00122CF8(0x10));
            func_001E66C0(a, func_001E55F8(D_003793C8, 0));
            func_001E7B38(s, func_001F0D78(D_003793B0), a);
        }
    }
    func_001E7A68(s, 0xCE87E4E3, 1, p->m18);
    func_001E7A68(s, 0x48E748B5, 1, p->m20);
    func_0022D728(g, p->m8);
    func_0024FBD8(func_0022E358(g), s);
    func_0024F418(func_0022E358(g), p->m24);
    if (s) func_001E6AE8(s, 3);
    func_001F0370(D_003793E0, 0, 0, 0);
    func_0022E9B8(g);
    func_002A7598(m);
    m->m18C = 0;
    m->m34 = 0;
    func_002A7ED8(m, 0);
    func_002A7EA8(m, 0);
    func_002A7EB8(m, -1);
    func_002A7658(m, p->m21);
    if (p->m0 == func_001F0D78(D_00379370)) {
        func_0023C6C0(func_0022E360(g));
    }
    m->m30 = 0;
    Item_002AF050* e;
    for (e = func_002A53F8(m, &it, 1); e; e = func_002A5490(m, &it, 1)) {
        func_002B2310(e);
        func_002B3070(e);
        if (e->m18) {
            Scr_002AF050* sc = func_00185578(e->m18, 0xD262802F);
            if (sc->m1C) func_002381E0(sc->m1C);
        }
    }
    e = func_002A5820(m);
    if (e) func_002B2BC0(e, 0);
    for (int i = 0; i < arr->mC; i++) {
        void* r = func_001E9378(arr, i);
        func_001E8A50(r, D_00379020, &key, 1);
        if (key == p->m0) {
            void* t = func_001E6978(func_001190D0(8));
            func_001E7268(t, D_003922B8, p->m8);
            func_001E7268(t, D_00392270, p->m10);
            if (p->m8 == 0) {
                func_001E7200(t, 0xF0E712D2, 1);
            } else {
                func_001E7200(t, 0xF0E712D2, 0);
            }
            func_001E8A50(r, D_003793F8, &name, 1);
            func_001F0210(name, t, 0, 0, 0);
            if (t) func_001E6AE8(t, 3);
            break;
        }
    }
    func_0010A9B0(D_00388A70);
    return 1;
}
