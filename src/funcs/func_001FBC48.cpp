struct Addr_001FBC48 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    char m8[8];
};
struct Conn_001FBC48;
struct Obj_001FBC48;
typedef void (*Cb_001FBC48)(char* buf, int n, Addr_001FBC48* addr);

extern "C" int func_00201288(Obj_001FBC48* self);
extern "C" int func_00325A60(int s, char* buf, int len, int flags, Addr_001FBC48* from, int* fromlen);
extern "C" int func_00325888(int s, char* buf, int len, int flags);
extern "C" void func_003264C8(int s);
extern "C" int func_0031BCE0(int sema);
extern "C" int func_0031BCC0(int sema);
extern "C" unsigned short func_00326B40(unsigned short v);
extern "C" Conn_001FBC48* func_001FE960(Obj_001FBC48* self, unsigned int ip, unsigned short port);
extern "C" Conn_001FBC48* func_001FEAE8(Obj_001FBC48* self, unsigned int ip, unsigned short port, int n);
extern "C" unsigned int func_0010FC30();
extern "C" int func_001FE258(Obj_001FBC48* self, char* buf, int pos, int n);
extern "C" void func_001F9598(void* p, int n, int v);
extern "C" void func_00201A68(Conn_001FBC48* c, int n);
extern "C" void func_00202710(Conn_001FBC48* c);

struct Conn_001FBC48 {
    char pad0[0x5C];
    int m5C;
    unsigned int m60;
    char pad64[0x70 - 0x64];
    Obj_001FBC48* m70;
    unsigned int m74;
    char pad78[0x20EC - 0x78];
    char m20EC[4];
};

struct Obj_001FBC48 {
    int m0;
    char pad4[0x17F4 - 4];
    int m17F4;
    char pad17F8[0x1820 - 0x17F8];
    int m1820;
    char pad1824[0x1834 - 0x1824];
    int m1834;
    char pad1838[0x1D68 - 0x1838];
    char m1D68[0x514];
    char pad[0x227C - 0x1D68 - 0x514];
    unsigned int m227C;
    Cb_001FBC48 m2280;
    char pad2284[0x42A0 - 0x2284];
    int m42A0;
    char pad42A4[0x4362 - 0x42A4];
    unsigned short m4362;
    unsigned int m4364;
    void Run();
};

void Obj_001FBC48::Run()
{
    Addr_001FBC48 addr;
    int addrlen = 16;
    if (func_00201288(this)) return;
    int n;
    do {
        if (!m1834) {
            n = func_00325A60(m1820, m1D68, 0x514, 0, &addr, &addrlen);
        } else {
            n = func_00325888(m1820, m1D68, 0x514, 0);
        }
        if (n < 0) {
            func_003264C8(m1820);
            return;
        }
        func_0031BCE0(m42A0);
        int len = n - 2;
        if (!(m227C & 0x20)) len = n;
        m17F4 += n;
        Conn_001FBC48* c = func_001FE960(this, m4364, func_00326B40(m4362));
        if (c) {
            if (c->m60 + len < c->m5C + 0xA28) {
                unsigned int t = func_0010FC30();
                if (!func_001FE258(this, m1D68, c->m60, n)) {
                    func_0031BCC0(m42A0);
                    if (m2280) m2280(m1D68, n, &addr);
                    continue;
                }
                c->m60 += len;
                func_001F9598(c->m20EC, n + 0x1C, m0);
                if (c->m74 < t) c->m74 = t;
            }
        } else if (!m1834) {
            c = func_001FEAE8(this, addr.m4, func_00326B40(addr.m2), 6);
            if (c) {
                c->m70 = this;
                if (!func_001FE258(this, m1D68, c->m60, n)) {
                    func_0031BCC0(m42A0);
                    if (m2280) m2280(m1D68, n, &addr);
                    func_00201A68(c, 3);
                    continue;
                }
                c->m60 = c->m5C + len;
                func_00202710(c);
            }
        }
        func_0031BCC0(m42A0);
    } while (n > 0);
}
