extern "C" bool func_001E8708(void* params, unsigned int name);

struct Obj_00262430 {
    char pad[0x5C];
    char m_params[4];
    bool Fn();
};

bool Obj_00262430::Fn()
{
    return func_001E8708(m_params, 0xF3149AC5);
}
