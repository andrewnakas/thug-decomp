extern "C" int func_0010FC30();

struct Timer_0026FD00 {
    int m0;
    int m_on;
    int m_start;
    int mC;
    int m10;
    int m_started;
    int m_stopped;
    void Start()
    {
        if (!m_on) {
            m_start = func_0010FC30();
            m_started = 1;
        }
        m_on = 1;
    }
    void Stop()
    {
        if (m_on)
            m_stopped = 1;
        m_on = 0;
    }
    void Set(int on);
};

void Timer_0026FD00::Set(int on)
{
    if (on)
        Start();
    else
        Stop();
    m_on = on;
}
