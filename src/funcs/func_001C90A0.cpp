typedef int qword __attribute__((mode(TI)));

struct Vec_001C90A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001C90A0() {}
    Vec_001C90A0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_001C90A0 operator+(const Vec_001C90A0& a, const Vec_001C90A0& b)
{
    return Vec_001C90A0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001C90A0 operator*(const Vec_001C90A0& a, float s)
{
    return Vec_001C90A0(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Ray_001C90A0 {
    Vec_001C90A0 m_pos;
    Vec_001C90A0 m_dir;
    Vec_001C90A0 Dir(float s) const { return Vec_001C90A0(m_dir.x * s, m_dir.y * s, m_dir.z * s, m_dir.w * s); }
};

struct Seg_001C90A0 {
    Vec_001C90A0 m_start;
    Vec_001C90A0 m_end;
};

extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int assert_);
extern "C" float func_001CB6F8(void* self);
extern "C" int func_002093E8(Seg_001C90A0* seg, int a, int b);

static inline float GetParam_001C90A0(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

bool func_001C90A0(void* self, Seg_001C90A0* seg, Ray_001C90A0* ray, Vec_001C90A0* off)
{
    {
        Vec_001C90A0 q = ray->m_pos + ray->Dir(GetParam_001C90A0(0xC3263E6E)) + *off * GetParam_001C90A0(0xAFBF7687);
        seg->m_start = q;
        seg->m_end = q;
    }
    float h = GetParam_001C90A0(0xA8C13E74);
    seg->m_start.y += func_001CB6F8(self) - h;
    seg->m_end.y += GetParam_001C90A0(0x8F35F29F);
    if (func_002093E8(seg, 1, 0)) {
        return false;
    }
    Vec_001C90A0 t = seg->m_start;
    seg->m_start = seg->m_end;
    seg->m_end = t;
    return func_002093E8(seg, 1, 0) == 0;
}
