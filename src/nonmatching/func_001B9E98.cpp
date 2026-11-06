/* fuzzy: 85.8 */
struct Vec_001B9E98 {
    float x, y, z, w;
    Vec_001B9E98() {}
    Vec_001B9E98(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001B9E98& operator+=(const Vec_001B9E98& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
        return *this;
    }
};

static inline Vec_001B9E98 operator*(const Vec_001B9E98& a, float s)
{
    return Vec_001B9E98(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Mat_001B9E98 {
    Vec_001B9E98 row[4];
};

extern "C" float func_00341068(float x);
extern "C" float func_0010FAB8();

struct Shake_001B9E98 {
    char pad[0x148];
    float m_time;
    float m_duration;
    float m_ampY;
    float m_ampX;
    float m_freqY;
    float m_freqX;
    void Apply(Vec_001B9E98* pos, Mat_001B9E98* m);
};

void Shake_001B9E98::Apply(Vec_001B9E98* pos, Mat_001B9E98* m)
{
    float t = m_time;
    float ax = 2.0f * (t * m_freqX * 3.1415927f);
    float ay = 2.0f * (t * m_freqY * 3.1415927f);
    float fade = t / m_duration;
    float y = m_ampY * func_00341068(ay) * fade;
    float x = m_ampX * func_00341068(ax) * fade;
    *pos += m->row[0] * x;
    *pos += m->row[1] * y;
    m_time -= func_0010FAB8();
    if (m_time < 0.0f)
        m_time = 0.0f;
}
