extern char D_00372840[];
extern char D_00372858[];
extern char D_00372870[];
extern char D_00372888[];
extern char D_00372898[];
extern char D_003728B0[];
extern char D_003728C8[];
extern char D_003728E0[];
extern int D_0038881C;
extern int D_0038ED88;

struct Heap_0022C318 {
    char pad[0xDC];
    void* m_DC;
};

extern Heap_0022C318* D_00388A70;

struct Lists_0022C318 {
    char pad[8];
    char m_list[1];
};

extern Lists_0022C318* D_0038C308;

struct Task_0022C318 {
    char pad[0x14];
    int m_pri;
};

struct Game_0022C318 {
    char pad[0x18];
    Task_0022C318* m_18;
    char pad1C[0x60];
    void* m_7C;
    char pad80[0x3E4];
    int m_464;
};

extern "C" void func_001F0370(char* name, void* params, void* a, int b);
extern "C" void func_0026B728();
extern "C" void func_0026C1D8();
extern "C" void func_00105260(void* list, void* node);
extern "C" void* func_0022E358(Game_0022C318* g);
extern "C" void func_0024FA38(void* a);
extern "C" void func_0010A950(Heap_0022C318* heap, void* a);
extern "C" void func_0010A9B0(Heap_0022C318* heap);
extern "C" void func_0010BFC0(char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_0022E050(Game_0022C318* g);
extern "C" void func_002625A0(void* a);
extern "C" void func_00264788(void* a);

void func_0022C318(Game_0022C318* game)
{
    func_001F0370(D_00372840, 0, 0, 0);
    game->m_464 = 0;
    Lists_0022C318* lists = D_0038C308;
    func_0026B728();
    func_0026C1D8();
    game->m_18->m_pri = 2;
    func_00105260(lists->m_list, game->m_18);
    func_0024FA38(func_0022E358(game));
    func_001F0370(D_00372858, 0, 0, 0);
    func_001F0370(D_00372870, 0, 0, 0);
    func_001F0370(D_00372888, 0, 0, 0);
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    func_0010BFC0(D_00372898);
    func_001F0370(D_003728B0, 0, 0, 0);
    func_0010BFC8();
    func_0010A9B0(D_00388A70);
    func_002625A0(func_0022E050(game));
    func_00264788(game->m_7C);
    func_001F0370(D_003728C8, 0, 0, 0);
    if (!D_0038881C && !D_0038ED88)
        func_001F0370(D_003728E0, 0, 0, 0);
}
