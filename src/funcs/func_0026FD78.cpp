extern "C" int func_0010FC30();

struct Timer_0026FD78 {
    char pad[0xC];
    int m_start;
    int Elapsed();
};

int Timer_0026FD78::Elapsed()
{
    int start = m_start;
    return func_0010FC30() - start;
}
