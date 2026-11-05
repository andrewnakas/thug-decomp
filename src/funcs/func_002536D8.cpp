extern void* D_0038FC78;
extern char D_00375010[];

struct Skater_002536D8 {
    char pad[0x27C];
    int m_flag;
};

struct Script_002536D8 {
    char pad[0x18];
    void* m18;
};

extern "C" Skater_002536D8* func_0022DD38(void* self);
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_002536D8(void* params, Script_002536D8* script)
{
    Skater_002536D8* s = func_0022DD38(D_0038FC78);
    if (s) {
        if (s->m_flag) func_001E7268(script->m18, D_00375010, 1);
        else func_001E7268(script->m18, D_00375010, 0);
        return true;
    }
    return false;
}
