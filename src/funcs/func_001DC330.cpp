struct Obj_001DC330 {
    char pad[0x10];
    float m10;
    float m14;
    float Get(float t, int clamp);
};

float Obj_001DC330::Get(float t, int clamp)
{
    float to;
    if (m14 != 0.0f || m10 != 100.0f)
        t = m14 + (m10 - m14) * t * 0.01f;
    to = m10;
    if (clamp && to < t)
        t = to;
    return t;
}
