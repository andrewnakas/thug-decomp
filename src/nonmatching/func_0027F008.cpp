/* fuzzy: 57.4 */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

typedef int qword __attribute__((mode(TI)));
union Vec_0027F008 {
    qword q;
    struct {
        float x, y, z, w;
    };
    Vec_0027F008() {}
    Vec_0027F008(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
    void operator+=(const Vec_0027F008& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
    }
    void operator*=(float k)
    {
        x *= k;
        y *= k;
        z *= k;
        w *= k;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

inline Vec_0027F008 operator*(const Vec_0027F008& a, float k) { return Vec_0027F008(a.x * k, a.y * k, a.z * k, a.w * k); }
inline Vec_0027F008 operator+(const Vec_0027F008& a, const Vec_0027F008& b)
{
    return Vec_0027F008(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline Vec_0027F008 operator-(const Vec_0027F008& a, const Vec_0027F008& b)
{
    return Vec_0027F008(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Mat_0027F008 {
    Vec_0027F008 row[4];
};

extern "C" void func_00323318(Mat_0027F008* dst, const Mat_0027F008* a, const Mat_0027F008* b);
extern "C" Mat_0027F008* func_00100928(Mat_0027F008* m, float angle);

inline Mat_0027F008 operator*(const Mat_0027F008& a, const Mat_0027F008& b)
{
    Mat_0027F008 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

struct Body_0027F008 {
    char pad0[0x50];
    Vec_0027F008 m_pos;
    Vec_0027F008 m_oldPos;
    Mat_0027F008 m_mat;
    Vec_0027F008 m_vel;
    char padC0[0x31C - 0xC0];
    int m_31C;
};

struct State_0027F008 {
    char pad0[0x34];
    int m_34;
};

struct Obj_0027F008 {
    char pad0[0xC];
    Body_0027F008* m_body;
    char pad10[0x20 - 0x10];
    Mat_0027F008 m_mat;
    char pad60[0x11C - 0x60];
    int m_11C;
    char pad120[0x150 - 0x120];
    Vec_0027F008 m_150;
    char pad160[0x270 - 0x160];
    Vec_0027F008 m_270;
    Vec_0027F008 m_280;
    char pad290[0x59C - 0x290];
    void* m_59C;
    char pad5A0[0x5B0 - 0x5A0];
    State_0027F008* m_5B0;
    void Snap(Vec_0027F008* normal);
};

extern "C" void func_001848F0(Body_0027F008* body, unsigned int event, int a);
extern "C" float func_002032A0(unsigned int name, int def);
extern "C" float func_00203D40(Body_0027F008* body, unsigned int name);
extern "C" void func_00270DD8(void* sound, int id, float pitch);
extern "C" int func_00283660(Obj_0027F008* self);
extern "C" float func_00284AA8(Obj_0027F008* self, Vec_0027F008* dir, float k, float* angle);
extern "C" bool func_0028E1C0(Obj_0027F008* self, int flags, int a);
extern "C" int func_003233B8(Vec_0027F008* d, Vec_0027F008* s);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

void Obj_0027F008::Snap(Vec_0027F008* normal)
{
    if (func_00283660(this))
        return;

    Vec_0027F008 dir = m_body->m_pos - m_body->m_oldPos;
    Vec_0027F008 moved = dir;
    func_003233B8(&dir, &dir);

    Body_0027F008* body = m_body;
    Vec_0027F008 up = body->m_mat.row[1] * func_002032A0(0xD4205C9B, 0);

    float angle;
    float turn = func_00284AA8(this, normal, 1.0f, &angle);
    float absTurn = fabsf(turn);
    float limit = func_002032A0(0x1483FD01, 0) * 0.017453294f;
    if (limit < absTurn) {
        Vec_0027F008& vel = m_body->m_vel;
        float scale = 1.0f - (absTurn - limit) / (1.5707964f - limit);
        float speed = vel.Length();
        vel *= scale;
        if (func_002032A0(0xBE0A58A0, 0) < speed) {
            int side = m_5B0->m_34;
            bool same;
            if (turn < 0.0f)
                same = side == 1;
            else
                same = side == 0;
            if (same)
                func_001848F0(m_body, 0x756A7535, 0);
            else
                func_001848F0(m_body, 0xB4101D70, 0);
            func_00270DD8(m_59C, m_11C, speed / func_00203D40(m_body, 0xCC5F87AA));
        }
    }

    m_body->m_pos = m_150 - up;
    Vec_0027F008 push = *normal * 6.0f;
    m_body->m_pos += push;

    float dist = moved.Length();
    dir = m_body->m_vel;
    func_003233B8(&dir, &dir);
    Vec_0027F008 step = dir * dist;

    m_270 = m_body->m_pos + up;
    m_270 += up;

    Vec_0027F008 base = m_body->m_pos + up;
    Vec_0027F008 ahead = base + step;
    Vec_0027F008 look = dir * func_002032A0(0x20102726, 0);
    m_280 = ahead + look;

    if (!func_0028E1C0(this, 0x10, 0))
        return;
    body = m_body;
    if (!body->m_31C)
        return;

    float a = 3.141593f - angle;
    float s = func_00341068(a);
    float c = func_00340F60(a);
    float vx = body->m_vel.x;
    float vz = body->m_vel.z;
    body->m_vel.x = c * vx + s * vz;
    body->m_vel.z = -s * vx + c * vz;

    body = m_body;
    body->m_mat = body->m_mat * *func_00100928((Mat_0027F008*)0x70003FC0, 3.141593f - angle);
    m_mat = m_body->m_mat;
    m_body->m_vel *= 0.5f;
    if (func_002032A0(0xBE0A58A0, 0) < dist)
        func_001848F0(m_body, 0xB4101D70, 0);
}
