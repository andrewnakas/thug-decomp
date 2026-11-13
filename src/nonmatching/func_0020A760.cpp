/* fuzzy: 98.6 */
typedef int qword_0020A760 __attribute__((mode(TI)));

struct Vec_0020A760 {
    union {
        qword_0020A760 q;
        float c[4];
    };
    Vec_0020A760() {}
    Vec_0020A760(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0020A760& operator+=(const Vec_0020A760& a)
    {
        c[0] += a[0];
        c[1] += a[1];
        c[2] += a[2];
        c[3] += a[3];
        return *this;
    }
};

static inline Vec_0020A760 operator-(const Vec_0020A760& a, const Vec_0020A760& b)
{
    return Vec_0020A760(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Mat_0020A760 {
    Vec_0020A760 r[4];
    const Vec_0020A760& operator[](int i) const { return r[i]; }
    Mat_0020A760& operator=(const Mat_0020A760& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    void ClearPos()
    {
        r[3] = Vec_0020A760(0.0f, 0.0f, 0.0f, 1.0f);
        r[0][3] = 0.0f;
        r[1][3] = 0.0f;
        r[2][3] = 0.0f;
    }
    void InvertOrtho()
    {
        Vec_0020A760 t = r[3];
        r[3][0] = -(t[0] * r[0][0] + t[1] * r[0][1] + t[2] * r[0][2]);
        r[3][1] = -(t[0] * r[1][0] + t[1] * r[1][1] + t[2] * r[1][2]);
        r[3][2] = -(t[0] * r[2][0] + t[1] * r[2][1] + t[2] * r[2][2]);
        float s = r[0][1];
        r[0][1] = r[1][0];
        r[1][0] = s;
        s = r[0][2];
        r[0][2] = r[2][0];
        r[2][0] = s;
        s = r[1][2];
        r[1][2] = r[2][1];
        r[2][1] = s;
    }
};

static inline bool operator==(const Mat_0020A760& a, const Mat_0020A760& b)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a.r[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

static inline bool operator!=(const Mat_0020A760& a, const Mat_0020A760& b)
{
    return !(a == b);
}

extern "C" void func_00323318(Mat_0020A760* d, const Mat_0020A760* a, Mat_0020A760* b);
extern "C" Vec_0020A760 func_00323298(const Mat_0020A760* m, const Vec_0020A760* v);

struct Parent_0020A760 {
    char pad0[0x50];
    Vec_0020A760 m50;
    char pad60[0x70 - 0x60];
    Mat_0020A760 m70;
};

struct Mover_0020A760 {
    Parent_0020A760* m0;
    char pad4[0x10 - 0x4];
    Mat_0020A760 m10;
    Vec_0020A760 m50;
    Vec_0020A760 m60;
    Mat_0020A760 m70;
    int mB0;
    bool Update(const Vec_0020A760* pt);
};

bool Mover_0020A760::Update(const Vec_0020A760* pt)
{
    Parent_0020A760* p = m0;
    if (!p) {
        return false;
    }
    m60 = p->m50 - m50;
    if (m10 != p->m70) {
        mB0 = 1;
        Vec_0020A760 v = *pt - m50;
        Vec_0020A760 local = v;
        Mat_0020A760 inv(m10);
        inv.ClearPos();
        inv.InvertOrtho();
        m70 = m0->m70;
        m70.ClearPos();
        func_00323318(&m70, &inv, &m70);
        Vec_0020A760 r;
        r = func_00323298(&m70, &local);
        m60 += r - v;
        m10 = m0->m70;
    } else {
        mB0 = 0;
    }
    m50 = m0->m50;
    return true;
}
