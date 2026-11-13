/* fuzzy: 61.1 */
// nm: 6 words: min() via movn on a copy of avail (game) vs movz here
struct Buf_001F6E58 {
    char m_pad0[0x50004];
    int m50004;
    void Consume(int n);
};

void Buf_001F6E58::Consume(int n)
{
    int avail = m50004;
    if (n >= avail)
        n = avail;
    m50004 = avail - n;
}
