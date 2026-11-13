/* fuzzy: 97.3 */
typedef int qword_0018B200 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct V_0018B200 {
    union {
        qword_0018B200 q;
        struct {
            float x, y, z, w;
        };
    };
    V_0018B200() {}
    V_0018B200(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline V_0018B200 operator+(const V_0018B200& a, const V_0018B200& b)
{
    return V_0018B200(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline V_0018B200 operator-(const V_0018B200& a, const V_0018B200& b)
{
    return V_0018B200(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V_0018B200 operator*(const V_0018B200& a, float s)
{
    return V_0018B200(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct M_0018B200 {
    V_0018B200 r[4];
};

extern "C" void func_00183CB8(int obj, int* ref);

struct Feeler_0018B200 {
    V_0018B200 m_start;     /* 0x00 */
    V_0018B200 m_end;       /* 0x10 */
    char pad20[0x90 - 0x20];
    float m_dist;           /* 0x90 */
    char pad94[0xA0 - 0x94];
    V_0018B200 m_point;     /* 0xA0 */
    V_0018B200 m_normal;    /* 0xB0 */
    int m_ref;              /* 0xC0 */
    char padC4[0xE0 - 0xC4];
    ~Feeler_0018B200()
    {
        if (m_ref) {
            func_00183CB8(m_ref, &m_ref);
            m_ref = 0;
        }
    }
};

extern "C" Feeler_0018B200* func_00209240(Feeler_0018B200* f);
extern "C" void func_00209350(Feeler_0018B200* f, int ignore, int flags);
extern "C" void func_00209380(Feeler_0018B200* f, const V_0018B200& start, const V_0018B200& end);
extern "C" bool func_002093E8(Feeler_0018B200* f, int a, int b);
extern "C" bool func_002099C0(Feeler_0018B200* f, V_0018B200* pos, V_0018B200* to, int a);
extern "C" void func_003233B8(V_0018B200* dst, V_0018B200* src);

/* pushes `pos` back from walls along the move from `old`, then probes sideways (along the matrix's X axis) and,
   when `face` is set and a side wall was hit, re-orients the matrix to look at `target` */
extern "C" void func_0018B200(V_0018B200* pos, M_0018B200* m, V_0018B200* old, V_0018B200* target, int side, int face)
{
    V_0018B200 dir = *pos - *old;
    func_003233B8(&dir, &dir);

    Feeler_0018B200 f;
    func_00209240(&f);
    func_00209350(&f, 0x90, 0);
    func_00209380(&f, *old, *pos + dir * 2.0f);
    if (func_002093E8(&f, 1, 0)) {
        float len = (f.m_end - f.m_start).Length();
        float t = f.m_dist;
        if (len * t < 13.9f)
            t = 13.9f / len;
        float back = t * len - 2.0f;
        *pos = *old + dir * back;
    }
    if (side) {
        bool hit;
        V_0018B200 a;
        a.x = m->r[0].x;
        a.y = 0.0f;
        a.z = m->r[0].z;
        a.w = 0.0f;
        float dist = 8.0f;
        float l = sqrtf(a.x * a.x + a.z * a.z);
        if (a.y < l) {
            float k = dist / l;
            a.z = a.z * k;
            a.x = a.x * k;
        }
        a.x += pos->x;
        a.y += pos->y;
        a.z += pos->z;
        a.w += pos->w;
        hit = func_002099C0(&f, pos, &a, 1);
        if (hit) {
            a.x -= f.m_point.x;
            a.y -= f.m_point.y;
            a.z -= f.m_point.z;
            a.w -= f.m_point.w;
            pos->x -= a.x;
            pos->y -= a.y;
            pos->z -= a.z;
            pos->w -= a.w;
        } else {
            V_0018B200 b;
            b.x = -m->r[0].x;
            b.y = 0.0f;
            b.z = -m->r[0].z;
            b.w = 0.0f;
            float l2 = sqrtf(b.x * b.x + b.z * b.z);
            if (0.0f < l2) {
                float k = dist / l2;
                b.z = b.z * k;
                b.x = b.x * k;
            }
            b.x += pos->x;
            b.y += pos->y;
            b.z += pos->z;
            b.w += pos->w;
            hit = func_002099C0(&f, pos, &b, 1);
            if (hit) {
                b.x -= f.m_point.x;
                b.y -= f.m_point.y;
                b.z -= f.m_point.z;
                b.w -= f.m_point.w;
                pos->x -= b.x;
                pos->y -= b.y;
                pos->z -= b.z;
                pos->w -= b.w;
            }
        }
        if (face && hit) {
            V_0018B200* up = &m->r[1];
            V_0018B200* fwd = &m->r[2];
            fwd->Set(target->x - pos->x, target->y - pos->y, target->z - pos->z, 1.0f);
            func_003233B8(fwd, fwd);
            m->r[0] = V_0018B200(m->r[1].y * m->r[2].z - m->r[1].z * m->r[2].y,
                                 m->r[1].z * m->r[2].x - m->r[1].x * m->r[2].z,
                                 m->r[1].x * m->r[2].y - m->r[1].y * m->r[2].x, 0.0f);
            func_003233B8(&m->r[0], &m->r[0]);
            m->r[1] = V_0018B200(m->r[2].y * m->r[0].z - m->r[2].z * m->r[0].y,
                                 m->r[2].z * m->r[0].x - m->r[2].x * m->r[0].z,
                                 m->r[2].x * m->r[0].y - m->r[2].y * m->r[0].x, 0.0f);
            func_003233B8(up, up);
            m->r[0] = V_0018B200(-m->r[0].x, -m->r[0].y, -m->r[0].z, -m->r[0].w);
            m->r[2] = V_0018B200(-m->r[2].x, -m->r[2].y, -m->r[2].z, -m->r[2].w);
            m->r[3].w = 1.0f;
            m->r[0].w = 0.0f;
            m->r[1].w = 0.0f;
            m->r[2].w = 0.0f;
        }
    }
}
