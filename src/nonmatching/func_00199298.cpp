/* fuzzy: 83.7 */
/* blocked: game redoes var*var mult per access (cf. func_001118A0); no C++ shape found */
typedef int qword __attribute__((mode(TI)));

struct Vec_00199298 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00199298() {}
    Vec_00199298(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_00199298 operator+(const Vec_00199298& a, const Vec_00199298& b)
{
    return Vec_00199298(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
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

struct Obj_00199298 {
    char pad0[0x1380];
    int m_debug;
    bool Slide(Hit_00199298* hit, Mesh_00199298* mesh, int arg, int skipFace, int skipEdge);
};

bool Obj_00199298::Slide(Hit_00199298* hit, Mesh_00199298* mesh, int arg, int skipFace, int skipEdge)
{
    for (int i = mesh->numFaces; --i != -1;) {
        if (i == skipFace) continue;
        Face_00199298* f = &mesh->faces[i];
        for (int j = 1; j != -1; j--) {
            bool hitEdge = false;
            bool near = false;
            Vec_00199298 a = hit->pos;
            Vec_00199298 b = f->edges[j].pos;
            if (__builtin_fabsf(a.x - b.x) < 0.1f && __builtin_fabsf(a.y - b.y) < 0.1f && __builtin_fabsf(a.z - b.z) < 0.1f) {
                near = true;
            }
            if (near && hit->normal.x * f->normal.x + hit->normal.y * f->normal.y + hit->normal.z * f->normal.z < -0.99f) {
                hitEdge = true;
            }
            if (hitEdge) {
                Vec_00199298* d = &mesh->faces[skipFace].edges[skipEdge].dir;
                hit->normal = Vec_00199298(d->y * hit->normal.z - d->z * hit->normal.y, d->z * hit->normal.x - d->x * hit->normal.z, d->x * hit->normal.y - d->y * hit->normal.x, 0.0f);
                hit->m20 = func_001990F0(this, hit, arg);
                if (m_debug) {
                    Vec_00199298 e = hit->pos + Vec_00199298(hit->normal.x * 72.0f, hit->normal.y * 72.0f, hit->normal.z * 72.0f, hit->normal.w * 72.0f);
                    func_001235E8(&hit->pos, &e, 0xFFFF64FF, 0xFFFF64FF, 1);
                }
                return true;
            }
        }
    }
    return false;
}
