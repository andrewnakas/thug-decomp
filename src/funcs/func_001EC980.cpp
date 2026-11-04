extern "C" int func_00100030(int range);

struct Deck_001EC980 {
    char pad0[0xC];
    unsigned short m_count;
    char padE[0x16 - 0xE];
    unsigned char m_cards[1];

    void Shuffle(int noRepeat);
};

void Deck_001EC980::Shuffle(int noRepeat)
{
    unsigned int n = m_count * 10;
    unsigned char last = m_cards[m_count - 1];
    for (unsigned int i = 0; i < n; i++) {
        int a = func_00100030(m_count);
        int b = func_00100030(m_count);
        unsigned char t = m_cards[a];
        m_cards[a] = m_cards[b];
        m_cards[b] = t;
    }
    if (noRepeat && m_cards[0] == last) {
        int j = func_00100030(m_count - 1);
        unsigned char t = m_cards[0];
        m_cards[0] = m_cards[j + 1];
        m_cards[j + 1] = t;
    }
}
