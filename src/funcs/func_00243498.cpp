struct Game_00243498 {
    char pad0[0x48];
    int m_48;
    int m_4C;
};

struct Array_00243498 {
    char pad0[0xC];
    int m_size;
};

struct Script_00243498 {
    char pad0[0x18];
    void* m_params;
};

extern "C" Game_00243498* func_00240850();
extern "C" Array_00243498* func_001E55B8(unsigned int name, int a);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool func_00243498(void* params, Script_00243498* script)
{
    Game_00243498* game = func_00240850();
    int a = game->m_48;
    int b = game->m_4C;
    int n = func_001E55B8(0xB892776F, 1)->m_size;
    func_001E7200(script->m_params, 0xF884773C, (a < n) ? a : n - 1);
    func_001E7200(script->m_params, 0xAF1575EB, b);
    return true;
}
