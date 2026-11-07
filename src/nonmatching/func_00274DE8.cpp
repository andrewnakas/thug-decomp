/* fuzzy: 97.4 */
typedef int qword __attribute__((mode(TI)));
union Vec_00274DE8 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00274DE8() {}
    Vec_00274DE8(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float Length() const;
    void Normalize();
    void operator+=(const Vec_00274DE8& o)
    {
        c[0] += o.c[0];
        c[1] += o.c[1];
        c[2] += o.c[2];
        c[3] += o.c[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
extern "C" float sqrtf(float);
inline float Vec_00274DE8::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline float Dot_00274DE8(const Vec_00274DE8& a, const Vec_00274DE8& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
inline Vec_00274DE8 operator*(const Vec_00274DE8& a, float k) { return Vec_00274DE8(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00274DE8 operator-(const Vec_00274DE8& a, const Vec_00274DE8& b)
{
    return Vec_00274DE8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Rail_00274DE8 {
    char pad0[0x50];
    Rail_00274DE8* m_next;
    Rail_00274DE8* m_prev;
};

struct Xform_00274DE8;

struct Game_00274DE8 {
    char pad0[0x28];
    Xform_00274DE8* m_rails;
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

extern "C" Vec_00274DE8 func_0026B1B0(Xform_00274DE8* x, Rail_00274DE8* r);
extern "C" bool func_001CB7B8(Rail_00274DE8* r, int bit);
extern "C" bool func_0026A968(const Vec_00274DE8& a, const Vec_00274DE8& b);
extern "C" float func_002032A0(unsigned int name, int def);
extern "C" Vec_00274DE8* func_00101820(Vec_00274DE8* v, const Vec_00274DE8* n);
extern "C" Vec_00274DE8* func_00101890(Vec_00274DE8* v, const Vec_00274DE8* n);
extern "C" void func_003233B8(Vec_00274DE8* d, Vec_00274DE8* s);
inline void Vec_00274DE8::Normalize() { func_003233B8(this, this); }
extern "C" float func_00340F60(float a);

// Move the skater along a rail segment; returns the node it ends on, or 0 if it left the rail.
Rail_00274DE8* Obj_00274DE8::Follow(Rail_00274DE8* node, float dt)
{
    Xform_00274DE8* rails = D_0038FC78->m_rails;
    Rail_00274DE8* next = node->m_next;
    int ok = 1;
    if (!next) {
    fail:
        return 0;
    }

    Vec_00274DE8 dir = func_0026B1B0(rails, next) - func_0026B1B0(rails, node);
    float segLen = dir.Length();
    dir *= 1.0f / segLen;

    // Gravity along the rail.
    Vec_00274DE8 grav;
    grav.Set(0.0f, func_002032A0(0xD1F46992, 0), 0.0f, 1.0f);
    func_00101890(&grav, &dir);
    m_body->m_vel += grav * dt;

    float sign = 1.0f;
    if (Dot_00274DE8(dir, m_body->m_vel) < 0.0f)
        sign = -1.0f;

    // Can we pass onto the adjoining segment (not too sharp a corner)?
    int stuck = 0;
    if (sign < 0.0f) {
        if (!node->m_prev || !func_001CB7B8(node->m_prev, 2)) {
            stuck = 1;
        } else {
            Vec_00274DE8 b, e;
            b = func_0026B1B0(rails, next) - func_0026B1B0(rails, node);
            e = func_0026B1B0(rails, node) - func_0026B1B0(rails, node->m_prev);
            b[1] = 0.0f;
            e[1] = 0.0f;
            b.Normalize();
            e.Normalize();
            if (Dot_00274DE8(b, e) < func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.017453294f))
                stuck = 1;
        }
    } else {
        if (!next->m_next || !func_001CB7B8(next->m_next, 2)) {
            stuck = 1;
        } else {
            Vec_00274DE8 b, e;
            b = func_0026B1B0(rails, node) - func_0026B1B0(rails, next);
            e = func_0026B1B0(rails, next) - func_0026B1B0(rails, next->m_next);
            b[1] = 0.0f;
            e[1] = 0.0f;
            b.Normalize();
            e.Normalize();
            if (Dot_00274DE8(b, e) < func_00340F60(func_002032A0(0x76C1DA15, 0) * 0.017453294f))
                stuck = 1;
        }
    }

    float over = 0.0f;
    float dist;
    if (sign < 0.0f) {
        Body_00274DE8* body = m_body;
        Vec_00274DE8 off = body->m_pos - func_0026B1B0(rails, next);
        dist = off.Length();
    } else {
        Body_00274DE8* body = m_body;
        Vec_00274DE8 off = body->m_pos - func_0026B1B0(rails, node);
        dist = off.Length();
    }
    if (segLen + 0.1f < dist) {
        over = dist - segLen;
        if (sign < 0.0f) {
            if (node->m_prev && func_001CB7B8(node->m_prev, 2)) {
                bool linked = func_0026A968(func_0026B1B0(rails, node), func_0026B1B0(rails, node->m_prev));
                if (!linked || stuck) {
                    ok = 0;
                } else {
                    m_body->m_pos = func_0026B1B0(rails, node);
                    node = node->m_prev;
                }
            } else {
                ok = 0;
            }
        } else {
            if (next->m_next && func_001CB7B8(next, 2)) {
                bool linked = func_0026A968(func_0026B1B0(rails, next), func_0026B1B0(rails, next->m_next));
                if (!linked || stuck) {
                    ok = 0;
                } else {
                    m_body->m_pos = func_0026B1B0(rails, next);
                    node = next;
                }
            } else {
                ok = 0;
            }
        }
    }
    if (!ok)
        goto fail;

    // Align the skater with the (possibly new) segment.
    Vec_00274DE8 seg = func_0026B1B0(rails, node->m_next) - func_0026B1B0(rails, node);
    seg.Normalize();
    float facing = 1.0f;
    if (Dot_00274DE8(seg, m_body->m_vel) < 0.0f)
        facing = -1.0f;
    func_00101820(&m_body->m_vel, &seg);
    m_body->m_vel *= facing;
    Vec_00274DE8 fwd = seg * facing;
    m_body->m_fwd = fwd;
    m_body->m_fwd.Normalize();
    m_body->m_right.Set(m_body->m_fwd[2], 0.0f, -m_body->m_fwd[0], 0.0f);
    m_body->m_right.Normalize();
    Body_00274DE8* body = m_body;
    body->m_up = Vec_00274DE8(body->m_fwd[1] * body->m_right[2] - body->m_fwd[2] * body->m_right[1],
                              body->m_fwd[2] * body->m_right[0] - body->m_fwd[0] * body->m_right[2],
                              body->m_fwd[0] * body->m_right[1] - body->m_fwd[1] * body->m_right[0], 0.0f);
    m_body->m_up.Normalize();
    m_body->m_pos += m_body->m_vel * dt;
    m_body->m_pos += fwd * over;
    return node;
}
