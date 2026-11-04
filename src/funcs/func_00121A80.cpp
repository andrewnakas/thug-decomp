extern "C" void func_001E8A30(void* params, unsigned int name, int* out, int required);

int GetParam121A80(void* params)
{
    int v;
    func_001E8A30(params, 0x4BB2084E, &v, 1);
    return v;
}
