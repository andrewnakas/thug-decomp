extern "C" void func_0017F1A8(void* t, int v);

struct Src_0014A840 {
    int m0[6];
    int m_18;
};

struct Obj_0014A840 {
    char pad[0x30];
    Src_0014A840* m_30;
    char pad2[0x8];
    void* m_3C;
    void Apply();
};

void Obj_0014A840::Apply()
{
    if (m_30)
        func_0017F1A8(m_3C, m_30->m_18);
    else
        func_0017F1A8(m_3C, 0);
}
