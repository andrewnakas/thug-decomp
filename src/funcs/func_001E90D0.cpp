struct Arr_001E90D0 {
    int m0;
    union {
        float one;
        float* many;
    } m4;
    int m8;
    int mC;
    void Set(int i, float v);
};

void Arr_001E90D0::Set(int i, float v)
{
    if (mC == 1) m4.one = v;
    else m4.many[i] = v;
}
