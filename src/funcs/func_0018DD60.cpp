struct Chan_0018DD60 {
    int m_active;
    char pad4[0x18];
};

extern "C" float func_0018DE28(Chan_0018DD60* c);

class Track_0018DD60 {
public:
    Chan_0018DD60 m_chans[6];
    int m_active;

    float Update();
};

float Track_0018DD60::Update()
{
    float sum = 0.0f;
    if (m_active) {
        m_active = 0;
        Chan_0018DD60* c = m_chans;
        for (int i = 0; i < 6; i++, c++) {
            if (c->m_active) {
                m_active = 1;
                sum += func_0018DE28(c);
            }
        }
    }
    return sum;
}
