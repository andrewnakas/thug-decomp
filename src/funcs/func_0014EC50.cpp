typedef int qword __attribute__((mode(TI)));

struct Vec_0014EC50 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0014EC50() {}
    Vec_0014EC50(float ax, float ay, float az) : x(ax), y(ay), z(az), w(1.0f) {}
    float LengthSqr() const { return x * x + y * y + z * z; }
};

static inline Vec_0014EC50 operator-(const Vec_0014EC50& a, const Vec_0014EC50& b)
{
    return Vec_0014EC50(a.x - b.x, a.y - b.y, a.z - b.z);
}

static inline Vec_0014EC50 Cross(const Vec_0014EC50& a, const Vec_0014EC50& b)
{
    return Vec_0014EC50(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}

static inline float Mid(float a, float b)
{
    return a + (b - a) * 0.5f;
}

struct Vert_0014EC50 {
    Vec_0014EC50 pos;
    unsigned char col[4];
    float uv[2];
};

struct Queue_0014EC50 {
    int count;
    int size;
    int m8;
};

extern Queue_0014EC50 D_003C3DC0;
extern "C" void func_00142FE0(Queue_0014EC50* q, Vert_0014EC50* v);
extern "C" void func_00142F98(Queue_0014EC50* q, Vert_0014EC50* v);
extern "C" void* func_00331404(void* d, const void* s, int n);

extern "C" int func_0014EC50(Vert_0014EC50** out, float thr)
{
    if (!D_003C3DC0.count) return 0;
    Vert_0014EC50 v0, v1, v2;
    func_00142FE0(&D_003C3DC0, &v2);
    func_00142FE0(&D_003C3DC0, &v1);
    func_00142FE0(&D_003C3DC0, &v0);
    Vec_0014EC50 e1 = v1.pos - v0.pos;
    Vec_0014EC50 e2 = v2.pos - v0.pos;
    Vec_0014EC50 n = Cross(e1, e2);
    if (thr < n.LengthSqr()) {
        int size = D_003C3DC0.size;
        Vert_0014EC50 m0, m1, m2;
        func_00331404(&m0, &v0, size);
        func_00331404(&m1, &v1, size);
        func_00331404(&m2, &v2, size);
        m0.pos.x = v0.pos.x + (v1.pos.x - v0.pos.x) * 0.5f;
        m0.pos.y = v0.pos.y + (v1.pos.y - v0.pos.y) * 0.5f;
        m0.pos.z = v0.pos.z + (v1.pos.z - v0.pos.z) * 0.5f;
        m1.pos.x = v1.pos.x + (v2.pos.x - v1.pos.x) * 0.5f;
        m1.pos.y = v1.pos.y + (v2.pos.y - v1.pos.y) * 0.5f;
        m1.pos.z = v1.pos.z + (v2.pos.z - v1.pos.z) * 0.5f;
        m2.pos.x = v2.pos.x + (v0.pos.x - v2.pos.x) * 0.5f;
        m2.pos.y = v2.pos.y + (v0.pos.y - v2.pos.y) * 0.5f;
        m2.pos.z = v2.pos.z + (v0.pos.z - v2.pos.z) * 0.5f;
        unsigned char* c0 = m0.col;
        unsigned char* c1 = m1.col;
        unsigned char* c2 = m2.col;
        for (int i = 0; i < 4; i++) {
            c0[i] = v0.col[i] + (int)((v1.col[i] - v0.col[i]) * 0.5f);
            c1[i] = v1.col[i] + (int)((v2.col[i] - v1.col[i]) * 0.5f);
            c2[i] = v2.col[i] + (int)((v0.col[i] - v2.col[i]) * 0.5f);
        }
        const float* t0 = v0.uv;
        const float* t1 = v1.uv;
        const float* t2 = v2.uv;
        for (int j = 0; j < 2; j++) {
            m0.uv[j] = Mid(t0[j], t1[j]);
            m1.uv[j] = Mid(t1[j], t2[j]);
            m2.uv[j] = Mid(t2[j], t0[j]);
        }
        func_00142F98(&D_003C3DC0, &v0);
        func_00142F98(&D_003C3DC0, &m0);
        func_00142F98(&D_003C3DC0, &m2);
        func_00142F98(&D_003C3DC0, &m0);
        func_00142F98(&D_003C3DC0, &v1);
        func_00142F98(&D_003C3DC0, &m1);
        func_00142F98(&D_003C3DC0, &m0);
        func_00142F98(&D_003C3DC0, &m1);
        func_00142F98(&D_003C3DC0, &m2);
        func_00142F98(&D_003C3DC0, &m2);
        func_00142F98(&D_003C3DC0, &m1);
        func_00142F98(&D_003C3DC0, &v2);
    } else {
        int size = D_003C3DC0.size;
        func_00331404(*out, &v0, size);
        (*out)++;
        func_00331404(*out, &v1, size);
        (*out)++;
        func_00331404(*out, &v2, size);
        (*out)++;
    }
    return 1;
}
