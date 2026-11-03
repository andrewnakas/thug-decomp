extern "C" int func_0013C790(void* p, int a);

class C_0013D720 {
public:
    char m_pad0[0x10];
    void* m_items[104];
    char m_pad1B0[2];
    short m_count;
    void Apply(int a);
};

void C_0013D720::Apply(int a)
{
    short i = 0;
    while (i < m_count) {
        func_0013C790(m_items[i], a);
        i++;
    }
}
