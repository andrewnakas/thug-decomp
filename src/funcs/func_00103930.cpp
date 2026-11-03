typedef int qword __attribute__((mode(TI)));

struct Vector {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vector() {}
    Vector(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    float operator[](int i) const { return (&x)[i]; }
    Vector& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

static inline Vector operator-(const Vector& a, const Vector& b) { return Vector(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vector operator+(const Vector& a, const Vector& b) { return Vector(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]); }

struct Mat_00103930 {
    Vector r0;
    Vector r1;
    Vector r2;
    Vector r3;
    Vector& operator[](int i) { return (&r0)[i]; }
    const Vector& operator[](int i) const { return (&r0)[i]; }
    Mat_00103930() {}
    void Ident()
    {
        r0.x = 1.0f; r0.y = 0.0f; r0.z = 0.0f; r0.w = 0.0f;
        r1.x = 0.0f; r1.y = 1.0f; r1.z = 0.0f; r1.w = 0.0f;
        r2.x = 0.0f; r2.y = 0.0f; r2.z = 1.0f; r2.w = 0.0f;
        r3.x = 0.0f; r3.y = 0.0f; r3.z = 0.0f; r3.w = 1.0f;
    }
};

extern "C" void func_003233B8(Vector* d, Vector* s);
extern "C" void func_00323318(Mat_00103930* d, const Mat_00103930* a, Mat_00103930* b);
extern "C" void func_00100700(Mat_00103930* m, const Vector* axis, float angle);

struct Obj_00103930 {
    Mat_00103930 m_a;
    Mat_00103930 m_b;
    Vector m_axis;
    float m_angle;
    int m_small;
    void Interp(Mat_00103930* out, float t);
};

void Obj_00103930::Interp(Mat_00103930* out, float t)
{
    if (t <= 0.0f) {
        *out = m_a;
        return;
    }
    if (t >= 1.0f) {
        *out = m_b;
        return;
    }
    if (m_small) {
        Mat_00103930 d;
        d.Ident();
        Vector dp;
        Vector p0 = m_a[3];
        Vector p1 = m_b[3];
        Vector pos;
        d[0] = m_b[0] - m_a[0];
        d[1] = m_b[1] - m_a[1];
        d[2] = m_b[2] - m_a[2];
        dp = p1 - p0;
        d[0] *= t;
        d[1] *= t;
        d[2] *= t;
        dp *= t;
        (*out)[0] = m_a[0] + d[0];
        (*out)[1] = m_a[1] + d[1];
        (*out)[2] = m_a[2] + d[2];
        pos = p0 + dp;
        func_003233B8(&(*out)[0], &(*out)[0]);
        func_003233B8(&(*out)[1], &(*out)[1]);
        func_003233B8(&(*out)[2], &(*out)[2]);
        (*out)[3] = pos;
    } else {
        Vector pos;
        Vector p0 = m_a[3];
        Vector p1 = m_b[3];
        Vector dp;
        (*out)[0] = m_a[0];
        (*out)[1] = m_a[1];
        (*out)[2] = m_a[2];
        (*out)[3] = Vector(0.0f, 0.0f, 0.0f, 1.0f);
        {
            Mat_00103930 rot;
            func_00100700(&rot, &m_axis, m_angle * t);
            func_00323318(out, &rot, out);
        }
        dp = p1 - p0;
        dp *= t;
        (*out)[3] = pos = p0 + dp;
    }
}
