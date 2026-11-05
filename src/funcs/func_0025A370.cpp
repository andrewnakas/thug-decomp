struct V_0025A370 {
    float x, y, z, w;
};

struct C_0025A370 {
    char m_pad[0x410];
    int m410;
    int m414;
    int m418;
    int m41C;
    V_0025A370 m420;
    int m430;
    int m434;
    void Reset();
};

static inline void Set_0025A370(V_0025A370* v)
{
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
    v->w = 1.0f;
}

void C_0025A370::Reset()
{
    m410 = 0;
    m414 = 0;
    m418 = 0;
    Set_0025A370(&m420);
    m430 = 0;
    m434 = 0;
}
