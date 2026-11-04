extern "C" int func_00136138();
extern "C" void func_0013C718(void* p, int a);

class C_0013D7A0 {
public:
    char m_pad0[0x10];
    void* m_items[60];
    int m_value;
    char m_pad104[0xAE];
    short m_count;
    bool Refresh();
};

bool C_0013D7A0::Refresh()
{
    m_value = func_00136138();
    for (short i = 0; i < m_count; i++) {
        func_0013C718(m_items[i], m_value);
    }
    return true;
}
