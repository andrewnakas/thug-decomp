typedef int qword __attribute__((mode(TI)));

struct Vec_00168580 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00168580() {}
    Vec_00168580(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Mat_00168580 {
    Vec_00168580 r0;
    Vec_00168580 r1;
    Vec_00168580 r2;
    Vec_00168580 r3;
};

static inline void Swap_00168580(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}

extern "C" void func_00323318(void* d, const Mat_00168580* a, void* b);

struct Cam_00168580 {
    char pad0[0xC0];
    Mat_00168580 mC0;
    void SetScale(short sx, short sy);
};

void Cam_00168580::SetScale(short sx, short sy)
{
    float fx = sx * (1.0f / 512.0f);
    float fy = sy * (1.0f / 512.0f);
    Mat_00168580 m;
    m.r0 = Vec_00168580(fx, 0.0f, 0.0f, 0.0f);
    m.r1 = Vec_00168580(0.0f, fy, 0.0f, 0.0f);
    m.r2 = Vec_00168580(0.0f, 0.0f, 1.4f, 0.0f);
    Swap_00168580(m.r0.y, m.r1.x);
    Swap_00168580(m.r0.z, m.r2.x);
    Swap_00168580(m.r0.w, m.r3.x);
    Swap_00168580(m.r1.z, m.r2.y);
    Swap_00168580(m.r1.w, m.r3.y);
    Swap_00168580(m.r2.w, m.r3.z);
    func_00323318(&mC0, &m, this);
}
