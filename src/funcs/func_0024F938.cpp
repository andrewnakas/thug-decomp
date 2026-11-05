extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

struct Obj_0024F938 {
    int m0;
    char m_params[4];
    unsigned int Fn();
};

unsigned int Obj_0024F938::Fn()
{
    unsigned int v = 0;
    func_001E8398(m_params, 0xA1DC81F9, &v, 0);
    return v;
}
