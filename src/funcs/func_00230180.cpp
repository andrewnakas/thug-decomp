extern void* D_0038FC78;

struct Set_00230180 {
    int pad0;
    void* m_4;
    void* m_8;
    void* m_C;
    void* m_10;
    void* m_14;
    void* m_18;
};

struct Profile_00230180 {
    char pad[0x20];
    int m_20;
    int m_24;
};

struct Comp_00230180 {
    char pad[0x68];
    float m_68;
    char pad6C[0x7C];
    float m_E8;
    char padEC[0x7C];
    float m_168;
};

struct Game_00230180 {
    char pad[0x24];
    void* m_24;
    char pad28[0x5C];
    void* m_84;
    char pad88[0x330];
    bool m_3B8;
};

extern "C" void* func_00263930(void* a);
extern "C" Set_00230180* func_0026EE60(void* a, void* b);
extern "C" void* func_0022DD38(void* mgr);
extern "C" Profile_00230180* func_00203360(void* skater);
extern "C" int func_002392B8(Profile_00230180* p);
extern "C" int func_0026E528(void* a, int b, int c);
extern "C" Comp_00230180* func_00185578(void* a, unsigned int key);
extern "C" bool func_0026E188(void* a, int b, int c);

void func_00230180(Game_00230180* game)
{
    game->m_3B8 = false;
    Set_00230180* set = func_0026EE60(game->m_84, func_00263930(game->m_24));
    void* skater = func_0022DD38(D_0038FC78);
    if (skater) {
        Profile_00230180* prof = func_00203360(skater);
        void* tbl = set->m_4;
        game->m_3B8 |= (func_0026E528(tbl, func_002392B8(prof), 0) != -1);
        game->m_3B8 |= (func_0026E528(set->m_8, prof->m_24, 0) != -1);
        Comp_00230180* comp = func_00185578(skater, 0x589E5FB3);
        int a = (int)(comp->m_E8 * 100.0f);
        int b = (int)(comp->m_68 * 100.0f);
        int c = (int)(comp->m_168 * 100.0f);
        int d = prof->m_20;
        game->m_3B8 |= func_0026E188(set->m_C, a, 0);
        game->m_3B8 |= func_0026E188(set->m_10, b, 0);
        game->m_3B8 |= func_0026E188(set->m_14, c, 0);
        game->m_3B8 |= func_0026E188(set->m_18, d, 0);
    }
}
