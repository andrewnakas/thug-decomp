// qsort-style comparison of two floats: -1, 0 or 1.
extern "C" int func_00161218(const float* a, const float* b)
{
    return *a >= *b ? *a > *b : -1;
}
