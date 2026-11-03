typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct V_001C0BC0 {
    float x, y, z, w;
};

union Vec_001C0BC0 {
    qword q;
    V_001C0BC0 v;
    Vec_001C0BC0() {}
    void Set(float x, float y, float z, float w)
    {
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
    }
    float Length() const { return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z); }
};

extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int flag);
extern "C" void func_003233B8(Vec_001C0BC0* out, Vec_001C0BC0* in);

static inline float Param_001C0BC0(unsigned int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &f, 1);
    return f;
}

struct Obj_001C0BC0 {
    char m_pad0[0x40];
    Vec_001C0BC0 m_40;
    char m_pad1[0x60 - 0x50];
    Vec_001C0BC0 m_60;
    char m_pad2[0x98 - 0x70];
    float m_98;
    void Update();
};

void Obj_001C0BC0::Update()
{
    float speed = m_40.Length();
    if (speed < Param_001C0BC0(0x0515A933)) {
        return;
    }
    Vec_001C0BC0 dir = m_40;
    func_003233B8(&dir, &dir);
    float t;
    if (Param_001C0BC0(0xE6C1CD0D) < speed) {
        t = Param_001C0BC0(0x7A583B9B) * m_98;
    } else {
        float rate = Param_001C0BC0(0x7A583B9B) * m_98;
        float lo = Param_001C0BC0(0x0515A933);
        float hi = Param_001C0BC0(0xE6C1CD0D);
        t = rate * ((speed - lo) / (hi - lo));
    }
    if (1.0f <= t) {
        m_60 = dir;
    } else {
        Vec_001C0BC0 sum;
        Vec_001C0BC0 step;
        Vec_001C0BC0 diff;
        diff.Set(dir.v.x - m_60.v.x, dir.v.y - m_60.v.y, dir.v.z - m_60.v.z, dir.v.w - m_60.v.w);
        step.Set(diff.v.x * t, diff.v.y * t, diff.v.z * t, diff.v.w * t);
        sum.Set(m_60.v.x + step.v.x, m_60.v.y + step.v.y, m_60.v.z + step.v.z, m_60.v.w + step.v.w);
        m_60 = sum;
        func_003233B8(&m_60, &m_60);
    }
}
