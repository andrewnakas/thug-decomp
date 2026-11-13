typedef int qword_00257068 __attribute__((mode(TI)));
union Vec_00257068 {
    qword_00257068 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    void operator+=(const Vec_00257068& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};

struct Mat_00257068 {
    Vec_00257068 r[4];
    Vec_00257068& operator[](int i) { return r[i]; }
    const Vec_00257068& operator[](int i) const { return r[i]; }
    Mat_00257068() {}
    Mat_00257068(const Mat_00257068& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    float Det() const;
    void Adjoint(const Mat_00257068& m);
    void Invert();
    void Scale(float s)
    {
        if (s != 1.0f) {
            r[0] *= s;
            r[1] *= s;
            r[2] *= s;
            r[3] *= s;
        }
    }
    void Invert(const Mat_00257068& in);
};

static inline float Det3_00257068(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}
inline float Mat_00257068::Det() const
{
    const Mat_00257068& m = *this;
    return m[0][0] * Det3_00257068(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) - m[0][1] * Det3_00257068(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) + m[0][2] * Det3_00257068(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) - m[0][3] * Det3_00257068(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_00257068::Adjoint(const Mat_00257068& m)
{
    r[0].c[0] = Det3_00257068(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_00257068(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] = Det3_00257068(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_00257068(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_00257068(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] = Det3_00257068(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_00257068(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] = Det3_00257068(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] = Det3_00257068(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_00257068(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] = Det3_00257068(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_00257068(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_00257068(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] = Det3_00257068(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_00257068(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] = Det3_00257068(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}
inline void Mat_00257068::Invert(const Mat_00257068& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) Scale(1.0f / d);
}
inline void Mat_00257068::Invert()
{
    Mat_00257068 t;
    t.Invert(*this);
    *this = t;
}


struct Src_00257068 {
    char pad0[0x70];
    Mat_00257068 m70;
};

/* View transform: world matrix, roll angle, viewport scale/offset. */
struct View_00257068 {
    Mat_00257068 m;
    float m40;
    float m44;
    float m48;
    float m_roll;
    Vec_00257068 m_scale;
    Vec_00257068 m_offset;
    Vec_00257068 m_center;
    char pad80[0x10];
    int m_valid;
};

extern "C" Mat_00257068* func_00100928(Mat_00257068* m, float angle);
extern "C" void func_00323318(Mat_00257068* d, const Mat_00257068* a, Mat_00257068* b);


static inline Mat_00257068 operator*(const Mat_00257068& a, const Mat_00257068& b)
{
    Mat_00257068 r = a;
    func_00323318(&r, &b, &r);
    return r;
}

/* Builds the view from the source's camera matrix once: optional roll, inverse, then the
   viewport scale and offset vectors around the screen centre. */
void func_00257068(Src_00257068* src, View_00257068* v)
{
    if (v->m_valid)
        return;
    v->m = src->m70;
    if (v->m_roll != 0.0f)
        v->m = *func_00100928((Mat_00257068*)0x70003FC0, v->m_roll) * v->m;
    v->m.Invert();
    v->m_scale.Set(v->m48 * 0.5f, v->m40 * 0.5f, v->m44, 1.0f);
    Vec_00257068 neg;
    neg.c[0] = -v->m_scale.c[0];
    neg.c[1] = -v->m_scale.c[1];
    neg.c[2] = -v->m_scale.c[2];
    neg.c[3] = -v->m_scale.c[3];
    v->m_offset = neg;
    v->m_offset[2] = 0.0f;
    v->m_scale += v->m_center;
    v->m_offset += v->m_center;
    v->m_valid = 1;
}
