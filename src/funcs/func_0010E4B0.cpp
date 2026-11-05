extern "C" void func_0010F050();
extern "C" int func_0010E4A0(void* self);

struct Wait_0010E4B0 {
    volatile int m_result;
    int Wait();
};

int Wait_0010E4B0::Wait()
{
    do
        func_0010F050();
    while (func_0010E4A0(this));
    return m_result;
}
