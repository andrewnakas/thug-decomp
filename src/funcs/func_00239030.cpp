struct Entry_00239030 {
    int m_time;
    unsigned int m_trick;
    unsigned int m_id;
};

struct Game_00239030 {
    char pad[0x24];
    void* m_24;
    char pad28[0x6C];
    Entry_00239030 m_entries[64];
};

extern Game_00239030* D_0038FC78;

struct Obj_00239030 {
    short pad0;
    short m_id;
};

extern "C" void* func_0022E358(Game_00239030* g);
extern "C" bool func_0024F908(void* a, unsigned int key);
extern "C" bool func_00263A00(void* a, unsigned int id, int b);
extern "C" void func_00263960(void* a, unsigned int id, int b);
extern "C" void* func_0022DF08(Game_00239030* g, int id);
extern "C" void func_00184BC0(void* skater, unsigned int trick, int a, int b, int c, int d);

void func_00239030(Obj_00239030* obj, int from, int to)
{
    Game_00239030* game = D_0038FC78;
    if (func_0024F908(func_0022E358(game), 0x1DED1EA4)) {
        for (int i = 0; i < 64; i++) {
            int t = game->m_entries[i].m_time;
            unsigned int id = game->m_entries[i].m_id;
            unsigned int trick = game->m_entries[i].m_trick;
            if (t && from < t && t <= to && !func_00263A00(game->m_24, id, -1)) {
                func_00263960(game->m_24, id, -1);
                func_00184BC0(func_0022DF08(game, obj->m_id), trick, -1, 0, 0, 0);
            }
        }
    }
}
