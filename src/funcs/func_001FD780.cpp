struct Addr_001FD780 {
    short m_family;
    unsigned short m_port;
    int m_addr;
    char m_zero[8];
};

struct Conn_001FD780 {
    char pad0[0x1820];
    int m1820;
    char m1824[0x14];
    int m1838;
};

extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" unsigned short func_00326B40(unsigned short v);
extern "C" int func_001FA648(int a);
extern "C" int func_003252D8(int s, Addr_001FD780* a, int len);
extern "C" int func_003264C8(int s);
extern "C" void func_00200F78(Conn_001FD780* c);
extern "C" int func_00325550(int s, void* a, int* len);

int func_001FD780(Conn_001FD780* c, int ip, unsigned short port)
{
    Addr_001FD780 addr;
    int len;
    func_003315B8(&addr, 0, 0x10);
    addr.m_family = 2;
    addr.m_port = func_00326B40(port);
    if (func_001FA648(c->m1838) != 1) {
        addr.m_addr = ip;
    }
    func_003315B8(addr.m_zero, 0, 8);
    if (func_003252D8(c->m1820, &addr, 0x10) < 0) {
        if (func_003264C8(c->m1820) != 0x14) goto fail;
        func_00200F78(c);
        addr.m_port = func_00326B40(0);
        if (func_003252D8(c->m1820, &addr, 0x10) < 0) goto fail;
    }
    len = 0x10;
    if (func_00325550(c->m1820, c->m1824, &len) >= 0) return 1;
fail:
    func_00200F78(c);
    return 0;
}
