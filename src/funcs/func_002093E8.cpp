typedef int qword_002093E8 __attribute__((mode(TI)));

struct Vec_002093E8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_002093E8 q;
    };
};

struct Line_002093E8 {
    Vec_002093E8 start;
    Vec_002093E8 end;
};

struct Hit_002093E8 {
    char m_pad[0x18];
    int m_18;
};

struct Handle_002093E8;

extern "C" void func_00183C98(Hit_002093E8* o, Handle_002093E8* h);
extern "C" void func_00183CB8(Hit_002093E8* o, Handle_002093E8* h);

struct Handle_002093E8 {
    Hit_002093E8* m_obj;
    Handle_002093E8* m_prev;
    Handle_002093E8* m_next;
    Handle_002093E8& operator=(Hit_002093E8* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
};

struct Feeler_002093E8;

extern void* D_0038EE60;

extern "C" void func_00101F38(Line_002093E8* line);
extern "C" void func_002093C0();
extern "C" bool func_001D3C00(Line_002093E8* line, Vec_002093E8* out, void (*cb)(), void* scene);
extern "C" bool func_001D3890(Line_002093E8* line, Vec_002093E8* out, void (*cb)(), void* scene);
extern "C" Hit_002093E8* func_001D4030(Line_002093E8* line, Vec_002093E8* out, void (*cb)(), void* scene);
extern "C" Hit_002093E8* func_001D3C28(Line_002093E8* line, Vec_002093E8* out, void (*cb)(), void* scene);

struct Feeler_002093E8 {
    Line_002093E8 m_line;
    int m_callback;
    char m_pad24[0x30 - 0x24];
    Vec_002093E8 m_point;
    Vec_002093E8 m_normal;
    char m_pad50[0x60 - 0x50];
    float m_dist;
    char m_pad64[0x78 - 0x64];
    int m_78;
    int m_7C;
    Feeler_002093E8* m_self;
    int m_84;
    char m_88;
    char m_89;
    char m_pad8a[0x90 - 0x8A];
    float m_hitDist;
    char m_pad94[0xA0 - 0x94];
    Vec_002093E8 m_hitNormal;
    Vec_002093E8 m_hitPoint;
    Handle_002093E8 m_hit;
    int m_CC;
    char m_padD0[4];
    void* m_scene;
    bool Check(bool getHit, bool all);
};

bool Feeler_002093E8::Check(bool getHit, bool all)
{
    void (*cb)() = 0;
    Line_002093E8 line;
    func_00101F38(&line);
    line.start.q = m_line.start.q;
    line.end.q = m_line.end.q;
    m_self = this;
    m_88 = 0;
    m_89 = 0;
    m_78 = 0;
    m_84 = 0;
    if (m_callback) {
        cb = func_002093C0;
    }
    void* scene = m_scene;
    if (!scene) {
        scene = D_0038EE60;
    }
    m_hit = 0;
    m_CC = 0;
    bool hit;
    if (all) {
        hit = func_001D3C00(&line, &m_point, cb, scene);
    } else {
        hit = func_001D3890(&line, &m_point, cb, scene);
    }
    if (getHit) {
        if (all) {
            m_hit = func_001D4030(&line, &m_point, cb, scene);
        } else {
            m_hit = func_001D3C28(&line, &m_point, cb, scene);
        }
        if (m_hit.m_obj) {
            m_CC = m_hit.m_obj->m_18;
        }
    }
    m_hitDist = m_dist;
    m_hitNormal.q = m_normal.q;
    m_hitPoint.q = m_point.q;
    return hit || m_hit.m_obj;
}
