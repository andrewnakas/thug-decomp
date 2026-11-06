/* fuzzy: 67.2 */
struct Vec_001C59B0 {
    float x, y, z, w;
    Vec_001C59B0() {}
    Vec_001C59B0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_001C59B0& operator-=(const Vec_001C59B0& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

struct Skater_001C59B0 {
    char pad0[0x30];
    Vec_001C59B0 m_pos;
    Vec_001C59B0 m_vel;
    char pad50[0x98 - 0x50];
    float m98;
    char pad9C[0xBC0 - 0x9C];
    int m_onPlane;
    char padBC4[0xBD0 - 0xBC4];
    Vec_001C59B0 m_normal;
    float m_planeD;
    float m_planeTop;
    Vec_001C59B0 ScaledNormal(float k) const
    {
        return Vec_001C59B0(m_normal.x * k, m_normal.y * k, m_normal.z * k, m_normal.w * k);
    }
};

extern "C" void* func_001E5548(unsigned int, int);
extern "C" bool func_001E7EB0(void*, unsigned int, float*, int);

static inline float GetPhysics_001C59B0(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

void func_001C59B0(Skater_001C59B0* sk)
{
    if (!sk->m_onPlane)
        return;
    if (sk->m_pos.y > sk->m_planeTop) {
        sk->m_onPlane = 0;
        return;
    }
    Vec_001C59B0& pos = sk->m_pos;
    float dist = sk->m_normal.x * sk->m_pos.x + sk->m_normal.y * sk->m_pos.y + sk->m_normal.z * sk->m_pos.z
        - sk->m_planeD;
    if (-GetPhysics_001C59B0(0xA20C43B7) < dist) {
        pos -= sk->ScaledNormal(GetPhysics_001C59B0(0x4D16F37D) * sk->m98);
        float dot = sk->m_vel.x * sk->m_normal.x + sk->m_vel.y * sk->m_normal.y + sk->m_vel.z * sk->m_normal.z;
        if (dot != 0.0f)
            sk->m_vel -= sk->ScaledNormal(dot);
    }
}
