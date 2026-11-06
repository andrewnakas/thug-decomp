struct Script_0020C2C0 {
    char m_pad0[0x18];
    void* m18;
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_001E4EC0(int v);
extern "C" void func_001E70C0(void* p, unsigned int name, void* v);

bool Cmd_0020C2C0(void* params, Script_0020C2C0* script)
{
    int v = 0;
    func_001E7DE8(params, 0x7F8C98FE, &v, 0);
    void* st = script->m18;
    func_001E70C0(st, 0x61414D56, func_001E4EC0(v));
    return true;
}
