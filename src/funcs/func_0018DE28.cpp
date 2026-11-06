extern "C" int func_0010FC30();
extern "C" float func_00341068(float x);

class Chan_0018DE28 {
public:
    int m_active;
    int m_hold;
    float m_duration;
    int m_start;
    float m_from;
    float m_delta;
    int m_curve;

    float Update();
};

float Chan_0018DE28::Update()
{
    float result = 0.0f;
    if (!m_active) {
        return result;
    }
    float t = (unsigned int)(func_0010FC30() - m_start);
    float dur = m_duration;
    if (t > dur) {
        if (m_hold) {
            result = m_from + m_delta;
        } else {
            m_active = 0;
        }
    } else if (m_curve != 0) {
        float f;
        if (m_curve < 0) {
            f = 1.0f - func_00341068(1.5707964f - t * 1.5707964f / dur);
        } else {
            f = func_00341068(t * 1.5707964f / dur);
            int i = m_curve - 1;
            if (i > 0) {
                do {
                    i--;
                    f *= f;
                } while (i != 0);
            }
        }
        result = m_from + f * m_delta;
    } else {
        result = m_from + t * m_delta / dur;
    }
    return result;
}
