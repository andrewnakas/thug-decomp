typedef int qword __attribute__((mode(TI)));

struct Vec_0011EAF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0011EAF0 {
    Vec_0011EAF0 r[4];
    Mat_0011EAF0() {}
    const Vec_0011EAF0& operator[](int i) const { return r[i]; }
    Mat_0011EAF0(const Mat_0011EAF0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0011EAF0 operator*(Mat_0011EAF0& b);
};

struct C_0011EAF0 {
    int m0;
    Mat_0011EAF0* m_mats;
    void* m_other;
    int GetRel(unsigned int id, Vec_0011EAF0* out);
};

extern "C" void* func_0011D4F0(C_0011EAF0* self, unsigned int id);
extern "C" int func_0011D798(C_0011EAF0* self, unsigned int id);
extern "C" Mat_0011EAF0* func_0011F540(void* o);
extern "C" void func_00323318(Mat_0011EAF0* d, Mat_0011EAF0* a, Mat_0011EAF0* b);

inline Mat_0011EAF0 Mat_0011EAF0::operator*(Mat_0011EAF0& b)
{
    Mat_0011EAF0 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

int C_0011EAF0::GetRel(unsigned int id, Vec_0011EAF0* out)
{
    void* e = func_0011D4F0(this, id);
    int idx = func_0011D798(this, id);
    if (!e)
        return 0;
    Mat_0011EAF0 a = m_mats[idx];
    Mat_0011EAF0 inv = func_0011F540(m_other)[idx];
    Vec_0011EAF0 t = inv.r[3];
    inv.r[3].x = -(t.x * inv.r[0].x + t.y * inv.r[0].y + t.z * inv.r[0].z);
    inv.r[3].y = -(t.x * inv.r[1].x + t.y * inv.r[1].y + t.z * inv.r[1].z);
    inv.r[3].z = -(t.x * inv.r[2].x + t.y * inv.r[2].y + t.z * inv.r[2].z);
    float a01 = inv.r[0].y;
    float a02 = inv.r[0].z;
    float a12 = inv.r[1].z;
    inv.r[0].y = inv.r[1].x;
    inv.r[0].z = inv.r[2].x;
    inv.r[1].x = a01;
    inv.r[1].z = inv.r[2].y;
    inv.r[2].x = a02;
    inv.r[2].y = a12;
    inv = inv * a;
    *out = inv.r[3];
    return 1;
}
