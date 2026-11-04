extern "C" int func_0013C7B8(void* p, bool flag);
extern "C" int func_0013C718(void* p, int a);
extern "C" int func_0013D8B0(void* self, int a);

class C_0013D518 {
public:
    char m_pad0[0x10];
    void* m_items[36];
    int m_ids[18];
    int m_mask;
    char m_padEC[0x14];
    int m_value;
    char m_pad104[0x90];
    int m_state;
    char m_pad198[0x18];
    unsigned long m_b0 : 1;
    unsigned long m_b1 : 3;
    unsigned long m_b4 : 1;
    unsigned long m_b5 : 11;
    short m_count;
    int Add(void* item, int id);
};

int C_0013D518::Add(void* item, int id)
{
    m_b0 = 0;
    m_items[m_count] = item;
    func_0013C7B8(m_items[m_count], m_b4);
    m_ids[m_count] = id;
    m_mask |= 1 << m_count;
    if (m_value) {
        func_0013C718(m_items[m_count], m_value);
    }
    m_count++;
    func_0013D8B0(this, 0);
    if (m_count == 1) {
        m_state = 0x9FACC1A5;
    }
    return 0;
}
