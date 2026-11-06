typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct V_001BF2F0 {
    float x, y, z, w;
};

union Vec_001BF2F0 {
    qword q;
    V_001BF2F0 v;
    Vec_001BF2F0() {}
    void Set(float x, float y, float z, float w)
    {
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
    }
    float LengthSq() const { return v.x * v.x + v.y * v.y + v.z * v.z; }
    float Length() const { return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z); }
    void Add(const Vec_001BF2F0& o)
    {
        v.x += o.v.x;
        v.y += o.v.y;
        v.z += o.v.z;
        v.w += o.v.w;
    }
};

struct Obj_001BF2F0 {
    char m_pad0[0xB0];
    Vec_001BF2F0 m_B0;
};

struct Sub_001BF2F0 {
    char m_pad0[0x2C];
    int m_2C;
};

extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int flag);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" Obj_001BF2F0* func_001CE918(void* a, Vec_001BF2F0* pos, void* b);
extern char D_00363408[];
extern char D_00363427[];
extern char D_00363448[];
extern void* D_0038EE60;

static inline float Param_001BF2F0(unsigned int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &f, 1);
    return f;
}

struct C_001BF2F0 {
    char m_pad0[0x1C];
    int m_1C;
    char m_pad1[0x30 - 0x20];
    Vec_001BF2F0 m_30;
    Vec_001BF2F0 m_40;
    int m_50;
    char m_pad2[0x60 - 0x54];
    Vec_001BF2F0 m_60;
    char m_pad3[0x80 - 0x70];
    char m_80[0x10];
    unsigned int m_90;
    char m_pad4[0x98 - 0x94];
    float m_98;
    char m_pad5[0xA38 - 0x9C];
    Sub_001BF2F0* m_A38;
    void* m_A3C;
    char m_pad6[0xB58 - 0xA40];
    int m_B58;
    float m_B5C;
    void Update();
};

extern "C" void func_001C1630(C_001BF2F0* self);
extern "C" void func_001C5330(C_001BF2F0* self);
extern "C" void func_001BF5A0(C_001BF2F0* self, float* speed);
extern "C" int func_001C0030(C_001BF2F0* self);
extern "C" void func_001C0BC0(C_001BF2F0* self);
extern "C" void func_001C0F20(C_001BF2F0* self);
extern "C" void func_001C1308(C_001BF2F0* self);

void C_001BF2F0::Update()
{
    func_001C1630(this);
    func_001C5330(this);
    float speed = m_40.Length();
    func_001BF5A0(this, &speed);
    if (m_90 == 0x1D537EFF) {
        if (m_B5C < Param_001BF2F0(0x8E1CF27A)) m_90 = 0x9B46E749;
    }
    Vec_001BF2F0 t;
    t.Set(m_60.v.x * speed, m_60.v.y * speed, m_60.v.z * speed, m_60.v.w * speed);
    m_40 = t;
    if (func_001C0030(this)) {
        func_001C0BC0(this);
    } else {
        m_B58 = 0;
    }
    if (m_1C != 0 || m_A38->m_2C != 0) {
        D_0038EE60 = 0;
        return;
    }
    Vec_001BF2F0* vel = &m_40;
    float dt = m_98;
    t.Set(m_40.v.x * dt, m_40.v.y * dt, m_40.v.z * dt, m_40.v.w * dt);
    m_30.Add(t);
    func_001C0F20(this);
    if (m_1C != 0 || m_A38->m_2C != 0) {
        D_0038EE60 = 0;
        return;
    }
    func_001C1308(this);
    Obj_001BF2F0* o = func_001CE918(m_A3C, &m_30, m_80);
    if (o) {
        func_00103F28(D_00363408, D_00363427, 0x327, D_00363448);
        m_40 = o->m_B0;
        m_50 = 0;
        m_40.v.y = 0.0f;
        float l2 = vel->LengthSq();
        if (l2 > 100.0f) {
            float r = 1.0f / sqrtf(l2);
            t.Set(m_40.v.x * r, m_40.v.y * r, m_40.v.z * r, m_40.v.w * r);
            m_60 = t;
        }
    }
    D_0038EE60 = 0;
}
