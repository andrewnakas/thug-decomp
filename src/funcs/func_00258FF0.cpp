typedef int qword_00258FF0 __attribute__((mode(TI)));

struct Vec_00258FF0 {
    union {
        struct {
            float x, y, z, w;
        } f;
        qword_00258FF0 q;
    } u;
    Vec_00258FF0() {}
    Vec_00258FF0(float x, float y, float z, float w)
    {
        u.f.x = x;
        u.f.y = y;
        u.f.z = z;
        u.f.w = w;
    }
    Vec_00258FF0& operator=(const Vec_00258FF0& o)
    {
        u.q = o.u.q;
        return *this;
    }
    Vec_00258FF0(const Vec_00258FF0& o) { u.q = o.u.q; }
    Vec_00258FF0& operator+=(const Vec_00258FF0& o)
    {
        u.f.x += o.u.f.x;
        u.f.y += o.u.f.y;
        u.f.z += o.u.f.z;
        u.f.w += o.u.f.w;
        return *this;
    }
};

union Row_00258FF0 {
    qword_00258FF0 q;
    struct {
        float x, y, z, w;
    } f;
};

static inline Vec_00258FF0 operator*(const Row_00258FF0& v, float s)
{
    return Vec_00258FF0(v.f.x * s, v.f.y * s, v.f.z * s, v.f.w * s);
}

struct Mat_00258FF0 {
    Row_00258FF0 r[4];
    Mat_00258FF0() {}
    const Row_00258FF0& operator[](int i) const { return r[i]; }
    Mat_00258FF0(const Mat_00258FF0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_00258FF0& operator=(const Mat_00258FF0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

extern "C" Mat_00258FF0* func_00100928(Mat_00258FF0* out, float a);
extern "C" void func_00323318(Mat_00258FF0* dst, const Mat_00258FF0* a, const Mat_00258FF0* b);

static inline Mat_00258FF0 operator*(const Mat_00258FF0& a, const Mat_00258FF0& b)
{
    Mat_00258FF0 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

struct Obj_00258FF0 {
    char m_pad0[0x10];
    Vec_00258FF0 m_pos;
    char m_pad20[0x10];
    Mat_00258FF0 m_mat;
    char m_pad70[0xD0 - 0x70];
    Vec_00258FF0 m_offset;
    char m_padE0[0x10];
    float m_speed;
    float m_period;
    float m_radius;
    float mFC;
    float m_angle;
    void Update(float dt);
};

void Obj_00258FF0::Update(float dt)
{
    m_angle = m_speed * (dt / m_period);
    m_mat = m_mat * *func_00100928((Mat_00258FF0*)0x70003FC0, m_angle);
    Row_00258FF0 up = m_mat.r[1];
    if (up.f.y > 0.0f)
        m_angle = -m_angle;
    float r = -m_radius;
    m_pos = Vec_00258FF0(m_mat.r[0].f.x * r, m_mat.r[0].f.y * r, m_mat.r[0].f.z * r, m_mat.r[0].f.w * r);
    Vec_00258FF0* p = &m_pos;
    p->u.f.x += m_offset.u.f.x;
    p->u.f.y += m_offset.u.f.y;
    p->u.f.z += m_offset.u.f.z;
    p->u.f.w += m_offset.u.f.w;
}
