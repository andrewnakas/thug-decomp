extern "C" int func_00132580();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_001F0D78(const char* name);
extern "C" void* func_00131DD8(int checksum);
extern "C" int func_00331950(const char* a, const char* b);
extern "C" void func_00132E20(void* obj);
extern "C" int func_00105520(const char* name);
extern "C" void* func_00139D70(int checksum);
extern "C" void func_00139D10(void* tex);
extern "C" void* func_00139C18(const char* name, int a, int b, int c, int d);
extern "C" int func_00146128(void* obj, char* name);
extern "C" void func_001334F8(void* obj, char* name, void* tex);
extern char D_0035D480[];
extern char D_0035D498[];

struct Obj_00131B80 {
    char pad[0x164];
    char m_name[1];
};

extern "C" Obj_00131B80* func_00131B80(const char* key, const char* level)
{
    char geom[128];
    char tex[128];
    func_003331D0(geom, D_0035D480, level, level, func_00132580());
    func_003331D0(tex, D_0035D498, level, level);
    Obj_00131B80* p = (Obj_00131B80*)func_00131DD8(func_001F0D78(key));
    if (func_00331950(p->m_name, geom) == 0) {
        func_00132E20(p);
        void* t = func_00139D70(func_00105520(tex));
        if (t) {
            func_00139D10(t);
        }
    }
    void* t2 = func_00139C18(tex, 1, 0, 0, 0);
    func_00146128(p, geom);
    func_001334F8(p, geom, t2);
    return p;
}
