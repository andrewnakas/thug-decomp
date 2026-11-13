/* fuzzy: 81.9 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001780F0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void operator*=(float k)
    {
        x *= k;
        y *= k;
        z *= k;
        w *= k;
    }
};

/* a Vec_001780F0 built from its four components */
struct VecInit_001780F0 : Vec_001780F0 {
    VecInit_001780F0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

/* a quadword of the packet, copied word by word */
struct Words_001780F0 {
    unsigned int w[4];
};

struct Mat_001780F0 {
    Vec_001780F0 r[4];
    Vec_001780F0& operator[](int i)
    {
        return r[i];
    }
    const Vec_001780F0& operator[](int i) const
    {
        return r[i];
    }
    Mat_001780F0() {}
    Mat_001780F0(const Mat_001780F0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_001780F0& operator=(const Mat_001780F0& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Pkt_001780F0 {
    short m0;
    unsigned short m2;
};

struct Mesh_001780F0 {
    int m0;
    unsigned int m4;
    int m8;
    Pkt_001780F0* mC;
    int m10[8];
    Vec_001780F0 m30;
    int m40;
    int m44;
    int m48;
    int m4C;
};

extern Vec_001780F0 D_003DD9F0[3];
extern Vec_001780F0 D_003DDA20[4];

struct Light_001780F0 {
    unsigned int m0;
    int m4[3];
    Vec_001780F0 m10[3];
    Vec_001780F0 m40[4];
    Vec_001780F0 m80[4];
    /* light i's direction, or the default one unless flag bit 1+i is set */
    Vec_001780F0* Dir(int i)
    {
        return (m0 & (2 << i)) ? &m10[i] : &D_003DD9F0[i];
    }
    /* colour i, or the default one unless one of the flag bits in mask is set */
    Vec_001780F0& Colour(int i, unsigned int mask)
    {
        return (m0 & mask) ? m80[i] : D_003DDA20[i];
    }
};

struct Inst_001780F0 {
    Mat_001780F0 m0;
    int m40[8];
    int m60;
    bool Visible() const
    {
        return (m60 & 1) ? true : false;
    }
    int m64;
    int m68;
    Inst_001780F0* m6C;
    int m70;
    Light_001780F0* m74;
};

struct Geom_001780F0 {
    int m0[4];
    unsigned int m10;
    int m14[10];
    Inst_001780F0* m3C;
};

struct Node_001780F0 {
    Node_001780F0* m0;
    int m4[9];
    int m28[2];
    Mesh_001780F0* m30;
    int m34;
    int m38[4];
    Geom_001780F0* m48;
};

extern Node_001780F0* D_003942F4;
extern Node_001780F0* D_003942A0;
extern Node_001780F0* D_003942FC;
extern Node_001780F0* D_0039427C;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern int D_0039429C;
extern int D_00394094;
extern long D_00394048;
extern long D_00394050;
extern float D_00394058;
extern float D_0039405C;
extern float D_00394060;
extern float D_00394064;
extern float D_00394070;
extern float D_00394074;
extern float D_00394078;
extern float D_0039407C;
extern float D_00394088;
extern float D_0039408C;
extern float D_003940AC;
extern float D_0038C020;
extern int D_0038C02C;
extern Mat_001780F0 D_003E1080;
extern Mat_001780F0 D_003E1100;
extern Mat_001780F0 D_003E1240;
extern Mat_001780F0 D_003E12C0;
extern Mat_001780F0 D_003E1300;
extern Words_001780F0 D_003E1580;
extern Words_001780F0 D_003E1590;
extern Words_001780F0 D_003E15A0;
extern Words_001780F0 D_003E15B0;
extern Words_001780F0 D_003E1640;
extern char D_280[];
extern char D_308[];
extern char D_310[];
extern char D_378[];
extern char D_380[];
extern char D_3A8[];
extern char D_420[];
extern char D_17C0[];

extern "C" int func_00177A58();
extern "C" int func_00177978(Mesh_001780F0* m);
extern "C" void func_001617A0(Node_001780F0* n);
extern "C" void func_00161090(Pkt_001780F0* p, int mode);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164EB8(int a);
extern "C" void func_00164F48(Mat_001780F0* m);
extern "C" unsigned int func_001726C0(Inst_001780F0* i);
extern "C" unsigned int func_00172778(Inst_001780F0* i);
extern "C" unsigned int func_001727F8(Inst_001780F0* i, int a, int b);
extern "C" unsigned int func_00172858(Inst_001780F0* i, int a);
extern "C" Vec_001780F0 func_00172870(Inst_001780F0* i);
extern "C" void func_0017B5C8(Inst_001780F0* i, Node_001780F0* n);
extern "C" void func_00323298(Vec_001780F0* out, Mat_001780F0* m, Vec_001780F0* v);
extern "C" void func_00323318(Mat_001780F0* d, const Mat_001780F0* a, Mat_001780F0* b);
extern "C" void func_003233B8(Vec_001780F0* d, Vec_001780F0* s);

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

static inline void Quad(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    D_00394274 = (unsigned char*)(p + 4);
}


static inline void CopyWords(Words_001780F0* d, const Words_001780F0* s)
{
    d->w[0] = s->w[0];
    d->w[1] = s->w[1];
    d->w[2] = s->w[2];
    d->w[3] = s->w[3];
}

static inline void AddReg(long data, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (int)data;
    p[1] = (int)(data >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

static inline void Mscal(char* prog)
{
    Put((((unsigned int)prog >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
}

static inline void Unpack(unsigned int num, unsigned short addr)
{
    num &= 0xFF;
    Put((num << 16) | 0x6C000000 | (addr & 0x3FF));
    D_00394290 = num;
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

static inline void Flush()
{
    if (D_0039427C) {
        func_001617A0(0);
    }
}

static inline void ZeroMat(Mat_001780F0* m)
{
    m->r[0].x = 0.0f;
    m->r[0].y = 0.0f;
    m->r[0].z = 0.0f;
    m->r[0].w = 0.0f;
    m->r[1].x = 0.0f;
    m->r[1].y = 0.0f;
    m->r[1].z = 0.0f;
    m->r[1].w = 0.0f;
    m->r[2].x = 0.0f;
    m->r[2].y = 0.0f;
    m->r[2].z = 0.0f;
    m->r[2].w = 0.0f;
    m->r[3].x = 0.0f;
    m->r[3].y = 0.0f;
    m->r[3].z = 0.0f;
    m->r[3].w = 0.0f;
}

static inline void SetVec(Vec_001780F0* v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* a plain four-float vector: a Vec_001780F0 converts to it component by component */
struct Raw_001780F0 {
    float x, y, z, w;
    Raw_001780F0(const Vec_001780F0& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
};

static inline VecInit_001780F0 Scale(const Raw_001780F0& s, float k)
{
    return VecInit_001780F0(s.x * k, s.y * k, s.z * k, s.w * k);
}


/* m * k */
static inline Mat_001780F0 Mul(const Mat_001780F0& m, const Mat_001780F0& k)
{
    Mat_001780F0 t = m;
    func_00323318(&t, &k, &t);
    return t;
}



/* Tint the four light colours by the packed rgb in c, and load them (times 2^-30)
   into row 3 of the direction matrix and rows 0..2 of the colour matrix. */
static inline void Tint(unsigned int c, const Vec_001780F0* col, Vec_001780F0* tint,
                        Mat_001780F0* dir, Mat_001780F0* lit)
{
    float k = (float)(c & 0xFF) * 0.0078125f;
    tint[0].x = col[0].x * k;
    tint[3].x = col[3].x * k;
    tint[1].x = col[1].x * k;
    tint[2].x = col[2].x * k;
    k = (float)((c >> 8) & 0xFF) * 0.0078125f;
    tint[0].y = col[0].y * k;
    tint[3].y = col[3].y * k;
    tint[1].y = col[1].y * k;
    tint[2].y = col[2].y * k;
    k = (float)((c >> 16) & 0xFF) * 0.0078125f;
    tint[0].z = col[0].z * k;
    tint[1].z = col[1].z * k;
    tint[2].z = col[2].z * k;
    tint[3].z = col[3].z * k;
    dir->r[3] = Scale(tint[0], 9.31322574615478515625e-10f);
    lit->r[0] = Scale(tint[1], 9.31322574615478515625e-10f);
    lit->r[1] = Scale(tint[2], 9.31322574615478515625e-10f);
    lit->r[2] = Scale(tint[3], 9.31322574615478515625e-10f);
}

static inline void DrawMesh(Mesh_001780F0* m, int flags)
{
    D_00394294 = 0x100;
    D_00394280 = 0x100;
    Tag(0x50000000, (unsigned int)m->mC);
    Put(0x03000100);
    Put(0x02000000);
    Mscal(D_280);
    Put((flags & 0xFFFF) | 0x04000000);
    Put(0x11000000);
    Close();
    D_00394280 += m->mC->m2;
}

extern "C" void func_001780F0()
{
    if (!func_00177A58())
        return;

    Mat_001780F0 inst;
    Mat_001780F0 view;
    Mat_001780F0 mid;
    Mat_001780F0 proj;
    Mat_001780F0 inst2;
    Mat_001780F0 view2;
    Mat_001780F0 m180;
    Mat_001780F0 m1C0;
    Mat_001780F0 dir;
    Mat_001780F0 lit;
    Vec_001780F0 col[4];
    Vec_001780F0 tint[4];
    Vec_001780F0 ctr;
    Mat_001780F0 scale;
    Mat_001780F0 scaled;
    unsigned int colour;
    float r;

    ZeroMat(&inst);
    ZeroMat(&view);
    ZeroMat(&mid);
    ZeroMat(&proj);
    ZeroMat(&inst2);
    ZeroMat(&view2);
    ZeroMat(&m180);
    ZeroMat(&m1C0);
    ZeroMat(&dir);
    SetVec(&col[0], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&col[1], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&col[2], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&col[3], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&tint[0], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&tint[1], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&tint[2], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&tint[3], 0.0f, 0.0f, 0.0f, 1.0f);
    SetVec(&ctr, 0.0f, 0.0f, 0.0f, 1.0f);

    if (D_0039427C != D_003942FC) {
        func_001617A0(D_003942FC);
    }
    Tag(0x10000000, 0);
    func_001645F8(0, 0, 0);
    AddReg(0x7800 | (long)0x7800 << 32, 0x19);
    AddReg(0x2000000 | (long)1 << 32, 0x4F);
    AddReg(0x30000, 0x48);
    AddReg(0xFF0000 | (long)0xFF0000 << 32, 0x41);
    AddReg(0x20401F0, 0x4D);
    AddReg(0, 0x4B);
    AddReg(0x206, 0);
    AddReg(0, 1);
    AddReg(0x78007800, 5);
    AddReg(0x88008800, 5);
    AddReg(1, 0x4B);
    AddReg(0xFE0001 | (long)0xFE0001 << 32, 0x41);
    AddReg(0, 0x1A);
    AddReg(0x200, 0x1B);
    func_001646D0(1);
    Mscal(D_310);
    Close();
    Flush();

    for (Node_001780F0* n = D_003942F4; n != D_003942A0; n = n->m0) {
        if (n == D_003942FC)
            continue;
        if (!n->m48 || (n->m48->m10 & 2))
            continue;
        if (D_0039427C != n) {
            func_001617A0(n);
        }
        Tag(0x10000000, 0);
        Put(0x11000000);
        Put(0x20000000);
        Put(0);
        Put(0x05000000);
        Put(0x01000101);
        D_0039429C = 1;
        Put(0x31000000);
        Quad(0x3F800000, 0, 0, 0);
        Put(0x03000000);
        Put(0x02000000);
        Put((((unsigned int)D_280 >> 3) & 0xFFFF) | 0x14000000);
        D_00394294 = 0;
        D_00394280 = 0;
        func_00164E48(0, (unsigned int)D_378 >> 3);
        Words_001780F0* q = (Words_001780F0*)D_00394274;
        CopyWords(&q[0], &D_003E1640);
        CopyWords(&q[1], &D_003E1580);
        CopyWords(&q[2], &D_003E1590);
        D_00394274 = (unsigned char*)(q + 3);
        func_00164EB8(0);
        func_001645F8(0, 0, 0);
        AddReg(D_00394048, 0x18);
        AddReg(D_00394050, 0x40);
        func_001646D0(1);
        Mscal(D_310);
        Close();

        scale.r[0] = VecInit_001780F0(1.0f, 0.0f, 0.0f, 0.0f);
        scale.r[1] = VecInit_001780F0(0.0f, 1.0f, 0.0f, 0.0f);
        scale.r[2] = VecInit_001780F0(0.0f, 0.0f, 1.4f, 0.0f);
        scale.r[3] = VecInit_001780F0(0.0f, 0.0f, 0.0f, 0.0f);

        Geom_001780F0* g = n->m48;
        if (!g)
            continue;

        /* Pass 1: unlit geometry. */
        if ((g->m10 & 1) && n->m30 && !(n->m30->m4 & 0x10)) {
            for (Inst_001780F0* s = g->m3C; s; s = s->m6C) {
                if (!s->Visible())
                    continue;
                inst = s->m0;
                view = Mul(inst, D_003E1080);
                mid = Mul(inst, D_003E1100);
                proj = Mul(mid, D_003E12C0);
                func_00323318(&scaled, &scale, &view);
                Tag(0x10000000, 0);
                Put(0x30000000);
                Quad(0, 0, 0, 0);
                func_00164E48(0, (unsigned int)D_3A8 >> 3);
                func_00164F48(&proj);
                func_00164F48(&scaled);
                func_00164EB8(0);
                Close();
                Mesh_001780F0* m = n->m30;
                for (int i = 0; i < n->m34; i++, m++) {
                    if (!func_00177978(m) || !m->mC)
                        continue;
                    ctr = m->m30;
                    ctr.w = 1.0f;
                    func_00323298(&ctr, &view, &ctr);
                    r = m->m30.w;
                    float x = ctr.x;
                    float y = ctr.y;
                    float z = ctr.z;
                    /* wholly outside one of the frustum planes */
                    if (r < z - D_00394088 || r < D_0039408C - z
                        || r < D_0039405C * z + D_00394064 * y
                        || r < D_0039405C * z - D_00394064 * y
                        || r < D_00394058 * z - D_00394060 * x
                        || r < D_00394058 * z + D_00394060 * x)
                        continue;
                    /* wholly inside: no clipping needed */
                    if (r < D_00394088 - z && r < z - D_0039408C
                        && r < -D_00394074 * z - D_0039407C * y
                        && r < -D_00394074 * z + D_0039407C * y
                        && r < -D_00394070 * z + D_00394078 * x
                        && r < -D_00394070 * z - D_00394078 * x) {
                        func_00161090(m->mC, 0);
                    } else {
                        func_00161090(m->mC, 2);
                    }
                    n->m28[D_00394094] = 1;
                }
            }
        }

        /* Pass 2: lit geometry. */
        Geom_001780F0* lit_g = n->m48;
        if (lit_g && (lit_g->m10 & 1) && n->m30 && (n->m30->m4 & 0x10))
        for (Inst_001780F0* s = lit_g->m3C; s; s = s->m6C) {
            if (!s->Visible())
                continue;
            if ((s->m60 >> 1) & 1) {
                func_0017B5C8(s, n);
            }
            inst2 = s->m0;
            view2 = Mul(inst2, D_003E1080);
            ctr = func_00172870(s);
            r = ctr.w;
            ctr.w = 1.0f;
            func_00323298(&ctr, &view2, &ctr);
            float x = ctr.x;
            float y = ctr.y;
            float z = ctr.z;
            if (r < z - D_00394088 || r < D_0039408C - z
                || r < D_0039405C * z + D_00394064 * y
                || r < D_0039405C * z - D_00394064 * y
                || r < D_00394058 * z - D_00394060 * x
                || r < D_00394058 * z + D_00394060 * x)
                continue;
            int clip = 1;
            if (r < D_00394088 - z && r < z - D_0039408C
                && r < -D_00394074 * z - D_0039407C * y
                && r < -D_00394074 * z + D_0039407C * y
                && r < -D_00394070 * z + D_00394078 * x
                && r < -D_00394070 * z - D_00394078 * x)
                clip = 0;
            if ((s->m60 >> 3) & 1) {
                clip |= 0x20;
            }
            n->m28[D_00394094] = 1;
            Tag(0x10000000, 0);
            view2[0] *= 128.0f;
            view2[1] *= 128.0f;
            view2[2] *= 128.0f;
            m180 = Mul(view2, D_003E1240);
            m1C0 = Mul(m180, D_003E1300);

            Light_001780F0* l = s->m74;
            if (l) {
                Vec_001780F0* d0 = l->Dir(0);
                Vec_001780F0* d1 = l->Dir(1);
                Vec_001780F0* d2 = l->Dir(2);
                dir.r[0].x = d0->x;
                dir.r[1].x = d0->y;
                dir.r[2].x = d0->z;
                dir.r[0].y = d1->x;
                dir.r[1].y = d1->y;
                dir.r[2].y = d1->z;
                dir.r[0].z = d2->x;
                dir.r[1].z = d2->y;
                dir.r[2].z = d2->z;
            } else {
                dir.r[0].x = D_003DD9F0[0].x;
                dir.r[1].x = D_003DD9F0[0].y;
                dir.r[2].x = D_003DD9F0[0].z;
                dir.r[0].y = D_003DD9F0[1].x;
                dir.r[1].y = D_003DD9F0[1].y;
                dir.r[2].y = D_003DD9F0[1].z;
                dir.r[0].z = D_003DD9F0[2].x;
                dir.r[1].z = D_003DD9F0[2].y;
                dir.r[2].z = D_003DD9F0[2].z;
            }
            Mat_001780F0 nrm = s->m0;
            func_003233B8(&nrm.r[0], &nrm.r[0]);
            func_003233B8(&nrm.r[1], &nrm.r[1]);
            func_003233B8(&nrm.r[2], &nrm.r[2]);
            dir = Mul(nrm, dir);

            if (l) {
                col[0] = (l->m0 & 0x11) ? l->m80[3] : D_003DDA20[3];
                col[1] = l->Colour(0, 0x22);
                col[2] = l->Colour(1, 0x44);
                col[3] = l->Colour(2, 0x88);
            } else {
                col[0] = D_003DDA20[3];
                col[1] = D_003DDA20[0];
                col[2] = D_003DDA20[1];
                col[3] = D_003DDA20[2];
            }
            if ((s->m60 >> 4) & 1) {
                colour = func_00172858(s, 0);
            } else {
                colour = func_00172778(s);
            }
            Tint(colour, col, tint, &dir, &lit);

            func_00164E48(0, (unsigned int)D_380 >> 3);
            Words_001780F0* q = (Words_001780F0*)D_00394274;
            CopyWords(&q[0], &D_003E15A0);
            CopyWords(&q[1], &D_003E15B0);
            D_00394274 = (unsigned char*)(q + 2);
            func_00164F48(&m180);
            func_00164F48(&m1C0);
            func_00164F48(&dir);
            func_00164F48(&lit);
            func_00164EB8(0);

            float depth = -view2.r[3].z;
            float fog;
            if (D_0038C020 < depth && D_0038C02C) {
                fog = D_003940AC * (D_0038C020 / depth - 1.0f) + 1.0f;
            } else {
                fog = 1.0f;
            }
            func_001645F8(0, 0, 0);
            AddReg((long)(int)(fog * 255.99f) << 56, 0xA);
            func_001646D0(1);
            Mscal(D_310);
            Put(0x13000000);
            Close();

            unsigned int qwc = s->m68 * 4;
            D_00394280 = 0;
            unsigned int src = func_001726C0(s);
            Tag(qwc | 0x30000000, src);
            Put(0);
            Unpack(s->m68 * 4, D_00394280);
            Tag(0x10000000, 0);
            Put(((s->m68 * 4) & 0xFFFF) | 0x04000000);
            Mscal(D_17C0);
            Put(0x30000000);
            Quad(0, 0, 0, 0);
            Close();

            Mesh_001780F0* m = n->m30;
            for (int i = 0; i < n->m34; i++, m++) {
                if (!func_00177978(m) || !m->mC || (m->m4 & 0x40000))
                    continue;
                if ((s->m60 >> 4) & 1) {
                    unsigned int c = func_001727F8(s, m->m48, m->m44);
                    if (colour != c) {
                        colour = c;
                        Tint(colour, col, tint, &dir, &lit);
                        Tag(0x10000000, 0);
                        Put(0x03000100);
                        Put(0x02000000);
                        D_00394280 = 0x100;
                        func_00164E48(0, (unsigned int)D_420 >> 3);
                        func_00164F48(&dir);
                        func_00164F48(&lit);
                        func_00164EB8(1);
                        Mscal(D_308);
                        Put(0x11000000);
                        Close();
                    }
                }
                DrawMesh(m, clip);
            }

            Tag(0x10000000, 0);
            Put(0x03000100);
            Put(0x02000000);
            dir.r[3] = Scale(col[0], 9.31322574615478515625e-10f);
            lit.r[0] = Scale(col[1], 9.31322574615478515625e-10f);
            D_00394280 = 0x100;
            lit.r[1] = Scale(col[2], 9.31322574615478515625e-10f);
            lit.r[2] = Scale(col[3], 9.31322574615478515625e-10f);
            func_00164E48(0, (unsigned int)D_420 >> 3);
            func_00164F48(&dir);
            func_00164F48(&lit);
            func_00164EB8(1);
            Mscal(D_308);
            Put(0x11000000);
            Close();

            m = n->m30;
            for (int i = 0; i < n->m34; i++, m++) {
                if (func_00177978(m) && m->mC && (m->m4 & 0x40000)) {
                    DrawMesh(m, clip);
                }
            }
        }
    }
    Flush();
}
