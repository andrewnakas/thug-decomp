typedef int qword __attribute__((mode(TI)));

struct Vec_001A8940 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001A8940() {}
    Vec_001A8940(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

inline Vec_001A8940 operator-(const Vec_001A8940& a, const Vec_001A8940& b)
{
    return Vec_001A8940(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Vec_001A8940 operator+(const Vec_001A8940& a, const Vec_001A8940& b)
{
    return Vec_001A8940(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vec_001A8940 operator*(const Vec_001A8940& a, float s)
{
    return Vec_001A8940(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" int func_001D2220(const Vec_001A8940* start, const Vec_001A8940* dir,
                             const Vec_001A8940* v0, const Vec_001A8940* v1,
                             const Vec_001A8940* v2, float* t);
extern "C" void func_00183CB8(void* obj, void* ref);

struct Face8_001A8940 {
    int m0;
    unsigned char m_v[4];
};

struct Face16_001A8940 {
    unsigned short m0[2];
    unsigned short m_v[3];
};

struct Geom_001A8940 {
    int m0[2];
    unsigned char m8;
    unsigned char m9;
    unsigned char m_small;
    unsigned char mB;
    void* m_faces;
    int GetIndex(int face, int k)
    {
        if (m_small) return ((Face8_001A8940*)m_faces)[face].m_v[k];
        return ((Face16_001A8940*)m_faces)[face].m_v[k];
    }
};

struct Coll_001A8940 {
    int m0[2];
    Geom_001A8940* m8;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual Vec_001A8940 GetVertex(int i);
};

struct Ref_001A8940 {
    void* m_obj;
    ~Ref_001A8940()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Feeler_001A8940 {
    int m0[20];
    int m50;
    int m54[7];
    Coll_001A8940* m70;
    int m74[11];
    Vec_001A8940 mA0;
    int mB0[4];
    Ref_001A8940 mC0;
    int mC4[7];
    Feeler_001A8940();
    int GetCollision(const Vec_001A8940& start, const Vec_001A8940& end, int flags);
};

int func_001A8940(const Vec_001A8940& start, const Vec_001A8940& end, Vec_001A8940* hit,
                  Vec_001A8940* verts)
{
    Vec_001A8940 d = end - start;
    float t = 0.0f;
    if (func_001D2220(&start, &d, &verts[0], &verts[1], &verts[2], &t)) {
        *hit = start + d * t;
        return 1;
    }
    Feeler_001A8940 f;
    if (f.GetCollision(start, end, 0)) {
        Coll_001A8940* c = f.m70;
        int face = f.m50;
        Geom_001A8940* g = c->m8;
        verts[0] = c->GetVertex(g->GetIndex(face, 0));
        verts[1] = c->GetVertex(g->GetIndex(face, 1));
        verts[2] = c->GetVertex(g->GetIndex(face, 2));
        *hit = f.mA0;
        return 1;
    }
    return 0;
}
