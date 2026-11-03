extern char D_0038FEA0[];
extern char D_0038FEA8[];
extern char D_0038FEB0[];
extern char D_0038FDE0[];
extern void* D_0038FC78;

struct Obj_00239198 {
    short pad0;
    short m_id;
    unsigned int m_value;
};

struct Skater_00239198 {
    char pad[0x31C];
    int m_local;
};

extern "C" void* func_0022E358(void* g);
extern "C" Skater_00239198* func_0022DF08(void* mgr, int id);
extern "C" unsigned int func_0024F938(void* a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_002041F8(Skater_00239198* s);
extern "C" void func_0012F8A8(char* text, int idx);

void func_00239198(Obj_00239198* obj, unsigned int value)
{
    char buf[64];
    void* game = D_0038FC78;
    obj->m_value = value;
    func_0022E358(game);
    Skater_00239198* skater = func_0022DF08(game, obj->m_id);
    if (skater->m_local) {
        if (func_0024F938(func_0022E358(game)) == func_001F0D78(D_0038FEA0) ||
            func_0024F938(func_0022E358(game)) == func_001F0D78(D_0038FEA8)) {
            unsigned int secs = obj->m_value / 1000;
            func_003331D0(buf, D_0038FEB0, secs / 60, obj->m_value / 1000 % 60);
        } else {
            func_003331D0(buf, D_0038FDE0, obj->m_value);
        }
        func_0012F8A8(buf, func_002041F8(skater));
    }
}
