extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_0024F6F8 {
    int m0;
    char m_params[4];
    int Fn();
};

int Obj_0024F6F8::Fn()
{
    int v;
    func_001E88D8(m_params, 0x6DC3D6F1, &v, 1);
    return v;
}
