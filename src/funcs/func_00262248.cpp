extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);

struct Obj_00262248 {
    char pad[0x5C];
    char m_params[4];
    int Fn(unsigned int name);
};

int Obj_00262248::Fn(unsigned int name)
{
    int v = 0;
    switch (name) {
    case 0xC15DBF86:
        func_001E8A30(m_params, 0xC15DBF86, &v, 1);
        break;
    case 0x7D02BCC3:
        func_001E8A30(m_params, 0x7D02BCC3, &v, 1);
        break;
    }
    return v;
}
