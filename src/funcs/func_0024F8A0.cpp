extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_0024F8A0 {
    int m0;
    char m_params[4];
    int Fn();
};

int Obj_0024F8A0::Fn()
{
    int v = 3;
    func_001E7DE8(m_params, 0xCE87E4E3, &v, 0);
    return v;
}
