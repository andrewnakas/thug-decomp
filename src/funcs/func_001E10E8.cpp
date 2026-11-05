extern "C" int func_001DED40();
extern "C" int func_001E3C58(void* p);

bool func_001E10E8(void* p)
{
    if (func_001DED40())
        return false;
    return func_001E3C58(p) == 1;
}
