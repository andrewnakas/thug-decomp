/* cflags: -fno-gcse -fno-rerun-loop-opt */
/* fuzzy: 48.2 */
/* Projects a textured decal/shadow along a ray (start -> end) onto the collision geometry: every collision
   face the projection volume touches is clipped against the unit square in projector space, subdivided,
   and the surviving triangles are stored with projector UVs and per-vertex intensities in a decal block. */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_0014F538 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0014F538 {
    Vec_0014F538 r[4];
};

struct Vert_0014F538 {
    Vec_0014F538 pos;           /* 0x00 */
    unsigned char col[4];       /* 0x10 */
    float u, v;                 /* 0x14 */
    int pad;
};

struct Tri_0014F538 {
    Vert_0014F538 v[3];
};

struct Queue_0014F538 {
    int count;
    int size;
    char data[0x4000];
};

struct SmallFace_0014F538 {
    unsigned short flags;
    unsigned short material;
    unsigned char idx[4];
};

struct Face_0014F538 {
    unsigned short flags;
    unsigned short material;
    unsigned short idx[3];
};

struct PackedVert_0014F538 {
    unsigned short x, y, z;
};

struct Sector_0014F538 {
    char pad0[0xA];
    unsigned char smallFaces;   /* 0x0A */
    unsigned char packedVerts;  /* 0x0B */
    void* faces;                /* 0x0C */
    Vec_0014F538 origin;        /* 0x10 */
    char pad20[0x10];
    void* verts;                /* 0x30 */
    char pad34[4];
    unsigned char* intensity;   /* 0x38 */

    int VertIndex(unsigned short face, int k) const
    {
        if (smallFaces)
            return ((SmallFace_0014F538*)faces)[face].idx[k];
        return ((Face_0014F538*)faces)[face].idx[k];
    }
    unsigned short Flags(unsigned short face) const
    {
        if (smallFaces)
            return ((SmallFace_0014F538*)faces)[face].flags;
        return ((Face_0014F538*)faces)[face].flags;
    }
    Vec_0014F538 Vertex(int i) const
    {
        Vec_0014F538 p;
        if (packedVerts) {
            p = origin;
            PackedVert_0014F538* pv = (PackedVert_0014F538*)verts;
            p.x += (float)pv[i].x * (1.0f / 16.0f);
            p.y += (float)pv[i].y * (1.0f / 16.0f);
            p.z += (float)pv[i].z * (1.0f / 16.0f);
            p.w = 0.0f;
        } else {
            float* fv = (float*)verts;
            p.x = fv[i * 3 + 0];
            p.y = fv[i * 3 + 1];
            p.z = fv[i * 3 + 2];
            p.w = 0.0f;
        }
        return p;
    }
};

struct SectorRef_0014F538 {
    char pad0[8];
    Sector_0014F538* sector;    /* 0x08 */
};

struct Texture_0014F538 {
    char pad0[0x1C];
    void* base;                 /* 0x1C */
    char pad20[0xC];
    void* override;             /* 0x2C */
};

struct Heap_0014F538 {
    char pad0[0xD8];
    void* bottomUp;             /* 0xD8 */
};

extern Queue_0014F538 D_003C3DC0;
extern Heap_0014F538* D_00388A70;

extern "C" void func_00100B60(Mat_0014F538* out, Vec_0014F538* from, Vec_0014F538* to, Vec_0014F538* up);
extern "C" void func_00100D20(Mat_0014F538* out, float w, float h, float zNear, float zFar);
extern "C" void func_00102328(void* bbox, Vec_0014F538* p);
extern "C" void func_00102358(void* bbox, Vec_0014F538* p);
extern "C" void* func_0010A638(Heap_0014F538* heap, int size, int a, int b);
extern "C" void func_0010A8D8(Heap_0014F538* heap, void* p);
extern "C" void func_0010A950(Heap_0014F538* heap, void* region);
extern "C" void func_0010A9B0(Heap_0014F538* heap);
extern "C" int func_00138920(Texture_0014F538* tex);    /* width */
extern "C" int func_00138948(Texture_0014F538* tex);    /* height */
extern "C" unsigned int func_00142F08(int* keys);
extern "C" void func_00142F88(Queue_0014F538* q);
extern "C" void func_00142F98(Queue_0014F538* q, Vert_0014F538* v);
extern "C" int* func_0014EAF8(void* tex);
extern "C" int func_0014EC50(Tri_0014F538** out, float thr);
extern "C" bool func_0014F270(Vec_0014F538* p, Vec_0014F538* a, Vec_0014F538* b, Vec_0014F538* c);
extern "C" void func_0014F4B8(int* keys, unsigned int slot);
extern "C" unsigned short* func_001D8118(Sector_0014F538* sector, void* bbox, unsigned int* count);
extern "C" void func_00323298(Vec_0014F538* out, Mat_0014F538* m, Vec_0014F538* v);
extern "C" void func_00323318(Mat_0014F538* out, Mat_0014F538* a, Mat_0014F538* b);
extern "C" void func_003233B8(Vec_0014F538* out, Vec_0014F538* in);
extern "C" int func_00335048();     /* rand */
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

