extern char D_00371C78[];

struct Iter_002B2990 {
    int m0;
    int m4;
    void* m8;
    Iter_002B2990() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002B2990() { m8 = D_00371C78; }
};

extern void* D_00392068;
extern char D_00379650[];
extern char D_003923A0[];
extern char D_003923A8[];
extern char D_003923B0[];
extern char D_00379678[];
extern char D_00379738[];
extern char D_00379750[];

struct Obj_002B2990 {
    char pad0[0x30];
    int m30;
    char m34[4];
    void Announce();
};

extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_002B1FC8(Obj_002B2990* o);
extern "C" int func_002B1FE8(Obj_002B2990* o);
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* p, int name, int type, void* v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" Obj_002B2990* func_002A56E0(void* t);
extern "C" Obj_002B2990* func_002A53F8(void* self, Iter_002B2990* it, int a);
extern "C" Obj_002B2990* func_002A5490(void* self, Iter_002B2990* it, int a);
extern "C" int func_002B22C8(Obj_002B2990* o);
extern "C" void func_002B2310(Obj_002B2990* o);

void Obj_002B2990::Announce()
{
    Iter_002B2990 it;
    void* t = D_00392068;
    char buf[64];
    func_003331D0(buf, D_00379650, m30 + 1);
    void* p = func_001E6978(func_001190D0(8));
    if (func_002B1FC8(this)) {
        func_001E7A30(p, func_001F0D78(D_003923A0), 3, (void*)func_001E54B8(buf, 0));
        func_001E7268(p, D_003923A8, m30);
        func_001F0370(D_00379678, 0, 0, 0);
        func_001F0370(D_00379738, p, 0, 0);
    } else {
        Obj_002B2990* o = func_002A56E0(t);
        if (o && !func_002B1FE8(o) && o->m30 == m30) func_001F0370(D_00379678, 0, 0, 0);
        func_001E7A30(p, func_001F0D78(D_003923A0), 3, m34);
        func_001E7A30(p, func_001F0D78(D_003923B0), 3, (void*)func_001E54B8(buf, 0));
        func_001E7268(p, D_003923A8, m30);
        func_001F0370(D_00379750, p, 0, 0);
    }
    for (Obj_002B2990* e = func_002A53F8(t, &it, 0); e; e = func_002A5490(t, &it, 0)) {
        if (func_002B22C8(e) == m30) {
            func_002B2310(e);
            break;
        }
    }
}
