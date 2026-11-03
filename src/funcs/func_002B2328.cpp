extern char D_00379650[];
extern char D_003923A0[];
extern char D_003923A8[];
extern char D_003923B0[];
extern char D_00379660[];
extern char D_00379678[];
extern char D_00379688[];
extern char D_003796A0[];
extern void* D_00392068;

struct Elem_002B2328 {
    char pad0[0x30];
    int m30;
    char m34[0x14C - 0x34];
    int m14C;
    void Announce(int id);
};

extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" Elem_002B2328* func_002A56E0(void* t);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* p, int name, int type, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" int func_002B1FC8(Elem_002B2328* e);
extern "C" int func_002B1FE8(Elem_002B2328* e);
extern "C" int func_001F0D78(char* s);

void Elem_002B2328::Announce(int id)
{
    char buf[64];
    void* g = D_00392068;
    func_003331D0(buf, D_00379650, id + 1);
    Elem_002B2328* host = func_002A56E0(g);
    void* p = func_001E6978(func_001190D0(8));
    if (func_002B1FC8(this)) {
        func_001E7A30(p, func_001F0D78(D_003923A0), 3, func_001E54B8(buf, 0));
        func_001E7268(p, D_003923A8, id);
        func_001F0370(D_00379660, p, 0, 0);
    } else if (!func_002B1FE8(host) && host->m30 == id) {
        func_001E7A30(p, func_001F0D78(D_003923A0), 3, (int)m34);
        func_001E7268(p, D_003923A8, id);
        func_001F0370(D_00379678, 0, 0, 0);
        func_001F0370(D_00379688, p, 0, 0);
    } else {
        func_001E7A30(p, func_001F0D78(D_003923A0), 3, (int)m34);
        func_001E7A30(p, func_001F0D78(D_003923B0), 3, func_001E54B8(buf, 0));
        func_001E7268(p, D_003923A8, id);
        func_001F0370(D_003796A0, p, 0, 0);
    }
    m14C &= ~0x7800;
    if (p)
        func_001E6AE8(p, 3);
}
