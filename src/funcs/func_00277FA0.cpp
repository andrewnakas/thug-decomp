extern "C" int func_00185578(void* obj, unsigned int name);

struct C_00277FA0 {
    char m_pad[0xC];
    void* mC;
    char m10[0x54];
    int m64;
    void Run();
};

void C_00277FA0::Run()
{
    m64 = func_00185578(mC, 0x5BD63B29);
}
