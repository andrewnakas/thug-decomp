extern float D_0038E138;
extern int D_0038E150;
extern "C" int func_001DED20();
extern "C" void func_001E3958(int v);
extern "C" int func_001DF170(void* p, float f);

void func_001DFF20(void* p, float f)
{
    if (func_001DED20())
        return;
    func_001E3958(0);
    if (f < 0.0f)
        f = D_0038E138;
    func_001DF170(p, f);
    D_0038E150 = 1;
}
