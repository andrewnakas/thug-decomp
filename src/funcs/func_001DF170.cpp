extern "C" int func_001DED20();
extern "C" int func_001E37D8(void* p);
extern "C" void func_001E34F8(float v);

int func_001DF170(void* p, float v)
{
    if (func_001DED20())
        return 0;
    if (!func_001E37D8(p))
        return 0;
    func_001E34F8(v);
    return 1;
}