static inline void Set(Vec_0014F538& v, float x, float y, float z, float w)
{
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
}

/* does the 2D triangle (a, b, c) touch the square [-1,1]x[-1,1]? */
static inline bool TouchesUnitSquare(float ax, float ay, float bx, float by, float cx, float cy)
{
    if (ax < -1.0f && bx < -1.0f && cx < -1.0f)
        return false;
    if (ax > 1.0f && bx > 1.0f && cx > 1.0f)
        return false;
    if (ay < -1.0f && by < -1.0f && cy < -1.0f)
        return false;
    if (ay > 1.0f && by > 1.0f && cy > 1.0f)
        return false;

    Vec_0014F538 sq[4];
    Set(sq[0], -1.0f, -1.0f, 0.0f, 0.0f);
    Set(sq[1], 1.0f, -1.0f, 0.0f, 0.0f);
    Set(sq[2], 1.0f, 1.0f, 0.0f, 0.0f);
    Set(sq[3], -1.0f, 1.0f, 0.0f, 0.0f);
    Vec_0014F538 a, b, c;
    Set(a, ax, ay, 0.0f, 1.0f);
    Set(b, bx, by, 0.0f, 1.0f);
    Set(c, cx, cy, 0.0f, 1.0f);
    for (int i = 0; i < 4; i++) {
        if (func_0014F270(&sq[i], &a, &b, &c))
            return true;
    }
    if (-1.0f <= ax && ax <= 1.0f && -1.0f <= ay && ay <= 1.0f)
        return true;
    if (-1.0f <= bx && bx <= 1.0f && -1.0f <= by && by <= 1.0f)
        return true;
    if (-1.0f <= cx && cx <= 1.0f && -1.0f <= cy && cy <= 1.0f)
        return true;

    /* first triangle edge against the square's edges */
    float ex = bx - ax;
    float ey = by - ay;
    for (int i = 0; i < 4; i++) {
        Vec_0014F538& p = sq[i];
        Vec_0014F538& q = sq[(i + 1) % 4];
        float dy = q.y - p.y;
        float dx = q.x - p.x;
        float den = dy * ex - dx * ey;
        if (den == 0.0f)
            continue;
        float t = (dx * (ay - p.y) - dy * (ax - p.x)) / den;
        float s = (ex * (ay - p.y) - ey * (ax - p.x)) / den;
        if (t <= 1.0f && s <= 1.0f)
            return true;
    }
    return false;
}

static inline void SetGrey(unsigned char* col, unsigned char i)
{
    unsigned char c[4];
    c[0] = i;
    c[1] = i;
    c[2] = i;
    c[3] = 0x80;
    col[0] = c[0];
    col[1] = c[1];
    col[2] = c[2];
    col[3] = c[3];
}

