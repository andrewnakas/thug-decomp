/* fuzzy: 95.5 */
/* Projects a textured decal/shadow along a ray (start -> end) onto the collision geometry: every collision
   face the projection volume touches is clipped against the unit square in projector space, subdivided,
   and the surviving triangles are stored with projector UVs and per-vertex intensities in a decal block. */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_0014F538;
extern "C" void func_003233B8(Vec_0014F538* out, Vec_0014F538* in);

struct Vec_0014F538 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0014F538() {}
    void Normalize()
    {
        func_003233B8(this, this);
    }
    Vec_0014F538(float x_, float y_, float z_, float w_)
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }
};

struct Mat_0014F538 {
    qword r[4];
};

struct Heap_0014F538 {
    char pad0[0xD8];
    void* bottomUp;             /* 0xD8 */
};

extern Heap_0014F538* D_00388A70;
extern "C" void* func_0010A638(Heap_0014F538* heap, int size, int a, int b);
extern "C" void func_0010A8D8(Heap_0014F538* heap, void* p);

struct Color_0014F538 {
    unsigned char r, g, b, a;
    Color_0014F538() {}
    Color_0014F538(int r_, int g_, int b_, int a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct Vert_0014F538 {
    Vec_0014F538 pos;           /* 0x00 */
    Color_0014F538 col;         /* 0x10 */
    float u, v;                 /* 0x14 */
    int pad;

    /* scratch arrays come from the current heap context */
    static void* operator new[](unsigned int size)
    {
        return func_0010A638(D_00388A70, size, 1, 0);
    }
    static void operator delete[](void* p)
    {
        func_0010A8D8(D_00388A70, p);
    }
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

struct Vec3_0014F538 {
    float x, y, z;
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

    unsigned short VertIndex(unsigned short face, int k) const
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
            p.x += (float)((PackedVert_0014F538*)verts)[i].x * (1.0f / 16.0f);
            p.y += (float)((PackedVert_0014F538*)verts)[i].y * (1.0f / 16.0f);
            p.z += (float)((PackedVert_0014F538*)verts)[i].z * (1.0f / 16.0f);
            p.w = 0.0f;
        } else {
            p.x = ((Vec3_0014F538*)verts)[i].x;
            p.y = ((Vec3_0014F538*)verts)[i].y;
            p.z = ((Vec3_0014F538*)verts)[i].z;
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

extern Queue_0014F538 D_003C3DC0;

extern "C" void func_00100B60(Mat_0014F538* out, Vec_0014F538* from, Vec_0014F538* to, Vec_0014F538* up);
extern "C" void func_00100D20(Mat_0014F538* out, float w, float h, float zNear, float zFar);
extern "C" void func_00102328(void* bbox, Vec_0014F538* p);
extern "C" void func_00102358(void* bbox, Vec_0014F538* p);
extern "C" void func_0010A950(Heap_0014F538* heap, void* region);
extern "C" void func_0010A9B0(Heap_0014F538* heap);
extern "C" int func_00138920(Texture_0014F538* tex);    /* width */
extern "C" int func_00138948(Texture_0014F538* tex);    /* height */
extern "C" unsigned int func_00142F08(int* keys);
extern "C" void func_00142F88(Queue_0014F538* q);
extern "C" void func_00142F98(Queue_0014F538* q, Vert_0014F538* v);
extern "C" int* func_0014EAF8(void* tex);
extern "C" int func_0014EC50(float thr, Vert_0014F538** out, void* unused);
extern "C" bool func_0014F270(Vec_0014F538* p, Vec_0014F538* a, Vec_0014F538* b, Vec_0014F538* c);
extern "C" void func_0014F4B8(int* keys, unsigned int slot);
extern "C" unsigned short* func_001D8118(Sector_0014F538* sector, void* bbox, unsigned int* count);
extern "C" void func_00323298(Vec_0014F538* out, Mat_0014F538* m, Vec_0014F538* v);
extern "C" void func_00323318(Mat_0014F538* out, Mat_0014F538* a, Mat_0014F538* b);
extern "C" int func_00335048();     /* rand */
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

static inline Vec_0014F538 Transform(Mat_0014F538& m, Vec_0014F538& v)
{
    Vec_0014F538 r;
    func_00323298(&r, &m, &v);
    return r;
}

static inline Mat_0014F538 Mul(Mat_0014F538& a, Mat_0014F538& b)
{
    Mat_0014F538 r = a;
    func_00323318(&r, &b, &r);
    return r;
}

static inline void Set(Vec_0014F538& v, float x, float y, float z, float w)
{
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
}

/* does the segment p->q cross the ray (ax, ay) + (ex, ey)? */
static inline bool EdgesCross(Vec_0014F538& p, Vec_0014F538& q, float ax, float ay, float ex, float ey)
{
    float dx = q.x - p.x;
    float dy = q.y - p.y;
    float den = dy * ex - dx * ey;
    if (den == 0.0f)
        return false;
    float t = (dx * (ay - p.y) - dy * (ax - p.x)) / den;
    float s = (ex * (ay - p.y) - ey * (ax - p.x)) / den;
    return t <= 1.0f && s <= 1.0f;
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

    Vec_0014F538 sq[4] = {
        Vec_0014F538(-1.0f, -1.0f, 0.0f, 0.0f),
        Vec_0014F538(1.0f, -1.0f, 0.0f, 0.0f),
        Vec_0014F538(1.0f, 1.0f, 0.0f, 0.0f),
        Vec_0014F538(-1.0f, 1.0f, 0.0f, 0.0f),
    };
    Vec_0014F538 a(ax, ay, 0.0f, 1.0f);
    Vec_0014F538 b(bx, by, 0.0f, 1.0f);
    Vec_0014F538 c(cx, cy, 0.0f, 1.0f);
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
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        if (EdgesCross(sq[i], sq[j], ax, ay, bx - ax, by - ay))
            return true;
    }
    return false;
}

static inline void SetGrey(Color_0014F538& col, unsigned char i)
{
    col = Color_0014F538(i, i, i, 0x80);
}

int func_0014F538(void* self, SectorRef_0014F538** sectors, Vec_0014F538* start, Vec_0014F538* end,
                  float size, float depth, Texture_0014F538* tex, Vec_0014F538* from)
{
    Mat_0014F538 view;
    Mat_0014F538 proj;
    Mat_0014F538 viewProj;
    Vec_0014F538 dir;
    dir.x = end->x - start->x;
    dir.y = end->y - start->y;
    dir.z = end->z - start->z;
    dir.w = end->w - start->w;
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    dir.Normalize();

    if (from) {
        Vec_0014F538 up;
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
        Vec_0014F538 up;
        Set(up, s, 0.0f, func_00340F60(a), 0.0f);
        func_00100B60(&view, start, end, &up);
        func_00100D20(&proj, size, size, 0.1f, len);
    } else {
        Vec_0014F538 up;
        Set(up, 0.0f, 1.0f, 0.0f, 0.0f);
        func_00100B60(&view, start, end, &up);
        func_00100D20(&proj, size, size, 0.1f, len);
    }
    viewProj = Mul(view, proj);

    void* image = tex->override;
    if (!image)
        image = tex->base;

    char bbox[0x20];
    func_00102328(bbox, start);
    int* block = 0;
    func_00102358(bbox, end);
    Vert_0014F538* tris = 0;

    SectorRef_0014F538* ref;
    while ((ref = *sectors++) != 0) {
        Sector_0014F538* sector = ref->sector;
        unsigned int count;
        unsigned short* face = func_001D8118(sector, bbox, &count);
        Vec_0014F538 s[3];
        for (unsigned int i = 0; i < count; i++, face++) {
            if (sector->Flags(*face) & 0x1010)
                continue;

            Vec_0014F538 w0 = sector->Vertex(sector->VertIndex(*face, 0));
            Vec_0014F538 w1 = sector->Vertex(sector->VertIndex(*face, 1));
            Vec_0014F538 w2 = sector->Vertex(sector->VertIndex(*face, 2));
            w0.w = 1.0f;
            w1.w = 1.0f;
            w2.w = 1.0f;
            s[0] = Transform(viewProj, w0);
            s[1] = Transform(viewProj, w1);
            s[2] = Transform(viewProj, w2);

            if (s[0].z < -1.0f && s[1].z < -1.0f && s[2].z < -1.0f)
                continue;
            if (s[0].z > 1.0f && s[1].z > 1.0f && s[2].z > 1.0f)
                continue;
            if (!TouchesUnitSquare(s[0].x, s[0].y, s[1].x, s[1].y, s[2].x, s[2].y))
                continue;

            /* skip faces degenerate in two axes */
            int same = (w0.x == w1.x && w1.x == w2.x);
            if (w0.y == w1.y && w1.y == w2.y)
                same++;
            if (w0.z == w1.z && w1.z == w2.z)
                same++;
            if (same >= 2)
                continue;

            if (!tris) {
                block = func_0014EAF8(image);
                if (!block)
                    continue;
                tris = (Vert_0014F538*)((char*)block + 0x410);
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
            int base = slot * 3;
            tris[base + 0].pos = w0;
            tris[base + 1].pos = w1;
            tris[base + 2].pos = w2;
            tris[base + 0].u = (s[0].x * 0.5f + 0.5f) * su;
            tris[base + 0].v = (s[0].y * 0.5f + 0.5f) * sv;
            tris[base + 1].u = (s[1].x * 0.5f + 0.5f) * su;
            tris[base + 1].v = (s[1].y * 0.5f + 0.5f) * sv;
            tris[base + 2].u = (s[2].x * 0.5f + 0.5f) * su;
            tris[base + 2].v = (s[2].y * 0.5f + 0.5f) * sv;
            unsigned char c0 = sector->intensity[sector->VertIndex(*face, 0)];
            unsigned char c1 = sector->intensity[sector->VertIndex(*face, 1)];
            unsigned char c2 = sector->intensity[sector->VertIndex(*face, 2)];
            Vert_0014F538* t0 = &tris[base + 0];
            Vert_0014F538* t1 = &tris[base + 1];
            Vert_0014F538* t2 = &tris[base + 2];
            SetGrey(tris[base + 0].col, c0);
            SetGrey(tris[base + 1].col, c1);
            SetGrey(tris[base + 2].col, c2);

            Vec_0014F538 e1, e2, n;
            Set(e1, t1->pos.x - t0->pos.x, t1->pos.y - t0->pos.y, t1->pos.z - t0->pos.z, 1.0f);
            Set(e2, t2->pos.x - t0->pos.x, t2->pos.y - t0->pos.y, t2->pos.z - t0->pos.z, 1.0f);
            Set(n, e1.y * e2.z - e2.y * e1.z, e1.z * e2.x - e2.z * e1.x, e1.x * e2.y - e2.x * e1.y, 1.0f);
            float thr = (n.x * n.x + n.y * n.y + n.z * n.z) * (1.0f / 128.0f);

            /* subdivide the face into a scratch list */
            func_00142F88(&D_003C3DC0);
            D_003C3DC0.size = sizeof(Vert_0014F538);
            func_00142F98(&D_003C3DC0, t0);
            func_00142F98(&D_003C3DC0, t1);
            func_00142F98(&D_003C3DC0, t2);
            func_0010A950(D_00388A70, D_00388A70->bottomUp);
            Vert_0014F538* list = new Vert_0014F538[100];
            Vert_0014F538* out = list;
            Vert_0014F538* p = list;
            func_0010A9B0(D_00388A70);
            while (func_0014EC50(thr, &out, 0))
                ;

            float iu = 1.0f / su;
            float iv = 1.0f / sv;
            int empty = 1;
            for (; p != out; p += 3) {
                float x0 = (p[0].u * iu - 0.5f) * 2.0f;
                float y0 = (p[0].v * iv - 0.5f) * 2.0f;
                float x1 = (p[1].u * iu - 0.5f) * 2.0f;
                float y1 = (p[1].v * iv - 0.5f) * 2.0f;
                float x2 = (p[2].u * iu - 0.5f) * 2.0f;
                float y2 = (p[2].v * iv - 0.5f) * 2.0f;
                if (!TouchesUnitSquare(x0, y0, x1, y1, x2, y2))
                    continue;
                block[slot] = (int)(depth * 1000.0f);
                empty = 0;
                tris[base + 0].pos = p[0].pos;
                tris[base + 1].pos = p[1].pos;
                tris[base + 2].pos = p[2].pos;
                tris[base + 0].u = p[0].u;
                tris[base + 0].v = p[0].v;
                tris[base + 1].u = p[1].u;
                tris[base + 1].v = p[1].v;
                tris[base + 2].u = p[2].u;
                tris[base + 2].v = p[2].v;
                tris[base + 0].col = p[0].col;
                tris[base + 1].col = p[1].col;
                tris[base + 2].col = p[2].col;
                slot = func_00142F08(block);
                base = slot * 3;
            }
            delete[] list;
            if (empty)
                func_0014F4B8(block, slot);
        }
    }
    return 0;
}
