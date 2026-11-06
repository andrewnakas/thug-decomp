struct Addr_001FB860 {
    short m_family;
    unsigned short m_port;
    int m_addr;
    char m_zero[8];
};

struct Conn_001FB860 {
    char pad0[0x1820];
    int m1820;
    char pad1824[0x10];
    int m1834;
    char pad1838[0x4360 - 0x1838];
    Addr_001FB860 m_addr;
};

extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" unsigned short func_00326B40(unsigned short v);
extern "C" int func_00325460(int s, Addr_001FB860* a, int len);
extern "C" int func_003264C8(int s);
extern "C" void func_00200F78(Conn_001FB860* c);

int func_001FB860(Conn_001FB860* c, int ip, unsigned short port)
{
    func_003315B8(&c->m_addr, 0, 0x10);
    c->m_addr.m_family = 2;
    c->m_addr.m_port = func_00326B40(port);
    c->m_addr.m_addr = ip;
    func_003315B8(c->m_addr.m_zero, 0, 8);
    int ok = 0;
    do {
        if (func_00325460(c->m1820, &c->m_addr, 0x10) != -1) {
            ok = 1;
        } else if (func_003264C8(c->m1820) != 6) {
            func_00200F78(c);
            return 0;
        }
    } while (!ok);
    if (!ip) {
        c->m1834 = 0;
    } else {
        c->m1834 = 1;
    }
    return 1;
}
