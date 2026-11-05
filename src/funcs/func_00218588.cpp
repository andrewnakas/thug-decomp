struct Script_00218588 {
    char pad0[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

bool func_00218588(void* params, Script_00218588* script)
{
    unsigned int a;
    unsigned int b;
    if (!func_001E8398(params, 0x174841BC, &a, 0))
        func_001E7DE8(params, 0x174841BC, &a, 1);
    if (!func_001E8398(params, 0x8E411006, &b, 0))
        func_001E7DE8(params, 0x8E411006, &b, 1);
    func_001E7360(script->m_params, 0xFBA40626, a + b);
    return true;
}
