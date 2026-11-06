extern char D_003716F8[];
extern char D_0038F858[];
extern char D_0038F860[];

struct Game_0021E610 {
    char pad[0x39C];
    void* m_39C;
};

struct Skater_0021E610 {
    char pad[0x31C];
    int m_31C;
};

struct Mode_0021E610 {
    char pad[0xAC];
    unsigned int m_AC;
};

extern Game_0021E610* D_0038FC78;
extern Mode_0021E610* D_00392808;

extern "C" bool func_001E84E8(void* params, const char* name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" bool func_001E8A30(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Skater_0021E610* func_00184D70(int id);
extern "C" Skater_0021E610* func_0022DE70(Game_0021E610* game, int id);
extern "C" Skater_0021E610* func_0022DD38(Game_0021E610* game);
extern "C" bool func_0025F620(void* p, int a);
extern "C" void func_0025F460(void* p);
extern "C" void func_0025F930(void* p, unsigned int name);
extern "C" bool func_0025F0F0(void* p);
extern "C" void func_002C5410(Mode_0021E610* mode);
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);

static inline bool Stop_0021E610()
{
    func_0025F460(D_0038FC78->m_39C);
    return true;
}

static inline bool Play_0021E610(void* params)
{
    unsigned int name = 0;
    func_001E8A30(params, 0xA1DC81F9, &name, 1);
    func_0025F930(D_0038FC78->m_39C, name);
    return true;
}

bool Cmd_0021E610(void* params, void* script)
{
    bool r = true;
    int id;
    int index = 0;
    Skater_0021E610* skater;
    if (func_001E84E8(params, D_003716F8, &id, 0))
        skater = func_00184D70(id);
    else if (func_001E7DE8(params, 0x5B8AB877, &index, 0))
        skater = func_0022DE70(D_0038FC78, index);
    else
        skater = func_0022DD38(D_0038FC78);
    if (skater && skater->m_31C) {
        if (func_001E87B8(params, D_0038F858))
            r = func_0025F620(D_0038FC78->m_39C, 0);
        else if (func_001E87B8(params, D_0038F860))
            r = Stop_0021E610();
        else
            r = Play_0021E610(params);
    }
    if (!func_0025F0F0(D_0038FC78->m_39C)) {
        if (D_00392808->m_AC == 0x7ECA21E5)
            func_002C5410(D_00392808);
        else
            func_001F0210(0x15674315, 0, 0, 0, 0);
    }
    return r;
}
