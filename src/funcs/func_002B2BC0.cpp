struct Mgr_002B2BC0;
struct Obj_002B2BC0;

struct Sk_002B2BC0 {
    char pad[0x18];
    int m18;
};

extern Mgr_002B2BC0* D_00392068;
extern void* D_0038FC78;
extern char D_00379768[];
extern char D_00379778[];
extern char D_00379788[];
extern char D_003797A0[];
extern char D_003797B0[];
extern char D_003797C8[];
extern char D_003923A0[];
extern char D_003923B8[];
extern char D_003923C0[];
extern "C" Obj_002B2BC0* func_002A5820(Mgr_002B2BC0* m);
extern "C" int func_002B1FC8(Obj_002B2BC0* o);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_002041F8(Sk_002B2BC0* p);
extern "C" int func_001F0D78(const char* s);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" int func_002A19A8(Mgr_002B2BC0* m);
extern "C" void* func_002A52F0(Mgr_002B2BC0* m, unsigned short id);
extern "C" char* func_00206A08(Sk_002B2BC0* p);
extern "C" void* func_002A8498(Mgr_002B2BC0* m);
extern "C" void func_002680E8(void* p, Sk_002B2BC0* s);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);

struct Obj_002B2BC0 {
    char pad0[0x18];
    Sk_002B2BC0* m18;
    char pad1C[0x34 - 0x1C];
    char m34[0x14C - 0x34];
    int m14C;
    unsigned long IsSel() { unsigned long v = *(unsigned char*)&m14C; return v >> 7; }
    void Select(int on);
};

void Obj_002B2BC0::Select(int on)
{
    Mgr_002B2BC0* mgr = D_00392068;
    void* gs = D_0038FC78;
    if (on) {
        Obj_002B2BC0* cur = func_002A5820(mgr);
        if (cur) cur->Select(0);
        if (!(m14C & 0x80)) {
            m14C |= 0x80;
            if (func_002B1FC8(this)) {
                void* s = func_001E6978(func_001190D0(8));
                if (!func_002041F8(m18)) {
                    func_001E73C8(s, D_00379768, func_001F0D78(D_00379768));
                } else {
                    func_001E73C8(s, D_00379778, func_001F0D78(D_00379778));
                }
                func_001F0370(D_00379788, s, 0, 0);
                if (s) func_001E6AE8(s, 3);
                func_001F0370(D_003797A0, 0, 0, 0);
            } else {
                void* s = func_001E6978(func_001190D0(8));
                func_001E73C8(s, D_00379768, func_001F0D78(D_00379768));
                func_001F0370(D_003797B0, s, 0, 0);
                func_001E7138(s, D_003923A0, m34);
                func_001F0370(D_003797C8, s, 0, 0);
                if (s) func_001E6AE8(s, 3);
            }
            if (!func_002A19A8(mgr) && func_002A52F0(mgr, m18->m18 == 0)) {
                void* s = func_001E6978(func_001190D0(8));
                func_001E7138(s, D_003923A0, func_00206A08(m18));
                func_001F0370(D_003797C8, s, 0, 0);
                if (s) func_001E6AE8(s, 3);
            }
            m14C |= 0x80;
        }
        void* p = func_002A8498(mgr);
        if (p) func_002680E8(p, m18);
    } else {
        if (IsSel()) {
            if (func_002B1FC8(this) &&
                (func_0024F938(func_0022E358(gs)) == func_001F0D78(D_003923B8) ||
                 func_0024F938(func_0022E358(gs)) == func_001F0D78(D_003923C0))) {
                void* s = func_001E6978(func_001190D0(8));
                func_001E73C8(s, D_00379768, func_001F0D78(D_00379768));
                func_001E73C8(s, D_00379778, func_001F0D78(D_00379778));
                func_001F0370(D_003797B0, s, 0, 0);
                if (s) func_001E6AE8(s, 3);
            }
            m14C &= ~0x80;
        }
    }
}
