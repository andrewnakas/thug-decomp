extern char D_00371EC0[];
extern char D_00371ED8[];
extern int D_00388814;
extern void* D_0038E0A0;
extern void* D_00392068;

struct Game_00225320 {
    char pad0[0x24];
    void* m_24;
    char pad28[0x5C];
    void* m_84;
};

extern Game_00225320* D_0038FC78;

struct Script_00225320 {
    char pad[0x18];
    void* m_params;
};

struct Track_00225320 {
    char pad[0xC];
    unsigned int m_value;
};

extern "C" bool func_001E8180(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int key, float* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int key, unsigned int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int key, char** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int key);
extern "C" char* func_0022E058(Game_00225320* g);
extern "C" char* func_002A6078(void* a);
extern "C" void func_00202F58(char* a, void* params);
extern "C" void func_001DD5A0(void* a, float f);
extern "C" void func_001E00E0(float f);
extern "C" void func_001E0C40(unsigned long a, unsigned long b);
extern "C" void func_001E0440(int a);
extern "C" Track_00225320* func_001E4FC8(unsigned int key);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int key, unsigned int value);
extern "C" void func_001E7200(void* params, unsigned int key, int value);
extern "C" void func_001F0210(unsigned int key, void* params, int a, int b, int c);
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_0022DCE0(Game_00225320* g, int i, bool v);
extern "C" void func_0022DC98(Game_00225320* g, int i, bool v);
extern "C" void func_0022DC50(Game_00225320* g, int i, bool v);
extern "C" void func_0026EE78(void* a, void* params);
extern "C" void* func_0022E050(Game_00225320* g);
extern "C" void func_00262B88(void* a, void* params);
extern "C" void func_00264320(void* a, void* params);
extern "C" void func_001F0370(char* name, void* params, void* a, int b);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void* func_0022E368(Game_00225320* g, int a);
extern "C" bool func_002623B8(void* a);
extern "C" void func_002624C8(void* a, char* s);

void func_00225320(void* params, Script_00225320* script)
{
    void* info = 0;
    Game_00225320* game = D_0038FC78;
    func_001E8180(params, 0x2FCA0578, &info, 0);
    void* p = 0;
    func_001E8180(info, 0xF7720C3F, &p, 0);
    func_00202F58(func_0022E058(game), p);
    p = 0;
    func_001E8180(info, 0xE62B6586, &p, 0);
    func_00202F58(func_002A6078(D_00392068), p);
    func_001E8180(info, 0x89EB9738, &p, 0);
    void* snd = D_0038E0A0;
    float f = 0.0f;
    if (func_001E7EB0(p, 0x6F016DFB, &f, 0))
        func_001DD5A0(snd, f);
    float g = 0.0f;
    if (func_001E7EB0(p, 0xABD4A575, &g, 0))
        func_001E00E0(g);
    unsigned int ah = 0;
    unsigned int al = 0;
    unsigned int bh = 0;
    unsigned int bl = 0;
    if (func_001E7DE8(p, 0x595D2C95, &ah, 0)) {
        func_001E7DE8(p, 0xC0547D2F, &al, 0);
        func_001E7DE8(p, 0xB7534DB9, &bh, 0);
        func_001E7DE8(p, 0x2937D81A, &bl, 0);
        func_001E0C40(((unsigned long)ah << 32) | al, ((unsigned long)bh << 32) | bl);
    }
    if (func_001E8708(p, 0x31C71B70))
        func_001E0440(1);
    else
        func_001E0440(0);
    if (D_00388814 == 4) {
        unsigned int track = 0xFFFFFFFF;
        func_001E8398(p, 0xE1F7C4AE, &track, 0);
        Track_00225320* t = func_001E4FC8(0xE1F7C4AE);
        if (t)
            t->m_value = track;
        void* q = func_001E6978(func_001190D0(8));
        func_001E7360(q, 0x8C465905, track);
        func_001F0210(0xD44400C2, q, 0, 0, 0);
    }
    void* arr = 0;
    if (func_001E8248(info, 0x37BDB853, &arr, 0)) {
        for (int i = 0; i < 8; i++) {
            void* e = func_001E9378(arr, i);
            func_0022DCE0(game, i, func_001E8708(e, 0x73CEE124));
            func_0022DC98(game, i, func_001E8708(e, 0x1EEF7085));
            func_0022DC50(game, i, func_001E8708(e, 0xA483BA67));
        }
    }
    func_0026EE78(game->m_84, params);
    void* a = 0;
    func_001E8180(params, 0xC9986BAF, &a, 1);
    func_00262B88(func_0022E050(game), a);
    func_00264320(D_0038FC78->m_24, params);
    unsigned int t0 = 0;
    unsigned int t1 = 0;
    void* theme = 0;
    unsigned int t2 = 0;
    func_001E8180(params, 0x4DA4937B, &theme, 0);
    if (theme) {
        func_001E8398(theme, 0xE3335D2F, &t0, 0);
        func_001E8398(theme, 0x2CC06F5E, &t1, 0);
        func_001E7DE8(theme, 0xCC946FF3, &t2, 0);
    }
    if (t0)
        func_001E7360(script->m_params, 0xE3335D2F, t0);
    if (t1)
        func_001E7360(script->m_params, 0x2CC06F5E, t1);
    void* q = func_001E6978(func_001190D0(8));
    func_001E7200(q, 0x3BED2CF5, t2);
    func_001E7360(q, 0x476CDADD, 0);
    func_001F0370(D_00371EC0, q, 0, 0);
    if (q)
        func_001E6AE8(q, 3);
    void* m = func_0022E368(game, 0);
    if (!func_002623B8(m)) {
        char* s = D_00371ED8;
        func_001E7C80(params, 0xF36C1878, &s, 0);
        func_002624C8(m, s);
    }
}
