extern "C" void* func_00185578(void* obj, unsigned int name);

struct C_001AB4D8 {
    int m_pad[3];
    void* mC;
    int m10[5];
    void* m24;
    void* m28;
    void* m2C;
    void* m30;
    void* m34;
    void* m38;
    void Bind();
};

void C_001AB4D8::Bind()
{
    m24 = func_00185578(mC, 0x27D7CD28);
    m28 = func_00185578(mC, 0x589E5FB3);
    m2C = func_00185578(mC, 0x5BD63B29);
    m30 = func_00185578(mC, 0x488AF07A);
    m34 = func_00185578(mC, 0x43686585);
    m38 = func_00185578(mC, 0x4FF8DAC6);
}
