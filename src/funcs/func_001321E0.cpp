extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" void func_00104418(char* buf);
extern "C" int func_00132580();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_00139C18(const char* name, int a, int b, int c, int d);
extern "C" void func_0010BFC0(const char* name);
extern "C" void* func_00146370(char* name, void* tex, int a, int b, int c);
extern "C" void func_0010BFC8();
extern char D_00389C50[];
extern char D_00389C58[];
extern char D_0035D4B0[];
extern char D_00389C60[];
extern char D_00389C68[];
extern char D_00389C70[];
extern char D_0035D4C0[];

extern "C" void* func_001321E0(const char* name, int a, int b, int c)
{
    char base[512];
    char geom[512];
    char tex[512];
    func_00331A9C(base, name);
    char* s = func_003364D8(base, D_00389C50);
    int found = s != 0;
    if (found) {
        *s = 0;
    }
    s = func_003364D8(base, D_00389C58);
    if (s) {
        *s = 0;
    }
    char* g = geom;
    func_00104418(g);
    const char* fmt = D_0035D4B0;
    const char* ext;
    if (found) {
        ext = D_00389C60;
    } else {
        ext = D_00389C68;
    }
    func_003331D0(g, fmt, base, ext, func_00132580());
    func_003331D0(tex, D_00389C70, base);
    void* t = func_00139C18(tex, 0, a, found, func_003364D8(geom, D_0035D4C0) ? 1 : b);
    func_0010BFC0(geom);
    void* r = func_00146370(geom, t, a, found, c);
    func_0010BFC8();
    return r;
}
