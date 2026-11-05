extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" void func_001E1000(int v);

extern "C" int func_0020E360(void* params)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_001E1000(v == 0);
    return 1;
}
