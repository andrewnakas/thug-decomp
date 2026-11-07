/* fuzzy: 73.8 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec4_00172078 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec4_00172078() {}
    Vec4_00172078(const Vec4_00172078& o) { q = o.q; }
    Vec4_00172078& operator=(const Vec4_00172078& o)
    {
        q = o.q;
        return *this;
    }
};

/* Node of a bounding-sphere hierarchy: sphere (centre xyz, radius w) at 0, flags at 0x1C. */
struct Node_00172078 {
    Vec4_00172078 m_sphere;
    char pad10[0xC];
    int m_flags;
    Node_00172078* m_child;
    char pad24[4];
    Node_00172078* m_next;
};

/* Returns the sphere enclosing the spheres of a node and of all its m_next siblings. Nodes without flag 2 whose
   radius is at least 1e10 (unbounded) are first replaced by their first child. */
Vec4_00172078 func_00172078(Node_00172078* node)
{
    while (!(node->m_flags & 2) && node->m_sphere.w >= 1e10f)
        node = node->m_child;
    Vec4_00172078 s = node->m_sphere;
    while (node->m_next) {
        node = node->m_next;
        Node_00172078* n = node;
        Vec4_00172078 big;
        Vec4_00172078 small;
        if (s.w < n->m_sphere.w) {
            big = n->m_sphere;
            small = s;
        } else {
            big = s;
            small = n->m_sphere;
        }
        Vec4_00172078 d;
        d.x = small.x - big.x;
        d.y = small.y - big.y;
        d.z = small.z - big.z;
        d.w = small.w - big.w;
        float dist2 = d.x * d.x + d.y * d.y + d.z * d.z;
        float dist = sqrtf(dist2);
        float dr = big.w - small.w;
        float t = 0.0f;
        if (dr * dr - dist2 < 0.0f)
            t = (d.w + dist) * 0.5f;
        if (0.0f < dist) {
            float inv = 1.0f / dist;
            d.x = d.x * inv;
            d.y = d.y * inv;
            d.z = d.z * inv;
            d.w = d.w * inv;
        }
        Vec4_00172078 c;
        Vec4_00172078 step;
        step.x = d.x * t;
        step.y = d.y * t;
        step.z = d.z * t;
        step.w = d.w * t;
        c.x = big.x + step.x;
        c.y = big.y + step.y;
        c.z = big.z + step.z;
        c.w = big.w + step.w;
        s = c;
        s.w = big.w + t;
    }
    return s;
}
