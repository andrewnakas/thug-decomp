/* sym: __15Feeler_001BF5A0 = 0x00209240 */
/* Walk component: turns the facing (m_60) toward the control direction (m_A0) and adjusts the walking speed.
   A sharp turn at low speed rotates by a fixed rate (slowed when a wall feeler hits), small turns blend toward
   the target, a near-reverse at speed skids to a stop; then a speed above the target eases down toward it
   (skid animation when stopping), otherwise it grows by a fixed rate capped at the target.
   m_90 receives the matching animation checksum. */
typedef int qword __attribute__((mode(TI)));

struct Vec_001BF5A0 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_001BF5A0() {}
    Vec_001BF5A0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    const float& operator[](int i) const { return (&x)[i]; }
};

static inline Vec_001BF5A0 operator+(const Vec_001BF5A0& a, const Vec_001BF5A0& b)
{
    return Vec_001BF5A0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_001BF5A0 operator-(const Vec_001BF5A0& a, const Vec_001BF5A0& b)
{
    return Vec_001BF5A0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

static inline Vec_001BF5A0 operator*(const Vec_001BF5A0& a, float s)
{
    return Vec_001BF5A0(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_001BF5A0 {
    void* m_p;
    void* m_prev;
    void* m_next;
    ~Ref_001BF5A0()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Feeler_001BF5A0 {
    Feeler_001BF5A0();
    Vec_001BF5A0 m_start;
    Vec_001BF5A0 m_end;
    char pad20[0xC0 - 0x20];
    Ref_001BF5A0 m_ref;
    char padCC[0xE0 - 0xCC];
};

struct Walk_001BF5A0 {
    char pad0[0x30];
    Vec_001BF5A0 m_pos;
    char pad40[0x60 - 0x40];
    Vec_001BF5A0 m_facing;
    char pad70[0x90 - 0x70];
    unsigned int m_anim;
    unsigned int m_lastAnim;
    float m_dt;
    char pad9C[4];
    Vec_001BF5A0 m_control;
    float m_input;
    int m_B4;
    int m_B8;
    char padBC[0x954 - 0xBC];
    float m_targetSpeed;
    char pad958[0xA60 - 0x958];
    int m_A60;
    char padA64[0xB58 - 0xA64];
    int m_B58;
    float m_B5C;
    int m_B60;
    void Update(float* speed);
};

extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int required);
extern "C" float func_001C6218(Walk_001BF5A0* self);
extern "C" float func_001C0E30(Walk_001BF5A0* self, float v);
extern "C" float func_00340F60(float x);
extern "C" float func_00341068(float x);
extern "C" int func_002093E8(Feeler_001BF5A0* f, int a, int b);
extern "C" void func_003233B8(Vec_001BF5A0* d, Vec_001BF5A0* s);

static inline float Max_001BF5A0(float a, float b)
{
    if (a < b)
        return b;
    return a;
}

static inline float Clamp_001BF5A0(float v, float lo, float hi)
{
    if (hi < v)
        v = hi;
    if (v < lo)
        return lo;
    return v;
}

static inline float Param(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

void Walk_001BF5A0::Update(float* speed)
{
    if (m_B4) {
        if (!m_B60)
            m_B5C = 0.0f;
        m_B5C += m_dt;
    }
    m_B60 = m_B4;

    float target = func_001C6218(this);
    if (target <= 0.0f)
        m_anim = 0x9B46E749;
    else
        m_anim = 0xAF895B3F;

    int done = 0;
    if (0.0f < m_input) {
        float d = m_facing.x * m_control.x + m_facing.y * m_control.y + m_facing.z * m_control.z;
        if ((*speed < Param(0x52582D5B) && d < func_00340F60(Param(0x5DFF96A4) * 0.017453294f)) ||
            (*speed < Param(0xF1E97E45) && d < -func_00340F60(Param(0x2D571C0F) * 0.017453294f))) {
            float rad = Param(0xB557804B) * 0.017453294f;
            float ang = rad * m_input * m_dt;
            int left = -m_facing.z * m_control.x + m_facing.x * m_control.z < 0.0f;
            if (!m_A60 || m_B58) {
                ang *= Param(0x7B446C98);
            } else {
                float c = func_00340F60(left ? ang : -ang);
                float s = func_00341068(left ? ang : -ang);
                Vec_001BF5A0 dir;
                dir.x = c * m_facing.x + s * m_facing.z;
                dir.y = 0.0f;
                dir.z = -s * m_facing.x + c * m_facing.z;
                Feeler_001BF5A0 f;
                f.m_start = m_pos;
                f.m_start.y += Param(0x6DA7F696);
                f.m_end = f.m_start + dir * Param(0x99978D2B);
                if (func_002093E8(&f, 0, 0))
                    ang *= Param(0x7B446C98);
            }
            float c = func_00340F60(left ? ang : -ang);
            float s = func_00341068(left ? ang : -ang);
            float nx = c * m_facing.x + s * m_facing.z;
            float nz = -s * m_facing.x + c * m_facing.z;
            m_facing.z = nz;
            m_facing.x = nx;
            int nowLeft = -nz * m_control.x + nx * m_control.z < 0.0f;
            if (left != nowLeft)
                m_facing = m_control;
            m_anim = left ? 0xF28ADBFC : 0x912220F8;
            done = 1;
        } else if (-func_00340F60(Param(0x2D571C0F) * 0.017453294f) < d) {
            float lo = m_B8 ? Param(0xA26760F5) : Param(0xAB9015BC);
            float hi = m_B8 ? Param(0x6CB2E5DE) : Param(0x911F29D7);
            float t = Clamp_001BF5A0((1.0f - (m_control.x * m_facing.x + m_control.y * m_facing.y + m_control.z * m_facing.z)) * 2.0f, 0.0f, 1.0f);
            float base = lo + (hi - lo) * t;
            float rate;
            if (*speed < Param(0x27815F69)) {
                float slow = Param(0xB278405D);
                rate = slow + (base - slow) * (*speed / Param(0x27815F69));
            } else {
                rate = base;
            }
            rate *= m_input;
            rate *= m_dt;
            if (1.0f <= rate) {
                m_facing = m_control;
            } else {
                m_facing = m_facing + (m_control - m_facing) * rate;
                func_003233B8(&m_facing, &m_facing);
            }
        } else if (Param(0xF1E97E45) < *speed) {
            done = 1;
            *speed = *speed - Param(0x09661ED7) * m_dt;
            *speed = Max_001BF5A0(*speed, 0.0f);
            m_anim = 0x1D537EFF;
        } else {
            m_facing = m_control;
        }
    }
    if (done)
        return;

    m_targetSpeed = target;
    target = func_001C0E30(this, target);
    if (target < *speed) {
        float ease = Param(0xACFA4E0C);
        if (target == 0.0f) {
            if (Param(0x79D182AD) < *speed)
                m_anim = 0x1D537EFF;
            else if (m_lastAnim == 0x1D537EFF && Param(0x311D02B2) < *speed)
                m_anim = 0x1D537EFF;
            else
                ease = Param(0x0A2AA811);
        }
        *speed = *speed + (target - *speed) * (ease * m_dt);
    } else {
        if (m_A60)
            *speed = *speed + Param(0x4F47C998) * m_dt;
        else
            *speed = *speed + Param(0x6590A49B) * m_dt;
        if (target < *speed)
            *speed = target;
    }
}
