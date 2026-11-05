extern "C" int func_001DA880(void* p);
extern "C" char* func_001DA868(void* p);

char* func_001DA820(void* p)
{
    if (func_001DA880(p))
        return func_001DA868(p);
    return func_001DA868(p) + 8;
}
