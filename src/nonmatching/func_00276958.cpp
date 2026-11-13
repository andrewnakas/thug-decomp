/* fuzzy: 83.0 */
/* sym: __14Slerp_00276958 = 0x00102FD0 */
typedef int qword_00276958 __attribute__((mode(TI)));

union Vec_00276958 {
    qword_00276958 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_00276958() {}
    Vec_00276958(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_00276958& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};

static inline Vec_00276958 operator-(const Vec_00276958& a, const Vec_00276958& b)
{
    return Vec_00276958(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}
static inline Vec_00276958 operator+(const Vec_00276958& a, const Vec_00276958& b)
{
    return Vec_00276958(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_00276958 operator*(const Vec_00276958& a, float k)
{
    return Vec_00276958(a[0] * k, a[1] * k, a[2] * k, a[3] * k);
}
static inline float Length_00276958(const Vec_00276958& v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

struct Mat_00276958 {
    Vec_00276958 r0;
    Vec_00276958 r1;
    Vec_00276958 r2;
    Vec_00276958 r3;
    const Vec_00276958& operator[](int i) const { return (&r0)[i]; }
    Mat_00276958& operator=(const Mat_00276958& o)
    {
        r0 = o[0];
        r1 = o[1];
        r2 = o[2];
        r3 = o[3];
        return *this;
    }
};

/* A received network snapshot of a remote skater (0x90 bytes, ring of 20). */
struct Snap_00276958 {
    char pad0[0x10];
    Mat_00276958 mat;
    Vec_00276958 pos;
    char pad60[0x10];
    unsigned int mask;
    int m74;
    int m78;
    signed char m7C;
    signed char m7D;
    signed char m7E;
    char pad7F[5];
    int m84;
    char pad88[8];
};

struct Ring_00276958 {
    char pad0[0x1C];
    int count;
    Snap_00276958 snaps[20];
};

struct Model_00276958 {
    char pad0[0x18];
    unsigned short id;
    char pad1A[0x50 - 0x1A];
    Vec_00276958 pos;
    char pad60[0x70 - 0x60];
    Mat_00276958 mat;
    Vec_00276958 vel;
    Mat_00276958 matC0;
};

struct Conn_00276958 {
    unsigned int time;
};

extern "C" unsigned int func_0010FC30();

struct Flag_00276958 {
    int m0;
    int value;
    unsigned int time;
    void Set(int v)
    {
        if (value != v) {
            value = v;
            time = func_0010FC30();
        }
    }
};

struct State_00276958 {
    char pad0[0x1C];
    int m1C;
    int m20;
    Flag_00276958 flags[23];
    int m138;
    int m13C;
    Vec_00276958 m140;
    char pad150[0x180 - 0x150];
    int m180;
};

/* Quaternion interpolator built from two matrices (func_00103000 / func_00103930). */
struct Slerp_00276958 {
    char pad[0xA0];
    Slerp_00276958();
};

struct Remote_00276958 {
    char pad0[0xC];
    Model_00276958* model;
    char pad10[0x1C - 0x10];
    unsigned int startTime;
    unsigned int playTime;
    char pad24[4];
    int index;
    char pad2C[4];
    Vec_00276958 lastPos;
    Vec_00276958 prevPos;
    char pad50[0x160 - 0x50];
    Vec_00276958 hist[20];
    int histCount;
    int GetHistCount() { return histCount; }
    float dt;
    char pad2A8[4];
    Ring_00276958* ring;
    char pad2B0[0x2B8 - 0x2B0];
    State_00276958* state;
    void* comp;
    void Update();
};

extern void* D_00392068;
extern int D_00388830;
extern int D_00391870;
extern char D_00391868[];

extern "C" float sqrtf(float);
static inline bool Late_00276958(unsigned int ms, unsigned int now, unsigned int t)
{
    return now - t > ms;
}
extern "C" Conn_00276958* func_002A39E0(void* mgr, int i);
extern "C" unsigned int func_00279F48(Snap_00276958* s);
extern "C" int func_0033EBE0(float f);
extern "C" void func_00186398(Model_00276958* m, int b);
extern "C" int func_00206A00(Model_00276958* m);
extern "C" void func_002069C0(Model_00276958* m);
extern "C" void func_001F0370(char* name, int a, Model_00276958* m, int c);
extern "C" void* func_002A52F0(void* mgr, int id);
extern "C" void func_00277740(Remote_00276958* self);
extern "C" int func_002B2280(void* p);
extern "C" void func_002B2180(void* p);
extern "C" void func_00206920(Model_00276958* m);
extern "C" void func_00103000(Slerp_00276958* s, Mat_00276958* a, Mat_00276958* b);
extern "C" void func_00103930(Slerp_00276958* s, Mat_00276958* out, float t);
extern "C" void func_00290890(void* comp, int v);

/* Plays back the remote skater from its snapshot ring: keeps a playback clock behind the newest
   snapshot, interpolates position and orientation between the two snapshots around it, smooths
   the velocity over the last 20 frames and copies the snapshot's state flags. */
void Remote_00276958::Update()
{
    void* mgr = D_00392068;
    Snap_00276958* snaps = ring->snaps;
    Conn_00276958* conn = func_002A39E0(mgr, 0);
    if (!conn)
        return;
    if (ring->count < 20)
        return;
    if (!startTime) {
        int i = (ring->count - 1) % 20;
        startTime = conn->time;
        Snap_00276958* s = &snaps[i];
        unsigned int t = func_00279F48(s);
        playTime = t - func_0033EBE0(1000.0f / (float)D_00388830);
        index = i;
        model->mat = s->mat;
        model->matC0 = s->mat;
        model->pos = s->pos;
        func_00186398(model, 1);
        model->vel.Set(0.0f, 0.0f, 0.0f, 1.0f);
        if (func_00206A00(model))
            return;
        func_002069C0(model);
        func_001F0370(D_00391868, 0, model, 0);
        func_002A52F0(mgr, model->id);
        func_00277740(this);
        return;
    }

    Vec_00276958 d;
    Slerp_00276958 slerp;
    Mat_00276958 out;
    Slerp_00276958* sl = &slerp;
    void* owner = func_002A52F0(mgr, model->id);
    if (!func_002B2280(owner))
        func_002B2180(owner);
    int next = ring->count % 20;
    unsigned int now = playTime + (conn->time - startTime);
    Snap_00276958* newest = &snaps[(ring->count - 1) % 20];
    if (func_00279F48(newest) < now) {
        if (Late_00276958(1000, now, func_00279F48(newest)))
            playTime -= now - func_00279F48(newest);
        else
            playTime -= 1000 / (unsigned int)D_00388830;
        now = playTime + (conn->time - startTime);
    }

    int j = next;
    do {
        if (func_00279F48(&snaps[j]) >= now) {
            index = j;
            int lag = next + 20;
            lag -= j;
            D_00391870 = lag % 20;
            if (D_00391870 >= 10)
                playTime += 1000 / (unsigned int)D_00388830 * 10;
            else if (D_00391870 == 0)
                func_00206920(model);
            Snap_00276958* cur = &snaps[j];
            int p = (j + 19) % 20;
            Snap_00276958* prev = &snaps[p];
            now -= func_00279F48(prev);
            int span = func_00279F48(cur) - func_00279F48(prev);
            float t = (float)(int)now / (float)span;
            d = cur->pos - prev->pos;
            prevPos = lastPos;
            Mat_00276958 a;
            Mat_00276958 b;
            Vec_00276958 r;
            r = cur->mat[2] - prev->mat[2];
            if (Length_00276958(r) > 0.75f) {
                model->mat = prev->mat;
                model->matC0 = prev->mat;
            } else {
                a = prev->mat;
                b = cur->mat;
                func_00103000(sl, &a, &b);
                func_00103930(sl, &out, t);
                model->mat = out;
                model->matC0 = out;
            }
            if (Length_00276958(d) > 600.0f) {
                model->pos = snaps[j].pos;
                model->vel = Vec_00276958(0.0f, 0.0f, 0.0f, 1.0f);
                func_00186398(model, 1);
            } else {
                Vec_00276958 sum;
                model->pos = snaps[p].pos + d * t;
                model->vel = (model->pos - prevPos) * (1.0f / dt);
                hist[histCount % 20] = model->vel;
                sum = r; /* the game reads sum from the stack slot that still holds r */
                int k;
                for (k = 0; k < 20 && k < GetHistCount(); k++)
                    sum += hist[k];
                if (k > 0)
                    model->vel = sum * (1.0f / (float)k);
            }
            lastPos = model->pos;
            Snap_00276958* s = &snaps[j];
            state->m1C = s->m78;
            state->m138 = s->m7C != 0;
            state->m13C = s->m84;
            state->m20 = s->m7D != 0;
            state->m180 = s->m7E != 0;
            func_00290890(comp, s->m74);
            for (int b = 0; b < 23; b++)
                state->flags[b].Set((snaps[j].mask & (1 << b)) != 0);
            if (state->flags[11].value)
                state->m140 = model->vel;
            else
                state->m140.Set(0.0f, 0.0f, 0.0f, 1.0f);
            return;
        }
        j = (j + 1) % 20;
    } while (j != next);
}
