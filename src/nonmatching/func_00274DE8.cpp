/* fuzzy: 35.9 */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));
union Vec_00274DE8 {
    qword q;
    struct {
        float x, y, z, w;
    };
    Vec_00274DE8() {}
    Vec_00274DE8(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void operator+=(const Vec_00274DE8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
    }
    void operator*=(float k)
    {
        x *= k;
        y *= k;
        z *= k;
        w *= k;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

inline Vec_00274DE8 operator*(const Vec_00274DE8& a, float k) { return Vec_00274DE8(a.x * k, a.y * k, a.z * k, a.w * k); }
inline Vec_00274DE8 operator-(const Vec_00274DE8& a, const Vec_00274DE8& b)
{
    return Vec_00274DE8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
inline float Dot_00274DE8(const Vec_00274DE8& a, const Vec_00274DE8& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

struct Rail_00274DE8 {
    char pad0[0x50];
    Rail_00274DE8* m_next;
    Rail_00274DE8* m_prev;
};

struct Mgr_00274DE8;

struct Game_00274DE8 {
    char pad0[0x28];
    Mgr_00274DE8* m_rails;
};
extern Game_00274DE8* D_0038FC78;

struct Body_00274DE8 {
    char pad0[0x50];
    Vec_00274DE8 m_pos;
    char pad60[0x70 - 0x60];
    Vec_00274DE8 m_right;
    Vec_00274DE8 m_up;
    Vec_00274DE8 m_fwd;
    char padA0[0xB0 - 0xA0];
    Vec_00274DE8 m_vel;
};

struct Obj_00274DE8 {
    char pad0[0xC];
    Body_00274DE8* m_body;
    Rail_00274DE8* Follow(Rail_00274DE8* node, float dt);
};

extern "C" void func_0026B1B0(Vec_00274DE8* out, Mgr_00274DE8* m, Rail_00274DE8* r);
extern "C" bool func_001CB7B8(Rail_00274DE8* r, int a);
extern "C" bool func_0026A968(Vec_00274DE8* a, Vec_00274DE8* b);
extern "C" float func_002032A0(unsigned int name, int def);
extern "C" Vec_00274DE8* func_00101820(Vec_00274DE8* v, const Vec_00274DE8* n);
extern "C" Vec_00274DE8* func_00101890(Vec_00274DE8* v, const Vec_00274DE8* n);
extern "C" int func_003233B8(Vec_00274DE8* d, Vec_00274DE8* s);
extern "C" float func_00340F60(float a);

// Move the skater along a rail segment; returns the node it ends on, or 0 if it left the rail.
Rail_00274DE8* Obj_00274DE8::Follow(Rail_00274DE8* node, float dt)
{
    Mgr_00274DE8* rails = D_0038FC78->m_rails;
    Rail_00274DE8* next = node->m_next;
    Vec_00274DE8 a, b, c, d;
    int ok = 1;
    if (!next)
        return 0;

    func_0026B1B0(&a, rails, next);
    func_0026B1B0(&b, rails, node);
    Vec_00274DE8 seg = a - b;
    float segLen = seg.Length();
    Vec_00274DE8 dir = seg * (1.0f / segLen);

    // Gravity along the rail.
    a.y = func_002032A0(0xD1F46992, 0);
    a.x = 0.0f;
    a.z = 0.0f;
    a.w = 1.0f;
    func_00101890(&a, &dir);
    b = a * dt;
    m_body->m_vel += b;

    float sign = 1.0f;
    if (Dot_00274DE8(dir, m_body->m_vel) < 0.0f)
        sign = -1.0f;

    // Can we pass onto the adjoining segment (not too sharp a corner)?
    int stuck = 0;
    bool corner = false;
    if (sign < 0.0f) {
        Rail_00274DE8* prev = node->m_prev;
        if (!prev || !func_001CB7B8(prev, 2)) {
            stuck = 1;
        } else {
            func_0026B1B0(&c, rails, next);
            func_0026B1B0(&d, rails, node);
            b = c - d;
            func_0026B1B0(&c, rails, node);
            func_0026B1B0(&d, rails, node->m_prev);
            corner = true;
        }
    } else {
        Rail_00274DE8* after = next->m_next;
        if (!after || !func_001CB7B8(after, 2)) {
            stuck = 1;
        } else {
            func_0026B1B0(&c, rails, node);
            func_0026B1B0(&d, rails, next);
            b = c - d;
            func_0026B1B0(&c, rails, next);
            func_0026B1B0(&d, rails, next->m_next);
            corner = true;
        }
    }
    if (corner) {
        a = c - d;
        b.y = 0.0f;
        a.y = 0.0f;
        func_003233B8(&b, &b);
        func_003233B8(&a, &a);
        float cosAngle = Dot_00274DE8(b, a);
        if (cosAngle < func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.017453294f))
            stuck = 1;
    }

    float over = 0.0f;
    if (sign < 0.0f)
        func_0026B1B0(&a, rails, next);
    else
        func_0026B1B0(&a, rails, node);
    Body_00274DE8* body = m_body;
    b = body->m_pos - a;
    float dist = b.Length();
    if (segLen + 0.1f < dist) {
        over = dist - segLen;
        if (sign < 0.0f) {
            if (!node->m_prev || !func_001CB7B8(node->m_prev, 2)) {
                ok = 0;
            } else {
                func_0026B1B0(&b, rails, node);
                func_0026B1B0(&a, rails, node->m_prev);
                if (!func_0026A968(&b, &a) || stuck) {
                    ok = 0;
                } else {
                    body = m_body;
                    func_0026B1B0(&b, rails, node);
                    body->m_pos = b;
                    node = node->m_prev;
                }
            }
        } else {
            if (!next->m_next || !func_001CB7B8(next, 2)) {
                ok = 0;
            } else {
                func_0026B1B0(&b, rails, next);
                func_0026B1B0(&a, rails, next->m_next);
                if (!func_0026A968(&b, &a) || stuck) {
                    ok = 0;
                } else {
                    body = m_body;
                    func_0026B1B0(&b, rails, next);
                    node = next;
                    body->m_pos = b;
                }
            }
        }
    }
    if (!ok)
        return 0;

    // Align the skater with the (possibly new) segment.
    func_0026B1B0(&a, rails, node->m_next);
    func_0026B1B0(&c, rails, node);
    b = a - c;
    func_003233B8(&b, &b);
    float facing = 1.0f;
    if (Dot_00274DE8(b, m_body->m_vel) < 0.0f)
        facing = -1.0f;
    func_00101820(&m_body->m_vel, &b);
    m_body->m_vel *= facing;
    a = b * facing;
    m_body->m_fwd = a;
    func_003233B8(&m_body->m_fwd, &m_body->m_fwd);
    body = m_body;
    body->m_right.x = body->m_fwd.z;
    body->m_right.w = 0.0f;
    body->m_right.z = -body->m_fwd.x;
    body->m_right.y = 0.0f;
    func_003233B8(&m_body->m_right, &m_body->m_right);
    body = m_body;
    c.w = 0.0f;
    c.x = body->m_fwd.y * body->m_right.z - body->m_fwd.z * body->m_right.y;
    c.y = body->m_fwd.z * body->m_right.x - body->m_fwd.x * body->m_right.z;
    c.z = body->m_fwd.x * body->m_right.y - body->m_fwd.y * body->m_right.x;
    body->m_up = c;
    func_003233B8(&m_body->m_up, &m_body->m_up);

    body = m_body;
    c = body->m_vel * dt;
    body->m_pos += c;
    c = a * over;
    m_body->m_pos += c;
    return node;
}
