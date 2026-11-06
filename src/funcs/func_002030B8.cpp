extern "C" bool func_001E8248(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7648(void* params, unsigned int name, void* value);

struct Obj_002030B8 {
    int m0;
    char m_params[4];
    bool Set(unsigned int name, void* value);
};

bool Obj_002030B8::Set(unsigned int name, void* value)
{
    int v = 0;
    if (!func_001E8248(m_params, name, &v, 0))
        return false;
    func_001E7648(m_params, name, value);
    return true;
}
