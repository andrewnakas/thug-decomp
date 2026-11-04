extern "C" short func_0013E9D8(void* self);
extern "C" void* func_0013E9B8(void* self, int i);
extern "C" void func_0013C568(void* p, bool on);

class C_0013D950 {
public:
    char m_pad0[0x1B0];
    bool m_b0 : 1;
    bool m_b1 : 1;
    bool m_b2 : 1;
    unsigned long m_b3 : 13;
    short m_count;
    bool SetActive(bool on);
};

bool C_0013D950::SetActive(bool on)
{
    if (m_b2 && on) {
        return false;
    }
    if (m_b1 == on) {
        return true;
    }
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        func_0013C568(func_0013E9B8(this, i), on);
    }
    m_b1 = on;
    return true;
}
