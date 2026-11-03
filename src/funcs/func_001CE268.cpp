struct Blend {
    char pad[0x1C];
    int m1C;
    int m20;
    float m24;
    int m28;
    int m2C;
    void Reset();
};

void Blend::Reset()
{
    m24 = 1.0f;
    m28 = 0;
    m2C = 0;
    m1C = 0;
    m20 = 0;
}
