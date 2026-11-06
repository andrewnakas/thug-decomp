/* fuzzy: 94.5 */
struct Pos_0017F940 {
    unsigned long x : 11;
    unsigned long px : 21;
    unsigned long y : 11;
};

struct Tex_0017F940 {
    int m0;
    int m_flags;
};

struct Spr_0017F940 {
    int m0;
    int m_clip;
    int m8;
    unsigned int m_color;
    Pos_0017F940* m_pos;
    int m14;
    int m18;
    float m_x;
    float m_y;
    unsigned short m_u;
    unsigned short m_v;
    float m_w;
    float m_h;
    float m_ax;
    float m_ay;
    float m_rot;
    int m3C;
    Tex_0017F940* m_tex;
};

struct V_0017F940 {
    float x, y, z, w;
};

extern int D_0038882C;
extern float D_0038C0FC;
extern float D_0038C100;
extern int D_0038C104;
extern unsigned int D_0038C108;
extern unsigned int* D_00394274;
extern "C" unsigned short func_0017EDA8(Tex_0017F940* t);
extern "C" float func_00340F60(float x);
extern "C" float func_00341068(float x);

static inline void Rot(V_0017F940& v, float a)
{
    float s = func_00341068(a);
    float c = func_00340F60(a);
    float x = v.x;
    float y = v.y;
    v.x = c * x - s * y;
    v.y = s * x + c * y;
}

static inline bool IsPal()
{
    return D_0038882C == 1;
}

static inline long OffX(long v)
{
    if (D_0038882C == 1) {
        return v + 0x6C00;
    }
    return v + 0x7000;
}

static inline long OffY(long v)
{
    if (D_0038882C == 1) {
        return v + 0x7200;
    }
    return v + 0x7000;
}

static inline void Put(unsigned int a, unsigned int b, unsigned int c)
{
    D_00394274[0] = a;
    D_00394274[1] = b;
    D_00394274[2] = c;
    D_00394274[3] = 0;
    D_00394274 += 4;
}

static inline int SX(float x, int o)
{
    return (int)(x * D_0038C0FC) + o;
}

static inline int SY(float y, int o)
{
    return (int)(y * D_0038C100) + o;
}

static inline int ScreenX(Spr_0017F940* s)
{
    long px = s->m_pos->x << 4;
    long fx = (int)(s->m_x * D_0038C0FC * 16.0f);
    if (IsPal()) {
        fx += 0x6C00;
    } else {
        fx += 0x7000;
    }
    return px + fx;
}

static inline int ScreenY(Spr_0017F940* s)
{
    long py = s->m_pos->y << 4;
    long fy = (int)(s->m_y * D_0038C100 * 16.0f);
    if (IsPal()) {
        fy += 0x7200;
    } else {
        fy += 0x7000;
    }
    return py + fy;
}

extern "C" void func_0017F940(Spr_0017F940* s)
{

    int ox = ScreenX(s);
    int oy = ScreenY(s);
    unsigned short v = s->m_tex ? func_0017EDA8(s->m_tex) : s->m_v;
    unsigned short v0 = v << 4;
    unsigned short v1 = (v - s->m_v) << 4;
    unsigned short u1 = s->m_u << 4;
    unsigned short u0 = 0;
    float w = s->m_w;
    float h = s->m_h;
    if (w < 0.0f) {
        w = -w;
        u0 = u1;
        u1 = 0;
    }
    if (h < 0.0f) {
        unsigned short t = v0;
        h = -h;
        v0 = v1;
        v1 = t;
    }
    float sw = w * 16.0f;
    float sh = h * 16.0f;
    float x0 = -s->m_ax * sw;
    float y0 = -s->m_ay * sh;
    float x1 = x0 + (float)(u1 - u0) * w;
    float y1 = y0 + (float)(v0 - v1) * h;
    unsigned int col;
    if (D_0038C104) {
        col = D_0038C108;
    } else {
        col = s->m_color;
    }
    if (s->m_tex && ((s->m_tex->m_flags >> 4) & 1)) {
        unsigned short t = v0;
        v0 = v1;
        v1 = t;
    }
    if (s->m_rot != 0.0f) {
        V_0017F940 c[4];
        c[0].x = x0; c[0].y = y0; c[0].z = 0.0f; c[0].w = 0.0f;
        c[1].x = x1; c[1].y = y0; c[1].z = 0.0f; c[1].w = 0.0f;
        c[2].x = x0; c[2].y = y1; c[2].z = 0.0f; c[2].w = 0.0f;
        c[3].x = x1; c[3].y = y1; c[3].z = 0.0f; c[3].w = 0.0f;
        Rot(c[0], s->m_rot);
        Rot(c[1], s->m_rot);
        Rot(c[2], s->m_rot);
        Rot(c[3], s->m_rot);
        int ax = SX(c[0].x, ox);
        int bx = SX(c[1].x, ox);
        int cx = SX(c[2].x, ox);
        int dx = SX(c[3].x, ox);
        int ay = SY(c[0].y, oy);
        int by = SY(c[1].y, oy);
        int cy = SY(c[2].y, oy);
        int dy = SY(c[3].y, oy);
        if (s->m_clip && ((ax | bx | cx | dx | ay | by | cy | dy) & 0xFFFF0000)) {
            return;
        }
        Put(u0, v0, 0);
        Put(ax, ay, col);
        Put(u1, v0, 0);
        Put(bx, by, col);
        Put(u0, v1, 0);
        Put(cx, cy, col);
        Put(u1, v1, 0);
        Put(dx, dy, col);
    } else {
        int ax = SX(x0, ox);
        int bx = SX(x1, ox);
        int ay = SY(y0, oy);
        int by = SY(y1, oy);
        if (s->m_clip && ((ax | bx | ay | by) & 0xFFFF0000)) {
            return;
        }
        Put(u0, v0, 0);
        Put(ax, ay, col);
        Put(u1, v1, 0);
        Put(bx, by, col);
    }
}
