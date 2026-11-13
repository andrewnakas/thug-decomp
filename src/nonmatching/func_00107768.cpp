/* fuzzy: 81.6 */
extern "C" int func_0031A838(int, int, int, int);
extern "C" int func_0031A970(int, int, int, int);
extern "C" int func_0031AC78(int, int);
extern "C" int func_0031A710(int, int, int, int);
extern "C" int func_0031AAE8(int, int, unsigned char*);

struct Pad_00107768 {
    char pad[0xC];
    int m_C;
    int m_10;
    int m_14;
    char pad18[0x40 - 0x18];
    unsigned char m_40[0x40];
    unsigned char m_80[0xCC - 0x80];
    int m_CC;
    int m_D0;
    int m_D4;
    int padD8;
    int m_DC;
    int m_E0;
    void Detect();
};

extern "C" void func_00107C60(Pad_00107768*);

void Pad_00107768::Detect()
{
    int type = func_0031A838(m_10, m_14, 1, 0);
    if (!type) {
        func_00107C60(this);
        return;
    }
    int ext = func_0031A838(m_10, m_14, 2, 0);
    if (ext > 0)
        type = ext;
    m_D0 = 0;
    m_C = type;
    switch (type) {
    case 2:
        m_DC = 2;
        break;
    case 3:
        m_DC = 2;
        break;
    case 4:
        if (func_0031A838(m_10, m_14, 2, 0)) {
            func_0031A970(m_10, m_14, 1, 3);
            return;
        }
        break;
    case 7: {
        m_CC |= 1;
        if (func_0031AC78(m_10, m_14) == 1)
            m_CC |= 4;
        int n = func_0031A710(m_10, m_14, -1, 0);
        m_D4 = n;
        if (n <= 0)
            break;
        m_CC |= 2;
        int i;
        for (i = 0; i < m_D4; i++) {
            if (!func_0031A710(m_10, m_14, i, 3))
                m_80[i] = 1;
            else
                m_80[i] = 0xFF;
        }
        for (i = 0; i < m_D4; i++)
            m_40[i] = i;
        for (int j = i; j < 6; j++)
            m_40[j] = 0xFF;
        func_0031AAE8(m_10, m_14, m_40);
        m_E0 = 2;
        m_DC = 5;
        return;
    }
    case 0x100:
        m_DC = 2;
        break;
    default:
        m_DC = 2;
        break;
    }
}
