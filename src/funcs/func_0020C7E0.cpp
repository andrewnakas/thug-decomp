struct Script_0020C7E0 {
    char pad[0x18];
    void* m18;
};
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_0010FC30();
extern "C" void func_001E7200(void* s, unsigned int id, int v);

bool func_0020C7E0(void* params, Script_0020C7E0* script)
{
    int t;
    func_001E7DE8(params, 0xD16B61E6, &t, 0);
    int start = t;
    void* s = script->m18;
    func_001E7200(s, 0x3EB3566B, func_0010FC30() - start);
    return true;
}
