struct Vec_001D2220 {
    float x, y, z, w;
};

static inline void Sub_001D2220(Vec_001D2220& r, const Vec_001D2220& a, const Vec_001D2220& b)
{
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
}

static inline void Cross_001D2220(Vec_001D2220& r, const Vec_001D2220& a, const Vec_001D2220& b)
{
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
    r.w = 0.0f;
}

static inline float Dot_001D2220(const Vec_001D2220& a, const Vec_001D2220& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

extern "C" bool func_001D2220(const Vec_001D2220* orig, const Vec_001D2220* dir, const Vec_001D2220* v0,
                              const Vec_001D2220* v1, const Vec_001D2220* v2, float* t)
{
    Vec_001D2220 e1;
    Vec_001D2220 e2;
    Vec_001D2220 pvec;
    Vec_001D2220 tvec;
    Vec_001D2220 qvec;
    Sub_001D2220(e1, *v1, *v0);
    Sub_001D2220(e2, *v2, *v0);
    Cross_001D2220(pvec, *dir, e2);
    float det = Dot_001D2220(e1, pvec);
    if (det < 0.03f)
        return false;
    Sub_001D2220(tvec, *orig, *v0);
    float u = Dot_001D2220(tvec, pvec);
    float lim = det * 1.00001f;
    if (u < 0.0f || u > lim)
        return false;
    Cross_001D2220(qvec, tvec, e1);
    float v = Dot_001D2220(*dir, qvec);
    if (v < 0.0f || u + v > lim)
        return false;
    *t = Dot_001D2220(e2, qvec) * (1.0f / det);
    bool hit = false;
    if (*t <= 1.0f && *t >= 0.0f)
        hit = true;
    return hit;
}
