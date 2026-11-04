typedef int qword_001C7928 __attribute__((mode(TI)));

struct Vec_001C7928 {
    union {
        qword_001C7928 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_001C7928() {}
    Vec_001C7928(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);

struct Skater_001C7928 {
    char pad0[0x60];
    Vec_001C7928 m_dir;
    char pad70[0x900];
    Vec_001C7928 m_vel;

    void Launch();
};

extern "C" float func_001CB6F8(Skater_001C7928* self);
extern "C" void func_001BF130(Skater_001C7928* self, int state);

void Skater_001C7928::Launch()
{
    float speed;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xC3263E6E, &speed, 1);
    m_vel = Vec_001C7928(m_dir.f.x * speed, m_dir.f.y * speed, m_dir.f.z * speed, m_dir.f.w * speed);
    m_vel.f.y = func_001CB6F8(this);
    func_001BF130(this, 2);
}
