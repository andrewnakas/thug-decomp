struct Vec {
    float x, y, z, w;
};

struct Mat {
    float m[4][4];
};

extern "C" void func_003233B8(Vec* dst, Vec* src);

static inline void Cross(Vec& r, const Vec& a, const Vec& b)
{
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
    r.w = 0.0f;
}

static inline float Dot(const Vec& a, const Vec& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

extern "C" Mat* func_00100B60(Mat* out, const Vec* eye, const Vec* at, const Vec* up)
{
    Vec f;
    f.x = at->x - eye->x;
    f.y = at->y - eye->y;
    f.z = at->z - eye->z;
    f.w = at->w - eye->w;
    func_003233B8(&f, &f);
    Vec r;
    Vec u;
    Cross(r, f, *up);
    Cross(u, r, f);
    out->m[0][0] = r.x; out->m[1][0] = r.y; out->m[2][0] = r.z;
    out->m[0][1] = u.x; out->m[1][1] = u.y; out->m[2][1] = u.z;
    out->m[0][2] = f.x; out->m[1][2] = f.y; out->m[2][2] = f.z;
    out->m[0][3] = 0.0f; out->m[1][3] = 0.0f; out->m[2][3] = 0.0f;
    out->m[3][0] = -Dot(r, *eye);
    out->m[3][1] = -Dot(u, *eye);
    out->m[3][2] = -Dot(f, *eye);
    out->m[3][3] = 1.0f;
    return out;
}
