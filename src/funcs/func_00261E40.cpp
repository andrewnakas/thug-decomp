extern "C" void func_001E7200(void* params, unsigned int name, int value);

struct Obj_00261E40 {
    char pad[0x5C];
    char m_params[4];
    bool Fn(unsigned int name, unsigned int v);
};

bool Obj_00261E40::Fn(unsigned int name, unsigned int v)
{
    if (v < 11) {
        func_001E7200(m_params, name, v);
        return true;
    }
    return false;
}
