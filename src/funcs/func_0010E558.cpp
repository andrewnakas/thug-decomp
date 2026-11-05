extern "C" int func_00109598(void* file);

struct Job_0010E558 {
    volatile int m0;
    char pad4[0x28 - 4];
    volatile int m28;
    int m2C;
    void* m30;
    int Wait();
};

int Job_0010E558::Wait()
{
    if (m30) {
        m0 = func_00109598(m30);
        return m0;
    }
    while (m28 < 0) {
    }
    return m28;
}
