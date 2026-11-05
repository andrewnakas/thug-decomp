extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void func_001DEF68(int v);
extern "C" void func_001DEF18(int v);

bool func_0020EAF0(void* params, void* script)
{
    int v;
    if (func_001E8398(params, 0, &v, 0))
        func_001DEF68(v);
    else
        func_001DEF18(-1);
    return true;
}
