typedef int qword __attribute__((mode(TI)));

struct Vec_0011D9F0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0011D9F0;
extern "C" void func_00323318(Mat_0011D9F0* d, Mat_0011D9F0* a, Mat_0011D9F0* b);
struct Mat_0011D9F0 {
    Vec_0011D9F0 r[4];
    Mat_0011D9F0() {}
    const Vec_0011D9F0& operator[](int i) const { return r[i]; }
    Mat_0011D9F0(const Mat_0011D9F0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0011D9F0 operator*(Mat_0011D9F0& b);
    void operator*=(Mat_0011D9F0& b) { func_00323318(this, &b, this); }
    void InvertOrtho()
    {
        Vec_0011D9F0 t = r[3];
        r[3].x = -(t.x * r[0].x + t.y * r[0].y + t.z * r[0].z);
        r[3].y = -(t.x * r[1].x + t.y * r[1].y + t.z * r[1].z);
        r[3].z = -(t.x * r[2].x + t.y * r[2].y + t.z * r[2].z);
        float a01 = r[0].y;
        float a02 = r[0].z;
        float a12 = r[1].z;
        r[0].y = r[1].x;
        r[0].z = r[2].x;
        r[1].x = a01;
        r[1].z = r[2].y;
        r[2].x = a02;
        r[2].y = a12;
    }
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
};

struct E_0011D9F0 {
    int m0;
    Mat_0011D9F0* m_mat;
    char pad[0x28];
};

struct C_0011D9F0 {
    int m0;
    Mat_0011D9F0* m_mats;
    void* m_other;
    int mC;
    int m10;
    int m_count;
    E_0011D9F0* m_ents;
    void Update(Mat_0011D9F0* world, float a, float b, float c);
};

extern "C" Mat_0011D9F0* func_0011F540(void* o);
extern "C" int func_0011F4D0(void* o, int i);
extern "C" void func_00323318(Mat_0011D9F0* d, Mat_0011D9F0* a, Mat_0011D9F0* b);
extern "C" void func_00123608(Vec_0011D9F0* a, Vec_0011D9F0* b, float x, float y, float z);

inline Mat_0011D9F0 Mat_0011D9F0::operator*(Mat_0011D9F0& b)
{
    Mat_0011D9F0 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

void C_0011D9F0::Update(Mat_0011D9F0* world, float a, float b, float c)
{
    Mat_0011D9F0* inv = func_0011F540(m_other);
    for (int i = 0; i < m_count; i++) {
        E_0011D9F0* e = &m_ents[i];
        Mat_0011D9F0 t;
        Mat_0011D9F0 p;
        Mat_0011D9F0 cur = m_mats[i];
        t = inv[i];
        t.InvertOrtho();
        t = t * cur;
        t *= *world;
        cur = *e->m_mat;
        if (i == 0) {
            p.Ident();
        } else {
            p = inv[func_0011F4D0(m_other, i)];
        }
        p.InvertOrtho();
        p = p * cur;
        p *= *world;
        func_00123608(&t.r[3], &p.r[3], a, b, c);
    }
}
