struct C_001F6D98 {
    char m_pad[0x50000];
    int m50000;
    int m50004;
    int m50008;
    int Get(char** out);
};

int C_001F6D98::Get(char** out)
{
    int n = m50008 - m50004;
    if (n) *out = (char*)this + m50000;
    return n;
}
