/* fuzzy: 95.3 */
/* func_0017BAA0: from lane 3 draft work/nm77/wt1 (size matches; remaining differences are scheduling/register allocation). */
extern "C" float sqrtf(float);

typedef int qword_0017BAA0 __attribute__((mode(TI)));

struct Mat_0017BAA0;
struct VecT_0017BAA0;

struct Vec_0017BAA0 {
    union {
        qword_0017BAA0 q;
        struct {
            float x, y, z, w;
        };
    };
    float& operator[](int i) { return (&x)[i]; }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    VecT_0017BAA0 operator-(const Vec_0017BAA0& o) const;
    Vec_0017BAA0 operator*(float k) const
    {
        Vec_0017BAA0 o;
        o.x = x * k;
        o.y = y * k;
        o.z = z * k;
        o.w = w * k;
        return o;
    }
    void Scale(float k)
    {
        x *= k;
        y *= k;
        z *= k;
        w *= k;
    }
};

struct VecT_0017BAA0 : Vec_0017BAA0 {
    VecT_0017BAA0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

inline VecT_0017BAA0 Vec_0017BAA0::operator-(const Vec_0017BAA0& o) const
{
    return VecT_0017BAA0(x - o.x, y - o.y, z - o.z, w);
}

extern "C" void func_00323298(Vec_0017BAA0* out, const Mat_0017BAA0* m, const Vec_0017BAA0* v);
extern "C" void func_00323318(Mat_0017BAA0* d, const Mat_0017BAA0* a, const Mat_0017BAA0* b);

struct Mat_0017BAA0 {
    Vec_0017BAA0 r[4];
    Mat_0017BAA0() {}
    const Vec_0017BAA0& operator[](int i) const { return r[i]; }
    Mat_0017BAA0(const Mat_0017BAA0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0017BAA0& operator=(const Mat_0017BAA0& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    void operator*=(const Mat_0017BAA0& b) { func_00323318(this, &b, this); }
    Mat_0017BAA0 operator*(const Mat_0017BAA0& b) const
    {
        Mat_0017BAA0 t = *this;
        t *= b;
        return t;
    }
    Vec_0017BAA0 operator*(const Vec_0017BAA0& v) const
    {
        Vec_0017BAA0 o;
        func_00323298(&o, this, &v);
        return o;
    }
    void Transpose(const Mat_0017BAA0& s)
    {
        if (&s == this) {
            float a01 = r[0].y, a10 = r[1].x;
            float a02 = r[0].z, a20 = r[2].x;
            float a03 = r[0].w, a30 = r[3].x;
            float a12 = r[1].z, a21 = r[2].y;
            float a13 = r[1].w, a31 = r[3].y;
            float a23 = r[2].w, a32 = r[3].z;
            r[0].y = a10; r[1].x = a01;
            r[0].z = a20; r[2].x = a02;
            r[0].w = a30; r[3].x = a03;
            r[1].z = a21; r[2].y = a12;
            r[1].w = a31; r[3].y = a13;
            r[2].w = a32; r[3].z = a23;
        } else {
            r[0].x = s.r[0].x; r[0].y = s.r[1].x; r[0].z = s.r[2].x; r[0].w = s.r[3].x;
            r[1].x = s.r[0].y; r[1].y = s.r[1].y; r[1].z = s.r[2].y; r[1].w = s.r[3].y;
            r[2].x = s.r[0].z; r[2].y = s.r[1].z; r[2].z = s.r[2].z; r[2].w = s.r[3].z;
            r[3].x = s.r[0].w; r[3].y = s.r[1].w; r[3].z = s.r[2].w; r[3].w = s.r[3].w;
        }
    }
    void InvertOrtho()
    {
        Vec_0017BAA0 t = r[3];
        r[3].x = -(t.x * r[0].x + t.y * r[0].y + t.z * r[0].z);
        r[3].y = -(t.x * r[1].x + t.y * r[1].y + t.z * r[1].z);
        r[3].z = -(t.x * r[2].x + t.y * r[2].y + t.z * r[2].z);
        float a01 = r[0].y;
        float a02 = r[0].z;
        float a12 = r[1].z;
        r[0].y = r[1].x;
        r[0].z = r[2].x;
        r[1].x = a01;
        r[1].z = r[2].y;
        r[2].x = a02;
        r[2].y = a12;
    }
    void Viewport(const Vec_0017BAA0& s, const Vec_0017BAA0& t)
    {
        r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].w = 0.0f;
        r[0].x = s.x; r[1].y = s.y; r[2].z = s.z; r[3].w = s.w;
        r[3].x = t.x; r[3].y = t.y; r[3].z = t.z;
    }
};

struct Rect_0017BAA0 {
    int m0;
    float x, y, w, h;
    float GetX() const { return x; }
    float GetY() const { return y; }
    float GetW() const { return w; }
    float GetH() const { return h; }
};

extern int D_0038882C;
extern int D_0038C018;
extern int D_0038C01C;
extern float D_0038C020;
extern float D_0038C024;
extern int D_0038C028;
extern int D_0038C02C;
extern long D_00394048;
extern long D_00394050;
extern float D_00394058;
extern float D_0039405C;
extern float D_00394060;
extern float D_00394064;
extern float D_00394068;
extern float D_0039406C;
extern float D_00394070;
extern float D_00394074;
extern float D_00394078;
extern float D_0039407C;
extern float D_00394080;
extern float D_00394084;
extern float D_00394088;
extern float D_0039408C;
extern int D_00394090;
extern int D_00394098;
extern int* D_003940A8;
extern float D_003940AC;
extern Mat_0017BAA0 D_003E1080;
extern Mat_0017BAA0 D_003E10C0;
extern Mat_0017BAA0 D_003E1100;
extern Mat_0017BAA0 D_003E1140;
extern Mat_0017BAA0 D_003E1180;
extern Mat_0017BAA0 D_003E11C0;
extern Mat_0017BAA0 D_003E1200;
extern Mat_0017BAA0 D_003E1240;
extern Mat_0017BAA0 D_003E1280;
extern Mat_0017BAA0 D_003E12C0;
extern Mat_0017BAA0 D_003E1300;
extern Mat_0017BAA0 D_003E1340;
extern Mat_0017BAA0 D_003E1380;
extern Mat_0017BAA0 D_003E13C0;
extern Mat_0017BAA0 D_003E1400;
extern Mat_0017BAA0 D_003E1440;
extern Mat_0017BAA0 D_003E1480;
extern Mat_0017BAA0 D_003E14C0;
extern Mat_0017BAA0 D_003E1500;
extern Vec_0017BAA0 D_003E1540;
extern Vec_0017BAA0 D_003E1550;
extern Vec_0017BAA0 D_003E1560;
extern Vec_0017BAA0 D_003E1570;
extern Vec_0017BAA0 D_003E1580;
extern Vec_0017BAA0 D_003E1590;
extern Vec_0017BAA0 D_003E15A0;
extern Vec_0017BAA0 D_003E15B0;
extern Vec_0017BAA0 D_003E15C0;
extern Vec_0017BAA0 D_003E15D0;
extern Vec_0017BAA0 D_003E15E0;
extern Vec_0017BAA0 D_003E15F0;
extern Vec_0017BAA0 D_003E1600;
extern Vec_0017BAA0 D_003E1610;
extern Vec_0017BAA0 D_003E1620;
extern Vec_0017BAA0 D_003E1640;
extern int D_003E26F8[4];
extern int D_003E2708[4];

extern "C" bool func_0017D438(int id);
extern "C" float func_00341158(float x);
extern "C" float func_00341618(float b, float e);

static inline bool IsMode1_0017BAA0()
{
    return D_0038882C == 1;
}

#define HW_0017BAA0 (IsMode1_0017BAA0() ? 320.0f : 256.0f)
#define HH_0017BAA0 (IsMode1_0017BAA0() ? 224.0f : 256.0f)
#define FW_0017BAA0 (IsMode1_0017BAA0() ? 640.0f : 512.0f)
#define FH_0017BAA0 (IsMode1_0017BAA0() ? 448.0f : 512.0f)

static inline void Mul_0017BAA0(Vec_0017BAA0& o, const Vec_0017BAA0& a, float k)
{
    o.x = a.x * k;
    o.y = a.y * k;
    o.z = a.z * k;
    o.w = a.w * k;
}

static inline void InvVp_0017BAA0(Vec_0017BAA0& is, Vec_0017BAA0& it, const Vec_0017BAA0& s, const Vec_0017BAA0& t)
{
    is.x = 1.0f / s.x;
    is.y = 1.0f / s.y;
    is.z = 1.0f / s.z;
    is.w = 1.0f / s.w;
    it.x = -is.x * t.x * is.w;
    it.y = -is.y * t.y * is.w;
    it.z = -is.z * t.z * is.w;
}

extern "C" void func_0017BAA0(int id, const Mat_0017BAA0* cam, const Rect_0017BAA0* vp, float fov, float aspect,
                              float nearz, float farz)
{
    float v = D_0038C024;
    D_003940AC = v;
    if (v < 0.003f) {
        D_003940AC = 0.003f;
    }
    if (0.997f < v) {
        D_003940AC = 0.997f;
    }
    if (!D_0038C02C) {
        D_003940AC = 0.75f;
    }
    *D_003940A8 = D_0038C028;
    if (func_0017D438(id)) {
        return;
    }
    D_003E11C0 = *cam;
    D_003E1200 = D_003E11C0;
    Vec_0017BAA0& r3 = D_003E1200.r[3];
    r3.x = 0.0f;
    r3.y = 0.0f;
    r3.z = 0.0f;
    r3.w = 1.0f;
    D_003E10C0.Transpose(D_003E1200);
    D_003E1080 = D_003E11C0;
    D_003E1080.InvertOrtho();
    D_003E1600 = D_003E1200 * VecT_0017BAA0(D_003E1080.r[3].x * 16.0f, D_003E1080.r[3].y * 16.0f,
                                           D_003E1080.r[3].z * 16.0f, D_003E1080.r[3].w * 16.0f);
    D_003E1610.x = (float)(int)D_003E1600.x;
    D_003E1610.y = (float)(int)D_003E1600.y;
    D_003E1610.z = (float)(int)D_003E1600.z;
    D_003E1610.w = 0.0f;
    D_003E1620 = D_003E1600 - D_003E1610;
    D_003E1620.w = D_003E1610.w;
    D_003E1340 = D_003E1080;
    D_003E1340.r[3] = D_003E10C0 * D_003E1620;
    D_003E1340.r[3].Scale(0.0625f);
    D_003E1340.r[3].w = 1.0f;

    float t = func_00341158(fov * 0.008726646f);
    D_00394068 = t;
    float u = -(t / aspect);
    D_00394088 = nearz;
    D_0039408C = farz;
    D_0039406C = u;
    D_00394060 = 1.0f / sqrtf(t * t + 1.0f);
    D_00394058 = 1.0f / sqrtf(1.0f / (t * t) + 1.0f);
    D_00394064 = 1.0f / sqrtf(u * u + 1.0f);
    D_0039405C = 1.0f / sqrtf(1.0f / (u * u) + 1.0f);
    D_00394080 = t * (620.0f / (vp->GetW() * HW_0017BAA0));
    D_00394084 = D_0039406C * (524.0f / (vp->GetH() * HH_0017BAA0));
    D_00394070 = 1.0f / sqrtf(1.0f / (D_00394080 * D_00394080) + 1.0f);
    D_00394074 = 1.0f / sqrtf(1.0f / (D_00394084 * D_00394084) + 1.0f);
    D_00394078 = 1.0f / sqrtf(D_00394080 * D_00394080 + 1.0f);
    D_0039407C = 1.0f / sqrtf(D_00394084 * D_00394084 + 1.0f);

    Mat_0017BAA0& pm = D_003E1240;
    pm.r[0].x = 1.0f / D_00394080;
    pm.r[0].y = 0.0f;
    pm.r[0].z = 0.0f;
    pm.r[0].w = 0.0f;
    pm.r[1].x = 0.0f;
    pm.r[1].y = 1.0f / D_00394084;
    pm.r[1].z = 0.0f;
    pm.r[1].w = 0.0f;
    pm.r[2].x = 0.0f;
    pm.r[2].y = 0.0f;
    pm.r[2].z = (nearz + farz) / (farz - nearz);
    pm.r[2].w = -1.0f;
    pm.r[3].x = 0.0f;
    pm.r[3].y = 0.0f;
    pm.r[3].z = (nearz + nearz) * farz / (nearz - farz);
    pm.r[3].w = 0.0f;
    D_003E1380 = D_003E1340 * D_003E1240;
    D_003E1100 = D_003E1080 * D_003E1240;

    D_003E1540.Set(620.0f, 524.0f, func_00341618(2.0f, 22.0f) * 0.999f, D_003940AC);
    D_003E1550.Set(2048.0f, 2048.0f, func_00341618(2.0f, 23.0f) * 1.5f, 0.0f);
    D_003E1560.Set(620.0f, 524.0f, func_00341618(2.0f, -95.0f) * 0.999f, func_00341618(2.0f, 32.0f));
    D_003E1570.Set(func_00341618(2.0f, 19.0f) + 2048.0f, func_00341618(2.0f, 19.0f) + 2048.0f,
                   func_00341618(2.0f, -94.0f) * 1.5f, func_00341618(2.0f, -32.0f));

    D_003E12C0.Viewport(D_003E1540, D_003E1550);
    D_003E13C0 = D_003E1380 * D_003E12C0;
    D_003E1140 = D_003E1100 * D_003E12C0;
    D_003E1280 = D_003E1240 * D_003E12C0;
    D_003E1300.Viewport(D_003E1560, D_003E1570);
    D_003E1400 = D_003E1380 * D_003E1300;
    D_003E1180 = D_003E1100 * D_003E1300;
    D_003E1440 = D_003E1340;
    D_003E1440.r[3].x = 0.0f;
    D_003E1440.r[3].y = 0.0f;
    D_003E1440.r[3].z = 0.0f;
    D_003E15C0.Set(620.0f, 524.0f, 0.01f, D_003940AC);
    D_003E15D0.Set(2048.0f, 2048.0f, 1.0f, 0.0f);
    D_003E1480 = D_003E1440 * D_003E1240;
    D_003E1500 = D_003E12C0;
    D_003E1500.r[2].z = D_003E15C0.z;
    D_003E1500.r[3].z = D_003E15D0.z;
    D_003E14C0 = D_003E1480 * D_003E1500;

    D_003E1640[0] = D_00394088;
    D_003E1640[1] = D_0039408C;
    D_003E1640[2] = 620.0f / (vp->GetW() * HW_0017BAA0);
    D_003E1640[3] = 524.0f / (vp->GetH() * HH_0017BAA0);

    InvVp_0017BAA0(D_003E1580, D_003E1590, D_003E1540, D_003E1550);
    D_003E1590.w = D_0038C020;
    InvVp_0017BAA0(D_003E15A0, D_003E15B0, D_003E1560, D_003E1570);
    D_003E15B0.w = 0.0f;
    InvVp_0017BAA0(D_003E15E0, D_003E15F0, D_003E15C0, D_003E15D0);
    D_003E15F0.w = 0.0f;

    float cy = vp->GetY() + vp->GetH() * 0.5f;
    float cx = vp->GetX() + vp->GetW() * 0.5f;
    D_00394048 = (long)((int)((2048.0f - cx * FW_0017BAA0) * 16.0f) & 0xFFFF) |
                 ((long)((int)((2048.0f - cy * FH_0017BAA0) * 16.0f) & 0xFFFF) << 32);
    float y1 = vp->GetY() + vp->GetH();
    float x1 = vp->GetX() + vp->GetW();
    D_00394050 = (long)((int)(vp->GetX() * FW_0017BAA0) & 0x7FF) | ((long)(((int)(x1 * FW_0017BAA0) - 1) & 0x7FF) << 16) |
                 ((long)((int)(vp->GetY() * FH_0017BAA0) & 0x7FF) << 32) |
                 ((long)(((int)(y1 * FH_0017BAA0) - 1) & 0x7FF) << 48);

    Vec_0017BAA0 c[4];
    c[0].Set(D_00394068 * farz, D_0039406C * farz, farz, 1.0f);
    func_00323298(&c[0], &D_003E11C0, &c[0]);
    c[1].Set(-D_00394068 * farz, D_0039406C * farz, farz, 1.0f);
    func_00323298(&c[1], &D_003E11C0, &c[1]);
    c[2].Set(D_00394068 * farz, -D_0039406C * farz, farz, 1.0f);
    func_00323298(&c[2], &D_003E11C0, &c[2]);
    c[3].Set(-D_00394068 * farz, -D_0039406C * farz, farz, 1.0f);
    func_00323298(&c[3], &D_003E11C0, &c[3]);
    Vec_0017BAA0 pos = D_003E1080.r[3];
    for (int i = 0; i < 3; i++) {
        D_003E26F8[i] = pos[i] <= c[0][i] && pos[i] <= c[1][i] && pos[i] <= c[2][i] && pos[i] <= c[3][i];
        D_003E2708[i] = c[0][i] <= pos[i] && c[1][i] <= pos[i] && c[2][i] <= pos[i] && c[3][i] <= pos[i];
    }
    D_00394098 = 1 << (id + 24);
    D_0038C01C = id;
    D_0038C018 = D_00394090;
}
