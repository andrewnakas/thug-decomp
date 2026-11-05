extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_002623B8 {
    char pad[0x5C];
    char m_params[4];
    bool Fn();
};

bool Obj_002623B8::Fn()
{
    int v;
    func_001E88D8(m_params, 0xD82F8AC8, &v, 1);
    return v != 0;
}
