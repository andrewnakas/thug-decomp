/* fuzzy: 86.5 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vector {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vector() {}
    Vector(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    float operator[](int i) const { return (&x)[i]; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

static inline Vector Cross(const Vector& a, const Vector& b)
{
    return Vector(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

extern "C" int func_003233B8(Vector* d, Vector* s);

struct Mat_001013F0 {
    Vector row[4];
    void Ident()
    {
        row[0].x = 1.0f; row[0].y = 0.0f; row[0].z = 0.0f; row[0].w = 0.0f;
        row[1].x = 0.0f; row[1].y = 1.0f; row[1].z = 0.0f; row[1].w = 0.0f;
        row[2].x = 0.0f; row[2].y = 0.0f; row[2].z = 1.0f; row[2].w = 0.0f;
        row[3].x = 0.0f; row[3].y = 0.0f; row[3].z = 0.0f; row[3].w = 1.0f;
    }
};

extern "C" int func_001013F0(Mat_001013F0* m)
{
    float l0 = m->row[0].Length();
    float l1 = m->row[1].Length();
    float l2 = m->row[2].Length();
    if (l0 < 0.99f) {
        if (l1 < 0.99f || l2 < 0.99f) {
            m->Ident();
        } else {
            m->row[0] = Cross(m->row[1], m->row[2]);
            func_003233B8(&m->row[0], &m->row[0]);
        }
    } else if (l1 < 0.99f) {
        if (l2 < 0.99f) {
            m->Ident();
        } else {
            m->row[1] = Cross(m->row[2], m->row[0]);
            func_003233B8(&m->row[1], &m->row[1]);
        }
    } else if (l2 < 0.99f) {
        m->row[2] = Cross(m->row[0], m->row[1]);
        func_003233B8(&m->row[2], &m->row[2]);
    } else {
        return 0;
    }
    return 1;
}
