/* fuzzy: 90.3 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_0018E4C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
    Row_0018E4C8& operator+=(const Row_0018E4C8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Row_0018E4C8& operator-=(const Row_0018E4C8& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
    Row_0018E4C8& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    float Length2() const { return x * x + y * y + z * z; }
};

struct Vec_0018E4C8 : Row_0018E4C8 {
    Vec_0018E4C8() {}
    Vec_0018E4C8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_0018E4C8 operator-(const Row_0018E4C8& v)
{
    return Vec_0018E4C8(-v.x, -v.y, -v.z, -v.w);
}

struct Quat_0018E4C8;
extern "C" float func_0011D4C0(Quat_0018E4C8* q);
extern "C" void func_00119228(Quat_0018E4C8* q, float w);
extern "C" void func_00119230(Quat_0018E4C8* q, float x, float y, float z);

struct Quat_0018E4C8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float& operator[](int i) { return (&x)[i]; }
    float Length() { return sqrtf(func_0011D4C0(this)); }
    Quat_0018E4C8& operator*=(float s)
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

struct Mat_0018E4C8 {
    Row_0018E4C8 r[4];
    Row_0018E4C8& operator[](int i) { return r[i]; }
    const Row_0018E4C8& operator[](int i) const { return r[i]; }
    void Ident()
    {
        r[0].x = 1.0f;
        r[0].y = 0.0f;
        r[0].z = 0.0f;
        r[0].w = 0.0f;
        r[1].x = 0.0f;
        r[1].y = 1.0f;
        r[1].z = 0.0f;
        r[1].w = 0.0f;
        r[2].x = 0.0f;
        r[2].y = 0.0f;
        r[2].z = 1.0f;
        r[2].w = 0.0f;
        r[3].x = 0.0f;
        r[3].y = 0.0f;
        r[3].z = 0.0f;
        r[3].w = 1.0f;
    }
    Mat_0018E4C8& operator*=(const Mat_0018E4C8& o);
    void FromQuat(const Quat_0018E4C8& q)
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
    Vec_0018E4C8 Rotate(const Row_0018E4C8& p) const
    {
        Vec_0018E4C8 o;
        o.x = p.x * r[0].x + p.y * r[1].x + p.z * r[2].x;
        o.y = p.x * r[0].y + p.y * r[1].y + p.z * r[2].y;
        o.z = p.x * r[0].z + p.y * r[1].z + p.z * r[2].z;
        o.w = p.w;
        return o;
    }
};

extern "C" Mat_0018E4C8* func_00323318(Mat_0018E4C8* out, const Mat_0018E4C8* a, const Mat_0018E4C8* b);
extern "C" Mat_0018E4C8* func_00100890(Mat_0018E4C8* out, float a);
extern "C" Mat_0018E4C8* func_00100928(Mat_0018E4C8* out, float a);
extern "C" Mat_0018E4C8* func_001009C0(Mat_0018E4C8* out, float a);

inline Mat_0018E4C8& Mat_0018E4C8::operator*=(const Mat_0018E4C8& o)
{
    func_00323318(this, &o, this);
    return *this;
}

// Rotate by the Euler angles in a (x, then y, then z).
static inline void ApplyEuler_0018E4C8(Mat_0018E4C8& m, const Row_0018E4C8& a)
{
    if (a.x != 0.0f || a.y != 0.0f || a.z != 0.0f) {
        Mat_0018E4C8 t;
        m *= *func_00100890(&t, a.x);
        m *= *func_00100928(&t, a.y);
        m *= *func_001009C0(&t, a.z);
    }
}

struct Pt_0018E4C8 {
    Row_0018E4C8 pos;
    Row_0018E4C8 m10;
    unsigned char m20;
    char pad21[0xF];
};

struct Arr_0018E4C8 {
    char pad0[0xC];
    int m_size;
};

struct Frame_0018E4C8 {
    char pad0[0x50];
    Row_0018E4C8 m50;
    char pad60[0x10];
    Mat_0018E4C8 m70;
};

extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Row_0018E4C8* out, int required);
extern "C" bool func_001E8038(void* params, char* name, Row_0018E4C8* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Arr_0018E4C8** out, int required);
extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_001E9378(Arr_0018E4C8* a, int i);
extern "C" void func_0022A268(void* params, Row_0018E4C8* out);
extern "C" float func_002032A0(unsigned int name, int a);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A50(void* dst, void* src);

extern char D_00361F00[];
extern char D_00361F10[];
extern char D_00361F20[];
extern float D_00394328;

struct Body_0018E4C8;
extern "C" void func_001920A8(Body_0018E4C8* self, unsigned int name);
extern "C" void func_00192258(Body_0018E4C8* self, Arr_0018E4C8* a);
extern "C" void func_00192380(Body_0018E4C8* self, Row_0018E4C8* top, Row_0018E4C8* bottom);
extern "C" void func_00192520(Body_0018E4C8* self, float w, float h);
extern "C" void func_001926A8(Body_0018E4C8* self, int n, float rx, float rz, float h);
extern "C" void func_001928A8(Body_0018E4C8* self, Row_0018E4C8* dims);

struct Body_0018E4C8 {
    char pad0[0xC];
    Frame_0018E4C8* mC;
    char pad10[0x1C - 0x10];
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    float m48;
    float m4C;
    Pt_0018E4C8* m50;
    unsigned short m54;
    char pad56[0x60 - 0x56];
    Row_0018E4C8 m60;
    Row_0018E4C8 m70;
    float m80;
    unsigned int m84;
    unsigned int m88;
    unsigned int m8C;
    unsigned int m90;
    void* m94;
    char pad98[0xB4 - 0x98];
    unsigned int mB4;
    char padB8[0xD4 - 0xB8];
    int mD4;
    char padD8[0xE0 - 0xD8];
    Row_0018E4C8 mE0;
    Row_0018E4C8 mF0;
    Quat_0018E4C8 m100;
    Row_0018E4C8 m110;
    Mat_0018E4C8 m120;
    char pad160[4];
    int m164;
    float m168;
    void Init(void* params);
};

void Body_0018E4C8::Init(void* params)
{
    mD4 = 0;
    mF0.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m110.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m120.Ident();

    // Start from the owner's position and orientation (rotation matrix -> quaternion).
    {
        Frame_0018E4C8* f = mC;
        mE0 = f->m50;
        const Mat_0018E4C8& m = f->m70;
        Quat_0018E4C8 r;
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
        m100 = r;
        m100.Normalize();
        m120.FromQuat(m100);
    }

    func_001E7FA8(params, 0x0C4C809E, &mF0, 0);
    func_001E7FA8(params, 0xFB1A83B2, &m110, 0);
    func_001E7FA8(params, 0x737612C6, &m60, 0);
    func_001E7EB0(params, 0x6FAE5C9A, &m20, 0);
    func_001E7EB0(params, 0x60B4860D, &m24, 0);
    func_001E7EB0(params, 0xF9D75930, &m28, 0);
    func_001E7EB0(params, 0xF1ECB30F, &m2C, 0);
    if (func_001E8618(params, 0xC11E4DD8)) {
        func_001E7EB0(params, 0xC11E4DD8, &m48, 0);
        m48 = m48 * m48;
    }
    if (func_001E8618(params, 0xA457ECE3)) {
        func_001E7EB0(params, 0xA457ECE3, &m4C, 0);
        m4C = m4C * m4C;
    }
    func_001E7EB0(params, 0x3390D1E5, &m40, 0);
    func_001E7EB0(params, 0x5A18F61F, &m44, 0);
    func_001E7EB0(params, 0x85F112C1, &m30, 0);
    func_001E7EB0(params, 0x8AB2DB68, &m34, 0);
    if (func_001E8618(params, 0xE9156E6D)) {
        float a;
        func_001E7EB0(params, 0xE9156E6D, &a, 0);
        m38 = func_00340F60(a * 0.01745329425f);
        m3C = func_00341068(a * 0.01745329425f);
    }
    func_001E7EB0(params, 0x1F4D0CA5, &m80, 0);
    func_001E8398(params, 0x58CDC0F0, &m84, 0);
    func_001E8398(params, 0x2D075F90, &m88, 0);
    func_001E8398(params, 0x571917FA, &m8C, 0);
    func_001E8398(params, 0xCCB84047, &m90, 0);
    if (func_001E8618(params, 0x0DD85BDA)) {
        void* s;
        func_001E8180(params, 0x0DD85BDA, &s, 1);
        m94 = func_001E6978(func_001190D0(8));
        func_001E6A50(m94, s);
    }
    if (func_001E8618(params, 0x94956E48)) {
        unsigned int name;
        func_001E8398(params, 0x94956E48, &name, 1);
        func_001920A8(this, name);
    }
    if (func_001E8708(params, 0x5E51924F)) {
        mB4 |= 1;
    } else {
        mB4 &= ~1;
    }

    // Shape kind: 4 keeps the existing vertices.
    unsigned int shape = m54 ? 4 : 0;
    if (func_001E8708(params, 0xF756B7C5)) {
        shape = 0;
    } else if (func_001E8708(params, 0x1CB1A2B6)) {
        shape = 1;
    } else if (func_001E8708(params, 0x64FBA415)) {
        shape = 2;
    } else if (func_001E8708(params, 0x20689278)) {
        shape = 3;
    }
    if (func_001E8618(params, 0xCCBFEA8C)) {
        Arr_0018E4C8* verts;
        shape = 4;
        func_001E8248(params, 0xCCBFEA8C, &verts, 0);
        func_00192258(this, verts);
    }
    if (shape == 0) {
        Vec_0018E4C8 top(32.0f, 32.0f, 16.0f, 1.0f);
        func_001E8038(params, D_00361F00, &top, 0);
        Vec_0018E4C8 bottom = top;
        func_001E8038(params, D_00361F10, &top, 0);
        func_001E8038(params, D_00361F20, &bottom, 0);
        top *= 0.5f;
        bottom *= 0.5f;
        func_00192380(this, &top, &bottom);
    } else if (shape == 1) {
        float w = 42.0f;
        float h = 32.0f;
        func_001E7EB0(params, 0x0AB21AF0, &w, 0);
        func_001E7EB0(params, 0x055CE396, &h, 0);
        w *= 0.5f;
        h *= 0.5f;
        func_00192520(this, w, h);
    } else if (shape == 2) {
        float rx = 12.0f;
        float rz;
        float h = 60.0f;
        int n = 6;
        func_001E7EB0(params, 0xC48391A5, &rx, 0);
        rz = rx;
        func_001E7EB0(params, 0x937E3B29, &rx, 0);
        func_001E7EB0(params, 0xE2AC8C3A, &rz, 0);
        func_001E7EB0(params, 0x0AB21AF0, &h, 0);
        func_001E7DE8(params, 0x4055F24A, &n, 0);
        h *= 0.5f;
        func_001926A8(this, n, rx, rz, h);
    } else if (shape == 3) {
        Vec_0018E4C8 dims(32.0f, 32.0f, 16.0f, 1.0f);
        func_001E7FA8(params, 0x1D82745A, &dims, 0);
        dims *= 0.5f;
        func_001928A8(this, &dims);
    }

    if (func_001E8618(params, 0xC35CAC0D)) {
        Arr_0018E4C8* list;
        func_001E8248(params, 0xC35CAC0D, &list, 0);
        for (int i = list->m_size; --i != -1;) {
            void* s = func_001E9378(list, i);
            if (func_001E8618(s, 0x806FFF30)) {
                m50[i].m20 = 0;
            } else {
                m50[i].m20 = 1;
                func_001E7FA8(s, 0, &m50[i].m10, 1);
            }
        }
    }
    if (func_001E8618(params, 0x17B93077)) {
        Vec_0018E4C8 ang;
        func_001E7FA8(params, 0x17B93077, &ang, 1);
        Mat_0018E4C8 rot;
        rot.Ident();
        ApplyEuler_0018E4C8(rot, ang);
        for (int i = m54; --i != -1;) {
            Vec_0018E4C8 p = rot.Rotate(m50[i].pos);
            m50[i].pos = p;
        }
    }
    if (func_001E8618(params, 0x9D2D0915)) {
        Vec_0018E4C8 ang;
        func_0022A268(params, &ang);
        Mat_0018E4C8 rot;
        rot.Ident();
        ApplyEuler_0018E4C8(rot, ang);
        for (int i = m54; --i != -1;) {
            Vec_0018E4C8 p = rot.Rotate(m50[i].pos);
            m50[i].pos = p;
        }
    }

    // Re-centre the vertices on their average.
    Vec_0018E4C8 c(0.0f, 0.0f, 0.0f, 1.0f);
    if (func_001E8618(params, 0x737612C6) && func_001E8618(params, 0x737612C6)) {
        func_001E7FA8(params, 0x737612C6, &c, 0);
    }
    for (int i = m54; --i != -1;) {
        c += m50[i].pos;
    }
    c *= 1.0f / (float)m54;
    m70 = -c;
    for (int i = m54; --i != -1;) {
        m50[i].pos -= c;
    }

    if (!func_001E7EB0(params, 0x967CD3AE, &m1C, 0)) {
        float mx = 0.0f;
        for (int i = m54; --i != -1;) {
            float d = sqrtf(m50[i].pos.Length2());
            if (d > mx)
                mx = d;
        }
        if (mx > 30.0f) {
            float k = mx * 0.03333333507f;
            m1C = m1C / (k * k);
        }
    }
    D_00394328 = func_002032A0(0x542CF0C7, 0);
    m168 = 0.0f;
    for (int i = m54; --i != -1;) {
        float d = m50[i].pos.Length2();
        if (m168 < d)
            m168 = d;
    }
    m164 = 0;
    m168 = sqrtf(m168) + 1.0f;
    Vec_0018E4C8 off = m120.Rotate(m70);
    mE0 -= off;
}
