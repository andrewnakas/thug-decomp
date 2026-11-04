typedef int qword __attribute__((mode(TI)));

struct Vec_0017B5C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Mat_0017B5C8 {
    Vec_0017B5C8 r[4];
    Mat_0017B5C8() {}
    const Vec_0017B5C8& operator[](int i) const { return r[i]; }
    Mat_0017B5C8(const Mat_0017B5C8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

struct Obj_0017B5C8 {
    Mat_0017B5C8 m_mat;
    int m40[10];
    int m68;
};

struct Pkt_0017B5C8 {
    unsigned short m0;
    unsigned short m2;
};

struct Ent_0017B5C8 {
    int m0[3];
    Pkt_0017B5C8* mC;
    int m10[16];
};

struct Node_0017B5C8 {
    int m0[12];
    Ent_0017B5C8* m30;
    int m34;
};

extern Node_0017B5C8* D_003942FC;
extern Node_0017B5C8* D_0039427C;
extern float D_00394040;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_3A8[];
extern char D_310[];
extern char D_17C0[];
extern char D_280[];
extern "C" void func_00323318(Mat_0017B5C8* d, Mat_0017B5C8* a, Mat_0017B5C8* b);
extern "C" void func_001617A0(Node_0017B5C8* n);
extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164F48(void* m);
extern "C" void func_00164EB8(int a);
extern "C" unsigned int func_001726C0(Obj_0017B5C8* o);
extern "C" int func_00177978(Ent_0017B5C8* e);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Put4(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    D_00394274 = (unsigned char*)(p + 4);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Close()
{
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}

static inline void Unpack(int n)
{
    unsigned int c = n & 0xFF;
    unsigned int h = (c << 16) | 0x6C000000;
    Put(h | ((unsigned short)D_00394280 & 0x3FF));
    D_00394290 = c;
}

extern "C" void func_0017B5C8(Obj_0017B5C8* obj, Node_0017B5C8* node)
{
    int i;
    Mat_0017B5C8 m(obj->m_mat);
    Mat_0017B5C8 s;
    D_00394040 = m.r[3].y;
    Vec_0017B5C8* t = &m.r[3];
    t->Set(m.r[1].x * -36.0f, m.r[1].y * -36.0f, m.r[1].z * -36.0f, 1.0f);
    Vec_0017B5C8* r0 = &s.r[0];
    Vec_0017B5C8* r1 = &s.r[1];
    Vec_0017B5C8* r2 = &s.r[2];
    Vec_0017B5C8* r3 = &s.r[3];
    r0->Set(32.0f, 0.0f, 0.0f, 0.0f);
    r1->Set(0.0f, 0.0f, 0.0f, 0.0f);
    r2->Set(0.0f, 32.0f, 0.0f, 0.0f);
    r3->Set(8421376.0f, 8421376.0f, 0.0f, 1.0f);
    func_00323318(&m, &s, &m);
    Node_0017B5C8* cur = D_003942FC;
    if (D_0039427C != cur) {
        func_001617A0(cur);
    }
    Tag(0x10000000, 0);
    func_00164E48(0, (unsigned int)D_3A8 >> 3);
    func_00164F48(&m);
    func_00164EB8(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    Put(0x30000000);
    Put4(0, 0, 0, 0);
    Put(0x11000000);
    Close();
    int n = obj->m68 << 2;
    D_00394280 = 0;
    unsigned int addr = func_001726C0(obj);
    Tag(n | 0x30000000, addr);
    Put(0);
    Unpack(obj->m68 << 2);
    Tag(0x10000000, 0);
    Put(((obj->m68 << 2) & 0xFFFF) | 0x04000000);
    Put((((unsigned int)D_17C0 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    Ent_0017B5C8* e = node->m30;
    for (i = 0; i < node->m34; e++, i++) {
        if (func_00177978(e) && e->mC) {
            D_00394294 = 0x100;
            D_00394280 = 0x100;
            Tag(0x50000000, (unsigned int)e->mC);
            Put(0x03000100);
            Put(0x02000000);
            Put((((unsigned int)D_280 >> 3) & 0xFFFF) | 0x14000000);
            D_00394294 = D_00394280;
            Put(0x04000004);
            Put(0x11000000);
            Close();
            D_00394280 += e->mC->m2;
        }
    }
    Tag(0x10000000, 0);
    Put(0x11000000);
    Put(0);
    if (D_0039427C != node) {
        func_001617A0(node);
    }
}
