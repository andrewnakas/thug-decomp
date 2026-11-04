extern "C" int func_00136158(int handle);
extern "C" void func_0013C718(void* p, int a);

class C_0013D820 {
public:
    char m_pad0[0x10];
    void* m_items[60];
    int m_value;
    char m_pad104[0xAE];
    short m_count;
    bool Release();
};

bool C_0013D820::Release()
{
    func_00136158(m_value);
    m_value = 0;
    for (short i = 0; i < m_count; i++) {
        func_0013C718(m_items[i], 0);
    }
    return true;
}
