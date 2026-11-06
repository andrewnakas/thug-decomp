/* fuzzy: 65.5 */
extern char D_00366B58[];
extern char D_003781D8[];
extern char D_003920C0[];
extern char D_00378200[];

struct Iter_002A12C0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A12C0() { m4 = 0; m8 = D_00366B58; }
    ~Iter_002A12C0() { m8 = D_00366B58; }
};

struct Peer_002A12C0 {
    char pad[0x20B4];
    int m20B4;
    char pad20B8[0x20EC - 0x20B8];
    char m20EC[0x34FC - 0x20EC];
    char m34FC[4];
};

struct Net_002A12C0 {
    char pad[0x14];
    void* m14;
    void* m18;
};

extern "C" int func_00201288(void* p);
extern "C" Peer_002A12C0* func_00200EC0(void* l, Iter_002A12C0* it);
extern "C" Peer_002A12C0* func_00200EF8(void* l, Iter_002A12C0* it);
extern "C" int func_00202768(Peer_002A12C0* p);
extern "C" int func_00202808(Peer_002A12C0* p);
extern "C" int func_001F9570(char* p);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002A12C0 {
    char pad[0x20];
    Net_002A12C0* m20;
    void List();
};

void Obj_002A12C0::List()
{
    Iter_002A12C0 it;
    char buf[1024];
    Net_002A12C0* net = m20;
    int pass = 0;
    do {
        pass++;
        if (net->m18 && !func_00201288(net->m18)) {
            int n = 0;
            for (Peer_002A12C0* p = func_00200EC0(net->m18, &it); p; p = func_00200EF8(net->m18, &it)) {
                if (!func_00202768(p)) {
                    char* a = p->m20EC;
                    char* b = p->m34FC;
                    func_003331D0(buf, D_003781D8, n, func_00202768(p) ? 0 : p->m20B4, func_00202808(p), func_001F9570(a), func_001F9570(b));
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E7138(s, D_003920C0, buf);
                    func_001F0370(D_00378200, s, 0, 0);
                    if (s)
                        func_001E6AE8(s, 3);
                    n++;
                }
            }
        }
        if (net->m14) {
            int n = 0;
            for (Peer_002A12C0* p = func_00200EC0(net->m14, &it); p; p = func_00200EF8(net->m14, &it)) {
                if (!func_00202768(p)) {
                    char* a = p->m20EC;
                    char* b = p->m34FC;
                    func_003331D0(buf, D_003781D8, n, func_00202768(p) ? 0 : p->m20B4, func_00202808(p), func_001F9570(a), func_001F9570(b));
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E7138(s, D_003920C0, buf);
                    func_001F0370(D_00378200, s, 0, 0);
                    if (s)
                        func_001E6AE8(s, 3);
                    n++;
                }
            }
        }
    } while (pass < 2);
}
