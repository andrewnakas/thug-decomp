extern "C" void func_001E70C0(void* params, unsigned int name, const char* value);

struct Obj_002624C8 {
    char pad[0x5C];
    char m_params[4];
    void Fn(const char* v);
};

void Obj_002624C8::Fn(const char* v)
{
    func_001E70C0(m_params, 0xF36C1878, v);
}
