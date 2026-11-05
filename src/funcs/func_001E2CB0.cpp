extern int D_0038E280;

struct Pad_001E2CB0 {
    int m_port;
};

extern "C" void func_001E2C10(Pad_001E2CB0* p, int a);

extern "C" int func_001E2CB0(Pad_001E2CB0* p)
{
    int r = 0;
    if ((D_0038E280 >> p->m_port) & 1) {
        func_001E2C10(p, 0);
        r = 1;
        D_0038E280 &= ~(1 << p->m_port);
    } else if (D_0038E280 & (0x10 << p->m_port)) {
        func_001E2C10(p, 1);
        r = 2;
        D_0038E280 &= ~(0x10 << p->m_port);
    }
    return r;
}
