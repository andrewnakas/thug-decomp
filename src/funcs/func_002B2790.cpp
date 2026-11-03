extern char D_00379650[];
extern char D_003923A0[];
extern char D_003923A8[];
extern char D_003923B0[];
extern char D_003796F8[];
extern char D_00379708[];
extern char D_00379718[];
extern char D_00379728[];

struct Elem_002B2790;

extern void* D_00392068;
extern "C" int func_001F0D78(char* s);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" Elem_002B2790* func_002A56E0(void* mgr);
extern "C" int func_002B1FC8(void* item);
extern "C" int func_002B1FE8(void* item);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

struct Elem_002B2790 {
    char pad[0x30];
    int m30;
    char m34[0x14C - 0x34];
    int m14C;
    void JoinGroup(int g);
};

void Elem_002B2790::JoinGroup(int g)
{
    char buf[64];
    void* mgr = D_00392068;
    func_003331D0(buf, D_00379650, g + 1);
    void* s = func_001E6978(func_001190D0(8));
    Elem_002B2790* cur = func_002A56E0(mgr);
    if (func_002B1FC8(this)) {
        func_001E7A30(s, func_001F0D78(D_003923A0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_003796F8, s, 0, 0);
    } else if (!func_002B1FE8(cur) && g == cur->m30) {
        void* t = func_001E6978(func_001190D0(8));
        func_001E7268(t, D_003923A8, cur->m30);
        func_001F0370(D_00379708, t, 0, 0);
        if (t)
            func_001E6AE8(t, 3);
        func_001E7A30(s, func_001F0D78(D_003923A0), 3, m34);
        func_001F0370(D_00379718, s, 0, 0);
    } else {
        func_001E7A30(s, func_001F0D78(D_003923A0), 3, m34);
        func_001E7A30(s, func_001F0D78(D_003923B0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_00379728, s, 0, 0);
    }
    if (s)
        func_001E6AE8(s, 3);
    m14C |= 0x800 << g;
}
