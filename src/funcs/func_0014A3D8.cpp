extern "C" void func_0017F0C0(void* t, int v);
extern "C" void func_0017F038(void* t, float f);

struct Obj_0014A3D8 {
    char pad[0x20];
    float m_20;
    int m_24;
    char pad2[0x8];
    int m_30;
    char pad3[0xC];
    void* m_40;
    void Apply();
};

void Obj_0014A3D8::Apply()
{
    if (m_30)
        func_0017F0C0(m_40, m_24);
    else
        func_0017F038(m_40, m_20);
}
