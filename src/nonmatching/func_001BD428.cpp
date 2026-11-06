/* fuzzy: 79.3 */
struct Vec_001BD428 {
    float x, y, z, w;
    Vec_001BD428() {}
    Vec_001BD428(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001BD428 operator+(const Vec_001BD428& a, const Vec_001BD428& b)
{
    return Vec_001BD428(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Pos_001BD428 {
    char pad[0x50];
    Vec_001BD428 m_pos;
};

struct Shape_001BD428 {
    char pad[0xE0];
    int m_active;
    char padE4[0xC];
    Vec_001BD428 m_points[3];
};

extern void* D_00392068;
extern "C" int func_001A9E60(void* p);
extern "C" int func_002A19A8(void* p);
extern "C" void func_001F0210(unsigned int type, void* s, Pos_001BD428* target, int b, int c);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00184950(Pos_001BD428* o);
extern "C" Shape_001BD428* func_00142290(int id);
extern "C" void func_001423C0(int id, int i, Vec_001BD428* v);

struct C_001BD428 {
    char pad[0xC];
    Pos_001BD428* mC;
    char pad10[0xC];
    unsigned int m1C;
    int m20;
    void* m24;
    unsigned int m28;
    unsigned int m2C;
    void Update();
};

void C_001BD428::Update()
{
    void* g = D_00392068;
    if (m24 && func_001A9E60(m24)) {
        if (!func_002A19A8(g))
            return;
        if (!m2C)
            return;
    }
    if (m1C)
        func_001F0210(m1C, 0, mC, 0, 0);
    if (m2C && m2C < func_0010FC30() - m28) {
        func_00184950(mC);
        return;
    }
    if (func_00142290(m20)->m_active) {
        for (int i = 0; i < 3; i++) {
            Vec_001BD428 v = func_00142290(m20)->m_points[i] + mC->m_pos;
            func_001423C0(m20, i, &v);
        }
    }
}
