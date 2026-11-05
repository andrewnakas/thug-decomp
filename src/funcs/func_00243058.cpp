extern char D_0038FF20[];

struct Item_00243058;
extern "C" void* func_00240850();
extern "C" int func_0023BF98(void* mgr, int a);
extern "C" Item_00243058* func_0023BB50(void* mgr, int id);
extern "C" int func_00246258(Item_00243058* it);
extern "C" void func_001E73C8(void* params, char* name, int value);

struct Script_00243058 {
    char m_pad[0x18];
    void* m_params;
};

bool Cmd_00243058(void* params, Script_00243058* script)
{
    void* mgr = func_00240850();
    if (!mgr)
        return false;
    int id = func_0023BF98(mgr, 1);
    if (id == -1)
        return false;
    Item_00243058* it = func_0023BB50(mgr, id);
    if (!it)
        return false;
    int v = func_00246258(it);
    func_001E73C8(script->m_params, D_0038FF20, v);
    return true;
}
