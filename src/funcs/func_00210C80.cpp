extern char D_00370420[];
extern char D_00370438[];
extern char D_0038F458[];
extern char D_0038F340[];
extern char D_0038F460[];
extern char D_00370450[];

extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8870(void* params, unsigned int name, char** out, int required);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_00139C18(char* path, int a, int b, int c, int d);
extern "C" int func_00104328(const char* a, const char* b);
extern "C" void func_00131A48(char* name, void* tex, bool a, bool b, bool c, bool d);

bool Cmd_00210C80(void* params, void* script)
{
    char buf[0x80];
    bool a = func_001E8708(params, 0x3D559E7D);
    bool b = func_001E8708(params, 0xB5BD28D8);
    bool c = func_001E8708(params, 0x417149C8);
    bool d = !func_001E8708(params, 0x8943DBD8);
    char* name = 0;
    func_001E8870(params, 0x26861025, &name, 1);
    func_00103F28(D_00370420, name);
    func_003331D0(buf, D_00370438, name, name, c ? D_0038F458 : D_0038F340);
    void* tex = func_00139C18(buf, 1, 0, 0, 0);
    if (func_00104328(name, D_0038F460))
        b = true;
    if (b)
        d = false;
    func_00131A48(name, tex, a ? false : d, b, a, c);
    func_00103F28(D_00370450);
    return true;
}
