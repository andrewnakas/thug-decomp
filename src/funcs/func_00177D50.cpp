struct Node_00177D50 {
    Node_00177D50* m_next;
    int m4[3];
    unsigned char* m10[2];
    unsigned char* m18[4];
    int m28[11];
    int m54;
};

extern Node_00177D50* D_003942A0;
extern Node_00177D50* D_0039427C;
extern int D_00394094;
extern int D_0039429C;
extern int D_0038882C;
extern float D_003E1610[4];
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern char D_280[];
extern char D_310[];
extern "C" void func_001617A0(Node_00177D50* n);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);

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

static inline void Cycle(int n)
{
    Put(0x01000000 | (n << 8) | n);
    D_0039429C = n;
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

extern "C" void func_00177D50()
{
    Node_00177D50* cur = D_003942A0;
    if (D_0039427C != cur) {
        func_001617A0(cur);
    }
    D_003942A0->m28[D_00394094] = 1;
    Tag(0x10000000, 0);
    Put(0x11000000);
    float* f = D_003E1610;
    float x = f[0];
    float y = f[1];
    float z = f[2];
    float w = f[3];
    Put(0x30000000);
    int* q = (int*)D_00394274;
    q[0] = (int)x;
    q[1] = (int)y;
    q[2] = (int)z;
    q[3] = (int)w;
    D_00394274 = (unsigned char*)(q + 4);
    Put(0x20000000);
    Put(0);
    Put(0x05000000);
    Cycle(1);
    Put(0x03000000);
    Put(0x02000000);
    Put((((unsigned int)D_280 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = 0;
    D_00394280 = 0;
    func_001645F8(0, 0, 0);
    int pal = D_0038882C == 1;
    Reg((pal ? 0x6C00 : 0x7000) | ((long)(pal ? 0x7200 : 0x7000) << 32), 0x18);
    pal = D_0038882C == 1;
    Reg((pal ? 0x27F0000 : 0x1FF0000) | ((long)(pal ? 0x1BF : 0x1FF) << 48), 0x40);
    Reg(0x50000, 0x47);
    Reg(5, 8);
    Reg(1, 0x1A);
    func_001646D0(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}
