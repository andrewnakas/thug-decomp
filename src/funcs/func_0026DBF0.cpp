extern char D_003913E8[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" int func_00263930(void* mgr);
extern "C" void* func_002637B0(void* mgr, int v);
extern "C" void func_0026D488(void* p);

struct Game_0026DBF0 {
    char pad[0x24];
    void* m24;
};

extern Game_0026DBF0* D_0038FC78;

bool Cmd_0026DBF0(void* params, void* script)
{
    void* mgr = D_0038FC78->m24;
    int v;
    if (!func_001E7E58(params, D_003913E8, &v, 0))
        v = func_00263930(mgr);
    func_0026D488(func_002637B0(mgr, v));
    return true;
}
