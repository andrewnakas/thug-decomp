extern "C" int func_001DA880(void* p);
extern "C" char* func_001DA868(void* p);

extern "C" char* func_001DA7D8(void* p)
{
    if (func_001DA880(p))
        return func_001DA868(p) + 8;
    return func_001DA868(p);
}
