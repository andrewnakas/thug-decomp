extern "C" void func_0017F1A8(void* t, int v);

struct Src_0014A418 {
    int m0[6];
    int m_18;
};

struct Obj_0014A418 {
    char pad[0x38];
    Src_0014A418* m_38;
    char pad2[0x4];
    void* m_40;
    void Apply();
};

void Obj_0014A418::Apply()
{
    if (m_38)
        func_0017F1A8(m_40, m_38->m_18);
    else
        func_0017F1A8(m_40, 0);
}
