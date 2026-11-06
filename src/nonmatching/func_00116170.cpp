/* fuzzy: 58.4 */
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
};

struct Vec_00116170 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_00116170 q;
    };
    Vec_00116170() {}
    Vec_00116170(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Decode(TransKey_00116170* k, int raw, float scale)
    {
        if (raw) {
            x = k->x;
            y = k->y;
            z = k->z;
            w = 1.0f;
        } else {
            CKey_00116170* c = (CKey_00116170*)k;
            x = (float)c->x / scale;
            y = (float)c->y / scale;
            z = (float)c->z / scale;
            w = 1.0f;
        }
    }
    Vec_00116170 operator-(const Vec_00116170& o) const { return Vec_00116170(x - o.x, y - o.y, z - o.z, w - o.w); }
    Vec_00116170 operator+(const Vec_00116170& o) const { return Vec_00116170(x + o.x, y + o.y, z + o.z, w + o.w); }
    Vec_00116170 operator*(float s) const { return Vec_00116170(x * s, y * s, z * s, w * s); }
};

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
    q.w = sqrtf(Max_00116170(1.0f - q.x * q.x - q.y * q.y - q.z * q.z, 0.0f));
    if (((CKey_00116170*)k)->m_time & 0x8000) {
        q.w = -q.w;
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

static inline void SampleTrans(Vec_00116170* trans, TransKey_00116170* t0, TransKey_00116170* t1, float tfrac, int raw, float scale)
{
    if (tfrac == 0.0f) {
        trans->Decode(t0, raw, scale);
    } else if (tfrac == 1.0f) {
        trans->Decode(t1, raw, scale);
    } else {
        Vec_00116170 a;
        Vec_00116170 b;
        a.Decode(t0, raw, scale);
        b.Decode(t1, raw, scale);
        *trans = (b - a) * tfrac + a;
    }
}

extern "C" int func_00116170(Anim_00116170* anim, Quat_00116170* rot, Vec_00116170* trans, float time)
{
    float t = time * 60.0f;
    float tfrac = 0.0f;
    float rfrac = tfrac;
    TransKey_00116170* tkeys = anim->m_trans;
    RotKey_00116170* rkeys = anim->m_rot;
    int id = anim->m20;
    RotKey_00116170* r0 = rkeys;
    RotKey_00116170* r1 = rkeys;
    TransKey_00116170* t0 = tkeys;
    TransKey_00116170* t1 = tkeys;
    for (int i = 0; i < anim->m_numBones; i++) {
        float scale = 32.0f;
        int nrot = func_00115C68(anim, id, i);
        int ntrans = func_00115C98(anim, id, i);
        int j;
        for (j = 0; j < nrot; j++) {
            if (j == nrot - 1) {
                r0 = r1 = &rkeys[j];
                rfrac = 0.0f;
                break;
            }
            RotKey_00116170* k = &rkeys[j];
            RotKey_00116170* n = k + 1;
            if (k->m_time <= t && t <= n->m_time) {
                rfrac = (t - (float)k->m_time) / ((float)n->m_time - (float)k->m_time);
                r0 = k;
                r1 = n;
                break;
            }
        }
        SampleRot(rot, r0, r1, rfrac, func_00115CC8(anim));
        for (j = 0; j < ntrans; j++) {
            if (j == ntrans - 1) {
                t0 = t1 = &tkeys[j];
                tfrac = 0.0f;
                break;
            }
            TransKey_00116170* k = &tkeys[j];
            TransKey_00116170* n = k + 1;
            if (k->m_time <= t && t <= n->m_time) {
                tfrac = (t - (float)k->m_time) / ((float)n->m_time - (float)k->m_time);
                t0 = k;
                t1 = n;
                break;
            }
        }
        SampleTrans(trans, t0, t1, tfrac, func_00115CC8(anim), scale);
        rkeys += nrot;
        tkeys += ntrans;
        rot++;
        trans++;
    }
    return 1;
}
