/* fuzzy: 90.4 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_00192F80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
    Row_00192F80& operator+=(const Row_00192F80& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Row_00192F80& operator-=(const Row_00192F80& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
    Row_00192F80& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    float Length2() const { return x * x + y * y + z * z; }
};

struct Vec_00192F80 : Row_00192F80 {
    Vec_00192F80() {}
    Vec_00192F80(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_00192F80 operator-(const Row_00192F80& v)
{
    return Vec_00192F80(-v.x, -v.y, -v.z, -v.w);
}

struct Quat_00192F80;
extern "C" float func_0011D4C0(Quat_00192F80* q);
extern "C" void func_00119228(Quat_00192F80* q, float w);
extern "C" void func_00119230(Quat_00192F80* q, float x, float y, float z);

struct Quat_00192F80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float& operator[](int i) { return (&x)[i]; }
    float Length() { return sqrtf(func_0011D4C0(this)); }
    Quat_00192F80& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    void Normalize(float len = 1.0f)
    {
        float l = Length();
        if (l > 0.0f) {
            *this *= len / l;
        }
    }
};

struct Mat_00192F80 {
    Row_00192F80 r[4];
    Row_00192F80& operator[](int i) { return r[i]; }
    const Row_00192F80& operator[](int i) const { return r[i]; }
    void Ident()
    {
        r[0].Set(1.0f, 0.0f, 0.0f, 0.0f);
        r[1].Set(0.0f, 1.0f, 0.0f, 0.0f);
        r[2].Set(0.0f, 0.0f, 1.0f, 0.0f);
        r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    }
    void FromQuat(const Quat_00192F80& q)
    {
        float n = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
        float s = (n > 0.0f) ? 2.0f / n : 0.0f;
        float xs = q.x * s;
        float ys = q.y * s;
        float zs = q.z * s;
        float wx = q.w * xs;
        float wy = q.w * ys;
        float wz = q.w * zs;
        float xx = q.x * xs;
        float xy = q.x * ys;
        float xz = q.x * zs;
        float yy = q.y * ys;
        float yz = q.y * zs;
        float zz = q.z * zs;
        r[0].x = 1.0f - (yy + zz);
        r[1].x = xy + wz;
        r[2].x = xz - wy;
        r[0].y = xy - wz;
        r[1].y = 1.0f - (xx + zz);
        r[2].y = yz + wx;
        r[0].z = xz + wy;
        r[1].z = yz - wx;
        r[2].z = 1.0f - (xx + yy);
    }
};

static inline float Len_00192F80(const Row_00192F80& v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

static inline Vec_00192F80 operator+(const Row_00192F80& a, const Row_00192F80& b)
{
    return Vec_00192F80(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Arr_00192F80 {
    char pad0[0xC];
    int m_size;
};

struct Pt3_00192F80 {
    int m0;
    float x, y, z;
};

struct Frame_00192F80 {
    char pad0[0x50];
    Row_00192F80 m50;
    char pad60[0x10];
    Mat_00192F80 m70;
    char padB0[0x10];
    Mat_00192F80 mC0;
};

// One triangle: origin and two edges.
struct Tri_00192F80 {
    Row_00192F80 v0;
    Row_00192F80 e1;
    Row_00192F80 e2;
    char pad30[0x80 - 0x30];
    float m80;
    float m84;
    char pad88[0x8];
};

extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;
struct Sub_00192F80 {
    char pad[0x220 - 0x140];
    ~Sub_00192F80();
};
extern "C" void func_00209240(Sub_00192F80* s);

struct Wheel_00192F80 {
    float m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    char pad18[0x44 - 0x18];
    float m44[10];
    char pad6C[0xB4 - 0x6C];
    int mB4;
    char padB8[0xD4 - 0xB8];
    int mD4;
    float mD8;
    char padDC[0x140 - 0xDC];
    Sub_00192F80 m140;
    Wheel_00192F80() { func_00209240(&m140); }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Skater_00192F80 {
    char pad0[0x388];
    float m388;
};

extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Row_00192F80* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Arr_00192F80** out, int required);
extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void* func_001E9378(Arr_00192F80* a, int i);
extern "C" Arr_00192F80* func_001E93A0(Arr_00192F80* a, int i);
extern "C" Pt3_00192F80* func_001E9328(Arr_00192F80* a, int i);
extern "C" float func_001E9298(Arr_00192F80* a, int i);
extern "C" Skater_00192F80* func_0022DD38(void* p);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern void* D_0038FC78;

struct Car_00192F80;
extern "C" void func_00196340(Car_00192F80* self, Wheel_00192F80* w, void* params);

struct Car_00192F80 {
    char pad0[0xC];
    Frame_00192F80* mC;
    char pad10[0x10];
    Row_00192F80 m20;
    Row_00192F80 m30;
    Quat_00192F80 m40;
    Row_00192F80 m50;
    char pad60[0x10];
    Mat_00192F80 m70;
    char padB0[0x124 - 0xB0];
    unsigned char m124;
    char pad125[0x12C - 0x125];
    int m12C;
    char pad130[0x140 - 0x130];
    Row_00192F80 m140;
    Row_00192F80 m150;
    char pad160[0x10];
    Row_00192F80 m170;
    float m180;
    char pad184[0xC];
    Row_00192F80 m190;
    float m1A0;
    float m1A4;
    float m1A8;
    float m1AC;
    float m1B0;
    float m1B4;
    float m1B8;
    float m1BC;
    int m1C0;
    unsigned int m1C4;
    int m1C8;
    float m1CC;
    char pad1D0[0x1D8 - 0x1D0];
    float m1D8;
    float m1DC;
    Tri_00192F80 m1E0[1];
    char pad270[0x310 - 0x270];
    int m310;
    int m314;
    Wheel_00192F80* m318;
    float m31C;
    float m320;
    int m324;
    float m328[6];
    float m340;
    float m344;
    float m348;
    char pad34C[0x1330 - 0x34C];
    int m1330;
    char pad1334[0xC];
    Row_00192F80 m1340;
    unsigned int m1350;
    char pad1354[4];
    unsigned int m1358;
    float m135C;
    int m1360;
    char pad1364[0x1374 - 0x1364];
    void* m1374;
    char pad1378[8];
    int m1380;
    void Init(void* params);
};

void Car_00192F80::Init(void* params)
{
    if (func_001E8708(params, 0x935AB858)) {
        m1380++;
        m1380 = m1380 % 3;
    } else if (func_001E8708(params, 0xE6B5FCD9)) {
        m1380 = (m1380 + 2) % 3;
    } else if (func_001E8708(params, 0x751DA48B)) {
        m1380 = 0;
    }
    if (func_001E8618(params, 0x93346B8C)) {
        float a;
        func_001E7EB0(params, 0x93346B8C, &a, 0);
        m170.Set(0.0f, a, 0.0f, 1.0f);
    }
    if (func_001E8618(params, 0x93FCA499)) {
        func_001E7EB0(params, 0x93FCA499, &m180, 0);
        m180 = 386.3999939f / m180;
    }
    if (func_001E8618(params, 0x8C6473EC)) {
        func_001E7FA8(params, 0x8C6473EC, &m190, 0);
        m190.x = 386.3999939f / m190.x;
        m190.y = 386.3999939f / m190.y;
        m190.z = 386.3999939f / m190.z;
    }
    func_001E7EB0(params, 0x79C3B862, &m1A0, 0);
    func_001E7EB0(params, 0xF476273C, &m1A4, 0);
    func_001E7EB0(params, 0x4A23A53C, &m1AC, 0);
    func_001E7EB0(params, 0x01DD4890, &m1A8, 0);
    func_001E7EB0(params, 0xB9F026ED, &m1B0, 0);
    func_001E7EB0(params, 0x8C14709E, &m1B4, 0);
    func_001E7EB0(params, 0x2C91E49B, &m1B8, 0);
    func_001E7EB0(params, 0x280F0E0B, &m1BC, 0);
    m1C0 = func_001E8708(params, 0x5341806A);
    if (func_001E8618(params, 0xC1E5ABDD)) {
        func_001E7EB0(params, 0xC1E5ABDD, &m1CC, 0);
        m1CC = m1CC * 0.01745329425f;
    }
    func_001E7EB0(params, 0x386837DB, &m1D8, 0);
    func_001E7EB0(params, 0x469CF79A, &m1DC, 0);
    m310 = func_001E8708(params, 0xC2A136CC);
    m314 = func_001E8708(params, 0xAD6C0A46);

    if (func_001E8618(params, 0xFC8C4AC6)) {
        Arr_00192F80* tris;
        float sum = 0.0f;
        func_001E8248(params, 0xFC8C4AC6, &tris, 1);
        int n = tris->m_size;
        int i = n;
        while (i-- != 0) {
            Tri_00192F80* t = &m1E0[i];
            Arr_00192F80* pts = func_001E93A0(tris, i);
            Pt3_00192F80* p = func_001E9328(pts, 0);
            t->v0.x = p->x;
            t->v0.y = p->y;
            t->v0.z = p->z;
            p = func_001E9328(pts, 1);
            t->e1.x = p->x;
            t->e1.y = p->y;
            t->e1.z = p->z;
            t->e1 -= t->v0;
            p = func_001E9328(pts, 2);
            t->e2.x = p->x;
            t->e2.y = p->y;
            t->e2.z = p->z;
            t->e2 -= t->v0;
            sum += Len_00192F80(t->v0);
            sum += Len_00192F80(t->v0 + t->e1);
            sum += Len_00192F80(t->v0 + t->e2);
            t->m80 = Len_00192F80(t->e1);
            t->m84 = Len_00192F80(t->e2);
        }
        func_0022DD38(D_0038FC78)->m388 = sum * 0.3333333433f / (float)n - 48.0f;
    }
    if (func_001E8618(params, 0x1757E572)) {
        void* s;
        func_001E8180(params, 0x1757E572, &s, 1);
        if (func_001E8618(s, 0x9AA9FAEE)) {
            func_001E7EB0(s, 0x9AA9FAEE, &m31C, 0);
            m31C = m31C * 12.0f;
        }
        if (func_001E8618(s, 0xB2268648)) {
            func_001E7EB0(s, 0xB2268648, &m320, 0);
            m320 = m320 * 12.0f;
        }
        if (func_001E8618(s, 0x33921583)) {
            func_001E7EB0(s, 0x33921583, &m348, 0);
            m348 = m348 * 0.1047199965f;
        }
        func_001E7EB0(s, 0x94EA6601, &m344, 0);
        func_001E7EB0(s, 0x82BCBB10, &m340, 0);
        if (func_001E8618(s, 0xC023FA75)) {
            Arr_00192F80* a;
            func_001E8248(s, 0xC023FA75, &a, 1);
            m324 = a->m_size;
            for (int i = 0; i < m324; i++) {
                m328[i] = func_001E9298(a, i);
            }
        }
    }
    if (func_001E8618(params, 0xB3F8557E)) {
        Arr_00192F80* a = 0;
        func_001E8248(params, 0xB3F8557E, &a, 1);
        unsigned int n = a->m_size;
        m1C4 = n;
        if (!m318) {
            m318 = new Wheel_00192F80[n];
        }
        for (int i = m1C4; --i != -1;) {
            void* wp = func_001E9378(a, i);
            func_00196340(this, &m318[i], wp);
        }
    }
    if (func_001E8618(params, 0x371BADFF)) {
        void* s;
        func_001E8180(params, 0x371BADFF, &s, 1);
        for (int i = m1C4; --i != -1;) {
            func_00196340(this, &m318[i], s);
        }
    }
    m1C8 = 0;
    for (int i = m1C4; --i != -1;) {
        if (m318[i].mD4) {
            m1C8++;
        }
    }

    // Orientation from the owner's matrix.
    {
        const Mat_00192F80& m = mC->m70;
        Quat_00192F80 r;
        float tr = m[0][0] + m[1][1] + m[2][2];
        float sq;
        if (tr > 0.0f) {
            sq = sqrtf(tr + 1.0f);
            float hw = sq * 0.5f;
            sq = 0.5f / sq;
            func_00119228(&r, hw);
            func_00119230(&r, (m[2][1] - m[1][2]) * sq, (m[0][2] - m[2][0]) * sq, (m[1][0] - m[0][1]) * sq);
        } else {
            int i = 0;
            if (m[0][0] < m[1][1])
                i = 1;
            if (m[i][i] < m[2][2])
                i = 2;
            int j = (i + 1) % 3;
            int k = (j + 1) % 3;
            sq = sqrtf(m[i][i] - (m[j][j] + m[k][k]) + 1.0f);
            r[i] = sq * 0.5f;
            sq = 0.5f / sq;
            r[j] = (m[j][i] + m[i][j]) * sq;
            r[k] = (m[k][i] + m[i][k]) * sq;
            r[3] = (m[k][j] - m[j][k]) * sq;
        }
        m40 = r;
    }
    m40.Normalize();
    if (func_001E8618(params, 0xAA99C521)) {
        Vec_00192F80 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E7FA8(params, 0xC97F3AA9, &v, 0);
        m40.x = v.x;
        m40.y = v.y;
        m40.z = v.z;
        m40.Normalize();
        m70.FromQuat(m40);
        m70.r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
        Mat_00192F80* d = &mC->m70;
        *d = m70;
        d = &mC->mC0;
        *d = m70;
    }
    m20 = mC->m50;
    if (func_001E8618(params, 0x7F261953)) {
        func_001E7FA8(params, 0x7F261953, &m20, 0);
        mC->m50 = m20;
    }
    int on = 0;
    if (m1330 || func_001E8708(params, 0x2ED67657)) {
        on = 1;
    }
    m1330 = on;
    if (func_001E8708(params, 0x2ED67657)) {
        func_001E7FA8(params, 0xEC86EF7A, &m1340, 1);
        func_001E8398(params, 0xDA75A33E, &m1350, 1);
    }
    func_001E8398(params, 0x0EDCF90E, &m1358, 0);
    m30.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m50.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m140.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m150.Set(0.0f, 0.0f, 0.0f, 1.0f);
    for (int i = m1C4; --i != -1;) {
        Wheel_00192F80* w = &m318[i];
        w->m4 = 1;
        w->m0 = w->mD8;
        w->mC = 0;
        w->m8 = 0;
        w->m10 = 0;
        w->m14 = 0;
        w->mB4 = 0;
        for (int j = 9; j != -1; j--) {
            w->m44[j] = 386.3999939f / m180 / (float)m1C4;
        }
    }
    m124 = 0;
    m1360 = 0;
    m12C = 0;
    m135C = 1.0f;
    m1374 = func_00185578(mC, 0x222756D5);
}
