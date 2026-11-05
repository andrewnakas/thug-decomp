extern void* D_0038FC78;
extern char D_00375028[];

struct Skater_002537A8 {
    char pad[0x288];
    float m_val;
};

struct Script_002537A8 {
    char pad[0x18];
    void* m18;
};

extern "C" Skater_002537A8* func_0022DD38(void* self);
extern "C" void func_001E7318(void* p, char* name, float v);

bool Cmd_002537A8(void* params, Script_002537A8* script)
{
    Skater_002537A8* s = func_0022DD38(D_0038FC78);
    if (s) {
        func_001E7318(script->m18, D_00375028, s->m_val);
        return true;
    }
    return false;
}
