struct Port_0010FD30 {
    char pad0[0xC814];
    int m_busy;
    char padC818[0xC920 - 0xC818];
};

extern int D_0038881C;
extern Port_0010FD30 D_003973D8[];

extern "C" void func_0010FD30(Port_0010FD30* p)
{
    int n = D_0038881C ? 1 : 3;
    for (int i = 0; i < n; i++) {
        if (p == &D_003973D8[i]) {
            D_003973D8[i].m_busy = 0;
            return;
        }
    }
}
