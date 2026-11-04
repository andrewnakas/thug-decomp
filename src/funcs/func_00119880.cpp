struct Obj119880 {
    char pad[0x24];
    float m_rate;
    void SetPerSecond(float v);
};

void Obj119880::SetPerSecond(float v)
{
    m_rate = v * (1.0f / 60.0f);
}
