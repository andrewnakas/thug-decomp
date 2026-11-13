/* fuzzy: 79.5 */
typedef int qword __attribute__((mode(TI)));

struct V_001C2500 {
    float x, y, z, w;
};

union Vec_001C2500 {
    qword q;
    V_001C2500 v;
    Vec_001C2500() {}
    Vec_001C2500(float x, float y, float z, float w)
    {
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
    }
    float Dot(const Vec_001C2500& b) const { return v.x * b.v.x + v.y * b.v.y + v.z * b.v.z; }
    Vec_001C2500 operator*(float s) const { return Vec_001C2500(v.x * s, v.y * s, v.z * s, v.w * s); }
    Vec_001C2500 operator+(const Vec_001C2500& b) const
    {
        return Vec_001C2500(v.x + b.v.x, v.y + b.v.y, v.z + b.v.z, v.w + b.v.w);
    }
};

extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int flag);

static inline float Param_001C2500(unsigned int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &f, 1);
    return f;
}

struct Obj_001C2500 {
    char m_pad0[0x40];
    Vec_001C2500 m_40;
    char m_pad1[0x98 - 0x50];
    float m_98;
    char m_pad2[0xA0 - 0x9C];
    Vec_001C2500 m_A0;
    float m_B0;
    char m_pad3[0xB70 - 0xB4];
    Vec_001C2500 m_B70;
    Vec_001C2500 m_B80;
    float m_B90;
    void Update();
};

void Obj_001C2500::Update()
{
    if (m_B90 != 0.0f) {
        float t = m_B90 - m_98;
        if (t < 0.0f) {
            t = 0.0f;
        }
        m_B90 = t;
        return;
    }
    Vec_001C2500& vel = m_40;
    vel.v.x -= m_B80.v.x;
    vel.v.y -= m_B80.v.y;
    vel.v.z -= m_B80.v.z;
    vel.v.w -= m_B80.v.w;
    Vec_001C2500 side(-m_B70.v.z, 0.0f, m_B70.v.x, 1.0f);
    float scale = m_B0;
    float sideTarget = Param_001C2500(0x896C8888) * scale * (m_A0.v.x * side.v.x + m_A0.v.y * side.v.y + m_A0.v.z * side.v.z);
    float sideSpeed = (m_40.v.x * side.v.x + m_40.v.y * side.v.y + m_40.v.z * side.v.z);
    sideSpeed += (sideTarget - sideSpeed) * (Param_001C2500(0xF085443B) * m_98);
    float fwdTarget = Param_001C2500(0x896C8888) * scale * (m_A0.v.x * m_B70.v.x + m_A0.v.y * m_B70.v.y + m_A0.v.z * m_B70.v.z);
    float fwdSpeed = (m_40.v.x * m_B70.v.x + m_40.v.y * m_B70.v.y + m_40.v.z * m_B70.v.z);
    if (!(0.0f <= fwdTarget && fwdTarget < fwdSpeed)) {
        if (fwdTarget < 0.0f && 0.0f < fwdSpeed) {
            fwdTarget += fwdSpeed;
        }
        fwdSpeed += (fwdTarget - fwdSpeed) * (Param_001C2500(0xF085443B) * m_98);
    }
    m_40 = m_B70 * fwdSpeed + side * sideSpeed;
    vel.v.x += m_B80.v.x;
    vel.v.y += m_B80.v.y;
    vel.v.z += m_B80.v.z;
    vel.v.w += m_B80.v.w;
}
