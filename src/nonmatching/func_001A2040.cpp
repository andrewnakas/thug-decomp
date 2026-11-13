/* fuzzy: 64.4 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Vec_001A2040 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001A2040() {}
    Vec_001A2040(const Vec_001A2040& v) { q = v.q; }
    Vec_001A2040(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

inline Vec_001A2040 operator-(const Vec_001A2040& a, const Vec_001A2040& b)
{
    return Vec_001A2040(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

inline Vec_001A2040 operator+(const Vec_001A2040& a, const Vec_001A2040& b)
{
    return Vec_001A2040(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vec_001A2040 operator*(const Vec_001A2040& a, float s)
{
    return Vec_001A2040(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Quat_001A2040 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat_001A2040() {}
    Quat_001A2040(const Quat_001A2040& v) { q = v.q; }
    Quat_001A2040(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Quat_001A2040 operator-() const { Quat_001A2040 r(-x, -y, -z, -w); return r; }
    Quat_001A2040 Normalize()
    {
        float s = 1.0f / sqrtf(x * x + y * y + z * z + w * w);
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
};

inline float Dot(const Quat_001A2040& a, const Quat_001A2040& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

struct Frame_001A2040 {
    Quat_001A2040 q[64];
    Vec_001A2040 t[64];
};

void func_001A2040(Frame_001A2040* frames, float* w, int count, Frame_001A2040* out, int n)
{
    int i;
    float cnt = 0.0f;
    for (i = 1; i < n; i++) {
        if (w[i] != 0.0f)
            cnt += 1.0f;
    }
    float sum = 0.0f;
    for (i = 1; i < n; i++)
        sum += w[i];
    w[0] = cnt - sum;

    float acc = 0.0f;
    for (i = n - 1; i > 0; i--) {
        if (w[i] != 0.0f) {
            float sw = w[i] + acc;
            int j = i - 1;
            while (w[j] <= 0.0f && j > 0)
                j--;
            acc += w[i];
            float t = 1.0f - w[j] / (sw + w[j]);
            Frame_001A2040* fj = &frames[j];
            Frame_001A2040* fi = &frames[i];
            for (int k = 0; k < count; k++) {
                Quat_001A2040& qj = fj->q[k];
                Quat_001A2040& qi = fi->q[k];
                if (Dot(qj, qi) < 0.0f)
                    qi = -qi;
                float x = qj.x + (qi.x - qj.x) * t;
                float y = qj.y + (qi.y - qj.y) * t;
                float z = qj.z + (qi.z - qj.z) * t;
                float ww = qj.w + (qi.w - qj.w) * t;
                qi.x = x;
                qi.y = y;
                qi.z = z;
                qi.w = ww;
                Quat_001A2040 nq = qi.Normalize();
                qj = nq;
                fj->t[k] = fj->t[k] + (fi->t[k] - fj->t[k]) * t;
            }
        }
    }
    func_00331404(out, frames, count * 16);
    func_00331404(out->t, frames->t, count * 16);
}
