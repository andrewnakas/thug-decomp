struct Obj_001FE388 {
    int m_avg;
    int m_vals[10];
    unsigned int m_idx;
    void Add(int v);
};

void Obj_001FE388::Add(int v)
{
    int sum = 0;
    int n = 0;
    m_vals[m_idx] = v;
    m_idx = (m_idx + 1) % 10;
    for (int i = 0; i < 10; i++) {
        if (m_vals[i]) {
            sum += m_vals[i];
            n++;
        }
    }
    if (n > 0)
        m_avg = sum / n;
}