int func_0014F538(void* self, SectorRef_0014F538** sectors, Vec_0014F538* start, Vec_0014F538* end,
                  Texture_0014F538* tex, Vec_0014F538* from, float size, float depth)
{
    Vec_0014F538 dir;
    dir.x = end->x - start->x;
    dir.y = end->y - start->y;
    dir.z = end->z - start->z;
    dir.w = end->w - start->w;
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    func_003233B8(&dir, &dir);

    Mat_0014F538 view;
    Mat_0014F538 proj;
    Vec_0014F538 up;
    if (from) {
        up.x = start->x - from->x;
        up.y = start->y - from->y;
        up.z = start->z - from->z;
        up.w = 0.0f;
        float dist = sqrtf(up.x * up.x + up.y * up.y + up.z * up.z) * 0.5f;
        Vec_0014F538 half;
        half.x = up.x * 0.5f;
        half.y = up.y * 0.5f;
        half.z = up.z * 0.5f;
        half.w = up.w;
        start->x -= half.x;
        start->y -= half.y;
        start->z -= half.z;
        start->w -= half.w;
        end->x -= half.x;
        end->y -= half.y;
        end->z -= half.z;
        func_003233B8(&up, &up);
        func_00100B60(&view, start, end, &up);
        func_00100D20(&proj, size, dist, 0.1f, len);
    } else if (fabsf(dir.y) > 0.5f) {
        float a = 2.0f * (float)func_00335048() * 1.46291812e-09f;
        float s = func_00341068(a);
        Set(up, s, 0.0f, func_00340F60(a), 0.0f);
        func_00100B60(&view, start, end, &up);
        func_00100D20(&proj, size, size, 0.1f, len);
    } else {
        Set(up, 0.0f, 1.0f, 0.0f, 0.0f);
        func_00100B60(&view, start, end, &up);
        func_00100D20(&proj, size, size, 0.1f, len);
    }
    Mat_0014F538 viewProj = view;
    func_00323318(&viewProj, &proj, &viewProj);

    void* image = tex->override;
    if (!image)
        image = tex->base;

    char bbox[0x20];
    func_00102328(bbox, start);
    int* block = 0;
    func_00102358(bbox, end);
    Tri_0014F538* tris = 0;

    for (; *sectors; sectors++) {
        Sector_0014F538* sector = (*sectors)->sector;
        unsigned int count;
        unsigned short* face = func_001D8118(sector, bbox, &count);
        /* (a short busy-wait loop of nops sits here in the original) */
        for (unsigned int i = 0; i < count; i++, face++) {
            if (sector->Flags(*face) & 0x1010)
                continue;

            Vec_0014F538 w[3];
            Vec_0014F538 s[3];
            w[0] = sector->Vertex(sector->VertIndex(*face, 0));
            w[0].w = 1.0f;
            w[1] = sector->Vertex(sector->VertIndex(*face, 1));
            w[1].w = 1.0f;
            w[2] = sector->Vertex(sector->VertIndex(*face, 2));
            w[2].w = 1.0f;
            for (int k = 0; k < 3; k++)
                func_00323298(&s[k], &viewProj, &w[k]);

            if (s[0].z < -1.0f && s[1].z < -1.0f && s[2].z < -1.0f)
                continue;
            if (s[0].z > 1.0f && s[1].z > 1.0f && s[2].z > 1.0f)
                continue;
            if (!TouchesUnitSquare(s[0].x, s[0].y, s[1].x, s[1].y, s[2].x, s[2].y))
                continue;

            /* skip faces degenerate in two axes */
            int same = (w[0].x == w[1].x && w[1].x == w[2].x);
            if (w[0].y == w[1].y && w[1].y == w[2].y)
                same++;
            if (w[0].z == w[1].z && w[1].z == w[2].z)
                same++;
            if (same >= 2)
                continue;

            if (!tris) {
                block = func_0014EAF8(image);
                if (!block)
                    continue;
                tris = (Tri_0014F538*)((char*)block + 0x410);
            }

            /* keep a half-texel border */
            float su, sv;
            if (from) {
                su = 1.0f - 1.0f / ((float)func_00138920(tex) * 0.5f);
                sv = 1.0f - 1.0f / ((float)func_00138948(tex) * 0.5f);
            } else {
                sv = 1.0f;
                su = sv;
            }

            unsigned int slot = func_00142F08(block);
            block[slot] = (int)(depth * 1000.0f);
            Tri_0014F538* t = &tris[slot];
            t->v[0].pos = w[0];
            t->v[0].u = (s[0].x * 0.5f + 0.5f) * su;
            t->v[0].v = (s[0].y * 0.5f + 0.5f) * sv;
            t->v[1].pos = w[1];
            t->v[1].u = (s[1].x * 0.5f + 0.5f) * su;
            t->v[1].v = (s[1].y * 0.5f + 0.5f) * sv;
            t->v[2].pos = w[2];
            t->v[2].u = (s[2].x * 0.5f + 0.5f) * su;
            t->v[2].v = (s[2].y * 0.5f + 0.5f) * sv;
            SetGrey(t->v[0].col, sector->intensity[sector->VertIndex(*face, 0)]);
            SetGrey(t->v[1].col, sector->intensity[sector->VertIndex(*face, 1)]);
            SetGrey(t->v[2].col, sector->intensity[sector->VertIndex(*face, 2)]);

            Vec_0014F538 e1, e2, n;
            e1.x = t->v[1].pos.x - t->v[0].pos.x;
            e1.y = t->v[1].pos.y - t->v[0].pos.y;
            e1.z = t->v[1].pos.z - t->v[0].pos.z;
            e1.w = 1.0f;
            e2.x = t->v[2].pos.x - t->v[0].pos.x;
            e2.y = t->v[2].pos.y - t->v[0].pos.y;
            e2.z = t->v[2].pos.z - t->v[0].pos.z;
            e2.w = 1.0f;
            n.x = e1.y * e2.z - e2.y * e1.z;
            n.y = e1.z * e2.x - e2.z * e1.x;
            n.z = e1.x * e2.y - e2.x * e1.y;
            n.w = 1.0f;
            float thr = (n.x * n.x + n.y * n.y + n.z * n.z) * (1.0f / 128.0f);

            /* subdivide the face into a scratch list */
            func_00142F88(&D_003C3DC0);
            D_003C3DC0.size = sizeof(Vert_0014F538);
            func_00142F98(&D_003C3DC0, &t->v[0]);
            func_00142F98(&D_003C3DC0, &t->v[1]);
            func_00142F98(&D_003C3DC0, &t->v[2]);
            func_0010A950(D_00388A70, D_00388A70->bottomUp);
            Tri_0014F538* list = (Tri_0014F538*)func_0010A638(D_00388A70, 0xC80, 1, 0);
            /* (another busy-wait loop of nops here in the original) */
            Tri_0014F538* out = list;
            func_0010A9B0(D_00388A70);
            while (func_0014EC50(&out, thr))
                ;

            float iu = 1.0f / su;
            float iv = 1.0f / sv;
            int empty = 1;
            for (Tri_0014F538* p = list; p != out; p++) {
                float x0 = (p->v[0].u * iu - 0.5f) * 2.0f;
                float y0 = (p->v[0].v * iv - 0.5f) * 2.0f;
                float x1 = (p->v[1].u * iu - 0.5f) * 2.0f;
                float y1 = (p->v[1].v * iv - 0.5f) * 2.0f;
                float x2 = (p->v[2].u * iu - 0.5f) * 2.0f;
                float y2 = (p->v[2].v * iv - 0.5f) * 2.0f;
                if (!TouchesUnitSquare(x0, y0, x1, y1, x2, y2))
                    continue;
                block[slot] = (int)(depth * 1000.0f);
                empty = 0;
                Tri_0014F538* d = &tris[slot];
                d->v[0].pos = p->v[0].pos;
                d->v[0].u = p->v[0].u;
                d->v[0].v = p->v[0].v;
                d->v[1].pos = p->v[1].pos;
                d->v[1].u = p->v[1].u;
                d->v[1].v = p->v[1].v;
                d->v[2].pos = p->v[2].pos;
                d->v[2].u = p->v[2].u;
                d->v[2].v = p->v[2].v;
                d->v[0].col[0] = p->v[0].col[0];
                d->v[0].col[1] = p->v[0].col[1];
                d->v[0].col[2] = p->v[0].col[2];
                d->v[0].col[3] = p->v[0].col[3];
                d->v[1].col[0] = p->v[1].col[0];
                d->v[1].col[1] = p->v[1].col[1];
                d->v[1].col[2] = p->v[1].col[2];
                d->v[1].col[3] = p->v[1].col[3];
                d->v[2].col[0] = p->v[2].col[0];
                d->v[2].col[1] = p->v[2].col[1];
                d->v[2].col[2] = p->v[2].col[2];
                d->v[2].col[3] = p->v[2].col[3];
                slot = func_00142F08(block);
            }
            if (list)
                func_0010A8D8(D_00388A70, list);
            if (empty)
                func_0014F4B8(block, slot);
        }
    }
    return 0;
}
