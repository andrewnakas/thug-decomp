struct Mgr_0023D588 {
    char pad[0x2C];
    int m_2C;
    int m_30;
    void Bump();
};

extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);

void Mgr_0023D588::Bump()
{
    m_2C++;
    m_30++;
    func_001F0210(0x888EF05E, 0, 0, 0, 0);
}
