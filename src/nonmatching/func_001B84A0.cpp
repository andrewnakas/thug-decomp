/* fuzzy: 54.8 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_001B84A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Dot(const Row_001B84A0& o) const { return x * o.x + y * o.y + z * o.z; }
    Row_001B84A0& operator+=(const Row_001B84A0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Mat_001B84A0 {
    Row_001B84A0 r[4];
};

extern "C" void func_003233B8(Row_001B84A0* out, const Row_001B84A0* in);
extern "C" Mat_001B84A0* func_00323318(Mat_001B84A0* out, const Mat_001B84A0* a, const Mat_001B84A0* b);
extern "C" Mat_001B84A0* func_00100928(Mat_001B84A0* out, float angle);
extern "C" void func_00100200(Mat_001B84A0* m, float x, float y, float z);

static inline void Normalize_001B84A0(Row_001B84A0& v)
{
    func_003233B8(&v, &v);
}

// a = Normalize(b x c)
static inline void CrossN_001B84A0(Row_001B84A0& a, const Row_001B84A0& b, const Row_001B84A0& c)
{
    Row_001B84A0 t;
    t.x = b.y * c.z - b.z * c.y;
    t.y = b.z * c.x - b.x * c.z;
    t.z = b.x * c.y - b.y * c.x;
    t.w = 0.0f;
    a = t;
    Normalize_001B84A0(a);
}

static inline void RotateY_001B84A0(Mat_001B84A0& m, Mat_001B84A0* tmp, float angle)
{
    func_00323318(&m, func_00100928(tmp, angle), &m);
}

struct Feeler_001B84A0 {
    char pad0[0x90];
    float m90;
    char pad94[0xC0 - 0x94];
    void* mC0;
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
extern "C" void func_001BA4F0(Row_001B84A0* q, Row_001B84A0* axis, float angle);
extern "C" void func_001BA5D0(Row_001B84A0* out, Row_001B84A0* q, Row_001B84A0* v);
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
    int instant = (m168->m104 & 8) != 0;
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
    cm->r[0] = m50;
    cm->r[1] = m60;
    cm->r[2] = m70;
    Row_001B84A0 fwd;
    fwd.Set(cm->r[2].x, cm->r[2].y, cm->r[2].z, 1.0f);

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
    Row_001B84A0 up = basis.r[1];
    if (mode == 0) {
        up = m16C->m160;
    }
    Row_001B84A0 vel;
    vel.Set(m168->mB0.x, 0.0f, m168->mB0.z, 1.0f);
    int still = func_001B9E30(this);

    if (!m170 || !m170->m1C) {
        if (sqrtf(vel.Dot(vel)) > D_00387A0C || still || m16C->mAC) {
            if (still) {
                basis.r[2].Set(0.0f, -1.0f, 0.0f, 1.0f);
                Node_001B84A0* n = m160;
                if (!n->m1C && !n->m20 && mode != 3) {
                    n->m28 = 0.0f;
                    m160->m2C = 0.0f;
                }
            } else {
                basis.r[2] = m168->mB0;
                Cfg_001B84A0* c = m16C;
                if (c->mAC) {
                    basis.r[2].x = 0.0f;
                    basis.r[2].z = 0.0f;
                    basis.r[2] += c->m140;
                }
                Normalize_001B84A0(basis.r[2]);
                Row_001B84A0 n;
                float k;
                if (mode == 1) {
                    if (m16C->mAC && basis.r[2].y < 0.0f) {
                        n.Set(0.0f, 1.0f, 0.0f, 1.0f);
                        k = basis.r[2].Dot(n) * D_00387A10;
                    } else {
                        n.Set(0.0f, 1.0f, 0.0f, 1.0f);
                        k = basis.r[2].y;
                    }
                    basis.r[1].Set(0.0f, 1.0f, 0.0f, 1.0f);
                } else if (mode == 2) {
                    n.Set(0.0f, 1.0f, 0.0f, 1.0f);
                    k = basis.r[2].y;
                } else {
                    n = m16C->m170;
                    k = basis.r[2].Dot(n) * D_00387A14;
                }
                // Remove the component along n.
                Row_001B84A0 d;
                d.Set(n.x * k, n.y * k, n.z * k, n.w * k);
                basis.r[2].x -= d.x;
                basis.r[2].y -= d.y;
                basis.r[2].z -= d.z;
                basis.r[2].w -= d.w;
                Normalize_001B84A0(basis.r[2]);
            }
            CrossN_001B84A0(basis.r[0], basis.r[1], basis.r[2]);
            CrossN_001B84A0(basis.r[1], basis.r[2], basis.r[0]);
        }
    }
    if (m168->m31C && m16C->mF4) {
        basis = ((Phys_001B84A0*)func_00185578(m168, 0x5BD63B29))->m440;
    }

    if (mode == 1) {
        m128 += func_0010FAB8() * 60.0f * D_00387A18;
        if (m128 > D_00387A1C) {
            m128 = D_00387A1C;
        }
    } else if (m128 > 0.0f) {
        m128 -= func_0010FAB8() * 60.0f * D_00387A20;
        if (m128 < 0.0f) {
            m128 = 0.0f;
        }
    } else if (m128 < 0.0f) {
        m128 += func_0010FAB8() * 60.0f * D_00387A24;
        if (m128 > 0.0f) {
            m128 = 0.0f;
        }
    }

    Mat_001B84A0 rot = *func_00100928((Mat_001B84A0*)0x70003FC0, m160->m2C + m160->m30);
    func_00323318(&rot, &basis, &rot);
    basis = rot;
    if (mode == 3) {
        func_001B8148(&basis, m12C + m128);
    } else if (!m16C->m40 || m16C->m64 || m16C->mAC) {
        func_001B8148(&basis, m124 + m128);
    }
    func_001B8148(&basis, m160->m28);

    if (mode != 3) {
        m11C = 0;
    } else {
        float a = D_00387A28;
        D_0038D3C0 = a;
        Mat_001B84A0 tmp;
        if (m11C == 0) {
            // Look 90 degrees to each side and keep the side that is clear.
            RotateY_001B84A0(basis, &tmp, a);
            Feeler_001B84A0 f;
            func_00209240(&f);
            Row_001B84A0 dir;
            Row_001B84A0 start;
            Row_001B84A0 end;
            Row_001B84A0 s;
            dir.Set(basis.r[2].x, 0.0f, basis.r[2].z, 1.0f);
            Normalize_001B84A0(dir);
            s.Set(basis.r[2].x * 3.0f, basis.r[2].y * 3.0f, basis.r[2].z * 3.0f, basis.r[2].w * 3.0f);
            Row_001B84A0& p = m168->m50;
            start.Set(p.x - s.x, p.y - s.y, p.z - s.z, p.w - s.w);
            s.Set(dir.x * 72.0f, dir.y * 72.0f, dir.z * 72.0f, dir.w * 72.0f);
            end.Set(start.x - s.x, start.y - s.y, start.z - s.z, start.w - s.w);
            func_00209350(&f, 0x90, 0);
            int side = 1;
            if (func_002099C0(&f, &start, &end, 1)) {
                float d1 = f.m90;
                RotateY_001B84A0(basis, &tmp, 2.0f * -D_0038D3C0);
                dir.Set(basis.r[2].x, 0.0f, basis.r[2].z, 1.0f);
                Normalize_001B84A0(dir);
                s.Set(basis.r[2].x * 3.0f, basis.r[2].y * 3.0f, basis.r[2].z * 3.0f, basis.r[2].w * 3.0f);
                Row_001B84A0& p2 = m168->m50;
                start.Set(p2.x - s.x, p2.y - s.y, p2.z - s.z, p2.w - s.w);
                s.Set(dir.x * 72.0f, dir.y * 72.0f, dir.z * 72.0f, dir.w * 72.0f);
                end.Set(start.x - s.x, start.y - s.y, start.z - s.z, start.w - s.w);
                if (!func_002099C0(&f, &start, &end, 1)) {
                    side = 2;
                } else if (f.m90 < d1) {
                    side = 2;
                } else {
                    RotateY_001B84A0(basis, &tmp, 2.0f * D_0038D3C0);
                    side = 1;
                }
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
            RotateY_001B84A0(basis, &tmp, a);
        }
    }
    if (m168 && m11C == 2) {
        m168->m28 |= 1 << func_001E53A0(0x16B8E4CB, 0);
    } else {
        m168->m28 &= ~(1 << func_001E53A0(0x16B8E4CB, 0));
    }

    // Target orientation (camera looks down -z).
    Mat_001B84A0 t;
    func_00100200(&t, 0.0f, 0.0f, 0.0f);
    t.r[0].Set(-basis.r[0].x, -basis.r[0].y, -basis.r[0].z, 0.0f);
    t.r[1].Set(basis.r[1].x, basis.r[1].y, basis.r[1].z, 0.0f);
    t.r[2].Set(-basis.r[2].x, -basis.r[2].y, -basis.r[2].z, 0.0f);
    t.r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    cm->r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    if (instant) {
        *cm = t;
    }
    Mat_001B84A0 old;
    if (!(t.r[0].Dot(cm->r[0]) > D_00387A2C && t.r[1].Dot(cm->r[1]) > D_00387A2C &&
          t.r[2].Dot(cm->r[2]) > D_00387A2C)) {
        func_00103000(m164, cm, &t);
        old = *cm;
        *cm = t;
        Cfg_001B84A0* c = m16C;
        if (c->m40 && !c->m64 && !c->mAC) {
            func_00103930(m164, cm, func_0018B1D0(m13C, dt));
            mD8 = D_00387A34;
        } else if (m16C->m1C == 0 && dt <= mD8) {
            mD8 -= dt;
            func_00103930(m164, cm, func_0018B1D0(m140, dt));
        } else {
            mD8 = 0.0f;
            func_00103930(m164, cm, func_0018B1D0(m138, dt));
            float d = fwd.Dot(cm->r[2]);
            float lim = m34 * D_00387A30;
            if (d < lim) {
                float rate = m138 * (d / lim);
                func_00103000(m164, &old, &t);
                func_00103930(m164, cm, func_0018B1D0(rate, dt));
                d = m34 * D_00387A30;
            }
            m34 = d;
        }
    }
    m50 = cm->r[0];
    m60 = cm->r[1];
    m70 = cm->r[2];

    // Position.
    Row_001B84A0 pos;
    func_001BA000(&pos, this, instant);
    float h;
    float back;
    if (instant) {
        float s = m10C;
        m10C = 1.0f;
        func_001BA1F8(this, &h, &back);
        m10C = s;
    } else {
        func_001BA1F8(this, &h, &back);
    }
    Row_001B84A0 u;
    pos.x += cm->r[2].x * back;
    pos.y += cm->r[2].y * back;
    pos.z += cm->r[2].z * back;
    pos.w += cm->r[2].w * back;
    u.Set(up.x * h, up.y * h, up.z * h, up.w * h);
    pos.x += u.x;
    pos.y += u.y;
    pos.z += u.z;
    pos.w += u.w;
    Row_001B84A0 target;
    Row_001B84A0& sp = m168->m50;
    target.Set(sp.x + u.x, sp.y + u.y, sp.z + u.z, sp.w + u.w);
    basis.r[2].Set(target.x - pos.x, target.y - pos.y, target.z - pos.z, 1.0f);
    Normalize_001B84A0(basis.r[2]);
    basis.r[1].x = cm->r[1].x;
    basis.r[1].y = cm->r[1].y;
    basis.r[1].z = cm->r[1].z;
    CrossN_001B84A0(basis.r[0], basis.r[1], basis.r[2]);
    CrossN_001B84A0(basis.r[1], basis.r[2], basis.r[0]);
    if (m120 != 0.0f) {
        Row_001B84A0 q;
        Row_001B84A0 r;
        func_001BA4F0(&q, &basis.r[2], m120);
        func_001BA5D0(&r, &q, &basis.r[1]);
        basis.r[1] = r;
        func_001BA4F0(&q, &basis.r[2], m120);
        func_001BA5D0(&r, &q, &basis.r[0]);
        basis.r[0] = r;
    }
    cm->r[0].Set(-basis.r[0].x, -basis.r[0].y, -basis.r[0].z, 0.0f);
    cm->r[1].Set(basis.r[1].x, basis.r[1].y, basis.r[1].z, 0.0f);
    cm->r[2].Set(-basis.r[2].x, -basis.r[2].y, -basis.r[2].z, 0.0f);
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
        Row_001B84A0 f = cm->r[2];
        Row_001B84A0 b;
        Row_001B84A0 from;
        b.Set(f.x * back, f.y * back, f.z * back, f.w * back);
        from.Set(pos.x - b.x, pos.y - b.y, pos.z - b.z, pos.w - b.w);
        func_0018B200(&pos, cm, &from, &target, 1, 1);
    }
    pos.w = 1.0f;
    func_001B80D8(cam, &pos);
    if (instant) {
        func_001B80F8(cam);
    }
}
