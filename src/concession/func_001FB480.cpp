/* cflags: -fno-gcse */
/* force: {"kind": "lfr", "block": 4, "reg": 123, "hard": 3} */
struct Addr_001FB480 {
    unsigned short m0;
    unsigned short port;
    int addr;
    char pad8[8];
};

struct Conn_001FB480 {
    char pad0[0x5C];
    unsigned int m5C;
    unsigned int m60;
    char pad64[0xC];
    void* m70;
    int m74;
    char pad78[0x2074];
    char m20EC[4];
};

typedef void (*Cb_001FB480)(void* a, int n, Addr_001FB480* from);

struct Net_001FB480 {
    int m0;
    char pad4[0x17F0];
    int m17F4;
    char pad17F8[0x28];
    int m1820;
    char pad1824[0x544];
    char m1D68[0x514];
    char pad227C_[0x0];
    unsigned int m227C;
    Cb_001FB480 m2280;
    char pad2284[0x201C];
    int m42A0;
    void Receive();
};

extern "C" int func_00201288(Net_001FB480* n);
extern "C" int func_00325A60(int s, char* buf, int len, int flags, Addr_001FB480* from, int* fromlen);
extern "C" void func_003264C8(int s);
extern "C" void func_0031BCE0(int m);
extern "C" void func_0031BCC0(int m);
extern "C" int func_00326B40(int port);
extern "C" Conn_001FB480* func_001FE960(Net_001FB480* n, int addr, int port);
extern "C" Conn_001FB480* func_001FEAE8(Net_001FB480* n, int addr, int port, int t);
extern "C" int func_00202738(Conn_001FB480* c);
extern "C" int func_001FE258(Net_001FB480* n, char* buf, unsigned int pos, int len);
extern "C" void func_001F9598(char* q, int len, int t);
extern "C" int func_0010FC30();
extern "C" void func_00201A68(Conn_001FB480* c, int r);
extern "C" void func_00202710(Conn_001FB480* c);

void Net_001FB480::Receive()
{
    struct { Addr_001FB480 a; int len; } f;
    f.len = 0x10;
    if (func_00201288(this)) return;
    char* buf = m1D68;
    int n;
    do {
        n = func_00325A60(m1820, buf, 0x514, 0, &f.a, &f.len);
        if (n < 0) {
            func_003264C8(m1820);
            return;
        }
        func_0031BCE0(m42A0);
        int len = n - 2;
        m17F4 += n;
        if (!(m227C & 0x20)) len = n;
        Conn_001FB480* c = func_001FE960(this, f.a.addr, func_00326B40(f.a.port));
        if (c) {
            if (func_00202738(c) || !(m227C & 0x20)) {
                if (c->m60 + len < c->m5C + 0xA28) {
                    if (!func_001FE258(this, buf, c->m60, n)) {
                        func_0031BCC0(m42A0);
                        if (m2280) m2280((void*)c->m60, n, &f.a);
                        continue;
                    }
                    c->m60 += len;
                    func_001F9598(c->m20EC, n + 0x1C, m0);
                    c->m74 = func_0010FC30();
                }
            }
        } else {
            c = func_001FEAE8(this, f.a.addr, func_00326B40(f.a.port), 6);
            if (c) {
                c->m70 = this;
                if (!func_001FE258(this, buf, c->m60, n)) {
                    func_0031BCC0(m42A0);
                    if (m2280) m2280(buf, n, &f.a);
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
