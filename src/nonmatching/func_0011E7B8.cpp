/* fuzzy: 88.6 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0011E7B8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};


struct Mat_0011E7B8 {
    Vec_0011E7B8 r[4];
    Mat_0011E7B8() {}
    const Vec_0011E7B8& operator[](int i) const { return r[i]; }
    Mat_0011E7B8(const Mat_0011E7B8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0011E7B8 operator*(Mat_0011E7B8& b);
    void SetTrans(float a, float b, float c, float d)
    {
        Vec_0011E7B8 o;
        o.Set(a, b, c, d);
        r[3] = o;
    }
    void InvertOrtho()
    {
        Vec_0011E7B8 t = r[3];
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
};

struct C_0011E7B8 {
    int m0;
    Mat_0011E7B8* m_mats;
    void* m_other;
    int GetRelMat(unsigned int id, Mat_0011E7B8* out);
};

extern "C" void* func_0011D4F0(C_0011E7B8* self, unsigned int id);
extern "C" int func_0011D798(C_0011E7B8* self, unsigned int id);
extern "C" Mat_0011E7B8* func_0011F540(void* o);
extern "C" void func_00323318(Mat_0011E7B8* d, Mat_0011E7B8* a, Mat_0011E7B8* b);

inline Mat_0011E7B8 Mat_0011E7B8::operator*(Mat_0011E7B8& b)
{
    Mat_0011E7B8 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

int C_0011E7B8::GetRelMat(unsigned int id, Mat_0011E7B8* out)
{
    void* e = func_0011D4F0(this, id);
    int idx = func_0011D798(this, id);
    if (!e)
        return 0;
    Mat_0011E7B8 a = m_mats[idx];
    Mat_0011E7B8 inv = func_0011F540(m_other)[idx];
    inv.InvertOrtho();
    inv = Mat_0011E7B8(inv * a);
    int j = func_0011D798(this, 0x9F173EEB);
    if (j != -1) {
        Vec_0011E7B8 save = inv.r[3];
        inv.SetTrans(0.0f, 0.0f, 0.0f, 1.0f);
        Mat_0011E7B8 root = func_0011F540(m_other)[j];
        inv = root * inv;
        inv.r[3] = save;
    }
    *out = inv;
    return 1;
}
