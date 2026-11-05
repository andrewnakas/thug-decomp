extern float D_0038E138;
extern "C" int func_001DED20(void* p);
extern "C" bool func_001DF458(float x);

extern "C" bool func_001DFA30(void* p, float x)
{
    if (func_001DED20(p))
        return false;
    if (x < 0.0f)
        x = D_0038E138;
    return func_001DF458(x);
}
