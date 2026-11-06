/* fuzzy: 54.4 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00199298 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00199298() {}
    Vec_00199298(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_00199298 operator*(const Vec_00199298& v, float s)
{
    return Vec_00199298(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_00199298 operator+(const Vec_00199298& a, const Vec_00199298& b)
{
    return Vec_00199298(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline float Dot_00199298(const Vec_00199298& a, const Vec_00199298& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline Vec_00199298 Cross_00199298(const Vec_00199298& a, const Vec_00199298& b)
{
    return Vec_00199298(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline bool Near_00199298(const Vec_00199298& a, const Vec_00199298& b)
{
    if (__builtin_fabsf(a.x - b.x) < 0.1f && __builtin_fabsf(a.y - b.y) < 0.1f && __builtin_fabsf(a.z - b.z) < 0.1f) {
        return true;
    }
    return false;
}

static inline Vec_00199298 Make_00199298(float x, float y, float z, float w)
{
    return Vec_00199298(x, y, z, w);
}

struct Edge_00199298 {
    Vec_00199298 pos;
    Vec_00199298 dir;
    Vec_00199298 m20;
};

struct Face_00199298 {
    Edge_00199298 edges[2];
    Vec_00199298 normal;
    char pad70[0x10];
};

struct Mesh_00199298 {
    char pad0[0x1040];
    Face_00199298 faces[32];
    int numFaces;
};

struct Hit_00199298 {
    Vec_00199298 pos;
    Vec_00199298 normal;
    float m20;
};

extern "C" float func_001990F0(void* self, Hit_00199298* hit, int arg);
extern "C" void func_001235E8(Vec_00199298* a, Vec_00199298* b, unsigned int c0, unsigned int c1, int n);

static inline bool Match_00199298(Hit_00199298* hit, Edge_00199298* e, Face_00199298* f)
{
    if (Near_00199298(hit->pos, e->pos) && Dot_00199298(hit->normal, f->normal) < -0.99f) {
        return true;
    }
    return false;
}

struct Obj_00199298 {
    char pad0[0x1380];
    int m_debug;
    bool Slide(Hit_00199298* hit, Mesh_00199298* mesh, int arg, int skipFace, int skipEdge);
};

bool Obj_00199298::Slide(Hit_00199298* hit, Mesh_00199298* mesh, int arg, int skipFace, int skipEdge)
{
    int i = mesh->numFaces - 1;
    if (i != -1) do {
        Vec_00199298* d = &mesh->faces[skipFace].edges[skipEdge].dir;
        if (i == skipFace) continue;
        Face_00199298* f = &mesh->faces[i];
        for (int j = 1; j != -1; j--) {
            bool near = false;
            bool hitEdge = false;
            Vec_00199298 a = hit->pos;
            Vec_00199298 b = f->edges[j].pos;
            if (__builtin_fabsf(a.x - b.x) < 0.1f && __builtin_fabsf(a.y - b.y) < 0.1f && __builtin_fabsf(a.z - b.z) < 0.1f) {
                near = true;
            }
            if (near && Dot_00199298(hit->normal, f->normal) < -0.99f) {
                hitEdge = true;
            }
            if (hitEdge) {
                hit->normal = Cross_00199298(*d, hit->normal);
                hit->m20 = func_001990F0(this, hit, arg);
                if (m_debug) {
                    Vec_00199298 s = hit->normal * 72.0f;
                    Vec_00199298 e = hit->pos + s;
                    func_001235E8(&hit->pos, &e, 0xFFFF64FF, 0xFFFF64FF, 1);
                }
                return true;
            }
        }
    } while (--i != -1);
    return false;
}
