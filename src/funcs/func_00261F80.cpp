extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_00261F80 {
    char pad[0x5C];
    char m_params[4];
    int Fn();
};

int Obj_00261F80::Fn()
{
    int v;
    func_001E88D8(m_params, 0xAC9B9EDA, &v, 1);
    return v;
}
