extern "C" int func_001E3BE8();
extern "C" void func_001E34F8(float x);

extern "C" bool func_001DF458(float x)
{
    if (!func_001E3BE8())
        return false;
    func_001E34F8(x);
    return true;
}
