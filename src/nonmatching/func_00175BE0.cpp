/* fuzzy: 85.7 */
extern unsigned int* D_00394274;
extern unsigned short D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_0039429C;
extern "C" void func_00164328(unsigned int addr, unsigned int n, int a, int b, int c, int d);

static inline void Put(unsigned int v)
{
    unsigned int* p = D_00394274;
    *p = v;
    D_00394274 = p + 1;
}

static inline void Clamp(int& c)
{
    if (c == 0)
        c = 1;
}

static inline void StCycl(int cl, int wl)
{
    Put(0x01000000 | (wl << 8) | cl);
    Clamp(cl);
    D_0039429C = cl;
}

static inline void Unpack(int cmd, int num, unsigned short addr, int mode)
{
    Put(((mode << 14) | (addr & 0x3FF)) & 0xFFFF | ((cmd << 24) | (num << 16)));
    D_00394290 = num;
}

extern "C" void func_00175BE0(unsigned int addr, unsigned int n, int b, int c, int d)
{
    StCycl((unsigned short)n, 1);
    Unpack(0x6C, 1, D_00394280, 3);
    func_00164328(addr, n, 0, b, c, d);
}
