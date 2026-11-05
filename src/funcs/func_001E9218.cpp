struct Arr_001E9218 {
    int m0;
    int* m4;
    int m8;
    int mC;
    int Get(int i);
};
extern "C" int func_001E91C0(Arr_001E9218* self, int i);

int Arr_001E9218::Get(int i)
{
    if (m8 == 3)
        return func_001E91C0(this, i);
    if (mC == 1)
        return (int)m4;
    return m4[i];
}
