extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_00261E18 {
    char pad[0x5C];
    char m_params[4];
    int Fn(unsigned int name);
};

int Obj_00261E18::Fn(unsigned int name)
{
    int v;
    func_001E88D8(m_params, name, &v, 1);
    return v;
}
