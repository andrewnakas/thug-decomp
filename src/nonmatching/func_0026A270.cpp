/* fuzzy: 86.9 */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

typedef int qword_0026A270 __attribute__((mode(TI)));

struct Vec_0026A270 {
    union {
        struct { float x, y, z, w; };
        qword_0026A270 q;
    };
    Vec_0026A270() {}
    void operator-=(const Vec_0026A270& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
    }
    Vec_0026A270(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_0026A270 operator-(const Vec_0026A270& a, const Vec_0026A270& b)
{
    return Vec_0026A270(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_0026A270 operator*(const Vec_0026A270& a, float s)
{
    return Vec_0026A270(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_003233B8(Vec_0026A270* d, Vec_0026A270* s);

static inline Vec_0026A270 Normalized_0026A270(Vec_0026A270 v)
{
    func_003233B8(&v, &v);
    return v;
}

static inline float Dot_0026A270(const Vec_0026A270& a, const Vec_0026A270& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

struct Seg_0026A270 {
    Vec_0026A270 p0;
    Vec_0026A270 p1;
};

struct Node_0026A270 {
    char pad0[0x10];
    Vec_0026A270 m_min;
    Vec_0026A270 m_max;
    Vec_0026A270 m_pos;
    char pad40[0x10];
    Node_0026A270* m50;
    Node_0026A270* m54;
    int m58;
    char pad5C[0x4];
    bool Overlaps(const Vec_0026A270& mn, const Vec_0026A270& mx)
    {
        return mn.x <= m_max.x && m_min.x <= mx.x && mn.z <= m_max.z && m_min.z <= mx.z && mn.y <= m_max.y &&
               m_min.y <= mx.y;
    }
};

extern "C" Seg_0026A270* func_00101F38(Seg_0026A270* s);
extern "C" int func_00101F60(Seg_0026A270* a, Seg_0026A270* b, Vec_0026A270* pa, Vec_0026A270* pb, float* mua,
                             float* mub, int clamp);
extern "C" void func_002682E0(Vec_0026A270* a, Vec_0026A270* b, Vec_0026A270* mn, Vec_0026A270* mx);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" bool func_001CB7B8(Node_0026A270* n, int a);
extern "C" bool func_0026A968(Vec_0026A270* a, Vec_0026A270* b);
extern "C" int func_002692B0(Node_0026A270* n, Vec_0026A270* dir);

struct Graph_0026A270 {
    char pad0[0x50];
    Node_0026A270* m_nodes;
    char pad54[0x8];
    int m_count;
    int Find(Vec_0026A270* a, Vec_0026A270* b, Vec_0026A270* outPos, Node_0026A270** outNode,
             Node_0026A270* skip, int side, float minDot);
};

int Graph_0026A270::Find(Vec_0026A270* a, Vec_0026A270* b, Vec_0026A270* outPos, Node_0026A270** outNode,
                         Node_0026A270* skip, int side, float minDot)
{
    int found = 0;
    Seg_0026A270 seg;
    func_00101F38(&seg);
    float best = 10000000.0f;
    Node_0026A270* bestNode = 0;
    seg.p0 = *a;
    seg.p1 = *b;
    Vec_0026A270 mn;
    Vec_0026A270 mx;
    Vec_0026A270* pmn = &mn;
    Vec_0026A270* pmx = &mx;
    func_002682E0(&seg.p0, &seg.p1, pmn, pmx);
    float pad = func_001E5318(0xF840753E, 0);
    mn.x -= pad;
    mn.y -= pad;
    mn.z -= pad;
    pmn->w = 1.0f;
    mx.x += pad;
    mx.y += pad;
    mx.z += pad;
    pmx->w = 1.0f;
    Vec_0026A270 bestPos;
    for (int i = 0; i < m_count; i++) {
        Node_0026A270* n = &m_nodes[i];
        if (!(n->m58 & 0x10) && n != skip && func_001CB7B8(n, 2)) {
            if (n->m50) {
                Vec_0026A270& hi = n->m_max;
                Vec_0026A270& lo = n->m_min;
                if (mn.x <= hi.x && mx.x >= lo.x && mn.z <= hi.z && mx.z >= lo.z && mn.y <= hi.y && mx.y >= lo.y) {
                    Seg_0026A270 s2;
                    func_00101F38(&s2);
                    s2.p0 = n->m_pos;
                    s2.p1 = n->m50->m_pos;
                    Vec_0026A270 pa = n->m_pos;
                    Vec_0026A270 pb = n->m50->m_pos;
                    float mua;
                    float mub;
                    if (func_0026A968(&pa, &pb) && func_00101F60(&seg, &s2, &pa, &pb, &mua, &mub, 1)) {
                        Vec_0026A270 d = pb - pa;
                        float lim = sqrtf(Dot_0026A270(d, d));
                        float score = lim;
                        Vec_0026A270 dirA;
                        Vec_0026A270 dirB;
                        dirA = s2.p1 - s2.p0;
                        dirB = *b - *a;
                        dirA.y = 0.0f;
                        dirB.y = 0.0f;
                        func_003233B8(&dirA, &dirA);
                        func_003233B8(&dirB, &dirB);
                        float dot = fabsf(Dot_0026A270(dirA, dirB));
                        if (dirB.x == 0.0f && dirB.z == 0.0f && dot == 0.0f)
                            dot = 1.0f;
                        score *= 1.122f - dot;
                        lim *= 2.0f - dot;
                        if (side) {
                            Vec_0026A270 v = *b - *a;
                            if (func_002692B0(n, &v) != side)
                                score *= 2.0f;
                        }
                        if (score < best) {
                            int ok = 1;
                            if (minDot != 1.0f && fabsf(dot) < minDot)
                                ok = 0;
                            if (ok) {
                                best = score;
                                if (pad < lim) {
                                    found = 0;
                                } else {
                                    bestNode = n;
                                    found = 1;
                                    bestPos = pb;
                                }
                            }
                        }
                    }
                }
            } else if (!n->m54) {
                Vec_0026A270& hi = n->m_max;
                Vec_0026A270& lo = n->m_min;
                if (mn.x <= hi.x && mx.x >= lo.x && mn.z <= hi.z && mx.z >= lo.z && mn.y <= hi.y && mx.y >= lo.y) {
                    Vec_0026A270 p = n->m_pos - *a;
                    Vec_0026A270 u = Normalized_0026A270(*b - *a);
                    Vec_0026A270 proj = u * Dot_0026A270(p, u);
                    p -= proj;
                    float dist = sqrtf(Dot_0026A270(p, p));
                    if (pad < dist)
                        continue;
                    dist *= 2.0f;
                    if (best < dist)
                        continue;
                    bestPos = n->m_pos;
                    best = dist;
                    bestNode = n;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        *outPos = bestPos;
        *outNode = bestNode;
    }
    return found;
}
