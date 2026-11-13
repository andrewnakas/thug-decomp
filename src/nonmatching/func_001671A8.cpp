/* fuzzy: 79.6 */
typedef int qword_001671A8 __attribute__((mode(TI)));

struct R_001671A8 {
    union {
        qword_001671A8 q;
        struct {
            float x, y, z, w;
        };
    };
};

struct V_001671A8 {
    union {
        qword_001671A8 q;
        struct {
            float x, y, z, w;
        };
    };
    V_001671A8() {}
    V_001671A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline V_001671A8 operator-(const V_001671A8& a)
{
    return V_001671A8(-a.x, -a.y, -a.z, -a.w);
}

static inline V_001671A8 operator-(const R_001671A8& a)
{
    return V_001671A8(-a.x, -a.y, -a.z, -a.w);
}

static inline V_001671A8 operator*(const V_001671A8& a, float s)
{
    return V_001671A8(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct M_001671A8;
extern "C" void func_00323298(V_001671A8* out, M_001671A8* m, const V_001671A8* v);

struct M_001671A8 {
    R_001671A8 r[4];
    M_001671A8& operator=(const M_001671A8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    /* inverse of a rigid transform: transpose the rotation, rotate and negate the translation */
    V_001671A8 Xform(const V_001671A8& v)
    {
        V_001671A8 out;
        func_00323298(&out, this, &v);
        return out;
    }
    void InvertOrtho()
    {
        R_001671A8 t = r[3];
        float dx = t.x * r[0].x + t.y * r[0].y + t.z * r[0].z;
        float dy = t.x * r[1].x + t.y * r[1].y + t.z * r[1].z;
        float dz = t.x * r[2].x + t.y * r[2].y + t.z * r[2].z;
        float f;
        f = r[0].y; r[0].y = r[1].x; r[1].x = f;
        f = r[0].z; r[0].z = r[2].x; r[2].x = f;
        f = r[1].z; r[1].z = r[2].y; r[2].y = f;
        r[3].x = -dx;
        r[3].y = -dy;
        r[3].z = -dz;
    }
};

extern "C" void func_00323318(M_001671A8* out, void* a, M_001671A8* b);
extern char D_003E1080[];
extern char D_003E1240[];
extern char D_003E12C0[];

struct Obj_001671A8 {
    M_001671A8 m_world;     /* 0x00 */
    V_001671A8 m_pos;       /* 0x40, position * 16 snapped to integers */
    unsigned int m_flags;   /* 0x50 */
    char pad54[0x70 - 0x54];
    M_001671A8 m_view;      /* 0x70 */
    void SetMatrix(M_001671A8* src);
};

extern "C" void func_00167A50(Obj_001671A8* self);

void Obj_001671A8::SetMatrix(M_001671A8* src)
{
    M_001671A8 inv;
    {
        M_001671A8 m;
        M_001671A8* pm = &m;
        *pm = *src;
        func_00323318(pm, D_003E1080, pm);
        inv = m;
        m_world = m;
    }
    inv.InvertOrtho();
    m_pos = -inv.r[3] * 16.0f;
    m_pos.x = (float)(int)m_pos.x;
    m_pos.y = (float)(int)m_pos.y;
    m_pos.z = (float)(int)m_pos.z;

    M_001671A8 m;
    m = m_world;
    m.r[3].q = (m_world.Xform(V_001671A8(-m_pos.x, -m_pos.y, -m_pos.z, -m_pos.w)) * 0.0625f).q;
    M_001671A8 tmp;
    func_00323318(&tmp, D_003E1240, &m);
    func_00323318(&m_view, D_003E12C0, &tmp);
    if (m_flags & 1)
        func_00167A50(this);
}
