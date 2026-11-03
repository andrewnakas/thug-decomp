extern "C" float sqrtf(float);

struct Vec_00136628 {
    float x, y, z, w;
    void SetDiff(const Vec_00136628& a, const Vec_00136628& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Light_00136628 {
    Vec_00136628 pos;
    float m10;
    float m14;
    float m18;
    char pad1C[0x14];
};

extern int D_00389E38;
extern Light_00136628 D_003BEC90[];

extern "C" Light_00136628* func_00136628(Vec_00136628* p)
{
    if (D_00389E38 <= 0) {
        return 0;
    }
    float best = 1.0f;
    int idx = -1;
    Vec_00136628 d;
    for (int i = 0; i < D_00389E38; i++) {
        Light_00136628* l = &D_003BEC90[i];
        if (l->m18 > 0.0f) {
            d.SetDiff(*p, l->pos);
            float len = d.Length();
            if (len < l->m10) {
                float s = len * l->m14;
                if (s < best) {
                    best = s;
                    idx = i;
                }
            }
        }
    }
    if (idx < 0) {
        return 0;
    }
    return &D_003BEC90[idx];
}
