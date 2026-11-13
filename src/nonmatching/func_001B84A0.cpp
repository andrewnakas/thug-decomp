/* fuzzy: 97.5 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_001B84A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Row_001B84A0() {}
    const float& operator[](int i) const { return (&x)[i]; }
    Row_001B84A0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Dot(const Row_001B84A0& o) const { return x * o[0] + y * o[1] + z * o[2]; }
    Row_001B84A0& operator+=(const Row_001B84A0& o)
    {
        x += o[0];
        y += o[1];
        z += o[2];
        w += o[3];
        return *this;
    }
    Row_001B84A0& operator-=(const Row_001B84A0& o)
    {
        x -= o[0];
        y -= o[1];
        z -= o[2];
        w -= o[3];
        return *this;
    }
};

static inline Row_001B84A0 operator*(const Row_001B84A0& v, float s)
{
    return Row_001B84A0(v[0] * s, v[1] * s, v[2] * s, v[3] * s);
}

static inline Row_001B84A0 operator+(const Row_001B84A0& a, const Row_001B84A0& b)
{
    return Row_001B84A0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Row_001B84A0 operator-(const Row_001B84A0& a, const Row_001B84A0& b)
{
    return Row_001B84A0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

static inline Row_001B84A0 Cross_001B84A0(const Row_001B84A0& b, const Row_001B84A0& c)
{
    return Row_001B84A0(b[1] * c[2] - b[2] * c[1], b[2] * c[0] - b[0] * c[2], b[0] * c[1] - b[1] * c[0], 0.0f);
}

struct Mat_001B84A0;
extern "C" Mat_001B84A0* func_00323318(Mat_001B84A0* out, const Mat_001B84A0* a, const Mat_001B84A0* b);

struct Mat_001B84A0 {
    Row_001B84A0 right;
    Row_001B84A0 up;
    Row_001B84A0 at;
    Row_001B84A0 trans;
    Mat_001B84A0() {}
    Row_001B84A0& operator[](int i) { return (&right)[i]; }
    const Row_001B84A0& operator[](int i) const { return (&right)[i]; }
    Mat_001B84A0(const Mat_001B84A0& o)
    {
        right = o[0];
        up = o[1];
        at = o[2];
        trans = o[3];
    }
    Mat_001B84A0& operator=(const Mat_001B84A0& o)
    {
        right = o[0];
        up = o[1];
        at = o[2];
        trans = o[3];
        return *this;
    }
};

static inline Mat_001B84A0 operator*(const Mat_001B84A0& a, const Mat_001B84A0& b)
{
    Mat_001B84A0 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

extern "C" void func_003233B8(Row_001B84A0* out, const Row_001B84A0* in);
extern "C" Mat_001B84A0* func_00100928(Mat_001B84A0* out, float angle);
extern "C" void func_00100200(Mat_001B84A0* m, float x, float y, float z);

static inline void Normalize_001B84A0(Row_001B84A0& v)
{
    func_003233B8(&v, &v);
}

// a = Normalize(b x c)
static inline void CrossN_001B84A0(Row_001B84A0& a, const Row_001B84A0& b, const Row_001B84A0& c)
{
    a = Cross_001B84A0(b, c);
    Normalize_001B84A0(a);
}

static inline void RotateY_001B84A0(Mat_001B84A0& m, float angle)
{
    Mat_001B84A0 tmp;
    func_00323318(&m, func_00100928(&tmp, angle), &m);
}

// v = v rotated by angle about axis (via a quaternion).
extern "C" void func_001BA4F0(Row_001B84A0* q, const Row_001B84A0* axis, float angle);
extern "C" void func_001BA5D0(Row_001B84A0* out, Row_001B84A0* q, Row_001B84A0* v);

static inline void RotateAbout_001B84A0(Row_001B84A0& v, const Row_001B84A0& axis, float angle)
{
    Row_001B84A0 q;
    Row_001B84A0 r;
    func_001BA4F0(&q, &axis, angle);
    func_001BA5D0(&r, &q, &v);
    v = r;
}

struct Feeler_001B84A0 {
    char pad0[0x90];
    float m90;
    char pad94[0xC0 - 0x94];
    void* mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" void func_00209240(Feeler_001B84A0* f);
extern "C" void func_00209350(Feeler_001B84A0* f, int a, int b);
extern "C" int func_002099C0(Feeler_001B84A0* f, Row_001B84A0* start, Row_001B84A0* end, int a);
extern "C" void func_00183CB8(void* p, void** slot);

struct Owner_001B84A0 {
    char pad0[0x104];
    unsigned int m104;
};

struct Node_001B84A0 {
    char pad0[0x1C];
    int m1C;
    int m20;
    char pad24[4];
    float m28;
    float m2C;
    float m30;
};

struct Cfg_001B84A0 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x40 - 0x20];
    int m40;
    char pad44[0x64 - 0x44];
    int m64;
    char pad68[0xAC - 0x68];
    int mAC;
    char padB0[0xF4 - 0xB0];
    int mF4;
    char padF8[0x140 - 0xF8];
    Row_001B84A0 m140;
    char pad150[0x10];
    Row_001B84A0 m160;
    Row_001B84A0 m170;
};

struct Lock_001B84A0 {
    char pad0[0x180];
    int m180;
};

struct Link_001B84A0 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x34 - 0x20];
    Lock_001B84A0* m34;
};

struct Skater_001B84A0 {
    char pad0[0x28];
    unsigned int m28;
    char pad2C[0x50 - 0x2C];
    Row_001B84A0 m50;
    char pad60[0xB0 - 0x60];
    Row_001B84A0 mB0;
    Mat_001B84A0 mC0;
    char pad100[4];
    unsigned int m104;
    char pad108[0x31C - 0x108];
    int m31C;
    bool TestFlag(unsigned int f) const { return (m104 & f) != 0; }
};

struct Board_001B84A0 {
    char pad0[0xEC];
    float mEC;
};

struct Flag_001B84A0 {
    char pad0[0x1C];
    int m1C;
};

struct Phys_001B84A0 {
    char pad0[0x440];
    Mat_001B84A0 m440;
    char pad480[0x5B4 - 0x480];
    Flag_001B84A0* m5B4;
};

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" float func_0010FAB8();

// Frame time in 60 Hz frames.
static inline float Frames_001B84A0() { return func_0010FAB8() * 60.0f; }
extern "C" void func_001B80F8(void* cam);
extern "C" Mat_001B84A0* func_001B80E8(void* cam);
extern "C" void func_001B80D8(void* cam, Row_001B84A0* pos);
extern "C" Mat_001B84A0* func_00206900(Skater_001B84A0* s);
extern "C" int func_001E53A0(unsigned int name, int a);
extern "C" void func_00103000(void* interp, Mat_001B84A0* from, Mat_001B84A0* to);
extern "C" void func_00103930(void* interp, Mat_001B84A0* out, float t);
extern "C" float func_0018B1D0(float rate, float dt);
extern "C" void func_0018B200(Row_001B84A0* pos, Mat_001B84A0* m, Row_001B84A0* from, Row_001B84A0* target, int a, int b);
extern float D_0038D3C0;
extern float D_00387A08;
extern float D_00387A0C;
extern float D_00387A10;
extern float D_00387A14;
extern float D_00387A18;
extern float D_00387A1C;
extern float D_00387A20;
extern float D_00387A24;
extern float D_00387A28;
extern float D_00387A2C;
extern float D_00387A30;
extern float D_00387A34;

struct Cam_001B84A0;
extern "C" int func_001B9E30(Cam_001B84A0* self);
extern "C" void func_001BA3B8(Cam_001B84A0* self);
extern "C" void func_001B8148(Mat_001B84A0* m, float angle);
extern "C" void func_001BA000(Row_001B84A0* pos, Cam_001B84A0* self, int instant);
extern "C" void func_001BA1F8(Cam_001B84A0* self, float* up, float* back);
extern "C" void func_001B9E98(Cam_001B84A0* self, Row_001B84A0* pos, Mat_001B84A0* m);

struct Cam_001B84A0 {
    char pad0[0xC];
    Owner_001B84A0* mC;
    char pad10[0x30 - 0x10];
    int m30;
    float m34;
    char pad38[0x50 - 0x38];
    Row_001B84A0 m50;
    Row_001B84A0 m60;
    Row_001B84A0 m70;
    Mat_001B84A0 m80;
    char padC0[0xD8 - 0xC0];
    float mD8;
    char padDC[0xF0 - 0xDC];
    float mF0;
    char padF4[0x10C - 0xF4];
    float m10C;
    char pad110[0x11C - 0x110];
    int m11C;
    float m120;
    float m124;
    float m128;
    float m12C;
    char pad130[0x138 - 0x130];
    float m138;
    float m13C;
    float m140;
    char pad144[4];
    float m148;
    char pad14C[0x160 - 0x14C];
    Node_001B84A0* m160;
    void* m164;
    Skater_001B84A0* m168;
    Cfg_001B84A0* m16C;
    Link_001B84A0* m170;
    void Update();
};

void Cam_001B84A0::Update()
{
    if (!m168) {
        return;
    }
    if (m170 && m170->m34->m180) {
        mC->m104 |= 1;
        return;
    }
    void* cam = func_00185578(mC, 0xC4E311FA);
    int instant = m168->TestFlag(8);
    if (instant) {
        m30 = 3;
    }
    if (m30 > 0) {
        instant = 1;
        m30--;
    }
    float dt = func_0010FAB8();
    func_001BA3B8(this);
    func_001B80F8(cam);
    Mat_001B84A0* cm = func_001B80E8(cam);
    cm->right = m50;
    cm->up = m60;
    cm->at = m70;
    Row_001B84A0 fwd(cm->at.x, cm->at.y, cm->at.z, 1.0f);

    // Basis the camera follows.
    int mode = m16C->m1C;
    Mat_001B84A0 basis;
    if (mode == 2) {
        basis = m80;
    } else {
        if (m168->m31C) {
            basis = *func_00206900(m168);
        } else {
            basis = m168->mC0;
        }
        m80 = basis;
    }
    float tilt = 0.0f;
    if (mode == 4 && m168->m31C) {
        tilt = ((Board_001B84A0*)func_00185578(m168, 0x589E5FB3))->mEC * D_00387A08;
    }
    if (tilt != m120) {
        if (!instant) {
            tilt = m120 + (tilt - m120) * mF0;
        }
        m120 = tilt;
    }
    Row_001B84A0 up;
    if (mode == 0) {
        up = m16C->m160;
    } else {
        up = basis[1];
    }
    Row_001B84A0 vel(m168->mB0.x, 0.0f, m168->mB0.z, 1.0f);
    int still = func_001B9E30(this);

    if (!m170 || !m170->m1C) {
        if (sqrtf(vel.Dot(vel)) > D_00387A0C || still || m16C->mAC) {
            if (still) {
                basis[2].Set(0.0f, -1.0f, 0.0f, 1.0f);
                Node_001B84A0* n = m160;
                if (!n->m1C && !n->m20 && mode != 3) {
                    n->m28 = 0.0f;
                    m160->m2C = 0.0f;
                }
            } else {
                basis[2] = m168->mB0;
                Cfg_001B84A0* c = m16C;
                if (c->mAC) {
                    basis.at.x = 0.0f;
                    basis.at.z = 0.0f;
                    basis[2] += c->m140;
                }
                Normalize_001B84A0(basis[2]);
                Row_001B84A0 n;
                float k;
                if (mode == 1) {
                    if (m16C->mAC && basis.at.y < 0.0f) {
                        n.Set(0.0f, 1.0f, 0.0f, 1.0f);
                        k = basis.at.Dot(n) * D_00387A10;
                    } else {
                        n.Set(0.0f, 1.0f, 0.0f, 1.0f);
                        k = basis[2].y;
                    }
                    basis[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
                } else if (mode == 2) {
                    n.Set(0.0f, 1.0f, 0.0f, 1.0f);
                    k = basis[2].y;
                } else {
                    n = m16C->m170;
                    k = basis.at.Dot(n) * D_00387A14;
                }
                // Remove the component along n.
                basis[2] -= n * k;
                Normalize_001B84A0(basis[2]);
            }
            CrossN_001B84A0(basis[0], basis[1], basis[2]);
            CrossN_001B84A0(basis[1], basis[2], basis[0]);
        }
    }
    if (m168->m31C && m16C->mF4) {
        basis = ((Phys_001B84A0*)func_00185578(m168, 0x5BD63B29))->m440;
    }

    if (mode == 1) {
        m128 += Frames_001B84A0() * D_00387A18;
        if (m128 > D_00387A1C) {
            m128 = D_00387A1C;
        }
    } else if (m128 > 0.0f) {
        m128 -= Frames_001B84A0() * D_00387A20;
        if (m128 < 0.0f) {
            m128 = 0.0f;
        }
    } else if (m128 < 0.0f) {
        m128 += Frames_001B84A0() * D_00387A24;
        if (m128 > 0.0f) {
            m128 = 0.0f;
        }
    }

    basis = basis * *func_00100928((Mat_001B84A0*)0x70003FC0, m160->m2C + m160->m30);
    if (mode == 3) {
        func_001B8148(&basis, m12C + m128);
    } else if (!m16C->m40 || m16C->m64 || m16C->mAC) {
        func_001B8148(&basis, m124 + m128);
    }
    func_001B8148(&basis, m160->m28);

    if (mode == 3) {
        float a = D_00387A28;
        D_0038D3C0 = a;
        if (m11C == 0) {
            // Look 90 degrees to each side and keep the side that is clear.
            RotateY_001B84A0(basis, a);
            Feeler_001B84A0 f;
            func_00209240(&f);
            Row_001B84A0 dir;
            dir.Set(basis.at.x, 0.0f, basis.at.z, 1.0f);
            Normalize_001B84A0(dir);
            Row_001B84A0 start = m168->m50 - basis[2] * 3.0f;
            Row_001B84A0 end = start - dir * 72.0f;
            func_00209350(&f, 0x90, 0);
            int side;
            if (func_002099C0(&f, &start, &end, 1)) {
                float d1 = f.m90;
                RotateY_001B84A0(basis, 2.0f * -D_0038D3C0);
                dir.Set(basis.at.x, 0.0f, basis.at.z, 1.0f);
                Normalize_001B84A0(dir);
                start = m168->m50 - basis[2] * 3.0f;
                end = start - dir * 72.0f;
                if (!func_002099C0(&f, &start, &end, 1)) {
                    side = 2;
                } else if (!(f.m90 < d1)) {
                    RotateY_001B84A0(basis, 2.0f * D_0038D3C0);
                    side = 1;
                } else {
                    side = 2;
                }
            } else {
                side = 1;
            }
            m11C = side;
            if (f.mC0) {
                func_00183CB8(f.mC0, &f.mC0);
                f.mC0 = 0;
            }
        } else {
            if (m11C != 1) {
                a = -a;
            }
            RotateY_001B84A0(basis, a);
        }
    } else {
        m11C = 0;
    }
    if (m168 && m11C == 2) {
        m168->m28 |= 1 << func_001E53A0(0x16B8E4CB, 0);
    } else {
        m168->m28 &= ~(1 << func_001E53A0(0x16B8E4CB, 0));
    }

    // Target orientation (camera looks down -z).
    Mat_001B84A0 t;
    func_00100200(&t, 0.0f, 0.0f, 0.0f);
    t.right.Set(-basis.right.x, -basis.right.y, -basis.right.z, 0.0f);
    t.up.Set(basis.up.x, basis.up.y, basis.up.z, 0.0f);
    t.at.Set(-basis.at.x, -basis.at.y, -basis.at.z, 0.0f);
    t.trans.x = 0.0f;
    t.trans.y = 0.0f;
    t.trans.z = 0.0f;
    t.trans.w = 1.0f;
    cm->trans.x = 0.0f;
    cm->trans.y = 0.0f;
    cm->trans.z = 0.0f;
    cm->trans.w = 1.0f;
    if (instant) {
        *cm = t;
    }
    float d0 = t.right.Dot(cm->right);
    float d1 = t.up.Dot(cm->up);
    float d2 = t.at.Dot(cm->at);
    if (d0 > D_00387A2C && d1 > D_00387A2C && d2 > D_00387A2C)
        goto aligned;
    {
        func_00103000(m164, cm, &t);
        Mat_001B84A0 old = *cm;
        *cm = t;
        Cfg_001B84A0* c = m16C;
        if (!c->m40 || c->m64 || c->mAC) {
        if (m16C->m1C == 0 && dt <= mD8) {
            mD8 -= dt;
            func_00103930(m164, cm, func_0018B1D0(m140, dt));
        } else {
            mD8 = 0.0f;
            func_00103930(m164, cm, func_0018B1D0(m138, dt));
            float d = fwd.Dot(cm->at);
            float lim = m34 * D_00387A30;
            if (d < lim) {
                float rate = m138 * (d / lim);
                func_00103000(m164, &old, &t);
                func_00103930(m164, cm, func_0018B1D0(rate, dt));
                d = m34 * D_00387A30;
            }
            m34 = d;
        }
        } else {
            func_00103930(m164, cm, func_0018B1D0(m13C, dt));
            mD8 = D_00387A34;
        }
    }
aligned:
    m50 = cm->right;
    m60 = cm->up;
    // Position.
    Row_001B84A0 pos;
    m70 = cm->at;
    func_001BA000(&pos, this, instant);
    float back;
    float h;
    if (instant) {
        float s = m10C;
        m10C = 1.0f;
        func_001BA1F8(this, &h, &back);
        m10C = s;
    } else {
        func_001BA1F8(this, &h, &back);
    }
    pos += cm->at * back;
    pos += up * h;
    Row_001B84A0 target = m168->m50 + up * h;
    basis.at.Set(target.x - pos.x, target.y - pos.y, target.z - pos.z, 1.0f);
    Normalize_001B84A0(basis[2]);
    basis.up.x = cm->up.x;
    basis.up.y = cm->up.y;
    basis.up.z = cm->up.z;
    CrossN_001B84A0(basis[0], basis[1], basis[2]);
    CrossN_001B84A0(basis[1], basis[2], basis[0]);
    if (m120 != 0.0f) {
        RotateAbout_001B84A0(basis[1], basis[2], m120);
        RotateAbout_001B84A0(basis[0], basis[2], m120);
    }
    cm->right.x = -basis.right.x;
    cm->right.y = -basis.right.y;
    cm->right.z = -basis.right.z;
    cm->right.w = 0.0f;
    cm->up.x = basis.up.x;
    cm->up.y = basis.up.y;
    cm->up.z = basis.up.z;
    cm->up.w = 0.0f;
    cm->at.x = -basis.at.x;
    cm->at.y = -basis.at.y;
    cm->at.z = -basis.at.z;
    cm->at.w = 0.0f;
    if (m148 > 0.0f) {
        func_001B9E98(this, &pos, cm);
    }
    int locked;
    if (m168->m31C) {
        locked = 0;
        if (((Phys_001B84A0*)func_00185578(m168, 0x5BD63B29))->m5B4->m1C) {
            locked = mode == 3;
        }
    } else {
        locked = 0;
    }
    if (!locked) {
        // copy of cm->at as a temporary: the game copies it (lq 0x20($s1) -> 0xF0) above the product (0xE0)
        // and from (0xD0), i.e. it is allocated after both
        Row_001B84A0 from = pos - Row_001B84A0(cm->at) * back;
        func_0018B200(&pos, cm, &from, &target, 1, 1);
    }
    pos.w = 1.0f;
    func_001B80D8(cam, &pos);
    if (!instant)
        return;
    func_001B80F8(cam);
}
