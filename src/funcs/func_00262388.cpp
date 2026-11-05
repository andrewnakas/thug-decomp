extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);

struct Obj_00262388 {
    char pad[0x5C];
    char m_params[4];
    int Fn();
};

int Obj_00262388::Fn()
{
    int v;
    func_001E8A30(m_params, 0xA1DC81F9, &v, 1);
    return v;
}
