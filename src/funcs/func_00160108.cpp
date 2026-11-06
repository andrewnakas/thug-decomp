struct Res_00160108 {
    float m0;
    float m4[4];
    float m14;
    char m18;
};

extern "C" Res_00160108 func_001600A0(void* a, void* b);

float func_00160108(void* a, void* b)
{
    Res_00160108 r = func_001600A0(a, b);
    return r.m14 - (r.m4[0] * r.m4[0] + r.m4[1] * r.m4[1] + r.m4[2] * r.m4[2] + r.m4[3] * r.m4[3]) / r.m0;
}
