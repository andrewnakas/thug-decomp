struct Obj_001E2B10 {
    int m_port;
    char pad4[0x1C - 4];
    int m1C;
    int m20;
};
extern unsigned int D_0038E280;
extern "C" void func_001E28F8(int op, int a, int b, int c);

extern "C" void func_001E2B10(Obj_001E2B10* o)
{
    D_0038E280 = (D_0038E280 & ~(0x10000 << o->m_port)) | (0x100 << o->m_port);
    if (o->m_port == 0)
        func_001E28F8(0x160, 0, 0, 0);
    else
        func_001E28F8((o->m_port - 1) | 0x170, o->m20, o->m1C, 0);
}
