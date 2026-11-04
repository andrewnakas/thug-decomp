extern "C" void func_001E88D8(void* params, unsigned int name, int* out, int required);

struct Obj_0024F860 {
    int m_0;
    int m_params[4];
    bool Get();
};

bool Obj_0024F860::Get()
{
    int value;
    func_001E88D8(m_params, 0xA6479767, &value, 1);
    return value != 0;
}
