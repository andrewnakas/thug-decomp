struct Script_00221618 {
    char pad0[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_003718B0[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0022E050(void* mgr);
extern "C" void* func_002629B8(void* mgr, unsigned int id);
extern "C" void* func_00262990(void* mgr);
extern "C" int func_00261E18(void* obj, unsigned int id);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_00221618(void* params, Script_00221618* script)
{
    unsigned int id;
    unsigned int which;
    func_001E8398(params, 0, &id, 1);
    void* mgr = func_0022E050(D_0038FC78);
    void* obj;
    if (func_001E8398(params, 0x5B8AB877, &which, 0))
        obj = func_002629B8(mgr, which);
    else
        obj = func_00262990(mgr);
    int r = func_00261E18(obj, id);
    func_001E7268(script->m_params, D_003718B0, r);
    return true;
}
