extern "C" float sqrtf(float);

typedef int qword_00150F60 __attribute__((mode(TI)));

struct V_00150F60 {
    union {
        qword_00150F60 q;
        struct {
            float x, y, z, w;
        };
    };
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V_00150F60& operator=(const V_00150F60& o)
    {
        q = o.q;
        return *this;
    }
};

struct Col_00150F60 {
    unsigned char r, g, b, a;
};

struct Vert_00150F60 {
    V_00150F60 pos;
    Col_00150F60 col;
    float u, v;
};

struct Sph_00150F60 {
    float x, y, z, r;
    Sph_00150F60(const Sph_00150F60& o);
};

struct Mat_00150F60 {
    float m[16];
    void Ident()
    {
        m[0] = 1.0f;
        m[1] = 0.0f;
        m[2] = 0.0f;
        m[3] = 0.0f;
        m[4] = 0.0f;
        m[5] = 1.0f;
        m[6] = 0.0f;
        m[7] = 0.0f;
        m[8] = 0.0f;
        m[9] = 0.0f;
        m[10] = 1.0f;
        m[11] = 0.0f;
        m[12] = 0.0f;
        m[13] = 0.0f;
        m[14] = 0.0f;
        m[15] = 1.0f;
    }
};

struct Queue_00150F60 {
    int count;
    int size;
    int m8;
};

struct Heap_00150F60 {
    char pad[0xD8];
    int mD8;
};

struct Fx_00150F60 {
    V_00150F60* m0;
    V_00150F60* m4;
    char pad8[0x4];
    Mat_00150F60* mC;
    char pad10[0x1C];
    Vert_00150F60* m2C;
};

struct Obj_00150F60 {
    char pad[0x20];
    void* m20;
    void Build();
};

struct IPos_00150F60 {
    int x, y, z, flags;
};

struct IUV_00150F60 {
    int u, v;
};

extern Heap_00150F60* D_00388A70;
extern void* D_0038A63C;
extern float D_0038A640;
extern float D_0038A644;
extern float D_0038A648;
extern V_00150F60 D_003C3DB0;
extern Queue_00150F60 D_003C3DC0;

extern "C" void* func_00131E48();
extern "C" void func_00134848(Col_00150F60* c, void* a);
extern "C" void func_00150DE0(void* n, void** out, int* count);
extern "C" int func_00170558(void* o);
extern "C" void* func_00170650(void* o);
extern "C" int func_00161860(void* mesh);
extern "C" int func_00161C98(void* mesh);
extern "C" Sph_00150F60 func_00172078(void* o);
extern "C" void func_0010A950(void* heap, int v);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00161D50(void* mesh, IPos_00150F60* out);
extern "C" void func_00162040(void* mesh, IUV_00150F60* out);
extern "C" void func_00162000(void* mesh, Col_00150F60* out);
extern "C" void func_00142F98(Queue_00150F60* q, const void* v);
extern "C" int func_00150E78(const Vert_00150F60* a, const Vert_00150F60* b, const Vert_00150F60* c, float t);
extern "C" int func_0010BE08();
extern "C" int func_0014EAC0(int n);
extern "C" Vert_00150F60* func_00143018(Queue_00150F60* q, int i);
extern "C" void func_00142F88(Queue_00150F60* q);
extern "C" Fx_00150F60* func_0014E988(void* mem, int n, void* o);
extern "C" void func_001521F0(void* table, int* key, Fx_00150F60* value);
extern "C" int func_0014EC50(float t, Vert_00150F60** out, void* o);
extern "C" int func_00335048();
extern "C" void func_003233B8(V_00150F60* d, V_00150F60* s);
extern "C" void func_00100700(Mat_00150F60* m, V_00150F60* axis, float a);
extern "C" void func_00323318(Mat_00150F60* d, Mat_00150F60* a, Mat_00150F60* b);

static inline void Put(void* table, const int& key, Fx_00150F60* value)
{
    func_001521F0(table, (int*)&key, value);
}

