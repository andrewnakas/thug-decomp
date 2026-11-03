struct Obj119890 {
    char pad[0x24];
    float m_rate;
    float GetPerSecond() const;
};

float Obj119890::GetPerSecond() const
{
    return m_rate * 60.0f;
}
