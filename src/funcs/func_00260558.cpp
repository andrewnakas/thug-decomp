extern void* D_00388A70;
extern char D_00375B28[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct C_00260558 {
    char m_pad[0x70];
    char* m70;
};

extern "C" void func_00260558(C_00260558* p, int flags)
{
    p->m70 = D_00375B28;
    if (flags & 1) func_0010A8D8(D_00388A70, p);
}
