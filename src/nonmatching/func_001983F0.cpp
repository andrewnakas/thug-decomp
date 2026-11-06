/* fuzzy: 56.8 */
struct Vec_001983F0 {
    float x, y, z, w;
};

static inline void Scale_001983F0(Vec_001983F0* r, const Vec_001983F0* v, float s)
{
    r->x = v->x * s;
    r->y = v->y * s;
    r->z = v->z * s;
    r->w = v->w * s;
}

static inline Vec_001983F0 Add_001983F0(const Vec_001983F0& a, const Vec_001983F0& b)
{
    Vec_001983F0 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

static inline bool Elapsed_001983F0(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

extern "C" unsigned int func_0010FC30();
extern "C" void func_001235E8(Vec_001983F0* a, Vec_001983F0* b, unsigned int c0, unsigned int c1, int f);

struct Obj_001983F0 {
    char pad0[0x20];
    Vec_001983F0 m20;
    char pad30[0x12C - 0x30];
    int m12C;
    unsigned int m130;
    char pad134[0x144 - 0x134];
    float m144;
    char pad148[0x180 - 0x148];
    float m180;
    char pad184[0x135C - 0x184];
    float m135C;
    char pad1360[0x1380 - 0x1360];
    int m1380;
    void ApplyGravity();
};

void Obj_001983F0::ApplyGravity()
{
    unsigned int start;
    if (m12C && (start = m130, func_0010FC30() - start > 300)) {
        m144 -= m135C * 115.920006f / m180;
    } else {
        m144 -= m135C * 386.4f / m180;
    }
    if (m1380) {
        Vec_001983F0 end;
        Vec_001983F0 sc;
        Vec_001983F0 v;
        v.x = 0.0f;
        v.y = -386.4f / m180;
        v.z = 0.0f;
        v.w = 1.0f;
        Scale_001983F0(&sc, &v, 0.05f);
        end.x = m20.x + sc.x;
        end.y = m20.y + sc.y;
        end.z = m20.z + sc.z;
        end.w = m20.w + sc.w;
        func_001235E8(&m20, &end, 0xFF003232, 0xFF003232, 1);
    }
}
