extern "C" int func_0031A5D0(int, int);

struct Pad_001079B8 {
    char pad[0x10];
    int m_10;
    int m_14;
    char pad18[0xE8 - 0x18];
    int m_E8;
    int GetState();
};

int Pad_001079B8::GetState()
{
    switch (func_0031A5D0(m_10, m_14)) {
    case 0:
    case 7:
    case 0x63:
        m_E8 = 0;
        return 2;
    case 1:
    case 5:
        return 3;
    case 6:
        return 1;
    case 2:
        return 0;
    default:
        return 0;
    }
}
