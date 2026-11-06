extern "C" int func_001E9218(void* self, int i);

struct Arr_001E91C0 {
    int m0;
    int* m4;
    int m8;
    int mC;
    int Get(int i);
};

int Arr_001E91C0::Get(int i)
{
    if (m8 == 4)
        return func_001E9218(this, i);
    if (mC == 1)
        return (int)m4;
    return m4[i];
}
