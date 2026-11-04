typedef int qword __attribute__((mode(TI)));

struct Vec_001C3590 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_001C3590() {}
    Vec_001C3590(float x, float y, float z, float w)
    {
        f.x = x; f.y = y; f.z = z; f.w = w;
    }
};

struct Obj_001C3590 {
    char pad0[0x70];
    Vec_001C3590 m_q;
    char pad80[0x980 - 0x80];
    float m_980;
    void Update();
};

extern "C" void* func_001E5548(unsigned int name, int);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);
extern "C" float func_0010FAB8();
extern "C" void func_003233B8(Vec_001C3590* out, Vec_001C3590* in);

void Obj_001C3590::Update()
{
    Vec_001C3590& q = m_q;
    if (m_q.f.y == 1.0f) return;
    if (m_q.f.y > 0.999f) {
        q.f.x = 0.0f;
        q.f.y = 1.0f;
        q.f.z = 0.0f;
        q.f.w = 1.0f;
        m_980 = 0.0f;
        return;
    }
    if (m_980 == 0.0f) {
        Vec_001C3590 res;
        Vec_001C3590 target(0.0f, 1.0f, 0.0f, 1.0f);
        Vec_001C3590 scaled;
        Vec_001C3590 diff;
        float rate;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x0F22C135, &rate, 1);
        float r = rate;
        float t = r * func_0010FAB8();
        diff.f.x = target.f.x - m_q.f.x;
        diff.f.y = target.f.y - m_q.f.y;
        diff.f.z = target.f.z - m_q.f.z;
        diff.f.w = target.f.w - m_q.f.w;
        scaled.f.x = diff.f.x * t;
        scaled.f.y = diff.f.y * t;
        scaled.f.z = diff.f.z * t;
        scaled.f.w = diff.f.w * t;
        res.f.x = m_q.f.x + scaled.f.x;
        res.f.y = m_q.f.y + scaled.f.y;
        res.f.z = m_q.f.z + scaled.f.z;
        res.f.w = m_q.f.w + scaled.f.w;
        q.q = res.q;
        func_003233B8(&q, &q);
    }
}
