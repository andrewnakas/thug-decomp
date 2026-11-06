/* fuzzy: 84.7 */
/* NEAR MISS (size 0x488 vs 0x498, opdiff 56; was 225): CSE-skip-blocks effect SOLVED by doing the XZ scale through a member using c[i] (unfolded this pointer in the skipped block invalidates all memory); down via Set() with c[i] gives the s2-relative y/w stores. Left: game keeps &f.hit in v0 then s0 (two pseudos) and computes h1 before the 3rd segment; game reloads 6.0 for h2 (mine reuses f21; hoisted 6.0 appears with or without a variable); 3rd/4th query arg order. */
/* sym: __15Feeler_0026A968 = 0x00209240 */
extern "C" float sqrtf(float);
typedef int qword_0026A968 __attribute__((mode(TI)));
union Vec_0026A968 {
    qword_0026A968 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0026A968() {}
    void ScaleXZ(float k)
    {
        c[0] *= k;
        c[2] *= k;
    }
    void ScaleXZ2(float k)
    {
        c[2] *= k;
        c[0] *= k;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    Vec_0026A968(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
};
inline Vec_0026A968 operator*(const Vec_0026A968& a, float k) { return Vec_0026A968(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_0026A968 operator+(const Vec_0026A968& a, const Vec_0026A968& b)
{
    return Vec_0026A968(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_0026A968 operator-(const Vec_0026A968& a, const Vec_0026A968& b)
{
    return Vec_0026A968(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

extern "C" void func_00183CB8(void* obj, void* ref);
struct Ref_0026A968 {
    void* m_obj;
    ~Ref_0026A968()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};
struct Feeler_0026A968 {
    Vec_0026A968 m_start;
    Vec_0026A968 m_end;
    char pad20[0xA0 - 0x20];
    Vec_0026A968 hit;
    Vec_0026A968 normal;
    Ref_0026A968 mC0;
    int mC4[7];
    Feeler_0026A968();
    Vec_0026A968* GetHit() { return &hit; }
};
extern "C" void func_00209380(Feeler_0026A968* f, const Vec_0026A968& s, const Vec_0026A968& e);
extern "C" int func_002093E8(Feeler_0026A968* f, int a, int b);
inline void Swap_0026A968(Vec_0026A968& a, Vec_0026A968& b)
{
    Vec_0026A968 t = a;
    a = b;
    b = t;
}

struct Mgr_0026A968 {
    char pad0[0xAC];
    unsigned int mAC;
};
extern Mgr_0026A968* D_00392808;

extern "C" bool func_0026A968(Vec_0026A968* a, Vec_0026A968* b)
{
    if (D_00392808->mAC == 0xD443A2BC) return true;
    Feeler_0026A968 f;
    Vec_0026A968 mid = (*a + *b) * 0.5f;
    mid = *a + (mid - *a) * 0.5f;
    Vec_0026A968 dir = *b - *a;
    dir[1] = 0.0f;
    float len = sqrtf(dir[0] * dir[0] + dir[2] * dir[2]);
    mid[1] += 6.0f;
    if (0.0f < len) {
        dir.ScaleXZ(7.0f / len);
    }
    float t = dir[0];
    dir[0] = dir[2];
    dir[2] = -t;
    func_00209380(&f, mid + dir, mid - dir);
    if (func_002093E8(&f, 1, 0)) return false;
    Swap_0026A968(f.m_end, f.m_start);
    if (func_002093E8(&f, 1, 0)) return false;
    Vec_0026A968 down;
    down.Set(0.0f, -12.0f, 0.0f, 1.0f);
    func_00209380(&f, mid + dir, mid + dir + down);
    if (!func_002093E8(&f, 1, 0)) return true;
    Vec_0026A968* hit = f.GetHit();
    float h1 = hit->c[1] - (mid[1] - 6.0f);
    func_00209380(&f, mid - dir, mid - dir + down);
    if (!func_002093E8(&f, 1, 0)) return true;
    float h2 = hit->c[1] - (mid[1] - 6.0f);
    if (-1.0f < h1 && -1.0f < h2) return false;
    if (h1 < h2) {
        float s = h1;
        h1 = h2;
        h2 = s;
    }
    if (1.0f < h1 && -2.0f < h2) return false;
    return true;
}
