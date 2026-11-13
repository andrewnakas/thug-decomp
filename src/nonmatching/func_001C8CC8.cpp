/* fuzzy: 99.0 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001C8CC8 {
    union {
        struct { float x, y, z, w; };
        float c[4];
        qword q;
    };
    const float& operator[](int i) const { return c[i]; }
    Vec_001C8CC8() {}
    Vec_001C8CC8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void operator+=(const Vec_001C8CC8& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
    }
};

static inline Vec_001C8CC8 operator+(const Vec_001C8CC8& a, const Vec_001C8CC8& b)
{
    return Vec_001C8CC8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_001C8CC8 operator*(const Vec_001C8CC8& a, float s)
{
    return Vec_001C8CC8(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

struct Node_001C8CC8 {
    char pad0[0x50];
    Node_001C8CC8* m50;
};

struct State_001C8CC8 {
    Vec_001C8CC8 m_pos;
    Vec_001C8CC8 m_dir;
    float m20;
    char pad24[0xC];
    Node_001C8CC8* m_node;
};

struct Coll_001C8CC8 {
    Vec_001C8CC8 start;
    Vec_001C8CC8 end;
};

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" int func_002093E8(Coll_001C8CC8* c, int a, int b);

static inline float GetF_001C8CC8(unsigned int id)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), id, &v, 1);
    return v;
}

struct Skater_001C8CC8 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x10];
    Vec_001C8CC8 m30;
    char pad40[0xA24 - 0x40];
    void* mA24;
    bool CheckRail(Coll_001C8CC8* feeler, const Vec_001C8CC8* pos, State_001C8CC8* st);
};

extern "C" void func_0026B1B0(Vec_001C8CC8* out, void* rails, Node_001C8CC8* node);
extern "C" bool func_001C90A0(Skater_001C8CC8* self, Coll_001C8CC8* feeler, State_001C8CC8* st, Vec_001C8CC8* side);
extern "C" int func_001C9C38(Skater_001C8CC8* self, Vec_001C8CC8* dir, Vec_001C8CC8* pos, int fwd, Vec_001C8CC8* side, float t, Vec_001C8CC8* d, Node_001C8CC8* a, Node_001C8CC8* b);
extern "C" float func_001CB6F8(Skater_001C8CC8* self);

bool Skater_001C8CC8::CheckRail(Coll_001C8CC8* feeler, const Vec_001C8CC8* pos, State_001C8CC8* st)
{
    st->m_pos = *pos;
    Vec_001C8CC8* dir = &st->m_dir;
    Vec_001C8CC8 side(-st->m_dir.z, 0.0f, st->m_dir.x, 1.0f);
    Vec_001C8CC8 rail;
    {
        Vec_001C8CC8 a;
        func_0026B1B0(&a, mA24, st->m_node);
        Vec_001C8CC8 b;
        func_0026B1B0(&b, mA24, st->m_node->m50);
        rail.x = a.x - b.x;
        rail.y = a.y - b.y;
        rail.z = a.z - b.z;
        rail.w = a.w - b.w;
    }
    if (!func_001C90A0(this, feeler, st, &side))
        return false;
    {
        Vec_001C8CC8 neg(-side.x, -side.y, -side.z, -side.w);
        bool miss = !func_001C90A0(this, feeler, st, &neg);
        if (miss)
            return false;
    }
    st->m_pos.y -= GetF_001C8CC8(0xA8C13E74);
    st->m_pos += st->m_dir * GetF_001C8CC8(0x262A9467);
    {
        Vec_001C8CC8 d = rail;
        if (func_001C9C38(this, dir, &st->m_pos, 1, &side, st->m20, &d, st->m_node, st->m_node->m50))
            return false;
    }
    {
        Vec_001C8CC8 d = rail;
        if (func_001C9C38(this, dir, &st->m_pos, 0, &side, st->m20, &d, st->m_node, st->m_node->m50))
            return false;
    }
    Vec_001C8CC8 target = st->m_pos + st->m_dir * GetF_001C8CC8(0xC3263E6E);
    target.y += func_001CB6F8(this);
    feeler->start = m30;
    feeler->end = target;
    if (func_002093E8(feeler, 1, 0)) {
        if (m1C)
            return false;
    } else
        return true;
    feeler->end = m30;
    feeler->end.y += GetF_001C8CC8(0xA85EC070);
    if (func_002093E8(feeler, 1, 0))
        return false;
    feeler->start = feeler->end;
    feeler->end = target;
    if (!func_002093E8(feeler, 1, 0))
        return true;
    return false;
}
