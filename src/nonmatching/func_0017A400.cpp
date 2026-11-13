/* fuzzy: 81.7 */
/* Builds the per-frame render DMA chain: one GIF/VIF setup packet per active viewport, then the main
   camera packet, the GS environment registers and the closing tag. */
struct Material_0017A400 {
    char pad0[0x10];
    unsigned int flags;             /* 0x10 */
};

struct Viewport_0017A400 {
    Viewport_0017A400* next;        /* 0x00 */
    char pad4[8];
    unsigned int flags;             /* 0x0C */
    unsigned int* chain[6];         /* 0x10, per-buffer start of the chain */
    int ready[6];                   /* 0x28 */
    char pad40[8];
    Material_0017A400* material;    /* 0x48 */
    char pad4C[4];
    void* camera;                   /* 0x50 */
};

struct Matrix_0017A400 {
    float m[4][4];
};

struct Camera_0017A400 {
    char pad0[0x40];
    float pos[3];                   /* 0x40 */
    char pad4C[4];
    char data[1];                   /* 0x50 */
};

extern Viewport_0017A400* D_003942F4;
extern Viewport_0017A400* D_003942A0;
extern Viewport_0017A400* D_003942FC;
extern Viewport_0017A400* D_0039427C;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern int D_0039409C;
extern int D_00394094;
extern float D_00394040;
extern long D_00394048;
extern long D_00394050;
extern int D_0038882C;
extern unsigned char D_0038C030;
extern unsigned int* D_003E2718[];
extern int D_0038BC88, D_0038BC8C, D_0038BC90, D_0038BC94, D_0038BC98, D_0038BC9C, D_0038BCA0, D_0038BCA4;
extern int D_0038BCA8, D_0038BCAC, D_0038BCB0, D_0038BCB4, D_0038BCB8, D_0038BCBC, D_0038BCC0, D_0038BCC4;
extern int D_0038BCC8, D_0038BCCC, D_0038BCD0;
extern char D_003E0FE0[];
extern char D_003E1580[];
extern char D_003E1590[];
extern char D_003E15E0[];
extern char D_003E15F0[];
extern char D_003E1640[];
extern char D_310[];
extern char D_378[];
extern char D_380[];

extern "C" void func_001617A0(Viewport_0017A400* vp);
extern "C" void func_00164E48(unsigned int eop, unsigned int prim);
extern "C" void func_00164F08(void* v);
extern "C" void func_00164EB8(unsigned int eop);
extern "C" void func_001645F8(int flag, int b, int c);
extern "C" void func_001646D0(unsigned int eop);
extern "C" void func_00166FA8(void* view);
extern "C" void func_001671A8(void* view, Matrix_0017A400* m);
extern "C" Camera_0017A400* func_00167140(unsigned int* buf, void* view);
extern "C" void func_00167068(Camera_0017A400* cam);
extern "C" void func_00168368(Camera_0017A400* cam, float f);
extern "C" void func_00168120(Camera_0017A400* cam, float f);
extern "C" void func_0016DCB8(void* list, void* view, int n);

