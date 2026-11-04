struct Vec_002BB010 {
    float x, y, z, w;
    Vec_002BB010() {}
    Vec_002BB010(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_002BB010 operator-(const Vec_002BB010& a, const Vec_002BB010& b)
{
    return Vec_002BB010(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Cell_002BB010 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
};

struct Shape_002BB010;

struct Grid_002BB010 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    char pad6[0x38 - 6];
    virtual Shape_002BB010* GetShape(int i);
};

extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;
extern "C" Cell_002BB010* func_002BB3B0(Grid_002BB010* g, int i);
extern "C" Vec_002BB010 func_002B6D00(Shape_002BB010* s, int k);

Vec_002BB010 func_002BB010(Grid_002BB010* g, int i)
{
    Vec_002BB010 c;
    Vec_002BB010 p;
    c.x = g->m3 * D_00392610 * 0.5f;
    c.y = 0.0f;
    c.z = g->m5 * D_00392618 * 0.5f;
    Cell_002BB010* cell = func_002BB3B0(g, i);
    Shape_002BB010* s = g->GetShape(i);
    Vec_002BB010 a = func_002B6D00(s, cell->m3);
    float x = cell->m0 * D_00392610 + a.x * 0.5f;
    float y = cell->m1 * D_00392614;
    Vec_002BB010 b = func_002B6D00(s, cell->m3);
    p.Set(x, y, cell->m2 * D_00392618 + b.z * 0.5f, 1.0f);
    return p - c;
}
