extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);

struct Obj_00262458 {
    char pad[0x5C];
    char m_params[4];
    void Fn(int v);
};

void Obj_00262458::Fn(int v)
{
    func_001E7A68(m_params, 0x09F350E5, 1, v);
}
