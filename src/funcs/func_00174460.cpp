struct V_00174460 {
    float x;
    float y;
    float z;
    float w;
};

extern V_00174460 D_003E15A0;
extern V_00174460 D_003E1570;
extern char D_003E1400[];
extern float D_003876CC;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_380[];
extern char D_200[];
extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164F08(void* v);
extern "C" void func_00164F48(void* m);
extern "C" void func_00164EB8(int a);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00164408(int a, int b, int c, int d, int e, unsigned int f);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

extern "C" void func_00174460(unsigned int frame)
{
    unsigned int cycle = 4;
    unsigned int unpack = 0x6C000000;
    Tag(0x10000000, 0);
    D_00394294 = D_00394280;
    func_00164E48(0, (unsigned int)D_380 >> 3);
    func_00164F08(&D_003E15A0);
    V_00174460 v;
    v.x = -D_003E15A0.x * D_003E1570.x * D_003E15A0.w;
    v.y = -D_003E15A0.y * D_003E1570.y * D_003E15A0.w;
    v.z = -D_003E15A0.z * (D_003E1570.z + D_003876CC) * D_003E15A0.w;
    *(int*)&v.w = 0;
    func_00164F08(&v);
    func_00164F48(D_003E1400);
    func_00164EB8(0);
    func_001645F8(0, 0, 0);
    Reg(0x44, 0x42);
    Reg(frame, 1);
    func_001646D0(0);
    Put(0x04000001);
    Put(((unsigned short)D_00394280 & 0x3FF) | 0x6C014000);
    D_00394290 = 1;
    func_00164408(5, 1, 0, 0x41, 1, (unsigned int)D_200 >> 3);
    Put(0x05000001);
    D_0039428C = cycle;
    D_00394288 = D_00394274;
    D_00394284 = 0x20;
    Put((((unsigned short)D_00394280 + 1) & 0x3FF) | unpack);
}
