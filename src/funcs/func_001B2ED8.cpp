typedef int qword __attribute__((mode(TI)));
union Vec_001B2ED8 { qword q; float c[4];
    Vec_001B2ED8& operator=(const Vec_001B2ED8& o) { q = o.q; return *this; }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};
static inline void Sub_001B2ED8(Vec_001B2ED8& r, const Vec_001B2ED8& a, const Vec_001B2ED8& b)
{
    r[0] = a[0] - b[0]; r[1] = a[1] - b[1]; r[2] = a[2] - b[2]; r[3] = a[3] - b[3];
}
static inline void Cross_001B2ED8(Vec_001B2ED8& r, const Vec_001B2ED8& a, const Vec_001B2ED8& b)
{
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
    r[3] = 0.0f;
}
struct Mat_001B2ED8 { Vec_001B2ED8 r[4];
    Mat_001B2ED8& operator=(const Mat_001B2ED8& o) { r[0] = o.r[0]; r[1] = o.r[1]; r[2] = o.r[2]; r[3] = o.r[3]; return *this; } };
struct Node_001B2ED8 { char pad[0x50]; Vec_001B2ED8 m_pos; char pad2[0x60]; Mat_001B2ED8 m_rot; };
extern "C" float func_00101BC8(Vec_001B2ED8* a, Vec_001B2ED8* b);
extern "C" void func_001B3138(void* self, float a, float b);
struct Obj_001B2ED8 { char pad[0xC]; Node_001B2ED8* m_C; void Face(Vec_001B2ED8* target, float f); };
void Obj_001B2ED8::Face(Vec_001B2ED8* target, float f)
{
    Node_001B2ED8* n = m_C;
    Mat_001B2ED8 m;
    m = n->m_rot;
    Vec_001B2ED8 pos;
    pos = n->m_pos;
    pos[1] = 0.0f;
    (*target)[1] = 0.0f;
    Vec_001B2ED8 d;
    Sub_001B2ED8(d, pos, *target);
    float a = func_00101BC8(&m.r[2], &d) + 180.0f;
    if (a > 360.0f) a -= (int)(a * (1.0f / 360.0f)) * 360.0f;
    Vec_001B2ED8 c;
    Cross_001B2ED8(c, m.r[2], d);
    if (c[1] > 0.0f) a = 360.0f - a;
    func_001B3138(this, a * 0.01745329425f, f);
}
