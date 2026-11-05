extern "C" void* func_00203278();
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E53A0(unsigned int id, int def);

int func_00203300(unsigned int id, int def)
{
    int v;
    if (func_001E7DE8(func_00203278(), id, &v, 0))
        return v;
    return func_001E53A0(id, def);
}
