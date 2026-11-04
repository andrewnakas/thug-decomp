extern "C" void func_001E88D8(void* params, unsigned int name, int* out, int required);

struct Obj_0024F590 {
    int m_0;
    int m_params[4];
    int Get();
};

int Obj_0024F590::Get()
{
    int value;
    func_001E88D8(m_params, 0x2EBE6CD1, &value, 1);
    return value;
}
