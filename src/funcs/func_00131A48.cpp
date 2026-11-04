extern "C" int func_00132580();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_00146088(char* name, int a, int b, int c, int d);
extern "C" int func_001F0D78(const char* name);
extern "C" void func_001334C0(void* obj, char* name);
extern char D_0035D468[];
extern char D_00389C40[];
extern char D_00389C48[];
extern void* D_004653B0[4];

struct Obj_00131A48 {
    char pad[0x80];
    int m_80;
    int m_84;
};

extern "C" Obj_00131A48* func_00131A48(const char* name, int a, int b, int c, int d, int flag)
{
    char buf[128];
    const char* fmt = D_0035D468;
    const char* ext;
    if (flag) {
        ext = D_00389C40;
    } else {
        ext = D_00389C48;
    }
    func_003331D0(buf, fmt, name, name, ext, func_00132580());
    func_0010BFC0(buf);
    Obj_00131A48* p = (Obj_00131A48*)func_00146088(buf, a, b, c, d);
    p->m_80 = func_001F0D78(name);
    p->m_84 = a;
    func_001334C0(p, buf);
    for (int i = 0; i < 4; i++) {
        if (D_004653B0[i] == 0) {
            D_004653B0[i] = p;
            break;
        }
    }
    func_0010BFC8();
    return p;
}
