struct Script_0020C7A0 {
    char pad[0x18];
    void* m18;
};

extern "C" int func_0010FC30(void* params);
extern "C" void func_001E7200(void* s, unsigned int name, int v);

extern "C" bool func_0020C7A0(void* params, Script_0020C7A0* script)
{
    void* s = script->m18;
    func_001E7200(s, 0xD16B61E6, func_0010FC30(params));
    return true;
}
