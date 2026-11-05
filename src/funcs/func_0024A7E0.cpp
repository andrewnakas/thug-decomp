extern "C" int func_00103F28(char* fmt);
extern "C" int func_00248800(void* self, unsigned int crc);
extern "C" void func_0024A860(void* self);
extern char D_00373E38[];

struct Guy_0024A7E0 {
    char pad0[0xA4];
    int m_A4;
    char padA8[0xB4 - 0xA8];
    int m_B4;
    char padB8[0xCC - 0xB8];
    int m_CC;
    int m_D0;
    void Lose();
};

void Guy_0024A7E0::Lose()
{
    func_00103F28(D_00373E38);
    func_00248800(this, 0x79D8D4B6);
    func_0024A860(this);
    int n = m_CC + 1;
    m_CC = n;
    if (n >= 4 && m_B4 >= 2) {
        m_CC = 0;
        m_B4--;
    }
    m_D0 = 0;
    m_A4 = 1;
}
