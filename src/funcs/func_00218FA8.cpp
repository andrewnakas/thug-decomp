struct Sub_00218FA8 {
    char pad[0x18];
    void* m18;
};
struct Script_00218FA8 {
    char pad[0x18];
    void* m18;
    char pad1C[0xBC - 0x1C];
    Sub_00218FA8* mBC;
};

extern char D_00370EF8[];
extern "C" void func_001E73C8(void* s, char* name, void* v);

extern "C" bool func_00218FA8(void* params, Script_00218FA8* script)
{
    if (!script->mBC)
        return false;
    if (!script->mBC->m18)
        return false;
    func_001E73C8(script->m18, D_00370EF8, script->mBC->m18);
    return true;
}
