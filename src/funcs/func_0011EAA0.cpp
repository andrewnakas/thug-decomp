struct Keys_0011EAA0 {
    char pad0[0x408];
    float m_times[1];
};

class Track_0011EAA0 {
public:
    int m0;
    int m4;
    Keys_0011EAA0* m_keys;
    unsigned int m_cur;
    unsigned int m_last;
    void Seek(float t);
};

void Track_0011EAA0::Seek(float t)
{
    if (m_keys) {
        for (unsigned int i = 0; i <= m_last; i++) {
            if (t < m_keys->m_times[i]) {
                m_cur = i;
                return;
            }
        }
    }
    m_cur = m_last;
}
