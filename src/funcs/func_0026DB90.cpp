extern char D_003913E8[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_002637B0(void* mgr, int v);
extern "C" void func_0026D618(void* p, void* params, void* script);

struct Game_0026DB90 {
    char pad[0x24];
    void* m24;
};

extern Game_0026DB90* D_0038FC78;

void Cmd_0026DB90(void* params, void* script)
{
    int v;
    func_001E7E58(params, D_003913E8, &v, 1);
    func_0026D618(func_002637B0(D_0038FC78->m24, v), params, script);
}
