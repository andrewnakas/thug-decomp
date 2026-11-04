struct O_00111278 {
    int pad[3];
    int m_C;
    int pad2[3];
    int m_1C;
};

extern "C" void func_00331404(int, int, int);
extern "C" void func_00111F70(int);
extern "C" void func_0031CD60(const char*, int, void*, int);
extern char D_0035BEA0[];

struct B_00111278 {
    char pad[0x28];
    volatile int m_28;
    volatile int m_2C;
    int pad30;
    volatile int m_34;
    int pad38;
    volatile int m_3C;
    char pad40[0x144 - 0x40];
    int m_144;
    int m_148;
    int m_14C;
    void Set(unsigned int type, int value, O_00111278* obj);
    void BaseSet(unsigned int type, int value, int extra);
};

extern "C" void func_0010E7E8(B_00111278*, unsigned int, int, int);

void B_00111278::Set(unsigned int type, int value, O_00111278* obj)
{
    int extra = obj->m_1C;
    switch (type) {
    case 0:
        return;
    case 1:
        m_3C = value;
        if (value < 0)
            m_28 = 0;
        else
            m_28 = extra;
        break;
    case 5:
        if (value >= 0)
            m_2C = value;
        break;
    case 2:
    case 3:
        if (m_148 && value > 0)
            func_00331404(m_144, m_148, value);
    case 4:
        if (value >= 0) {
            m_2C += value;
            if (m_148) {
                func_00111F70(m_14C);
                m_144 = 0;
                m_148 = 0;
                m_14C = 0;
            }
        }
        break;
    case 6:
        if (m_34 >= 2)
            func_0031CD60(D_0035BEA0, m_34 - 1, this, obj->m_C);
        break;
    }
    m_34;
    func_0010E7E8(this, type, value, extra);
}
