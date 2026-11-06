struct Cfg_00114770 {
    char pad0[0x1C];
    unsigned int m_interval;
};

extern unsigned int D_00389040;
extern "C" unsigned long func_0010FA98();
extern "C" void func_0010F958();

struct Timer_00114770 {
    int m0;
    int m4;
    int m8;
    Cfg_00114770* m_cfg;
    void Wait();
};

void Timer_00114770::Wait()
{
    Cfg_00114770* c = m_cfg;
    unsigned long now;
    do {
        now = func_0010FA98();
    } while (now - D_00389040 < c->m_interval);
    D_00389040 = now;
    func_0010F958();
}
