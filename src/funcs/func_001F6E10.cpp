struct Ring_001F6E10 {
    char m0[0x50000];
    int m50000;
    int m50004;
    int m50008;
    int Get(char** out);
};

int Ring_001F6E10::Get(char** out)
{
    if (m50004)
        *out = m0 + (m50000 - m50004 + m50008) % m50008;
    return m50004;
}
