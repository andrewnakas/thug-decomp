extern int D_00388814;

static inline int GetMode_002189E8() { return D_00388814; }

extern "C" bool func_002189E8()
{
    if (GetMode_002189E8() == 1 || GetMode_002189E8() == 2 || GetMode_002189E8() == 3)
        return true;
    return false;
}
