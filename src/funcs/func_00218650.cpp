extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7C80(void* params, unsigned int name, int* out, int assert_);
extern "C" int func_001055B0(int a, int b);
extern "C" void func_001E7360(void* params, unsigned int name, int value);

struct Script_00218650 {
    char pad[0x18];
    void* m_params;
};

bool func_00218650(void* params, Script_00218650* script)
{
    int a;
    int b;
    func_001E8398(params, 0x3F4B019E, &a, 1);
    func_001E7C80(params, 0x94542EEA, &b, 1);
    void* out = script->m_params;
    func_001E7360(out, 0xAFB911C6, func_001055B0(a, b));
    return true;
}
