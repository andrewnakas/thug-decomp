extern char D_003702A8[];
extern char D_003702C0[];
extern "C" bool func_001E8870(void* params, unsigned int name, char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" char* func_001E0F20(int id, int a);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_001DEEE0();
extern "C" void func_001DFDD0(char* name, bool flag);
extern "C" void func_001E1210(int id);

bool Cmd_0020ECB8(void* params, void* script)
{
    char buf[0x30];
    char* name = 0;
    int id = 999;
    int flag = 0;
    if (!func_001E8870(params, 0, &name, 0)) {
        func_001E7DE8(params, 0, &id, 0);
        name = func_001E0F20(id, 0);
        func_003331D0(buf, D_003702A8, name);
        name = buf;
    }
    func_001E7DE8(params, 0x5EA0E211, &flag, 0);
    if (name) {
        func_00103F28(D_003702C0, name);
        func_001DEEE0();
        func_001DFDD0(name, flag != 0);
        func_001E1210(id);
    }
    return true;
}
