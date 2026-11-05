typedef int qword_001C4210 __attribute__((mode(TI)));

struct Vec_001C4210 {
    union {
        qword_001C4210 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

extern float D_00387ABC;
extern volatile float D_00387AC0;

extern "C" float func_003414F0(float y, float x);

static inline float Abs_001C4210(float x)
{
    return (x < 0.0f) ? -x : x;
}

struct Obj_001C4210 {
    char pad0[0x60];
    Vec_001C4210 m_dir;
    char pad70[0xBE0];
    Vec_001C4210 m_targetDir;
    float m_turnTime;
    float m_turnAngle;

    void StartTurn(const Vec_001C4210* dir, float time);
};

void Obj_001C4210::StartTurn(const Vec_001C4210* dir, float time)
{
    float from = func_003414F0(m_dir.f.x, m_dir.f.z);
    float diff = func_003414F0(dir->f.x, dir->f.z) - from;
    m_turnAngle = diff;
    if (Abs_001C4210(diff) > D_00387ABC) {
        float sign = 1.0f;
        if (diff < 0.0f)
            sign = -1.0f;
        m_turnAngle = diff - sign * D_00387AC0;
    }
    m_targetDir = *dir;
    m_turnTime = time;
}
