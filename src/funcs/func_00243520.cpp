struct Game_00243520 {
    char pad0[0x48];
    int m_48;
    int m_4C;
};

extern "C" Game_00243520* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool func_00243520(void* params)
{
    Game_00243520* game = func_00240850();
    int a = game->m_48;
    int b = game->m_4C;
    func_001E7DE8(params, 0x067E4AD1, &a, 0);
    func_001E7DE8(params, 0x3D836C96, &b, 0);
    game->m_48 = a;
    game->m_4C = b;
    return true;
}
