/* fuzzy: 91.1 */
// Script command: reads x/y offsets, a scale and an angle from the params and sets a 2D transform built
// around the centre of the unit square (translate -0.5, scale, rotate about z, translate back, offset).

typedef int qword __attribute__((mode(TI)));

struct Vec_00121200 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_00121200& operator+=(const Vec_00121200& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Mat_00121200;
extern "C" void func_00323318(Mat_00121200* out, const Mat_00121200* a, const Mat_00121200* b);

struct Mat_00121200 {
    Vec_00121200 row[4];
    void Mul(const Mat_00121200& b)
    {
        func_00323318(this, &b, this);
    }
    void Translate(const Vec_00121200& v)
    {
        row[3] += v;
    }
};

extern void* D_00389520;
extern void* D_00389518;
extern "C" void* func_0011FE68(void* owner);
extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
// builds a rotation matrix about axis (returned through the hidden result pointer)
extern "C" Mat_00121200 func_00100700(const Vec_00121200* axis, float angle);
extern "C" void func_0013E108(void* target, void* a, void* b, Mat_00121200* m);

// Single VU0 macro-mode operations (the vector unit has no C++ spelling).
static inline void LoadVF4(const Vec_00121200* p)
{
    __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p));
}

static inline void LoadVF5(const Vec_00121200* p)
{
    __asm__ __volatile__("lqc2 $vf5, 0(%0)" : : "r"(p));
}

static inline void MulVF6()
{
    __asm__ __volatile__("vmul.xyzw $vf6, $vf4, $vf5");
}

static inline void StoreVF6(Vec_00121200* p)
{
    __asm__ __volatile__("sqc2 $vf6, 0(%0)" : : "r"(p) : "memory");
}

// dst = a * b, component by component, on VU0
static inline void Mul_00121200(Vec_00121200* dst, const Vec_00121200* a, const Vec_00121200* b)
{
    LoadVF4(a);
    LoadVF5(b);
    MulVF6();
    StoreVF6(dst);
}

// every row of m multiplied by (s.x, s.y, s.z, 1), component by component
static inline void ScaleRows_00121200(Mat_00121200* m, Vec_00121200* s)
{
    s->w = 1.0f;
    Mul_00121200(&m->row[0], s, &m->row[0]);
    Mul_00121200(&m->row[1], s, &m->row[1]);
    Mul_00121200(&m->row[2], s, &m->row[2]);
    Mul_00121200(&m->row[3], s, &m->row[3]);
}

static inline void Identity_00121200(Mat_00121200* m)
{
    m->row[0].x = 1.0f;
    m->row[0].y = 0.0f;
    m->row[0].z = 0.0f;
    m->row[0].w = 0.0f;
    m->row[1].x = 0.0f;
    m->row[1].y = 1.0f;
    m->row[1].z = 0.0f;
    m->row[1].w = 0.0f;
    m->row[2].x = 0.0f;
    m->row[2].y = 0.0f;
    m->row[2].z = 1.0f;
    m->row[2].w = 0.0f;
    m->row[3].x = 0.0f;
    m->row[3].y = 0.0f;
    m->row[3].z = 0.0f;
    m->row[3].w = 1.0f;
}

extern "C" bool func_00121200(void* a0, void* a1, void* a, void* b)
{
    void* params = func_0011FE68(D_00389520);
    if (!params) {
        return true;
    }
    if (func_001E8618(params, 0x8602F6EE)) {
        int off;
        func_001E7DE8(params, 0x8602F6EE, &off, 0);
        if (off) {
            return false;
        }
    }
    float x, y, scale, angle;
    func_001E7EB0(params, 0xCF6AA087, &x, 1);
    func_001E7EB0(params, 0x5663F13D, &y, 1);
    func_001E7EB0(params, 0x266932C8, &scale, 1);
    func_001E7EB0(params, 0x1256B6C6, &angle, 1);

    Mat_00121200 m;
    Vec_00121200 v;
    Identity_00121200(&m);
    v.Set(-0.5f, -0.5f, 0.0f, 0.0f);
    m.Translate(v);
    v.y = v.z = v.x = scale * 0.01f;
    ScaleRows_00121200(&m, &v);

    v.Set(0.0f, 0.0f, 1.0f, 1.0f);
    Mat_00121200 r = func_00100700(&v, angle * 0.017453294f);
    m.Mul(r);

    v.Set(0.5f, 0.5f, 0.0f, 0.0f);
    m.Translate(v);
    v.Set(x * 0.01f, y * 0.01f, 0.0f, 0.0f);
    m.row[3].x += v.x * m.row[0].x + v.y * m.row[1].x;
    m.row[3].y += v.x * m.row[0].y + v.y * m.row[1].y;
    m.row[3].z += v.x * m.row[0].z + v.y * m.row[1].z;
    func_0013E108(D_00389518, a, b, &m);
    return true;
}
