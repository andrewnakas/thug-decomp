extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

class Obj_00145C48 {
public:
    char pad[0x3C];
    float m_3C;
    int Load(void* params);
};

int Obj_00145C48::Load(void* params)
{
    m_3C = 0;
    func_001E7EB0(params, 0, &m_3C, 0);
    return 1;
}
