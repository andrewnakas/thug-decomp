struct Fog_00130510 {
    float m_start;
    float m_end;
    float m_scaleX;
    float m_scaleY;
    float m_offX;
    float m_offY;
};

struct Entry_00130510 {
    float m0;
    char pad4[0x1C];
    float m20;
    float m24;
    char pad28[0xC];
    float m34;
    float m38;
    char pad3C[0x14];
    void SetOffset(float x, float y)
    {
        m20 = x;
        m24 = y;
    }
    void SetScale(float x, float y)
    {
        m34 = x;
        m38 = y;
    }
};

extern "C" unsigned int func_0010FC30();

class C_00130510 {
public:
    Entry_00130510 m_entries[16];
    Fog_00130510 m_target;
    Fog_00130510 m_cur;
    unsigned int m_lastTime;
    unsigned int m_remaining;
    void Update();
};

void C_00130510::Update()
{
    unsigned int now = func_0010FC30();
    float t = (float)(now - m_lastTime) / (float)m_remaining;
    if (now - m_lastTime < m_remaining)
        m_remaining = m_remaining - (now - m_lastTime);
    else
        m_remaining = 0;
    m_lastTime = now;
    if (m_remaining) {
        m_cur.m_start += (m_target.m_start - m_cur.m_start) * t;
        m_cur.m_end += (m_target.m_end - m_cur.m_end) * t;
        m_cur.m_scaleX += (m_target.m_scaleX - m_cur.m_scaleX) * t;
        m_cur.m_scaleY += (m_target.m_scaleY - m_cur.m_scaleY) * t;
        m_cur.m_offX += (m_target.m_offX - m_cur.m_offX) * t;
        m_cur.m_offY += (m_target.m_offY - m_cur.m_offY) * t;
    } else {
        m_cur = m_target;
    }
    for (int i = 0; i < 16; i++) {
        float f = (float)i * 0.0625f;
        Entry_00130510* e = &m_entries[i];
        e->SetOffset(m_cur.m_offX * f, m_cur.m_offY * f);
        e->SetScale((m_cur.m_scaleX - 1.0f) * f + 1.0f, (m_cur.m_scaleY - 1.0f) * f + 1.0f);
        e->m0 = (m_cur.m_start + (m_cur.m_end - m_cur.m_start) * f) * 0.0625f;
    }
}
