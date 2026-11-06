extern char D_0038F340[];
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void func_001E4E98(int a, const char* s);

extern "C" bool func_0020C250(void* params, void* script)
{
    int a = 0;
    func_001E7DE8(params, 0x7F8C98FE, &a, 0);
    const char* s = D_0038F340;
    func_001E7C80(params, 0x61414D56, &s, 0);
    func_001E4E98(a, s);
    return true;
}
