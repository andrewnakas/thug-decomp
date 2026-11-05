extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_0024F4C0 {
    int m0;
    char m_params[4];
    bool Fn();
};

bool Obj_0024F4C0::Fn()
{
    int v;
    func_001E88D8(m_params, 0x47F763FF, &v, 1);
    return v != 0;
}
