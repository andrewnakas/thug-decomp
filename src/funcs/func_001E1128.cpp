extern int D_0038881C;
extern "C" bool func_001DED40();
extern "C" int func_001E5628(unsigned int name, int a);
extern "C" int func_001E3C58(int port);

extern "C" bool func_001E1128()
{
    if (func_001DED40())
        return false;
    if (!D_0038881C && !func_001E5628(0x62DF9442, 0))
        return true;
    for (int i = 0; i < 3; i++) {
        if (func_001E3C58(i) == 1)
            return true;
    }
    return false;
}
