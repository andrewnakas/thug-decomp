typedef int qword __attribute__((mode(TI)));

struct Row_0025B828 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};
struct Vec_0025B828 : Row_0025B828 {
    Vec_0025B828() {}
    Vec_0025B828(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_0025B828 operator-(const Row_0025B828& a, const Row_0025B828& b) { return Vec_0025B828(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vec_0025B828 Cross(const Row_0025B828& a, const Row_0025B828& b)
{
    return Vec_0025B828(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

extern "C" void func_003233B8(Row_0025B828* d, Row_0025B828* s);
struct Mat_0025B828 {
    Row_0025B828 r[4];
    Row_0025B828& operator[](int i) { return r[i]; }
    const Row_0025B828& operator[](int i) const { return r[i]; }
    Mat_0025B828() {}
    Mat_0025B828(const Mat_0025B828& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0025B828& operator=(const Mat_0025B828& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    void Ident()
    {
        r[0][0] = 1.0f; r[0][1] = 0.0f; r[0][2] = 0.0f; r[0][3] = 0.0f;
        r[1][0] = 0.0f; r[1][1] = 1.0f; r[1][2] = 0.0f; r[1][3] = 0.0f;
        r[2][0] = 0.0f; r[2][1] = 0.0f; r[2][2] = 1.0f; r[2][3] = 0.0f;
        r[3][0] = 0.0f; r[3][1] = 0.0f; r[3][2] = 0.0f; r[3][3] = 1.0f;
    }
    void FromQuat(const Row_0025B828& q, const Row_0025B828& t)
    {
        Row_0025B828 s, c, w;
        s[0] = q[0] * q[0];
        s[1] = q[1] * q[1];
        s[2] = q[2] * q[2];
        c[0] = q[1] * q[2];
        c[1] = q[2] * q[0];
        c[2] = q[0] * q[1];
        w[0] = q[3] * q[0];
        w[1] = q[3] * q[1];
        w[2] = q[3] * q[2];
        r[0][0] = 1.0f - (s[1] + s[2]) * 2.0f;
        r[0][1] = (c[2] + w[2]) * 2.0f;
        r[0][2] = (c[1] - w[1]) * 2.0f;
        r[0][3] = 0.0f;
        r[1][0] = (c[2] - w[2]) * 2.0f;
        r[1][1] = 1.0f - (s[0] + s[2]) * 2.0f;
        r[1][2] = (c[0] + w[0]) * 2.0f;
        r[1][3] = 0.0f;
        r[2][0] = (c[1] + w[1]) * 2.0f;
        r[2][1] = (c[0] - w[0]) * 2.0f;
        r[2][2] = 1.0f - (s[0] + s[1]) * 2.0f;
        r[2][3] = 0.0f;
        r[3] = t;
        r[3][3] = 1.0f;
    }
};

static inline void Orient(Mat_0025B828* mat, Row_0025B828& t)
{
    func_003233B8(&t, &t);
    mat->Ident();
    (*mat)[2] = t;
    (*mat)[0] = Cross((*mat)[1], (*mat)[2]);
    func_003233B8(&(*mat)[0], &(*mat)[0]);
    (*mat)[1] = Cross((*mat)[2], (*mat)[0]);
}

struct Ent_0025B828 {
    char pad0[0x1C];
    struct { char pad[0x20]; int m20; }* m1C;
};
struct Game_0025B828 {
    char pad0[0x28];
    Ent_0025B828* m28[2];
};
struct Tgt_0025B828 {
    char pad0[0x50];
    Row_0025B828 m50;
    char pad60[0x10];
    Mat_0025B828 m70;
};

extern Game_0025B828* D_00390828;
extern void* D_0038FC78;
extern "C" Row_0025B828* func_00114E18(void* p);
extern "C" Mat_0025B828* func_00114E48(void* p);
extern "C" void func_00114D28(void* p, float f);
extern "C" float func_001E5318(unsigned int name, int a);
extern "C" void* func_0022E040(void* p);
extern "C" Tgt_0025B828* func_00187B48(void* mgr, unsigned int id);

struct Obj_0025B828;
extern "C" void func_0025AB18(Obj_0025B828* self, int a);
extern "C" void func_0025B730(Obj_0025B828* self, Vec_0025B828* q, Vec_0025B828* p);

struct Obj_0025B828 {
    char pad0[0x18];
    void* m18;
    char pad1C[0x3C - 0x1C];
    int m3C;
    unsigned int m40;
    char pad44[0xC];
    Row_0025B828 m50;
    Row_0025B828 m60;
    int m70;
    int m74;
    int m78;
    void Update();
};

void Obj_0025B828::Update()
{
    Row_0025B828* pos = func_00114E18(m18);
    Mat_0025B828* mat = func_00114E48(m18);
    Ent_0025B828** e = D_00390828->m28;
    for (int i = 0; i < 2; i++) {
        if (e[i]->m1C->m20 & 0x40)
            func_0025AB18(this, 1);
    }
    if (m78) {
        Vec_0025B828 q(0.0f, 0.0f, 0.0f, 1.0f);
        Vec_0025B828 p;
        func_0025B730(this, &q, &p);
        *pos = p;
        Vec_0025B828 one(0.0f, 0.0f, 0.0f, 1.0f);
        q[0] = -q[0];
        q[1] = -q[1];
        q[2] = -q[2];
        mat->FromQuat(q, one);
    } else {
        *pos = Vec_0025B828(0.0f, 0.0f, 0.0f, 1.0f);
        mat->Ident();
        func_00114D28(m18, func_001E5318(0x99529205, 0));
    }
    if (!m3C) return;
    Row_0025B828 p;
    if (m40 != 0xC588EEBC) {
        Tgt_0025B828* o = func_00187B48(func_0022E040(D_0038FC78), m40);
        if (!o) return;
        p = o->m50;
        p[3] = 1.0f;
        if (m70) {
            Mat_0025B828 m = o->m70;
            m[3] = p;
            m[3][0] += m50[0] * m[0][0] + m50[1] * m[1][0] + m50[2] * m[2][0];
            m[3][1] += m50[0] * m[0][1] + m50[1] * m[1][1] + m50[2] * m[2][1];
            m[3][2] += m50[0] * m[0][2] + m50[1] * m[1][2] + m50[2] * m[2][2];
            p = m[3];
        }
        if (m74) {
            *pos = p;
            Mat_0025B828 m = o->m70;
            m[3] = p;
            m[3][0] += m60[0] * m[0][0] + m60[1] * m[1][0] + m60[2] * m[2][0];
            m[3][1] += m60[0] * m[0][1] + m60[1] * m[1][1] + m60[2] * m[2][1];
            m[3][2] += m60[0] * m[0][2] + m60[1] * m[1][2] + m60[2] * m[2][2];
            *pos = m[3];
        }
        Vec_0025B828 t = *pos - p;
        Orient(mat, t);
    } else {
        p = m50;
        *pos = m60;
        Vec_0025B828 t = *pos - p;
        t[3] = 1.0f;
        Orient(mat, t);
    }
}
