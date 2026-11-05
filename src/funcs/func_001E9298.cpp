union Val_001E9298 {
    int i;
    float f;
    int* pi;
    float* pf;
};
struct Arr_001E9298 {
    int m0;
    Val_001E9298 m4;
    int m8;
    int mC;
    float GetFloat(int i);
};

float Arr_001E9298::GetFloat(int i)
{
    if (mC == 1) {
        if (m8 == 2)
            return m4.f;
        return (float)m4.i;
    }
    if (m8 == 2)
        return m4.pf[i];
    return (float)m4.pi[i];
}
