struct Color_001246E8 {
    unsigned char r, g, b, a;
};

struct Sub_001246E8 {
    float m0;
    char pad4[0x20 - 0x4];
    float m20;
    float m24;
    char pad28[0x34 - 0x28];
    float m_x;
    float m_y;
    char pad3C[0x48 - 0x3C];
    Color_001246E8 m_color;
    char pad4C[0x4];
};

struct C_001246E8 {
    char pad0[0x80];
    Sub_001246E8 m80;
    void Write(void* params);
};

extern "C" void func_001E72B0(void* params, unsigned int id, float v);
extern "C" void func_001E7558(void* params, unsigned int id, float a, float b);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(void* arr, int type, int n);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" void func_001E7648(void* params, unsigned int id, void* arr);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int flags);
extern "C" int func_00125DC8(C_001246E8* self);
extern "C" void func_001E7200(void* params, unsigned int id, int v);

void C_001246E8::Write(void* params)
{
    Sub_001246E8* s = &m80;
    func_001E72B0(params, 0x2F1FC695, m80.m0);
    Color_001246E8 c = m80.m_color;
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, 4, 1);
    func_001E90A8(arr, 0, c.r);
    func_001E90A8(arr, 1, c.g);
    func_001E90A8(arr, 2, c.b);
    func_001E90A8(arr, 3, c.a);
    func_001E7648(params, 0x3F6BCDBA, arr);
    func_001E6518(arr);
    if (arr)
        func_001E8DE8(arr, 3);
    if (s->m_x == s->m_y)
        func_001E72B0(params, 0x13B9DA7B, s->m_x);
    else
        func_001E7558(params, 0x13B9DA7B, s->m_x, s->m_y);
    Sub_001246E8* t = &m80;
    func_001E7558(params, 0x7F261953, t->m20, t->m24);
    if (func_00125DC8(this))
        func_001E7200(params, 0x73CB6D65, 1);
    else
        func_001E7200(params, 0x73CB6D65, 0);
}
