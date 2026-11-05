struct Obj_0011A0E8;
extern "C" int func_0011A210(Obj_0011A0E8* self);

struct Obj_0011A0E8 {
    char pad[0x54];
    float m_rate;
    float m_scale;
    float GetValue();
};

float Obj_0011A0E8::GetValue()
{
    switch (func_0011A210(this)) {
    case 0:
        return 0.0f;
    case 2:
        return 1.0f;
    case 1:
        return m_rate * m_scale;
    }
    return 0.0f;
}
