/* fuzzy: 96.3 */
// Rebuilds the view volumes for this frame: for each volume, four side planes through the eye and the
// volume's far corners (wound to face inwards, whichever side of the far face the eye is on) plus the far
// plane itself; optionally copies the volumes to the scratchpad, then uploads every plane to VU0 data memory
// and starts the culling microprogram's setup at 0x30.

typedef int qword __attribute__((mode(TI)));

struct Vec_0016C940 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0016C940() {}
    Vec_0016C940(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Corners_0016C940 {
    int m_00[4];
    Vec_0016C940 m_corner[4];       // 0x10
    Vec_0016C940 m_dir;             // 0x50
};

struct Volume_0016C940 {
    Corners_0016C940* m_corners;
    int m_04[3];
    Vec_0016C940 m_planes[5];       // 0x10
    int m_hits;                     // 0x60
    int m_64[3];
};

extern unsigned int D_0038BC14;
extern unsigned int D_0038BC1C;
extern int D_0038BC24;
extern Volume_0016C940 D_003E0AA0[];

extern "C" void func_0016C648();
extern "C" void func_0016C890(const Vec_0016C940* a, const Vec_0016C940* b);
extern "C" void func_003233B8(Vec_0016C940* dst, const Vec_0016C940* src);

// Single VU0 macro-mode operations.
static inline void ClearVI1()
{
    __asm__ __volatile__("viaddi $vi1, $vi0, 0");
}

static inline void MoveToVF1(qword v)
{
    __asm__ __volatile__("qmtc2.ni %0, $vf1" : : "r"(v));
}

static inline void StoreVF1Next()
{
    __asm__ __volatile__("vsqi.xyzw $vf1, ($vi1++)");
}

static inline void SetVI1(int v)
{
    __asm__ __volatile__("ctc2.ni %0, $vi1" : : "r"(v));
}

static inline void CallMicro30()
{
    __asm__ __volatile__("vcallms 0x30");
}

static inline void VuNop()
{
    __asm__ __volatile__("vnop");
}

extern "C" void func_0016C940(const Vec_0016C940* eye)
{
    Vec_0016C940 p;
    Vec_0016C940 q;
    Vec_0016C940 n;
    for (unsigned int i = 0; i < D_0038BC14; i++) {
    }
    func_0016C648();
    func_0016C890(eye, eye);
    for (unsigned int i = 0; i < D_0038BC1C; i++) {
        Corners_0016C940* c = D_003E0AA0[i].m_corners;
        Vec_0016C940 d(eye->x - c->m_corner[0].x, eye->y - c->m_corner[0].y, eye->z - c->m_corner[0].z,
                       eye->w - c->m_corner[0].w);
        if (0.0f <= d.x * c->m_dir.x + d.y * c->m_dir.y + d.z * c->m_dir.z) {
            p = Vec_0016C940(c->m_corner[0].x - eye->x, c->m_corner[0].y - eye->y, c->m_corner[0].z - eye->z, c->m_corner[0].w - eye->w);
            q = Vec_0016C940(c->m_corner[1].x - eye->x, c->m_corner[1].y - eye->y, c->m_corner[1].z - eye->z, c->m_corner[1].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[0] = n;
            p = Vec_0016C940(c->m_corner[2].x - eye->x, c->m_corner[2].y - eye->y, c->m_corner[2].z - eye->z, c->m_corner[2].w - eye->w);
            q = Vec_0016C940(c->m_corner[3].x - eye->x, c->m_corner[3].y - eye->y, c->m_corner[3].z - eye->z, c->m_corner[3].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[1] = n;
            p = Vec_0016C940(c->m_corner[1].x - eye->x, c->m_corner[1].y - eye->y, c->m_corner[1].z - eye->z, c->m_corner[1].w - eye->w);
            q = Vec_0016C940(c->m_corner[2].x - eye->x, c->m_corner[2].y - eye->y, c->m_corner[2].z - eye->z, c->m_corner[2].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[2] = n;
            p = Vec_0016C940(c->m_corner[3].x - eye->x, c->m_corner[3].y - eye->y, c->m_corner[3].z - eye->z, c->m_corner[3].w - eye->w);
            q = Vec_0016C940(c->m_corner[0].x - eye->x, c->m_corner[0].y - eye->y, c->m_corner[0].z - eye->z, c->m_corner[0].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[3] = n;
            p = Vec_0016C940(c->m_corner[2].x - c->m_corner[0].x, c->m_corner[2].y - c->m_corner[0].y, c->m_corner[2].z - c->m_corner[0].z, c->m_corner[2].w - c->m_corner[0].w);
            q = Vec_0016C940(c->m_corner[3].x - c->m_corner[0].x, c->m_corner[3].y - c->m_corner[0].y, c->m_corner[3].z - c->m_corner[0].z, c->m_corner[3].w - c->m_corner[0].w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * c->m_corner[0].x + n.y * c->m_corner[0].y + n.z * c->m_corner[0].z);
            D_003E0AA0[i].m_planes[4] = n;
        } else {
            p = Vec_0016C940(c->m_corner[1].x - eye->x, c->m_corner[1].y - eye->y, c->m_corner[1].z - eye->z, c->m_corner[1].w - eye->w);
            q = Vec_0016C940(c->m_corner[0].x - eye->x, c->m_corner[0].y - eye->y, c->m_corner[0].z - eye->z, c->m_corner[0].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[0] = n;
            p = Vec_0016C940(c->m_corner[3].x - eye->x, c->m_corner[3].y - eye->y, c->m_corner[3].z - eye->z, c->m_corner[3].w - eye->w);
            q = Vec_0016C940(c->m_corner[2].x - eye->x, c->m_corner[2].y - eye->y, c->m_corner[2].z - eye->z, c->m_corner[2].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[1] = n;
            p = Vec_0016C940(c->m_corner[2].x - eye->x, c->m_corner[2].y - eye->y, c->m_corner[2].z - eye->z, c->m_corner[2].w - eye->w);
            q = Vec_0016C940(c->m_corner[1].x - eye->x, c->m_corner[1].y - eye->y, c->m_corner[1].z - eye->z, c->m_corner[1].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[2] = n;
            p = Vec_0016C940(c->m_corner[0].x - eye->x, c->m_corner[0].y - eye->y, c->m_corner[0].z - eye->z, c->m_corner[0].w - eye->w);
            q = Vec_0016C940(c->m_corner[3].x - eye->x, c->m_corner[3].y - eye->y, c->m_corner[3].z - eye->z, c->m_corner[3].w - eye->w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * eye->x + n.y * eye->y + n.z * eye->z);
            D_003E0AA0[i].m_planes[3] = n;
            p = Vec_0016C940(c->m_corner[3].x - c->m_corner[0].x, c->m_corner[3].y - c->m_corner[0].y, c->m_corner[3].z - c->m_corner[0].z, c->m_corner[3].w - c->m_corner[0].w);
            q = Vec_0016C940(c->m_corner[2].x - c->m_corner[0].x, c->m_corner[2].y - c->m_corner[0].y, c->m_corner[2].z - c->m_corner[0].z, c->m_corner[2].w - c->m_corner[0].w);
            n = Vec_0016C940(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x, 0.0f);
            func_003233B8(&n, &n);
            n.w = -(n.x * c->m_corner[0].x + n.y * c->m_corner[0].y + n.z * c->m_corner[0].z);
            D_003E0AA0[i].m_planes[4] = n;
        }
    }
    if (D_0038BC24) {
        Volume_0016C940* src = D_003E0AA0;
        Volume_0016C940* dst = (Volume_0016C940*)0x70000000;
        for (int k = D_0038BC1C; k != 0; k--) {
            dst->m_corners = src->m_corners;
            Vec_0016C940* dp = dst->m_planes;
            Vec_0016C940* sp = src->m_planes;
            int j = 5;
            while (j--) {
                *dp++ = *sp++;
            }
            dst->m_hits = src->m_hits;
            src++;
            dst++;
        }
    }
    Volume_0016C940* v = D_003E0AA0;
    ClearVI1();
    for (int k = D_0038BC1C; k != 0; k--) {
        Vec_0016C940* pl = v->m_planes;
        for (int j = 5; j != 0; j--) {
            MoveToVF1(pl->q);
            StoreVF1Next();
            pl++;
        }
        v++;
    }
    SetVI1(*(volatile unsigned int*)&D_0038BC1C);
    CallMicro30();
    VuNop();
}
