extern char D_0038F438[];
extern "C" bool func_001E8870(void* params, unsigned int name, char** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_00115780(char* s, int a);
extern "C" void func_001157E0(char* s, int a);

bool Cmd_00219DE0(void* params, void* script)
{
    char buf[0x100];
    char* name;
    unsigned int type;
    func_001E8870(params, 0, &name, 1);
    func_001E8398(params, 0, &type, 1);
    func_003331D0(buf, D_0038F438, name);
    switch (type) {
    case 0xC6A56FE3:
        func_00115780(buf, 1);
        break;
    case 0xC06EAD08:
        func_001157E0(buf, 1);
        break;
    }
    return true;
}
