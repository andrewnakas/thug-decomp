extern void* D_00392068;
extern char D_00378BB0[];
extern char D_00378328[];
extern char D_00378648[];
extern "C" void* func_002A6070(void* net);
extern "C" int func_001F0D78(char* s);
extern "C" int func_00203018(void* p, int a, int b);

bool Cmd_002AB048(void* params, void* script)
{
    void* p = func_002A6070(D_00392068);
    int a = func_001F0D78(D_00378BB0);
    int b = func_001F0D78(D_00378328);
    return func_00203018(p, a, b) == func_001F0D78(D_00378648);
}
