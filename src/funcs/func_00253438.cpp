extern void* D_0038FC78;
extern char D_00374FC8[];

struct Skater_00253438 {
    char pad[0x280];
    int m_flag;
};

struct Script_00253438 {
    char pad[0x18];
    void* m18;
};

extern "C" Skater_00253438* func_0022DD38(void* self);
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_00253438(void* params, Script_00253438* script)
{
    Skater_00253438* s = func_0022DD38(D_0038FC78);
    if (s) {
        if (s->m_flag) func_001E7268(script->m18, D_00374FC8, 1);
        else func_001E7268(script->m18, D_00374FC8, 0);
        return true;
    }
    return false;
}
