extern void* D_0038FC78;
extern char D_00374FF8[];

struct Skater_002535F8 {
    char pad[0x278];
    int m_flag;
};

struct Script_002535F8 {
    char pad[0x18];
    void* m18;
};

extern "C" Skater_002535F8* func_0022DD38(void* self);
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_002535F8(void* params, Script_002535F8* script)
{
    Skater_002535F8* s = func_0022DD38(D_0038FC78);
    if (s) {
        if (s->m_flag) func_001E7268(script->m18, D_00374FF8, 1);
        else func_001E7268(script->m18, D_00374FF8, 0);
        return true;
    }
    return false;
}
