class Anim_001197A8;
extern "C" void func_001197F0(Anim_001197A8* self);

class Anim_001197A8 {
public:
    char pad0[0x1C];
    float m_time;
    float m20;
    float m_speed;
    void Skip(float dt);
};

void Anim_001197A8::Skip(float dt)
{
    float s = m_speed;
    m_speed = 0.0f;
    m_time += dt;
    func_001197F0(this);
    m_speed = s;
}
