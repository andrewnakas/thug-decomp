struct Node_00177A60 {
    Node_00177A60* m_next;
    int m4[3];
    unsigned char* m10[2];
    unsigned char* m18[4];
    int m28[11];
    int m54;
};

extern Node_00177A60 D_003E26A0;
extern unsigned char* D_003942D0[2];
extern Node_00177A60* D_003942F4;
extern Node_00177A60* D_00394298;
extern Node_00177A60* D_00394300;
extern int D_00394094;
extern int D_003940A0;
extern int D_0039409C;
extern int D_003940A4;
extern int D_0039427C;
extern int D_0039429C;
extern unsigned char* D_003942C0;
extern int D_0038BFF4;
extern int D_0038BFE8;
extern int D_0038BFEC;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern char D_0034C4D8[];
extern char D_003484E0[];
extern char D_280[];
extern "C" int func_0010FC30();
extern "C" void func_00160F18(int a, int b);
extern "C" void func_001614C8(Node_00177A60* n);

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

extern "C" void func_00177A60()
{
    int r = func_0010FC30();
    Node_00177A60* g = &D_003E26A0;
    g->m54 = 0x8080;
    unsigned char* buf = D_003942D0[D_00394094];
    g->m18[D_00394094] = buf;
    g->m28[D_00394094] = 1;
    D_003940A0 = r;
    D_003942C0 = buf;
    D_00394274 = buf;
    if (D_0038BFF4) {
        if (D_0038BFE8) {
            func_00160F18(7, 2);
        } else {
            func_00160F18(1, 2);
        }
        D_0038BFE8 = D_0038BFEC;
    } else {
        func_00160F18(4, 2);
    }
    func_00160F18(3, 2);
    func_00160F18(6, 2);
    int n = (D_0034C4D8 - D_003484E0 + 15) / 16;
    unsigned int* t = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)t;
    t[1] = (unsigned int)D_003484E0;
    t[0] = n | 0x30000000;
    D_00394274 = (unsigned char*)(t + 2);
    Put(0);
    Put(0);
    Tag(0x70000000, 0);
    Put(0x11000000);
    Put(0x20000000);
    Put(0);
    Put(0x05000000);
    Cycle(1);
    Put(0x03000000);
    Put(0x02000000);
    Put((((unsigned int)D_280 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
    for (Node_00177A60* n = D_003942F4; n; n = n->m_next) {
        func_001614C8(n);
        n->m28[D_00394094] = 0;
    }
    D_0039427C = 0;
    D_00394298->m10[D_00394094] = D_00394274;
    D_00394300->m10[D_00394094] = D_00394274;
    Tag(0x70000000, 0);
    Put(0);
    Put(0);
    D_00394298->m28[D_00394094] = 1;
    D_0039409C = 0;
    D_003940A4 = 0;
}
