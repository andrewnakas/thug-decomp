extern char D_0038FD20[];
extern "C" int func_001E8A50(void* params, char* name, void** out, int req);
extern "C" void func_002304D0(void* v, void* script);

extern "C" void func_00230490(void* params, void* script)
{
    void* v;
    func_001E8A50(params, D_0038FD20, &v, 1);
    func_002304D0(v, script);
}
