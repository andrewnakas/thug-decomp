/* fuzzy: 98.3 */
typedef int qword __attribute__((mode(TI)));
union Vec_00103000 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};

struct Mat_00103000;
extern "C" void func_00323318(Mat_00103000* d, const Mat_00103000* a, Mat_00103000* b);
extern "C" void func_00100FE8(Mat_00103000* m, Vec_00103000* axis, float* angle);

struct Mat_00103000 {
    Vec_00103000 r[4];
    Mat_00103000() {}
    Mat_00103000(const Mat_00103000& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
    }
    Mat_00103000& operator=(const Mat_00103000& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
    Vec_00103000& operator[](int i) { return r[i]; }
    const Vec_00103000& operator[](int i) const { return r[i]; }
    float Det() const;
    void Adjoint(const Mat_00103000& m);
    void Invert(const Mat_00103000& in);
    void Invert();
    Mat_00103000& operator*=(const Mat_00103000& o)
    {
        func_00323318(this, &o, this);
        return *this;
    }
    Mat_00103000 operator*(const Mat_00103000& o) const
    {
        Mat_00103000 t = *this;
        t *= o;
        return t;
    }
};

static inline float Det3_00103000(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}

inline float Mat_00103000::Det() const
{
    const Mat_00103000& m = *this;
    return m[0][0] * Det3_00103000(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) -
           m[0][1] * Det3_00103000(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]) +
           m[0][2] * Det3_00103000(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]) -
           m[0][3] * Det3_00103000(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
}

inline void Mat_00103000::Adjoint(const Mat_00103000& m)
{
    r[0].c[0] =  Det3_00103000(m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[1].c[0] = -Det3_00103000(m[1][0], m[2][0], m[3][0], m[1][2], m[2][2], m[3][2], m[1][3], m[2][3], m[3][3]);
    r[2].c[0] =  Det3_00103000(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][3], m[2][3], m[3][3]);
    r[3].c[0] = -Det3_00103000(m[1][0], m[2][0], m[3][0], m[1][1], m[2][1], m[3][1], m[1][2], m[2][2], m[3][2]);
    r[0].c[1] = -Det3_00103000(m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[1].c[1] =  Det3_00103000(m[0][0], m[2][0], m[3][0], m[0][2], m[2][2], m[3][2], m[0][3], m[2][3], m[3][3]);
    r[2].c[1] = -Det3_00103000(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][3], m[2][3], m[3][3]);
    r[3].c[1] =  Det3_00103000(m[0][0], m[2][0], m[3][0], m[0][1], m[2][1], m[3][1], m[0][2], m[2][2], m[3][2]);
    r[0].c[2] =  Det3_00103000(m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[1].c[2] = -Det3_00103000(m[0][0], m[1][0], m[3][0], m[0][2], m[1][2], m[3][2], m[0][3], m[1][3], m[3][3]);
    r[2].c[2] =  Det3_00103000(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][3], m[1][3], m[3][3]);
    r[3].c[2] = -Det3_00103000(m[0][0], m[1][0], m[3][0], m[0][1], m[1][1], m[3][1], m[0][2], m[1][2], m[3][2]);
    r[0].c[3] = -Det3_00103000(m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[1].c[3] =  Det3_00103000(m[0][0], m[1][0], m[2][0], m[0][2], m[1][2], m[2][2], m[0][3], m[1][3], m[2][3]);
    r[2].c[3] = -Det3_00103000(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][3], m[1][3], m[2][3]);
    r[3].c[3] =  Det3_00103000(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}

inline void Mat_00103000::Invert(const Mat_00103000& in)
{
    Adjoint(in);
    float d = in.Det();
    if (d != 1.0f) {
        float s = 1.0f / d;
        if (s != 1.0f) {
            r[0] *= s;
            r[1] *= s;
            r[2] *= s;
            r[3] *= s;
        }
    }
}

inline void Mat_00103000::Invert()
{
    Mat_00103000 t;
    t.Invert(*this);
    *this = t;
}

struct Obj_00103000 {
    Mat_00103000 m_a;
    Mat_00103000 m_b;
    Vec_00103000 m_axis;
    float m_angle;
    int m_small;
    void Set(const Mat_00103000& a, const Mat_00103000& b);
    void Update();
};

inline void Obj_00103000::Update()
{
    Mat_00103000 d = m_a;
    d.Invert();
    Mat_00103000 t = d * m_b;
    d = t;
    func_00100FE8(&d, &m_axis, &m_angle);
    m_small = m_angle < 0.03490659f;
}

void Obj_00103000::Set(const Mat_00103000& a, const Mat_00103000& b)
{
    m_a = a;
    m_b = b;
    Update();
}
