struct Skater_0021E1B0 {
    char m_pad[0x31C];
    int m_local;
};

struct Game_0021E1B0 {
    char m_pad[0x39C];
    void* m_cutscenes;
};

extern Game_0021E1B0* D_0038FC78;
extern char D_003716F8[];
extern char D_00371728[];

extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" Skater_0021E1B0* func_00184D70(unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Skater_0021E1B0* func_0022DE70(Game_0021E1B0* game, int index);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_0025F708(void* cutscenes, unsigned int name, bool skippable);

bool func_0021E1B0(void* params)
{
    unsigned int skater_name;
    int skater_id = 0;
    Skater_0021E1B0* skater;
    if (func_001E84E8(params, D_003716F8, &skater_name, 0)) {
        skater = func_00184D70(skater_name);
    } else {
        func_001E7DE8(params, 0x5B8AB877, &skater_id, 0);
        skater = func_0022DE70(D_0038FC78, skater_id);
    }
    if (skater && skater->m_local) {
        unsigned int name = 0;
        func_001E8398(params, 0xA1DC81F9, &name, 0);
        int skippable = 0;
        func_001E7E58(params, D_00371728, &skippable, 0);
        func_0025F708(D_0038FC78->m_cutscenes, name, skippable != 0);
    }
    return true;
}
