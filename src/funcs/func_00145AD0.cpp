extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

class Obj_00145AD0 {
public:
    char pad[0x30];
    float m_30;
    int Load(void* params);
};

int Obj_00145AD0::Load(void* params)
{
    m_30 = 500.0f;
    func_001E7EB0(params, 0, &m_30, 0);
    return 1;
}
