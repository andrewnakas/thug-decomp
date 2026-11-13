/* fuzzy: 99.1 */
// Sets up a VU1 rendering pass: transforms three sets of clip planes by the current view matrix and keeps
// them (and their absolute values) in VU0 registers vf10-vf30, then builds the DMA/VIF packet that uploads
// the VU1 microprogram, sets the GS registers for the pass and starts it.

typedef int qword __attribute__((mode(TI)));

struct Vec_0017CD90 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_0017CD90 {
    Vec_0017CD90 row[4];
    Mat_0017CD90() {}
    const Vec_0017CD90& operator[](int i) const { return row[i]; }
    Mat_0017CD90(const Mat_0017CD90& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
    }
    Mat_0017CD90& operator=(const Mat_0017CD90& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
    Mat_0017CD90 operator*(Mat_0017CD90& b);
};

extern Mat_0017CD90 D_003E1080;
extern float D_00394058;
extern float D_0039405C;
extern float D_00394060;
extern float D_00394064;
extern float D_00394070;
extern float D_00394074;
extern float D_00394078;
extern float D_0039407C;
extern int D_00394298;
extern int D_0039427C;
extern unsigned char* D_00394274;     // packet write cursor
extern unsigned int* D_00394278;      // last DMA tag
extern unsigned short* D_00394288;    // last VIF DIRECT code
// 32-bit: the game copies it whole (0017D39C lw $v1, D_00394280; 0017D3A4 sw $v1, D_00394294) and reads
// the low half for the VIF code (0017D2B8 lhu $v0, D_00394280)
extern unsigned int D_00394280;
extern int D_00394290;
extern int D_00394294;
extern unsigned long D_00394050;
extern unsigned long D_00394048;
extern int D_0038882C;
extern unsigned char D_0034CB80[];
extern unsigned char D_0034D280[];

extern "C" void func_00323318(Mat_0017CD90* dst, const Mat_0017CD90* a, const Mat_0017CD90* b);
extern "C" void func_001617A0(int a);
extern "C" void func_001644E8(int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_001647B0(int reg, unsigned long value);
extern "C" void func_00164F48(void* a);
extern unsigned char D_003E1180[];

// Single VU0 macro-mode operations (the vector unit has no C++ spelling).
static inline void SetVF31One() { __asm__ __volatile__("vmaxw.xyzw $vf31, $vf0, $vf0w"); }
static inline void LoadVF10(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf10, 0(%0)" : : "r"(p)); }
static inline void LoadVF11(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf11, 0(%0)" : : "r"(p)); }
static inline void LoadVF12(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf12, 0(%0)" : : "r"(p)); }
static inline void LoadVF16(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf16, 0(%0)" : : "r"(p)); }
static inline void LoadVF17(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf17, 0(%0)" : : "r"(p)); }
static inline void LoadVF18(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf18, 0(%0)" : : "r"(p)); }
static inline void LoadVF19(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf19, 0(%0)" : : "r"(p)); }
static inline void LoadVF23(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf23, 0(%0)" : : "r"(p)); }
static inline void LoadVF24(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf24, 0(%0)" : : "r"(p)); }
static inline void LoadVF25(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf25, 0(%0)" : : "r"(p)); }
static inline void LoadVF26(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf26, 0(%0)" : : "r"(p)); }
static inline void LoadVF30(const Vec_0017CD90* p) { __asm__ __volatile__("lqc2 $vf30, 0(%0)" : : "r"(p)); }
static inline void AbsVF13() { __asm__ __volatile__("vabs.xyzw $vf13, $vf10"); }
static inline void AbsVF14() { __asm__ __volatile__("vabs.xyzw $vf14, $vf11"); }
static inline void AbsVF15() { __asm__ __volatile__("vabs.xyzw $vf15, $vf12"); }
static inline void AbsVF20() { __asm__ __volatile__("vabs.xyzw $vf20, $vf17"); }
static inline void AbsVF21() { __asm__ __volatile__("vabs.xyzw $vf21, $vf18"); }
static inline void AbsVF22() { __asm__ __volatile__("vabs.xyzw $vf22, $vf19"); }
static inline void AbsVF27() { __asm__ __volatile__("vabs.xyzw $vf27, $vf24"); }
static inline void AbsVF28() { __asm__ __volatile__("vabs.xyzw $vf28, $vf25"); }
static inline void AbsVF29() { __asm__ __volatile__("vabs.xyzw $vf29, $vf26"); }

inline Mat_0017CD90 Mat_0017CD90::operator*(Mat_0017CD90& b)
{
    Mat_0017CD90 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

// four planes of a frustum with half-extents (sx, sy) and depth range (z0, z1), all through the origin
static inline void Frustum_0017CD90(Vec_0017CD90* r0, Vec_0017CD90* r1, Vec_0017CD90* r2, Vec_0017CD90* r3,
                                    const float& sx, const float& sy, const float& z0, const float& z1)
{
    r0->Set(-sx, sx, 0.0f, 0.0f);
    r1->Set(0.0f, 0.0f, sy, -sy);
    r2->Set(-z0, -z0, -z1, -z1);
    r3->Set(0.0f, 0.0f, 0.0f, 0.0f);
}

static inline bool IsWide_0017CD90() { return D_0038882C == 1; }

static inline void Pad_0017CD90(unsigned char* end)
{
    while (D_00394274 < end) {
        *D_00394274++ = 0;
    }
}

static inline void Put32_0017CD90(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

extern "C" void func_0017CD90(float nearZ, float farZ)
{
    Mat_0017CD90 m;

    SetVF31One();
    {
        Vec_0017CD90* r1 = &m.row[1];
        Vec_0017CD90* r2 = &m.row[2];
        Vec_0017CD90* r3 = &m.row[3];
        Frustum_0017CD90(&m.row[0], r1, r2, r3, D_00394060, D_00394064, D_00394058, D_0039405C);
        m = D_003E1080 * m;
        LoadVF10(&m.row[0]);
        LoadVF11(r1);
        LoadVF12(r2);
        LoadVF16(r3);
    }
    AbsVF13();
    AbsVF14();
    AbsVF15();

    {
        Vec_0017CD90* r1 = &m.row[1];
        Vec_0017CD90* r2 = &m.row[2];
        Vec_0017CD90* r3 = &m.row[3];
        m.row[0].Set(0.0f, 0.0f, 0.0f, 0.0f);
        r1->Set(0.0f, 0.0f, 0.0f, 0.0f);
        r2->Set(0.0f, 0.0f, -1.0f, 1.0f);
        r3->Set(0.0f, 0.0f, nearZ, -farZ);
        m = D_003E1080 * m;
        LoadVF17(&m.row[0]);
        LoadVF18(r1);
        LoadVF19(r2);
        LoadVF23(r3);
    }
    AbsVF20();
    AbsVF21();
    AbsVF22();

    {
        Vec_0017CD90* r1 = &m.row[1];
        Vec_0017CD90* r2 = &m.row[2];
        Vec_0017CD90* r3 = &m.row[3];
        Frustum_0017CD90(&m.row[0], r1, r2, r3, D_00394078, D_0039407C, D_00394070, D_00394074);
        m = D_003E1080 * m;
        LoadVF24(&m.row[0]);
        LoadVF25(r1);
        LoadVF26(r2);
        LoadVF30(r3);
    }
    AbsVF27();
    AbsVF28();
    AbsVF29();

    if (D_0039427C != D_00394298) {
        func_001617A0(D_00394298);
    }

    // DMA ref tag: the VU1 microprogram, then FLUSHE / MSKPATH3-off codes
    int size = D_0034D280 - D_0034CB80;
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = p;
    p[1] = (unsigned int)D_0034CB80;
    p[0] = ((size + 15) / 16) | 0x30000000;
    D_00394274 = (unsigned char*)(p + 2);
    p[2] = 0x03000000;
    D_00394274 = (unsigned char*)(p + 3);
    p[3] = 0x02000020;
    D_00394274 = (unsigned char*)(p + 4);
    // DMA cnt tag for the GS setup, padded so that the DIRECT code ends a quadword
    unsigned int* t = (unsigned int*)D_00394274;
    D_00394278 = t;
    t[0] = 0x10000000;
    t[1] = 0;
    D_00394274 = (unsigned char*)(t + 2);
    unsigned char* end = (unsigned char*)(((int)t + 15) & ~15) + 12;
    Put32_0017CD90(0x11000000);
    Pad_0017CD90(end);

    unsigned int* direct = (unsigned int*)D_00394274;
    D_00394288 = (unsigned short*)direct;
    *direct = 0x50000000;
    D_00394274 = (unsigned char*)(direct + 1);
    func_001644E8(0xE, 1, 0, 0, 0, 1, 3);
    func_001647B0(0x40, D_00394050);
    func_001647B0(0x18, D_00394048);
    bool wide = IsWide_0017CD90();
    unsigned int h = wide ? 0x280 : 0x200;
    unsigned int w = wide ? 0x280 : 0x200;
    unsigned int ox = wide ? (w * 0x700) >> 13 : w >> 2;
    func_001647B0(0x4E, ((ox + (IsWide_0017CD90() ? (h * 0x380) >> 13 : h >> 3)) & 0x1FF) | 0x101000000L);
    Pad_0017CD90((unsigned char*)(((int)D_00394274 + 15) & ~15));

    // close the DIRECT block, then unpack the constants and start the microprogram
    int bytes = D_00394274 - (unsigned char*)D_00394288 - 4;
    *D_00394288 = bytes / 16;
    Put32_0017CD90(((unsigned short)D_00394280 & 0x3FF) | 0x6C078000);
    D_00394290 = 7;
    func_00164F48(D_003E1180);
    ((float*)D_00394274)[0] = 320.0f;
    ((float*)D_00394274)[1] = 320.0f;
    ((unsigned int*)D_00394274)[2] = 0;
    ((unsigned int*)D_00394274)[3] = 0;
    D_00394274 += 16;
    ((unsigned int*)D_00394274)[0] = 0x39005000;
    ((unsigned int*)D_00394274)[1] = 0x39006000;
    ((unsigned int*)D_00394274)[2] = 0;
    ((unsigned int*)D_00394274)[3] = 0x3F800000; // 1.0f, stored as an integer (0017D2F4 lui $t2, 0x3F80; sw $t2)
    D_00394274 += 16;
    ((unsigned int*)D_00394274)[0] = 0x3900B000;
    ((unsigned int*)D_00394274)[1] = 0x3900A000;
    ((unsigned int*)D_00394274)[2] = 0;
    ((unsigned int*)D_00394274)[3] = 0;
    D_00394274 += 16;
    Put32_0017CD90(0x14000008);
    D_00394294 = D_00394280;
    unsigned int id = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (id != 3 && id != 0 && id != 4) {
        *(unsigned short*)D_00394278 = (D_00394274 - (unsigned char*)D_00394278 - 8) >> 4;
    }
    if (D_0039427C) {
        func_001617A0(0);
    }
}
