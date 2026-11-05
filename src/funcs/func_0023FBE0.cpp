struct Mgr_0023FBE0 {
    char pad[0x1C];
    void* m_1C;
    char pad20[0x2C - 0x20];
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    char pad50[0x5C - 0x50];
    void* m_5C;
    void Reset();
};

extern "C" void func_001E6B30(void* s);

void Mgr_0023FBE0::Reset()
{
    func_001E6B30(m_1C);
    m_2C = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3C = 0;
    m_40 = 0;
    m_4C = 0;
    m_48 = 0;
    func_001E6B30(m_5C);
}
