extern char D_0038F340[];
extern char D_0038F378[];

struct Script_0020C3B8 {
    char pad[0x18];
    void* m_18;
};

extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001E70C0(void* p, unsigned int name, char* text);

bool Cmd_0020C3B8(void* params, Script_0020C3B8* script)
{
    char buf[0x70];
    char num[0x20];
    const char* str = D_0038F340;
    func_001E7C80(params, 0xC4745838, &str, 0);
    int len = func_00331BB8(str);
    func_00331A9C(buf, str);
    int max = 15;
    func_001E7DE8(params, 0xA6931595, &max, 0);
    int n = 1;
    func_001E7DE8(params, 0x4A4F7821, &n, 0);
    func_003331D0(num, D_0038F378, n);
    int numLen = func_00331BB8(num);
    if (max < len + numLen)
        buf[max - numLen] = 0;
    func_00331678(buf, num);
    unsigned int name = 0;
    func_001E8398(params, 0x50060694, &name, 0);
    func_001E70C0(script->m_18, name, buf);
    return true;
}
