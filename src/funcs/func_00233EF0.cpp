/* sym: _vt$13Iter_00233EF0 = 0x00371C78 */
struct Net_00233EF0;
extern Net_00233EF0* D_00392068;
extern char D_003730A0[];
extern char D_003731D0[];
extern char D_003731E8[];
extern char D_00373200[];
extern char D_00373210[];
extern char D_0038FDA8[];

class Iter_00233EF0 {
public:
    void* m_node;
    int m_index;
    Iter_00233EF0() : m_index(0) {}
    virtual ~Iter_00233EF0() {}
    virtual void Run();
};

struct Info_00233EF0 {
    char pad[0x38];
    int m38;
};
extern Info_00233EF0* D_00390828;

struct Msg_00233EF0 {
    int m0;
    int m4;
    char m8;
    char m9;
    char mA[1];
};

struct Skater_00233EF0 {
    char pad[0x31C];
    int m31C;
};

struct Conn_00233EF0 {
    char pad0[0x18];
    Conn_00233EF0* m18;
    char pad1C[0x18];
    char m34[0x20];
};

struct Leader_00233EF0 {
    char pad0[0x18];
    void* m18;
    char pad1C[0x14];
    int m30;
};

extern "C" void* memcpy(void* d, const void* s, unsigned int n);
extern "C" int func_002A1A38(Net_00233EF0* net);
extern "C" void* func_0022E358(void* g);
extern "C" void func_0024EFE0(void* self, int v);
extern "C" void* func_0022E040(void* g);
extern "C" Skater_00233EF0* func_00187B48(void* mgr, int id);
extern "C" bool func_0024F8D8(void* a, char* name);
extern "C" bool func_0024F4C0(void* self);
extern "C" void* func_00203360(Skater_00233EF0* sk);
extern "C" int func_0024F938(void* gm);
extern "C" int func_002392B8(void* s);
extern "C" void func_00239198(void* s, int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" char* func_00206A08(Skater_00233EF0* sk);
extern "C" void func_001E70C0(void* p, unsigned int name, char* v);
extern "C" void func_001F0210(unsigned int name, void* p, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_0022C4A0(void* game, Skater_00233EF0* sk, int a);
extern "C" void func_002A7ED8(Net_00233EF0* net, int v);
extern "C" int func_00236248(void* g);
extern "C" int func_002A8580(Net_00233EF0* net);
extern "C" void func_002A8588(Net_00233EF0* net);
extern "C" bool func_0024F540(void* gm);
extern "C" int func_0024F590(void* gm);
extern "C" int func_002B0FB8(Net_00233EF0* net, int team);
extern "C" Leader_00233EF0* func_002A56E0(Net_00233EF0* net);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" int func_002A7EC0(Net_00233EF0* net);
extern "C" int func_002A8560(Net_00233EF0* net);
extern "C" void func_001F0370(char* name, void* params, void* obj, int a);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001E6B30(void* p);
extern "C" int func_001F0D78(char* name);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* p, int name, int type, char* v);
extern "C" void func_002A7EB8(Net_00233EF0* net, int v);
extern "C" Conn_00233EF0* func_002A53F8(Net_00233EF0* net, Iter_00233EF0* it, int a);
extern "C" Conn_00233EF0* func_002A5490(Net_00233EF0* net, Iter_00233EF0* it, int a);
extern "C" int func_002B1108(Net_00233EF0* net, void* p);
extern "C" int func_002B1FC8(Conn_00233EF0* c);
extern "C" Conn_00233EF0* func_002A7EB0(Net_00233EF0* net);
extern "C" bool func_0024F908(void* a, unsigned int key);
extern "C" void func_002A7EA8(Net_00233EF0* net, Conn_00233EF0* c);

struct Cmd_00233EF0 {
    Msg_00233EF0* m0;
    char pad4[0x18];
    void* m1C;
    int Run();
};

int Cmd_00233EF0::Run()
{
    Msg_00233EF0* msg = m0;
    Net_00233EF0* net = D_00392068;
    void* g = m1C;
    char* p = msg->mA;
    Info_00233EF0* info = D_00390828;
    int i;
    if (!func_002A1A38(net))
        func_0024EFE0(func_0022E358(g), msg->m0);
    for (i = 0; i < msg->m9; i++) {
        int score;
        char idx = *p;
        p++;
        memcpy(&score, p, 4);
        p += 4;
        Skater_00233EF0* sk = func_00187B48(func_0022E040(g), idx);
        if (!sk)
            continue;
        if (func_0024F8D8(func_0022E358(g), D_003730A0) || !func_0024F4C0(func_0022E358(g))) {
            void* s = func_00203360(sk);
            if (func_0024F938(func_0022E358(g)) == 0xBFF33600 && !sk->m31C) {
                if (func_002392B8(s) > 0 && !score) {
                    void* prm = func_001E6978(func_001190D0(8));
                    func_001E70C0(prm, 0xA1DC81F9, func_00206A08(sk));
                    func_001F0210(0x9B043179, prm, 0, 0, 0);
                    if (prm)
                        func_001E6AE8(prm, 3);
                    func_0022C4A0(g, sk, 1);
                }
            }
            func_00239198(s, score);
        } else if (!sk->m31C) {
            func_00239198(func_00203360(sk), score);
        }
    }
    if (msg->m8)
        func_002A7ED8(net, 1);
    int id = msg->m4;
    if (id != func_00236248(g) && !func_002A8580(net)) {
        func_001F0210(0x1CEDB62C, 0, 0, 0, 0);
        func_002A8588(net);
    }
    if (func_0024F540(func_0022E358(g))) {
        char buf[0x80];
        int best = -1;
        int max = 0;
        int n = func_0024F590(func_0022E358(g));
        for (i = 0; i < n; i++) {
            int sc = func_002B0FB8(net, i);
            if (max < sc) {
                max = sc;
                best = i;
            } else if (sc == max) {
                best = -1;
            }
        }
        if (best != -1) {
            Leader_00233EF0* l = func_002A56E0(net);
            if (msg->m8) {
                if (l->m18) {
                    if (l->m30 == best)
                        func_001848F0(l->m18, 0x96935417, 0);
                    else
                        func_001848F0(l->m18, 0xE3EC7E9E, 0);
                }
            } else if (func_002A7EC0(net) != best && func_0024F8D8(func_0022E358(g), D_003731D0) && !func_002A8560(net)) {
                if (l->m18 && l->m30 == best) {
                    func_001F0370(D_003731E8, 0, l->m18, 0);
                } else {
                    func_003331D0(buf, D_00373200, best + 1);
                    void* prm = func_001E6978(func_001190D0(8));
                    func_001E6B30(prm);
                    int k = func_001F0D78(D_0038FDA8);
                    func_001E7A30(prm, k, 3, func_001E54B8(buf, 0));
                    func_001F0370(D_00373210, prm, l->m18, 0);
                    if (prm)
                        func_001E6AE8(prm, 3);
                }
                func_002A7EB8(net, best);
            }
        }
    } else {
        Iter_00233EF0 it;
        Conn_00233EF0* best = 0;
        int max = 0;
        int cnt = 0;
        for (Conn_00233EF0* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0)) {
            int sc = func_002B1108(net, c->m18->m18);
            if (max < sc) {
                max = sc;
                best = c;
            } else if (sc == max) {
                best = 0;
            }
            cnt++;
        }
        if (best) {
            Leader_00233EF0* l = func_002A56E0(net);
            if (msg->m8) {
                if (func_002B1FC8(best))
                    func_001848F0(best->m18, 0x96935417, 0);
                else if (l->m18)
                    func_001848F0(best->m18, 0xE3EC7E9E, 0);
            } else if (func_002A7EB0(net) != best && cnt >= 2 && func_0024F908(func_0022E358(g), 0xD63DFD0F) && !info->m38) {
                if (func_002B1FC8(best)) {
                    func_001F0210(0xA1D334D0, 0, best->m18, 0, 0);
                } else {
                    void* prm = func_001E6978(func_001190D0(8));
                    func_001E6B30(prm);
                    func_001E7A30(prm, 0xA4B08520, 3, best->m34);
                    func_001F0210(0x7A4B9D14, prm, l->m18, 0, 0);
                    if (prm)
                        func_001E6AE8(prm, 3);
                }
                func_002A7EA8(net, best);
            }
        }
    }
    return 1;
}
