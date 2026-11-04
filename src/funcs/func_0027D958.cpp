extern "C" float sqrtf(float);
extern "C" float func_002032A0(unsigned int name, int a);

struct Vec_0027D958 {
    float x, y, z, w;
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Body_0027D958 {
    char pad0[0xB0];
    Vec_0027D958 m_vel;
};

struct Obj_0027D958 {
    char pad0[0xC];
    Body_0027D958* m_body;
    char pad10[0x64];
    float m_74;

    bool IsSlow();
};

bool Obj_0027D958::IsSlow()
{
    float speed = m_body->m_vel.Length();
    if (speed < func_002032A0(0x62A1FA03, 0) && m_74 < func_002032A0(0xC3527EF2, 0))
        return true;
    return false;
}
