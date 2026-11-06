typedef int qword_00267E30 __attribute__((mode(TI)));

struct Vec_00267E30 {
    union {
        qword_00267E30 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_00267E30() {}
    Vec_00267E30(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

union Row_00267E30 {
    qword_00267E30 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Mat_00267E30 {
    Row_00267E30 r[4];
    Mat_00267E30() {}
    const Row_00267E30& operator[](int i) const { return r[i]; }
    Mat_00267E30(const Mat_00267E30& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_00267E30& operator=(const Mat_00267E30& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Obj_00267E30 {
    char pad0[0x50];
    Vec_00267E30 m50;
    char pad60[0x10];
    Mat_00267E30 m70;
    char padB0[0x160 - 0xB0];
    Obj_00267E30* m160;
    int pad164;
    int m168;

    void Update();
};

extern "C" void* func_00256BA0(Obj_00267E30* o);
extern "C" int func_0011E7B8(void* skel, unsigned int crc, Mat_00267E30* out);
extern "C" Mat_00267E30* func_00100890(Mat_00267E30* out, float a);
extern "C" void func_00323318(Mat_00267E30* d, Mat_00267E30* a, Mat_00267E30* b);
extern "C" Vec_00267E30 func_00323298(Mat_00267E30* m, Row_00267E30* v);

static inline Mat_00267E30 operator*(const Mat_00267E30& a, const Mat_00267E30& b)
{
    Mat_00267E30 r = b;
    func_00323318(&r, (Mat_00267E30*)&a, &r);
    return r;
}

static inline Vec_00267E30 operator*(const Mat_00267E30& a, const Row_00267E30& b)
{
    Vec_00267E30 r = func_00323298((Mat_00267E30*)&a, (Row_00267E30*)&b);
    return r;
}

void Obj_00267E30::Update()
{
    if (!m168)
        return;
    Mat_00267E30* m = &m70;
    func_0011E7B8(func_00256BA0(m160), 0xDDEC28AF, m);
    {
        Mat_00267E30 rot;
        *m = *m * *func_00100890(&rot, 90.0f);
    }
    {
        Vec_00267E30 off(0.0f, 0.0f, -18.0f, 0.0f);
        m70.r[3].f.x += m->r[0].f.x * off.f.x + m->r[1].f.x * off.f.y + m->r[2].f.x * off.f.z;
        m70.r[3].f.y += m->r[0].f.y * off.f.x + m->r[1].f.y * off.f.y + m->r[2].f.y * off.f.z;
        m70.r[3].f.z += m->r[0].f.z * off.f.x + m->r[1].f.z * off.f.y + m->r[2].f.z * off.f.z;
    }
    Row_00267E30 pos = m70.r[3];
    m70.r[3].q = Vec_00267E30(0.0f, 0.0f, 0.0f, 1.0f).q;
    *m = m160->m70 * *m;
    m50 = m160->m70 * pos;
    Vec_00267E30* v = &m50;
    Obj_00267E30* o = m160;
    v->f.x += o->m50.f.x;
    v->f.y += o->m50.f.y;
    v->f.z += o->m50.f.z;
    v->f.w += o->m50.f.w;
}
