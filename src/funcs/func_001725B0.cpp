extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

struct Inst_001725B0;

struct Owner_001725B0 {
    char pad0[0x3C];
    Inst_001725B0* m3C;
};

struct Inst_001725B0 {
    char pad0[0x60];
    int m60;
    void* m64;
    char pad68[0x6C - 0x68];
    Inst_001725B0* m6C;
    Owner_001725B0* m70;
    void Destroy(unsigned int flags);
};

void Inst_001725B0::Destroy(unsigned int flags)
{
    if ((m60 >> 4) & 1) {
        if (m64)
            func_0010A8D8(D_00388A70, m64);
    }
    if (m70->m3C == this) {
        m70->m3C = m6C;
    } else {
        Inst_001725B0* p;
        for (p = m70->m3C; p; p = p->m6C) {
            if (p->m6C == this)
                break;
        }
        p->m6C = m6C;
    }
    if (flags & 1)
        func_0010A8D8(D_00388A70, this);
}
