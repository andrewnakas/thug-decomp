struct Game_0021EAA0 {
    char pad[0x3A0];
    void* m3A0;
};

extern Game_0021EAA0* D_0038FC78;
extern char D_0038F858[];
extern char D_0038F860[];

extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_001E8A30(void* params, unsigned int name, int* out, int req);
extern "C" bool func_0025F620(void* mgr, int a);
extern "C" void func_0025F460(void* mgr);
extern "C" void func_0025F930(void* mgr, int v);

bool Cmd_0021EAA0(void* params, void* script)
{
    void* mgr = D_0038FC78->m3A0;
    if (func_001E87B8(params, D_0038F858))
        return func_0025F620(mgr, 0);
    if (func_001E87B8(params, D_0038F860)) {
        func_0025F460(mgr);
        return true;
    }
    int v = 0;
    func_001E8A30(params, 0xA1DC81F9, &v, 1);
    func_0025F930(mgr, v);
    return true;
}
