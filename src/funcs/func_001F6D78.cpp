struct Buf_001F6D78 {
    char data[0x50000];
    int m50000;
    int m50004;
    int m50008;
    void Reset();
};

void Buf_001F6D78::Reset()
{
    m50008 = 0x50000;
    m50000 = 0;
    m50004 = 0;
}
