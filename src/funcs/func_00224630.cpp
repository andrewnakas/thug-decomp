extern char D_00371E58[];
extern int D_00388814;
extern void* D_0038E0A0;
extern void* D_00392068;

struct Flags_00224630 {
    int m_c;
    int m_a;
    int m_b;
    int pad;
};

struct Game_00224630 {
    char pad0[0x24];
    void* m_24;
    char pad28[0x5C];
    void* m_84;
    char pad88[0x340];
    Flags_00224630 m_flags[8];
};

extern Game_00224630* D_0038FC78;

union Time_00224630 {
    long q;
    struct {
        int lo;
        int hi;
    } s;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" char* func_0022E058(Game_00224630* g);
extern "C" void func_001E6AC8(void* params, char* s);
extern "C" void func_001E78A8(void* params, unsigned int key, void* value);
extern "C" float func_001DD618(void* a);
extern "C" float func_001E0180();
extern "C" void func_001E72B0(void* params, unsigned int key, float value);
extern "C" void func_001E0C20(Time_00224630* a, Time_00224630* b);
extern "C" void func_001E7200(void* params, unsigned int key, int value);
extern "C" unsigned int func_001E5458(char* name, int a);
extern "C" void func_001E7360(void* params, unsigned int key, unsigned int value);
extern "C" bool func_001E0498();
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void func_001E9170(void* arr, int i, void* value);
extern "C" void func_001E7720(void* params, unsigned int key, void* arr);
extern "C" char* func_002A6078(void* a);
extern "C" void func_001E77D0(void* params, unsigned int key, char* s);
extern "C" void func_00263DC0(void* a, void* params);
extern "C" void func_0026EF70(void* a, void* params);
extern "C" void* func_0022E050(Game_00224630* g);
extern "C" void func_00262A50(void* a, void* params);

void func_00224630(void* params)
{
    void* info = func_001E6978(func_001190D0(8));
    Game_00224630* game = D_0038FC78;
    char* name = func_0022E058(game);
    void* p = func_001E6978(func_001190D0(8));
    func_001E6AC8(p, name + 4);
    func_001E78A8(info, 0xF7720C3F, p);
    p = func_001E6978(func_001190D0(8));
    func_001E72B0(p, 0x6F016DFB, func_001DD618(D_0038E0A0));
    func_001E72B0(p, 0xABD4A575, func_001E0180());
    Time_00224630 a;
    Time_00224630 b;
    func_001E0C20(&a, &b);
    Time_00224630 a2 = a;
    Time_00224630 b2 = b;
    int ah = a2.s.hi;
    int al = a2.s.lo;
    int bh = b2.s.hi;
    int bl = b2.s.lo;
    func_001E7200(p, 0x595D2C95, ah);
    func_001E7200(p, 0xC0547D2F, al);
    func_001E7200(p, 0xB7534DB9, bh);
    func_001E7200(p, 0x2937D81A, bl);
    if (D_00388814 == 4)
        func_001E7360(p, 0xE1F7C4AE, func_001E5458(D_00371E58, 0));
    if (func_001E0498())
        func_001E7360(p, 0, 0x31C71B70);
    func_001E78A8(info, 0x89EB9738, p);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, 8, 0xA);
    for (int i = 0; i < 8; i++) {
        p = func_001E6978(func_001190D0(8));
        if (game->m_flags[i].m_a)
            func_001E7360(p, 0, 0x1EEF7085);
        if (game->m_flags[i].m_b)
            func_001E7360(p, 0, 0xA483BA67);
        if (game->m_flags[i].m_c)
            func_001E7360(p, 0, 0x73CEE124);
        func_001E9170(arr, i, p);
    }
    func_001E7720(info, 0x37BDB853, arr);
    func_001E77D0(info, 0xE62B6586, func_002A6078(D_00392068) + 4);
    func_001E78A8(params, 0x2FCA0578, info);
    func_00263DC0(D_0038FC78->m_24, params);
    func_0026EF70(game->m_84, params);
    void* q = func_001E6978(func_001190D0(8));
    func_00262A50(func_0022E050(game), q);
    func_001E78A8(params, 0xC9986BAF, q);
}
