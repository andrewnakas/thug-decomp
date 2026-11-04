typedef int qword __attribute__((mode(TI)));

struct Vec_0014DC60 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0014DC60 {
    Vec_0014DC60 r[4];
    Mat_0014DC60() {}
    const Vec_0014DC60& operator[](int i) const { return r[i]; }
    Mat_0014DC60(const Mat_0014DC60& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0014DC60 operator*(Mat_0014DC60& b);
};

extern "C" Mat_0014DC60* func_00100928(Mat_0014DC60* out, float a);
extern "C" void func_00323318(Mat_0014DC60* d, Mat_0014DC60* a, Mat_0014DC60* b);
extern "C" void func_001711F8(void* p, Vec_0014DC60* v, int a, int one);

inline Mat_0014DC60 Mat_0014DC60::operator*(Mat_0014DC60& b)
{
    Mat_0014DC60 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Obj_0014DC60 {
    char pad0[4];
    int m4;
    char pad8[0x20 - 8];
    void* m20;
    char pad24[0x30 - 0x24];
    Mat_0014DC60 m30;
    void Rotate(int a);
    void Update();
};

extern "C" void func_0014E048(Obj_0014DC60* self);

void Obj_0014DC60::Rotate(int a)
{
    Mat_0014DC60 m = m30;
    Mat_0014DC60 r;
    func_00100928(&r, (float)a * 1.57079637f);
    Vec_0014DC60 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;
    w.w = 1.0f;
    m.r[3] = w;
    r = m * r;
    m30.r[0] = r.r[0];
    m30.r[1] = r.r[1];
    m30.r[2] = r.r[2];
    if (m4 != 2) {
        func_0014E048(this);
    } else {
        func_001711F8(m20, &m30.r[3], a, 1);
    }
}
