extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);

struct Obj_002624F0 {
    char pad[0x5C];
    char m_params[4];
    const char* Fn();
};

const char* Obj_002624F0::Fn()
{
    const char* v;
    func_001E8870(m_params, 0x2AB66CB8, &v, 1);
    return v;
}
