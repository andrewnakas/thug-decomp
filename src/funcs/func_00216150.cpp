extern "C" int func_001E88D8(void* params, unsigned int id, int* out, int req);

bool func_00216150(void* params)
{
    int v = 0;
    func_001E88D8(params, 0, &v, 0);
    return v != 0;
}
