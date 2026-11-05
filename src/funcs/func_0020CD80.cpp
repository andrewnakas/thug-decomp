extern void* D_0038FC78;
struct Script_0020CD80 {
    char pad[0x18];
    void* m18;
};
extern "C" void* func_0022E368(void* mgr, void* params);
extern "C" void* func_00262488(void* o);
extern "C" void func_001E70C0(void* s, unsigned int id, void* v);

bool func_0020CD80(void* params, Script_0020CD80* script)
{
    void* o = func_0022E368(D_0038FC78, 0);
    void* s = script->m18;
    func_001E70C0(s, 0xF36C1878, func_00262488(o));
    return true;
}
