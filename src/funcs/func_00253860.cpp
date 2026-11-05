extern void* D_0038FC78;
extern char D_00375038[];

struct Skater_00253860 {
    char pad[0x290];
    int m_val;
};

struct Script_00253860 {
    char pad[0x18];
    void* m18;
};

extern "C" Skater_00253860* func_0022DD38(void* self);
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_00253860(void* params, Script_00253860* script)
{
    Skater_00253860* s = func_0022DD38(D_0038FC78);
    if (s) {
        func_001E7268(script->m18, D_00375038, s->m_val);
        return true;
    }
    return false;
}
