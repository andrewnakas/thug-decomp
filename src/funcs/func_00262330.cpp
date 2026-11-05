extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);

struct Obj_00262330 {
    char pad[0x5C];
    char m_params[4];
    void* Fn(unsigned int name);
};

void* Obj_00262330::Fn(unsigned int name)
{
    void* v;
    func_001E8180(m_params, name, &v, 1);
    return v;
}
