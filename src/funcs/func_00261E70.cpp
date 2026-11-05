extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);

struct Obj_00261E70 {
    char pad[0x5C];
    char m_params[4];
    bool Fn(int d);
};

bool Obj_00261E70::Fn(int d)
{
    int v;
    func_001E88D8(m_params, 0x471FC4DD, &v, 1);
    v += d;
    func_001E7A68(m_params, 0x471FC4DD, 1, v);
    return true;
}
