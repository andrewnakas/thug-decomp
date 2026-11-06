/* fuzzy: 70.3 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00190EC8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00190EC8() {}
    Vec_00190EC8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00190EC8& operator+=(const Vec_00190EC8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

inline Vec_00190EC8 operator-(const Vec_00190EC8& a, const Vec_00190EC8& b)
{
    return Vec_00190EC8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Vec_00190EC8 operator+(const Vec_00190EC8& a, const Vec_00190EC8& b)
{
    return Vec_00190EC8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vec_00190EC8 operator*(const Vec_00190EC8& a, float s)
{
    return Vec_00190EC8(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_00190EC8 {
    void* m_obj;
    ~Ref_00190EC8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct BBox_00190EC8 {
    Vec_00190EC8 m_min;
    Vec_00190EC8 m_max;
    BBox_00190EC8(const Vec_00190EC8& mn, const Vec_00190EC8& mx);
};

struct Feeler_001A8940 {
    Vec_00190EC8 m_start;
    Vec_00190EC8 m_end;
    int m20[28];
    float m_frac;
    int m94[7];
    Vec_00190EC8 m_normal;
    Ref_00190EC8 mC0;
    int mC4[4];
    void* mD4;
    int mD8[2];
    Feeler_001A8940();
};

struct Item_00190EC8 {
    Vec_00190EC8 m_off;
    Vec_00190EC8 m_normal;
    int m20;
    float m_dist;
    float m_dot;
    char m_hit;
    char m_flag;
};

struct Obj_00190EC8 {
    char pad0[0x54];
    unsigned short m_count;
    char pad56[0xE0 - 0x56];
    Vec_00190EC8 m_pos;
    char padF0[0x160 - 0xF0];
    signed char m_hits;
    char pad161[0x168 - 0x161];
    float m_radius;
    bool Probe();
};

extern char D_003E3570[];
extern Item_00190EC8 D_003E4540[];
extern "C" void func_001DA948(void* cache, BBox_00190EC8* b);
extern "C" char func_002093E8(Feeler_001A8940* f, int a, int b);

bool Obj_00190EC8::Probe()
{
    Feeler_001A8940 f;
    BBox_00190EC8 box(m_pos - Vec_00190EC8(m_radius, m_radius, m_radius, 1.0f),
                      m_pos + Vec_00190EC8(m_radius, m_radius, m_radius, 1.0f));
    func_001DA948(D_003E3570, &box);
    f.mD4 = D_003E3570;
    m_hits = 0;
    int i = m_count;
    while (i-- != 0) {
        Item_00190EC8* it = &D_003E4540[i];
        f.m_end = m_pos;
        f.m_start = m_pos;
        f.m_end += it->m_off;
        it->m_hit = func_002093E8(&f, 0, 0);
        if (it->m_hit) {
            float t = 1.0f - f.m_frac;
            Vec_00190EC8 d = f.m_end - f.m_start;
            Vec_00190EC8 v = d * t;
            it->m_normal = f.m_normal;
            it->m_dist = 0.0f;
            it->m_flag = 0;
            it->m_dot = it->m_normal.x * v.x + it->m_normal.y * v.y + it->m_normal.z * v.z;
            it->m_hit = it->m_dot <= it->m_dist;
            if (it->m_hit) {
                m_hits++;
            }
        }
    }
    return m_hits != 0;
}
