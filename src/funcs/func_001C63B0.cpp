typedef int qword_001C63B0 __attribute__((mode(TI)));

struct Vec_001C63B0 {
    union {
        qword_001C63B0 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_001C63B0(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

extern float D_00387ADC;

extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

struct Obj_001C63B0 {
    char pad0[0x60];
    Vec_001C63B0 m_dir;

    Vec_001C63B0 RotatedDir(int angle);
};

Vec_001C63B0 Obj_001C63B0::RotatedDir(int angle)
{
    float a = (float)angle * D_00387ADC;
    float c = func_00340F60(a);
    float s = func_00341068(a);
    Vec_001C63B0 r(c * m_dir.f.x - s * m_dir.f.z, 0.0f, s * m_dir.f.x + c * m_dir.f.z, 1.0f);
    return r;
}
