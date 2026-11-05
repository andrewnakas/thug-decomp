struct Script_0020C848 {
    char pad[0x18];
    void* m18;
};
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void func_001E6B90(void* s, int v);
extern "C" void func_001E6D18(void* s, int v);

bool func_0020C848(void* params, Script_0020C848* script)
{
    int v = 0;
    func_001E8398(params, 0, &v, 0);
    void* s = script->m18;
    func_001E6B90(s, v);
    func_001E6D18(s, v);
    return true;
}
