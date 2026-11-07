/* fuzzy: 71.6 */
/* sym: GetX__13Anim_001177A8Pvi = 0x00115C68 */
/* sym: GetY__13Anim_001177A8Pvi = 0x00115C98 */
/* sym: Test__13Anim_001177A8 = 0x00115CC8 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Quat_001177A8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Quat_001177A8()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
    Quat_001177A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Quat_001177A8 operator-() const { return Quat_001177A8(-x, -y, -z, -w); }
};

struct Vec_001177A8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001177A8() {}
    Vec_001177A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_001177A8 operator-(const Vec_001177A8& a, const Vec_001177A8& b)
{
    return Vec_001177A8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001177A8 operator+(const Vec_001177A8& a, const Vec_001177A8& b)
{
    return Vec_001177A8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001177A8 operator*(const Vec_001177A8& a, float s)
{
    return Vec_001177A8(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct FKey_001177A8 {
    int m0;
    float x, y, z;
};

struct RKey_001177A8 {
    signed short time : 15;
    unsigned short neg : 1;
    short x, y, z;
};

struct TKey_001177A8 {
    short time;
    short x, y, z;
};

static inline void GetRot_001177A8(Quat_001177A8* q, RKey_001177A8* k, int flt)
{
    if (flt) {
        FKey_001177A8* f = (FKey_001177A8*)k;
        q->x = f->x;
        q->y = f->y;
        q->z = f->z;
    } else {
        q->x = k->x * 0.00006103515625f;
        q->y = k->y * 0.00006103515625f;
        q->z = k->z * 0.00006103515625f;
    }
    float w = 1.0f - q->x * q->x - q->y * q->y - q->z * q->z;
    w = sqrtf(w > 0.0f ? w : 0.0f);
    q->w = w;
    if (k->neg)
        q->w = -w;
}

static inline void GetPos_001177A8(Vec_001177A8* v, TKey_001177A8* k, int flt, float div)
{
    if (flt) {
        FKey_001177A8* f = (FKey_001177A8*)k;
        v->x = f->x;
        v->y = f->y;
        v->z = f->z;
    } else {
        v->x = k->x / div;
        v->y = k->y / div;
        v->z = k->z / div;
    }
    v->w = 1.0f;
}

static inline Quat_001177A8 Nlerp_001177A8(const Quat_001177A8& a, Quat_001177A8& b, float t)
{
    if (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w < 0.0f)
        b = -b;
    float x = a.x + (b.x - a.x) * t;
    float y = a.y + (b.y - a.y) * t;
    float z = a.z + (b.z - a.z) * t;
    float w = a.w + (b.w - a.w) * t;
    float inv = 1.0f / sqrtf(x * x + y * y + z * z + w * w);
    b.x = x * inv;
    b.y = y * inv;
    b.z = z * inv;
    b.w = w * inv;
    return b;
}

static inline void InterpPos_001177A8(Vec_001177A8* out, TKey_001177A8* k0, TKey_001177A8* k1, float t, int flt, float scale)
{
    Vec_001177A8 a;
    Vec_001177A8 b;
    GetPos_001177A8(&a, k0, flt, scale);
    GetPos_001177A8(&b, k1, flt, scale);
    *out = a + (b - a) * t;
}

struct Anim_001177A8 {
    int m0;
    unsigned int m4;
    int m8;
    char padC[0x18 - 0xC];
    RKey_001177A8* m18;
    TKey_001177A8* m1C;
    void* m20;
    int GetX(void* data, int i);
    int GetY(void* data, int i);
    bool Test();
    int Sample(Quat_001177A8* rot, Vec_001177A8* pos, float time);
};

extern "C" int func_00116A48(Anim_001177A8* self, Quat_001177A8* rot, Vec_001177A8* pos, float time);

int Anim_001177A8::Sample(Quat_001177A8* rot, Vec_001177A8* pos, float time)
{
    if (m4 & 0x800000)
        return func_00116A48(this, rot, pos, time);
    RKey_001177A8* r0 = m18;
    RKey_001177A8* r1 = m18;
    TKey_001177A8* t0 = m1C;
    TKey_001177A8* t1 = m1C;
    RKey_001177A8* rbase = m18;
    TKey_001177A8* tbase = m1C;
    float rt = 0.0f;
    float tt = 0.0f;
    float ft = time * 60.0f;
    void* counts = m20;
    for (int i = 0; i < m8; i++) {
        int nr = GetX(counts, i);
        int nt = GetY(counts, i);
        for (int j = 0; j < nr; j++) {
            if (j == nr - 1) {
                r0 = r1 = &rbase[j];
                rt = 0.0f;
                break;
            }
            RKey_001177A8* k = &rbase[j];
            RKey_001177A8* n = k + 1;
            float a = k->time;
            if (a <= ft) {
                float b = n->time;
                if (ft <= b) {
                    r0 = k;
                    rt = (ft - a) / (b - a);
                    r1 = n;
                    break;
                }
            }
        }
        int flt = Test();
        if (rt == 0.0f) {
            GetRot_001177A8(rot, r0, flt);
        } else if (rt == 1.0f) {
            GetRot_001177A8(rot, r1, flt);
        } else {
            Quat_001177A8 q0;
            Quat_001177A8 q1;
            GetRot_001177A8(&q0, r0, flt);
            GetRot_001177A8(&q1, r1, flt);
            *rot = Nlerp_001177A8(q0, q1, rt);
        }
        float scale = 32.0f;
        for (int j = 0; j < nt; j++) {
            if (j == nt - 1) {
                t0 = t1 = &tbase[j];
                tt = 0.0f;
                break;
            }
            TKey_001177A8* k = &tbase[j];
            TKey_001177A8* n = k + 1;
            float a = k->time;
            if (a <= ft) {
                float b = n->time;
                if (ft <= b) {
                    t0 = k;
                    tt = (ft - a) / (b - a);
                    t1 = n;
                    break;
                }
            }
        }
        flt = Test();
        if (tt == 0.0f) {
            GetPos_001177A8(pos, t0, flt, scale);
        } else if (tt == 1.0f) {
            GetPos_001177A8(pos, t1, flt, scale);
        } else {
            InterpPos_001177A8(pos, t0, t1, tt, flt, scale);
        }
        rot++;
        pos++;
        rbase += nr;
        tbase += nt;
    }
    return 1;
}
