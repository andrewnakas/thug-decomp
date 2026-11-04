extern "C" int func_0031A5D0(int, int);
extern "C" int func_0031A468(int, int, void*);

struct File_00107690 {
    char pad[0x10];
    int m_10;
    int m_14;
    int m_18;
    int pad1C;
    char m_20[0xE8 - 0x20];
    int m_E8;
    void Poll();
    void Close();
    void Reset();
};

extern "C" void func_00107C60(File_00107690*);
extern "C" void func_00107BF0(File_00107690*);

void File_00107690::Poll()
{
    switch (func_0031A5D0(m_10, m_14)) {
    case 2:
    case 6:
        if (func_0031A468(m_10, m_14, m_20) > 0) {
            m_18 = 1;
            m_E8 = 1;
        } else {
            m_18 = 0;
        }
        break;
    case 0:
        m_E8 = 0;
        func_00107C60(this);
        func_00107BF0(this);
        break;
    }
}
