extern char D_003716F8[];
extern char D_0038F850[];
extern char D_00371708[];

struct Skater_0021E070 {
    char m_pad[0x31C];
    int m_local;
};

struct Mgr_0021E070 {
    char m_pad[0x39C];
    void* m39C;
};

extern Mgr_0021E070* D_0038FC78;

extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_0025FB98(void* self);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" Skater_0021E070* func_00184D70(unsigned int id);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" Skater_0021E070* func_0022DE70(void* self, int index);
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" void func_0025F460(void* self);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_0025F9D0(void* self, unsigned int text, void* params, unsigned int name);
extern "C" int func_00103F28(const char* fmt, ...);

bool func_0021E070(void* params)
{
    if (func_001E8708(params, 0x0C567FA2)) {
        func_0025FB98(D_0038FC78->m39C);
        return true;
    }
    unsigned int id;
    int index = 0;
    Skater_0021E070* skater;
    if (func_001E84E8(params, D_003716F8, &id, 0)) {
        skater = func_00184D70(id);
    } else {
        func_001E7DE8(params, 0x5B8AB877, &index, 0);
        skater = func_0022DE70(D_0038FC78, index);
    }
    if (!skater) {
        return true;
    }
    if (skater->m_local) {
        if (func_001E87B8(params, D_0038F850)) {
            func_0025F460(D_0038FC78->m39C);
        } else {
            unsigned int text = 0;
            func_001E8398(params, 0xA1DC81F9, &text, 0);
            func_001F0210(0xDF00BDFF, 0, 0, 0, 0);
            func_0025F9D0(D_0038FC78->m39C, text, params, 0x66B7DD11);
        }
    } else {
        func_00103F28(D_00371708);
    }
    return true;
}
