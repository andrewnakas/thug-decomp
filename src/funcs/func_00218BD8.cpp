extern char D_00370E98[];
extern "C" bool func_001E7C80(void* params, int name, char** out, int required);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_00104460(char* s);
extern "C" void func_001E7138(void* p, char* name, char* value);

struct Script_00218BD8 {
    char m_pad0[0x18];
    void* m18;
};

bool Cmd_00218BD8(void* params, Script_00218BD8* script)
{
    char buf[0x80];
    char* s;
    func_001E7C80(params, 0, &s, 1);
    func_00331A9C(buf, s);
    func_00104460(buf);
    func_001E7138(script->m18, D_00370E98, buf);
    return true;
}
