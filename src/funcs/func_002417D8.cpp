struct Script_002417D8 {
    char pad[0x18];
    void* m_params;
};

extern char D_0038FF48[];
extern char D_0038FF50[];

extern "C" int func_001E7C80(void* params, unsigned int name, const char** out, int req);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" void func_001E70C0(void* params, unsigned int name, const char* value);

bool Cmd_002417D8(void* params, Script_002417D8* script)
{
    char buf[128];
    const char* str;
    func_001E7C80(params, 0, &str, 1);
    buf[0] = D_0038FF48[0];
    int i;
    for (i = 0; str[i + 1]; i++)
        buf[i] = str[i];
    buf[i] = 0;
    func_00331678(buf, D_0038FF50);
    func_001E70C0(script->m_params, 0xC60CE720, buf);
    return true;
}
