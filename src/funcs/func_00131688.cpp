extern char D_00389BB8[];
extern char D_00389BC0[];
extern char D_0035D3F8[];
extern char D_0035D408[];
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_00104028(void* str, const char* text);

extern "C" void* func_00131688(void* str, const char* name, const char* ext)
{
    char buf[0x200];
    if (func_003364D8(name, D_00389BB8) || func_003364D8(name, D_00389BC0)) {
        func_003331D0(buf, D_0035D3F8, name);
    } else {
        func_003331D0(buf, D_0035D408, name, name, ext);
    }
    func_00104028(str, buf);
    return str;
}
