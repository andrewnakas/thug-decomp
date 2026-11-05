extern float D_0038E138;
extern int D_0038E148;
extern int D_0038E150;

extern "C" int func_001DED20();
extern "C" void func_001E34F8(float v);

extern "C" void func_001E0188(float v)
{
    if (func_001DED20())
        return;
    if (v > 100.0f || v < 0.0f)
        return;
    D_0038E138 = v;
    if (D_0038E148 && D_0038E150 == 1)
        func_001E34F8(v);
}
