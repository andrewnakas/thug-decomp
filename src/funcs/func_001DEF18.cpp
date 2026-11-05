extern "C" int func_001DED40();
extern "C" void func_001E39A8();
extern "C" void func_001E3978(int v, int b);

void func_001DEF18(int v)
{
    if (func_001DED40())
        return;
    if (v == -1)
        func_001E39A8();
    else
        func_001E3978(v, 1);
}
