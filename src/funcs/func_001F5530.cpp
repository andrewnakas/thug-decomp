extern "C" int func_001F5430(void* p);
extern "C" int func_0032A670(void* p);

extern "C" bool func_001F5530(void* p)
{
    bool r = false;
    if (!func_001F5430(p))
        r = func_0032A670(p) != 0;
    return r;
}
