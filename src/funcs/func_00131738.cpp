extern char D_00389BB8[];
extern char D_00389BC0[];
extern char D_0035D3F8[];
extern char D_0035D408[];
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

extern "C" void func_00131738(const char* name, const char* ext, char* out)
{
    if (func_003364D8(name, D_00389BB8) || func_003364D8(name, D_00389BC0)) {
        func_003331D0(out, D_0035D3F8, name);
    } else {
        func_003331D0(out, D_0035D408, name, name, ext);
    }
}
