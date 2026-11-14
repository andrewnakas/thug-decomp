/* fuzzy: 89.0 */
/* blocked: the game stores the cfc2 results through &hit/&index held in $a0/$v1 and reads vi1/vi6 into $t0/$t1; pointer locals reproduce the stores but not $t0/$t1, and the directed force search finds no match */
// Sphere-against-view-volumes test. With the VU0 path enabled the microprogram at 0x458 tests the sphere
// (centre in xyz, radius in w) and returns hit/index in vi1/vi6; otherwise each of the volumes is tested
// here, plane by plane. A hit bumps the volume's counter by `count`. Returns whether the sphere hit.

typedef int qword __attribute__((mode(TI)));

struct Vec_0016FBD0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Plane_0016FBD0 {
    float x, y, z, d;
};

struct Volume_0016FBD0 {
    int m_00[4];
    Plane_0016FBD0 m_planes[5];     // 0x10
    int m_hits;                     // 0x60
    int m_64[3];
};

struct PackedVolume_0016FBD0 {
    char m_00[0x60];
    int m_hits;                     // 0x60
    char m_64[0xC];
} __attribute__((packed));

extern int D_0038BC20;
extern int D_0038BC24;
extern int D_0038BC1C;
extern Volume_0016FBD0 D_003E0AA0[];

// Single VU0 macro-mode operations.
static inline void LoadVF7(const Vec_0016FBD0* p)
{
    __asm__ __volatile__("lqc2 $vf7, 0(%0)" : : "r"(p));
}

static inline void CallMicro458()
{
    __asm__ __volatile__("vcallms 0x458");
}

static inline void VuNop()
{
    __asm__ __volatile__("vnop");
}

static inline int GetVI1()
{
    int r;
    __asm__ __volatile__("cfc2.ni %0, $vi1" : "=r"(r));
    return r;
}

static inline int GetVI6()
{
    int r;
    __asm__ __volatile__("cfc2.ni %0, $vi6" : "=r"(r));
    return r;
}

extern "C" int func_0016FBD0(const Vec_0016FBD0* centre, int count, float radius)
{
    if (D_0038BC20) {
        Vec_0016FBD0 s;
        volatile int hit;
        volatile int index;
        s = *centre;
        s.w = radius;
        LoadVF7(&s);
        CallMicro458();
        VuNop();
        int h = GetVI1();
        int i = GetVI6();
        hit = h;
        index = i;
        if (hit) {
            ((PackedVolume_0016FBD0*)D_003E0AA0)[index].m_hits += count;
        }
        return hit != 0;
    }
    float x = centre->x;
    float y = centre->y;
    float z = centre->z;
    Volume_0016FBD0* v = D_0038BC24 ? (Volume_0016FBD0*)0x70000000 : D_003E0AA0;
    int n = D_0038BC1C;
    if (n) {
        float nr = -radius;
        do {
            Plane_0016FBD0* p = v->m_planes;
            int i = 5;
            do {
                if (nr <= p->x * x + p->y * y + p->z * z + p->d) {
                    goto next;
                }
                p++;
            } while (--i);
            v->m_hits += count;
            return 1;
        next:
            v++;
        } while (--n);
    }
    return 0;
}
