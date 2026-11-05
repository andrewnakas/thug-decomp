struct Vec_0025B538 {
    float x, y, z, w;
    void Set(float nx, float ny, float nz, float nw)
    {
        x = nx;
        y = ny;
        z = nz;
        w = nw;
    }
};

extern "C" bool func_001E8398(void* params, unsigned int name, void* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_0025B538* out, int required);

struct Obj_0025B538 {
    char pad0[0x3C];
    bool m_3C;
    char m_40[0x10];
    Vec_0025B538 m_50;
    Vec_0025B538 m_60;
    bool m_70;
    bool m_74;

    void Load(void* params);
};

void Obj_0025B538::Load(void* params)
{
    m_3C = func_001E8398(params, 0x531E4D28, m_40, 0);
    if (!m_3C)
        return;
    m_50.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_001E7FA8(params, 0x906642BF, &m_50, 0);
    m_70 = m_50.x != 0.0f || m_50.y != 0.0f || m_50.z != 0.0f;
    m_60.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m_74 = func_001E7FA8(params, 0xA00D3D6E, &m_60, 0);
}
