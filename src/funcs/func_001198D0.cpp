class Anim_001198D0 {
public:
    char pad0[0x18];
    float m_start;
    float m_time;
    float m_end;
    float m_speed;
    int m_reverse;
    int m_loop;
    int m30;
    int m_mode;
    void Set(float from, float to, float unused, float speed, int mode, int loop);
};

void Anim_001198D0::Set(float from, float to, float unused, float speed, int mode, int loop)
{
    m_start = from < to ? from : to;
    m_end = to > from ? to : from;
    m_time = from;
    m_speed = speed * (1.0f / 60.0f);
    int dir = to <= from ? -1 : 0;
    m_mode = mode;
    m_reverse = dir;
    m_loop = loop;
    m30 = 0;
}
