struct Timer_0010FAC8 {
    float m_scale;
    float m_frame;
    double m_dscale;
    int m_flags[4];
    int m20;
    int m24;
    int m28;
};

extern Timer_0010FAC8 D_00397378;
extern int D_00388830;

extern "C" double func_0010FAC8()
{
    return D_00397378.m_dscale / (float)D_00388830;
}
