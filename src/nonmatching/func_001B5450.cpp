/* fuzzy: 72.2 */
typedef int qword_001B5450 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct V_001B5450 {
    union {
        qword_001B5450 q;
        struct {
            float x, y, z, w;
        };
    };
};

struct M_001B5450 {
    V_001B5450 r[4];
};

struct Target_001B5450 {
    char pad0[0x50];
    float x, y, z, w;   /* 0x50 */
};

struct Jump_001B5450 {
    char pad0[0xC];
    Target_001B5450* m_target;  /* 0x0C */
    char pad10[0x10];
    unsigned int m_flags;       /* 0x20 */
    char pad24[0x3C];
    float m_pos[4];             /* 0x60 */
    char pad70[0x60];
    int m_spin;                 /* 0xD0 */
    int mD4;                    /* 0xD4 */
    float m_spinTime;           /* 0xD8 */
    int mDC;                    /* 0xDC */
    M_001B5450 m_startMatrix;   /* 0xE0 */
    int m120;                   /* 0x120 */
    float m_heading;            /* 0x124 */
    char pad128[8];
    M_001B5450 m_matrix;        /* 0x130 */
    void* Launch(void* params, int toTarget);
};

extern "C" void func_001B5E78(Jump_001B5450* self);
extern "C" void* func_001B4D00(Jump_001B5450* self, void* params);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" float func_001E5318(unsigned int name, int required);
extern "C" int func_001E8708(void* params, unsigned int flag);
extern "C" void func_001E72B0(void* s, unsigned int id, float v);
extern "C" int func_001E7528(void* s, unsigned int id, V_001B5450* v);
extern "C" void func_001E7360(void* s, unsigned int id, int v);
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int required);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" bool func_001A2CE0(void* comp);
extern "C" int func_00100030(int range);
extern "C" float func_00101BC8(const void* a, const V_001B5450* b);
extern "C" void func_003233B8(V_001B5450* dst, V_001B5450* src);

/* sets up a jump: computes launch velocity (to the target, or straight up) and the spin, and fills the result struct */
void* Jump_001B5450::Launch(void* params, int toTarget)
{
    func_001B5E78(this);
    m_flags = m_flags & ~0x200 & ~0x400;
    m120 = 0;
    m_heading = 0.0f;
    mD4 = 0;
    void* out = func_001B4D00(this, params);

    float height;
    func_001E7EB0(params, 0x838DA447, &height, 1);
    float gravity = func_001E5318(0xE224A5D3, 1);
    float time;

    if (toTarget || func_001E8708(params, 0xB02567AE)) {
        Target_001B5450* t = m_target;
        V_001B5450 d;
        d.x = m_pos[0] - t->x;
        d.y = 0.0f;
        d.z = m_pos[2] - t->z;
        d.w = m_pos[3] - t->w;
        if (t->y + height < m_pos[1])
            height = (m_pos[1] - t->y) + func_001E5318(0x23F14B13, 1);
        float h = height;
        float up = sqrtf(-h * 2.0f / gravity);
        float down = sqrtf(__builtin_fabsf((m_target->y + h - m_pos[1]) / gravity) * 2.0f);
        float dist = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        time = up + down;
        float hspeed = dist / time;
        float vspeed = h / up - gravity * (up * 0.5f);
        func_003233B8(&d, &d);

        V_001B5450 hv;
        hv.x = d.x * hspeed;
        hv.y = d.y * hspeed;
        hv.z = d.z * hspeed;
        hv.w = d.w * hspeed;
        V_001B5450 axis;
        axis.x = 0.0f;
        axis.y = 1.0f;
        axis.z = 0.0f;
        axis.w = 1.0f;
        V_001B5450 vv;
        vv.x = axis.x * vspeed;
        vv.y = axis.y * vspeed;
        vv.z = axis.z * vspeed;
        vv.w = axis.w * vspeed;
        V_001B5450 vel;
        vel.x = hv.x + vv.x;
        vel.y = hv.y + vv.y;
        vel.z = hv.z + vv.z;
        vel.w = hv.w + vv.w;
        float speed = sqrtf(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
        func_003233B8(&vel, &vel);
        func_001E7528(out, 0xFD4BC03E, &vel);
        func_001E72B0(out, 0x1C4C5690, speed);
        func_001E72B0(out, 0x66CED87B, time);
    } else {
        func_001E72B0(out, 0x1C4C5690, sqrtf(gravity * 2.0f * -height));
        float half = sqrtf(-height * 2.0f * gravity);
        time = half + half;
    }

    int spin = 0;
    if (func_001E8708(params, 0xB4077854)) {
        int n = (int)(time / func_001E5318(0x8B381AB1, 1));
        if (n >= 5)
            n = 4;
        spin = func_00100030(n + 1) * 180;
    } else {
        float f;
        if (func_001E7EB0(params, 0x96FB50D9, &f, 0))
            spin = (int)(f + 0.01f);
    }
    if (spin < 0)
        spin = -spin;
    if (spin > 0) {
        int dir;
        func_001E8398(params, 0xEF0B71A0, &dir, 1);
        bool flag = func_001A2CE0(func_00185578(m_target, 0x72AD7B23));
        switch ((unsigned int)dir) {
        case 0x20E1C4A3:
            if (flag)
                spin = -spin;
            break;
        case 0x448D01A7:
            if (!flag)
                spin = -spin;
            break;
        case 0xE7390A8B:
            if (func_00100030(2) == 1)
                spin = -spin;
            break;
        }
        m_spin = spin;
        m_flags |= 0x200;
    }

    int rotate = func_001E8708(params, 0x04AA0CFF);
    if (spin % 360 == 0) {
        if (!rotate)
            func_001E7360(out, 0, 0x8868E76A);
    } else if (rotate) {
        func_001E7360(out, 0, 0x8868E76A);
    }
    if (rotate) {
        V_001B5450 up;
        up.x = 0.0f;
        up.w = 1.0f;
        m_flags |= 0x400;
        up.y = 1.0f;
        up.z = 0.0f;
        m_heading = func_00101BC8(&m_matrix.r[2], &up) + func_001E5318(0x95E91D23, 0);
    }
    if (m_flags & 0x600) {
        m_startMatrix = m_matrix;
        m_spinTime = time * func_001E5318(0xC1DFC97B, 1);
        mDC = 0;
    }
    if (func_001E8708(params, 0xB02567AE))
        func_001E72B0(out, 0xA1810C27, m_pos[1]);
    return out;
}
