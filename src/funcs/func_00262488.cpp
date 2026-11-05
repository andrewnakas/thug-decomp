extern char D_00375BF0[];
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);

struct Obj_00262488 {
    char pad[0x5C];
    char m_params[4];
    const char* Fn();
};

const char* Obj_00262488::Fn()
{
    const char* v = D_00375BF0;
    func_001E7C80(m_params, 0xF36C1878, &v, 0);
    return v;
}
