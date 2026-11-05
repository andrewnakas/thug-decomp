extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

bool func_0020B490(void* params)
{
    int a = 0;
    func_001E7DE8(params, 0x174841BC, &a, 0);
    int b = 0;
    func_001E7DE8(params, 0x8E411006, &b, 0);
    return a == b;
}
