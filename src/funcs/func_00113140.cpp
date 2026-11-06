extern "C" int func_003240F0(int a, int b);
struct Job_00113140;
extern "C" int func_00113000(Job_00113140* j);

struct Job_00113140 {
    int m0;
    int m4;
    int m8;
    int m_state;
    int Start();
};

int Job_00113140::Start()
{
    if (func_003240F0(m4, m8)) {
        m_state = 8;
        return 0;
    }
    return func_00113000(this) == 0;
}
