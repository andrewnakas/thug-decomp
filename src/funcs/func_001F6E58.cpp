struct Buf_001F6E58 {
    char m_pad0[0x50004];
    int m50004;
    int Consume(int n);
};

// Returns the amount taken: the game leaves min(n, m50004) in $v0.
int Buf_001F6E58::Consume(int n)
{
    int take = m50004;
    if (n < take)
        take = n;
    m50004 -= take;
    return take;
}
