extern "C" int func_0010FC30();

struct Timer_0026FDA0 {
    char pad[0x8];
    int m_start;
    int Elapsed();
};

int Timer_0026FDA0::Elapsed()
{
    int start = m_start;
    return func_0010FC30() - start;
}
