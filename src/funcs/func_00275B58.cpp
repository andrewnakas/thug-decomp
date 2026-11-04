typedef int qword __attribute__((mode(TI)));

struct Vec_00275B58 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00275B58;
extern "C" void func_00323318(Mat_00275B58* d, const Mat_00275B58* a, Mat_00275B58* b);
extern "C" Mat_00275B58* func_00100928(Mat_00275B58* out, float a);

struct Mat_00275B58 {
    Vec_00275B58 r[4];
    Mat_00275B58() {}
    const Vec_00275B58& operator[](int i) const { return r[i]; }
    Mat_00275B58(const Mat_00275B58& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_00275B58 operator*(const Mat_00275B58& b) const;
};

inline Mat_00275B58 Mat_00275B58::operator*(const Mat_00275B58& b) const
{
    Mat_00275B58 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Body_00275B58 {
    char pad[0x70];
    Mat_00275B58 m70;
    Vec_00275B58 mB0;
};

struct Obj_00275B58 {
    char pad[0xC];
    Body_00275B58* mC;
    float Align(const Vec_00275B58* up, float* out);
};

static inline float Clamp_00275B58(float v, float lo, float hi)
{
    if (v > hi) v = hi;
    if (v < lo) v = lo;
    return v;
}

extern "C" float func_003412F0(float x);
extern "C" float func_00341068(float x);
extern "C" float func_00340F60(float x);
extern "C" float func_002032A0(unsigned int name, int a);

float Obj_00275B58::Align(const Vec_00275B58* up, float* out)
{
    Body_00275B58* b = mC;
    float d = b->m70.r[0].x * up->x + b->m70.r[0].y * up->y + b->m70.r[0].z * up->z;
    d = Clamp_00275B58(d, -1.0f, 1.0f);
    float a = func_003412F0(d);
    if (a > 1.570796371f) a -= 3.141592741f;
    float t = a * func_002032A0(0xE07EE1A9, 0);
    *out = t;
    Vec_00275B58& p = mC->mB0;
    float s = func_00341068(t);
    float c = func_00340F60(t);
    float x = p.x;
    float z = p.z;
    p.x = c * x + s * z;
    p.z = -s * x + c * z;
    Mat_00275B58& m = mC->m70;
    m = *func_00100928((Mat_00275B58*)0x70003FC0, *out) * m;
    return a;
}
