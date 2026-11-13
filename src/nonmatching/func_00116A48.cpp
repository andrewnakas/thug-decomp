/* fuzzy: 86.1 */
typedef int qword_00116A48 __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct QKey_00116A48 {
    short time : 15;
    unsigned short neg : 1;
    short x, y, z;
};

struct TKey_00116A48 {
    short time;
    short x, y, z;
};

struct Pack_00116A48 {
    short x, y, z, pad;
};

extern Pack_00116A48 D_003BD8E8[];
extern Pack_00116A48 D_003BE0E8[];

struct Quat_00116A48 {
    union {
        qword_00116A48 q;
        struct {
            float x, y, z, w;
        };
    };
    Quat_00116A48() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
    Quat_00116A48(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float& W() { return w; }
    void Decode(const QKey_00116A48& k)
    {
        if (k.x == 0 && k.y == 0 && k.z == 0) {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
            w = 1.0f;
        } else {
            float qx = k.x * (1.0f / 16384.0f);
            float qy = k.y * (1.0f / 16384.0f);
            float qz = k.z * (1.0f / 16384.0f);
            float qw = 1.0f - qx * qx - qy * qy - qz * qz;
            if (qw < 0.0f) {
                qw = 0.0f;
            }
            x = qx;
            y = qy;
            z = qz;
            W() = k.neg ? -sqrtf(qw) : sqrtf(qw);
        }
    }
    Quat_00116A48 operator-() const { return Quat_00116A48(-x, -y, -z, -w); }
};

struct Vec_00116A48 {
    union {
        qword_00116A48 q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_00116A48() {}
    Vec_00116A48(float ax, float ay, float az, float aw = 1.0f) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_00116A48 operator-(const Vec_00116A48& a, const Vec_00116A48& b)
{
    return Vec_00116A48(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
static inline Vec_00116A48 operator+(const Vec_00116A48& a, const Vec_00116A48& b)
{
    return Vec_00116A48(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
static inline Vec_00116A48 operator*(const Vec_00116A48& a, float s)
{
    return Vec_00116A48(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Bits_00116A48 {
    int count;
    unsigned bits[1];
};

struct Ctx_00116A48 {
    char pad0[0xC];
    unsigned char* qpos[64];
    unsigned char* tpos[64];
    char pad20C[0xA0C - 0x20C];
    int enabled;
    unsigned* boneFlags;
    int bit;
};

static inline unsigned char* ReadQKey(QKey_00116A48* k, unsigned char* p)
{
    short raw = p[0] | (p[1] << 8);
    p += 2;
    k->time = raw & 0x3FFF;
    k->neg = (raw & 0x8000) != 0;
    if (raw & 0x4000) {
        if (!(raw & 0x3800)) {
            Pack_00116A48* e = &D_003BD8E8[*p++];
            k->time &= 0x7FF;
            k->x = e->x;
            k->y = e->y;
            k->z = e->z;
        } else {
            if (raw & 0x2000) {
                k->x = *p++;
            } else {
                k->x = p[0] | (p[1] << 8);
                p += 2;
            }
            if (raw & 0x1000) {
                k->y = *p++;
            } else {
                k->y = p[0] | (p[1] << 8);
                p += 2;
            }
            if (raw & 0x800) {
                k->z = *p++;
            } else {
                k->z = p[0] | (p[1] << 8);
                p += 2;
            }
            k->time &= 0x7FF;
        }
    } else {
        k->x = p[0] | (p[1] << 8);
        k->y = p[2] | (p[3] << 8);
        k->z = p[4] | (p[5] << 8);
        p += 6;
    }
    return p;
}

static inline unsigned char* ReadTKey(TKey_00116A48* k, unsigned char* p)
{
    unsigned char b = *p++;
    bool packed = false;
    if (b & 0x80) {
        packed = true;
    }
    if (b & 0x40) {
        k->time = b & 0x3F;
    } else {
        k->time = p[0] | (p[1] << 8);
        p += 2;
    }
    if (packed) {
        Pack_00116A48* e = &D_003BE0E8[*p++];
        k->x = e->x;
        k->y = e->y;
        k->z = e->z;
    } else {
        k->x = p[0] | (p[1] << 8);
        k->y = p[2] | (p[3] << 8);
        k->z = p[4] | (p[5] << 8);
        p += 6;
    }
    return p;
}

static inline Quat_00116A48 Slerp(const Quat_00116A48& a, Quat_00116A48& b, float t)
{
    if (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w < 0.0f) {
        b = -b;
    }
    float x = a.x + (b.x - a.x) * t;
    float y = a.y + (b.y - a.y) * t;
    float w = a.w + (b.w - a.w) * t;
    float z = a.z + (b.z - a.z) * t;
    float r = 1.0f / sqrtf(x * x + y * y + z * z + w * w);
    b.x = x * r;
    b.y = y * r;
    b.z = z * r;
    b.w = w * r;
    return b;
}

static inline void InterpQ(Quat_00116A48* q, const QKey_00116A48& k0, const QKey_00116A48& k1, float f)
{
    if (f == 0.0f) {
        q->Decode(k0);
    } else if (f == 1.0f) {
        q->Decode(k1);
    } else {
        Quat_00116A48 a;
        Quat_00116A48 b;
        a.Decode(k0);
        b.Decode(k1);
        *q = Slerp(a, b, f);
    }
}

static inline void InterpT(Vec_00116A48* t, const TKey_00116A48& j0, const TKey_00116A48& j1, float g, float scale)
{
    if (g == 0.0f) {
        t->x = j0.x / scale;
        t->y = j0.y / scale;
        t->z = j0.z / scale;
        t->w = 1.0f;
    } else if (g == 1.0f) {
        t->x = j1.x / scale;
        t->y = j1.y / scale;
        t->z = j1.z / scale;
        t->w = 1.0f;
    } else {
        Vec_00116A48 a;
        Vec_00116A48 b;
        a.x = j0.x / scale;
        a.y = j0.y / scale;
        a.z = j0.z / scale;
        a.w = 1.0f;
        b.x = j1.x / scale;
        b.y = j1.y / scale;
        b.z = j1.z / scale;
        b.w = 1.0f;
        *t = a + (b - a) * g;
    }
}

struct Anim_00116A48 {
    int m_0;
    unsigned m_flags;
    int m_numBones;
    int m_C;
    int m_10;
    int m_14;
    unsigned char* m_qdata;
    unsigned char* m_tdata;
    int m_20;
    int m_24;
    Bits_00116A48* m_mask;
    int m_2C;
    int m_30;
    unsigned short* m_qsizes;
    unsigned short* m_tsizes;

    bool GetFrame(Quat_00116A48* q, Vec_00116A48* t, Ctx_00116A48* ctx, float time);
};

bool Anim_00116A48::GetFrame(Quat_00116A48* q, Vec_00116A48* t, Ctx_00116A48* ctx, float time)
{
    QKey_00116A48 k0, k1;
    TKey_00116A48 j0, j1;
    QKey_00116A48* pk0 = &k0;
    QKey_00116A48* pk1 = &k1;
    TKey_00116A48* pj0 = &j0;
    TKey_00116A48* pj1 = &j1;
    time *= 60.0f;
    unsigned char* qdata = m_qdata;
    unsigned char* tdata = m_tdata;
    unsigned short* qsizes = m_qsizes;
    unsigned short* tsizes = m_tsizes;
    unsigned mask;
    if (ctx && ctx->enabled) {
        mask = 1 << ctx->bit;
    } else {
        mask = 0;
    }
    for (int i = 0; i < m_numBones; i++) {
        bool skip;
        if (mask) {
            skip = (ctx->boneFlags[i] & mask) != 0;
        } else {
            skip = false;
        }
        if (m_flags & 0x80000) {
            skip = !(m_mask->bits[i / 32] & (1 << i));
        }
        if (!skip) {
            unsigned char* qp = qdata;
            unsigned char* tp = tdata;
            unsigned char* qend = qdata + *qsizes;
            unsigned char* tend = tdata + *tsizes;
            if (ctx && ctx->enabled) {
                qp = ctx->qpos[i];
                tp = ctx->tpos[i];
            }
            float f;
            do {
                if (ctx) {
                    ctx->qpos[i] = qp;
                }
                unsigned char* p = ReadQKey(pk0, qp);
                if (p >= qend) {
                    *pk1 = *pk0;
                    f = 0.0f;
                    goto done_f;
                }
                qp = p;
                ReadQKey(pk1, p);
                if (pk0->time <= time && time <= pk1->time) {
                    break;
                }
            } while (1);
            f = (time - pk0->time) / ((float)pk1->time - (float)pk0->time);
        done_f:
            InterpQ(q, *pk0, *pk1, f);

            float g;
            do {
                if (ctx) {
                    ctx->tpos[i] = tp;
                }
                unsigned char* p = ReadTKey(pj0, tp);
                if (p >= tend) {
                    *pj1 = *pj0;
                    g = 0.0f;
                    goto done_g;
                }
                tp = p;
                ReadTKey(pj1, p);
                if (pj0->time <= time && time <= pj1->time) {
                    break;
                }
            } while (1);
            g = (time - pj0->time) / ((float)pj1->time - (float)pj0->time);
        done_g:
            InterpT(t, *pj0, *pj1, g, 32.0f);
        }
        qdata += *qsizes;
        tdata += *tsizes;
        qsizes++;
        tsizes++;
        t++;
        q++;
    }
    return true;
}
