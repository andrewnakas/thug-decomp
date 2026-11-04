struct Skater_0021E288 {
    char pad0[0x31C];
    int m31C;
};

struct Game_0021E288 {
    char pad0[0x39C];
    void* m39C;
};

extern Game_0021E288* D_0038FC78;
extern char D_003716F8[];
extern char D_00371738[];

extern "C" int func_001E84E8(void* params, char* name, int* out, int a);
extern "C" Skater_0021E288* func_00184D70(int id);
extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int a);
extern "C" Skater_0021E288* func_0022DE70(Game_0021E288* game, int i);
extern "C" int func_001E8398(void* params, unsigned int crc, unsigned int* out, int a);
extern "C" int func_001E7E58(void* params, char* name, int* out, int a);
extern "C" void func_0025F7A0(void* p, unsigned int crc, bool pause);

bool Cmd_0021E288(void* params, void* script)
{
    int id;
    int idx = 0;
    Skater_0021E288* s;
    if (func_001E84E8(params, D_003716F8, &id, 0)) {
        s = func_00184D70(id);
    } else {
        func_001E7DE8(params, 0x5B8AB877, &idx, 0);
        s = func_0022DE70(D_0038FC78, idx);
    }
    if (s && s->m31C) {
        unsigned int crc = 0;
        func_001E8398(params, 0xA1DC81F9, &crc, 0);
        int pause = 0;
        func_001E7E58(params, D_00371738, &pause, 0);
        func_0025F7A0(D_0038FC78->m39C, crc, pause != 0);
    }
    return true;
}
