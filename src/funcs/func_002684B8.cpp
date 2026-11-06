typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_002684B8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    float& operator[](int i) { return (&x)[i]; }
    void FromMatrix(struct Mat_002684B8& m);
};

struct Mat_002684B8 {
    Row_002684B8 r[4];
    Row_002684B8& operator[](int i) { return r[i]; }
    Mat_002684B8& operator*=(const Mat_002684B8& o);
    void Rotate(const Row_002684B8& a);
    void RotX(float a);
    void RotY(float a);
    void RotZ(float a);
    void Identity()
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
};

extern "C" Mat_002684B8* func_00100890(Mat_002684B8* m, float a);
extern "C" Mat_002684B8* func_00100928(Mat_002684B8* m, float a);
extern "C" Mat_002684B8* func_001009C0(Mat_002684B8* m, float a);
extern "C" Mat_002684B8* func_00323318(Mat_002684B8* out, const Mat_002684B8* a, const Mat_002684B8* b);

inline Mat_002684B8& Mat_002684B8::operator*=(const Mat_002684B8& o)
{
    func_00323318(this, &o, this);
    return *this;
}
inline void Mat_002684B8::RotX(float a)
{
    Mat_002684B8 t;
    *this *= *func_00100890(&t, a);
}
inline void Mat_002684B8::RotY(float a)
{
    Mat_002684B8 t;
    *this *= *func_00100928(&t, a);
}
inline void Mat_002684B8::RotZ(float a)
{
    Mat_002684B8 t;
    *this *= *func_001009C0(&t, a);
}
inline void Mat_002684B8::Rotate(const Row_002684B8& a)
{
    if (a.x != 0.0f || a.y != 0.0f || a.z != 0.0f) {
        RotX(a.x);
        RotY(a.y);
        RotZ(a.z);
    }
}

extern "C" void func_00119228(Row_002684B8* q, float w);
extern "C" void func_00119230(Row_002684B8* q, float x, float y, float z);

inline void Row_002684B8::FromMatrix(Mat_002684B8& m)
{
    float tr = m[0][0] + m[1][1] + m[2][2];
    float sq;
    if (tr > 0.0f) {
        sq = sqrtf(tr + 1.0f);
        func_00119228(this, sq * 0.5f);
        sq = 0.5f / sq;
        func_00119230(this, (m[2][1] - m[1][2]) * sq, (m[0][2] - m[2][0]) * sq, (m[1][0] - m[0][1]) * sq);
    } else {
        int a = 0;
        if (m[0][0] < m[1][1])
            a = 1;
        if (m[a][a] < m[2][2])
            a = 2;
        int b = (a + 1) % 3;
        int c = (b + 1) % 3;
        sq = sqrtf(m[a][a] - (m[b][b] + m[c][c]) + 1.0f);
        (*this)[a] = sq * 0.5f;
        sq = 0.5f / sq;
        (*this)[b] = (m[b][a] + m[a][b]) * sq;
        (*this)[c] = (m[c][a] + m[a][c]) * sq;
        (*this)[3] = (m[c][b] - m[b][c]) * sq;
    }
}

struct Entry_002684B8 {
    char pad0[0x10];
    Row_002684B8 m10;
    Row_002684B8 m20;
    Row_002684B8 m30;
    Row_002684B8 m40;
    int m50;
    int m54;
    int m58;
    short m5C;
    unsigned char m5E;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_0026B448(Entry_002684B8* e, int a);
extern "C" void func_0026B460(Entry_002684B8* e, int a);
extern "C" void func_00229FF8(void* params, Row_002684B8* out);
extern "C" void func_0022A268(void* params, Row_002684B8* out);
extern "C" int func_001DB060(unsigned int id);
extern "C" int func_00229E70(void* params);
extern "C" int func_00229F00(void* params, int i);
extern "C" void func_002682E0(Row_002684B8* a, Row_002684B8* b, Row_002684B8* c, Row_002684B8* d);

struct Obj_002684B8 {
    char pad0[0x50];
    Entry_002684B8* m50;
    short (*m54)[4];
    char pad58[8];
    int m60;
    void Add(int id, void* params);
};

void Obj_002684B8::Add(int id, void* params)
{
    Entry_002684B8* e = &m50[m60];
    short* ix = m54[m60];
    m60++;
    unsigned int type;
    func_001E8398(params, 0x12B4E660, &type, 0);
    bool rot = type == 0x30C19600;
    unsigned int mode;
    func_001E8398(params, 0x7321A8D6, &mode, 0);
    e->m50 = 0;
    e->m54 = 0;
    for (int i = 0; i < 4; i++) ix[i] = -1;
    e->m5C = id;
    e->m58 = 0;
    if (func_001E8708(params, 0x7C2552B9))
        func_0026B448(e, 2);
    else
        func_0026B460(e, 2);
    func_00229FF8(params, &e->m30);
    if (func_001E8708(params, 0xF4C67F0F)) e->m58 |= 1;
    if (func_001E8708(params, 0x4DE721DE)) e->m58 |= 2;
    if (rot) {
        e->m58 |= 0x10;
        if (mode == 0xC84243DA)
            e->m58 |= 0x20;
        else
            e->m58 &= ~0x20;
    }
    if (func_001E8708(params, 0xF6DD21CA))
        e->m58 |= 0x40;
    else
        e->m58 &= ~0x40;
    if (func_001E8708(params, 0x5E9CE29B))
        e->m58 |= 0x80;
    else
        e->m58 &= ~0x80;
    if (func_001E8708(params, 0xF22BFC6D))
        e->m58 |= 0x8;
    else
        e->m58 &= ~0x8;
    if (rot) {
        Row_002684B8 ang;
        func_0022A268(params, &ang);
        Mat_002684B8 m;
        Row_002684B8 q;
        m.Identity();
        m.Rotate(ang);
        q.FromMatrix(m);
        e->m40 = q;
    }
    if (!rot) {
        e->m5E = 0;
        unsigned int v;
        func_001E8398(params, 0x54CF8532, &v, 1);
        e->m5E = func_001DB060(v);
    }
    int cnt = func_00229E70(params);
    if (cnt) {
        for (int i = 0; i < cnt; i++) ix[i] = func_00229F00(params, i);
    }
    func_002682E0(&e->m30, &e->m30, &e->m10, &e->m20);
}
