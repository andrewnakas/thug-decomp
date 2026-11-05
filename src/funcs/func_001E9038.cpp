struct Arr_001E9038 {
    int m0;
    union {
        float one;
        float* many;
    } m4;
    int m8;
    int mC;
    float* Data();
};

float* Arr_001E9038::Data()
{
    if (mC == 1) return &m4.one;
    return m4.many;
}
