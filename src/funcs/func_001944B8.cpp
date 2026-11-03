typedef int qword __attribute__((mode(TI)));

struct Vec_001944B8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_001944B8 {
    Vec_001944B8 r[4];
    const Vec_001944B8& operator[](int i) const { return r[i]; }
    Mat_001944B8& operator=(const Mat_001944B8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Node_001944B8 {
    char pad0[0xC];
    unsigned int m_flags;
    char pad10[0x50 - 0x10];
    Vec_001944B8 m50;
    char pad60[0x70 - 0x60];
    Mat_001944B8 m_mat;
    Vec_001944B8 mB0;
    Mat_001944B8 m_lastMat;
};

struct Wheel_001944B8 {
    char pad0[0x8];
    float m_spin;
    char padC[0xB4 - 0xC];
    float mB4;
    char padB8[0x220 - 0xB8];
};

struct Obj_001944B8;
extern "C" void func_0019B920();
extern "C" void func_0019BB98(Obj_001944B8* self);
extern "C" void func_00197EC0(Obj_001944B8* self);
extern "C" void func_00196B40(Obj_001944B8* self);
extern "C" void func_0019BBB0(Obj_001944B8* self);
extern "C" void func_0019BE98(Obj_001944B8* self);
extern "C" void func_0019BEA0(Obj_001944B8* self);
extern "C" float func_0010FAB8();
extern "C" float func_00340E88(float);
extern "C" void func_00196678(Obj_001944B8* self);
extern "C" void func_00199618(Obj_001944B8* self);
extern "C" void func_00197AD0(Obj_001944B8* self);
extern "C" void func_001980F0(Obj_001944B8* self);
extern "C" void func_00198300(Obj_001944B8* self);
extern "C" void func_0019C380(Obj_001944B8* self);
extern "C" void func_0019B7A0(Obj_001944B8* self);
extern "C" int func_00103F28(const char* fmt, ...);
extern char D_00362060[];
extern char D_0036207F[];
extern char D_003620A8[];

struct Obj_001944B8 {
    char pad0[0xC];
    Node_001944B8* m_node;
    char pad10[0x20 - 0x10];
    Vec_001944B8 m20;
    char pad30[0x60 - 0x30];
    int m60;
    char pad64[0x70 - 0x64];
    Mat_001944B8 m_mat;
    Vec_001944B8 mB0;
    char padC0[0x120 - 0xC0];
    unsigned int m_state;
    char pad124[0x128 - 0x124];
    int m128;
    char pad12C[0x134 - 0x12C];
    float m134;
    char pad138[0x140 - 0x138];
    Vec_001944B8 m_force;
    Vec_001944B8 m_torque;
    float m_dt;
    char pad164[0x1C4 - 0x164];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_001944B8* m_wheels;
    char pad31C[0x354 - 0x31C];
    int m354;
    char pad358[0x135C - 0x358];
    float m_gravityScale;
    float m_gravityTime;
    char pad1364[0x1368 - 0x1364];
    float m1368;
    float m136C;
    float m1370;
    char pad1374[0x1384 - 0x1374];
    int m1384;
    bool Busy() { return m134 > 0.0f; }
    bool Aborted()
    {
        bool r = false;
        if (m128 || (m_node->m_flags & 1)) r = true;
        return r;
    }
    void Update();
};

void Obj_001944B8::Update()
{
    m128 = 0;
    if (m1384 == 0) {
        func_0019B920();
    } else {
        func_0019BB98(this);
    }
    if (m60 == 0) {
        m_node->m_lastMat = m_node->m_mat;
        func_00197EC0(this);
        if (m354) {
            int i = m_numWheels;
            while (i-- != 0) {
                m_wheels[i].m_spin = 0.0f;
            }
        }
        func_00196B40(this);
        func_0019BBB0(this);
        func_0019BE98(this);
        func_0019BEA0(this);
        return;
    }
    float dt = func_0010FAB8();
    if (Busy()) {
        m134 -= dt;
    }
    if (m_gravityTime != 0.0f) {
        m_gravityTime -= dt;
        if (m_gravityTime <= 0.0f || m_state >= 2) {
            func_00103F28(D_00362060, D_0036207F, 0x29B, D_003620A8);
            m_gravityTime = 0.0f;
            m_gravityScale = 1.0f;
        }
    }
    int steps;
    if (dt >= 1.0f / 30.0f) {
        steps = (int)func_00340E88(dt * 59.999996f);
        if (steps >= 7) steps = 6;
        m_dt = dt / (float)steps;
    } else {
        m_dt = dt;
        steps = 1;
    }
    int k = steps;
    while (k--) {
        func_00196678(this);
        m_force.Set(0.0f, 0.0f, 0.0f, 1.0f);
        m_torque.Set(0.0f, 0.0f, 0.0f, 1.0f);
        int i = m_numWheels;
        while (i-- != 0) {
            m_wheels[i].mB4 = 0.0f;
        }
        if (m1384 == 0) {
            func_00199618(this);
            if (Aborted()) return;
        }
        func_00197AD0(this);
        if (Aborted()) return;
        func_00197EC0(this);
        func_001980F0(this);
        func_00198300(this);
        if (m_state != 0) {
            m1368 = 0.0f;
        } else {
            m1368 += m_dt;
        }
        if (m_state != 0 || m1370 > 0.0f) {
            m136C = 0.0f;
        } else {
            m136C += m_dt;
        }
    }
    if (m1384 == 0) {
        func_0019C380(this);
        m_node->m50 = m20;
        m_node->mB0 = mB0;
        m_node->m_mat = m_mat;
        m_node->m_lastMat = m_node->m_mat;
        func_0019B7A0(this);
        func_0019BBB0(this);
        func_0019BE98(this);
        func_0019BEA0(this);
    }
}
