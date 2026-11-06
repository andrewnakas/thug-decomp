struct Mgr_0021F378 {
    char m_pad0[0x24];
    void* m24;
};

extern Mgr_0021F378* D_0038FC78;
extern char D_0038F868[];
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" int func_00263930(void* p);
extern "C" void func_00230330(void* p, int v);

bool Cmd_0021F378(void* params, void* script)
{
    void* obj = D_0038FC78->m24;
    int v;
    if (!func_001E88F8(params, D_0038F868, &v, 0))
        v = func_00263930(obj);
    func_00230330(D_0038FC78, v);
    return true;
}
