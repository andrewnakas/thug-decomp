extern "C" unsigned int func_0010FC30();
extern "C" unsigned int func_0033EBE0(float f);
extern "C" void func_001848F0(void* obj, unsigned int name, int flags);

struct Timer_001BC020 {
    int m_pad[8];
    float m20;
};

struct C_001BC020 {
    int m_pad[3];
    void* mC;
    int m10[3];
    int m1C;
    int m20;
    int m24[320];
    int m524;
    int m528;
    int m52C;
    void Add(unsigned char* params, int bit, int mask, unsigned int nameOn, unsigned int nameOff,
             Timer_001BC020* timer);
};

void C_001BC020::Add(unsigned char* params, int bit, int mask, unsigned int nameOn,
                     unsigned int nameOff, Timer_001BC020* timer)
{
    if (timer) {
        unsigned int now = func_0010FC30();
        if (now < func_0033EBE0(timer->m20)) return;
    }
    if ((params + bit)[1]) {
        if (!(m1C & mask) && m52C && !m524 && !m528) func_001848F0(mC, nameOn, 0);
        m20 |= mask;
    } else {
        if (!(m1C & mask)) return;
        if (m52C && !m524 && !m528) func_001848F0(mC, nameOff, 0);
    }
}
