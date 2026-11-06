extern void* D_00392068;
extern char D_00370CA0[];
extern char D_00370798[];
extern char D_00370CB0[];

extern "C" void* func_002A6070(void* mgr);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void* func_00202EF8(void* o, unsigned int name);
extern "C" bool func_001E8A50(void* params, char* name, unsigned int* out, int required);

bool Cmd_00217020()
{
    void* o = func_002A6070(D_00392068);
    void* p = func_00202EF8(o, func_001F0D78(D_00370CA0));
    unsigned int v;
    func_001E8A50(p, D_00370798, &v, 1);
    return v != func_001F0D78(D_00370CB0);
}
