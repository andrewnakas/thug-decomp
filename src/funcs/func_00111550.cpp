struct Req_00111550 {
    int m_a;
    int m_b;
    int m_c;
    int m_d;
};

class Queue_00111550 {
public:
    int m0[16];
    Req_00111550 m_reqs[16];
    int m_count;
    Req_00111550* Find(int a);
};

Req_00111550* Queue_00111550::Find(int a)
{
    for (int i = 0; i < m_count; i++) {
        if (m_reqs[i].m_a == a) {
            return &m_reqs[i];
        }
    }
    return 0;
}
