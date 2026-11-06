typedef int qword_0025A4B0 __attribute__((mode(TI)));

struct Row_0025A4B0 {
    union {
        qword_0025A4B0 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

struct Vec_0025A4B0 : Row_0025A4B0 {
    Vec_0025A4B0() {}
    Vec_0025A4B0(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

static inline Vec_0025A4B0 operator-(const Row_0025A4B0& a, const Row_0025A4B0& b)
{
    return Vec_0025A4B0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

static inline Vec_0025A4B0 operator+(const Row_0025A4B0& a, const Row_0025A4B0& b)
{
    return Vec_0025A4B0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_0025A4B0 operator*(const Row_0025A4B0& a, float s)
{
    return Vec_0025A4B0(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

static inline Vec_0025A4B0 Cross(const Row_0025A4B0& a, const Row_0025A4B0& b)
{
    return Vec_0025A4B0(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct Mat_0025A4B0 {
    Row_0025A4B0 r[4];
};

extern "C" void func_003233B8(Row_0025A4B0* d, Row_0025A4B0* s);
extern "C" float sqrtf(float);

struct Trail_0025A4B0 {
    char pad0[0x10];
    Row_0025A4B0 m_points[64];
    int m_count;
    int m_index;
    unsigned int m_target;
    int pad41C;
    Row_0025A4B0 m_cur;
    float m_dist;
    int m_flat;
    void GetFollow(Row_0025A4B0* out, Mat_0025A4B0* mat);
};

void Trail_0025A4B0::GetFollow(Row_0025A4B0* out, Mat_0025A4B0* mat)
{
    if (m_count <= 0)
        return;
    Row_0025A4B0 cur = m_cur;
    int left = m_count - 1;
    int i = m_index;
    float dist = m_dist;
    Row_0025A4B0 pt;
    Row_0025A4B0 d;
    float len;
    pt = m_points[i];
    for (;;) {
        d = pt - cur;
        len = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
        if (len < dist) {
            dist -= len;
            cur = pt;
            if (!left)
                goto done;
            i--;
            left--;
            if (i < 0)
                i = 63;
            pt = m_points[i];
        } else {
            goto done;
        }
    }
done:
    if (len > 0.0f) {
        Vec_0025A4B0 dir = d * (1.0f / -len);
        *out = cur - dir * dist;
        if (m_flat) {
            mat->r[2] = mat->r[2] * 10.0f + dir;
            func_003233B8(&mat->r[2], &mat->r[2]);
            Vec_0025A4B0 up(0.0f, 1.0f, 0.0f, 1.0f);
            mat->r[0] = Cross(up, mat->r[2]);
            func_003233B8(&mat->r[0], &mat->r[0]);
            mat->r[1] = Cross(mat->r[2], mat->r[0]);
        } else {
            mat->r[2] = mat->r[2] * 10.0f + dir;
            mat->r[2][1] = 0.0f;
            func_003233B8(&mat->r[2], &mat->r[2]);
            mat->r[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
            mat->r[0] = Cross(mat->r[1], mat->r[2]);
        }
    }
}
