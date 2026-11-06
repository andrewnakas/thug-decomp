extern char D_0035CDD8[];
extern char D_00389828[];
extern "C" void func_001E7318(void* params, const char* name, float v);
extern "C" void func_001E73C8(void* params, const char* name, int v);

class Elem_00128B30;
extern "C" void func_001246E8(Elem_00128B30* self, void* params);

class Elem_00128B30 {
public:
    char pad0[0xC4];
    float m_rot;
    char padC8[0x1A0 - 0xC8];
    int m_texture;
    void GetProps(void* params);
};

void Elem_00128B30::GetProps(void* params)
{
    func_001246E8(this, params);
    func_001E7318(params, D_0035CDD8, m_rot);
    func_001E73C8(params, D_00389828, m_texture);
}
