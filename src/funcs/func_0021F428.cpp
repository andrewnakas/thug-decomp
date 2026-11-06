struct Mgr_0021F428 {
    char m_pad0[0x24];
    void* m24;
};

extern Mgr_0021F428* D_0038FC78;
extern char D_0038F870[];

extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" void* func_0022E358(Mgr_0021F428* mgr);
extern "C" int func_0024F908(void* obj, unsigned int key);
extern "C" int func_0024F860(void* obj);
extern "C" void func_00263960(void* obj, int v, int n);

bool Cmd_0021F428(void* params)
{
    int v;
    func_001E88F8(params, D_0038F870, &v, 1);
    if (!func_0024F908(func_0022E358(D_0038FC78), 0x1DED1EA4) && !func_0024F860(func_0022E358(D_0038FC78)))
        return true;
    func_00263960(D_0038FC78->m24, v, -1);
    return true;
}
