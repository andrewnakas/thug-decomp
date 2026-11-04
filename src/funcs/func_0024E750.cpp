struct Goal_0024E750 {
    char pad[0x20];
    void* m_params;
    char pad24[0xA4 - 0x24];
    int m_A4;
    int m_A8;
    int m_AC;
    int m_B0;
    int m_B4;
};

extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00244620(Goal_0024E750* goal);

void func_0024E750(Goal_0024E750* goal)
{
    goal->m_A8 = 0;
    goal->m_B0 = 0;
    goal->m_AC = 0;
    goal->m_B4 = 0;
    goal->m_A4 = 0;
    func_001E7200(goal->m_params, 0x9278CA8D, 0);
    int t;
    if (func_001E7DE8(goal->m_params, 0x184E30FD, &t, 0)) {
        goal->m_AC = t * 1000;
        int n;
        func_001E7DE8(goal->m_params, 0x906B67BA, &n, 1);
        goal->m_B0 *= 1000;
        goal->m_B0 *= n;
    } else {
        func_001E7DE8(goal->m_params, 0xC808F9FB, &goal->m_B4, 0);
    }
    func_00244620(goal);
}
