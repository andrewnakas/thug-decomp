extern "C" void func_0017F0C0(void* t, int v);
extern "C" void func_0017F038(void* t, float f);

struct Obj_0014A800 {
    char pad[0x18];
    float m_18;
    int m_1C;
    char pad2[0xC];
    int m_2C;
    char pad3[0xC];
    void* m_3C;
    void Apply();
};

void Obj_0014A800::Apply()
{
    if (m_2C)
        func_0017F0C0(m_3C, m_1C);
    else
        func_0017F038(m_3C, m_18);
}
