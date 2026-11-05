extern float D_0038E1E8;
extern "C" int func_0033EBE0(float f);
extern "C" void func_001E34F0(int v);

void Set_001E1800(float f)
{
    D_0038E1E8 = f;
    func_001E34F0(func_0033EBE0(f));
}
