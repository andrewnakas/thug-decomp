struct S_0020E418 {
    char m_pad[0x18];
    void* m18;
};
extern char D_00370298[];
extern "C" int func_001E1208(void* params);
extern "C" void func_001E7268(void* a, char* name, int v);

extern "C" int func_0020E418(void* params, S_0020E418* script)
{
    int v = func_001E1208(params);
    func_001E7268(script->m18, D_00370298, v);
    return 1;
}
