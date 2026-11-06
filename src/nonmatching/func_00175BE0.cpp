/* fuzzy: 47.1 */
extern unsigned char* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern int D_0039429C;
extern "C" void func_00164328(int a, int b, int c, int d, int e, int f);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

extern "C" void func_00175BE0(int a, int count, int b, int c, int d)
{
    unsigned int n = count & 0xFFFF;
    Put(n | 0x01000100);
    if (!n) n = 1;
    D_0039429C = n;
    Put(((unsigned short)D_00394280 & 0x3FF) | 0x6C01C000);
    D_00394290 = 1;
    func_00164328(a, count, 0, b, c, d);
}
