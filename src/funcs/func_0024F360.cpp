extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_0024F360 {
    int m0;
    char m_params[4];
    bool Fn();
};

bool Obj_0024F360::Fn()
{
    int v;
    if (!func_001E88D8(m_params, 0xD57C16BA, &v, 0)) return false;
    return v != 0;
}
