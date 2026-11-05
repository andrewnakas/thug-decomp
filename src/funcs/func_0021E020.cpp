extern char D_0038F848[];
struct Obj_0021E020 {
    char pad[0x18];
    int m18;
    char pad2[0x31C - 0x1C];
    int m31C;
};
struct Script_0021E020 {
    char pad[0x18];
    void* m18;
    char pad2[0xBC - 0x1C];
    Obj_0021E020* mBC;
};
extern "C" void func_001E73C8(void* s, void* name, int v);

bool func_0021E020(void* params, Script_0021E020* script)
{
    Obj_0021E020* o = script->mBC;
    if (!o)
        return false;
    if (!o->m31C)
        return false;
    func_001E73C8(script->m18, D_0038F848, o->m18);
    return true;
}
