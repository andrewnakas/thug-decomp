extern char* D_0038E27C;
extern char* D_0038E278;
extern "C" char* func_0031F700(int size);

char* func_001E34A0()
{
    if (!D_0038E27C) {
        char* v = func_0031F700(0x90040);
        D_0038E27C = v;
        D_0038E278 = v - (((int)v & 0x3F) - 0x40);
        if (!v)
            return 0;
    }
    return D_0038E278;
}
