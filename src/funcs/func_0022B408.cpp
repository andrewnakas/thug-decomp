struct Skater_0022B408 {
    char pad0[0x54];
    unsigned int m_flags;
};

struct Obj_0022B408 {
    char pad0[0x20];
    Skater_0022B408* m_skater;
    void Report();
};

extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" void func_0022B3A8(unsigned int name);

void Obj_0022B408::Report()
{
    Skater_0022B408* sk = m_skater;
    if (!func_001E5628(0xF3E055E1, 1)) {
        return;
    }
    if (sk->m_flags & 0x10) {
        func_0022B3A8(0xCBB91022);
    } else if (sk->m_flags & 0x80) {
        func_0022B3A8(0xE69691FA);
    } else if (sk->m_flags & 0x20) {
        func_0022B3A8(0xFFC29C2A);
    } else if (sk->m_flags & 0x800) {
        func_0022B3A8(0x51B0E413);
    } else if (sk->m_flags & 0x40) {
        func_0022B3A8(0x746D2598);
    } else if (sk->m_flags & 4) {
        func_0022B3A8(0x81D0A13C);
    } else if (sk->m_flags & 1) {
        func_0022B3A8(0x18D9F086);
    } else if (sk->m_flags & 8) {
        func_0022B3A8(0x55919EE3);
    } else if (sk->m_flags & 2) {
        func_0022B3A8(0xCC98CF59);
    } else if (sk->m_flags & 0x1000) {
        func_0022B3A8(0x1B0B7922);
    } else if (sk->m_flags & 0x4000) {
        func_0022B3A8(0xBBC0E36A);
    } else if (sk->m_flags & 0x8000) {
        func_0022B3A8(0xDD589439);
    } else if (sk->m_flags & 0x2000) {
        func_0022B3A8(0x7A03C488);
    }
}
