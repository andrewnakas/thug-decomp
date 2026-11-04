struct Rgba_00126000 {
    unsigned char r, g, b, a;
};

struct Vec_00126000 {
    float x, y, z, w;
};

struct Sprite_00126000 {
    char pad[0x538];
    Rgba_00126000 m_rgba;
    void SetRgba(Rgba_00126000 c) { m_rgba = c; }
};

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8870(void* params, unsigned int name, void** out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E8998(void* params, unsigned int name, Vec_00126000* out, int req);
extern "C" void func_001E4C80(Vec_00126000* v);

class C_00126000 {
public:
    char pad[0x1B8];
    Sprite_00126000* m_sprite;
    char pad1BC[0xC];
    Rgba_00126000 m_rgba1C8;
    int m_state;
    int m_saved;
    void SetProperties(void* params);
    void Base(void* params);
    int GetRgba(void* params, unsigned int name, Rgba_00126000* out);
    void SetTexture(unsigned int name);
    void SetFont(void* p);
    void Show();
    void Hide();
    void SetSize(float w, float h);
    void SetFlag(int on);
};

void C_00126000::SetProperties(void* params)
{
    Base(params);
    unsigned int tex;
    if (func_001E8398(params, 0x2F6BF72D, &tex, 0))
        SetTexture(tex);
    void* font;
    if (func_001E8870(params, 0xC4745838, &font, 0))
        SetFont(font);
    if (func_001E8708(params, 0xD1653C6C))
        Show();
    if (func_001E8708(params, 0x4B73E4F8))
        Hide();
    Rgba_00126000 rgba;
    if (GetRgba(params, 0x4F0E1182, &rgba) && m_sprite)
        m_sprite->SetRgba(rgba);
    Vec_00126000 size;
    func_001E4C80(&size);
    if (func_001E8998(params, 0x2A1FE0CC, &size, 0))
        SetSize(size.y, size.z);
    if (func_001E8708(params, 0x8A897DD2))
        SetFlag(1);
    if (func_001E8708(params, 0x95B5B9A0))
        SetFlag(0);
    GetRgba(params, 0x1E7BB1F5, &m_rgba1C8);
    if (func_001E8708(params, 0x0BF51A0C))
        m_saved = m_state;
    if (func_001E8708(params, 0x61B7B58B))
        m_state = m_saved;
    if (func_001E8708(params, 0xB7686F92))
        m_state = 1;
    if (func_001E8708(params, 0xD25BC6CD))
        m_state = 0;
}
