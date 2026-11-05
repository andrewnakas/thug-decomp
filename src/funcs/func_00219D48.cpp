extern "C" int func_001E8248(void* params, unsigned int name, void** out, int required);

bool Has_00219D48(void* params)
{
    void* v = 0;
    return func_001E8248(params, 0, &v, 0) != 0;
}
