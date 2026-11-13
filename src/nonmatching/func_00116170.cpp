/* fuzzy: 98.6 */
extern "C" float sqrtf(float);

typedef int qword_00116170 __attribute__((mode(TI)));

struct RotKey_00116170 {
    int m_time : 15;
    int m_rest : 17;
    float x, y, z;
};

struct CKey_00116170 {
    unsigned short m_time;
    short x, y, z;
    short pad[4];
};

struct TransKey_00116170 {
    short m_time;
    short pad;
    float x, y, z;
};

struct Quat_00116170 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_00116170 q;
    };
    Quat_00116170()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
    Quat_00116170(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Quat_00116170 operator-() const { return Quat_00116170(-x, -y, -z, -w); }
    float& operator[](int i) { return (&x)[i]; }
};

static inline float TransScale_00116170()
{
    return 32.0f;
}

struct Vec_00116170 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_00116170 q;
    };
    Vec_00116170() {}
    float& operator[](int i) { return (&x)[i]; }
    Vec_00116170(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_00116170 operator-(const Vec_00116170& a, const Vec_00116170& b)
{
    return Vec_00116170(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_00116170 operator+(const Vec_00116170& a, const Vec_00116170& b)
{
    return Vec_00116170(b.x + a.x, b.y + a.y, b.z + a.z, b.w + a.w);
}

static inline Vec_00116170 operator*(const Vec_00116170& a, float s)
{
    return Vec_00116170(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Anim_00116170 {
    int m0;
    int m4;
    int m_numBones;
    int padC[3];
    RotKey_00116170* m_rot;
    TransKey_00116170* m_trans;
    int m20;
};

extern "C" int func_00115C68(Anim_00116170* a, int b, int i);
extern "C" int func_00115C98(Anim_00116170* a, int b, int i);
extern "C" int func_00115CC8(Anim_00116170* a);

static inline float Max_00116170(float a, float b)
{
    return a > b ? a : b;
}

static inline void GetRot(Quat_00116170& q, RotKey_00116170* k, int raw)
{
    if (raw) {
        q.x = k->x;
        q.y = k->y;
        q.z = k->z;
    } else {
        CKey_00116170* c = (CKey_00116170*)k;
        q.x = (float)c->x * 0.00006103515625f;
        q.y = (float)c->y * 0.00006103515625f;
        q.z = (float)c->z * 0.00006103515625f;
    }
    q.w = sqrtf(Max_00116170(0.0f, 1.0f - q.x * q.x - q.y * q.y - q.z * q.z));
    if (((CKey_00116170*)k)->m_time & 0x8000) {
        q[3] = -q[3];
    }
}

static inline Quat_00116170 Lerp(const Quat_00116170& a, Quat_00116170& b, float t)
{
    if (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w < 0.0f) {
        b = -b;
    }
    b.x = a.x + (b.x - a.x) * t;
    b.y = a.y + (b.y - a.y) * t;
    b.z = a.z + (b.z - a.z) * t;
    b.w = a.w + (b.w - a.w) * t;
    float inv = 1.0f / sqrtf(b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w);
    b.x *= inv;
    b.y *= inv;
    b.z *= inv;
    b.w *= inv;
    return b;
}

static inline void SampleRot(Quat_00116170* rot, RotKey_00116170* r0, RotKey_00116170* r1, float rfrac, int raw)
{
    if (rfrac == 0.0f) {
        GetRot(*rot, r0, raw);
    } else if (rfrac == 1.0f) {
        GetRot(*rot, r1, raw);
    } else {
        Quat_00116170 a;
        Quat_00116170 b;
        GetRot(a, r0, raw);
        GetRot(b, r1, raw);
        *rot = Lerp(a, b, rfrac);
    }
}

static inline void GetTrans(Vec_00116170& v, TransKey_00116170* k, int raw)
{
    if (raw) {
        v[0] = k->x;
        v[1] = k->y;
        v[2] = k->z;
        v[3] = 1.0f;
    } else {
        CKey_00116170* c = (CKey_00116170*)k;
        v[0] = (float)c->x / TransScale_00116170();
        v[1] = (float)c->y / TransScale_00116170();
        v[2] = (float)c->z / TransScale_00116170();
        v[3] = 1.0f;
    }
}

static inline void SampleTrans(Vec_00116170* trans, TransKey_00116170* t0, TransKey_00116170* t1, float tfrac, int raw)
{
    if (tfrac == 0.0f) {
        GetTrans(*trans, t0, raw);
    } else if (tfrac == 1.0f) {
        GetTrans(*trans, t1, raw);
    } else {
        Vec_00116170 a;
        Vec_00116170 b;
        GetTrans(a, t0, raw);
        GetTrans(b, t1, raw);
        *trans = (b - a) * tfrac + a;
    }
}

extern "C" int func_00116170(Anim_00116170* anim, Quat_00116170* rot, Vec_00116170* trans, float time)
{
    float t = time * 60.0f;
    float tfrac = 0.0f;
    float rfrac = tfrac;
    TransKey_00116170* t0;
    TransKey_00116170* t1;
    RotKey_00116170* r0;
    RotKey_00116170* r1;
    RotKey_00116170* rkeys = r0 = r1 = anim->m_rot;
    TransKey_00116170* tkeys = t0 = t1 = anim->m_trans;
    int id = anim->m20;
    for (int i = 0; i < anim->m_numBones; i++) {
        int nrot = func_00115C68(anim, id, i);
        int ntrans = func_00115C98(anim, id, i);
        int j;
        for (j = 0; j < nrot; j++) {
            if (j == nrot - 1) {
                r1 = r0 = &rkeys[j];
                rfrac = 0.0f;
                break;
            }
            if (rkeys[j].m_time <= t && t <= rkeys[j + 1].m_time) {
                rfrac = (t - (float)rkeys[j].m_time) / ((float)rkeys[j + 1].m_time - (float)rkeys[j].m_time);
                r0 = &rkeys[j];
                r1 = r0 + 1;
                break;
            }
        }
        SampleRot(rot, r0, r1, rfrac, func_00115CC8(anim));
        for (j = 0; j < ntrans; j++) {
            if (j == ntrans - 1) {
                t1 = t0 = &tkeys[j];
                tfrac = 0.0f;
                break;
            }
            if (tkeys[j].m_time <= t && t <= tkeys[j + 1].m_time) {
                tfrac = (t - (float)tkeys[j].m_time) / ((float)tkeys[j + 1].m_time - (float)tkeys[j].m_time);
                t0 = &tkeys[j];
                t1 = t0 + 1;
                break;
            }
        }
        SampleTrans(trans, t0, t1, tfrac, func_00115CC8(anim));
        rkeys += nrot;
        tkeys += ntrans;
        rot++;
        trans++;
    }
    return 1;
}
