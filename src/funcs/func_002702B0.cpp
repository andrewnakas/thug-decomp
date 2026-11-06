extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);

struct Obj_002702B0 {
    char pad[0x44];
    float m44;
    float m48;
    char pad2[0x90 - 0x4C];
    float m90;
    void Load(void* params);
};

void Obj_002702B0::Load(void* params)
{
    m48 = 18.333334f;
    m44 = 45.0f;
    func_001E7EB0(params, 0xF1A99B27, &m90, 0);
}
