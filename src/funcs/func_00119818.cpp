class Anim_00119818 {
public:
    char pad0[0x18];
    float m_start;
    float m_time;
    float m_end;
    float m24;
    int m_reverse;
    int m_loop;
    bool IsDone();
};

bool Anim_00119818::IsDone()
{
    if (!m_loop) {
        if (!m_reverse) {
            return m_time == m_end;
        }
        return m_time == m_start;
    }
    return false;
}
