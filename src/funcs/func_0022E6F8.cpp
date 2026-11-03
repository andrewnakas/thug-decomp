extern char D_00372C68[];
extern char D_0038FCC8[];
extern char D_00372CB0[];
extern char D_00372CC0[];
extern char D_00372CD0[];
extern char D_00372CE8[];

struct Heap_0022E6F8 {
    char pad[0x3EC];
    void* m_3EC;
};

extern Heap_0022E6F8* D_00388A70;

struct Game_0022E6F8 {
    char pad[0x90];
    int m_90;
    char pad94[0x31C];
    unsigned int m_level;
    unsigned int m_prevLevel;
    char pad3B8[4];
    void* m_3BC;
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_0010A950(Heap_0022E6F8* heap, void* a);
extern "C" void func_0010A9B0(Heap_0022E6F8* heap);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6B30(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, unsigned int value);
extern "C" void func_001F0370(char* name, void* params, void* a, int b);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_00213420(void* params, int a);
extern "C" void func_0024FDF8(void* a, unsigned int key);

void func_0022E6F8(Game_0022E6F8* game, unsigned int level)
{
    func_00103F28(D_00372C68, level);
    func_0010A950(D_00388A70, D_00388A70->m_3EC);
    void* p = func_001E6978(func_001190D0(8));
    func_001E6B30(p);
    func_001E7A68(p, func_001F0D78(D_0038FCC8), 0xD, level);
    func_001F0370(D_00372CB0, p, 0, 0);
    if (p)
        func_001E6AE8(p, 3);
    game->m_prevLevel = game->m_level;
    game->m_level = level;
    p = func_001E6978(func_001190D0(8));
    func_001E6B30(p);
    if (level != func_001F0D78(D_00372CC0))
        func_001E7A68(p, 0, 0xD, func_001F0D78(D_00372CD0));
    func_00213420(p, 0);
    if (p)
        func_001E6AE8(p, 3);
    game->m_90 = 1;
    func_0024FDF8(game->m_3BC, func_001F0D78(D_00372CE8));
    func_0010A9B0(D_00388A70);
}
