extern "C" void func_00249698(void* self);
extern "C" int func_003331D0(char* buf, char* fmt, int a);
extern "C" int func_001D0BD0(int a);
extern "C" int func_001D0AA8(int a, char* name, int b, int c, int d, int e);
extern "C" void func_001D0BC8(int a, int b);
extern "C" int func_001F0D78(char* name);
extern int D_0038DB38;
extern char D_00373C48[];

struct Obj_002495E8 {
    int m0;
    int m4;
    int m_8;
    void Load(int id, int flags);
};

void Obj_002495E8::Load(int id, int flags)
{
    char buf[32];
    func_00249698(this);
    func_003331D0(buf, D_00373C48, id);
    int mgr = D_0038DB38;
    int old = func_001D0BD0(mgr);
    if (func_001D0AA8(mgr, buf, id, flags, 0, 0)) {
        m_8 = func_001F0D78(buf);
    }
    func_001D0BC8(mgr, old);
}