static inline void Tag(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Put(unsigned int v)
{
    unsigned int* p = D_00394274;
    *p = v;
    D_00394274 = p + 1;
}

/* GIF A+D register write */
static inline void Reg(long v, int reg)
{
    unsigned int* p = D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = p + 3;
}

/* pad to a qword and patch the qword count into the open tag */
static inline void CloseTag()
{
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
}

static inline void Select(Viewport_0017A400* vp)
{
    if (D_0039427C != vp)
        func_001617A0(vp);
}

void func_0017A400(int skipList)
{
    for (Viewport_0017A400* vp = D_003942F4; vp != D_003942A0; vp = vp->next) {
        if (vp == D_003942FC)
            continue;
        if (!vp->material || !(vp->material->flags & 2))
            continue;
        Select(vp);
        if (vp->flags & 4) {
            D_003E2718[D_0039409C] = D_00394274;
            D_0039409C++;
        }
        Tag(0x10000000, 0xFE000000);
        Put((unsigned short)D_00394280 | 0x03000000);
        Put(0x02000000);
        unsigned int saved = D_00394280;
        D_00394280 = 0;
        func_00164E48(1, (unsigned int)D_378 >> 3);
        func_00164F08(D_003E1640);
        if (vp->flags & 2) {
            func_00164F08(D_003E15E0);
            func_00164F08(D_003E15F0);
        } else {
            func_00164F08(D_003E1580);
            func_00164F08(D_003E1590);
        }
        func_00164EB8(0);
        func_001645F8(1, 0, 0);
        Reg(D_00394048, 0x18);
        Reg(D_00394050, 0x40);
        func_001646D0(1);
        Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
        D_00394294 = D_00394280;
        CloseTag();
        ((unsigned short*)D_00394278)[1] |= (unsigned short)D_00394280 & 0x3FF;
        D_00394280 += saved;
        if (vp->flags & 4) {
            Tag(0x10000000, 0);
            Put(0);
            Put(0);
        }
        vp->camera = 0;
    }

    void* view = D_00394274;
    if (D_0039427C)
        func_001617A0(0);
    D_00394274 = (unsigned int*)((char*)view + 0xC0);
    func_00166FA8(view);
    Matrix_0017A400 ident;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ident.m[i][j] = (i == j) ? 1.0f : 0.0f;
    func_001671A8(view, &ident);

    Viewport_0017A400* main = D_003942FC;
    main->ready[D_00394094] = 1;
    main->chain[D_00394094] = D_00394274;
    Tag(0x70000000, 0);
    Put(0);
    Put(0);
    Camera_0017A400* cam = func_00167140(D_00394274, view);
    D_00394274 = (unsigned int*)((char*)D_00394274 + 0x170);
    func_00167068(cam);
    func_00168368(cam, D_00394040);
    func_00168120(cam, 16.0f);

    Select(D_003942FC);
    Tag(0x10000001, 0);
    Put(0);
    Put(0x30000000);
    unsigned int* p = D_00394274;
    p[0] = (int)cam->pos[0];
    p[1] = (int)cam->pos[1];
    p[2] = (int)cam->pos[2];
    p[3] = 0;
    D_00394274 = p + 4;
    Tag(0x30110012, (unsigned int)cam->data);
    Put((unsigned short)D_00394280 | 0x03000000);
    Put(0x02000000);
    D_00394280 += 0x11;
    D_003942FC->camera = cam;
    Tag(0x10000000, 0);
    func_00164E48(0, (unsigned int)D_380 >> 3);
    func_00164F08(D_003E1580);
    func_00164F08(D_003E1590);
    func_00164EB8(0);
    func_001645F8(0, 0, 0);

    bool pal = D_0038882C == 1;
    Reg(0, 0x3F);                                   /* TEXFLUSH */
    Reg(0, 0x4B);                                   /* FBA_2 */
    Reg(0xE20213E00L, 7);                           /* TEX0_2 */
    Reg(1, 0x15);                                   /* TEX1_2 */
    Reg(5, 9);                                      /* CLAMP_2 */
    Reg((0xFF000000UL << 32) | (pal ? 0xA0000 : 0x80000), 0x4D);   /* FRAME_2: FBMSK 0xFF000000 (alpha) */
    unsigned int height = pal ? 0x280 : 0x200;
    unsigned int width = pal ? 0x280 : 0x200;
    width = pal ? (width * 0x700) >> 13 : width >> 2;
    Reg(((width + (pal ? (height * 0x380) >> 13 : height >> 3)) & 0x1FF) | (0x8080L << 17), 0x4F);
    Reg(D_00394048, 0x19);
    Reg(D_00394050, 0x41);
    Reg(((long)D_0038C030 << 32) | 0x66, 0x43);
    Reg(0x5080B, 0x48);
    Reg(0, 0x1A);
    Reg(0x250, 0x1B);
    func_001646D0(0);
    CloseTag();

    D_0038BC88 = 0;
    D_0038BC8C = 0;
    D_0038BC90 = 0;
    D_0038BC94 = 0;
    D_0038BC98 = 0;
    D_0038BC9C = 0;
    D_0038BCA4 = 0;
    D_0038BCA8 = 0;
    D_0038BCA0 = 0;
    D_0038BCAC = 0;
    D_0038BCB0 = 0;
    D_0038BCB4 = 0;
    D_0038BCB8 = 0;
    D_0038BCBC = 0;
    D_0038BCC0 = 0;
    D_0038BCC4 = 0;
    D_0038BCC8 = 0;
    D_0038BCCC = 0;
    D_0038BCD0 = 0;
    if (!skipList)
        func_0016DCB8(D_003E0FE0, view, 6);

    Select(D_003942FC);
    Tag(0x10000000, 0);
    func_001645F8(0, 0, 0);
    Reg(1, 0x1A);
    func_001646D0(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    CloseTag();
}
