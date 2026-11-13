typedef int qword __attribute__((mode(TI)));

struct Vec_001B4228;
extern "C" void func_003233B8(Vec_001B4228* out, Vec_001B4228* in);

struct V4_001B4228 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    const float& operator[](int i) const { return (&x)[i]; }
    bool operator==(const V4_001B4228& o) const { return x == o[0] && y == o[1] && z == o[2] && w == o[3]; }
    bool operator!=(const V4_001B4228& o) const { return !(*this == o); }
};

struct Vec_001B4228 : V4_001B4228 {
    Vec_001B4228() {}
    Vec_001B4228(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001B4228(const Vec_001B4228& o) { q = o.q; }
    Vec_001B4228 operator-(const Vec_001B4228& o) const { return Vec_001B4228((*this)[0] - o[0], (*this)[1] - o[1], (*this)[2] - o[2], (*this)[3] - o[3]); }
    Vec_001B4228 operator+(const Vec_001B4228& o) const { return Vec_001B4228((*this)[0] + o[0], (*this)[1] + o[1], (*this)[2] + o[2], (*this)[3] + o[3]); }
    Vec_001B4228 operator*(float s) const { return Vec_001B4228(x * s, y * s, z * s, w * s); }
    Vec_001B4228 operator-() const { return Vec_001B4228(-x, -y, -z, -w); }
    Vec_001B4228& Normalize()
    {
        func_003233B8(this, this);
        return *this;
    }
};

static inline Vec_001B4228 Cross_001B4228(const Vec_001B4228& a, const Vec_001B4228& b)
{
    return Vec_001B4228(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Tri_001B4228 {
    Vec_001B4228 v[3];
};

struct Mat_001B4228 {
    V4_001B4228 r[4];
    V4_001B4228& operator[](int i) { return r[i]; }
    Mat_001B4228& operator=(const Mat_001B4228& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Obj_001B4228 {
    char pad0[0x50];
    Tri_001B4228 m_tri;
};

struct Body_001B4228 {
    char pad0[0xC0];
    Mat_001B4228 m_mat;
};

extern "C" Obj_001B4228* func_00185578(Body_001B4228* body, unsigned int name);
extern "C" void func_00100DC0(Mat_001B4228* m, int a);

struct C_001B4228 {
    char pad0[0xC];
    Body_001B4228* m_body;
    char pad1[0x8C - 0x10];
    float m_8C;
    Vec_001B4228 m_from;
    Vec_001B4228 m_to;
    Vec_001B4228 m_up;
    float m_blend;
    char pad2[0x130 - 0xC4];
    Mat_001B4228 m_mat;
    void UpdateUp();
};

void C_001B4228::UpdateUp()
{
    Obj_001B4228* o = func_00185578(m_body, 0x0A015E17);
    if (!o) return;
    Tri_001B4228 t = o->m_tri;
    Vec_001B4228 e1 = t.v[1] - t.v[0];
    Vec_001B4228 e2 = t.v[2] - t.v[0];
    Vec_001B4228 n = Cross_001B4228(e1, e2).Normalize();
    if (n.y < 0.0f) n = -n;
    if (n != m_to) {
        m_to = n;
        m_from = m_up;
        m_blend = 1.0f;
    }
    if (m_blend != 0.0f) {
        if (m_from == m_to) {
            m_blend = 0.0f;
        } else {
            float b = m_blend - m_8C * 6.0f;
            m_blend = b;
            if (b <= 0.0f) {
                m_blend = 0.0f;
                m_up = m_to;
            } else {
                m_up = m_to + (m_from - m_to) * b;
                m_up.Normalize();
            }
        }
    }
    Mat_001B4228 m = m_body->m_mat;
    if (m[1] != m_up) {
        m[1] = m_up;
        func_00100DC0(&m, 1);
        m_body->m_mat = m;
        m_mat = m;
    }
}
