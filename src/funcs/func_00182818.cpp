extern char D_00361798[];
extern unsigned long D_0038C310;
extern "C" int func_00103F28(char* fmt);
extern "C" void func_00165058();
extern "C" void func_00165088();
extern "C" int func_001E53A0(unsigned int id, int def);
extern "C" void func_0010FB08();
extern "C" unsigned long func_0010FA98();
extern "C" void func_0010FBA0();
extern "C" void func_00131918();
extern "C" void func_001E22F0();
extern "C" void func_00105200(void* list, int flag);
extern "C" void func_00182568();
extern "C" void func_00131960();
extern "C" void func_00230550();
extern "C" void func_00131938();
extern "C" void func_0010F958();

struct C_00182818 {
    int m0;
    int m_quit;
    char m8[0xA0 - 0x8];
    char mA0[0xF8 - 0xA0];
    int m_steps;
    int m_stepping;
    void Run();
};

void C_00182818::Run()
{
    int saved = m_quit;
    m_quit = 0;
    do {
        if (m_steps) {
            func_00103F28(D_00361798);
            m_stepping = 1;
            m_steps--;
        }
        func_00165058();
        func_00165088();
        int wait = func_001E53A0(0x3214C818, 0);
        if (wait) {
            func_0010FB08();
            while (func_0010FA98() < D_0038C310) {
            }
            D_0038C310 = func_0010FA98() + wait;
        } else {
            func_0010FBA0();
        }
        func_00131918();
        func_001E22F0();
        func_00105200(mA0, m_stepping != 0);
        func_00105200(m8, m_stepping != 0);
        func_00182568();
        func_00131960();
        func_00230550();
        func_00131938();
        func_0010F958();
        m_stepping = 0;
    } while (m_quit == 0);
    m_quit = saved;
}
