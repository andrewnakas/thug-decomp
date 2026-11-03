typedef unsigned int u128 __attribute__((mode(TI)));

union Vec4 {
    float v[4];
    u128 q;
};

struct Mat {
    Vec4 row[4];
};

struct State {
    Mat m_mat;
    Vec4 m_pos;
    float m50;
    float m54;
};

struct Source {
    char pad[0x28];
    float m28;
    char pad2[0x30 - 0x2C];
    Vec4 m30;
    Mat m40;
    float m80;
    void GetState(State* out) const;
};

void Source::GetState(State* out) const
{
    out->m_mat = m40;
    out->m_pos = m30;
    out->m50 = m80;
    out->m54 = m28;
}
