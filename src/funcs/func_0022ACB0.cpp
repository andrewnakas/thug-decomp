typedef int qword __attribute__((mode(TI)));

extern int D_0038FC04;
extern float D_00394344;
extern float D_00394348;
extern void* D_0038C608;

union Vec_0022ACB0 {
    qword q;
    struct {
        float x, y, z, w;
    };
    Vec_0022ACB0& operator=(const Vec_0022ACB0& o)
    {
        q = o.q;
        return *this;
    }
};

union V4_0022ACB0 {
    qword q;
    struct {
        float x, y, z, w;
    };
    V4_0022ACB0() {}
    V4_0022ACB0(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Mat_0022ACB0 {
    Vec_0022ACB0 r[4];
    Mat_0022ACB0() {}
    const Vec_0022ACB0& operator[](int i) const { return r[i]; }
    Mat_0022ACB0 operator*(const Mat_0022ACB0& b) const;
    Mat_0022ACB0(const Mat_0022ACB0& o)
    {
        r[0].q = o[0].q;
        r[1].q = o[1].q;
        r[2].q = o[2].q;
        r[3].q = o[3].q;
    }
    Mat_0022ACB0& operator=(const Mat_0022ACB0& o)
    {
        r[0].q = o.r[0].q;
        r[1].q = o.r[1].q;
        r[2].q = o.r[2].q;
        r[3].q = o.r[3].q;
        return *this;
    }
};

extern "C" Mat_0022ACB0* func_00100700(Mat_0022ACB0* out, V4_0022ACB0* axis, float ang);
extern "C" Mat_0022ACB0* func_00100928(Mat_0022ACB0* out, float ang);
extern "C" void func_00323318(Mat_0022ACB0* d, const Mat_0022ACB0* a, Mat_0022ACB0* b);

inline Mat_0022ACB0 Mat_0022ACB0::operator*(const Mat_0022ACB0& b) const
{
    Mat_0022ACB0 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Cam_0022ACB0 {
    char pad0[0x70];
    Mat_0022ACB0 m70;
    char padB0[0x54];
    int m104;
};

struct Ctrl_0022ACB0 {
    char pad0[0x30];
    float m30;
    float m34;
    char pad38[8];
    float m40;
    float m44;
    char pad48[8];
    unsigned int m_flags;
    char pad54[4];
    int m_mode;
    char pad5C[4];
    void* m60;
};

extern "C" int func_0010FC30();
extern "C" Cam_0022ACB0* func_00187B48(void* mgr, unsigned int id);
extern "C" void func_00255A28(void* p, float a, float b);
extern "C" void func_0022B2E0(Cam_0022ACB0* cam, V4_0022ACB0* v);
extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" int func_0013B0E0();
extern "C" void func_0013B330(int v);

static inline void Dead_0022ACB0(float* p, float k)
{
    float v = *p;
    if (50.0f < v)
        v -= 50.0f;
    else if (v < -50.0f)
        v += 50.0f;
    else
        goto zero;
    v *= k;
    goto done;
zero:
    v = 0.0f;
done:
    *p = v;
}

class Viewer_0022ACB0 {
public:
    char pad0[0x20];
    Ctrl_0022ACB0* m20;
    void Update();
};

void Viewer_0022ACB0::Update()
{
    Ctrl_0022ACB0* c = m20;
    int last = D_0038FC04;
    int delta = func_0010FC30() - last;
    D_0038FC04 += delta;
    float dt = delta * 0.001000000047f;
    if (c->m_flags & 0x4000) {
        if (c->m60 && !c->m_mode)
            c->m_mode = 1;
        else
            c->m_mode = 0;
    }
    Dead_0022ACB0(&c->m34, 0.01282051299f);
    Dead_0022ACB0(&c->m30, 0.01282051299f);
    Dead_0022ACB0(&c->m44, 0.01282051299f);
    Dead_0022ACB0(&c->m40, 0.01282051299f);
    Cam_0022ACB0* cam = func_00187B48(D_0038C608, 0xEB17151B);
    if (cam) {
        if (c->m_mode == 0) {
            if (c->m44 != 0.0f) {
                V4_0022ACB0 axis(1.0f, 0.0f, 0.0f, 1.0f);
                Mat_0022ACB0& m = cam->m70;
                Mat_0022ACB0 rot;
                func_00100700(&rot, &axis, c->m44 * dt * D_00394344 * 0.01745329425f);
                m = rot * m;
            }
            if (c->m40 != 0.0f) {
                Mat_0022ACB0 t = cam->m70;
                Mat_0022ACB0& m = cam->m70;
                Mat_0022ACB0 rm;
                func_00323318(&t, func_00100928(&rm, -c->m40 * dt * D_00394344 * 0.01745329425f), &t);
                m = t;
            }
        } else if (c->m_mode == 1) {
            func_00255A28(c->m60, c->m40, c->m44);
        }
        float dx = c->m30;
        if (dx != 0.0f || c->m34 != 0.0f) {
            float s = dt * D_00394348;
            V4_0022ACB0 v;
            v.x = dx * s;
            v.y = 0.0f;
            v.z = c->m34 * s;
            v.w = 1.0f;
            func_0022B2E0(cam, &v);
        }
    }
    if (c->m_flags & 2) {
        V4_0022ACB0 v(0.0f, dt * D_00394348, 0.0f, 1.0f);
        func_0022B2E0(cam, &v);
    }
    if (c->m_flags & 4) {
        V4_0022ACB0 v(0.0f, -dt * D_00394348, 0.0f, 1.0f);
        func_0022B2E0(cam, &v);
    }
    if (!func_001E5628(0xD8C91578, 0)) {
        if (c->m_flags & 0x10000) {
            V4_0022ACB0 axis(0.0f, 0.0f, 1.0f, 1.0f);
            Mat_0022ACB0& m = cam->m70;
            Mat_0022ACB0 rot;
            float speed = D_00394344 * -0.5f;
            func_00100700(&rot, &axis, dt * speed * 0.01745329425f);
            m = rot * m;
        }
        if (c->m_flags & 0x20000) {
            V4_0022ACB0 axis(0.0f, 0.0f, 1.0f, 1.0f);
            Mat_0022ACB0& m = cam->m70;
            Mat_0022ACB0 rot;
            float speed = D_00394344 * 0.5f;
            func_00100700(&rot, &axis, dt * speed * 0.01745329425f);
            m = rot * m;
        }
    }
    cam->m104 &= ~1;
    if (c->m_flags & 0x1000)
        func_0013B330((func_0013B0E0() + 1) % 6);
    c->m_flags = 0;
}
