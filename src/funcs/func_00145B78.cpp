extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

class Obj_00145B78 {
public:
    char pad[0x38];
    float m_38;
    bool Run(void* p);
};

bool Obj_00145B78::Run(void* p)
{
    m_38 = 4.0f;
    func_001E7EB0(p, 0, &m_38, 0);
    return true;
}
