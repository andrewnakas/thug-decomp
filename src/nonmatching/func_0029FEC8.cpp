/* fuzzy: 94.9 */
typedef int qword __attribute__((mode(TI)));
union Vec_0029FEC8 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0029FEC8() {}
    Vec_0029FEC8(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    Vec_0029FEC8(float x, float y, float z)
    {
        c[3] = 0.0f;
        c[1] = y;
        c[0] = x;
        c[2] = z;
    }
    Vec_0029FEC8& operator=(const Vec_0029FEC8& o)
    {
        q = o.q;
        return *this;
    }
    void operator+=(const Vec_0029FEC8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};

struct Mat_0029FEC8 {
    Vec_0029FEC8 r0;
    Vec_0029FEC8 r1;
    Vec_0029FEC8 r2;
    Vec_0029FEC8 r3;
    Mat_0029FEC8() {}
    const Vec_0029FEC8& operator[](int i) const { return (&r0)[i]; }
    Mat_0029FEC8(const Mat_0029FEC8& o) : r0(o[0]), r1(o[1]), r2(o[2]), r3(o[3]) {}
    Mat_0029FEC8& operator=(const Mat_0029FEC8& o)
    {
        r0.q = o.r0.q;
        r1.q = o.r1.q;
        r2.q = o.r2.q;
        r3.q = o.r3.q;
        return *this;
    }
    Mat_0029FEC8 operator*(const Mat_0029FEC8& b) const;
    void Translate(const Vec_0029FEC8& v)
    {
        r3.c[0] += v.c[0] * r0.c[0] + v.c[1] * r1.c[0] + v.c[2] * r2.c[0];
        r3.c[1] += v.c[0] * r0.c[1] + v.c[1] * r1.c[1] + v.c[2] * r2.c[1];
        r3.c[2] += v.c[0] * r0.c[2] + v.c[1] * r1.c[2] + v.c[2] * r2.c[2];
    }
};

extern "C" void func_00323318(Mat_0029FEC8* out, const Mat_0029FEC8* a, Mat_0029FEC8* b);
extern "C" void func_00323298(Vec_0029FEC8* out, const Mat_0029FEC8* m, const Vec_0029FEC8* v);

inline Mat_0029FEC8 Mat_0029FEC8::operator*(const Mat_0029FEC8& b) const
{
    Mat_0029FEC8 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}
static inline Vec_0029FEC8 operator*(const Mat_0029FEC8& m, const Vec_0029FEC8& v)
{
    Vec_0029FEC8 r;
    func_00323298(&r, &m, &v);
    return r;
}

extern char D_00371C78[];
struct Iter_0029FEC8 {
    int m0;
    int m4;
    void* m8;
    Iter_0029FEC8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_0029FEC8() { m8 = D_00371C78; }
};

struct Model_0029FEC8 {
    char pad0[0x50];
    Vec_0029FEC8 m50;
    char pad60[0x70 - 0x60];
    Mat_0029FEC8 m70;
};
struct Elem_0029FEC8 {
    char pad0[0x18];
    Model_0029FEC8* m18;
};
struct Obj_0029FEC8 {
    char pad0[0x50];
    Vec_0029FEC8 m50;
    char pad60[0x70 - 0x60];
    Mat_0029FEC8 m70;
};

extern void* D_0038FC78;
extern void* D_00392068;
extern char D_003920A0[];
extern char D_00377ED8[];
extern char D_00377EE8[];
extern char D_00377EF8[];
extern char D_00377F08[];

extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(const char* s);
extern "C" Elem_0029FEC8* func_002A53F8(void* self, Iter_0029FEC8* it, int a);
extern "C" Elem_0029FEC8* func_002A5490(void* self, Iter_0029FEC8* it, int a);
extern "C" int func_002B22B8(Elem_0029FEC8* e);
extern "C" int func_002B22C8(Elem_0029FEC8* e);
extern "C" Obj_0029FEC8* func_00184D70(int id);
extern "C" void* func_00256BA0(Model_0029FEC8* m);
extern "C" int func_0011E7B8(void* p, unsigned int name, Mat_0029FEC8* m);
extern "C" Mat_0029FEC8* func_00100890(Mat_0029FEC8* out, float deg);

void Place_0029FEC8()
{
    Iter_0029FEC8 it;
    void* mgr = D_00392068;
    if (func_0024F938(func_0022E358(D_0038FC78)) != func_001F0D78(D_003920A0))
        return;
    for (Elem_0029FEC8* e = func_002A53F8(mgr, &it, 0); e; e = func_002A5490(mgr, &it, 0)) {
        if (!func_002B22B8(e))
            continue;
        int id;
        switch (func_002B22C8(e)) {
        case 0:
            id = func_001F0D78(D_00377ED8);
            break;
        case 1:
            id = func_001F0D78(D_00377EE8);
            break;
        case 2:
            id = func_001F0D78(D_00377EF8);
            break;
        case 3:
            id = func_001F0D78(D_00377F08);
            break;
        default:
            id = 0;
            break;
        }
        Obj_0029FEC8* o = func_00184D70(id);
        if (!o)
            return;
        Mat_0029FEC8* m = &o->m70;
        func_0011E7B8(func_00256BA0(e->m18), 0xDDEC28AF, m);
        {
            Mat_0029FEC8 rot;
            *m = *func_00100890(&rot, 90.0f) * *m;
        }
        Vec_0029FEC8 v(0.0f, 12.0f, 0.0f);
        o->m70.r3.c[0] += v.c[0] * m->r0.c[0] + v.c[1] * m->r1.c[0] + v.c[2] * m->r2.c[0];
        o->m70.r3.c[1] += v.c[0] * m->r0.c[1] + v.c[1] * m->r1.c[1] + v.c[2] * m->r2.c[1];
        o->m70.r3.c[2] += v.c[0] * m->r0.c[2] + v.c[1] * m->r1.c[2] + v.c[2] * m->r2.c[2];
        v = m->r3;
        m->r3 = Vec_0029FEC8(0.0f, 0.0f, 0.0f, 1.0f);
        *m = *m * e->m18->m70;
        o->m50 = e->m18->m70 * v;
        o->m50 += e->m18->m50;
    }
}
