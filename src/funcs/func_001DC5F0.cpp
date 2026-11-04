extern "C" float fabsf(float x);

struct Obj_001DC5F0 {
    float m_v[5];
    int m_type;
    float GetLargest();
};

float Obj_001DC5F0::GetLargest()
{
    unsigned int n = (m_type == 2) ? 5 : 2;
    float best = m_v[0];
    for (unsigned int i = 1; i < n; i++) {
        if (fabsf(best) < fabsf(m_v[i])) {
            best = m_v[i];
        }
    }
    return best;
}
