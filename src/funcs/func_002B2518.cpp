extern char D_00371C78[];
extern char D_00379650[];
extern char D_003923A0[];
extern char D_003923B0[];
extern char D_003796B8[];
extern char D_003796C8[];
extern char D_003796E0[];

struct Iter_002B2518 {
    int m0;
    int m4;
    void* m8;
    Iter_002B2518() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002B2518() { m8 = D_00371C78; }
};

struct Elem_002B2518;

extern void* D_00392068;
extern "C" int func_001F0D78(char* s);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" Elem_002B2518* func_002A56E0(void* mgr);
extern "C" int func_002B1FC8(void* item);
extern "C" int func_002B1FE8(void* item);
extern "C" int func_002B22C8(void* item);
extern "C" void func_002B2310(void* item);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" Elem_002B2518* func_002A53F8(void* self, Iter_002B2518* it, int a);
extern "C" Elem_002B2518* func_002A5490(void* self, Iter_002B2518* it, int a);

struct Elem_002B2518 {
    char pad[0x34];
    char m34[0x14C - 0x34];
    int m14C;
    void SetGroup(int g);
};

void Elem_002B2518::SetGroup(int g)
{
    Iter_002B2518 it;
    char buf[64];
    void* mgr = D_00392068;
    func_003331D0(buf, D_00379650, g + 1);
    void* s = func_001E6978(func_001190D0(8));
    Elem_002B2518* cur = func_002A56E0(mgr);
    if (func_002B1FC8(this)) {
        func_001E7A30(s, func_001F0D78(D_003923A0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_003796B8, s, 0, 0);
    } else if (!func_002B1FE8(cur) && func_002B22C8(cur) == g) {
        func_001E7A30(s, func_001F0D78(D_003923A0), 3, m34);
        func_001E7A30(s, func_001F0D78(D_003923B0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_003796C8, s, 0, 0);
    } else {
        func_001E7A30(s, func_001F0D78(D_003923A0), 3, m34);
        func_001E7A30(s, func_001F0D78(D_003923B0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_003796E0, s, 0, 0);
    }
    if (s)
        func_001E6AE8(s, 3);
    Elem_002B2518* q = func_002A53F8(mgr, &it, 0);
    if (q) do {
        if (func_002B22C8(q) == g) {
            q->m14C &= ~(0x800 << g);
            func_002B2310(q);
        }
        q = func_002A5490(mgr, &it, 0);
    } while (q);
    m14C |= 0x800 << g;
}
