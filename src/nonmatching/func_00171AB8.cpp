/* fuzzy: 97.7 */
extern "C" float sqrtf(float);

typedef int qword_00171AB8 __attribute__((mode(TI)));

struct V_00171AB8 {
    union {
        struct { float x, y, z, w; };
        qword_00171AB8 q;
    };
    V_00171AB8() {}
    V_00171AB8(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_00171AB8 operator+(const V_00171AB8& b) const { return V_00171AB8(x + b.x, y + b.y, z + b.z, w + b.w); }
    V_00171AB8 operator-(const V_00171AB8& b) const { return V_00171AB8(x - b.x, y - b.y, z - b.z, w - b.w); }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    V_00171AB8 operator*(float s) const { return V_00171AB8(x * s, y * s, z * s, w * s); }
};

extern float D_003876AC;
extern float D_003876B0;

struct Sphere_00171AB8 {
    V_00171AB8 m_center;
    float m_half[3];
};

extern "C" void func_00171AB8(Sphere_00171AB8* out, V_00171AB8* pts, int n)
{
    V_00171AB8 mn;
    V_00171AB8 mx;
    V_00171AB8 c;
    V_00171AB8 h;
    mn.x = mn.y = mn.z = D_003876AC;
    mx.x = mx.y = mx.z = D_003876B0;
    int i;
    for (i = 0; i < n; i++) {
        if (pts[i].x < mn.x) mn.x = pts[i].x;
        if (pts[i].y < mn.y) mn.y = pts[i].y;
        if (pts[i].z < mn.z) mn.z = pts[i].z;
        if (mx.x < pts[i].x) mx.x = pts[i].x;
        if (mx.y < pts[i].y) mx.y = pts[i].y;
        if (mx.z < pts[i].z) mx.z = pts[i].z;
    }
    c = (mx + mn) * 0.5f;
    float r = 0.0f;
    for (i = 0; i < n; i++) {
        float len = (pts[i] - c).Length();
        if (r < len) r = len;
    }
    h = (mx - mn) * 0.5f;
    out->m_center = c;
    out->m_center.w = r;
    out->m_half[0] = h.x;
    out->m_half[2] = h.z;
    out->m_half[1] = h.y;
}
