/* force: {"kind": "lfr", "block": 44, "reg": 336, "hard": 34} */
/* force: {"kind": "lfr", "block": 52, "reg": 403, "hard": 33} */
/* force: {"kind": "lfr", "block": 64, "reg": 463, "hard": 33} */
typedef int qword __attribute__((mode(TI)));

struct Vec_00209B80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00209B80() {}
    Vec_00209B80(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00209B80(const Vec_00209B80& o) { q = o.q; }
    Vec_00209B80& operator=(const Vec_00209B80& o)
    {
        q = o.q;
        return *this;
    }
};

struct Pt_00209B80 {
    Vec_00209B80 pos;
    Vec_00209B80 v;
    unsigned char flag;
};

struct Edge_00209B80 {
    Pt_00209B80 pts[2];
    Vec_00209B80 n;
    int m70;
    unsigned char m74;
};

extern "C" void func_003233B8(Vec_00209B80* d, Vec_00209B80* s);

static inline bool Near_00209B80(Vec_00209B80 a, Vec_00209B80 b, float eps)
{
    if (__builtin_fabsf(a.x - b.x) < eps && __builtin_fabsf(a.y - b.y) < eps && __builtin_fabsf(a.z - b.z) < eps)
        return true;
    return false;
}

static inline float Dot_00209B80(const Vec_00209B80& a, const Vec_00209B80& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Edges_00209B80 {
    char pad0[0x30];
    Edge_00209B80 m_in[32];
    int m1030;
    char pad1034[0xC];
    Edge_00209B80 m_out[32];
    int m2040;
    void Merge();
};

void Edges_00209B80::Merge()
{
    int used[32];
    Vec_00209B80 dirs[32];
    int i = m1030;
    while (i--) {
        used[i] = 0;
        Edge_00209B80* e = &m_in[i];
        Vec_00209B80 d(e->pts[1].pos.x - e->pts[0].pos.x, e->pts[1].pos.y - e->pts[0].pos.y,
                       e->pts[1].pos.z - e->pts[0].pos.z, e->pts[1].pos.w - e->pts[0].pos.w);
        dirs[i] = d;
        func_003233B8(&dirs[i], &dirs[i]);
    }
    int k = m1030;
    while (k--) {
        Edge_00209B80* a = &m_in[k];
        if (used[k])
            continue;
        int j = k;
        while (j--) {
            Edge_00209B80* b = &m_in[j];
            if ((Near_00209B80(a->pts[0].pos, b->pts[0].pos, 0.1f) && Near_00209B80(a->pts[1].pos, b->pts[1].pos, 0.1f)) ||
                (Near_00209B80(a->pts[0].pos, b->pts[1].pos, 0.1f) && Near_00209B80(a->pts[1].pos, b->pts[0].pos, 0.1f))) {
                if (0.99f < a->n.x * b->n.x + a->n.y * b->n.y + a->n.z * b->n.z)
                    used[j] = 1;
            }
        }
    }
    m2040 = 0;
    int n = m1030;
    while (n--) {
        Edge_00209B80 cur = m_in[n];
        if (used[n])
            continue;
        int j = n;
        while (j--) {
            Edge_00209B80* b = &m_in[j];
            if (used[j])
                continue;
            if (cur.n.x * b->n.x + cur.n.y * b->n.y + cur.n.z * b->n.z < 0.99f)
                continue;
            if (__builtin_fabsf(Dot_00209B80(dirs[n], dirs[j])) < 0.99f)
                continue;
            /* point copies field by field: the game's lq/sq, lbu/sb, lq/sq order (0020A0D4..0020A0EC) */
            if (Near_00209B80(cur.pts[0].pos, b->pts[0].pos, 0.1f)) {
                cur.pts[0].pos = b->pts[1].pos;
                cur.pts[0].flag = b->pts[1].flag;
                cur.pts[0].v = b->pts[1].v;
            } else if (Near_00209B80(cur.pts[0].pos, b->pts[1].pos, 0.1f)) {
                cur.pts[0].pos = b->pts[0].pos;
                cur.pts[0].flag = b->pts[0].flag;
                cur.pts[0].v = b->pts[0].v;
            } else if (Near_00209B80(cur.pts[1].pos, b->pts[0].pos, 0.1f)) {
                cur.pts[1].pos = b->pts[1].pos;
                cur.pts[1].flag = b->pts[1].flag;
                cur.pts[1].v = b->pts[1].v;
            } else if (Near_00209B80(cur.pts[1].pos, b->pts[1].pos, 0.1f)) {
                cur.pts[1].pos = b->pts[0].pos;
                cur.pts[1].flag = b->pts[0].flag;
                cur.pts[1].v = b->pts[0].v;
            } else {
                continue;
            }
            used[j] = 1;
        }
        m_out[m2040++] = cur;
    }
}
