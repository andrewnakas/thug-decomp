struct Ent_0010F7C0 {
    int m0;
    int m4;
    int m_a;
    int m_b;
};

class Tab_0010F7C0 {
public:
    int m0[4];
    int m_count;
    int m14;
    Ent_0010F7C0 m_ents[1];
    int Has(int a, int b);
};

int Tab_0010F7C0::Has(int a, int b)
{
    for (int i = 0; i < m_count; i++) {
        if (m_ents[i].m_a == a && m_ents[i].m_b == b) {
            return 1;
        }
    }
    return 0;
}
