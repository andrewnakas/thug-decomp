/* fuzzy: 49.9 */
typedef int qword_0018B200 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct V_0018B200 {
    union {
        qword_0018B200 q;
        struct {
            float x, y, z, w;
        };
    };
};

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
extern "C" void func_00209380(Feeler_0018B200* f, V_0018B200* start, V_0018B200* end);
extern "C" bool func_002093E8(Feeler_0018B200* f, int a, int b);
extern "C" bool func_002099C0(Feeler_0018B200* f, V_0018B200* pos, V_0018B200* to, int a);
extern "C" void func_003233B8(V_0018B200* dst, V_0018B200* src);

/* pushes `pos` back from walls along the move from `old`, then probes sideways (along the matrix's X axis) and,
   when `face` is set and a side wall was hit, re-orients the matrix to look at `target` */
extern "C" void func_0018B200(V_0018B200* pos, M_0018B200* m, V_0018B200* old, V_0018B200* target, int side, int face)
{
    V_0018B200 dir;
    dir.x = pos->x - old->x;
    dir.y = pos->y - old->y;
    dir.z = pos->z - old->z;
    dir.w = pos->w - old->w;
    func_003233B8(&dir, &dir);

    Feeler_0018B200 f;
    func_00209240(&f);
    func_00209350(&f, 0x90, 0);
    V_0018B200 ext;
    ext.x = dir.x + dir.x;
    ext.y = dir.y + dir.y;
    ext.z = dir.z + dir.z;
    ext.w = dir.w + dir.w;
    V_0018B200 end;
    end.x = pos->x + ext.x;
    end.y = pos->y + ext.y;
    end.z = pos->z + ext.z;
    end.w = pos->w + ext.w;
    func_00209380(&f, old, &end);
    if (func_002093E8(&f, 1, 0)) {
        V_0018B200 d;
        d.x = f.m_end.x - f.m_start.x;
        d.y = f.m_end.y - f.m_start.y;
        d.z = f.m_end.z - f.m_start.z;
        d.w = f.m_end.w - f.m_start.w;
        float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        float t = f.m_dist;
        if (len * t < 13.9f)
            t = 13.9f / len;
        float back = t * len - 2.0f;
        V_0018B200 s;
        s.x = dir.x * back;
        s.y = dir.y * back;
        s.z = dir.z * back;
        s.w = dir.w * back;
        V_0018B200 p;
        p.x = old->x + s.x;
        p.y = old->y + s.y;
        p.z = old->z + s.z;
        p.w = old->w + s.w;
        *pos = p;
    }
    if (side) {
        bool hit;
        V_0018B200 a;
        a.x = m->r[0].x;
        a.y = 0.0f;
        a.z = m->r[0].z;
        a.w = 0.0f;
        float l = sqrtf(a.x * a.x + a.z * a.z);
        if (a.y < l) {
            float k = 8.0f / l;
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
                float k = 8.0f / l2;
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
            V_0018B200* fwd = &m->r[2];
            fwd->x = target->x - pos->x;
            fwd->y = target->y - pos->y;
            fwd->z = target->z - pos->z;
            fwd->w = 1.0f;
            func_003233B8(fwd, fwd);
            V_0018B200 c;
            c.x = m->r[1].y * m->r[2].z - m->r[1].z * m->r[2].y;
            c.y = m->r[1].z * m->r[2].x - m->r[1].x * m->r[2].z;
            c.z = m->r[1].x * m->r[2].y - m->r[1].y * m->r[2].x;
            c.w = 0.0f;
            m->r[0] = c;
            func_003233B8(&m->r[0], &m->r[0]);
            c.x = m->r[2].y * m->r[0].z - m->r[2].z * m->r[0].y;
            c.y = m->r[2].z * m->r[0].x - m->r[2].x * m->r[0].z;
            c.z = m->r[2].x * m->r[0].y - m->r[2].y * m->r[0].x;
            c.w = 0.0f;
            m->r[1] = c;
            func_003233B8(&m->r[1], &m->r[1]);
            V_0018B200 n0;
            n0.x = -m->r[0].x;
            n0.y = -m->r[0].y;
            n0.z = -m->r[0].z;
            n0.w = -m->r[0].w;
            V_0018B200 n2;
            n2.x = -m->r[2].x;
            n2.y = -m->r[2].y;
            n2.z = -m->r[2].z;
            n2.w = -m->r[2].w;
            m->r[3].w = 1.0f;
            m->r[0] = n0;
            m->r[2] = n2;
            m->r[0].w = 0.0f;
            m->r[1].w = 0.0f;
            m->r[2].w = 0.0f;
        }
    }
}
