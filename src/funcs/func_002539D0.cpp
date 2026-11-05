extern void* D_0038FC78;
extern char D_00375058[];

struct Skater_002539D0 {
    char pad[0x294];
    int m_val;
};

struct Script_002539D0 {
    char pad[0x18];
    void* m18;
};

extern "C" Skater_002539D0* func_0022DD38(void* self);
extern "C" void func_001E7268(void* p, char* name, int v);

bool Cmd_002539D0(void* params, Script_002539D0* script)
{
    Skater_002539D0* s = func_0022DD38(D_0038FC78);
    if (s) {
        func_001E7268(script->m18, D_00375058, s->m_val);
        return true;
    }
    return false;
}
