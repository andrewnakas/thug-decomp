/* fuzzy: 91.8 */
extern float D_00387B80;

static inline float Abs_001D2438(float x)
{
    return (x < 0.0f) ? -x : x;
}

bool func_001D2438(float* t, float ax, float ay, float adx, float ady, float bx, float by, float bdx, float bdy)
{
    float apx = -ady;
    float apy = adx;
    float bpx = -bdy;
    float bpy = bdx;
    float den = bdx * apx + bdy * apy;
    float dx = ax - bx;
    float dy = ay - by;
    float nb = dx * bpx + dy * bpy;
    float na = dx * apx + dy * apy;
    if (den > 0.0f) {
        if (nb < 0.0f || nb > den)
            return false;
    } else {
        if (nb > 0.0f || nb < den)
            return false;
    }
    if (den > 0.0f) {
        if (na < 0.0f || na > den)
            return false;
    } else {
        if (na > 0.0f || na < den)
            return false;
    }
    if (Abs_001D2438(den) < D_00387B80) {
        *t = 0.0f;
        return true;
    }
    *t = nb / den;
    return true;
}
