extern char D_003F5868[];
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" void func_003331D0(char* dst, const char* src);

extern "C" bool func_002170B8(void* params, void* script)
{
    const char* s;
    func_001E8870(params, 0, &s, 1);
    func_003331D0(D_003F5868, s);
    return true;
}
