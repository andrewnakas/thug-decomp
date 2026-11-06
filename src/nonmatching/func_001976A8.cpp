/* fuzzy: 66.7 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001976A8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_001976A8 {
    Vec_001976A8 r[4];
    Mat_001976A8() {}
    const Vec_001976A8& operator[](int i) const { return r[i]; }
    Mat_001976A8(const Mat_001976A8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_001976A8& operator=(const Mat_001976A8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_001976A8 operator*(Mat_001976A8& b);
    void operator*=(Mat_001976A8& b);
    void Transpose(Mat_001976A8& m);
};

extern "C" void func_00323318(Mat_001976A8* d, Mat_001976A8* a, Mat_001976A8* b);

inline Mat_001976A8 Mat_001976A8::operator*(Mat_001976A8& b)
{
    Mat_001976A8 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

inline void Mat_001976A8::operator*=(Mat_001976A8& b)
{
    *this = *this * b;
}

inline void Mat_001976A8::Transpose(Mat_001976A8& d)
{
    if (this == &d) {
        float a01 = d.r[0].y, a10 = d.r[1].x;
        float a02 = d.r[0].z, a20 = d.r[2].x;
        float a03 = d.r[0].w, a30 = d.r[3].x;
        float a12 = d.r[1].z, a21 = d.r[2].y;
        float a13 = d.r[1].w, a31 = d.r[3].y;
        float a23 = d.r[2].w, a32 = d.r[3].z;
        d.r[0].y = a10; d.r[1].x = a01;
        d.r[0].z = a20; d.r[2].x = a02;
        d.r[0].w = a30; d.r[3].x = a03;
        d.r[1].z = a21; d.r[2].y = a12;
        d.r[1].w = a31; d.r[3].y = a13;
        d.r[2].w = a32; d.r[3].z = a23;
    } else {
        float b00 = r[0].x; float b01 = r[0].y; float b02 = r[0].z; float b03 = r[0].w;
        float b10 = r[1].x; float b11 = r[1].y; float b12 = r[1].z; float b13 = r[1].w;
        float b20 = r[2].x; float b21 = r[2].y; float b22 = r[2].z; float b23 = r[2].w;
        float b30 = r[3].x; float b31 = r[3].y; float b32 = r[3].z; float b33 = r[3].w;
        d.r[0].x = b00; d.r[0].y = b10; d.r[0].z = b20; d.r[0].w = b30;
        d.r[1].x = b01; d.r[1].y = b11; d.r[1].z = b21; d.r[1].w = b31;
        d.r[2].x = b02; d.r[2].y = b12; d.r[2].z = b22; d.r[2].w = b32;
        d.r[3].x = b03; d.r[3].y = b13; d.r[3].z = b23; d.r[3].w = b33;
    }
}

class Obj_001976A8 {
public:
    char pad0[0x70];
    Mat_001976A8 m70;
    char padB0[0xD0 - 0xB0];
    Mat_001976A8 mD0;
    char pad110[0x190 - 0x110];
    Vec_001976A8 m190;

    void Update();
};

void Obj_001976A8::Update()
{
    mD0.r[2].x = m190.x * m70.r[2].x;
    mD0.r[2].y = m190.y * m70.r[2].y;
    mD0.r[2].z = m190.z * m70.r[2].z;
    mD0.r[0].x = m190.x * m70.r[0].x;
    mD0.r[0].y = m190.y * m70.r[0].y;
    mD0.r[0].z = m190.z * m70.r[0].z;
    mD0.r[1].x = m190.x * m70.r[1].x;
    mD0.r[1].y = m190.y * m70.r[1].y;
    mD0.r[1].z = m190.z * m70.r[1].z;
    Mat_001976A8 t;
    m70.Transpose(t);
    mD0 *= t;
}
