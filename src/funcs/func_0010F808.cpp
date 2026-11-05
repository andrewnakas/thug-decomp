struct Timer_0010F808 {
    float m_scale;
    float m_frame;
    double m_dscale;
    int m_flags[4];
    int m20;
    int m24;
    int m28;
};

extern Timer_0010F808 D_00397378;
extern Timer_0010F808 D_003973A8;
extern long D_00388DA0;
extern volatile int D_00388D7C;

extern "C" void func_0010F808()
{
    D_00397378.m_scale = 1.0f;
    D_00397378.m_dscale = 1.0;
    D_00397378.m_frame = 1.0f / 60.0f;
    for (int i = 0; i < 4; i++) {
        D_00397378.m_flags[i] = 1;
    }
    D_00397378.m20 = 0;
    D_00397378.m24 = 0;
    D_00397378.m28 = 0;
    D_003973A8 = D_00397378;
    D_00388DA0 = 0;
    D_00388D7C = 0;
}
