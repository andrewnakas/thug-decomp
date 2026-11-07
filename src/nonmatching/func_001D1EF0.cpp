/* fuzzy: 76.5 */
typedef int qword_001D1EF0 __attribute__((mode(TI)));

struct Vec_001D1EF0 {
    union {
        qword_001D1EF0 q;
        float c[4];
    };
    Vec_001D1EF0() {}
    Vec_001D1EF0(const Vec_001D1EF0& o) { q = o.q; }
    Vec_001D1EF0& operator=(const Vec_001D1EF0& o)
    {
        q = o.q;
        return *this;
    }
    Vec_001D1EF0(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};

static inline Vec_001D1EF0 operator-(const Vec_001D1EF0& a, const Vec_001D1EF0& b)
{
    return Vec_001D1EF0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline Vec_001D1EF0 operator+(const Vec_001D1EF0& a, const Vec_001D1EF0& b)
{
    return Vec_001D1EF0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_001D1EF0 operator*(const Vec_001D1EF0& a, float s)
{
    Vec_001D1EF0 v(a);
    v[0] *= s;
    v[1] *= s;
    v[2] *= s;
    v[3] *= s;
    return v;
}

struct Seg_001D1EF0 {
    Vec_001D1EF0 p0;
    Vec_001D1EF0 p1;
};

struct Hit_001D1EF0 {
    Vec_001D1EF0 normal;
    Vec_001D1EF0 point;
    int m20;
    void SetPoint(const Vec_001D1EF0& v)
    {
        Vec_001D1EF0 p(v);
        p[3] = 1.0f;
        point = p;
    }
};

class Obj_001D1EF0 {
public:
    int m0;
    unsigned short m4;
    short m6;
    int m8;
    virtual void v0();
    virtual void v1();
    virtual unsigned int GetFlags(int face);
    virtual int GetTerrain(int face);
};

struct Info_001D1EF0;
typedef void (*Callback_001D1EF0)(Info_001D1EF0* info);

struct Info_001D1EF0 {
    Hit_001D1EF0 hit;
    float m30;
    unsigned short m34;
    unsigned short m36;
    unsigned short m38;
    int m3C;
    Obj_001D1EF0* m40;
    int m44;
    int m48;
    Callback_001D1EF0 m4C;
    int m50;
    int m54;
    unsigned char m58;
    unsigned char m59;
};

extern int D_0038DE40;

extern "C" bool func_001D1EF0(Seg_001D1EF0* line, Obj_001D1EF0* obj, Hit_001D1EF0* hit, float t, Info_001D1EF0* info)
{
    bool accept = false;
    bool found = false;
    Info_001D1EF0 saved;
    if (D_0038DE40) {
        if (info->m30 <= t) {
            accept = true;
        }
    } else if (t <= info->m30) {
        accept = true;
    }
    if (!accept) {
        saved = *info;
    }
    int face = hit->m20;
    unsigned int flags = obj->GetFlags(face);
    if (!(flags & info->m34) && !(~flags & info->m36)) {
        info->m58 = 1;
        info->hit = *hit;
        info->m30 = t;
        info->m38 = flags;
        info->m3C = obj->GetTerrain(face);
        info->m59 = flags & 0x40;
        info->m40 = obj;
        info->m44 = obj->m0;
        info->hit.SetPoint(line->p0 + (line->p1 - line->p0) * t);
        if (info->m4C) {
            info->m4C(info);
        }
        found = true;
    }
    if (!accept) {
        *info = saved;
    }
    return accept ? found : false;
}
