struct Mover {
    char pad[0x20];
    int m_active;
    float m24;
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    void Start(float a, float b, float time, float d);
};

void Mover::Start(float a, float b, float time, float d)
{
    m_active = 1;
    m38 = a;
    m34 = b;
    if (time > 0.0f) {
        m40 = (a - m2C) / time;
        m3C = (b - m28) / time;
    }
    m44 = time;
    m24 = d;
}
