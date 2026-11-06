extern "C" int func_001DED40(int a);
extern "C" int func_001DEDE0(int a, int b);
extern "C" int func_001E3A90(int i);

extern "C" int func_001DF8E8(int a)
{
    if (func_001DED40(a))
        return 0;
    int i = func_001DEDE0(a, 1);
    if (i < 0)
        return 0;
    func_001E3A90(i);
    func_001E3A90(i);
    /* no return value: the game sets none here either (falls off the end of an int function, original bug) */
}
