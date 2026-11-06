class Evt_00118268 {
public:
    int m0[6];
    int m_frame;
    int InRange(float from, float to, int inclusive);
};

int Evt_00118268::InRange(float from, float to, int inclusive)
{
    if (inclusive) {
        if (from < to) {
            float f = m_frame;
            return from <= f && f <= to;
        } else {
            float f = m_frame;
            return f <= from && to <= f;
        }
    } else {
        if (from < to) {
            float f = m_frame;
            return from <= f && f < to;
        } else {
            float f = m_frame;
            return f <= from && to < f;
        }
    }
}