static inline V_00150F60* Dir()
{
    return &D_003C3DB0;
}

static inline void Spin(Mat_00150F60* m, V_00150F60* axis, float a)
{
    Mat_00150F60 rot;
    func_00100700(&rot, axis, a);
    func_00323318(m, &rot, m);
}

static inline float Frac(float x)
{
    return x * 4.656613e-10f;
}

static inline float Rnd()
{
    return (float)func_00335048() * 2.0f * 4.656613e-10f + -1.0f;
}

static inline void Mod(Col_00150F60& c, const Col_00150F60& b)
{
    int t;
    t = c.r * b.r;
    c.r = t >> 7;
    t = c.g * b.g;
    c.g = t >> 7;
    t = c.b * b.b;
    c.b = t >> 7;
    t = c.a * b.a;
    c.a = t >> 7;
}

void Obj_00150F60::Build()
{
    Col_00150F60 base;
    void* list[12];
    int count;
    void* root = m20;
    func_00134848(&base, func_00131E48());
    count = 0;
    func_00150DE0(root, list, &count);
    for (int i = 0; i < count; i++) {
        void* obj = list[i];
        if (func_00170558(obj)) {
            continue;
        }
        void* mesh = func_00170650(obj);
        int n = func_00161860(mesh);
        if (n < 3) {
            continue;
        }
        int colBytes = n * 4;
        int centered = func_00161C98(mesh) == 0x10;
        Sph_00150F60 s = func_00172078(obj);
        D_003C3DC0.size = 0x20;
        func_0010A950(D_00388A70, D_00388A70->mD8);
        IPos_00150F60* pos = (IPos_00150F60*)func_0010A638(D_00388A70, n * 16, 1, 0);
        IUV_00150F60* uv = (IUV_00150F60*)func_0010A638(D_00388A70, n * 8, 1, 0);
        Col_00150F60* col = (Col_00150F60*)func_0010A638(D_00388A70, colBytes, 1, 0);
        func_0010A9B0(D_00388A70);
        func_00161D50(mesh, pos);
        func_00162040(mesh, uv);
        func_00162000(mesh, col);
        Vert_00150F60 v0;
        Vert_00150F60 v1;
        Vert_00150F60 v2;
        if (centered) {
            v0.pos.x = pos[0].x * 0.0625f + s.x;
            v0.pos.y = pos[0].y * 0.0625f + s.y;
            v0.pos.z = pos[0].z * 0.0625f + s.z;
            v0.pos.w = 1.0f;
            v1.pos.x = pos[1].x * 0.0625f + s.x;
            v1.pos.y = pos[1].y * 0.0625f + s.y;
            v1.pos.z = pos[1].z * 0.0625f + s.z;
            v1.pos.w = 1.0f;
        } else {
            v0.pos.x = pos[0].x * 0.0625f;
            v0.pos.y = pos[0].y * 0.0625f;
            v0.pos.z = pos[0].z * 0.0625f;
            v0.pos.w = 1.0f;
            v1.pos.x = pos[1].x * 0.0625f;
            v1.pos.y = pos[1].y * 0.0625f;
            v1.pos.z = pos[1].z * 0.0625f;
            v1.pos.w = 1.0f;
        }
        v0.u = uv[0].u * 0.00024414062f;
        v0.v = uv[0].v * 0.00024414062f;
        v1.u = uv[1].u * 0.00024414062f;
        v1.v = uv[1].v * 0.00024414062f;
        v0.col = col[0];
        Mod(v0.col, base);
        v1.col = col[1];
        Mod(v1.col, base);
        int tris = 0;
        int sub = 0;
        for (int k = 2; k < n; k++) {
            if (centered) {
                v2.pos.x = pos[k].x * 0.0625f + s.x;
                v2.pos.y = pos[k].y * 0.0625f + s.y;
                v2.pos.z = pos[k].z * 0.0625f + s.z;
                v2.pos.w = 1.0f;
            } else {
                v2.pos.x = pos[k].x * 0.0625f;
                v2.pos.y = pos[k].y * 0.0625f;
                v2.pos.z = pos[k].z * 0.0625f;
                v2.pos.w = 1.0f;
            }
            v2.u = uv[k].u * 0.00024414062f;
            v2.v = uv[k].v * 0.00024414062f;
            v2.col = col[k];
            Mod(v2.col, base);
            if (!(pos[k].flags & 0x8000)) {
                func_00142F98(&D_003C3DC0, &v0);
                sub++;
                func_00142F98(&D_003C3DC0, &v1);
                tris++;
                func_00142F98(&D_003C3DC0, &v2);
                sub += func_00150E78(&v0, &v1, &v2, D_0038A640);
            }
            v0 = v1;
            v1 = v2;
        }
        if (pos) {
            func_0010A8D8(D_00388A70, pos);
        }
        if (uv) {
            func_0010A8D8(D_00388A70, uv);
        }
        if (col) {
            func_0010A8D8(D_00388A70, col);
        }
        if (!sub) {
            continue;
        }
        float thr = D_0038A640;
        int avail = func_0010BE08();
        int need = func_0014EAC0(sub) * 3 / 2;
        if (avail < need) {
            int r = (int)((float)need / (float)avail + 0.99f);
            r = (r + 3) & ~3;
            thr *= (float)(r * r);
            sub = tris;
            for (int t = 0; t < tris; t++) {
                Vert_00150F60* a = func_00143018(&D_003C3DC0, t * 3);
                Vert_00150F60* b = func_00143018(&D_003C3DC0, t * 3 + 1);
                Vert_00150F60* c = func_00143018(&D_003C3DC0, t * 3 + 2);
                sub += func_00150E78(a, b, c, thr);
            }
            need = func_0014EAC0(sub) * 3 / 2;
            if (avail < need) {
                func_00142F88(&D_003C3DC0);
                continue;
            }
        }
        int j = 0;
        Fx_00150F60* fx = func_0014E988(func_0010A638(D_00388A70, 0x38, 1, 0), sub, obj);
        V_00150F60 center;
        V_00150F60 dir;
        float k = -D_0038A648;
        Vert_00150F60* cur = fx->m2C;
        V_00150F60* d = Dir();
        float len = d->Length();
        center.x = d->x * k + s.x;
        center.y = d->y * k + s.y;
        center.z = d->z * k + s.z;
        center.w = 1.0f;
        Put(D_0038A63C, (int)fx, fx);
        Vert_00150F60* t = cur;
        while (func_0014EC50(thr, &cur, obj)) {
        }
        for (; t < cur; t += 3, j++) {
            Vert_00150F60* a = t;
            Vert_00150F60* b = t + 1;
            Vert_00150F60* c3 = t + 2;
            fx->m0[j].x = (a->pos.x + b->pos.x + c3->pos.x) * 0.33333334f;
            fx->m0[j].y = (a->pos.y + b->pos.y + c3->pos.y) * 0.33333334f;
            fx->m0[j].z = (a->pos.z + b->pos.z + c3->pos.z) * 0.33333334f;
            fx->m0[j].w = 1.0f;
            float rnd = (float)func_00335048();
            dir.Set(fx->m0[j].x - center.x, fx->m0[j].y - center.y, fx->m0[j].z - center.z, fx->m0[j].w - center.w);
            float speed = len + Frac(len) * (D_0038A644 * rnd);
            float d = dir.Length();
            if (d > 0.0f) {
                float f = speed / d;
                dir.x *= f;
                dir.y *= f;
                dir.z *= f;
            }
            fx->m4[j] = dir;
            dir.Set(Rnd(), Rnd(), Rnd(), 0.0f);
            func_003233B8(&dir, &dir);
            fx->mC[j].Ident();
            Spin(&fx->mC[j], &dir, (float)func_00335048() * 4.656613e-11f);
        }
    }
}
