extern "C" short func_0013E9D8(void* self);
extern "C" void* func_0013E9B8(void* self, int i);
extern "C" int func_0013C7B8(void* p, bool on);

class C_0013EE68 {
public:
    char m_pad0[0x1B0];
    bool m_b0 : 1;
    bool m_b1 : 1;
    bool m_b2 : 1;
    bool m_b3 : 1;
    bool m_b4 : 1;
    unsigned long m_b5 : 11;
    short m_count;
    void SetFlag(bool on);
};

void C_0013EE68::SetFlag(bool on)
{
    m_b4 = on;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        func_0013C7B8(func_0013E9B8(this, i), on);
    }
}
