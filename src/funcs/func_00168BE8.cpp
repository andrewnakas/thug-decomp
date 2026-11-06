struct Vec_00168BE8 {
    float x, y, z, w;
};

extern unsigned int* D_00394274;
extern Vec_00168BE8 D_003E1610;
extern char D_380[];
extern char D_003E1580[];
extern char D_003E1590[];
extern char D_003E13C0[];
extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164F08(void* v);
extern "C" void func_00164F48(void* m);
extern "C" void func_00164EB8(int a);

static inline void Put_00168BE8(unsigned int v)
{
    unsigned int* p = D_00394274;
    *p = v;
    D_00394274 = p + 1;
}

static inline void PutVec_00168BE8(int x, int y, int z, int w)
{
    int* p = (int*)D_00394274;
    p[0] = x;
    p[1] = y;
    p[2] = z;
    p[3] = w;
    D_00394274 = (unsigned int*)(p + 4);
}

extern "C" void func_00168BE8(int a)
{
    int x = (int)D_003E1610.x;
    int y = (int)D_003E1610.y;
    int z = (int)D_003E1610.z;
    int w = (int)D_003E1610.w;
    Put_00168BE8(0x30000000);
    PutVec_00168BE8(x, y, z, w);
    func_00164E48(a, (unsigned int)D_380 >> 3);
    func_00164F08(D_003E1580);
    func_00164F08(D_003E1590);
    func_00164F48(D_003E13C0);
    func_00164EB8(0);
}
