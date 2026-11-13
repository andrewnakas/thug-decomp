/* fuzzy: 96.6 */
struct Vec_001688F0 {
    float x, y, z, w;
};

extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern int D_0038882C;
extern unsigned long D_00394050;
extern unsigned long D_00394048;
extern Vec_001688F0 D_003E1610;
extern char D_003E1640[];
extern char D_003E1580[];
extern char D_003E1590[];
extern char D_003E13C0[];

extern "C" void func_00164E48(int a, unsigned int b);
extern char D_378[];
extern "C" void func_00164F08(void* p);
extern "C" void func_00164F48(void* p);
extern "C" void func_00164EB8(int a);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);

static inline void Tag_001688F0(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Add_001688F0(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

static inline void Row_001688F0(const Vec_001688F0& v)
{
    float x = v.x, y = v.y, z = v.z, w = v.w;
    Add_001688F0(0x30000000);
    int* p = (int*)D_00394274;
    p[0] = (int)x;
    p[1] = (int)y;
    p[2] = (int)z;
    p[3] = (int)w;
    D_00394274 = (unsigned int*)(p + 4);
}

static inline void Reg_001688F0(unsigned long v, unsigned int r)
{
    unsigned int* p = D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = r;
    D_00394274 = p + 3;
}

static inline bool IsPal_001688F0() { return D_0038882C == 1; }

void func_001688F0()
{
    Tag_001688F0(0x10000000, 0);
    Row_001688F0(D_003E1610);
    unsigned int r = 8;
    func_00164E48(0, (unsigned int)D_378 >> 3);
    func_00164F08(D_003E1640);
    func_00164F08(D_003E1580);
    func_00164F08(D_003E1590);
    func_00164F48(D_003E13C0);
    func_00164EB8(0);
    func_001645F8(0, 0, 0);
    Reg_001688F0(5, r);
    Reg_001688F0(D_0038882C == 1 ? 0xFF000000000A0000 : 0xFF00000000080000, 0x4C);
    Reg_001688F0(D_00394050, 0x40);
    Reg_001688F0(D_00394048, 0x18);
    Reg_001688F0(0x50000, 0x47);
    Reg_001688F0(1, 0x46);
    bool pal = D_0038882C == 1;
    unsigned int hh = pal ? 0x280 : 0x200;
    unsigned int ww = pal ? 0x280 : 0x200;
    unsigned int fb = pal ? ww * 0x700 >> 13 : ww >> 2;
    unsigned long zv;
    if (IsPal_001688F0()) {
        zv = ((fb + (hh * 0x380 >> 13)) & 0x1FF) | 0x101000000;
    } else {
        zv = fb + (hh >> 3);
        zv = (zv & 0x1FF) | 0x101000000;
    }
    Reg_001688F0(zv, 0x4E);
    func_001646D0(0);
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
}
